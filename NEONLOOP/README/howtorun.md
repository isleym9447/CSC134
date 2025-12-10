


# Requirements



Operating System

Windows 10 or Windows 11 (64-bit)

Compiler

MinGW-w64 (WinLibs) – GCC 13.1.0 (64-bit)
Downloadable from the link provided on the SFML site (WinLibs MSVCRT 13.1.0 64-bit).

Graphics Library

SFML 2.6.2 — GCC 13.1.0 MinGW (SEH) — 64-bit

⚠️ Important Compatibility Note
SFML's precompiled Windows packages are tightly tied to compiler version.
This project must be built using GCC 13.1.0, which exactly matches the SFML binary package.
Mismatched versions will cause missing symbol errors or “entry point not found” crashes.

🚀 How to Build & Run the Game

You can either run the provided executable or build from source using the exact toolchain described below.

▶️ Option 1 — Running the Prebuilt Game (Recommended)

Open the project folder.

Locate the folder containing game.exe.

Ensure the following DLL files are present in the same folder:

SFML DLLs:

sfml-graphics-2.dll

sfml-window-2.dll

sfml-system-2.dll

MinGW DLLs:

libstdc++-6.dll

libgcc_s_seh-1.dll

libwinpthread-1.dll

Double-click game.exe.

If all required DLLs are present, the game will open in an SFML window.

▶️ Option 2 — Building From Source
1. Install MinGW-w64 (GCC 13.1.0)

Download the WinLibs MSVCRT GCC 13.1.0 (64-bit) toolchain and extract it to:

C:\mingw64_sfml\


Verify the compiler works:

"C:\mingw64_sfml\bin\g++" --version


It should report gcc 13.1.0.

2. Install SFML 2.6.2 (64-bit, MinGW GCC 13.1.0)

Download and extract SFML to:

C:\SFML-2.6.2\


You should now have:

C:\SFML-2.6.2\include
C:\SFML-2.6.2\lib
C:\SFML-2.6.2\bin

3. Build the Game

From the project root:

cd "C:\path\to\project"


Compile using MinGW:

"C:\mingw64_sfml\bin\g++" src\*.cpp -std=c++17 ^
  -I"C:\SFML-2.6.2\include" ^
  -L"C:\SFML-2.6.2\lib" ^
  -lsfml-graphics -lsfml-window -lsfml-system ^
  -o game.exe


Copy the required DLLs from:

C:\SFML-2.6.2\bin

C:\mingw64_sfml\bin

into the same folder as game.exe.

Run the game:

game.exe

🎮 Controls & Gameplay

This game plays like a visual novel, with interactive text scenes and decision points.

Controls
Key	Action
Left Click	Advance dialogue / select choices (if implemented)
Enter	Confirm a menu selection
Escape	Exit the game window
X button (window)	Quit the game

As the game grows, additional keyboard or mouse controls may be added.

Gameplay Summary

The game opens in an SFML-rendered window.

The player begins with character creation (lifepath, name, attributes).

The story progresses through modular scenes, each controlled by a SceneManager.

Choices influence:

Branching dialogue

Character stats

Story routes

Encounter outcomes

The architecture supports:

Scene transitions

Background images

Text rendering

Expanding into a full visual novel UI

This framework is designed to grow—allowing future additions such as animations, sound, UI panels, and save/load.

📁 Project Structure
project_root/
│
├── src/
│   ├── main.cpp
│   ├── SceneManager.cpp
│   ├── CharCreateScene.cpp
│   ├── ApartmentScene.cpp
│   └── (more scenes as added)
│
├── assets/
│   ├── backgrounds/
│   ├── fonts/
│   └── images/
│
└── game.exe (if provided)
