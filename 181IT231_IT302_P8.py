import math
def combinations(n,r): 				#CALCULATING nCr
	ans=1
	if(n<r):
		return 0
	if(r==0 or r==n):
		return 1
	if(n-r<r):
		r=n-r
	for i in range(1,r+1):
		ans*=(n-r+i)/i
	return ans
f=open("181IT231_IT302_P8_Output_TC6.txt","w")
a=int(input("Enter value of A : "))
b=int(input("Enter value of B : "))
c=int(input("Enter value of C : "))
d=int(input("Enter value of D : "))
if(a<0 or b<0 or c<0 or d<0):
	print("INVALID INPUTS HENCE PROGRAM TERMINATED")
	f.write("INVALID INPUTS HENCE PROGRAM TERMINATED")
	f.close()
	exit(0)
f.write("INTERMEDIATE VALUES")
one=combinations(b,d)
two=combinations(a-b,c-d)
three=combinations(a,c)
prob=(one*two)/three
print("probabilty of",d,"component/s to be defective is/are : ",prob)
f.write("\nprobabilty of "+str(d)+" component/s to be defective is/are : "+str(prob))
mean=b*c/a
print("mean->",mean)
f.write("\nMEAN->"+str(mean))
variance=((a-c)/(a-1))*c*(b/a)*(1-(b/a))
print("variance->",variance)
f.write("\nVARIANCE->"+str(variance))
standard_deviation=math.sqrt(variance)
print("standard deviation->",standard_deviation)
f.write("\nSTANDARD DEVIATION->"+str(standard_deviation))
left=mean - 2*standard_deviation
#left=0 if mean - 2*standard_deviation<0 else mean - 2*standard_deviation
right=mean+2*standard_deviation
print("Chebyshev's interval for μ ± 2σ is : (",left,",",right,")")
f.write("\nChebyshev's interval : ( "+str(left)+" , "+str(right)+" ) ")
f.close()
