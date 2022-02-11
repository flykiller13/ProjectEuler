#include "102.h"

int triangles()
{
    // Create a text string, which is used to output the text file
    string* triangles_arr = new string[1001];

    // Read from the text file
    ifstream triangles_text("p102_triangles.txt");

    // Use a while loop together with the getline() function to read the file line by line
    int i = 0;
    while (getline(triangles_text, triangles_arr[i])) {
        // Output the text from the file
        cout << triangles_arr[i] << endl;
        i++;
    }

    // Close the file
    triangles_text.close();
    delete[] triangles_arr;

    return 0;
}