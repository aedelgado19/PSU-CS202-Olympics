# PSU-CS202-Olympics
For this assignment, we were to create a program to keep track of Olympic sports and athletes to demonstrate operator overloading. Each different kind
of sport implemented the insertion and extraction operators for read and display, respectively, and the equality operator for removing nodes in the Linear Linked List.

Athletes were stored in a Binary Search Tree of Linear Linked Lists. This maintained efficient traversal time, as it is at best O(log(n)) time and at worst O(n).
However, as this was not implemented always as a balanced tree, it couldn't always be O(log(n)) time but was on average more efficient than the previous data structures
required in programming assignments. 
