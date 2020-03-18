# Problem: Registration System

# Each time a new user wants to register, he sends to the system a request with his name, 
# for example, abc. If such a name does not exist in the system database, it is inserted into the 
# database, and the user gets the response OK. If the name already exists, user gets a response of 
# the name and appends a number to it (1,2,3....), for example, abc1.

import sys
from collections import defaultdict

# default value

def default():
	return 0

# variables

num_of_names=0
names_dict=defaultdict(default)


# Parse input

flag=0
count=0
for line in sys.stdin:
	if flag==0:		# first line			
		num_of_names=int(line.split()[0])		
		flag+=1;
	else:			# i-th line
		name=line.split()[0]
		names_dict[name]+=1
		count+=1

		if names_dict[name]==1:
			print("OK")
		else:
			temp=str(names_dict[name]-1)
			print(name+temp)
		
		if num_of_names==count:
			break
