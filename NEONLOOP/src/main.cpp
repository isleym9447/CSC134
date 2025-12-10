#include <SFML/Graphics.hpp>
#include <memory>

#include "scenemanager.h"
#include "player.h"

// scenes
#include "scenes/scene_charcreate.h"
#include "scenes/scene_apartment.h"

int main() {
    // Create the main game window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "NEON LOOP");
    window.setFramerateLimit(60);

    // Your player object, filled in by char create
    player currentPlayer("Temp", "Unknown");

    // Start on character creation
    SceneManager::changeScene(std::make_unique<SceneCharCreate>(currentPlayer));

    sf::Clock clock;

    while (window.isOpen()) {
        // ---------- EVENT HANDLING ----------
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (auto* scene = SceneManager::getCurrentScene()) {
                scene->handleEvent(event);
            }
        }

        // ---------- UPDATE ----------
        float dt = clock.restart().asSeconds();

        if (auto* scene = SceneManager::getCurrentScene()) {
            scene->update(dt);

            // If the current scene says it's finished, transition
            if (scene->isFinished()) {
                // If it's the character creation scene, go to the apartment
                if (dynamic_cast<SceneCharCreate*>(scene) != nullptr) {
                    SceneManager::changeScene(
                        std::make_unique<SceneApartment>()   // 🔹 no player arg here
                    );
                }
                // Later you can add more transitions for other scenes
            }
        }

        // ---------- DRAW ----------
        window.clear(sf::Color::Black);

        if (auto* scene = SceneManager::getCurrentScene()) {
            scene->draw(window);
        }

        window.display();
    }

    return 0;
}
