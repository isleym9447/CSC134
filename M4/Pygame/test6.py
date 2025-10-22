import pygame
import sys
import random
import colorsys
import math

# Initialize Pygame
pygame.init()

width, height = 1000, 600
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Colorful Bouncing Stars with Spaceship")

clock = pygame.time.Clock()

def draw_star(surface, color, position, radius):
    """Draw a 5-point star centered at position with given radius."""
    x, y = position
    points = []
    # 5 points + 5 inner points for star shape
    for i in range(10):
        angle = i * math.pi / 5  # 36 degrees per point
        if i % 2 == 0:
            r = radius  # outer point
        else:
            r = radius * 0.5  # inner point
        px = x + r * math.sin(angle)
        py = y - r * math.cos(angle)
        points.append((px, py))
    pygame.draw.polygon(surface, color, points)

class Particle:
    def __init__(self):
        self.radius = random.randint(10, 18)
        self.x = random.uniform(self.radius, width - self.radius)
        self.y = random.uniform(self.radius, height - self.radius)
        self.vx = random.uniform(-3, 3)
        self.vy = random.uniform(-3, 3)
        self.hue = random.random()  # Hue for color cycling (0-1)
        self.saturation = 1
        self.value = 1

    def move(self):
        self.x += self.vx
        self.y += self.vy

        # Bounce off walls
        if self.x < self.radius:
            self.x = self.radius
            self.vx = -self.vx
        elif self.x > width - self.radius:
            self.x = width - self.radius
            self.vx = -self.vx

        if self.y < self.radius:
            self.y = self.radius
            self.vy = -self.vy
        elif self.y > height - self.radius:
            self.y = height - self.radius
            self.vy = -self.vy

        # Shift hue slightly for smooth color change
        self.hue = (self.hue + 0.005) % 1

    def draw(self, surface):
        # Convert HSV to RGB for smooth color cycling
        rgb = colorsys.hsv_to_rgb(self.hue, self.saturation, self.value)
        color = tuple(int(c * 255) for c in rgb)
        draw_star(surface, color, (self.x, self.y), self.radius)

    def bounce(self, spaceship):
        # Detect collision with spaceship
        dist_x = self.x - spaceship.x - spaceship.width / 2
        dist_y = self.y - spaceship.y - spaceship.height / 2
        distance = math.sqrt(dist_x**2 + dist_y**2)

        # If distance is less than sum of radii, bounce the particle
        if distance < self.radius + spaceship.width / 2:
            # Reflect velocity based on the collision angle
            normal_angle = math.atan2(dist_y, dist_x)  # Angle of the normal
            speed = math.sqrt(self.vx**2 + self.vy**2)
            reflection_angle = 2 * normal_angle - math.atan2(self.vy, self.vx)
            self.vx = speed * math.cos(reflection_angle)
            self.vy = speed * math.sin(reflection_angle)

class Spaceship:
    def __init__(self):
        self.width = 40
        self.height = 60
        self.x = width // 2
        self.y = height // 2
        self.speed = 5
        self.color = (255, 255, 255)

    def move(self, keys):
        if keys[pygame.K_w]:
            self.y -= self.speed
        if keys[pygame.K_s]:
            self.y += self.speed
        if keys[pygame.K_a]:
            self.x -= self.speed
        if keys[pygame.K_d]:
            self.x += self.speed

        # Keep spaceship within bounds
        self.x = max(0, min(self.x, width - self.width))
        self.y = max(0, min(self.y, height - self.height))

    def draw(self, surface):
        # Simple triangle spaceship design
        points = [
            (self.x + self.width // 2, self.y),  # top point
            (self.x, self.y + self.height),  # bottom-left
            (self.x + self.width, self.y + self.height),  # bottom-right
        ]
        pygame.draw.polygon(surface, self.color, points)

# Create particles
particles = [Particle() for _ in range(30)]

# Surface for trails with alpha
trail_surface = pygame.Surface((width, height))
trail_surface.set_alpha(50)  # trail fade amount
trail_surface.fill((0, 0, 0))

# Create spaceship
spaceship = Spaceship()

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Handle spaceship movement
    keys = pygame.key.get_pressed()
    spaceship.move(keys)

    # Fade trails by blitting a semi-transparent black surface
    screen.blit(trail_surface, (0, 0))

    # Move and draw particles
    for p in particles:
        p.move()
        p.bounce(spaceship)  # Make particles bounce off the spaceship
        p.draw(screen)

    # Draw the spaceship
    spaceship.draw(screen)

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
sys.exit()
