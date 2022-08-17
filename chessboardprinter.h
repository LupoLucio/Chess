#ifndef CHESSBOARDPRINTER_H
#define CHESSBOARDPRINTER_H

class ChessBoard;
class Piece;

namespace Chess {

#define MAKE_FLAG_OPERATORS(TYPE)                                                                  \
    inline TYPE operator&(TYPE a, TYPE b) { return TYPE(int(a) & int(b)); }                        \
    inline TYPE operator|(TYPE a, TYPE b) { return TYPE(int(a) | int(b)); }                        \
    inline TYPE operator~(TYPE a) { return TYPE(~int(a)); }                                        \
    inline bool hasFlag(TYPE a, TYPE flag)                                                         \
    {                                                                                              \
        return ((a & flag) == flag && (int(flag) != 0 || a == flag));                              \
    }                                                                                              \
    inline void setFlag(TYPE &a, TYPE flag, bool on = true) { a = (on ? (a | flag) : (a & ~flag)); }

// See https://docs.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences
enum class ConsoleColor {
    Black = 0,
    Red = 1,
    Green = 2,
    Yellow = 3,
    Blue = 4,
    Magenta = 5,
    Cyan = 6,
    White = 7,
    Default = 9
};

enum class ConsoleFormat { Default = 0, Foreground = 1 << 1, Background = 1 << 2, Bold = 1 << 3 };

MAKE_FLAG_OPERATORS(ConsoleFormat)

enum class PrintMode {
    Normal = 0, // No colors
    MarkCurrentPiece = 1 << 0, // Current piece will be printed in different color
    ColorAllPieces = 1 << 1, // All pieces will be colored based on their color
};

MAKE_FLAG_OPERATORS(PrintMode)

} // namespace Chess

/*!
 * \brief The ChessBoardPrinter class
 *
 * Class to print ChessBoard to console window
 * It can use colors
 */
class ChessBoardPrinter
{
public:
    struct TextFormat
    {
        Chess::ConsoleColor text = Chess::ConsoleColor::Default;
        Chess::ConsoleColor background = Chess::ConsoleColor::Default;
        Chess::ConsoleFormat fmt = Chess::ConsoleFormat::Default;

        inline void setTextColor(Chess::ConsoleColor c)
        {
            text = c;
            Chess::setFlag(fmt, Chess::ConsoleFormat::Foreground, true);
        }

        inline void setBGColor(Chess::ConsoleColor c)
        {
            background = c;
            Chess::setFlag(fmt, Chess::ConsoleFormat::Background, true);
        }

        inline void setBold(bool val) { Chess::setFlag(fmt, Chess::ConsoleFormat::Bold, val); }
    };

    ChessBoardPrinter(ChessBoard &cb_,
                      Chess::PrintMode mode = Chess::PrintMode::ColorAllPieces
                              | Chess::PrintMode::MarkCurrentPiece);

    inline void setCurPiece(Piece *piece) { currentPiece = piece; }

    void printChessBoardToStdout();

private:
    ChessBoard &cb;
    Chess::PrintMode m_mode;
    Piece *currentPiece;

public:
    TextFormat whitePieceFmt;
    TextFormat blackPieceFmt;
    TextFormat currentPieceFmt;
    TextFormat headerFmt;
};

#endif // CHESSBOARDPRINTER_H
