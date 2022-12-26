grp1 = ['A', 'B', 'C', 'D', 'E', 'F']
grp2 = ['B', 'D', 'N', 'M', 'J']
grp3 = ['E', 'N', 'F', 'K', 'S', 'Z']

r1 = []
r2 = []
r3 = []
b = []
r4 = []

def fun1():
    for i in grp1:
        for j in grp2:
            if(i==j):
                r1.append(i)

    print("Students who play both cricket and badminton ", r1)
fun1()
def fun2():
    for i in grp1:
        f=0
        for j in grp2:
            if(i==j):
                f=1
        if(f==0):
            r2.append(i)
    for j in grp2:
        f=0
        for i in grp1:
            if(i==j):
                f=1
        if(f==0):
            r2.append(j)
    print("Students who play either cricket or badminton", r2)
fun2()

def fun3():
    a = grp1+grp2
    for i in grp3:
        f=0
        for j in a:
            if(i==j):
                f=1
        if(f==0):
            r3.append(i)
    print("Students who play neither cricket nor badminton", r3)
fun3()
    
def fun4():
    for i in grp1:
        for k in grp3:
            if(i==k):
                b.append(i)
    for i in b:
        c=0
        for j in grp2:
            if(i==j):
                c=c+1
        if(c==0):
            r4.append(i)


            
    print("Students who play cricket and football but not badminton: ", r4)
fun4()
