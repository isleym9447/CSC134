#ifndef HACKINGMINIGAME_H
#define HACKINGMINIGAME_H

#include <string>
#include <vector>

/// Simple hacking mini-game interface for your Cyberpunk-style project.
/// - hackingminigame(): runs the current placeholder version (accepts any input).
/// - hackingminigame_with_tech(int tech): runs the game and returns true on success,
///   false on failure. Replace the placeholder logic inside the .cpp to check
///   the provided tech stat against your success criteria.
///


/// Run the hacking mini-game (placeholder: always succeeds).
void hackingminigame();

/// Run the hacking mini-game using a player's tech stat.
/// Returns true if the hack succeeded, false if it failed.
/// TODO: Implement success logic in the .cpp file (e.g., require tech >= X
///       or mix with sequence correctness and other modifiers).
bool hackingminigame_with_tech(int tech);

/// Utility: returns a vector of the buffer codes shown to the player.
/// (You can call this from other code to show the buffer without running the game.)
std::vector<std::string> hacking_buffer();

#endif // HACKINGMINIGAME_H
