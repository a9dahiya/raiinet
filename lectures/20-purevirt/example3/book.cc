export module book;
import abstractbook;
import <string>;

export class Book: public AbstractBook {
 public:
  Book(const std::string &title, const std::string &author, int numPages);
  Book(const Book &b);

  Book& operator=(const Book &rhs);

  ~Book();
};
