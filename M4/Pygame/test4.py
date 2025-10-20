import pygame
import sys
import random
import math

# Initialize Pygame
pygame.init()

# Set up the display
width, height = 600, 400
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Happy & Sad Bouncing Blobs")

# Pastel colors for blobs
PASTEL_COLORS = [
    (255, 179, 186),  # pastel pink
    (255, 223, 186),  # pastel orange
    (255, 255, 186),  # pastel yellow
    (186, 255, 201),  # pastel green
    (186, 225, 255),  # pastel blue
]

class Blob:
    def __init__(self):
        self.radius = random.randint(30, 40)
        self.x = random.randint(self.radius, width - self.radius)
        self.y = random.randint(self.radius, height - self.radius)
        self.x_velocity = random.choice([2, -2, 1.5, -1.5])
        self.y_velocity = random.choice([2, -2, 1.5, -1.5])
        self.color = random.choice(PASTEL_COLORS)
        self.squish = 0  # Amount of squish for bounce effect
        self.happy = False  # Start with a sad face
        self.touching_edge = False  # To track if currently touching edge

    def move(self):
        self.x += self.x_velocity
        self.y += self.y_velocity

        # Check for collisions
        touching = (
            self.x - self.radius <= 0 or
            self.x + self.radius >= width or
            self.y - self.radius <= 0 or
            self.y + self.radius >= height
        )

        # Bounce logic
        if touching:
            # Only toggle if wasn't touching edge last frame
            if not self.touching_edge:
                # Reverse velocity for edges hit
                if self.x - self.radius <= 0 or self.x + self.radius >= width:
                    self.x_velocity = -self.x_velocity
                if self.y - self.radius <= 0 or self.y + self.radius >= height:
                    self.y_velocity = -self.y_velocity

                self.squish = 0.5  # start squish animation
                self.happy = not self.happy  # toggle face on bounce

            self.touching_edge = True
        else:
            self.touching_edge = False

        # Animate squish effect (shrink and release)
        if self.squish > 0:
            self.squish -= 0.05
        else:
            self.squish = 0

    def draw(self):
        # Squish scales radius horizontally and vertically
        scale_x = 1 + self.squish
        scale_y = 1 - self.squish

        # Draw the blob (ellipse to show squish)
        blob_rect = pygame.Rect(0, 0, int(self.radius * 2 * scale_x), int(self.radius * 2 * scale_y))
        blob_rect.center = (self.x, self.y)
        pygame.draw.ellipse(screen, self.color, blob_rect)

        # Draw cute face (happy or sad based on the state)
        eye_y = self.y - self.radius // 4 * scale_y
        eye_x_offset = self.radius // 2 * scale_x
        eye_radius = int(self.radius * 0.15)

        # Eyes
        pygame.draw.circle(screen, (50, 50, 50), (int(self.x - eye_x_offset), int(eye_y)), eye_radius)
        pygame.draw.circle(screen, (50, 50, 50), (int(self.x + eye_x_offset), int(eye_y)), eye_radius)

        # Draw the mouth (happy or sad)
        smile_width = self.radius * scale_x
        smile_height = self.radius * 0.5 * scale_y
        smile_rect = pygame.Rect(0, 0, smile_width, smile_height)
        smile_rect.center = (self.x, self.y + self.radius // 4 * scale_y)

        # If the blob is happy, draw a smiling arc; otherwise, a sad one
               
        if self.happy:
            # Make the smile much happier (arc upwards)
            pygame.draw.arc(screen, (50, 50, 50), smile_rect, -math.pi/3, math.pi/3, 3)  # Happy, more curved up
        else:
            # Sad frown
            pygame.draw.arc(screen, (50, 50, 50), smile_rect, math.pi/6, 5*math.pi/6, 3)  # Sad frown



# Create blobs
num_blobs = 6
blobs = [Blob() for _ in range(num_blobs)]

# --- Main Loop ---
clock = pygame.time.Clock()
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Background: soft pastel pink
    screen.fill((255, 240, 245))

    # Move and draw blobs
    for blob in blobs:
        blob.move()
        blob.draw()

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
sys.exit()
