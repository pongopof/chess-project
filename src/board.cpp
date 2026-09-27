#include "board.h"

#include <stdexcept>

namespace chess {

    //Get index for square
std::size_t Board::indexOf(Square square)
{
    if (!square.isValid()) {
        throw std::out_of_range{"Square is outside the board"};
    }

    return static_cast<std::size_t>(
        square.rank * 8 + square.file
    );
}
//Returns what piece is a square.
std::optional<Piece> Board::pieceAt(Square square) const
{
    return squares_[indexOf(square)];
}
//
Board Board::startingPosition()
{
    Board board;

    constexpr std::array<PieceType, 8> backRank{
        PieceType::Rook,
        PieceType::Knight,
        PieceType::Bishop,
        PieceType::Queen,
        PieceType::King,
        PieceType::Bishop,
        PieceType::Knight,
        PieceType::Rook
    };

    for (int file = 0; file < 8; ++file) {
        const auto type =
            backRank[static_cast<std::size_t>(file)];

        board.squares_[indexOf(Square{file, 0})] =
            Piece{type, Color::White};

        board.squares_[indexOf(Square{file, 1})] =
            Piece{PieceType::Pawn, Color::White};

        board.squares_[indexOf(Square{file, 6})] =
            Piece{PieceType::Pawn, Color::Black};

        board.squares_[indexOf(Square{file, 7})] =
            Piece{type, Color::Black};
    }

    return board;
}

} // namespace chess