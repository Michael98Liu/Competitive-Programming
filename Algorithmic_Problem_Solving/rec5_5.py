# enumerate all possible combinations of four 4
from itertools import permutations

def evaluate(equation):
    #print(equation)
    stack = []
    postfix = []
    for i in range(len(equation)):
        if equation[i] == 4:
            postfix.append(equation[i])
        elif equation[i] == '+' or equation[i] == '-':
            while len(stack) != 0:
                p = stack.pop()
                postfix.append(p)
            stack.append(equation[i])
        else:
            while len(stack) != 0 and (stack[-1] != '-' and stack[-1] !='+'):
                p = stack.pop()
                postfix.append(p)
            stack.append(equation[i])
    while len(stack) != 0:
        p = stack.pop()
        postfix.append(p)
    #print(postfix)

    for i in range(len(postfix)):
        if postfix[i] == 4:
            stack.append(postfix[i])
        else:
            a = stack.pop()
            b = stack.pop()
            if postfix[i] == '-':
                stack.append(b - a)
            elif postfix[i] == '+':
                stack.append(b + a)
            elif postfix[i] == '*':
                stack.append(a*b)
            elif postfix[i] == '/':
                stack.append(int(b/a))
    #print(stack[0])
    return stack[0]

signs = ['+', '-', '*', '/']*3
equation = [4, '', 4, '', 4, '', 4]
allPoss = {}

for i in permutations(signs, 3):
    for ind in range(len(i)):
        equation[2*ind + 1] = i[ind]
    re = evaluate(equation)
    if int(re) == re:
        allPoss[int(re)] = equation[:]


n = int(input())
for i in range(n):
    num = int(input())
    if num in allPoss:
        equ = allPoss[num]
        equ = [str(x) for x in equ]
        print(" ".join(equ), end=" ")
        print("= {}".format(num))
    else:
        print("no solution")
