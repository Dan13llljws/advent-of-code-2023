from z3 import *
import os

x = Int('x')
y = Int('y')
z = Int('z')
vx = Int('vx')
vy = Int('vy')
vz = Int('vz')
s = Solver()

f = open("input.txt", "r")
for line in f:
	xyz, vxyz = line.split('@')
	x1, y1, z1 = map(int, xyz.split(','))
	vx1, vy1, vz1 = map(int, vxyz.split(','))

	s.add((x1 - x) * (vy - vy1) == (y1 - y) * (vx - vx1))
	s.add((y1 - y) * (vz - vz1) == (z1 - z) * (vy - vy1))
	s.add((z1 - z) * (vx - vx1) == (x1 - x) * (vz - vz1))
	s.add((x1 - x) / (vx - vx1) >= 0)

s.check()
print(s.model())
print(s.model()[x].as_long() + s.model()[y].as_long() + s.model()[z].as_long())


