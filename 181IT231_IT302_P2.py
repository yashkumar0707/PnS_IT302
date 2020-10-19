from collections import defaultdict
def solve(people,person):
    numerator=people[person][0]*people[person][1]
    denominator=0
    for i in people.keys():
        denominator+=people[i][0]*people[i][1]
    return numerator/denominator

n=int(input("Enter number of inspectors: "))
namelist=[]
for i in range(n):
    m=input("Enter name: ")
    namelist.append(m)
dic=defaultdict(list)
for i in namelist:
    per,pack=input("Enter percentage and number of packages for "+i+": ").split()
    dic[i].append(int(per)/100)
    dic[i].append(1/int(pack))
person=input("Enter name whose probability is to be checked: ")
if person not in dic:
    print("Person "+person+" is not in the list of people ",m)
else:
    print(solve(dic,person))
