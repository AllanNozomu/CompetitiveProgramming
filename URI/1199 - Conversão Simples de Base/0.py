while True:
    a = input()
    if a[0:2] == "0x":
        print(int(a, 16))
    elif int(a) < 0:
        break
    else:
        print("0x" + hex(int(a)).upper()[2:])