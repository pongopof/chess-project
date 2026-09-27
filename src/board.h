#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "chess_types.h"

#include <array>
#include <cstddef>
#include <optional>

namespace chess {

class Board {
public:
    Board() = default;

    [[nodiscard]] static Board startingPosition();

    [[nodiscard]] std::optional<Piece> pieceAt(Square square) const;

private:
    std::array<std::optional<Piece>, 64> squares_{};

    [[nodiscard]] static std::size_t indexOf(Square square);
};

} // namespace chess

#endif