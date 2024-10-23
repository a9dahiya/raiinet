export module book;
import <string>;

export class Book {
  std::string title, author;
  int numPages;
 protected:
  int getNumPages() const;
 public:
  Book(const std::string &title, const std::string &author, int numPages);
  std::string getTitle() const;
  std::string getAuthor() const;
  bool isItHeavy() const;
};
