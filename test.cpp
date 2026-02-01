#include <iostream>
#include <string>
using namespace std;


const int MAX = 100;
string songTitle[MAX] = {"Bohemian Rhapsody", "Stairway to Heaven", "Hotel California", "Imagine", "Smells Like Teen Spirit"};
string artist[MAX] = {"Queen", "Led Zeppelin", "Eagles", "John Lennon", "Nirvana"};
string duration[MAX] = {"5:55", "8:02", "6:30", "3:03", "5:01"};
int songAmount = 5;

void displayPlaylist(string, string);
void createPlaylist(string&, string&);

int main()
{
    system("chcp 65001 > nul");
    string playlistTitle, playlistDescription;
    createPlaylist(playlistTitle, playlistDescription);
    displayPlaylist(playlistTitle, playlistDescription);

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


