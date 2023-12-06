#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <iterator>
#include <limits.h>
#include <limits>
#include<queue>
#include <stack>
#include <chrono>
#include <iomanip>

using namespace std::chrono;
using namespace std;

struct Recipe{
public:
    string name;
    string minutes;
    string numbIngredients;
    string numbSteps;
    unordered_set<string> ingredients;
    string nutrition;
    string steps;
    string description;

    bool operator<(const Recipe& x) const {
        return this->numbIngredients < x.numbIngredients;
    }

    void printRecipeInfo() const {
        cout << "\nRecipe Information" << endl;
        cout << "------------------" << endl;
        cout << "Recipe Name: " << name << endl;
        cout << "Cooking Time (in minutes): " << minutes << endl;
        cout << "Number of Ingredients: " << numbIngredients << endl;
        cout << "Number of Steps: " << numbSteps << endl;
        cout << endl;
        cout << "Necessary Ingredients: " << endl;
        for (auto iter = ingredients.begin(); iter != ingredients.end(); ++iter) {
            if (iter != ingredients.begin()) {
                cout << endl;
            }
            cout << *iter;
        }
        cout << endl;
        cout << "\nNutrition Facts: " << nutrition << endl;
        cout << endl;
        cout << "Steps: " << steps << endl;
        cout << endl;
        cout << "Description: " << description << endl;
        cout << "________________________________________________________________________________________________________________________"
             << endl;
    }
};

class Graph{
private:
    int vertices;

public:
    Graph();
    unordered_map<int, vector<pair<int,int>>> adjList;
    unordered_map<int, Recipe> mapper;
    unordered_map<string, vector<int>> ingredientMapper;
    void readCSV(string& filename);
    void graphConnectorAlgorithm();
    void writeGraphToCSV(string& filename);
    void readForGraphCreation(string& filename);
    vector<string> askForUserInput();
    void everyRecipeWithOnlyExactIngredients(vector<string>& list);
    void everyRecipeWithInputIngredientsPlusExtraIngredients(vector<string>& list);
    void SearchRecipesWithExactIngredientsDijkstra(vector<string>& list);
    void SearchRecipesWithInputIngredientsPlusExtraIngredientsDijkstra(vector<string>& list);
    void SearchRecipesWithExactIngredientsBFS(vector<string>& list);
    void SearchRecipesWithInputIngredientsPlusExtraIngredientsBFS(vector<string>& list);
    void SearchRecipesWithExactIngredientsDFS(vector<string>& list);
    void SearchRecipesWithInputIngredientsPlusExtraIngredientsDFS(vector<string>& list);
    void FindVerySimilarRecipes();
};

void printMenu() {
    cout << "\033[1;32mSelect an option:\033[0m" << "\n" << endl;
    cout << "\033[1;33m1. Test Dijkstra algorithm search for recipes with exact ingredients\033[0m\n";
    cout << "\033[1;33m2. Test Dijkstra algorithm search for recipes with ingredients plus extra ingredients\033[0m\n";
    cout << "\033[1;33m3. Test BFS search for recipes with exact ingredients\033[0m\n";
    cout << "\033[1;33m4. Test BFS search for recipes with ingredients plus extra ingredients\033[0m\n";
    cout << "\033[1;33m5. Test DFS search for recipes with exact ingredients\033[0m\n";
    cout << "\033[1;33m6. Test DFS search for recipes with ingredients plus extra ingredients\033[0m\n";
    cout << "\033[1;33m7. Search recipes with exact ingredients\033[0m\n";
    cout << "\033[1;33m8. Search recipes with input ingredients plus extra ingredients\033[0m\n";
    cout << "\033[1;33m9.Test the FindSimilarRecipes function\033[0m\n";
    cout << "\033[1;33m0. Exit the program\033[0m\n";
}

int main() {
    Graph test;
    string filename = "RAW_recipes1.csv";
    test.readCSV(filename);
    cout << "\033[41m___________________¶¶¶¶¶¶\033[0m" << endl;
    cout << "\033[41m_________________¶¶¶¶¶___¶¶\033[0m" << endl;
    cout << "\033[41m________________¶¶¶¶¶¶¶___¶\033[0m" << endl;
    cout << "\033[41m_______________¶¶¶¶¶¶¶¶¶¶¶¶¶\033[0m" << endl;
    cout << "\033[41m___________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶\033[0m" << endl;
    cout << "\033[41m________¶¶¶¶¶___¶¶¶¶¶¶¶¶¶¶¶____¶¶¶¶¶\033[0m" << endl;
    cout << "\033[41m_____¶¶¶¶_________¶¶¶¶¶¶__________¶¶¶\033[0m" << endl;
    cout << "\033[41m____¶¶¶______¶____________________¶__¶¶¶\033[0m" << endl;
    cout << "\033[41m___¶¶________¶¶__¶¶_____¶¶__¶¶¶________¶¶\033[0m" << endl;
    cout << "\033[41m__¶¶_______________¶¶__¶¶_____¶¶¶_______¶¶\033[0m" << endl;
    cout << "\033[41m_¶¶______________________________________¶\033[0m" << endl;
    cout << "\033[41m¶¶________________________________________¶\033[0m" << endl;
    cout << "\033[41m¶¶________________________________________¶\033[0m" << endl;
    cout << "\033[41m_¶¶¶____________________________________¶¶\033[0m" << endl;
    cout << "\033[41m___¶¶¶¶¶____________________________¶¶¶¶¶\033[0m" << endl;
    cout << "\033[33m____¶_¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶_¶\033[0m" << endl;
    cout << "\033[33m_____¶____¶_____¶____¶¶____¶_____¶¶___¶¶\033[0m" << endl;
    cout << "\033[33m_____¶____¶¶____¶____¶¶____¶_____¶____¶\033[0m" << endl;
    cout << "\033[33m_____¶¶____¶____¶¶___¶¶___¶¶____¶¶___¶¶\033[0m" << endl;
    cout << "\033[33m______¶____¶¶___¶¶___¶¶___¶____¶____¶¶\033[0m" << endl;
    cout << "\033[33m______¶¶____¶___¶¶___¶¶___¶___¶___¶¶\033[0m" << endl;
    cout << "\033[33m_______¶____¶¶___¶___¶¶___¶____¶___¶¶\033[0m" << endl;
    cout << "\033[33m_______¶¶___¶¶___¶___¶¶___¶____¶___¶¶\033[0m" << endl;
    cout << "\033[33m________¶____¶¶__¶¶__¶¶__¶¶___¶¶___¶\033[0m" << endl;
    cout << "\033[33m________¶¶____¶___¶__¶¶__¶___¶¶__¶¶\033[0m" << endl;
    cout << "\033[33m_________¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶\033[0m" << "\n" << endl;

    cout << "\x1b[34m█┼┼┼█ ███ █┼┼ ███ ███ █▄┼▄█ ███ ┼┼ ███ ███ ┼┼ ███ █┼█ ███ ┼┼ ███ ███ ███ ███ ███ ███ ┼┼ ████ ███ █┼┼█ ███ ███ ███ ███ ███ ███." << endl;
    cout << "\x1b[34m█┼█┼█ █▄┼ █┼┼ █┼┼ █┼█ █┼█┼█ █▄┼ ┼┼ ┼█┼ █┼█ ┼┼ ┼█┼ █▄█ █▄┼ ┼┼ █▄┼ █▄┼ █┼┼ ┼█┼ █▄█ █▄┼ ┼┼ █▄▄▄ █▄┼ ██▄█ █▄┼ █▄┼ █▄█ ┼█┼ █┼█ █▄┼▀" << endl;
    cout << "\x1b[34m█▄█▄█ █▄▄ █▄█ ███ █▄█ █┼┼┼█ █▄▄ ┼┼ ┼█┼ █▄█ ┼┼ ┼█┼ █┼█ █▄▄ ┼┼ █┼█ █▄▄ ███ ▄█▄ █┼┼ █▄▄ ┼┼ █▄▄█ █▄▄ █┼██ █▄▄ █┼█ █┼█ ┼█┼ █▄█ █┼█ ▀" << "\n" << endl;

    string filenameTwo = "GraphData5.csv";
    test.readForGraphCreation(filenameTwo);

    int choice;
    do {
        printMenu();
        cin >> choice;

        // Input validation to clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        switch (choice) {

            case 1: {
                // Test Dijkstra algorithm search for recipes with exact ingredients
                vector<string> userInput = test.askForUserInput();
                auto startA = high_resolution_clock::now();
                test.SearchRecipesWithExactIngredientsDijkstra(userInput);
                auto stopA = high_resolution_clock::now();
                duration<double> d = stopA - startA;
                cout << fixed << setprecision(3) << "Dijkstra's algorithm takes " << d.count() << " seconds to search for recipes with exact ingredients." << endl;
                break;
            }
            case 2: {
                // Test Dijkstra algorithm search for recipes with ingredients plus extra ingredients
                vector<string> userInput = test.askForUserInput();
                auto startB = high_resolution_clock::now();
                test.SearchRecipesWithInputIngredientsPlusExtraIngredientsDijkstra(userInput);
                auto stopB = high_resolution_clock::now();
                duration<double> d = stopB - startB;
                cout << fixed << setprecision(3) << "Dijkstra's algorithm takes " << d.count() << " seconds to search for recipes with extra ingredients." << endl;
                break;
            }
            case 3: {
                // Test BFS search for recipes with exact ingredients
                vector<string> userInput = test.askForUserInput();
                auto startC = high_resolution_clock::now();
                test.SearchRecipesWithExactIngredientsBFS(userInput);
                auto stopC = high_resolution_clock::now();
                duration<double> d = stopC - startC;
                cout << fixed << setprecision(3) << "BFS algorithm takes " << d.count() << " seconds to search for recipes with exact ingredients." << endl;
                break;
            }
            case 4: {
                // Test BFS search for recipes with ingredients plus extra ingredients
                vector<string> userInput = test.askForUserInput();
                auto startD = high_resolution_clock::now();
                test.SearchRecipesWithInputIngredientsPlusExtraIngredientsBFS(userInput);
                auto stopD = high_resolution_clock::now();
                duration<double> d = stopD - startD;
                cout << fixed << setprecision(3) << "BFS algorithm takes " << d.count() << " seconds to search for recipes with extra ingredients." << endl;
                break;
            }
            case 5: {
                // Test DFS search for recipes with exact ingredients
                vector<string> userInput = test.askForUserInput();
                auto startE = high_resolution_clock::now();
                test.SearchRecipesWithExactIngredientsDFS(userInput);
                auto stopE = high_resolution_clock::now();
                duration<double> d = stopE - startE;
                cout << fixed << setprecision(3) << "DFS algorithm takes " << d.count() << " seconds to search for recipes with exact ingredients." << endl;
                break;
            }
            case 6: {
                // Test DFS search for recipes with ingredients plus extra ingredients
                vector<string> userInput = test.askForUserInput();
                auto startF = high_resolution_clock::now();
                test.SearchRecipesWithInputIngredientsPlusExtraIngredientsDFS(userInput);
                auto stopF = high_resolution_clock::now();
                duration<double> d = stopF - startF;
                cout << fixed << setprecision(3) << "DFS algorithm takes " << d.count() << " seconds to search for recipes with extra ingredients." << endl;
                break;
            }
            case 7: {
                vector<string> userInput = test.askForUserInput();
                auto startG = high_resolution_clock::now();
                test.everyRecipeWithOnlyExactIngredients(userInput);
                auto stopG = high_resolution_clock::now();
                duration<double> d = stopG - startG;
                cout << fixed << setprecision(3) << "It takes " << d.count() << " seconds to search for recipes with exact ingredients" << endl;
                break;
            }
            case 8: {
                vector<string> userInput = test.askForUserInput();
                auto startH = high_resolution_clock::now();
                test.everyRecipeWithInputIngredientsPlusExtraIngredients(userInput);
                auto stopH = high_resolution_clock::now();
                duration<double> d = stopH - startH;
                cout << fixed << setprecision(3) << "It takes " << d.count() << " seconds to search for recipes with extra ingredients" << endl;
                break;
            }
            case 9: {
                // Test the FindSimilarRecipes function
                test.FindVerySimilarRecipes();
                break;
            }
            case 0:
                cout << "\x1b[31mExiting the app. Goodbye!\x1b[0m" << endl;
                break;

            default:
                cout << "\x1b[31mInvalid choice. Please enter a valid option.\x1b[0m" << endl;
        }

    } while (choice != 0);

    return 0;
}


Graph::Graph()
{
    vertices = 0;
}


void Graph::readCSV(string& filename) {
    int counter = 1;
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        // Skip the header line
        getline(file, line);

        // Read each line in the CSV file
        while (getline(file, line)) {
            istringstream iss(line);

            Recipe node;

            // Read values from each column
            string var1;
            getline(iss, var1, ',');
            node.name = var1;

            string var2;
            getline(iss, var2, ',');
            node.minutes = var2;

            string var3;
            getline(iss, var3, ',');
            node.numbIngredients = var3;

            string var4;
            getline(iss, var4, ',');
            node.numbSteps = var4;

            string getRid;
            getline(iss, getRid, '[');

            // Read and process the ingredients
            string var5;
            getline(iss, var5, ']');
            int pos = var5.find(",");
            string token = var5.substr(0, pos);
            node.ingredients.insert(token);
            ingredientMapper[token].push_back(counter);
            var5 = var5.substr(pos + 2);
            pos = var5.find(",");
            while (pos != string::npos) {
                token = var5.substr(0, pos);
                node.ingredients.insert(token);
                ingredientMapper[token].push_back(counter);
                var5 = var5.substr(pos + 2);
                pos = var5.find(",");
            }
            node.ingredients.insert(var5);
            ingredientMapper[var5].push_back(counter);

            getline(iss, getRid, '[');

            // Read and process the nutrition information
            string var6;
            getline(iss, var6, ']');
            node.nutrition = var6;

            getline(iss, getRid, '[');

            // Read and process the steps
            string var7;
            getline(iss, var7, ']');
            node.steps = var7;

            getline(iss, getRid, ',');

            // Read the description
            string var8;
            getline(iss, var8);
            node.description = var8;

            // Add the recipe to the adjacency list and mapper
            adjList[counter] = {};
            mapper[counter] = node;
            ++counter;
        }

        file.close();
    } else {
        cerr << "\x1b[31mUnable to open file: " << filename << "\x1b[0m" << endl;
    }
}



void Graph::graphConnectorAlgorithm()
{
    // Create a temporary map to store recipes
    unordered_map<int, Recipe> temp;
    temp = mapper;

    // Iterate over each recipe in the graph
    for (auto iter = adjList.begin(); iter != adjList.end(); ++iter)
    {
        // Create a multimap to store rankings of other recipes based on ingredient similarity
        multimap<int, int, greater<int>> recipeRankings;

        // Iterate over each recipe in the temporary map
        for (auto iterTwo = temp.begin(); iterTwo != temp.end(); ++iterTwo)
        {
            int score = 0;

            // Calculate ingredient similarity score between the current recipes
            if (iter->first != iterTwo->first && iter->first != 2163)
            {
                for (auto iterThree = mapper[iter->first].ingredients.begin(); iterThree != mapper[iter->first].ingredients.end(); ++iterThree)
                {
                    if (iterTwo->second.ingredients.find(*iterThree) != iterTwo->second.ingredients.end())
                    {
                        ++score;
                    }
                }

                // Insert the recipe into the multimap based on the score
                recipeRankings.insert({score, iterTwo->first});
            }
        }

        // Skip the top 10,000 recipes (for demonstration purposes)
        auto iterFour = recipeRankings.begin();
        for (int i = 0; i < 10000; i++)
        {
            if (iterFour != recipeRankings.end())
            {
                ++iterFour;
            }
        }

        // Erase the skipped recipes
        recipeRankings.erase(iterFour, recipeRankings.end());

        // Connect the current recipe to the top recipes in the multimap
        for (iterFour = recipeRankings.begin(); iterFour != recipeRankings.end(); ++iterFour)
        {
            int weight = 0;
            weight = mapper[iterFour->second].ingredients.size() - iterFour->first;

            // Ensure weight is non-negative
            if (weight < 0)
            {
                weight = 0;
            }

            // Connect the recipes with their calculated weight
            iter->second.push_back(make_pair(iterFour->second, weight));
        }

        // Connect the current recipe to a dummy recipe (2163) with a weight of 100
        iter->second.push_back(make_pair(2163, 100));

        // Remove the current recipe from the temporary map
        temp.erase(iter->first);
        iterFour = recipeRankings.begin();

        // Skip the next 200 recipes in the multimap and remove them from the temporary map
        for (int i = 0; i < 200; i++)
        {
            if (iterFour != recipeRankings.end())
            {
                temp.erase(iterFour->second);
                ++iterFour;
            }
        }
    }

    // Connect all recipes to a dummy recipe (2163) with a weight of 100
    for (auto iter = mapper.begin(); iter != mapper.end(); ++iter)
    {
        adjList[2163].push_back(make_pair(iter->first, 100));
    }
}


void Graph::writeGraphToCSV(string& filename)
{
    // Open the output file for writing
    std::ofstream myfile;
    myfile.open(filename);

    // Iterate over each vertex in the graph
    for (auto iter = adjList.begin(); iter != adjList.end(); ++iter)
    {
        // Write the vertex ID to the file
        myfile << iter->first << ",";

        // Iterate over each neighbor of the current vertex
        for (auto iterTwo = iter->second.begin(); iterTwo != iter->second.end(); ++iterTwo)
        {
            // Write the neighbor's ID and edge weight to the file
            myfile << iterTwo->first << "," << iterTwo->second << ",";
        }

        // Move to the next line for the next vertex
        myfile << "\n";
    }

    // Close the output file
    myfile.close();
}


void Graph::readForGraphCreation(string& filename)
{
    // Open the input file for reading
    ifstream file(filename);

    // Check if the file is open successfully
    if (file.is_open())
    {
        string line;

        // Read each line from the file
        while (getline(file, line))
        {
            istringstream iss(line);
            string a;
            string b;
            string c;

            // Extract the first value from the line (vertex ID)
            getline(iss, a, ',');

            // Iterate over the remaining values separated by commas (neighbors and weights)
            while (getline(iss, b, ','))
            {
                getline(iss, c, ',');

                // Convert the values to integers and add the neighbor and weight to the adjacency list
                adjList[stoi(a)].push_back(make_pair(stoi(b), stoi(c)));
            }
        }

        // Close the input file
        file.close();
    }
    else
    {
        // Display an error message if the file is not open
        cout << "\x1b[31mFile is not open!\x1b[0m" << endl;
    }
}


vector<string> Graph::askForUserInput()
{
    // Prompt the user to enter ingredients
    cout << "\033[32mPlease enter ingredients (enter 'done' in a new line to stop): \033[0m" << endl;

    string input;
    vector<string> inputList;

    // Read input from the user until 'done' is entered
    while (getline(cin, input))
    {
        // Check if the user entered 'done' to stop input
        if (input == "done")
        {
            break;
        }
        else
        {
            // Add the entered ingredient to the list
            inputList.push_back(input);
        }
    }

    // Return the list of entered ingredients
    return inputList;
}


void Graph::everyRecipeWithOnlyExactIngredients(vector<string>& list)
{
    // Set to keep track of recipes that match the criteria
    unordered_set<string> keepTrack;

    // Check if the list contains less than two ingredients
    if (list.size() < 2)
    {
        cout << "\x1b[31mNo recipes with ONLY " << list[0] << "\x1b[0m" << endl;
    }
    else
    {
        // Iterate over each ingredient in the list
        for (int i = 0; i < list.size(); i++)
        {
            // Iterate over each recipe containing the current ingredient
            for (int j = 0; j < ingredientMapper[list[i]].size(); j++)
            {
                // Get the ID of the recipe containing the current ingredient
                int spot = ingredientMapper[list[i]][j];

                // Check if the recipe has exactly the same number of ingredients as in the list
                if (mapper[spot].ingredients.size() == list.size())
                {
                    // Iterate over each ingredient in the list
                    for (int k = 0; k < list.size(); k++)
                    {
                        // Check if the current ingredient is not present in the recipe
                        if (mapper[spot].ingredients.find(list[k]) == mapper[spot].ingredients.end())
                        {
                            break;  // Exit the loop if a mismatch is found
                        }
                        else
                        {
                            // If all ingredients match, add the recipe name to the set
                            if (k == list.size() - 1)
                            {
                                keepTrack.insert(mapper[spot].name);
                            }
                        }
                    }
                }
            }
        }
    }

    // Check if no matching recipes were found
    if (keepTrack.size() == 0)
    {
        cout << "\033[1;31mNo Recipe Found!\033[0m" << endl;
    }
    else
    {
        // Iterate over all recipes and print information for those in the set
        for (const auto &recipe: mapper)
        {
            if (keepTrack.find(recipe.second.name) != keepTrack.end())
                recipe.second.printRecipeInfo();
        }
    }
}


void Graph::everyRecipeWithInputIngredientsPlusExtraIngredients(vector<string>& list)
{
    // Set to keep track of recipes that match the criteria
    unordered_set<int> keepTrack;

    // Iterate over the first ingredient in the list
    for (int i = 0; i < 1; i++)
    {
        // Iterate over each recipe containing the current ingredient
        for (int j = 0; j < ingredientMapper[list[i]].size(); j++)
        {
            // Add the recipe ID to the set
            keepTrack.insert(ingredientMapper[list[i]][j]);
        }
    }

    // Create a copy of the set to track matching recipes
    unordered_set<int> trackCopy = keepTrack;

    // Iterate over the remaining ingredients in the list
    for (int i = 1; i < list.size(); i++)
    {
        // Iterate over each recipe in the set
        for (auto iter = keepTrack.begin(); iter != keepTrack.end(); ++iter)
        {
            // Check if the current ingredient is not present in the recipe
            if (find(ingredientMapper[list[i]].begin(), ingredientMapper[list[i]].end(), *iter) == ingredientMapper[list[i]].end())
            {
                // Remove the recipe from the copy set if the ingredient is not present
                trackCopy.erase(*iter);
            }
        }
    }

    // Check if no matching recipes were found
    if (trackCopy.size() == 0)
    {
        cout << "\033[1;31mNo recipes with ingredients found!\033[0m" << endl;
    }
    else
    {
        // Iterate over the set of matching recipes and print their information
        for (int iter: trackCopy)
        {
            mapper[iter].printRecipeInfo();
        }
    }
}


void Graph::SearchRecipesWithExactIngredientsDijkstra(vector<string>& list)
{
    // Priority queue for Dijkstra's algorithm
    priority_queue<int, vector<int>, greater<int>> gq;

    // Vector to store distances from the source vertex
    vector<int> distance(adjList.size());

    // Set to keep track of recipes that match the criteria
    unordered_set<string> recipeTracker;

    // Initialize distances to infinity
    for (int i = 0; i < distance.size(); i++)
    {
        distance[i] = INT_MAX;
    }

    // Source vertex (adjusted for 0-based indexing)
    int src = 231637;
    distance[src - 1] = 0;
    gq.push(src);

    // Dijkstra's algorithm
    while (!gq.empty())
    {
        int vertex = gq.top();
        int dist = distance[vertex];
        gq.pop();

        // Iterate over the neighbors of the current vertex
        for (auto iter = adjList[vertex].begin(); iter != adjList[vertex].end(); ++iter)
        {
            // Update distance if a shorter path is found
            if (dist + iter->second < distance[iter->first])
            {
                distance[iter->first] = dist + iter->second;
                gq.push(iter->first);

                // Check if the ingredients match the specified list
                for (int i = 0; i < list.size(); i++)
                {
                    if (mapper[iter->first].ingredients.find(list[i]) == mapper[iter->first].ingredients.end())
                    {
                        break;
                    }
                    else
                    {
                        if (i == list.size() - 1)
                        {
                            recipeTracker.insert(mapper[iter->first].name);
                        }
                    }
                }
            }
        }
    }

    // Check if no matching recipes were found
    if (recipeTracker.size() == 0)
    {
        cout << "\033[1;31mNo Recipe Found!\033[0m" << endl;
    }
    else
    {
        // Iterate over the set of matching recipes and print their information
        for (const auto &recipeName : recipeTracker)
        {
            int isValid = -1;
            for (const auto &pair : mapper)
            {
                if (pair.second.name == recipeName)
                {
                    isValid = pair.first;
                    break;
                }
            }
            if (isValid != -1)
            {
                mapper[isValid].printRecipeInfo();
            }
        }
    }
}

void Graph::SearchRecipesWithInputIngredientsPlusExtraIngredientsDijkstra(vector<string>& list)
{
    // Priority queue for Dijkstra's algorithm
    priority_queue<int, vector<int>, greater<int>> gq;

    // Vector to store distances from the source vertex
    vector<int> distance(adjList.size());

    // Set to keep track of recipes that match the criteria
    unordered_set<string> recipeTracker;

    // Initialize distances to infinity
    for (int i = 0; i < distance.size(); i++)
    {
        distance[i] = INT_MAX;
    }

    // Source vertex (adjusted for 0-based indexing)
    int src = 231637;
    distance[src - 1] = 0;
    gq.push(src);

    // Dijkstra's algorithm
    while (!gq.empty())
    {
        int vertex = gq.top();
        int dist = distance[vertex];
        gq.pop();

        // Iterate over the neighbors of the current vertex
        for (auto iter = adjList[vertex].begin(); iter != adjList[vertex].end(); ++iter)
        {
            // Update distance if a shorter path is found
            if (dist + iter->second < distance[iter->first])
            {
                distance[iter->first] = dist + iter->second;
                gq.push(iter->first);

                // Check if the ingredients match the specified list
                for (int i = 0; i < list.size(); i++)
                {
                    if (mapper[iter->first].ingredients.find(list[i]) != mapper[iter->first].ingredients.end())
                    {
                        if (i == list.size() - 1)
                        {
                            recipeTracker.insert(mapper[iter->first].name);
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }

    // Check if no matching recipes were found
    if (recipeTracker.size() == 0)
    {
        cout << "\033[1;31mNo Recipe Found!\033[0m" << endl;
    }
    else
    {
        // Iterate over the set of matching recipes and print their information
        for (const auto &recipeName : recipeTracker)
        {
            int isValid = -1;
            for (const auto &pair : mapper)
            {
                if (pair.second.name == recipeName)
                {
                    isValid = pair.first;
                    break;
                }
            }
            if (isValid != -1)
            {
                mapper[isValid].printRecipeInfo();
            }
        }
    }
}


void Graph::SearchRecipesWithExactIngredientsBFS(vector<string>& list)
{
    // Source vertex
    int source = 231637;

    // Set to keep track of visited vertices
    std::unordered_set<int> visited;

    // Queue for BFS traversal
    std::queue<int> q;

    // Set to keep track of recipes that match the criteria
    unordered_set<string> recipeTracker;

    // Initialize source vertex
    visited.insert(source);
    q.push(source);

    // BFS traversal
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        // Get neighbors and sort them for a consistent order
        vector<pair<int, int>> neighbors = adjList[u];
        std::sort(neighbors.begin(), neighbors.end());

        // Iterate over neighbors
        for (auto v : neighbors)
        {
            // Check if the neighbor has not been visited
            if (visited.count(v.first) == 0)
            {
                visited.insert(v.first);
                q.push(v.first);

                // Check if the ingredients match the specified list
                for (int i = 0; i < list.size(); i++)
                {
                    if (mapper[v.first].ingredients.find(list[i]) == mapper[v.first].ingredients.end())
                    {
                        break;
                    }
                    else
                    {
                        if (i == list.size() - 1)
                        {
                            recipeTracker.insert(mapper[v.first].name);
                        }
                    }
                }
            }
        }
    }

    // Check if no matching recipes were found
    if (recipeTracker.size() == 0)
    {
        cout << "\x1b[31mNo recipes found " << list[0] << "\x1b[0m" << endl;
    }
    else
    {
        // Iterate over the set of matching recipes and print their information
        for (const auto &recipeName : recipeTracker)
        {
            int isValid = -1;
            for (const auto &pair : mapper)
            {
                if (pair.second.name == recipeName)
                {
                    isValid = pair.first;
                    break;
                }
            }
            if (isValid != -1)
            {
                mapper[isValid].printRecipeInfo();
            }
        }
    }
}


void Graph::SearchRecipesWithInputIngredientsPlusExtraIngredientsBFS(vector<string>& list)
{
    // Source vertex
    int source = 231637;

    // Set to keep track of visited vertices
    std::unordered_set<int> visited;

    // Queue for BFS traversal
    std::queue<int> q;

    // Set to keep track of recipes that match the criteria
    unordered_set<string> recipeTracker;

    // Initialize source vertex
    visited.insert(source);
    q.push(source);

    // BFS traversal
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        // Get neighbors and sort them for a consistent order
        vector<pair<int, int>> neighbors = adjList[u];
        std::sort(neighbors.begin(), neighbors.end());

        // Iterate over neighbors
        for (auto v : neighbors)
        {
            // Check if the neighbor has not been visited
            if (visited.count(v.first) == 0)
            {
                visited.insert(v.first);
                q.push(v.first);

                // Check if the ingredients match the specified list
                for (int i = 0; i < list.size(); i++)
                {
                    if (mapper[v.first].ingredients.find(list[i]) != mapper[v.first].ingredients.end())
                    {
                        if (i == list.size() - 1)
                        {
                            recipeTracker.insert(mapper[v.first].name);
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }

    // Check if no matching recipes were found
    if (recipeTracker.size() == 0)
    {
        cout << "\x1b[31mNo recipes found " << list[0] << "\x1b[0m" << endl;
    }
    else
    {
        // Iterate over the set of matching recipes and print their information
        for (const auto &recipeName : recipeTracker)
        {
            int index = -1;
            for (const auto &pair : mapper)
            {
                if (pair.second.name == recipeName)
                {
                    index = pair.first;
                    break;
                }
            }
            if (index != -1)
            {
                mapper[index].printRecipeInfo();
            }
        }
    }
}


void Graph::SearchRecipesWithExactIngredientsDFS(vector<string>& list)
{
    // Source vertex
    int source = 231637;

    // Set to keep track of visited vertices
    std::unordered_set<int> visited;

    // Stack for DFS traversal
    std::stack<int> s;

    // Set to keep track of recipes that match the criteria
    unordered_set<string> recipeTracker;

    // Initialize source vertex
    visited.insert(source);
    s.push(source);

    // DFS traversal
    while (!s.empty())
    {
        int u = s.top();
        s.pop();

        // Get neighbors and sort them for a consistent order
        vector<pair<int, int>> neighbors = adjList[u];
        std::sort(neighbors.begin(), neighbors.end());

        // Iterate over neighbors
        for (auto v : neighbors)
        {
            // Check if the neighbor has not been visited
            if (visited.count(v.first) == 0)
            {
                visited.insert(v.first);
                s.push(v.first);

                // Check if the ingredients match the specified list
                for (int i = 0; i < list.size(); i++)
                {
                    if (mapper[v.first].ingredients.find(list[i]) == mapper[v.first].ingredients.end())
                    {
                        break;
                    }
                    else
                    {
                        if (i == list.size() - 1)
                        {
                            recipeTracker.insert(mapper[v.first].name);
                        }
                    }
                }
            }
        }
    }

    // Check if no matching recipes were found
    if (recipeTracker.size() == 0)
    {
        cout << "\x1b[31mNo recipes found " << list[0] << "\x1b[0m" << endl;
    }
    else
    {
        // Iterate over the set of matching recipes and print their information
        for (const auto &recipeName : recipeTracker)
        {
            int isValid = -1;
            for (const auto &pair : mapper)
            {
                if (pair.second.name == recipeName)
                {
                    isValid = pair.first;
                    break;
                }
            }
            if (isValid != -1)
            {
                mapper[isValid].printRecipeInfo();
            }
        }
    }
}


void Graph::SearchRecipesWithInputIngredientsPlusExtraIngredientsDFS(vector<string>& list)
{
    // Source vertex
    int source = 231637;

    // Set to keep track of visited vertices
    std::unordered_set<int> visited;

    // Stack for DFS traversal
    std::stack<int> s;

    // Set to keep track of recipes that match the criteria
    unordered_set<string> recipeTracker;

    // Initialize source vertex
    visited.insert(source);
    s.push(source);

    // DFS traversal
    while (!s.empty())
    {
        int u = s.top();
        s.pop();

        // Get neighbors and sort them for a consistent order
        vector<pair<int, int>> neighbors = adjList[u];
        std::sort(neighbors.begin(), neighbors.end());

        // Iterate over neighbors
        for (auto v : neighbors)
        {
            // Check if the neighbor has not been visited
            if (visited.count(v.first) == 0)
            {
                visited.insert(v.first);
                s.push(v.first);

                // Check if the ingredients match the specified list
                for (int i = 0; i < list.size(); i++)
                {
                    if (mapper[v.first].ingredients.find(list[i]) != mapper[v.first].ingredients.end())
                    {
                        if (i == list.size() - 1)
                        {
                            recipeTracker.insert(mapper[v.first].name);
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }

    // Check if no matching recipes were found
    if (recipeTracker.size() == 0)
    {
        cout << "\x1b[31mNo recipes found " << list[0] << "\x1b[0m" << endl;
    }
    else
    {
        // Iterate over the set of matching recipes and print their information
        for (const auto &recipeName : recipeTracker)
        {
            int index = -1;
            for (const auto &pair : mapper)
            {
                if (pair.second.name == recipeName)
                {
                    index = pair.first;
                    break;
                }
            }
            if (index != -1)
            {
                mapper[index].printRecipeInfo();
            }
        }
    }
}



void Graph::FindVerySimilarRecipes() {
    string input;
    vector<string> list;

    // Get user input for the recipe to find similar recipes
    cout << "\033[1;32mPlease enter a recipe to find similar recipes: \033[0m" << endl;
    getline(cin, input);
    list.push_back(input);

    int recipeID;
    int index = 1;
    bool checker = false;
    vector<pair<int, int>> sortedRankings;

    // Iterate through recipes to find the recipe ID for the given input
    for (auto iter = mapper.begin(); iter != mapper.end(); ++iter) {
        string parsedName = iter->second.name;

        // Remove extra spaces in the recipe name
        int pos = parsedName.find("  ");
        while (pos != std::string::npos) {
            parsedName.erase(pos, 1);
            pos = parsedName.find("  ");
        }
        pos = parsedName.find("   ");
        while (pos != std::string::npos) {
            parsedName.erase(pos, 1);
            parsedName.erase(pos, 1);
            pos = parsedName.find("   ");
        }

        // Check if the parsed name matches the user input
        if (parsedName == list[0]) {
            recipeID = iter->first;
            checker = true;
        }
    }

    if (checker == true) {
        // Check if the recipe has similar recipes in the adjacency list
        if (adjList[recipeID].size() != index) {
            cout << "\033[1;32mRecipes  ||  Similarity Ranking (the lower the number, the more similar the recipes are! Number = # extra ingredients needed to make recipe)\033[0m" << endl;

            // Sort the rankings based on similarity
            for (auto iter = adjList[recipeID].begin(); iter != adjList[recipeID].end(); ++iter) {
                sortedRankings.push_back(make_pair(iter->second, iter->first));
            }
            sort(sortedRankings.begin(), sortedRankings.end());

            // Print the sorted rankings
            for (auto iter = sortedRankings.begin(); iter != sortedRankings.end(); ++iter) {
                cout << mapper[iter->second].name << "  ||  " << iter->first << endl;
            }
        } else {
            // If no similar recipes in the adjacency list, calculate and display rankings
            multimap<int, int> recipeRankings;
            for (auto iter = mapper.begin(); iter != mapper.end(); ++iter) {
                int score = 0;
                int weight = 0;

                // Calculate similarity score
                if (recipeID != iter->first) {
                    for (auto iterTwo = mapper[recipeID].ingredients.begin();
                         iterTwo != mapper[recipeID].ingredients.end(); ++iterTwo) {
                        if (iter->second.ingredients.find(*iterTwo) != iter->second.ingredients.end()) {
                            ++score;
                        }
                    }

                    // Calculate weight based on extra ingredients needed
                    weight = iter->second.ingredients.size() - score;
                    if (weight < 0) {
                        weight = 0;
                    }
                    recipeRankings.insert({weight, iter->first});
                }
            }

            auto iterator = recipeRankings.begin();
            for (int i = 0; i < 20000; i++) {
                if (iterator != recipeRankings.end()) {
                    ++iterator;
                }
            }
            recipeRankings.erase(iterator, recipeRankings.end());

            cout << "\033[1;32mRecipes  ||  Similarity Ranking (the lower the number, the more similar they are! Number = # extra ingredients needed to make recipe)\033[0m" << endl;

            // Print the calculated rankings
            for (auto iter = recipeRankings.begin(); iter != recipeRankings.end(); ++iter) {
                cout << mapper[iter->second].name << "  ||  " << iter->first << endl;
            }
        }
    } else {
        // If no matching recipe found by that name
        cout << "\033[1;31mNo matching recipe found by that name!\033[0m" << endl;
    }

    cout << "Please enter a recipe you like to see its information: " << endl;
    string finalInput;
    getline(cin, finalInput);
    bool finalChecker = false;
    for(auto x = mapper.begin(); x != mapper.end(); ++x)
    {
        string parsedName = x->second.name;

        // Remove extra spaces in the recipe name
        int pos = parsedName.find("  ");
        while (pos != std::string::npos) {
            parsedName.erase(pos, 1);
            pos = parsedName.find("  ");
        }
        pos = parsedName.find("   ");
        while (pos != std::string::npos) {
            parsedName.erase(pos, 1);
            parsedName.erase(pos, 1);
            pos = parsedName.find("   ");
        }

        // Check if the parsed name matches the user input
        if (parsedName == finalInput) {
            finalChecker = true;
            x->second.printRecipeInfo();
        }
    }
    if(finalChecker == false)
    {
        cout << "No recipe found with that name!" << endl;
    }
}

/*    auto startA = high_resolution_clock::now();
    test.everyRecipeWithOnlyExactIngredients(userInput);
    auto stopA = high_resolution_clock::now();
    duration<double> d = stopA - startA;
    cout << fixed << setprecision(3) << "It takes " << d.count() << " seconds to search for recipes with exact ingredients" << endl;

    auto startB = high_resolution_clock::now();
    test.everyRecipeWithInputIngredientsPlusExtraIngredients(userInput);
    auto stopB = high_resolution_clock::now();
    duration<double> d = stopB - startB;
    cout << fixed << setprecision(3) << "It takes " << d.count() << " seconds to search for recipes with extra ingredients" << endl;

    auto startC = high_resolution_clock::now();
    test.SearchRecipesWithExactIngredientsDijkstra(userInput);
    auto stopC = high_resolution_clock::now();
    duration<double> d = stopC - startC;
    cout << fixed << setprecision(3) << "Dijkstra's algorithm takes " << d.count() << " seconds to search for recipes with exact ingredients" << endl;

    auto startD = high_resolution_clock::now();
    test.SearchRecipesWithInputIngredientsPlusExtraIngredientsDijkstra(userInput);
    auto stopD = high_resolution_clock::now();
    duration<double> d = stopD - startD;
    cout << fixed << setprecision(3) << "Dijkstra's algorithm takes " << d.count() << " seconds to search for recipes with extra ingredients" << endl;

    auto startE = high_resolution_clock::now();
    test.SearchRecipesWithExactIngredientsBFS(userInput);
    auto stopE = high_resolution_clock::now();
    duration<double> d = stopE - startE;
    cout << fixed << setprecision(3) << "BFS algorithm takes " << d.count() << " seconds to search for recipes with exact ingredients" << endl;

    auto startF = high_resolution_clock::now();
    test.SearchRecipesWithInputIngredientsPlusExtraIngredientsBFS(userInput);
    auto stopF = high_resolution_clock::now();
    duration<double> d = stopF - startF;
    cout << fixed << setprecision(3) << "BFS algorithm takes " << d.count() << " seconds to search for recipes with extra ingredients" << endl;

    auto startG = high_resolution_clock::now();
    test.SearchRecipesWithExactIngredientsDFS(userInput);
    auto stopG = high_resolution_clock::now();
    duration<double> d = stopG - startG;
    cout << fixed << setprecision(3) << "DFS algorithm takes " << d.count() << " seconds to search for recipes with exact ingredients" << endl;

    auto startH = high_resolution_clock::now();
    test.SearchRecipesWithInputIngredientsPlusExtraIngredientsDFS(userInput);
    auto stopH = high_resolution_clock::now();
    duration<double> d = stopH - startH;
    cout << fixed << setprecision(3) << "DFS algorithm takes " << d.count() << " seconds to search for recipes with extra ingredients" << endl;

    auto startI = high_resolution_clock::now();
    test.SearchRecipesWithExactIngredientsBellmanFord(userInput);
    auto stopI = high_resolution_clock::now();
    duration<double> d = stopI - startI;
    cout << fixed << setprecision(3) << "Bellman Ford algorithm takes " << d.count() << " seconds to search for recipes with exact ingredients" << endl;
*/
