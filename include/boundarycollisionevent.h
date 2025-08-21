#pragma once

#include "event.h"
#include "sceneitem.h"
#include "edge.h"

namespace game {
    class BoundaryCollisionEvent : public Event {
        public:
            BoundaryCollisionEvent(SceneItem* object, const Edge& edge);
            BoundaryCollisionEvent(const BoundaryCollisionEvent& other);
            virtual ~BoundaryCollisionEvent();

            SceneItem* object() const;
            Edge edge() const;

            BoundaryCollisionEvent& operator= (const BoundaryCollisionEvent& other);

        private:
            SceneItem* _object;
            Edge _edge;
    };
};