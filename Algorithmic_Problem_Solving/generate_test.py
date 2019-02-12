from random import randint

with open("input.txt", "w") as f:
    f.write("50\n")

    for i in range(50):
        f.write('100 ')
    f.write('\n')
    #f.write("{} {} {} {} {} {}\n".format(s1, s2, s3, s4, s5,v))
    '''
    f.write("100\n")
    for i in range(1, 101):
        x = randint(1, 100)
        f.write("{} ".format(x))
    f.write("\n")

    for i in range(1,101):
        x = randint(1, 100)
        f.write("{} ".format(x))
    f.write("\n")
    '''


    '''
    hw10_1
    f.write("1000 100000\n")

    for i in range(100000):
        a = randint(1, 1001)
        b = randint(1, 1001)
        f.write("{} {}\n".format(a, b))
    '''


    '''
    f.write("1\n")
    for i in range(194000):
        n = random.randint(0, 25)
        alpha = 'abcdefghijklmnopqrstuvwxyz'
        f.write(alpha[n])
    f.write("1\na#")
    '''
    '''
    n = random.randint(10, 1000)
    s = random.randint(10, 1000000)
    f.write("{} {}\n".format(n, s))
    for i in range(n):
        f.write("{} ".format(random.randint(-10000, 10000)))
    f.write("\n")
    '''
    '''
    option = ['y', 'n']
    f.write("1000 12\n")
    for i in range(1000):
        for j in range(12):
            f.write("{}".format(option[random.randint(0,1)]))
        f.write("\n")
    '''

    '''
    option = ["#", ".", "?"]
    f.write("500 500\n")
    for i in range(500):
        for i in range(500):
            f.write("{}".format(option[random.randint(0,1)]))
        f.write("\n")

    f.write("200 200\n")
    for i in range(200):
        for i in range(200):
            f.write("{}".format(option[random.randint(0,2)]))
        f.write("\n")
    '''
