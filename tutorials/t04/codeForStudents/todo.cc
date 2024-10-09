import <iostream>;
import <string>;
import list;
import task;

using namespace std;

int main() {
    List list;
    string cmd;
    string option;
    while (cin >> cmd) {
        if (cmd == "print") { // tests Task::print
            list.print();
        } else if (cmd == "add") { // tests Task::addChild
            cin.ignore();
            getline(cin, option);
            list.addChild(option);
        } else if (cmd == "delete") { // tests Task::removeChild
            list.deleteCur();
        } else if (cmd == "parent") { // tests Task::getParent
            list.parent();
        } else if (cmd == "up") { // goes back to the ToDo list level
            list.up();
        } else if (cmd == "desc") { // tests Task::setId
            cin.ignore();
            getline(cin, option);
            list.setDescription(option);
        } else if (cmd == "done") { // tests Task::setValue
            list.setDone(true);
        } else if (cmd == "undone") { // tests Task::setValue
            list.setDone(false);
        } else if (cmd == "find") { // tests Task::findChild
            cin.ignore();
            getline(cin, option);
            list.findChild(option);
        } else if (cmd == "findId") { // tests Task::findChildId
            int id;
            cin >> id;
            list.findChildId(id);
        } else if (cmd == "cut") { // moves current task to internal clipboard
            list.cut();
        } else if (cmd == "copy") { // copies current task to internal clipboard
            list.copy();
        } else if (cmd == "paste") { // adds task from internal clipboard as a new child
            list.paste();
        } else if (cmd == "quit") {
            break;
        } else {
            cerr << "Invalid command." << endl;
        }
    }    
}
