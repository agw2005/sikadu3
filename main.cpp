#include <iostream>

void horizontalLine(){
    std::cout<<"----------------------------------------------------------------------------------------------------"<<std::endl;
}

struct Node{
    long long id;
    float gpa;
    std::string name;
    char gender;
    Node* next = nullptr;
};

struct LinkedList{
    Node* head = nullptr;
    Node* tail = nullptr;
    int population = 0;

    void push_back(long long idInput, float ipkInput, std::string namaInput, char genderInput){
        Node* temp = new Node();
        temp -> id = idInput;
        temp -> gpa = ipkInput;
        temp -> name = namaInput;
        temp -> gender = genderInput;

        if(head == nullptr){
            head = temp;
            tail = temp;
        } else{
            tail -> next = temp;
            tail = temp;
        }
        population++;
    }

    void deleteTail(){
        if(population == 0) {
            std::cout << "There are no elements inside the list\n";
        } else {
            Node *current = head;
            Node *previous = nullptr;
            while (current->next != nullptr) {
                previous = current;
                current = current->next;
            }
            if (previous != nullptr) {
                tail = previous;
                tail->next = nullptr;
            } else {
                head = nullptr;
                tail = nullptr;
            }
            delete current;
        }
        population--;
    }

    void deleteHead(){
        if(population == 0){
            std::cout << "There are no elements inside the list\n";
        } else {
            Node *temp = head;
            head = head->next;
            delete temp;

            population--;

            if (head == nullptr) {
                tail = nullptr;
            }
        }
    }

    void deleteID(long long flag){
        if(population == 0){
            std::cout << "There are no elements inside the list\n";
        } else {
            if (head->id == flag) {
                deleteHead();
            }
            Node *current = head;
            Node *previous = nullptr;
            while (current != nullptr) {
                if (current->id == flag) {
                    if (current == tail) {
                        previous->next = nullptr;
                        tail = previous;
                    } else {
                        previous->next = current->next;
                    }
                    delete current;
                    population--;
                    return;
                }
                previous = current;
                current = current->next;
            }
        }
    }

    void deleteName(std::string& flag){
        if(population == 0){
            std::cout << "There are no elements inside the list\n";
        } else {
            if (head->name == flag) {
                deleteHead();
            }
            Node *current = head;
            Node *previous = nullptr;
            while (current != nullptr) {
                if (current->name == flag) {
                    if (current == tail) {
                        previous->next = nullptr;
                        tail = previous;
                    } else {
                        previous->next = current->next;
                    }
                    delete current;
                    population--;
                    return;
                }
                previous = current;
                current = current->next;
            }
        }
    }

    void printComplete() const{
        Node* current = head;
        if(population == 0){
            std::cout<<"The list is empty!\n";
            horizontalLine();
        } else{
            for (int i = 1; i <= population; i++) {
                std::cout << "Index-" << i << " : " << current->name <<" ("<<current->gender<< ") (NIM:" << current->id << ')' << std::endl;
                if (current == tail) {
                    std::cout << "Next(NULL)\n";
                } else {
                    std::cout << "Next(" << (current->next)->name << ")\n";
                }
                horizontalLine();
                current = current->next;
            }
        }
        std::cout<<"Population: "<<population<<std::endl;
    }

    void printPartial() const {
        Node* current = head;
        for (int i = 1; i <= population; i++) {
            std::cout <<"("<< current->id << ")"<<current->name;
            current = current->next;
        }
        std::cout<<std::endl;
    }

    bool duplicateName(std::string& flag) const{
        Node* current = head;
        for(int i = 1 ; i <= population ; i++){
            if(current->name == flag){return true;}
            else{
                current = current -> next;
            }
        }
        return false;
    }

    bool duplicateID(long long flag) const{
        Node* current = head;
        for(int i = 1 ; i <= population ; i++){
            if(current->id == flag){return true;}
            else{
                current = current -> next;
            }
        }
        return false;
    }

};

LinkedList bubbleSortByID(LinkedList flag) {
    LinkedList result = flag;
    long long tempID;
    std::string tempName;
    float tempGPA;
    char tempGender;
    Node* current = result.head;
    while (current->next != nullptr) {
        if (current->id > current->next->id) {
            tempID = current->next->id;
            tempName = current->next->name;
            tempGPA = current->next->gpa;
            tempGender = current->next->gender;
            current->next->id = current->id;
            current->next->name = current->name;
            current->next->gpa = current->gpa;
            current->next->gender = current->gender;
            current->id = tempID;
            current->name = tempName;
            current->gpa = tempGPA;
            current->gender = tempGender;
        }
        current = current->next;
    }
    return result;
}

void uppercaseGender(char& flag){
    if(flag == 'l'){
        flag = 'L';
    } else if(flag == 'p'){
        flag = 'P';
    }
}

void capitalize(std::string& str) {
    for (int i = 0; i < str.length(); i++) {
        if (i == 0 || (str[i - 1] == ' ' && i < str.length())) {
            str[i] = std::toupper(str[i]);
        }
    }
}

int main() {
    //Declarations
    std::string mainMenu = "1. Add student\n2. Delete student\n3. List students\n4. Create a task\n5. Insert a grade\n6. Exit\n";
    std::string deleteMenu = "1. Delete newest\n2. Delete oldest\n3. Delete by index\n4. Delete by name\n5. Back to main menu\n";
    int menuInput;
    long long idInput;
    float gpaInput;
    std::string nameInput;
    char genderInput;
    bool programIsRunning{true},notValid{true}, deletionIsRunning{true};
    LinkedList test;
    LinkedList sortedTest;

    //Test subjects
    test.push_back(11,4.0,"Abigail",'P');
    test.push_back(55,4.0,"Ariana",'P');
    test.push_back(22,4.0,"Billy",'L');
    test.push_back(33,4.0,"Charlie",'L');

    //Program Running Event Loops
    do{
        std::cout<<mainMenu<<"Input:\n";
        std::cin>>menuInput;
        std::cin.ignore(1, '\n');
        horizontalLine();
        switch(menuInput){

            //Add student
            case 1:
                //Name
                do{
                    std::cout << "Enter the name of the student:\n";
                    std::getline(std::cin, nameInput);
                    capitalize(nameInput);
                    horizontalLine();
                    if(test.duplicateName(nameInput)){
                        std::cout << "The student by that name already exist! Please try again.\n";
                        horizontalLine();
                    } else{
                        notValid = false;
                    }
                }while(notValid);
                //ID
                do{
                    std::cout<<"Enter the student ID:\n";
                    horizontalLine();
                    std::cin>>idInput;
                    horizontalLine();
                    if(idInput < 1){
                        notValid = true;
                        std::cout << "The student ID you just entered is not a valid ID, please try again.\n";
                        horizontalLine();
                    } else if(test.duplicateID(idInput)){
                        notValid = true;
                        std::cout << "The student ID already exist, please try again.\n";
                        horizontalLine();
                    } else{notValid = false;}
                }while(notValid);
                //Gender
                do{
                    std::cout<<"Enter student gender:\n";
                    std::cin>>genderInput;
                    horizontalLine();
                    if(genderInput != 'L' && genderInput != 'P' && genderInput != 'l' && genderInput != 'p'){
                        notValid = true;
                        std::cout << "The gender you entered is not valid, please try again.\n";
                        horizontalLine();
                    } else{notValid = false;}
                } while(notValid);
                uppercaseGender(genderInput);
                //GPA
                do{
                    std::cout<<"Enter the student grade this semester:\n";
                    std::cin>>gpaInput;
                    horizontalLine();
                    if(gpaInput < 0.0 || gpaInput > 4.0){
                        notValid = true;
                        std::cout << "The grade you entered is not valid, please try again.\n";
                        horizontalLine();
                    } else{notValid = false;}
                } while(notValid);
                test.push_back(idInput, gpaInput , nameInput, genderInput);
                notValid = true;
                break;

            //Delete student
            case 2:
                if(test.population == 0){
                    std::cout<<"There is no student to delete\n";
                } else{
                    do {
                        std::cout << deleteMenu;
                        horizontalLine();
                        std::cin >> menuInput;
                        horizontalLine();
                        switch (menuInput) {
                            case 1:
                                //Delete most recent added
                                test.deleteTail();
                                break;
                            case 2:
                                //Delete most oldest added
                                test.deleteHead();
                                break;
                            case 3:
                                //Delete by ID
                                do {
                                    std::cout << "What is the ID of the student you want to delete?\n";
                                    std::cin >> menuInput;
                                    if (!test.duplicateID(menuInput)){
                                        std::cout << "There is no student by that ID number\n";
                                    } else {
                                        test.deleteID(menuInput);
                                        notValid = false;
                                    }
                                } while (notValid);
                                break;
                            case 4:
                                //Delete by name
                                do {
                                    std::cout << "What is the name of the student you want to delete?\n";
                                    std::cin >> nameInput;
                                    capitalize(nameInput);
                                    if (!test.duplicateName(nameInput)){
                                        std::cout << "There is no student by that name\n";
                                    } else {
                                        test.deleteName(nameInput);
                                        notValid = false;
                                    }
                                } while (notValid);
                                break;
                            case 5:
                                deletionIsRunning = false;
                                break;
                            default:
                                std::cout
                                        << "The value you just entered is beyond our instruction, please try again.\n";
                                break;
                        }
                    } while (deletionIsRunning);
                    deletionIsRunning = true;
                }
                break;
            case 3:
                //Prints the list
                sortedTest = bubbleSortByID(test);
                sortedTest.printComplete();
                break;
            case 4:
                //Create task
                break;
            case 5:
                //Insert grade
                break;
            case 6:
                programIsRunning = false;
                break;
            default:
                std::cout << "The value you just entered is beyond our instruction, please try again.\n";
                horizontalLine();
                break;
        }
    }while(programIsRunning);
}