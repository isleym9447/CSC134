import turtle
import colorsys

# Setup
t = turtle.Turtle()
t.speed(-5)
turtle.bgcolor("black")
t.width(2)

# Parameters
n = 300           # Number of iterations
hue = 0           # Starting hue

# Spiral loop
for i in range(n):
    # Convert HSV to RGB for a colorful gradient
    color = colorsys.hsv_to_rgb(hue, 1, 1)
    t.color(color)
    
    # Draw a line and rotate
    t.forward(i * 2)
    t.left(59)
    
    # Update hue (wraps around 1.0)
    hue += 0.007

# Finish
turtle.done()
