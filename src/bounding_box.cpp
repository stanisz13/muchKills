#include "bounding_box.hpp"

bounding_box::bounding_box(vec2f newPos, vec2f newSize) : pos{newPos}, size{newSize} {};

void bounding_box::setPos (vec2f newPos) {
    pos = newPos;
}

void bounding_box::setSize (vec2f newSize) {
    size = newSize;
}

bool collides(const bounding_box& A, const bounding_box& B) {
    return  A.pos.x < B.pos.x + B.size.x &&
            A.pos.x + A.size.x > B.pos.x &&
            A.pos.y < B.pos.y + B.size.y &&
            A.pos.y + A.size.y > B.pos.y;
}

void bounding_box::updateScale()
{
    sf::FloatRect bounds;
    setPos(vec2f(bounds.left, bounds.top));
    setSize(vec2f(bounds.width, bounds.height));
}
