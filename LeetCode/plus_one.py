def main():
    digits = [1,2,3]
    plusOne(digits)
    print(digits)
def plusOne(digits):
   n = len(digits)
   for i in range(n-1, -1, -1):
       if digits[i] == 9:
           digits[i] = 0
       else:
           digits[i] += 1
           return digits
   digits[0] = 1
   digits.append(0)
   return digits


main()