for i in range(1,21,1):
    if i % 3 == 0 and i % 5 == 0 :
        print("fizzbuzz")
    elif i % 3 == 0 :
        print("fuzz")

    elif i % 5 == 0:
        print("buzz")

    else :
        print(i)


def celsius_to_f(c, unit='F'):
    if unit == 'F':
        return(c * 9/5 + 32)
    else : 
        return c

print(celsius_to_f( 32, 'C'))
print( f"{celsius_to_f( 43, 'F'):.1f}")

n = 1000
count = 0
while n > 0:
    n = n // 3
    count += 1

print(count)