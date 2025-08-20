
#include "wall.h"
#include "color.h"

using game::Color;
using game::Wall;
using game::Renderer;
using game::SceneItem;

Wall::Wall()
    : SceneItem() {
    Vector sze(800, 5);
    resize(sze);
}

Wall::~Wall() {

}

void Wall::update(float delta) {
    SceneItem::update(delta);
}

void Wall::render(Renderer* renderer) {
    SceneItem::render(renderer);
    auto rect = rectangle();
    renderer->draw(rect, Color::navyBlue());
}
