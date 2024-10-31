export module abstractbook;
import <string>;

export class AbstractBook {
  std::string title, author;
  int numPages;
 protected:
  int getNumPages() const;
  AbstractBook& operator=(const AbstractBook &rhs);  // Assignment now protected

 public:
  AbstractBook(const std::string &title, const std::string &author, int numPages);
  AbstractBook(const AbstractBook &b);

  std::string getTitle() const;
  std::string getAuthor() const;
  virtual bool isItHeavy() const;

  virtual bool favourite() const;

  virtual ~AbstractBook() = 0;  // Pure virtual destructor????
};
