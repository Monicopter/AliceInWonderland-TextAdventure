#pragma once

enum class Action {
    HELP,
    INSPECT,
    TALK,
    TAKE,
    USE,
    MOVE,
    INVENTORY,
    CONSUME,
    QUIT
};

enum class Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST
};

enum class consumeEffect {
    NONE,
    SHRINK,
    ENLARGE,
    SATIATE,
};