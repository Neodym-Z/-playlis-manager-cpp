#include <iostream>
#include <cctype>
#include <string>
using namespace std;


// ===== Global Constants =====
const int MAX = 100;

// ===== Global Parallel Arrays =====
string songTitle[MAX];
string artist[MAX];
float duration[MAX];

int songAmount = 0;

// ===== Function Prototypes =====
// These declare the functions before main()
// so main() knows they exist (modularity moment)

void addSong();        // Adds a new song to the playlist
void removeSong();     // Removes a song from the playlist
void displaySongs();   // Displays all songs currently in the playlist
void searchSong();     // Searches for a song by title (or partial title)
void showMenu();       // Displays the menu options to the user
int getChoice();       // Gets and returns the user's menu choice
void displayStats(); // Displays playlist statistics (total songs, total duration, average length, longest and shortest song)




/*
    Program: Music Playlist Manager

    IPO (Input-Process-Output) Breakdown:

    INPUT:
    - Song title
    - Song duration
    - Album name
    - Playlist name
    - Playlist description

    PROCESS:
    - Create playlist
    - Add song to playlist
    - Remove song from playlist
    - Search for a song in the playlist

    OUTPUT:
    - Display playlist contents
    - Display search results
*/


int main()
{
    int choice; // Stores the user's menu choice

    // Loop keeps running until user chooses to exit (choice == 0)
    do {
        showMenu();           // Display menu options
        choice = getChoice(); // Get user's choice

        // Call functions based on user choice
        if (choice == 1) addSong();
        else if (choice == 2) removeSong();
        else if (choice == 3) searchSong();
        else if (choice == 4) displaySongs();
        else if (choice == 5) displayStats();

    } while (choice != 0); // Exit loop when user selects 0

    return 0; // End of program
}

void searchSong()
{
    string query;
    bool found = false;
}