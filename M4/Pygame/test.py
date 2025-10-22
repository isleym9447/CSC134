import pygame
import sys

# Initialize Pygame
pygame.init()

# Set up the display
width, height = 600, 400
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Pygame Test Window")

# --- Main Game Loop ---
running = True
x = width // 2
y = height // 2
radius = 50
frames = 0

while running:
    # Check for events (like closing the window)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Fill the screen with a color (white)
    screen.fill((230, 204, 255))

    # Draw a simple circle
    pygame.draw.circle(screen, (128, 0, 255), (x, y), radius)

    #slowly move the circle for next frame
    frames = frames + 1
    if frames % 10 == 0:
        x = x + 1
        y = y + 1

    # Update the display
    pygame.display.flip()

# Quit Pygame
pygame.quit()
sys.exit()