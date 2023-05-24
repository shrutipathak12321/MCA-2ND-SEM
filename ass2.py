import datetime
coupon_codes={
    "Monday": 0.10,
    "Tuesday": 0.15,
    "Wednesday": 0.20,
    "Thursday": 0.25,
    "Friday": 0.30,
    "Saturday": 0.35,
    "Sunday": 0.40,
}

current_day= datetime.datetime.now().strftime("%A")

if current_day in coupon_codes:
    discount_rate = coupon_codes[current_day]
    coupon_code= f"DISCOUNT{int(discount_rate * 100)}"
    print(f"Today is {current_day}, and the discount rate is {discount_rate *100}%")
    print(f"Use coupon code '{coupon_code}' at checkout to avail the discount!")
else:
    print("No discount for today")
