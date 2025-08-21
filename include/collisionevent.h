#pragma once

#include "event.h"
#include "sceneitem.h"

namespace game {
    class CollisionEvent : public Event {
        public:
            CollisionEvent(SceneItem* firstObject, SceneItem* secondObject);
            CollisionEvent(const CollisionEvent& other);
            virtual ~CollisionEvent();

            SceneItem* firstObject() const;
            SceneItem* secondObject() const;

            CollisionEvent& operator= (const CollisionEvent& other);
        private:
            SceneItem* _firstObject;
            SceneItem* _secondObject;
    };
}