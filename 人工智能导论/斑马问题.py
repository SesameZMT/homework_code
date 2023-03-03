from kanren import run, eq, membero, var, conde
from kanren.core import lall
x = var()
z = var()
rules = lall(
    eq(x, z), 
    eq(z, 3)
)
run(0, x, rules)