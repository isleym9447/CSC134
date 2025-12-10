#include "scenemanager.h"
#include "scenes/scene.hpp"

std::unique_ptr<Scene> SceneManager::currentScene = nullptr;

void SceneManager::changeScene(std::unique_ptr<Scene> newScene) {
    currentScene = std::move(newScene);
}

Scene* SceneManager::getCurrentScene() {
    return currentScene.get();
}
