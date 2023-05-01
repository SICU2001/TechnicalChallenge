// Sofía Ingigerth Cañas Urbina 
// Kalypso Technical Challenge

#include <iostream>
#include <string>

using namespace std;

// Number of employees N and hoodies that have been assigned
int N, hoodies = 0;

int main()
{
    // Begin the system
    cout << endl << "   RANDOM GIFTS SYSTEM" << endl;
    
    // Ask for the number of employees and store it
    cout << endl << "   How many employees are there?" << endl << endl << "    ";
    cin >> N;
    cout << endl;

    // Create the list of strings or data base
    string assignedGifts[N];
    
    // Store posible gifts for assignment
    string gifts[3] = {"Backpack", "T-shirt", "Hoodie"};

    // Cycle in employees for gift assignment
    for(int i=0; i<N; i++){
            
        // If 20 hoodies have not been assigned yet then we can still give away hoodies
        if(hoodies < 20){
            
            // Generate 0, 1 or 2 randomly to decide the gift from the gift array
            int gift = rand() % 3;
            // Store the result in the database
            assignedGifts[i] = gifts[gift];
    
            // If the assigned gift is a hoodie, increase the count
            if(assignedGifts[i] == "Hoodie") hoodies++;
            
        // Else, we can only give away Backpacks and T-shirts
        }else{ 
            // Generate 0 or 1 randomly the gift from the remaining gifts
            int gift = rand() % 2;
            // Store the result in the database
            assignedGifts[i] = gifts[gift];
        }
    }

    // Headers for the displayed list
    cout << "   Employee    Gift" << endl;
    
    // Cycle in employees to display a list with the number of the employee (1 to #) and the gift assigned to her/him
    for(int i=0; i<N; i++){
        // Output the number of the employee (remember the array is 0 indexed) and the assigned gift acording to the database
        cout << "   " << i+1 << "           " << assignedGifts[i] << endl;
    }
}
