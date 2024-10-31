export module comic;
import <string>;
import book;

export class Comic: public Book {
  std::string hero;
 public:
  Comic(const std::string &title, const std::string &author, int numPages, const std::string &hero);
  Comic(const Comic &cb);

  Comic &operator=(const Comic &rhs);

  bool isItHeavy() const override;
  std::string getHero() const;

  bool favourite() const override;
};
