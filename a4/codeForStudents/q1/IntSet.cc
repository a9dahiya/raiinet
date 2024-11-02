export module intset;

import <iostream>;
import <vector>;

export class IntSet {
    std::vector<int> data;

  public:

    class Iterator {
        // *** Fill in whatever you need for private fields and methods
      public:
        int operator*() const;
        Iterator& operator++();
        bool operator!=(const Iterator & it) const;
    };

    IntSet* operator|( const IntSet & i ) const;  // Set union.
    IntSet* operator&( const IntSet & i ) const;  // Set intersection.
    bool operator==( const IntSet & i ) const;    // Set equality.
    bool isSubset( const IntSet & i ) const;      // True if i is a subset of "this".
    bool contains( int e ) const;                 // True if "this" contains element e.

    void add( int e );                            // Adds element e to "this".
    void remove( int e );                         // Removes element e from "this".

    Iterator begin() const;
    Iterator end() const;
};

// Output operator for IntSet.
export std::ostream& operator<<( std::ostream & out, const IntSet & is );

// Input operator for IntSet. Continuously read int values from in and add to the passed IntSet.
// Function stops when input contains a non-int value. Discards the first non-int character.
export std::istream& operator>>( std::istream & in, IntSet & is );
