#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <memory>
#include "scenes/scene.hpp"   // base Scene class

class Scene;

class SceneManager {
public:
    // Swap to a new scene
    static void changeScene(std::unique_ptr<Scene> newScene);

    // Get the current active scene (or nullptr)
    static Scene* getCurrentScene();

private:
    static std::unique_ptr<Scene> currentScene;
};

#endif
