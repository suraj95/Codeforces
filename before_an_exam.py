# Problem: "Before an Exam"

# Input
# 1st line= d: days, sumTime: hours studied
# .
# ..
# ...
# i-th line= minTime: minimum hours studied, maxTime: maximum hours studied


# Output
# 1st line= YES
# 2nd line= hours spend studying each day

import sys


# Variables
d=0
sumTime=0


days =[]
minTime=0
maxTime=0

count=0

# Parse input
for line in sys.stdin:
	if count==0:		# First line			
		d=int(line.split()[0])		
		sumTime=int(line.split()[1])
		count+=1;
	else:				# i-th line
		minTime=int(line.split()[0])
		maxTime=int(line.split()[1])
		days.append((minTime,maxTime))
		count+=1;
		if d==len(days):
			break

# Check if solution is possible
minTotal=0
maxTotal=0

for item in days:
	minTime=item[0]
	maxTime=item[1]

	minTotal+=minTime
	maxTotal+=maxTime

if minTotal<=sumTime<=maxTotal:
	print("YES")

	# Greedy Solution

	output_days=[]
	hoursLeft=sumTime

	for i in range(len(days)):
		minTime=days[i][0]
		output_days.append(minTime) # make sure every day satisfies minimum study time
		hoursLeft-=minTime

	for i in range(len(days)):
		minTime=days[i][0]
		maxTime=days[i][1]

		gap=maxTime-minTime

		if gap>hoursLeft:
			output_days[i]+=hoursLeft # now fill gaps wherever possible
			hoursLeft-=hoursLeft
		else:
			output_days[i]+=gap
			hoursLeft-=gap

	# print solution
	for item in output_days:
		print(item)

else:
	print("NO")





