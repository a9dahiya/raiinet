import stringBag;
import <iostream>;
import <string>;
import <utility>;

using namespace std;

// Node workhorse ctor
StringBag::Node::Node (const string & s, size_t arity, Node* next) {}
// StringBag default ctor
StringBag::StringBag() {}
// StringBag copy ctor
StringBag::StringBag(const StringBag & otherSB) {}
// StringBag move ctor
StringBag::StringBag (StringBag && otherSB) {}
// StringBag dtor
StringBag::~StringBag() {}

// StringBag copy operator=
StringBag& StringBag::operator=(const StringBag & otherSB) {}
// StringBag move operator=
StringBag& StringBag::operator=(StringBag && otherSB) {}

void StringBag::add(const string & s) {}
void StringBag::remove(const string & s) {}
void StringBag::removeAll(const string & s) {}

StringBag StringBag::operator+(const StringBag & otherSB) const {}
StringBag StringBag::operator-(const StringBag & otherSB) const {}
StringBag& StringBag::operator+=(const StringBag& otherSB) {}
StringBag& StringBag::operator-=(const StringBag& otherSB) {}

bool StringBag::operator==(const StringBag & otherSB) const {}

// go thru and delete Nodes with arity==0
void StringBag::dezombify () {}

// Returns a pointer to the Node for value s if it exists, even if it has 
// arity zero
StringBag::Node* StringBag::find (const string & s) const {}

size_t StringBag::getNumElements () const {}
size_t StringBag::getNumValues () const {}
size_t StringBag::arity(const string & s) const {}
