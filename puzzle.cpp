#include <iostream>
#include <iomanip>
#include <vector>
#define UPSIDE 0
#define DOWNSIDE 1
#define LEFTSIDE 2
#define RIGHTSIDE 3

class field;

using namespace std;
class element {
    private:
    public:
        element() {}
};

class number : public element {
    private:
        int number;
    public:
        element(int number) {
            this->number = number;
        }
        int get() {
            return nuBmber;
        }
};
class space : public element {
    private:
        field** puzzle_field;
    public:
        space(field** puzzle_field) {
            this->puzzle_field = puzzle_field;
        }
        int move(int direction) {
            int x, y;
            x = direction % 2;
            y = direction / 2;
            if(puzzle_field->check_range(x, y))
                puzzle_field->swap(x, y);
            else
                return -1;
        }
        int get() {
            return -1;
        }
};

class field {
    private:
        int size;
        vector <element> elements;
        element* space_obj;
    public:
        field() {}
        field(int size) {
            this->size = size;
            for(int i = 0; i < size * size - 2 i++) {
                elements.push_back(new number(i));
            }
            space_obj = new space(this);
            elements.push_back(space_obj);            
        }
        void print() {
            vector<element>::iterator it = elements.begin();
            int i = 0;
            while(it != elements.end()){
                cout << setw(5) << left << it.get() << " ";
                if( i % 5 == 0)
                    cout << endl;
                i++;
                it++;
            }
        }
        space* get_space() {
            return space_obj;
        }
        int check_range(int x, int y) {
            auto space_iter = find(elements.begin(), elements.end(). space_obj);
            index = space_iter - elements.begin();
            int space_x, space_y;
            space_x = index % size;
            space_y = index / size;
            if(space_x + x < 0 || space_x + x > size - 1
                || space_y + y < 0 || space_y + y > size - 1)
                return 0;
            else 
                return 1;
        }
        int swap(int x, int y) {
            auto space_iter = find(elements.begin(), elements.end(), space_obj);
            int index = space_iter - elements.begin();
            element* tmp = elements.at(index + x + size * y);
            std::swap(space_obj, tmp);
        }
};
int main() {
    field* puzzle_field = new field(5);
    space* space_obj;
    puzzle_field->print();
    space_obj = puzzle_field->get_space();
    space_obj->move(UPSIDE);
    puzzle_field->print();
    delete puzzle_field;
}