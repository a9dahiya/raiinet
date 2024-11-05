export module crustandsauce;
import <string>;
import pizza;

export class CrustAndSauce: public Pizza {
 public:
  float price() override;
  std::string description() override;
};
