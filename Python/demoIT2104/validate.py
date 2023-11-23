import re

email = input("What's your email address? ").strip()

if re.search(r"^\w+@\w+\.(com|edu|org|gov|net)$", email, re.IGNORECASE):
    print("Valid")
else:
    print("Invalid")