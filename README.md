# Technical Challenge

The Kalypso's Americas Innovation Center (AIC) is getting ready for its next opening anniversary. A system needs to be generated to randomly distribute one gift to each one of the N current employees in Mexico.

There are 3 possible gifts:
* Backpack
* T-shirt
* Hoodie

We would like your help as an intern to generate the pseudocode to display the final list of employees and the gifts that were assigned to them.

Here are the conditions to consider for developing the pseudocode:

**1.** Use any data structure (array, list, queue, stack, hashtable, tree, etcetera) to store the 3 different gifts. They will act as a "database" that can be accessed to retrieve the information. Explain why you used that data structure.

**2.** Use a cycle to display (print) a list with the number of the employee (1 to #) and the gift assigned to her/him.

**3.** There are only 20 hoodies available, so in case the 20 hoodies available have been already assigned, proceed to only assign the Backpacks and T-shirts to the other employees. 

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
Then, we will do a for cycle in the employees for assign a gift to each one. And here we have two possiblities when assigning a gift to the i-th employee. We can have hoodies left or not. This will depend on the number of hoodies that we have assigned so far. If it is less of 20 then we have hoodies left, otherwise not. And in the case we have hoodies left we generate a random number: 0, 1 or 2 to decide the gift we are assigning from the gifts array. If the assigned gift is a hoodie then count it in the respective variable. Finally we store the selection in the database and continue with the next employee.

```
for(int i=0; i<N; i++){
        if(hoodies < 20){
            int gift = rand() % 3;
            assignedGifts[i] = gifts[gift];
            if(assignedGifts[i] == "Hoodie") hoodies++; 
```

In the case we do not have hoodies left we generate a random number: 0, 1 to decide the gift we are assigning from the gifts array, because 2 is not an option anymore. We store the selection in the database and continue with the next employee until finishing with the *N* employees.

```
       }else{ 
              int gift = rand() % 2;
              assignedGifts[i] = gifts[gift];
       }
}
```
### Display assignment

We use another for cycle throughout the employees but this time for consulting the information of the data base once all the employees have an assigned gift and we print the result. We print the headers of the list first (Employee -> Gift).

```
cout << "   Employee    Gift" << endl;
    
for(int i=0; i<N; i++){
        cout << "   " << i+1 << "           " << assignedGifts[i] << endl;
 }
```
### Output examples
With 10 employees:

![image](https://user-images.githubusercontent.com/84815840/235420163-a4115b10-21a3-4548-ba54-b5187cb3cdb9.png)

With 60 employees:

![image](https://user-images.githubusercontent.com/84815840/235420282-425b809d-85ad-483b-b64c-c0716531e52a.png)

![image](https://user-images.githubusercontent.com/84815840/235420591-bd7273df-0897-491f-ad9e-9c95f7f23464.png)

Note that employee number 51 is assigned the last hoodie and no more hoodies are given away after that.

## Consideration of possible scenarios and Optimization

The presented assignment method is functional and complies with assigning the three different gifts to a variable number of employees, in addition to not assigning more than 20 hoodies. The time complexity is O(n) because we iterate throughout the employees assigning gifts with a time constant method (rand) and then displaying the result. This time complexity can not be improved, because we necessarily need to cycle through the employees in the database. The space complexity is O(n) too because we are asked to store the gifts for each employee. 

We can not optimize time with other method, and we could only optimize space if we did not store the assignation in a data base, just print it once we decide and keep track of the number of hoodies with just one variable as we are currently doing. But if we want the data base then space complexity must be at least O(n) too.

In the solution of the problem we have considered the scenario when, while assigning gifts to certain employee, we run out of hoodies. At the begging the chances of getting one certain gift of the three are balanced at 33%. But when we do not have more hoodies, one of this probabilities go suddenly to 0 and the other two balance to 50%, looking like we have an infinite number of backpacks and t-shirts because an employee's assignment does not affect the following probability, at least in the way we are solving the problem. In my opinion, there are a lot of possible ways to solve the problem or assign the gifts with different methods, but it all depends and it is important to consider, the conditions we want to meet, and in this case we only have the hoodie restriction and any other restrictions depends on how we think the problem. 

If we, for example, we care that the last employees are no less likely to get a hoodie than the first ones, how is happening in this solution, so what we could do is first choose 20 random employees to give them hoodies (in case we have more than 20 employees and we want to use all the hoodies). One method of doing this is to use the rand function to generate numbers from 0 to N-1 and repeat the process until we have 20 different numbers. Then, assign to the rest either a backpack or a t-shirt. In this way, the probability for everyone of having a hoodie would be 20/N, a backpack (N-20)/(2N) and the same for the shirt.

