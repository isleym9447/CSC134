import turtle
import random
import time

# Setup screen
screen = turtle.Screen()
screen.title("DVD Screensaver")
screen.bgcolor("black")
screen.setup(width=800, height=600)
screen.tracer(0)  # turn off auto-updates for smooth animation

# Create the DVD logo (rectangle placeholder)
logo = turtle.Turtle()
logo.shape("square")
logo.color("white")
logo.shapesize(stretch_wid=2, stretch_len=4)
logo.penup()
logo.speed(0)

# Movement variables (reduced speed)
dx = 2
dy = 2

# Colors for logo changes
colors = ["red", "blue", "green", "yellow", "magenta", "cyan", "white", "orange"]

# Screen boundaries
screen_width = 400
screen_height = 300

def change_color():
    logo.color(random.choice(colors))

def is_in_corner(x, y, margin=5):
    """Check if the logo is in a screen corner (with some margin)"""
    return (
        abs(x - screen_width) < margin and abs(y - screen_height) < margin or
        abs(x + screen_width) < margin and abs(y - screen_height) < margin or
        abs(x - screen_width) < margin and abs(y + screen_height) < margin or
        abs(x + screen_width) < margin and abs(y + screen_height) < margin
    )

# Main animation loop
while True:
    screen.update()
    x, y = logo.xcor(), logo.ycor()

    # Move logo
    logo.setx(x + dx)
    logo.sety(y + dy)

    # Bounce off walls
    if x + dx > screen_width or x + dx < -screen_width:
        dx *= -1
        change_color()

    if y + dy > screen_height or y + dy < -screen_height:
        dy *= -1
        change_color()

    # Corner detection
    if is_in_corner(logo.xcor(), logo.ycor(), margin=10):
        print("🎯 Corner hit!")

    # Slow it down
    time.sleep(0.01)
