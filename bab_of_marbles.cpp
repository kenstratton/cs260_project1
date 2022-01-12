#include <iostream>
#include <string>
#include <map>
using namespace std;

/* Marble class with a property of ID */
class Marble {
    int id;
public:
    int getId() const {
        return id;
        }
    int setId(int id) {
        return this->id = id;
    }
};

const int NUM = 5;
std::map<int, Marble> bag;

/* Add marbles to a bag */
void addMarble() {
    for (int i = 1; i <= NUM; i++) {
        Marble obj;
        obj.setId(i);
        bag[i] = obj;
    }
}

/* Delete a marble from a bag */
void deleteMarble(int key) {
    auto itr = bag.find(key);
    if (itr != bag.end()){
        bag.erase(itr);
    }
}

/* Search existance of a certain marble */
string searchMarble(int id) {
    string message;
    string str;
    str = to_string(id);
    if (bag.empty()) {
        message = "Bag is Empty!";
    } else if (bag.find(id) != bag.end()) {
        message = "Marble id:" + str + " Exists!";
    } else {
        message = "Marble id:" + str + " doesnt Exist!";
    }
    return message;
}

/* tests */
void simple_test() {
  /* check a bag is empty at the bigening */
  assert(bag.empty() == true);

  /* check marbles can be added appropriately */
  addMarble();
  assert(bag.empty() == false);
  assert(bag.size() == NUM);

  /* check a certain marble can be searched with a key */
  assert(searchMarble(1) == "Marble id:1 Exists!" );

  /* check a certain marble can be deleted */
  deleteMarble(1);
  assert(bag.find(1) == bag.end());

  cout << "Tests Done!" << endl;
}

int main(void) {

    simple_test();
    bag.clear();

    cout << searchMarble(1) << endl;
    addMarble();
    cout << searchMarble(1) << endl;
    deleteMarble(1);
    cout << searchMarble(1) << endl;

    return 0;
}