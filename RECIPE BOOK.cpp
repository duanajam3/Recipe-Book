# RECIPE BOOK
#include <iostream>
#include <string>

using namespace std;

// Grouping The Variables
    struct Recipe{
    string name;
    string ingredients;
    string instructions;
};

// Arrays to store credentials and recipes
const int MAX_USERS = 10;
const int MAX_RECIPES = 100;
string usernames[MAX_USERS];
string passwords[MAX_USERS];
Recipe breakfastRecipes[MAX_RECIPES];
Recipe lunchRecipes[MAX_RECIPES];
Recipe dinnerRecipes[MAX_RECIPES];
int numUsers = 0;
int numBreakfastRecipes = 0;
int numLunchRecipes = 0;
int numDinnerRecipes = 0;

// Functions
bool registerUser();
bool loginUser();
void displayMenu();
void addRecipe(Recipe recipes[], int& numRecipes);
void editRecipe(Recipe recipes[], int numRecipes);
void deleteRecipe(Recipe recipes[], int& numRecipes);
void searchRecipe(const Recipe recipes[], int numRecipes);
// Main Program
int main() {
    int choice;
    bool loggedIn = false;

   
    do {
// Login or Register
        if (!loggedIn) {
            cout << "=== Recipe Book ===\n";
            cout << "1. Register\n";
            cout << "2. Login\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore(); // Clear unwanted variables 

            switch (choice) {
                case 1:
                    if (numUsers < MAX_USERS) {
                        if (registerUser()) {
                            cout << "Registration successful!\n";
                        } else {
                            cout << "Registration failed. Try again later.\n";
                        }
                    } else {
                        cout << "Maximum number of users reached.\n";
                    }
                    break;
                case 2:
                    loggedIn = loginUser();
                    if (!loggedIn) {
                        cout << "Login failed. Incorrect username or password.\n";
                    }
                    break;
                case 3:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } else {
// Display main menu
            displayMenu();
            cin >> choice;
            cin.ignore(); 

            switch (choice) {
                case 1:
                    addRecipe(breakfastRecipes, numBreakfastRecipes);
                    break;
                case 2:
                    addRecipe(lunchRecipes, numLunchRecipes);
                    break;
                case 3:
                    addRecipe(dinnerRecipes, numDinnerRecipes);
                    break;
                case 4:
                    editRecipe(breakfastRecipes, numBreakfastRecipes);
                    break;
                case 5:
                    editRecipe(lunchRecipes, numLunchRecipes);
                    break;
                case 6:
                    editRecipe(dinnerRecipes, numDinnerRecipes);
                    break;
                case 7:
                    deleteRecipe(breakfastRecipes, numBreakfastRecipes);
                    break;
                case 8:
                    deleteRecipe(lunchRecipes, numLunchRecipes);
                    break;
                case 9:
                    deleteRecipe(dinnerRecipes, numDinnerRecipes);
                    break;
                case 10:
                    searchRecipe(breakfastRecipes, numBreakfastRecipes);
                    break;
                case 11:
                    searchRecipe(lunchRecipes, numLunchRecipes);
                    break;
                case 12:
                    searchRecipe(dinnerRecipes, numDinnerRecipes);
                    break;
                case 13:
                    cout << "Logging out...\n";
                    loggedIn = false;
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }

    } while (choice != 3);

    return 0;
}

bool registerUser() {
    if (numUsers < MAX_USERS) {
        cout << "Enter new username: ";
        getline(cin, usernames[numUsers]);
        cout << "Enter new password: ";
        getline(cin, passwords[numUsers]);
        numUsers++;
        return true;
    } else {
        cout << "Maximum number of users reached.\n";
        return false;
    }
}

bool loginUser() {
    string username, password;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);

    for (int i = 0; i < numUsers; ++i) {
        if (usernames[i] == username && passwords[i] == password) {
            cout << "Login successful!\n";
            return true;
        }
    }
    return false;
}

void displayMenu() {
    cout << "\n=== Main Menu ===\n";
    cout << "1. Add Breakfast Recipe\n";
    cout << "2. Add Lunch Recipe\n";
    cout << "3. Add Dinner Recipe\n";
    cout << "4. Edit Breakfast Recipe\n";
    cout << "5. Edit Lunch Recipe\n";
    cout << "6. Edit Dinner Recipe\n";
    cout << "7. Delete Breakfast Recipe\n";
    cout << "8. Delete Lunch Recipe\n";
    cout << "9. Delete Dinner Recipe\n";
    cout << "10. Search Breakfast Recipes\n";
    cout << "11. Search Lunch Recipes\n";
    cout << "12. Search Dinner Recipes\n";
    cout << "13. Logout\n";
    cout << "Enter your choice: ";
}

void addRecipe(Recipe recipes[], int& numRecipes) {
    if (numRecipes < MAX_RECIPES) {
        Recipe recipe;
        cout << "Enter recipe name: ";
        getline(cin, recipe.name);
        cout << "Enter ingredients: ";
        getline(cin, recipe.ingredients);
        cout << "Enter instructions: ";
        getline(cin, recipe.instructions);
        recipes[numRecipes] = recipe;
        numRecipes++;
        cout << "Recipe added successfully.\n";
    } else {
        cout << "Maximum number of recipes reached.\n";
    }
}

void editRecipe(Recipe recipes[], int numRecipes) {
    int index;
    cout << "Enter index of recipe to edit (0-" << numRecipes - 1 << "): ";
    cin >> index;
    cin.ignore(); 

    if (index >= 0 && index < numRecipes) {
        cout << "Enter new recipe name: ";
        getline(cin, recipes[index].name);
        cout << "Enter new ingredients: ";
        getline(cin, recipes[index].ingredients);
        cout << "Enter new instructions: ";
        getline(cin, recipes[index].instructions);
        cout << "Recipe edited successfully.\n";
    } else {
        cout << "Invalid index.\n";
    }
}

void deleteRecipe(Recipe recipes[], int& numRecipes) {
    int index;
    cout << "Enter index of recipe to delete (0-" << numRecipes - 1 << "): ";
    cin >> index;
    cin.ignore(); 

    if (index >= 0 && index < numRecipes) {
        for (int i = index; i < numRecipes - 1; ++i) {
            recipes[i] = recipes[i + 1];
        }
        numRecipes--;
        cout << "Recipe deleted successfully.\n";
    } else {
        cout << "Invalid index.\n";
    }
}

void searchRecipe(const Recipe recipes[], int numRecipes) {
    string searchName;
    bool found = false;
    cout << "Enter recipe name to search for: ";
    getline(cin, searchName);

    for (int i = 0; i < numRecipes; ++i) {
        if (recipes[i].name == searchName) {
            cout << "\n=== Recipe Found ===\n";
            cout << "Name: " << recipes[i].name << endl;
            cout << "Ingredients: " << recipes[i].ingredients << endl;
            cout << "Instructions: " << recipes[i].instructions << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Recipe not found.\n";
    }
}
# DUA NAJAM