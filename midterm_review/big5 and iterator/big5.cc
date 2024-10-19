import <string>;

class Duo {
    bool ***arr; // array of pointers to arrays of pointers
    int arrLen;
    int* lens; // array of lengths of inner array of pointers
    public:
        Duo() : arr{new bool **[1]}, arrLen{1}, lens{new int[1]} {
            arr[0] = new bool*[1];
            arr[0][0] = new bool{true};
            lens[0] = 1;
        }
        // write out the rest of big 5
        class Iterator {
            bool ***arr;
            int arrLen;
            int* lens;
            int arrPos; // position in outer array
            int inPos; // position in inner array
            Iterator(bool*** arr, int arrLen, int* lens, int arrPos, int inPos) : arr{arr},
             arrLen{arrLen}, 
             lens{lens},
             arrPos{arrPos} {}
            bool operator!=(const Iterator& o) {}
            Iterator& operator++() {}
            bool& operator*() {}
        };
        Iterator begin() {}
        Iterator end() {}
};
