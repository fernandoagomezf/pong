#pragma once

#include "vector.h"
#include "renderer.h"
#include "rectangle.h"

namespace game {    
    class SceneItem {
        public:
            virtual ~SceneItem();

            game::Vector position() const;
            game::Vector size() const;
            game::Rectangle rectangle() const;
            
            void resize(const game::Vector& newSize);
            void moveTo(const game::Vector& newPosition);
            virtual void update(float delta);
            virtual void render(game::Renderer* renderer);         

        protected:
            SceneItem();

        private:
            game::Vector _position;
            game::Vector _size;
    };
}

