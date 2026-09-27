#ifndef CHESS_BOARD_VIEW_H
#define CHESS_BOARD_VIEW_H

#include "board.h"

#include <QGraphicsView>

class QGraphicsScene;
class QResizeEvent;

namespace chess {

class BoardView : public QGraphicsView {
public:
    explicit BoardView(QWidget* parent = nullptr);

    void displayBoard(const Board& board);

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    QGraphicsScene* scene_;

    static constexpr int squareSize = 80;
    static constexpr int boardSize = 8 * squareSize;
};

} // namespace chess

#endif