import <string>;
import <utility>;

class Duo {
    bool ***arr; // array of pointers to array of pointers
    int arrLen;
    int* lens; // array of lengths of inner array of pointers
    public:
        Duo() : arr{new bool **[1]}, arrLen{1}, lens{new int[1]} {
            arr[0] = new bool* [1];
            arr[0][0] = new bool{true};
            lens[0] = 1;
        }
        // write out the rest of big 5
        ~Duo() {
            for (int i = 0; i < arrLen; ++i) {
                for (int j = 0; j < lens[i]; ++j) {
                    delete arr[i][j];
                }
                delete[] arr[i];
            }
            delete[] arr;
            delete[] lens;
        }

        Duo(const Duo& other) : arr{new bool**[other.arrLen]}, arrLen{other.arrLen}, lens{new int[other.arrLen]} {
            for (int i = 0; i < arrLen; ++i) {
                lens[i] = other.lens[i];
                arr[i] = new bool*[lens[i]];
                for (int j = 0; j < lens[i]; ++j) {
                    arr[i][j] = new bool{*(other.arr[i][j])};
                }
            }
        }

        Duo(Duo&& other) : arr{other.arr}, arrLen{other.arrLen}, lens{other.lens} {
            other.arr = nullptr;
            other.lens = nullptr;
	    other.arrLen = 0;
        }

        Duo& operator=(const Duo& other) {
            if (this == &other) return *this;
            Duo tmp{other};
            std::swap(arr, tmp.arr);
            std::swap(arrLen, tmp.arrLen);
            std::swap(lens, tmp.lens);
            return *this;
        }

        Duo& operator=(Duo&& other) {
            if (this == &other) return *this;
            std::swap(arr, other.arr);
            std::swap(arrLen, other.arrLen);
            std::swap(lens, other.lens);
            return *this;
        }

        class Iterator {
            bool ***arr;
            int arrLen;
            int* lens;
            int arrPos; // position in outer array
            int inPos; // position in inner array
            public:
                Iterator(bool*** arr, int arrLen, int* lens, int arrPos, int inPos) : arr{arr},
                arrLen{arrLen}, 
                lens{lens},
                arrPos{arrPos},
                inPos{inPos} {}
                bool operator!=(const Iterator& o) {
                    return (arr != o.arr) || (arrLen != o.arrLen) || (lens != o.lens) || (arrPos != o.arrPos) || (inPos != o.inPos);
                }
                Iterator& operator++() {

                    if (inPos == lens[arrPos] - 1) {
                        ++arrPos;
                        inPos = 0;
                    }
                    else {
                        ++inPos;
                    }
                    return *this;
                }
                bool& operator*() {
                    return *(arr[arrPos][inPos]);
                }
        };
        Iterator begin() {
            return Iterator(arr, arrLen, lens, 0, 0);
        }
        Iterator end() {
            return Iterator(arr, arrLen, lens, arrLen, 0);
        }
};
