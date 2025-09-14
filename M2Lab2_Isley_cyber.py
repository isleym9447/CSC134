import turtle
import colorsys
import random

# Setup
screen = turtle.Screen()
screen.bgcolor("black")
t = turtle.Turtle()
t.speed(0)
t.width(2)
t.hideturtle()

# Parameters
lines = 120
angle = 123  # creates the sharp spiral
hue = 0

# Draw glowing cyber spiral
for i in range(lines):
    t.penup()
    t.goto(0, 0)
    t.pendown()

    # Neon color using HSV gradient
    color = colorsys.hsv_to_rgb(hue, 1, 1)
    t.pencolor(color)

    # Random glitch offset for edgy look
    glitch = random.uniform(-5, 5)
    t.forward(i * 4 + glitch)
    t.right(angle)

    hue += 0.01
    if hue > 1:
        hue = 0

# Overlay glowing circuits
t.width(1)
for _ in range(40):
    t.penup()
    t.goto(random.randint(-300, 300), random.randint(-300, 300))
    t.pendown()
    t.pencolor(random.choice(["cyan", "magenta", "lime", "deepskyblue", "hotpink"]))
    for _ in range(4):
        t.forward(random.randint(20, 80))
        t.right(90)

turtle.done()
