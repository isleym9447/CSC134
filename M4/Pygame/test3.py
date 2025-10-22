import pygame
import sys
import random

# Initialize Pygame
pygame.init()

# Set up the display
width, height = 600, 400
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Bouncing Circles")

# Circle settings
num_circles = 5
circles = []

# Circle class to handle each circle's properties
class Circle:
    def __init__(self):
        self.x = random.randint(50, width - 50)
        self.y = random.randint(50, height - 50)
        self.radius = random.randint(20, 50)
        self.x_velocity = random.choice([3, -3, 2, -2, 1, -1])
        self.y_velocity = random.choice([3, -3, 2, -2, 1, -1])
        self.color = random.choice([(255, 0, 0), (0, 255, 0), (0, 0, 255), (255, 255, 0), (255, 165, 0)])
        self.trail = []

    def move(self):
        self.x += self.x_velocity
        self.y += self.y_velocity

        # Bounce off the walls
        if self.x - self.radius <= 0 or self.x + self.radius >= width:
            self.x_velocity = -self.x_velocity
            self.color = random.choice([(255, 0, 0), (0, 255, 0), (0, 0, 255), (255, 255, 0), (255, 165, 0)])
        
        if self.y - self.radius <= 0 or self.y + self.radius >= height:
            self.y_velocity = -self.y_velocity
            self.color = random.choice([(255, 0, 0), (0, 255, 0), (0, 0, 255), (255, 255, 0), (255, 165, 0)])

        # Keep a trail of previous positions
        self.trail.append((self.x, self.y))
        if len(self.trail) > 10:
            self.trail.pop(0)

    def draw(self):
        # Draw the trail first (fading effect)
        for i, pos in enumerate(self.trail):
            fade_color = tuple(int(c * (1 - i / 10)) for c in self.color)
            pygame.draw.circle(screen, fade_color, (pos[0], pos[1]), self.radius)

        # Draw the current circle
        pygame.draw.circle(screen, self.color, (self.x, self.y), self.radius)

# Create multiple circles
for _ in range(num_circles):
    circles.append(Circle())

# --- Main Game Loop ---
running = True
while running:
    # Check for events (like closing the window)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Fill the screen with a background color
    screen.fill((230, 204, 255))

    # Move and draw each circle
    for circle in circles:
        circle.move()
        circle.draw()

    # Update the display
    pygame.display.flip()

    # Control the frame rate
    pygame.time.Clock().tick(60)  # 60 frames per second

# Quit Pygame
pygame.quit()
sys.exit()
