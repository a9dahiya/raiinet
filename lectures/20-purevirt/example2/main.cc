import <iostream>;
import <string>;
import book;
import text;
import comic;

using namespace std;


int main() {
  Text t1("Programming for Beginners", "Niklaus Wirth", 200, "Pascal");
  Text t2("Programming for Big Kids", "Bjarne Stroustrup", 300, "C++");

  Book *pb1 = &t1;
  Book *pb2 = &t2;
  
  *pb1 = *pb2;

  cout << "Book 1: " << t1.getTitle() << ", " << t1.getAuthor() << ", "
       << t1.getTopic() << endl;

  cout << "Book 2: " << t2.getTitle() << ", " << t2.getAuthor() << ", "
       << t2.getTopic() << endl;
}
