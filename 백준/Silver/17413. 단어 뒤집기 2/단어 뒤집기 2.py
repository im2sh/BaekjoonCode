import sys

sen = list(sys.stdin.readline().rstrip())
sen.append(' ')
temp = []
reverse_sen = []

i = 0
j = ''
stack = []
while i < len(sen):
    if sen[i] == '<' and len(stack) == 0:
        while sen[i] != '>':
            temp.append(sen[i])
            i+=1
        temp.append('>')
        i+=1
        
    elif sen[i] != ' ' and sen[i] != '<':
        stack.append(sen[i])
        i+=1

    else:
        while len(stack) != 0:
            j = stack.pop()
            temp.append(j)
        if sen[i] != '<':
            temp.append(' ')
            i+=1

reverse_sen = "".join(temp)
print(reverse_sen)


