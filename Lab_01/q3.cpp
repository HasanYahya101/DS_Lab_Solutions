#include <iostream>
#include <string>
using namespace std;

class LibraryItem
{
private:
    int item_id;
    string title;
    string author_creator;
    int publication_year;
    bool is_available;

public:
    LibraryItem()
    {
        this->item_id = 0;
        this->title = "";
        this->author_creator = "";
        this->publication_year = 0;
        this->is_available = true;
    }
    LibraryItem(int item_id, string title, string author_creator, int publication_year, bool is_available)
    {
        this->item_id = item_id;
        this->title = title;
        this->author_creator = author_creator;
        this->publication_year = publication_year;
        this->is_available = is_available;
    }
    int getItemId()
    {
        return this->item_id;
    }
    string getTitle()
    {
        return this->title;
    }
    string getAuthorCreator()
    {
        return this->author_creator;
    }
    int getPublicationYear()
    {
        return this->publication_year;
    }
    bool getIsAvailable()
    {
        return this->is_available;
    }
    void setItemId(int item_id)
    {
        this->item_id = item_id;
    }
    void setTitle(string title)
    {
        this->title = title;
    }
    void setAuthorCreator(string author_creator)
    {
        this->author_creator = author_creator;
    }
    void setPublicationYear(int publication_year)
    {
        this->publication_year = publication_year;
    }
    void setIsAvailable(bool is_available)
    {
        this->is_available = is_available;
    }
};

class Book : public LibraryItem
{
private:
    int ISBN;
    string genre;

public:
    Book()
    {
        this->ISBN = 0;
        this->genre = "";
    }
    Book(int ISBN, string genre)
    {
        this->ISBN = ISBN;
        this->genre = genre;
    }
    int getISBN()
    {
        return this->ISBN;
    }
    string getGenre()
    {
        return this->genre;
    }
    void setISBN(int ISBN)
    {
        this->ISBN = ISBN;
    }
    void setGenre(string genre)
    {
        this->genre = genre;
    }
};

class Magazine : public LibraryItem
{
private:
    int issue_number;
    string topic;

public:
    Magazine()
    {
        this->issue_number = 0;
        this->topic = "";
    }
    Magazine(int issue_number, string topic)
    {
        this->issue_number = issue_number;
        this->topic = topic;
    }
    int getIssueNumber()
    {
        return this->issue_number;
    }
    string getTopic()
    {
        return this->topic;
    }
    void setIssueNumber(int issue_number)
    {
        this->issue_number = issue_number;
    }
    void setTopic(string topic)
    {
        this->topic = topic;
    }
};

class DVD : public LibraryItem
{
private:
    int duration;
    string director;

public:
    DVD()
    {
        this->duration = 0;
        this->director = "";
    }
    DVD(int duration, string director)
    {
        this->duration = duration;
        this->director = director;
    }
    int getDuration()
    {
        return this->duration;
    }
    string getDirector()
    {
        return this->director;
    }
    void setDuration(int duration)
    {
        this->duration = duration;
    }
    void setDirector(string director)
    {
        this->director = director;
    }
};

void addBook(Book *book)
{
    int item_id, publication_year, ISBN;
    string title, author_creator, genre;
    bool is_available;
    cout << "Enter item id: ";
    cin >> item_id;
    cout << "Enter title: ";
    cin >> title;
    cout << "Enter author/creator: ";
    cin >> author_creator;
    cout << "Enter publication year: ";
    cin >> publication_year;
    cout << "Enter availability status (0/1): ";
    cin >> is_available;
    cout << "Enter ISBN: ";
    cin >> ISBN;
    cout << "Enter genre: ";
    cin >> genre;
    book->setItemId(item_id);
    book->setTitle(title);
    book->setAuthorCreator(author_creator);
    book->setPublicationYear(publication_year);
    book->setIsAvailable(is_available);
    book->setISBN(ISBN);
    book->setGenre(genre);
}

void addMagazine(Magazine *magazine)
{
    int item_id, publication_year, issue_number;
    string title, author_creator, topic;
    bool is_available;
    cout << "Enter item id: ";
    cin >> item_id;
    cout << "Enter title: ";
    cin >> title;
    cout << "Enter author/creator: ";
    cin >> author_creator;
    cout << "Enter publication year: ";
    cin >> publication_year;
    cout << "Enter availability status (0/1): ";
    cin >> is_available;
    cout << "Enter issue number: ";
    cin >> issue_number;
    cout << "Enter topic: ";
    cin >> topic;
    magazine->setItemId(item_id);
    magazine->setTitle(title);
    magazine->setAuthorCreator(author_creator);
    magazine->setPublicationYear(publication_year);
    magazine->setIsAvailable(is_available);
    magazine->setIssueNumber(issue_number);
    magazine->setTopic(topic);
}

void addDVD(DVD *dvd)
{
    int item_id, publication_year, duration;
    string title, author_creator, director;
    bool is_available;
    cout << "Enter item id: ";
    cin >> item_id;
    cout << "Enter title: ";
    cin >> title;
    cout << "Enter author/creator: ";
    cin >> author_creator;
    cout << "Enter publication year: ";
    cin >> publication_year;
    cout << "Enter availability status (0/1): ";
    cin >> is_available;
    cout << "Enter duration: ";
    cin >> duration;
    cout << "Enter director: ";
    cin >> director;
    dvd->setItemId(item_id);
    dvd->setTitle(title);
    dvd->setAuthorCreator(author_creator);
    dvd->setPublicationYear(publication_year);
    dvd->setIsAvailable(is_available);
    dvd->setDuration(duration);
    dvd->setDirector(director);
}

void displayBook(Book *book)
{
    cout << "Item id: " << book->getItemId() << endl;
    cout << "Title: " << book->getTitle() << endl;
    cout << "Author/Creator: " << book->getAuthorCreator() << endl;
    cout << "Publication year: " << book->getPublicationYear() << endl;
    cout << "Availability status: " << book->getIsAvailable() << endl;
    cout << "ISBN: " << book->getISBN() << endl;
    cout << "Genre: " << book->getGenre() << endl;
}

void borrowBook(Book *book)
{
    if (book->getIsAvailable())
    {
        book->setIsAvailable(false);
        cout << "Book borrowed successfully!" << endl;
    }
    else
    {
        cout << "Book is not available!" << endl;
    }
}

void displayMagazine(Magazine *magazine)
{
    cout << "Item id: " << magazine->getItemId() << endl;
    cout << "Title: " << magazine->getTitle() << endl;
    cout << "Author/Creator: " << magazine->getAuthorCreator() << endl;
    cout << "Publication year: " << magazine->getPublicationYear() << endl;
    cout << "Availability status: " << magazine->getIsAvailable() << endl;
    cout << "Issue number: " << magazine->getIssueNumber() << endl;
    cout << "Topic: " << magazine->getTopic() << endl;
}

void borrowMagazine(Magazine *magazine)
{
    if (magazine->getIsAvailable())
    {
        magazine->setIsAvailable(false);
        cout << "Magazine borrowed successfully!" << endl;
    }
    else
    {
        cout << "Magazine is not available!" << endl;
    }
}

void displayDVD(DVD *dvd)
{
    cout << "Item id: " << dvd->getItemId() << endl;
    cout << "Title: " << dvd->getTitle() << endl;
    cout << "Author/Creator: " << dvd->getAuthorCreator() << endl;
    cout << "Publication year: " << dvd->getPublicationYear() << endl;
    cout << "Availability status: " << dvd->getIsAvailable() << endl;
    cout << "Duration: " << dvd->getDuration() << endl;
    cout << "Director: " << dvd->getDirector() << endl;
}

void borrowDVD(DVD *dvd)
{
    if (dvd->getIsAvailable())
    {
        dvd->setIsAvailable(false);
        cout << "DVD borrowed successfully!" << endl;
    }
    else
    {
        cout << "DVD is not available!" << endl;
    }
}

int main()
{
    cout << "------------------------------------------" << endl;
    cout << "Welcome to the Library Management System!" << endl;
    cout << "------------------------------------------" << endl;
    Book *book = new Book();
    Magazine *magazine = new Magazine();
    DVD *dvd = new DVD();
    addBook(book);
    addMagazine(magazine);
    addDVD(dvd);
    cout << "------------------------------------------" << endl;
    cout << "Adding Completed! Displaying Information..." << endl;
    cout << "------------------------------------------" << endl;
    displayBook(book);
    displayMagazine(magazine);
    displayDVD(dvd);
    cout << "------------------------------------------" << endl;
    cout << "Borrowing Items..." << endl;
    cout << "------------------------------------------" << endl;
    borrowBook(book);
    borrowMagazine(magazine);
    borrowDVD(dvd);
    borrowDVD(dvd);
    return 0;
}
