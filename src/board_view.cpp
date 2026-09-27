#include "board_view.h"

#include <QBrush>
#include <QColor>
#include <QFont>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QPainter>
#include <QPen>
#include <QResizeEvent>
#include <QString>

namespace {

QString pieceLetter(chess::PieceType type)
{
    switch (type) {
    case chess::PieceType::Pawn:
        return QStringLiteral("P");

    case chess::PieceType::Knight:
        return QStringLiteral("N");

    case chess::PieceType::Bishop:
        return QStringLiteral("B");

    case chess::PieceType::Rook:
        return QStringLiteral("R");
    
    case chess::PieceType::Queen:
        return QStringLiteral("Q");

    case chess::PieceType::King:
        return QStringLiteral("K");
    }

    return QStringLiteral("?");
}

}

namespace chess {

BoardView::BoardView(QWidget* parent)
    : QGraphicsView(parent),
      scene_(new QGraphicsScene(this))
{
    setScene(scene_);

    scene_->setSceneRect(0, 0, boardSize, boardSize);

    setRenderHint(QPainter::Antialiasing);
    setRenderHint(QPainter::TextAntialiasing);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setMinimumSize(320, 320);
}

void BoardView::displayBoard(const Board& board)
{
    scene_->clear();

    const QColor lightSquare{222, 210, 185};
    const QColor darkSquare{125, 145, 115};

    QFont pieceFont;
    pieceFont.setPixelSize(44);
    pieceFont.setBold(true);

    for (int rank = 0; rank < 8; ++rank) {
        for (int file = 0; file < 8; ++file) {
            const int x = file * squareSize;
            const int y = (7 - rank) * squareSize;

            const bool isLight = (file + rank) % 2 != 0;
            const QColor squareColor =
                isLight ? lightSquare : darkSquare;

            scene_->addRect(
                x,
                y,
                squareSize,
                squareSize,
                QPen{Qt::NoPen},
                QBrush{squareColor}
            );

            const auto piece = board.pieceAt(Square{file, rank});

            if (!piece) {
                continue;
            }

            auto* label = scene_->addSimpleText(
                pieceLetter(piece->type),
                pieceFont
            );

            const QColor pieceColor =
                piece->color == Color::White
                    ? QColor{255, 255, 255}
                    : QColor{25, 25, 25};

            label->setBrush(QBrush{pieceColor});
            label->setZValue(1);

            const auto bounds = label->boundingRect();

            label->setPos(
                x + squareSize / 2.0 - bounds.center().x(),
                y + squareSize / 2.0 - bounds.center().y()
            );
        }
    }

    fitInView(scene_->sceneRect(), Qt::KeepAspectRatio);
}

void BoardView::resizeEvent(QResizeEvent* event)
{
    QGraphicsView::resizeEvent(event);

    fitInView(scene_->sceneRect(), Qt::KeepAspectRatio);
}

} // namespace chess


