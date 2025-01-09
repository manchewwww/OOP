#include <iostream>
#include <exception>
#pragma warning (disable:4996)

class Book
{
	char* author;
	char* title;
	unsigned pages;
	unsigned year;
public:
	Book() {
		author = nullptr;
		title = nullptr;
	}
	Book& operator=(const Book& other)
	{
		setAuthor(other.author);
		setTitle(other.title);
		setPages(other.pages);
		setYear(other.year);
	}

	const char* getAuthor() const {
		return author;
	}
	const char* getBookName() const {
		return title;
	}
	unsigned getPages() const {
		return pages;
	}
	unsigned getYear() const {
		return year;
	}
	void setAuthor(const char* author) {
		if(this->author != nullptr)
			delete[] this->author;
		unsigned size = strlen(author) + 1;
		this->author = new char[size];
		strcpy(this->author, author);
	}
	void setTitle(const char* title) {
		if (this->title != nullptr)
			delete[] this->title;
		unsigned size = strlen(title) + 1;
		this->title = new char[size];
		strcpy(this->title, title);
	}
	void setPages(unsigned pages) {
		if (pages < 0 || pages > 2019) {
			this->pages = 0;
		}
		this->pages = pages;
	}
	void setYear(unsigned year) {
		if (year < 0 || year > 2019) {
			this->year = 0;
		}
		this->year = year;
	}
	~Book() {
		std::cout << author << std::endl;
		std::cout << title << std::endl;
		std::cout << pages << std::endl;
		std::cout << year << std::endl;
		delete[] author;
		delete[] title;
	}
};

class Library
{
	Book* books;
	char* address;
	unsigned countBooks;
public:
	const Book* getBooks() const{
		return books;
	}
	const char* gerAddress() const {
		return address;
	}
	Library& operator=(const Library& other) {
		setBooks(other.books);
		setAddress(other.address);
		setCountBooks(other.countBooks);
	}
	void setBooks(Book* books) {
		this->books = books;
	}
	void setAddress(const char* address) {
		if (this->address != nullptr) {
			delete[] address;
		}
		this->address = new (std::nothrow) char[strlen(address) + 1];
		if (this->address == nullptr) {
			throw std::bad_alloc("D");
		}
		strcpy(this->address, address);
	}
	void setCountBooks(const unsigned countBooks) {
		this->countBooks = countBooks;
	}

};
int main()
{
	Book p;
	Book d;
	d = p;
	Book list[3];
	list[0] = p;
	list[1] = d;
	p.setAuthor("Ivan");
	p.setTitle("Kkk");
	p.setPages(333);
	p.setYear(2018);
}
