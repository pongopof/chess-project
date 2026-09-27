#include "board.h"
#include "board_view.h"

#include <QApplication>
#include <QWidget>

#include <iostream>

namespace {

char symbolFor(chess::Piece piece)
{
    const bool white = piece.color == chess::Color::White;

    switch (piece.type) {
    case chess::PieceType::Pawn:
        return white ? 'P' : 'p';

    case chess::PieceType::Knight:
        return white ? 'N' : 'n';

    case chess::PieceType::Bishop:
        return white ? 'B' : 'b';

    case chess::PieceType::Rook:
        return white ? 'R' : 'r';

    case chess::PieceType::Queen:
        return white ? 'Q' : 'q';

    case chess::PieceType::King:
        return white ? 'K' : 'k';
    }

    return '?';
}

void printBoard(const chess::Board& board)
{
    for (int rank = 7; rank >= 0; --rank) {
        std::cout << rank + 1 << "  ";

        for (int file = 0; file < 8; ++file) {
            const auto piece =
                board.pieceAt(chess::Square{file, rank});

            std::cout << (piece ? symbolFor(*piece) : '.')
                      << ' ';
        }

        std::cout << '\n';
    }

    std::cout << "\n   a b c d e f g h\n" << std::flush;
}

} // namespace

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    const auto board = chess::Board::startingPosition();

    chess::BoardView window;
    window.setWindowTitle("Chess Training");
    window.resize(700, 700);
    window.displayBoard(board);
    window.show();

    return app.exec();
}