import turtle
import time

# Setup screen
screen = turtle.Screen()
screen.bgcolor("black")
screen.title("Shining Spinning Star")
screen.tracer(0) # manual updates for animation

pen = turtle.Turtle()
pen.hideturtle()
pen.speed(0)
pen.color("yellow")
pen.pensize(2)

def draw_star(size, angle):
    pen.clear()
    pen.penup()
    pen.goto(0, -size//2)
    pen.pendown()
    pen.setheading(angle)

    for _ in range(5):
        pen.forward(size)
        pen.right(144)

# Animate spinning
angle = 0
for _ in range(200): # number of frames
    draw_star(200, angle)
    screen.update()
    time.sleep(0.05)
    angle += 5 # rotate star

turtle.done()
