# Codeforces Div2 A: Watermelon Problem
 
 
# Divide the watermelon (1 ≤ w ≤ 100) in such a way that each of the two parts weighs even number of kilos, 
# at the same time it is not obligatory that the parts are equal. 
 
# w=8  pairs of (4,4) or (2,6)
 
import sys
 
def divide(w):
	if w%2==0:     # sum of 2 even numbers can be written as 2n + 2m which is 2*(n+m)
		if(w==2):
			print("NO")   # 2 is an edge case
		else:
			print("YES")
	else:			   
		print("NO")
 
for line in sys.stdin:
	divide(int(line))
