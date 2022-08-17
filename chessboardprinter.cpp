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
#include "ChessBoard.h"
#include "Piece.h"

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

    int newMode = oldMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (newMode == oldMode)
    {
        // Nothing to change
        hOut = INVALID_HANDLE_VALUE;
        return;
    }

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

ostream &operator<<(ostream &out, ChessBoardPrinter::TextFormat info)
{
    out << "\x1b["; // Special character

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

    const char shortName[int(Piece::Type::NTypes)] = {
        'b', // Bishop
        'K', // King
        'k', // Knight
        'p', // Pawn
        'q', // Queen
        'r' // Rook
    };

    Piece *p;

    // Print Chess horizontal table header
    if (m_mode != Chess::PrintMode::Normal)
        cout << headerFmt; // Set colors

    cout << "     "; // 5 spaces
    for (int i = 0; i < 8; i++)
    {
        cout << i << "    "; // 1 digit + 4 spaces = 5
    }

    if (m_mode != Chess::PrintMode::Normal)
        cout << TextFormat{}; // Reset colors

    std::cout << endl;

    for (int x = 0; x < 8; x++)
    {
        // Make column 3 character wide, so pieces align centered to header
        if (m_mode != Chess::PrintMode::Normal)
            cout << headerFmt; // Set colors

        // Print vertical table header
        cout << " " << x << " "; // 1 digit + 2 spaces = 3

        if (m_mode != Chess::PrintMode::Normal)
            cout << TextFormat{}; // Reset colors

        for (int y = 0; y < 8; y++)
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
                const char typeLetter = shortName[int(p->getType())];

                // Print piece
                cout << " " << colorLetter << typeLetter << p->getNumber()
                     << " "; // 2 letters, 1 digit, 2 space = 5

                if (m_mode != Chess::PrintMode::Normal)
                    cout << TextFormat{}; // Reset colors
            }
            else
            {
                // Fill empty position
                cout << "     "; // 5 spaces
            }
        }

        cout << endl;
    }

    if (m_mode != Chess::PrintMode::Normal)
        cout << TextFormat{}; // Reset colors
}
