#include <iostream>
#include <cctype>
#include <string>
using namespace std;


// ===== Global Constants =====
const int MAX = 100;

// ===== Global Parallel Arrays =====
string songTitle[MAX];
string artist[MAX];
string duration[MAX];

int songAmount = 0;
// ===== Function Prototypes =====
// These declare the functions before main()
// so main() knows they exist (modularity moment)

void addSong();        // Adds a new song to the playlist
void removeSong();     // Removes a song from the playlist
void displayPlaylist(string, string);   // Displays all songs currently in the playlist
void searchSong();     // Searches for a song by title (or partial title)
void showMenu();       // Displays the menu options to the user
int getChoice();       // Gets and returns the user's menu choice
void displayStats(); // Displays playlist statistics (total songs, total duration, average length, longest and shortest song)
void showWelcome(); // show the welcome message
void createPlaylist(string&, string&); // allows the user to create the playlist (entering their title and description)



/*
    Program: Music Playlist Manager

    IPO (Input-Process-Output) Breakdown:

    INPUT:
    - Song title
    - Song duration
    - Album name
    - Playlist name
    - Playlist Description

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
    string playlistTitle, playlistDescription;
    system("chcp 65001 > nul"); // Sets Windows console to UTF-8 for proper ASCII display
    displayWelcome();
    createPlaylist(playlistTitle, playlistDescription);

    // Loop keeps running until user chooses to exit (choice == 0)
    do {
        showMenu();           // Display menu options
        choice = getChoice(); // Get user's choice

        // Call functions based on user choice
        if (choice == 1) addSong();
        else if (choice == 2) removeSong();
        else if (choice == 3) searchSong();
        else if (choice == 4) displayPlaylist(playlistTitle, playlistDescription);
        else if (choice == 5) displayStats();

    } while (choice != 0); // Exit loop when user selects 0

    return 0; // End of program
}

void showMenu()
{
    // shows the menu for the user to choose 
    cout << "\n========== MENU ==========\n";
    cout << "1. Add Song\n";
    cout << "2. Remove Song\n";
    cout << "3. Search Song\n";
    cout << "4. Display Playlist\n";
    cout << "5. Playlist Stats\n";
    cout << "0. Exit\n";
    cout << "==========================\n";
}

void displayWelcome()
{
    cout << "\n";
    cout << "  ███╗   ███╗██╗   ██╗███████╗██╗ ██████╗\n";
    cout << "  ████╗ ████║██║   ██║██╔════╝██║██╔════╝\n";
    cout << "  ██╔████╔██║██║   ██║███████╗██║██║     \n";
    cout << "  ██║╚██╔╝██║██║   ██║╚════██║██║██║     \n";
    cout << "  ██║ ╚═╝ ██║╚██████╔╝███████║██║╚██████╗\n";
    cout << "  ╚═╝     ╚═╝ ╚═════╝ ╚══════╝╚═╝ ╚═════╝\n";
    cout << "   ♪♫ PLAYLIST MANAGER ♫♪\n";
    cout << "Welcome to the Playlist Manager!";
    cout << "\n";
}

void createPlaylist(string& title, string& description)
{
    cout << "♪♫ Name your playlist: " << endl;
    getline(cin >> ws, title);
    cout << "Add a description to set the vibe: " << endl;
    getline(cin >> ws, description);
    cout << endl;
}

void displayPlaylist(string title, string description)
{
    // displays the contents of the playlist(ex: title, description, each song and it's contents)
    cout << title << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << description << endl;
    cout << "=========================================================" << endl;
    for (int i = 0; i < songAmount; i++)
    {
        cout << i + 1 << ". " << songTitle[i] << " - " << artist[i] << " (" << duration[i] << ")" << endl;
    }
    cout << "=========================================================" << endl;
}



void searchSong()
{
    if (songAmount == 0)
    {
        cout << "Playlist is Empty. Cannot search for a song." << endl;
        return;
    }
    
    char choice;

    do {
         string query;
         bool found = false;

         cout << "Enter the song title to search: " << endl;
         getline(cin >> ws, query);

         for (int i = 0; i < songAmount; i++)
         {
            if (songTitle[i].find(query) != string::npos)
            {
                cout << i + 1 << ". " << songTitle[i] << " - " << artist[i] << " (" << duration[i] << ")" << endl;
                // ex: Creep - Radiohead (4:21)
                found = true;
            }
         }

         if (!found)
         {
            cout << "No Matching Songs found." << endl;
         }

         cout << "Search Again? (Y/N)";
         cin >> choice;
         cin.ignore();

    } while (toupper(choice) == 'Y');

}