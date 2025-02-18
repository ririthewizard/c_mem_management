#include "structs.h"

struct Coordinate {
    int x;
    int y;
    int z;
}

struct Coordinate new_coord(int x, int y, int z) {
    struct Coordinate coord = {
	.x = x,
	.y = y,
	.z = z
    };
    return coord;
};

struct Coordinate scale_coordinate(struct Coordinate coord, int factor) {
    struct Coordinate scaled = coord;
    scaled.x *= factor;
    scaled.y *= factor;
    scaled.z *= factor;

    return scaled;
}
