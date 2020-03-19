# Problem: Mysterious Present

# Chain here is such a sequence of envelopes A = {a1,  a2,  ...,  an}, where the width and 
# the height of the i-th envelope is strictly higher than the width and the height of the 
# (i  -  1)-th envelope respectively. Chain size is the number of envelopes in the chain.

# We have to make the chain of the maximum size from the envelopes, such that we will be able
# to put a card into it. The card fits into the chain if its width and height is lower than the 
# width and the height of the smallest envelope in the chain respectively.


import sys

# Variables

n=0 # number of envelopes
w=0	# card width
h=0	# card height

# Parse input

flag=0
count=0

chain=[]
for line in sys.stdin:
	if flag==0:		# first line			
		n=int(line.split()[0])
		w=int(line.split()[1])
		h=int(line.split()[2])
		flag+=1
	else:	
		    		# i-th line
		count+=1
		width=int(line.split()[0])
		height=int(line.split()[1])

		if width>w and height>h:  # check if card fits in this envelope

			tup=((width,height),count)	# tuple of dimensions and index
			chain.append(tup)

		if count==n:
			break



if len(chain)==0: # card does not fit in any envelope
	print(0)

else:

	# now sort the chain of envelopes
	chain.sort()

	# now we have to use Recursion or Dynamic programming check through every possible branch 
	# to get the longest chain possible

	n = len(chain)
	dp = [0]*n
	parent = [-1]*n
  
	# dp is the list that stores longest increasing subsequence
	# Declare the list (array) for dp and initialize dp 
	# values for all indexes 

	dp[0]=1       # initialize first element of dp
	for i in range(1,n):
		for j in range(0,i):
			if chain[j][0][0] < chain[i][0][0] and chain[j][0][1]<chain[i][0][1]:
				if 1+dp[j] > dp[i]:
					dp[i]=1+dp[j]
					parent[i]=j

		if(dp[i]==0):
			dp[i]=1


	# Initialize maximum to 0 to get the maximum of all 
	maximum = 1
	k=0
  
	# Pick maximum of all values 
	for i in range(n):
		if dp[i]>maximum:
			maximum = dp[i]
			k=i

	print(maximum)

	final_indexes=[]
	while True:
		final_indexes.append(chain[k][1]) # stored in reverse order
		k=parent[k]
		if k==-1:
			break

	for item in reversed(final_indexes):
		print(item)

