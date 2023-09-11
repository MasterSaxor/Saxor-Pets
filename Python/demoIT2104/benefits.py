age = 67
income = 10000

if (age > 70) and (income < 15000):
    print("Eligible for benefits")
elif (age > 70) and (income < 20000):
    print("Eligible for reduced benefits")
elif (age < 70) and (income < 20000):
    print("Eligible for reduced benefits")
else:
    print("Not eligible for benefits")