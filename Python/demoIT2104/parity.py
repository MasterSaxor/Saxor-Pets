def main():
    num = int(input("Input a number: "))
    if is_even(num):
        print("That's even!")
    else:
        print("That's odd!")

def is_even(x):
    # return True if x % 2 == 0 else False
    return x % 2 == 0

main()
