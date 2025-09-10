import turtle
import math

# Setup
turtle.bgcolor("black")
turtle.speed(0)
turtle.pensize(3)
turtle.pencolor("white")

# Draw outer circle
turtle.penup()
turtle.goto(0, -150)
turtle.pendown()
turtle.circle(150)

# Draw inner circle
turtle.penup()
turtle.goto(0, -120)
turtle.pendown()
turtle.circle(120)

# Draw six spokes
for i in range(6):
    angle = i * 60
    turtle.penup()
    turtle.goto(0,0)
    turtle.setheading(angle)
    turtle.forward(120)
    turtle.pendown()
    turtle.forward(30)  # extend past inner circle to outer ring

# Draw small gaps (inner cut-outs)
turtle.pensize(15)
for i in range(6):
    angle = i * 60 + 30
    turtle.penup()
    turtle.goto(0,0)
    turtle.setheading(angle)
    turtle.forward(135)
    turtle.pendown()
    turtle.forward(15)

turtle.hideturtle()
turtle.done()