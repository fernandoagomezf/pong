
#include "common.h"
#include "scene.h"
#include "sceneitem.h"
#include "event.h"
#include "eventbus.h"

using std::find;
using std::invalid_argument;
using game::Renderer;
using game::Scene;
using game::Event;
using game::EventBus;

Scene::Scene(Renderer* renderer, EventBus* bus) {
    if (renderer == nullptr) {
        throw invalid_argument("A renderer is needed for the scene.");
    }
    if (bus == nullptr) {
        throw invalid_argument("An event bus is needed for the scene.");
    }
    _renderer = renderer;
    _bus = bus;
}

Scene::~Scene() {
    for (auto item : _items)     {
        delete item;
    }
    _items.clear();
}

Renderer* Scene::getRenderer() const {
    return _renderer;
}

EventBus* Scene::getBus() const {
    return _bus;
}

void Scene::load() {

}

void Scene::unload() {
    
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

void Scene::update(long delta) {
    for (auto i : _items) {
        i->update(delta);
    }
}

void Scene::render(){
    _renderer->clear();

    for (auto i : _items) {
        i->render(_renderer);
    }

    _renderer->show();
}

