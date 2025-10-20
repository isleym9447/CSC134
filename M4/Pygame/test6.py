import pygame
import sys
import random
import colorsys
import math

# Initialize Pygame
pygame.init()

width, height = 1000, 600
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Colorful Bouncing Stars with Trails")

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

particles = [Particle() for _ in range(30)]

# Surface for trails with alpha
trail_surface = pygame.Surface((width, height))
trail_surface.set_alpha(50)  # trail fade amount
trail_surface.fill((0, 0, 0))

running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

        # Add a particle on mouse click
        if event.type == pygame.MOUSEBUTTONDOWN:
            particles.append(Particle())

    # Fade trails by blitting a semi-transparent black surface
    screen.blit(trail_surface, (0, 0))

    # Move and draw particles
    for p in particles:
        p.move()
        p.draw(screen)

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
sys.exit()
