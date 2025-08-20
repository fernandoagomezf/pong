
#include <algorithm>
#include <stdexcept>
#include "scene.h"
#include "event.h"

using std::find;
using std::invalid_argument;
using game::Renderer;
using game::Scene;
using game::Event;
using game::EventBus;

Scene::Scene(EventBus* bus) {
    if (bus == nullptr) {
        throw invalid_argument("An event bus is needed for the scene.");
    }
    _bus = bus;
}

Scene::~Scene() {
    for (auto item : _items)     {
        delete item;
    }
    _items.clear();
}

EventBus* Scene::getBus() const {
    return _bus;
}

void Scene::attach(SceneItem* item) {
    auto i = find(_items.begin(), _items.end(), item);
    if (i == _items.end()) {
        _items.push_back(item);
    }
}

void Scene::detach(SceneItem* item) {
    auto i = find(_items.begin(), _items.end(), item);
    if (i != _items.end()) {
        _items.erase(i);
    }
}

void Scene::update(float delta) {
    for (auto i : _items) {
        i->update(delta);
    }
}

void Scene::render(Renderer* renderer){
    renderer->clear();
    for (auto i : _items) {
        i->render(renderer);
    }
    renderer->show();
}

