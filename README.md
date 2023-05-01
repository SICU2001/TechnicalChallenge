# Technical Challenge

The Kalypso's Americas Innovation Center (AIC) is getting ready for its next opening anniversary. A system needs to be
generated to randomly distribute one gift to each one of the N current employees in Mexico.

There are 3 possible gifts:
* Backpack
* T-shirt
* Hoodie

We would like your help as an intern to generate the pseudocode to display the final list of employees and the gifts that
were assigned to them.

Here are the conditions to consider for developing the pseudocode:

**1.** Use any data structure (array, list, queue, stack, hashtable, tree, etcetera) to store the 3 different gifts. They
will act as a "database" that can be accessed to retrieve the information. Explain why you used that data
structure.

**2.** Use a cycle to display (print) a list with the number of the employee (1 to #) and the gift assigned to her/him.
**3.** There are only 20 hoodies available, so in case the 20 hoodies available have been already assigned, proceed
to only assign the Backpacks and T-shirts to the other employees. 

## Solution
For this challenge I will use the programming language C++. The implementation is included in the *KalypsoChallenge.cpp* file in this repository. 

### Data base
I will use a list of strings, since there are no employee names, it is only necessary to assign to an employee number (index in the list), a gift. In this case the gift will be represented by a string: "Backpack", "T-shirt" or "Hoodie". Other data we will collect in variables will be the number of employees *N* and the number or hoodies we have assigned at the moment, starting by 0. So we ask for this data and then create the list of strings for the data base.

```
int N, hoodies = 0;

cout << endl << "   How many employees are there?" << endl << endl << "    ";
cin >> N;

string assignedGifts[N];
```
### Gift assignment

The first step for the gift assignment will be store the possible gifts in an array.

```
string gifts[3] = {"Backpack", "T-shirt", "Hoodie"};
```
Then, we will do a for cycle in the employees for assign a gift to each one. And here we have two possiblities when assigning a gift to the i-th employee. We can have hoodies left or not. This will depend on the number of hoodies that we have assigned so far. If it is less of 20 then we have hoodies left otherwise no. And in the case we have hoodies left we generate a random number: 0, 1 or 2 to decide the gift we are assigning from the gifts array. If the assigned gift is a hoodie then count it in the respective variable. Finally we store the selection in the database and continue with the next employee.

```
for(int i=0; i<N; i++){
       
        if(hoodies < 20){
            
            int gift = rand() % 3;
            
            assignedGifts[i] = gifts[gift];
  
            if(assignedGifts[i] == "Hoodie") hoodies++; 
```


## Consideration of possible scenarios and Optimization
