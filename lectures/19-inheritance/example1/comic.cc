export module comic;
import <string>;
import book;

export class Comic: public Book {
  std::string hero;
 public:
  Comic(const std::string &title, const std::string &author, int numPages, const std::string &hero);
  std::string getHero() const;
};
