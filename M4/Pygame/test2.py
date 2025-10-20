import pygame
import sys

# Initialize Pygame
pygame.init()

# Set up the display
width, height = 600, 400
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("DVD Screensaver")

# Circle settings
x = width // 2
y = height // 2
radius = 50
x_velocity = 3
y_velocity = 3

# --- Main Game Loop ---
running = True
while running:
    # Check for events (like closing the window)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Update the circle's position
    x += x_velocity
    y += y_velocity

    # Bounce off walls by reversing direction when hitting boundaries
    if x - radius <= 0 or x + radius >= width:  # Left or Right edge
        x_velocity = -x_velocity
    if y - radius <= 0 or y + radius >= height:  # Top or Bottom edge
        y_velocity = -y_velocity

    # Fill the screen with a color (white)
    screen.fill((230, 204, 255))

    # Draw the circle
    pygame.draw.circle(screen, (128, 0, 255), (x, y), radius)

    # Update the display
    pygame.display.flip()

    # Control the frame rate
    pygame.time.Clock().tick(60)  # 60 frames per second

# Quit Pygame
pygame.quit()
sys.exit()
