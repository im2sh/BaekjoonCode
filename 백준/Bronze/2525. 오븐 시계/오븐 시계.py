h, m = map(int, input().split())
cook = int(input())

m += cook

if(m >= 60):
    while(m>=60):
        h+=1
        m-=60

if(h==24):
    h = 0
elif(h>24):
    h -= 24

print(str(h),str(m))
