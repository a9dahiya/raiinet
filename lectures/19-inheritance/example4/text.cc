export module text;
import <string>;
import book;

export class Text: public Book {
  std::string topic;
 public:
  Text(const std::string &title, const std::string &author, int numPages, const std::string &topic);
  bool isItHeavy() const override;
  std::string getTopic() const;

  bool favourite() const override;
};
