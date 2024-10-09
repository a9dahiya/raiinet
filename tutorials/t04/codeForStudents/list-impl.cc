module list;

using namespace std;

List::List(): root{new Task{"ToDo"}}, cur{root}, clip{nullptr} {}

List::~List() {
    delete clip;
    delete root;
}

void List::printCurrent() {
    cout << "Task \"" << cur->getDescription() << "\" is now the current task." << endl;
}

void List::print() {
    cout << *cur;
}

void List::addChild(string description) {
    if (cur->getLength() != childrenCapacity) {
        Task *newTask = new Task{description};
        newTask->setParent(cur);
        cur->addChild(newTask);
        cur = newTask;
        printCurrent();
    } else {
        std::cout << "No room for new tasks!" << std::endl;
    }
}

void List::deleteCur() {
    if (cur == root) {
        cerr << "List cannot be removed." << endl;
        return;
    }
    Task *tmp = cur;
    cur = tmp->getParent();
    cur->removeChild(tmp);
    delete tmp;
    printCurrent();
}

void List::parent() {
    if (cur->getParent() == nullptr) {
        cerr << "Current task is already the upper level task." << endl;
        return;
    }
    cur = cur->getParent();
    printCurrent();
}

void List::up() {
    cur = root;
    printCurrent();
}

void List::setDescription(string option) {
    cur->setDescription(option);
    cout << "Task " << cur->getId() << " description set to \"" << option << "\"." << endl;
}

void List::setDone(bool done) {
    cur->setDone(done);
    if (done) {
        cout << "Task \"" << cur->getDescription() << "\" is done!" << endl;
    } else {
        cout << "Task \"" << cur->getDescription() << "\" is not done!" << endl;
    }
}

void List::findChild(string option) {
    Task *tmp = cur->findChild(option);
    if (tmp == nullptr) {
        cerr << "Task \"" << option << "\" not found." << endl;
        return;
    }
    cur = tmp;
    printCurrent();
}

void List::findChildId(int option) {
    Task *tmp = cur->findChildId(option);
    if (tmp == nullptr) {
        cerr << "Task with id " << option << " not found." << endl;
        return;
    }
    cur = tmp;
    printCurrent();
}

void List::cut() {
    if (cur == root) {
        cerr << "List cannot be cut." << endl;
        return;
    }
    // remove task from parent
    Task *parent = cur->getParent();
    parent->removeChild(cur);
    if (clip == nullptr) {
        // using move constructor
        clip = new Task{std::move(*cur)};
    } else {
        // using move assignment operator
        *clip = std::move(*cur);
    }
    // delete original task
    delete cur;
    cur = parent;
    cout << "Task \"" << clip->getDescription() << "\" is now in the clipboard." << endl;
    printCurrent();
}

void List::copy() {
    if (cur == root) {
        cerr << "List cannot be copied." << endl;
        return;
    }
    // copy task to clipboard
    if (clip == nullptr) {
        // using copy constructor
        clip = new Task{*cur};
    } else {
        // using copy assignment operator
        *clip = *cur;
    }
    cout << "Task \"" << clip->getDescription() << "\" is now in the clipboard." << endl;
}

void List::paste() {
    if (clip == nullptr) {
        cerr << "The clipboard is empty." << endl;
        return;
    } else if (cur->getLength() != childrenCapacity) {
        // copy task from clipboard as a new child of the current task
        Task *newTask = new Task{*clip};  // using copy constructor
        newTask->setParent(cur);
        cur->addChild(newTask);
        cur = newTask;
        printCurrent();
    } else {
        std::cout << "No room for new tasks!" << std::endl;
    }
    
}
