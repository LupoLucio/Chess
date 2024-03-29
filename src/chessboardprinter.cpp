#ifdef _WIN32
// windows.h must be first header
#    include <windows.h> //For GetStdHandle(), SetConsoleMode()

// On MinGW it is not defined so we manually define it, copy value from Microsoft website
// See https://docs.microsoft.com/en-us/windows/console/getconsolemode
#    ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#        define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#    endif
#endif //_WIN32

#include "chessboardprinter.h"
#include "chessboard.h"
#include "piece.h"

#include <iostream>
using namespace std;

#ifdef _WIN32
/*!
 * \brief The EnableConsoleVirtualSequence class
 *
 * On Windows console virtual sequences are not recognized by default
 * This class enables them on constructor and reset to old state on destructor
 */
class EnableConsoleVirtualSequence
{
public:
    EnableConsoleVirtualSequence(bool enable);
    ~EnableConsoleVirtualSequence();

    HANDLE hOut = INVALID_HANDLE_VALUE;
    DWORD oldMode = 0;
    int error = 0;
};

EnableConsoleVirtualSequence::EnableConsoleVirtualSequence(bool enable)
{
    // Set output mode to handle virtual terminal sequences
    if (!enable)
        return;

    // Get console STDOUT handle
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        error = GetLastError();
        return;
    }

    // Save old mode for later
    if (!GetConsoleMode(hOut, &oldMode))
    {
        error = GetLastError();
        hOut = INVALID_HANDLE_VALUE;
        return;
    }

    // Enable virtual sequences
    int newMode = oldMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (newMode == oldMode)
    {
        // Nothing to change
        hOut = INVALID_HANDLE_VALUE;
        return;
    }

    // Set new console mode
    if (!SetConsoleMode(hOut, newMode))
    {
        error = GetLastError();
        hOut = INVALID_HANDLE_VALUE;
    }
}

EnableConsoleVirtualSequence::~EnableConsoleVirtualSequence()
{
    // Reset to old mode
    if (hOut != INVALID_HANDLE_VALUE)
        SetConsoleMode(hOut, oldMode);
}

#endif // _WIN32

int getColorNumber(Chess::ConsoleColor color, Chess::ConsoleFormat format)
{
    // Convert color to virtual terminal sequences
    // See https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences
    const int colorVal = int(color);

    int fmtVal = 0;
    if (hasFlag(format, Chess::ConsoleFormat::Foreground))
        fmtVal = 30;
    else if (hasFlag(format, Chess::ConsoleFormat::Background))
        fmtVal = 40;
    else
        return 0; // Reset to default

    if (hasFlag(format, Chess::ConsoleFormat::Bold))
        fmtVal += 60; // Make it bold

    return colorVal + fmtVal;
}

/*!
 * \brief operator <<
 * \param out ostream like cout
 * \param info color info
 * \return same ostream as out
 *
 * Helper function to colorize std::cout using virtual terminal sequences
 */
ostream &operator<<(ostream &out, ChessBoardPrinter::TextFormat info)
{
    out << "\x1b["; // Special character to begin command

    bool addSemicolon = false;
    if (Chess::hasFlag(info.fmt, Chess::ConsoleFormat::Foreground))
    {
        // Get foreground and ignore background
        int fg = getColorNumber(info.text, info.fmt & ~Chess::ConsoleFormat::Background);
        out << fg;
        addSemicolon = true;
    }
    if (Chess::hasFlag(info.fmt, Chess::ConsoleFormat::Background))
    {
        if (addSemicolon)
            out << ';'; // Separate from foreground

        // Get background and ignore foreground
        int bg = getColorNumber(info.background, info.fmt & ~Chess::ConsoleFormat::Foreground);
        out << bg;
    }

    out << 'm'; // End command
    return out;
}

ChessBoardPrinter::ChessBoardPrinter(ChessBoard &cb_, Chess::PrintMode mode) : cb(cb_), m_mode(mode)
{
    headerFmt.setBold(true);
    headerFmt.setBGColor(Chess::ConsoleColor::Blue);

    whitePieceFmt.setBGColor(Chess::ConsoleColor::Red);
    blackPieceFmt.setBGColor(Chess::ConsoleColor::Green);

    currentPieceFmt.setBGColor(Chess::ConsoleColor::Yellow);
    currentPieceFmt.setTextColor(Chess::ConsoleColor::Magenta);
}

void ChessBoardPrinter::printChessBoardToStdout()
{
#ifdef _WIN32
    EnableConsoleVirtualSequence seq(m_mode != Chess::PrintMode::Normal);
    if (seq.error)
    {
        cout << "CONSOLE ERROR: " << seq.error << endl;
        m_mode = Chess::PrintMode::Normal; // Disable colors
    }
#endif // _WIN32

    Piece *p = nullptr;
    const char *emptyCell = "     "; //5 spaces
    const char *emptyHeaderCell = "   "; //3 spaces

    // Print Chess horizontal table header
    if (m_mode != Chess::PrintMode::Normal)
        cout << headerFmt; // Set colors

    cout << emptyHeaderCell; // 3 spaces, left header corner
    for (int x = 0; x < 8; x++)
    {
        cout << "  " << x << "  "; // 1 digit + 4 spaces = 5
    }

    //Print axis name at end of row
    cout << " X ";

    if (m_mode != Chess::PrintMode::Normal)
        cout << TextFormat{}; // Reset colors

    //Go to first row AFTER color reset
    cout << endl;

    for (int y = 0; y < 8; y++)
    {
        // Make column 3 character wide, so pieces align centered to header

        //Set header format
        if (m_mode != Chess::PrintMode::Normal)
            cout << headerFmt; // Set colors

        // Print vertical table header
        cout << " " << y << " "; // 1 digit + 2 spaces = 3

        if (m_mode != Chess::PrintMode::Normal)
            cout << TextFormat{}; // Reset colors

        for (int x = 0; x < 8; x++)
        {
            p = cb.getPieceAtPos(Position(x, y));
            if (p && p->isAlive)
            {
                if (m_mode != Chess::PrintMode::Normal)
                {
                    TextFormat fmt = blackPieceFmt;
                    if (p == currentPiece
                        && Chess::hasFlag(m_mode, Chess::PrintMode::MarkCurrentPiece))
                        fmt = currentPieceFmt;
                    else if (p->getColor() == Piece::Color::White)
                        fmt = whitePieceFmt;

                    cout << fmt; // Set colors
                }

                const char colorLetter = p->getColor() == Piece::Color::White ? 'w' : 'b';
                const char typeLetter = Piece::getTypeShortName(p->getType());

                // Print piece
                cout << " " << colorLetter << typeLetter << p->getNumber()
                     << " "; // 2 letters, 1 digit, 2 space = 5

                if (m_mode != Chess::PrintMode::Normal)
                    cout << TextFormat{}; // Reset colors
            }
            else
            {
                // Fill empty position
                cout << emptyCell; // 3 spaces
            }
        }

        //Set header format for right header
        if (m_mode != Chess::PrintMode::Normal)
            cout << headerFmt; // Set colors

        //Print right header
        cout << emptyHeaderCell;

        if (m_mode != Chess::PrintMode::Normal)
            cout << TextFormat{}; // Reset colors

        //Go to next row AFTER color reset
        cout << endl;
    }

    //Set header format
    if (m_mode != Chess::PrintMode::Normal)
        cout << headerFmt; // Set colors

    //Print axis name at end of column
    cout << " Y ";

    //Print whole row of bottom header, 8 cells
    for (int x = 0; x < 8; x++)
    {
        cout << emptyCell;
    }

    //Print right header
    cout << emptyHeaderCell;

    if (m_mode != Chess::PrintMode::Normal)
        cout << TextFormat{}; // Reset colors

    //Go to new line AFTER color reset
    cout << endl;
}
