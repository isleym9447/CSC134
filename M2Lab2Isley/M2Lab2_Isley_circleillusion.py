import turtle
import colorsys

# Setup
screen = turtle.Screen()
screen.bgcolor("black")
t = turtle.Turtle()
t.hideturtle()
t.speed(0)
t.pensize(2)

# Parameters
rings = 100
hue = 0

for i in range(rings):
    t.penup()
    
    # Move to center and set orientation
    t.goto(0, 0)
    t.setheading(i * 7)  # Controls spiral twist
    
    # Move forward to position the circle
    t.forward(i * 2)
    
    # Set color using HSV for gradient
    color = colorsys.hsv_to_rgb(hue, 1, 1)
    t.pencolor(color)
    
    # Draw decreasing size circle
    t.pendown()
    t.circle(100 - i)
    
    hue += 0.01  # Gradual color shift

turtle.done()
