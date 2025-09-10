"""
CSC 134
M2Lab2 - turtle
isleym9447
9/10/25

"""
import turtle
import math

# Setup
screen = turtle.Screen()
screen.bgcolor("white")
t = turtle.Turtle()
t.speed(0)
t.hideturtle()

# Parameters
outer_radius = 150
inner_radius = 100
spoke_width = 20
num_spokes = 6

def draw_circle(radius, color):
    t.penup()
    t.goto(0, -radius)
    t.setheading(0)
    t.pendown()
    t.color(color)
    t.begin_fill()
    t.circle(radius)
    t.end_fill()

def draw_spoke(angle):
    t.penup()
    t.goto(0, 0)
    t.setheading(angle)
    t.forward(inner_radius)
    t.setheading(angle + 90)
    t.pendown()
    t.color("white")
    t.begin_fill()
    for _ in range(2):
        t.forward(spoke_width)
        t.right(90)
        t.forward(outer_radius - inner_radius)
        t.right(90)
    t.end_fill()

# Draw outer black circle
draw_circle(outer_radius, "black")

# Draw white spokes (cutouts)
angle_step = 360 / num_spokes
for i in range(num_spokes):
    draw_spoke(i * angle_step)

# Draw inner black circle to complete the look
draw_circle(inner_radius - 10, "black")

# Done
turtle.done()
