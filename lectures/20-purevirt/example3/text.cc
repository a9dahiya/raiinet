export module text;
import <string>;
import abstractbook;

export class Text: public AbstractBook {
  std::string topic;
 public:
  Text(const std::string &title, const std::string &author, int numPages, const std::string &topic);

  bool isItHeavy() const override;
  std::string getTopic() const;

  bool favourite() const override;

  Text(const Text &other);

  Text &operator=(const Text &rhs);
};
