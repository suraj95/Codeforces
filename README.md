## CodeForces Problems

This repository contains solutions to popular Codeforces problems. I was initially contributing to the Daily-Coding-Problems repository for my daily practice. It created by my colleague, for but updates on it were slow due to everyones busy schedule and commits to a forked repository don't count as contributions to Github. Most competitive programmers have terrible coding practices born out of the need to finish the code as fast as possible and the fact that you don’t expect someone else to read the code—— things like not using proper indentation or variable names. I will try my best to keep my code as readable as possible.

C++ is by far the the most popular language of choice for competitive programmers across the world as it is usually faster than Java and Python, and most of the resources are available in C++. I haven't coded much in C++, and I am not really doing this competitively, so I will stick to Python. Python is an amazingly user friendly language, the only flaw that it possesses is that is slow. Unless the problem I am solving has strict memory and time constraints, Python's speed should not be an issue. Also, pointers can be hard to implement and debug, and memory management can also be a big headache. Still, I will occasionally code in C++ to be in touch with it. 

The problems generally contain long stories about some people and what not. You don’t need these to solve the problem. Read the input/output formats and constraints very carefully. Understand what is asked and what is given in problem and get a brute-force solution first and optimize later. Solve for the base case first, and then look for edge cases. Analyzing your algorithm is pretty crucial in competitive programming. 

The efficiency of algorithms are generally measured in Time Complexity and Space Complexity. 

![alt text](./images/big-o.png)

It is very possible for O(N) code to run faster than 0(1) code for specific inputs. Big 0 just describes the rate of increase. For this reason, we drop the constants in runtime. An algorithm that one might have described as 0(2N) is actually O(N). And if it only goes through half of the array (in terms of iterations) does not impact the big 0 time. You should drop the non-dominant terms-— O(N^2 + N) becomes O(N^2). For example, the expression O(B^2+A) cannot be reduced without some special knowledge of A and B.
