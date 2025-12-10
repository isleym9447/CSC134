#ifndef SCENE_HPP
#define SCENE_HPP

#include <SFML/Graphics.hpp>

class Scene {
public:
    virtual ~Scene() = default;

    virtual void handleEvent(const sf::Event& event) = 0;
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

    // For scenes that want to signal "I'm done"
    virtual bool isFinished() const { return false; }
};

#endif
