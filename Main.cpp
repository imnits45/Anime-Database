#include <bits/stdc++.h>
class Anime {
private:
    std::string title;
    std::string director;
    std::string voiceActors;
    int releaseYear;
    float rating;
    std::string synopsis;

public:
    Anime(std::string title, std::string director, std::string voiceActors, int releaseYear, float rating, std::string synopsis) {
        this->title = title;
        this->director = director;
        this->voiceActors = voiceActors;
        this->releaseYear = releaseYear;
        this->rating = rating;
        this->synopsis = synopsis;
    }

    std::string getTitle() {
        return title;
    }

    void setTitle(std::string title) {
        this->title = title;
    }

    std::string getDirector() {
        return director;
    }

    void setDirector(std::string director) {
        this->director = director;
    }

    std::string getVoiceActors() {
        return voiceActors;
    }

    void setVoiceActors(std::string voiceActors) {
        this->voiceActors = voiceActors;
    }

    int getReleaseYear() {
        return releaseYear;
    }

    void setReleaseYear(int releaseYear) {
        this->releaseYear = releaseYear;
    }

    float getRating() {
        return rating;
    }

    void setRating(float rating) {
        this->rating = rating;
    }

    std::string getSynopsis() {
        return synopsis;
    }

    void setSynopsis(std::string synopsis) {
        this->synopsis = synopsis;
    }
};

void readAnimeDataFromFile(std::vector<Anime>& animeList) {
    std::ifstream inputFile("anime.txt");
    if (inputFile.is_open()) {
        std::string title, director, voiceActors, synopsis;
        int releaseYear;
        float rating;

        while (inputFile >> title >> director >> voiceActors >> releaseYear >> rating >> synopsis) {
            Anime anime(title, director, voiceActors, releaseYear, rating, synopsis);
            animeList.push_back(anime);
        }
        inputFile.close();
    }
}

void writeAnimeDataToFile(std::vector<Anime>& animeList) {
    std::ofstream outputFile("anime.txt");
    if (outputFile.is_open()) {
        for (auto& anime : animeList) {
            outputFile << anime.getTitle() << " "
                       << anime.getDirector() << " "
                       << anime.getVoiceActors() << " "
                       << anime.getReleaseYear() << " "
                       << anime.getRating() << " "
                       << anime.getSynopsis() << std::endl;
        }
        outputFile.close();
    }
}
void displayAnimeList(std::vector<Anime>& animeList) {
    std::cout << "Anime List:" << std::endl;
    for (auto& anime : animeList) {
        std::cout << "Title: " << anime.getTitle() << std::endl;
        std::cout << "Director: " << anime.getDirector() << std::endl;
        std::cout << "Voice Actors: " << anime.getVoiceActors() << std::endl;
        std::cout << "Release Year: " << anime.getReleaseYear() << std::endl;
        std::cout << "Rating: " << anime.getRating() << std::endl;
        std::cout << "Synopsis: " << anime.getSynopsis() << std::endl;
        std::cout << std::endl;
    }
}

void addAnimeToList(std::vector<Anime>& animeList) {
    std::string title, director, voiceActors, synopsis;
    int releaseYear;
    float rating;

    std::cout << "Enter anime title: ";
    std::getline(std::cin, title);
    std::cout << "Enter anime director: ";
    std::getline(std::cin, director);
    std::cout << "Enter anime voice actors: ";
    std::getline(std::cin, voiceActors);
    std::cout << "Enter anime release year: ";
    std::cin >> releaseYear;
    std::cout << "Enter anime rating: ";
    std::cin >> rating;
    std::cin.ignore(); // Ignore newline character
    std::cout << "Enter anime synopsis: ";
    std::getline(std::cin, synopsis);

    Anime anime(title, director, voiceActors, releaseYear, rating, synopsis);
    animeList.push_back(anime);
    std::cout << "Anime added to list." << std::endl;
}

void saveAnimeListToFile(std::vector<Anime>& animeList) {
    writeAnimeDataToFile(animeList);
    std::cout << "Anime list saved to file." << std::endl;
}
void searchAnimeByTitle(std::vector<Anime>& animeList) {
    std::string searchTerm;
    std::cout << "Enter the title of the anime you want to search for: ";
    std::getline(std::cin, searchTerm);

    bool animeFound = false;

    for (auto& anime : animeList) {
        if (anime.getTitle() == searchTerm) {
            std::cout << "Anime found:" << std::endl;
            std::cout << "Title: " << anime.getTitle() << std::endl;
            std::cout << "Director: " << anime.getDirector() << std::endl;
            std::cout << "Voice Actors: " << anime.getVoiceActors() << std::endl;
            std::cout << "Release Year: " << anime.getReleaseYear() << std::endl;
            std::cout << "Rating: " << anime.getRating() << std::endl;
            std::cout << "Synopsis: " << anime.getSynopsis() << std::endl;
            animeFound = true;
        }
    }

    if (!animeFound) {
        std::cout << "Anime not found." << std::endl;
    }
}

void modifyAnime(std::vector<Anime>& animeList) {
    std::string searchTerm;
    std::cout << "Enter the title of the anime you want to modify: ";
    std::getline(std::cin, searchTerm);

    bool animeFound = false;

    for (auto& anime : animeList) {
        if (anime.getTitle() == searchTerm) {
            std::cout << "Enter the new title (or leave blank to keep current): ";
            std::string newTitle;
            std::getline(std::cin, newTitle);
            if (!newTitle.empty()) {
                anime.setTitle(newTitle);
            }

            std::cout << "Enter the new director (or leave blank to keep current): ";
            std::string newDirector;
            std::getline(std::cin, newDirector);
            if (!newDirector.empty()) {
                anime.setDirector(newDirector);
            }

            std::cout << "Enter the new voice actors (or leave blank to keep current): ";
            std::string newVoiceActors;
            std::getline(std::cin, newVoiceActors);
            if (!newVoiceActors.empty()) {
                anime.setVoiceActors(newVoiceActors);
            }

            std::cout << "Enter the new release year (or leave blank to keep current): ";
            std::string newReleaseYearStr;
            std::getline(std::cin, newReleaseYearStr);
            if (!newReleaseYearStr.empty()) {
                int newReleaseYear = std::stoi(newReleaseYearStr);
                anime.setReleaseYear(newReleaseYear);
            }

            std::cout << "Enter the new rating (or leave blank to keep current): ";
            std::string newRatingStr;
            std::getline(std::cin, newRatingStr);
            if (!newRatingStr.empty()) {
                double newRating = std::stod(newRatingStr);
                anime.setRating(newRating);
            }

            std::cout << "Enter the new synopsis (or leave blank to keep current): ";
            std::string newSynopsis;
            std::getline(std::cin, newSynopsis);
            if (!newSynopsis.empty()) {
                anime.setSynopsis(newSynopsis);
            }

            std::cout << "Anime modified." << std::endl;
            animeFound = true;
            break;
        }
    }

    if (!animeFound) {
        std::cout << "Anime not found." << std::endl;
    }
}

class User {
private:
    std::string username;
    std::string password;

public:
    User(std::string username, std::string password) {
        this->username = username;
        this->password = password;
    }

    std::string getUsername() const {
        return username;
    }

    std::string getPassword() const {
        return password;
    }
};

bool authenticateUser(const std::vector<User>& userList, std::string username, std::string password) {
    for (const auto& user : userList) {
        if (user.getUsername() == username && user.getPassword() == password) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<User> userList;
    userList.emplace_back("imnits45", "password");
    userList.emplace_back("github", "password2");

    std::string username, password;
    std::cout << "Enter your username: ";
    std::getline(std::cin, username);

    std::cout << "Enter your password: ";
    std::getline(std::cin, password);

    if (authenticateUser(userList, username, password)) {
        std::cout << "Authentication successful." << std::endl;
         std::vector<Anime> animeList;
    readAnimeDataFromFile(animeList);

    int choice = 0;
    while (choice != 4) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Display anime list" << std::endl;
        std::cout << "2. Add anime to list" << std::endl;
        std::cout << "3. Save anime list to file" << std::endl;
        std::cout << "4. Search Anime by title" << std::endl;
        std::cout << "5. Exit program" << std::endl;
        std::cout << "6. Modify an existing Anime" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline character

        switch (choice) {
            case 1:
                displayAnimeList(animeList);
                break;
            case 2:
                addAnimeToList(animeList);
                break;
            case 3:
                saveAnimeListToFile(animeList);
                break;
            case 4:
                searchAnimeByTitle(animeList);
                break;
            case 5:
                modifyAnime(animeList);
                break;
            case 6:
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
    }
    else {
        std::cout << "Authentication failed. Please try again." << std::endl;
    }

    return 0;
}