def main():
    s =  input()
    count = 0
    for i in s:
        if i == 's':
            count += 1
        else:
            count = 0
        if count == 2:
            print("hiss")
            return
    print("no hiss")


main()
