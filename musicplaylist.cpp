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
string playlistTitle, playlistDescription;
// ===== Function Prototypes =====
// These declare the functions before main()
// so main() knows they exist (modularity moment)

void addSong();        // Adds a new song to the playlist
void removeSong();     // Removes a song from the playlist
void displayPlaylist();   // Displays all songs currently in the playlist
void searchSong();     // Searches for a song by title (or partial title)
void showMenu();       // Displays the menu options to the user
int getChoice();       // Gets and returns the user's menu choice
void displayStats(); // Displays playlist statistics (total songs, total duration, average length, longest and shortest song)
void displayWelcome(); // show the welcome message
void createPlaylist(); // allows the user to create the playlist (entering their title and description)



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
    int choice;
    system("chcp 65001 > nul"); // Sets Windows console to UTF-8 for proper ASCII display
    displayWelcome();
    createPlaylist();

    // Loop keeps running until user chooses to exit (choice == 0)
    do {
        showMenu();           // Display menu options
        choice = getChoice(); // Get user's choice

        // Call functions based on user choice
        if (choice == 1) addSong();
        else if (choice == 2) removeSong();
        else if (choice == 3) searchSong();
        else if (choice == 4) displayPlaylist();
        else if (choice == 5) displayStats();

    } while (choice != 0); // Exit loop when user selects 0

    return 0; // End of program
}

void showMenu()
{
    // shows the menu for the user to choose from
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
    // displays a welcome message for the user
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

int getChoice()
{
    // To take user choice based on the menu 
    int choice;
    cout << "Enter your choice (1-5)/ '0' to exit: " << endl;
    cin >> choice;
    cin.ignore();
    return choice;
}

void createPlaylist()
{
    // prompts the user to create the playlist by entering their playlist name and the description
    cout << "♪♫ Name your playlist: " << endl;
    getline(cin >> ws, playlistTitle);
    cout << "Add a description to set the vibe: " << endl;
    getline(cin >> ws, playlistDescription);
    cout << endl;
}

void addSong()
{
    // allows users to add songs repeatedly until they exit.
    char choice;
   do {
     if (songAmount >= MAX)
    {
        cout << "Playlist is full! Cannot add more songs." << endl;
        return;
    }
    cout << "Enter song title: ";
    getline(cin >> ws, songTitle[songAmount]);

    cout << "Enter artist name: "; 
    getline(cin >> ws, artist[songAmount]);

    cout << "Enter duration (MM:SS) [ex: (3:56)]: ";
    getline(cin >> ws, duration[songAmount]);

    songAmount++;
    cout << "Song added successfully!" << endl;
    cout << "Add another song? (Y/N): ";
    cin >> choice;
    cin.ignore();
   } while (toupper(choice) == 'Y');
}

void removeSong()
{
    if (songAmount == 0)
    {
        cout << "There are no songs to delete." << endl;
        return;
    }
    

    int choice;
    char removeAgain;

    do {
        displayPlaylist();
        cout << "Enter the song number to delete: ";
        cin >> choice;
        cin.ignore();

        int index = choice - 1;

        if (index < 0 || index >= songAmount)
        {
            cout << "Invalid song number" << endl;
            continue;
        }

        for (int i = index; i < songAmount - 1; i++)
        {
            songTitle[i] = songTitle[i+1];
            artist[i] = artist[i+1];
            duration[i] = duration[i+1];
        }
        songAmount--;
        cout << "Song deleted successfully!" << endl;
        cout << "Remove another song? (Y/N): ";
        cin >> removeAgain;
        cin.ignore();
    } while (toupper(removeAgain) == 'Y');
}

void displayPlaylist()
{
    // displays the contents of the playlist(ex: title, description, each song and it's contents)
    if (songAmount == 0)
    {
        cout << "Playlist is empty! Add some songs first." << endl;
        return;
    }
    cout << playlistTitle << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << playlistDescription << endl;
    cout << "=========================================================" << endl;
    for (int i = 0; i < songAmount; i++)
    {
        cout << i + 1 << ". " << songTitle[i] << " - " << artist[i] << " (" << duration[i] << ")" << endl;
    }
    cout << "=========================================================" << endl;
}



void searchSong()
{
    // allows user to search for a specific song inside the playlist
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

         cout << "Search Again? (Y/N): ";
         cin >> choice;
         cin.ignore();

    } while (toupper(choice) == 'Y');
}