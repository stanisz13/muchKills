#pragma once

#include "vector.hpp"

struct bounding_box {
    bounding_box(){};
    bounding_box(vec2f newPos, vec2f newSize);
    vec2f pos;
    vec2f size;
    void setPos(vec2f newPos);
    void setSize(vec2f newSize);

    void updateScale();
};

bool collides(const bounding_box& A, const bounding_box& B);
