def findSum():
    """
    finding sum of all numbers
    input = number of elements
    output = sum of all elements
    """
    sum = 0
    print("Enter count: ")
    count = int (input())
    for i in range(count):
        print("input a number: ")
        num = input ()
        num = int(num)
        sum += num
    print("sum of numbers: ",end ='')
    print(sum,end='\r\n')
    print("END")


from time import sleep as sl
def progress():
    print("|",end= '\r') 
    sl(1) 
    print("/",end= '\r') 
    sl(1) 
    print("-",end= '\r') 
    sl(1) 
    print("/",end= '\r') 
    sl(1) 
    print("-",end= '\r') 
    sl(1) 
    print("\\",end= '\r') 
    sl(1) 

if __name__ == "__main__":

    for i in range(10):
        progress()
    findSum()
