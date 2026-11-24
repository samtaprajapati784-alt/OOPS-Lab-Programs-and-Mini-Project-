/*
Name: Samta Prajapati
Roll no.: CO2122
*/
#include <iostream>
#include <string>
#include <limits>
using namespace std;

class MusicSys {
public:
    string song_title, artist_name, album_name, category, playlist;
    int song_id;
    int play_count = 0;
    bool aval;

    MusicSys() {
        song_id = 0;
        song_title = "Null";
        artist_name = "Null";
        album_name = "Null";
        category = "Null";
        playlist = "Null";
        play_count = 0;
        aval = false;
    }

    MusicSys(int id, string Songtitle, string Artistname, string Albumname,
             string categoryname, string playlistname, int playcount) {
        song_id = id;
        song_title = Songtitle;
        artist_name = Artistname;
        album_name = Albumname;
        category = categoryname;
        playlist = playlistname;
        play_count = playcount;
    }

    MusicSys(const MusicSys &S3) {
        song_id = S3.song_id;
        song_title = S3.song_title;
        artist_name = S3.artist_name;
        album_name = S3.album_name;
        category = S3.category;
        playlist = S3.playlist;
        play_count = S3.play_count;
        aval = S3.aval;
    }

    void addsong();
    void displaysong();
    void playsong();
    void addtoplaylist(string str);
    void removeplaylist();
    void viewstats();
};

void MusicSys::addsong() {
    cout << "Enter Song Name to add: ";
    cin >> song_title;
    cout << "Enter Artist name: ";
    cin >> artist_name;
    cout << "Enter Song Album: ";
    cin >> album_name;
    cout << "Enter Song Category: ";
    cin >> category;
}

void MusicSys::displaysong() {
    cout << "Song name: " << song_title << endl;
    cout << "Artist Name: " << artist_name << endl;
    cout << "Album Name: " << album_name << endl;
    cout << "Category: " << category << endl;
    cout << "Playlist: " << playlist << endl;
}

void MusicSys::playsong() {
    cout << "Playing Music: " << song_title << endl;
    play_count += 1;
}

void MusicSys::addtoplaylist(string str) {
    playlist = str;
}

void MusicSys::removeplaylist() {
    playlist = "none";
}

void MusicSys::viewstats() {
    cout << "Song Name: " << song_title << endl;
    cout << "Song Category: " << category << endl;
    cout << "Song ID: " << song_id << endl;
    cout << "Play Count: " << play_count << endl;
}

int main() {
    MusicSys M;
    MusicSys m1(M);
    MusicSys m2(1, "shape", "justin", "bieber", "pop", "sunlight", 1);
    int choice;
    int para_choice;
    string str;

    do {
        cout << "\n-------Menu------" << endl;
        cout << "1. Add Song" << endl;
        cout << "2. Display song Details" << endl;
        cout << "3. Play Song" << endl;
        cout << "4. Add to playlist" << endl;
        cout << "5. Remove the playlist" << endl;
        cout << "6. View Stats" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                M.addsong();
                break;
            case 2:
                cout << "Which profile to display? (1 for Default, 2 for Preloaded): ";
                cin >> para_choice;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid choice. Returning to menu." << endl;
                    break;
                }
                if (para_choice == 1) {
                    M.displaysong();
                } else if (para_choice == 2) {
                    m2.displaysong();
                } else {
                    cout << "Invalid profile choice." << endl;
                }
                break;
            case 3:
                M.playsong();
                break;
            case 4:
                cout << "Enter Playlist Name: ";
                cin >> str;
                M.addtoplaylist(str);
                break;
            case 5:
                M.removeplaylist();
                break;
            case 6:
                M.viewstats();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Enter a valid statement." << endl;
                break;
        }
    } while (choice != 7);

    return 0;
}

/*OUTPUT 
-------Menu------
1. Add Song
2. Display song Details
3. Play Song
4. Add to playlist
5. Remove the playlist
6. View Stats
7. Exit
Enter your Choice: 1
Enter Song Name to add: Treasure
Enter Artist name: Bruno_Mars
Enter Song Album: Jukebox
Enter Song Category: Disco

-------Menu------
1. Add Song
2. Display song Details
3. Play Song
4. Add to playlist
5. Remove the playlist
6. View Stats
7. Exit
Enter your Choice: 2
Which profile to display? (1 for Default, 2 for Preloaded): 1
Song name: Treasure
Artist Name: Bruno_Mars
Album Name: Jukebox
Category: Disco
Playlist: Null

-------Menu------
1. Add Song
2. Display song Details
3. Play Song
4. Add to playlist
5. Remove the playlist
6. View Stats
7. Exit
Enter your Choice: 4
Enter Playlist Name: Party

-------Menu------
1. Add Song
2. Display song Details
3. Play Song
4. Add to playlist
5. Remove the playlist
6. View Stats
7. Exit
Enter your Choice: 3
Playing Music: Treasure

-------Menu------
1. Add Song
2. Display song Details
3. Play Song
4. Add to playlist
5. Remove the playlist
6. View Stats
7. Exit
Enter your Choice: 5

-------Menu------
1. Add Song
2. Display song Details
3. Play Song
4. Add to playlist
5. Remove the playlist
6. View Stats
7. Exit
Enter your Choice: 6
Song Name: Treasure
Song Category: Disco
Song ID: 0
Play Count: 1

-------Menu------
1. Add Song
2. Display song Details
3. Play Song
4. Add to playlist
5. Remove the playlist
6. View Stats
7. Exit
Enter your Choice: 2
Which profile to display? (1 for Default, 2 for Preloaded): 1
Song name: Treasure
Artist Name: Bruno_Mars
Album Name: Jukebox
Category: Disco
Playlist: none

-------Menu------
1. Add Song
2. Display song Details
3. Play Song
4. Add to playlist
5. Remove the playlist
6. View Stats
7. Exit
Enter your Choice: 2
Which profile to display? (1 for Default, 2 for Preloaded): 2
Song name: shape
Artist Name: justin
Album Name: bieber
Category: pop
Playlist: sunlight

-------Menu------
1. Add Song
2. Display song Details
3. Play Song
4. Add to playlist
5. Remove the playlist
6. View Stats
7. Exit
Enter your Choice: 7
Exiting...
*/
