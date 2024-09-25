#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

// Enum to store music genres
enum Genre { Pop, Jazz, Classic };

// Structure to store album information
struct Album {
    string album_name;
    int number_of_songs;
    Genre genre;
    int track_number;
    string tracks[5];
    string track_location[5];
};

void AddNewSong(Album& album);
void ViewAlbumDetails();
void PlaySong();

int main() {
    Album album;
    

    while (true) {
        cout << "\n\033[1;92m-----MENU----\033[0m\n\n\n";

        cout << "1. Add a New Song\n";
        cout << "2. View Details of a Selected Album\n";
        cout << "3. Play a Song\n";
        cout << "4. Exit\n\n";
        
        cout << "Select an option: ";

        int choice;
        cin >> choice;
        cin.ignore(); // Consume newline character

        switch (choice) {
            case 1:
                AddNewSong(album);
                break;
            case 2:
                ViewAlbumDetails();
                break;
            case 3:
                PlaySong();
                break;
            case 4:
                cout<<"\n\033[1;92mProgram Terminated. Thanks For Using The Music Player!\033[0m\n";
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    }

    return 0;
}

//Album information Input
void AddNewSong(Album& album) {

    // Get user input for album details
    cout << "\nEnter Album Name: ";
    getline(cin, album.album_name);

    cout<<"How Many Songs does this Album Consist of: "; 
    cin>>album.number_of_songs;  

    // Display genre selection menu
    cout << "\nSelect Genre:\n";
    cout << "\t1. Pop\n\t2. Jazz\n\t3. Classic\n";
    cout<<"Option: "; 
    int genre_choice;
    cin >> genre_choice;
    cin.ignore(); 
    album.genre = static_cast<Genre>(genre_choice - 1);

    // Get user input for song names and locations
    string song_name; 
    for (int i = 0; i < album.number_of_songs ; i++) {
        cout << "Enter Track " << i + 1 << " : ";
        getline(cin, song_name);
        album.tracks[i] = song_name; 
        album.track_location[i] = "\\Albums\\" + album.album_name + "\\" + song_name;
    }

    // Append album details to Music.txt
    ofstream music_file("Music.txt", ios::app);
    if (music_file.is_open()) {
        music_file << "Album Name: " << album.album_name << "\n";
        music_file << "Genre: ";

        if (album.genre == Pop) music_file << "Pop";
        else if (album.genre == Jazz) music_file << "Jazz";
        else music_file << "Classic";

        music_file << "\n";
        
        music_file << "Tracks:\n";
        for (int i = 0; i < album.number_of_songs ; i++) {
            music_file << i + 1 << ". " << album.tracks[i] << "\tLocation: \"" << album.track_location[i] << ".mp3\"\n";
        }
        music_file << "\n";
        music_file.close();
        cout << "\n\033[1;92mAlbum Added Successfully!\033[0m\n\n";
    }
    else {
        cout << "Unable to open Music.txt for appending.\n";
    }
}

//View Album Inforamation
void ViewAlbumDetails() {

    string album_name; 

    cout<<"Please Enter the Name of The Album You Want To Find: ";
    getline(cin,album_name);
    ifstream music_file("Music.txt");
    if (music_file.is_open()) {
        string line;
        while (getline(music_file, line)) {
            if (line.find("Album Name: "+album_name) != string::npos) {
                cout <<"\n\n\033[1;92m"<< line << "\033[0m\n";
                while (getline(music_file, line) && !line.empty()) {
                    cout << "\033[1;92m"<<line <<"\033[0m\n";
                }
                cout << "\n";
            }
        }
        music_file.close();
    }
    else {
        cout << "Unable to open Music.txt for reading.\n";
    }
}

//Play Song from music file
void PlaySong() {
    ifstream music_file("Music.txt");
    if (music_file.is_open()) {

        string album_name;
        cout << "Please Enter the Name of The Album You Want To Find: ";
        getline(cin, album_name);
        
        cout << "\n";

        
        string song_name; 
        cout << "Please Enter The Name of the Song You Want To Play: ";
        getline(cin,song_name); 
        
        
        cout << "\n";

        string line;

        while (getline(music_file, line)) {
            if (line.find("Album Name: " + album_name) != string::npos) {
                while (getline(music_file, line) && !line.empty()) {
                    if (line.find(song_name) != string::npos) {
                        // Find the start and end positions of the location within double quotes
                        int start = line.find("Location: \"");
                        int end = line.find_last_of("\"");

                        if (start != string::npos && end != string::npos) {
                            string track_location = line.substr(start + 12, end - (start +12));
                            

                            cout<<"\033[1;92mNow Playing: "<<song_name<<"\033[0m\n\n"; 

                            // You can use track_location with ShellExecute here
                            ShellExecute(NULL, NULL, track_location.c_str(), NULL, NULL, SW_SHOWNORMAL);
                        } 
                        else {
                            cout << "Location not found for the selected track.\n\n";
                        }
                    }
                }
            }
        }
        music_file.close();
    } else {
        cout << "Unable to open Music.txt for reading.\n";
    }
}