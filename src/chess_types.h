#ifndef CHESS_TYPES_H
#define CHESS_TYPES_H

namespace chess {

enum class Color {
    White,
    Black
};

enum class PieceType {
    Pawn,
    Knight,
    Bishop,
    Rook,
    Queen,
    King
};

struct Piece {
    PieceType type;
    Color color;
};

struct Square {
    int file;
    int rank;

    [[nodiscard]] constexpr bool isValid() const noexcept
    {
        return file >= 0 && file < 8
            && rank >= 0 && rank < 8;
    }
};

} // namespace chess

#endif