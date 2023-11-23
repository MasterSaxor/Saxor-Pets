# Validate email address
import re

email = input("What's your email address? ").strip()

if re.search(r"^\w+@\w+\.(com|gov|net|org|edu)$", email, re.IGNORECASE):
    print("Valid")
else:
    print("Invalid")
