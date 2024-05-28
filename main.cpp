#include <iostream>
#include <vector>

void horizontalLine(){
    std::cout<<"----------------------------------------------------------------------------------------------------"<<std::endl;
}

struct Node{
    long long id;
    float gpa;
    std::string name;
    char gender;
    Node* next = nullptr;
    Node* prev = nullptr;
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
            temp -> prev = tail;
            tail -> next = temp;
            tail = temp;
        }
        population++;
    }

    void deleteHead(){
        Node* temp = head;
        if(population == 0){
            std::cout<<"List is empty!\n";
        } else if(population == 1){
            delete temp;
            tail = nullptr;
            head = nullptr;
        } else{
            head = temp -> next;
            head -> prev = nullptr;
            delete temp;
        }
        population--;
    }

    void deleteTail(){
        Node* current = head;
        Node* previousCurrent = nullptr;
        if(population == 0){
            std::cout<<"List is empty!\n";
        } else if(population == 1){
            delete current;
            tail = nullptr;
            head = nullptr;
        } else{
            while(current != tail){
                previousCurrent = current;
                current = current -> next;
            }
            previousCurrent->next = nullptr;
            tail = previousCurrent;
            delete current;
        }
        population--;
    }

    void deleteIndex(int flag){
        int index = 1;
        Node* current = head;
        Node* previousCurrent = nullptr;
        if(population == 0){
            std::cout<<"List is empty!\n";
        } else if(flag < 1 || flag > population){
            return;
        } else if(flag == 1){
            if(current->next == nullptr){
                delete current;
                head = nullptr;
                tail = nullptr;
            } else{
                head = current -> next;
                head->prev = nullptr;
                delete current;
            }
        } else if(flag == population){
            while(current != tail){
                previousCurrent = current;
                current = current -> next;
            }
            previousCurrent->next = nullptr;
            tail = previousCurrent;
            delete current;
        }
        else{
            while(index != flag){
                previousCurrent = current;
                current = current -> next;
                index++;
            }
            previousCurrent->next = current->next;
            (current->next)->prev = previousCurrent;
            delete current;
        }
        population--;
    }

    void deleteID(long long flag){
        Node* current = head;
        Node* previousCurrent = nullptr;
        while(current->id != flag){
            previousCurrent = current;
            current = current->next;
        }
        if(current->next == nullptr){
            previousCurrent->next = current->next;
            tail = previousCurrent;
            delete current;
        } else if(current == head){
            head = current -> next;
            head -> prev = nullptr;
            delete current;
        } else{
            previousCurrent->next = current->next;
            (current->next)->prev = previousCurrent;
            delete current;
        }
        population--;
    }

    void deleteName(const std::string& flag){
        Node* current = head;
        Node* previousCurrent = nullptr;
        while(current->name != flag){
            previousCurrent = current;
            current = current->next;
        }
        if(current->next == nullptr){
            previousCurrent->next = current->next;
            tail = previousCurrent;
            delete current;
        } else if(current == head){
            head = current -> next;
            head -> prev = nullptr;
            delete current;
        } else{
            previousCurrent->next = current->next;
            (current->next)->prev = previousCurrent;
            delete current;
        }
        population--;
    }

    //void printForDebugging() const{
    //    Node* current = head;
    //    if(population == 0){
    //        std::cout<<"The list is empty!\n";
    //        horizontalLine();
    //    } else{
    //        for (int i = 1; i <= population; i++) {
    //            std::cout << "Index-" << i << " : " << current->name <<" ("<<current->gender<< ") (NIM:" << current->id << ')' << std::endl;
    //            if (current == tail) {
    //                std::cout << "Next(NULL)\n";
    //            } else {
    //                std::cout << "Next(" << (current->next)->name << ")\n";
    //            }
    //            horizontalLine();
    //            current = current->next;
    //        }
    //    }
    //    std::cout<<"Population: "<<population<<std::endl;
    //    horizontalLine();
    //}

    void printName() const{
        Node* current = head;
        if(population == 0){
            std::cout<<"The list is empty!\n";
            horizontalLine();
        } else{
            for (int i = 1; i <= population; i++) {
                std::cout <<i<< ". ("<<current->name <<")("<<current->id<< ")(" << current->gender << ")("<<current->gpa<<")" << std::endl;
                current = current->next;
            }
        }
    }

    void printID() const{
        Node* current = head;
        if(population == 0){
            std::cout<<"The list is empty!\n";
            horizontalLine();
        } else{
            for (int i = 1; i <= population; i++) {
                std::cout <<i<< ". ("<<current->id <<")("<<current->name<< ")(" << current->gender << ")("<<current->gpa<<")" << std::endl;
                current = current->next;
            }
        }
    }

    void printGPA() const{
        Node* current = head;
        if(population == 0){
            std::cout<<"The list is empty!\n";
            horizontalLine();
        } else{
            for (int i = 1; i <= population; i++) {
                std::cout <<i<< ". ("<<current->gpa <<")("<<current->name<< ")(" << current->id << ")("<<current->gender<<")" << std::endl;
                current = current->next;
            }
        }
    }

    void printGender() const{
        Node* current = head;
        if(population == 0){
            std::cout<<"The list is empty!\n";
            horizontalLine();
        } else{
            for (int i = 1; i <= population; i++) {
                std::cout <<i<< ". ("<<current->gender <<")("<<current->name<< ")(" << current->id << ")("<<current->gpa<<")" << std::endl;
                current = current->next;
            }
        }
    }

    //void printPartial() const {
    //    Node* current = head;
    //    for (int i = 1; i <= population; i++) {
    //        std::cout <<"("<< current->id << ")"<<current->name;
    //        current = current->next;
    //    }
    //    std::cout<<std::endl;
    //}

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

    void elementAtIndex(int flag){
        if(flag == -1){
            std::cout<<"The student not within the list\n";
        }
        Node* current = nullptr;
        for(int i = 0 ; i < flag ; i++){
            if(current== nullptr){current=head;}
            else{current = current->next;}
        }
        std::cout<<"Student found:\nName: "<<current->name<<" ("<<current->gender<<")"<<"\nID: "<<current->id<<"\nGPA: "<<current->gpa<<'\n';
    }

};

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
        } else{
            str[i] = std::tolower(str[i]);
        }
    }
}

void printStringButWithBreaks(std::string theString){
    for(int i = 0 ; i <= (int)size(theString) ; i+=50){
        for(int ii = 0 ; ii < 50 && i+ii < (int)size(theString)  ; ii++){
            std::cout<<theString[i+ii];
        }
        std::cout<<"";
    }
    std::cout<<'\n';
}

void bubbleSortByName(LinkedList flag) {
    long long tempID;
    std::string tempName;
    float tempGPA;
    char tempGender;
    Node* i_check = flag.head;
    Node* ii_check = flag.head;
    for(int i = 1 ; i <= flag.population ; i++){
        for(int ii = 1 ; ii <= flag.population ; ii++){
            if(i != ii && i_check->name[0] < ii_check->name[0]){
                tempName = i_check->name;
                tempID = i_check->id;
                tempGPA = i_check->gpa;
                tempGender = i_check->gender;
                i_check->name = ii_check->name;
                i_check->id = ii_check->id;
                i_check->gpa = ii_check->gpa;
                i_check->gender = ii_check->gender;
                ii_check->name = tempName;
                ii_check->id = tempID;
                ii_check->gpa = tempGPA;
                ii_check->gender = tempGender;
            }
            ii_check = ii_check->next;
        }
        ii_check = flag.head;
        i_check = i_check->next;
    }
}

int quickSortProcess(LinkedList& flag,int start,int end){
    long long tempID;
    std::string tempName;
    float tempGPA;
    char tempGender;
    int i = start-1;
    long long pivotValue;
    Node* iIndex;
    Node* jIndex = nullptr;
    Node* pivotNode = nullptr;


    //Find the starting position of j
    for(int a = 0 ; a <= start ; a++){
        if(jIndex == nullptr){
            jIndex = flag.head;
        } else{
            jIndex = jIndex->next;
        }
    }

    iIndex = jIndex->prev;

    //Find the position of pivot
    for(int a = 0 ; a <= end ; a++){
        if(pivotNode == nullptr){
            pivotNode = flag.head;
        } else {
            pivotNode = pivotNode->next;
        }
    }
    pivotValue = pivotNode->id;


    for(int j = start+1 ; j <= end ; j++){
        if(jIndex->id < pivotValue){
            i++;
            if(iIndex == nullptr){
                iIndex = flag.head;
            } else{
                iIndex = iIndex->next;
            }
            tempID = iIndex->id;
            tempName = iIndex->name;
            tempGPA = iIndex->gpa;
            tempGender = iIndex->gender;
            iIndex->id = jIndex->id;
            iIndex->name = jIndex->name;
            iIndex->gpa = jIndex->gpa;
            iIndex->gender = jIndex->gender;
            jIndex->id = tempID;
            jIndex->name = tempName;
            jIndex->gpa = tempGPA;
            jIndex->gender = tempGender;
        }
        jIndex = jIndex->next;
    }
    i++;
    if(iIndex == nullptr){
        iIndex = flag.head;
    } else{
        iIndex = iIndex->next;
    }
    tempID = iIndex->id;
    tempName = iIndex->name;
    tempGPA = iIndex->gpa;
    tempGender = iIndex->gender;
    iIndex->id = pivotNode->id;
    iIndex->name = pivotNode->name;
    iIndex->gpa = pivotNode->gpa;
    iIndex->gender = pivotNode->gender;
    pivotNode->id = tempID;
    pivotNode->name = tempName;
    pivotNode->gpa = tempGPA;
    pivotNode->gender = tempGender;
    return i;
}

void quickSortByID(LinkedList& flag,int start,int end){
    if(end<=start){return;}
    int newPivot = quickSortProcess(flag,start,end);
    quickSortByID(flag,start,newPivot-1);
    quickSortByID(flag,newPivot+1,end);
}

void selectionSortByGPA(LinkedList& flag){
    long long tempID;
    std::string tempName;
    float tempGPA;
    char tempGender;
    Node* current = flag.head;
    Node* minimum = current;
    Node* currentNext = current->next;
    for(int i = 1 ; i < flag.population ; i++) {
        while (currentNext != nullptr) {
            if (currentNext->gpa > minimum->gpa) {
                minimum = currentNext;
            }
            currentNext = currentNext->next;
        }
        tempGPA = current->gpa;
        tempName = current->name;
        tempID = current->id;
        tempGender = current->gender;
        current->gpa = minimum->gpa;
        current->name = minimum->name;
        current->id = minimum->id;
        current->gender = minimum->gender;
        minimum->gpa = tempGPA;
        minimum->name = tempName;
        minimum->id = tempID;
        minimum->gender = tempGender;
        current = current->next;
        minimum = current;
        currentNext = current->next;
    }
}

void bubbleSortByGender(LinkedList flag) {
    long long tempID;
    std::string tempName;
    float tempGPA;
    char tempGender;
    Node* i_check = flag.head;
    Node* ii_check = flag.head;
    for(int i = 1 ; i <= flag.population ; i++){
        for(int ii = 1 ; ii <= flag.population ; ii++){
            if(i != ii && i_check->gender < ii_check->gender){
                tempName = i_check->name;
                tempID = i_check->id;
                tempGPA = i_check->gpa;
                tempGender = i_check->gender;
                i_check->name = ii_check->name;
                i_check->id = ii_check->id;
                i_check->gpa = ii_check->gpa;
                i_check->gender = ii_check->gender;
                ii_check->name = tempName;
                ii_check->id = tempID;
                ii_check->gpa = tempGPA;
                ii_check->gender = tempGender;
            }
            ii_check = ii_check->next;
        }
        ii_check = flag.head;
        i_check = i_check->next;
    }
}

void linearSearchName(std::string& nameInput, LinkedList list){
    Node* current = list.head;
    while(current != nullptr){
        if(current->name == nameInput){
            std::cout<<"Student found:\nName: "<<current->name<<" ("<<current->gender<<")"<<"\nID: "<<current->id<<"\nGPA: "<<current->gpa<<'\n';
            return;
        }
        current = current->next;
    }
    std::cout<<"The name \""<<nameInput<<"\" is not within the list\n";
}

int binarySearchID(LinkedList list ,long long flag){
    int low,high,middle;
    long long value;
    Node* midNode;
    low = 0;
    high = list.population;
    while(low <= high){
        midNode = nullptr;
        middle = low + (high - low) / 2;

        //Find the middle Node
        for(int a = 0 ; a < middle ; a++){
            if(midNode== nullptr){midNode=list.head;}
            else{midNode = midNode->next;}
        }
        value = midNode->id;

        if(value < flag){
            low = middle+1;
        } else if(value > flag){
            high = middle-1;
        } else{return middle;}
    }
    return -1;
}

int main() {
    //Declarations
    std::string mainMenu = "1. Add student\n2. Delete student\n3. List students\n4. Create a task\n5. Insert a grade\n6. Search student\n7. Exit\n";
    std::string deleteMenu = "1. Delete newest\n2. Delete oldest\n3. Delete by index\n4. Delete by ID\n5. Delete by name\n6. Go back to main menu\n";
    int menuInput, searchIndex;
    long long idInput;
    float gpaInput;
    std::string nameInput;
    char genderInput;
    bool programIsRunning{true},notValid{true}, deletionIsRunning{true};
    LinkedList test;
    LinkedList sortedTest;
    bool taskDeadlineValid = true;
    bool taskDocumentSelectionValid = true;
    std::string taskTitle, taskDescription, taskDocument, taskDeadlinePhase;
    int taskDeadline,taskDeadlinePhaseSelection,taskDocumentSelection,taskDocumentAmount;
    std::vector<std::string> taskDocumentVector;
    bool taskDeadlinePhaseValid = true;
    Node* target = nullptr;
    int gradingSelection;
    float newGrade;

    //Test subjects for debugging
    test.push_back(44,2.5,"Douglass",'L');
    test.push_back(11,4.0,"Abigail",'P');
    test.push_back(77,1.0,"Goldilock",'P');
    test.push_back(55,2.0,"Estella",'P');
    test.push_back(22,3.5,"Billy",'L');
    test.push_back(33,3.0,"Charlie",'L');
    test.push_back(66,1.5,"Fey",'P');

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
                //GPA = ipk
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
                if(test.population < 1){
                    std::cout<<"There is no student to delete\n";
                } else{
                    do {
                        std::cout << deleteMenu;
                        horizontalLine();
                        std::cin >> menuInput;
                        std::cin.ignore(1, '\n');
                        horizontalLine();
                        switch (menuInput) {
                            case 1:
                                //Delete most recent added
                                test.deleteTail();
                                deletionIsRunning = false;
                                break;
                            case 2:
                                //Delete most oldest added
                                test.deleteHead();
                                deletionIsRunning = false;
                                break;
                            case 3:
                                //Delete by index
                                std::cout << "What is the roll number of the student you want to delete?\n";
                                horizontalLine();
                                std::cin >> menuInput;
                                test.deleteIndex(menuInput);
                                deletionIsRunning = false;
                                horizontalLine();
                                break;
                            case 4:
                                //Delete by ID
                                std::cout << "What is the roll number of the student you want to delete?\n";
                                horizontalLine();
                                std::cin >> menuInput;
                                horizontalLine();
                                if(!test.duplicateID(menuInput)){
                                    std::cout<<"A student by that ID does not exist\n";
                                } else {
                                    test.deleteID(menuInput);
                                }
                                deletionIsRunning = false;
                                horizontalLine();
                                break;
                            case 5:
                                //Delete by name
                                std::cout << "What is the name of the student you want to delete?\n";
                                horizontalLine();
                                std::getline(std::cin, nameInput);
                                capitalize(nameInput);
                                if (!test.duplicateName(nameInput)){
                                    std::cout << "There is no student by that name\n";
                                } else {
                                    test.deleteName(nameInput);
                                }
                                deletionIsRunning = false;
                                horizontalLine();
                                break;
                            case 6:
                                deletionIsRunning = false;
                                break;
                            default:
                                std::cout<< "The value you just entered is beyond our instruction, please try again.\n";
                                break;
                        }
                    } while (deletionIsRunning);
                    deletionIsRunning = true;
                }
                break;
            case 3:
                if(test.population < 1){
                    std::cout<<"List is empty!\n";
                } else {
                    std::cout<< "1. Sort by ID\n2. Sort by name\n3. Sort by GPA\n4. Sort by Gender\n5. Sort by time added"<< std::endl;
                    std::cin>>menuInput;
                    horizontalLine();
                    switch (menuInput) {
                        case 1:
                            sortedTest = test;
                            quickSortByID(sortedTest, 0, test.population - 1);
                            sortedTest.printID();
                            break;
                        case 2:
                            sortedTest = test;
                            bubbleSortByName(sortedTest);
                            sortedTest.printName();
                            break;
                        case 3:
                            sortedTest = test;
                            selectionSortByGPA(sortedTest);
                            sortedTest.printGPA();
                            break;
                        case 4:
                            sortedTest = test;
                            bubbleSortByGender(sortedTest);
                            sortedTest.printGender();
                            break;
                        case 5:
                            test.printName();
                            break;
                        default:
                            break;
                    }
                }
                horizontalLine();
                break;
            case 4:
                if(test.population < 1){
                    std::cout<<"List is empty!\n";
                } else {
                    std::cout << "What is the title of this task you would like to give to your students?\n";
                    std::getline(std::cin, taskTitle);

                    std::cout << "Provide the description of the task:\n";
                    std::getline(std::cin, taskDescription);

                    std::cout << "Would you like to attach any file?\n1. Yes\n2. No\n";
                    while (taskDocumentSelectionValid) {
                        std::cin >> taskDocumentSelection;
                        if (taskDocumentSelection == 1) {
                            std::cout << "How many files do you want to attach?\n";
                            std::cin >> taskDocumentAmount;
                            for (int i = 0; i < taskDocumentAmount; i++) {
                                std::cout << "What is the name of file number " << i + 1 << '\n';
                                std::cin >> taskDocument;
                                taskDocumentVector.push_back(taskDocument);
                            }
                            taskDocumentSelectionValid = false;
                        } else if (taskDocumentSelection == 2) {
                            taskDocument = "-";
                            taskDocumentSelectionValid = false;
                        } else {
                            std::cout << "The value you just entered is beyond our instruction, please try again.\n";
                        }
                    }
                    std::cout << "What is the deadline of this task? (hour from 1 -- 12)\n";
                    while (taskDeadlineValid) {
                        std::cin >> taskDeadline;
                        if (taskDeadline < 13 && taskDeadline > 0) { taskDeadlineValid = false; }
                        else {
                            std::cout << "The value you just entered is not a valid hour.\n";
                        }
                    }
                    std::cout << "1. AM\n2. PM\n";
                    while (taskDeadlinePhaseValid) {
                        std::cin >> taskDeadlinePhaseSelection;
                        if (taskDeadlinePhaseSelection == 1) {
                            taskDeadlinePhase = "AM";
                            taskDeadlinePhaseValid = false;
                        } else if (taskDeadlinePhaseSelection == 2) {
                            taskDeadlinePhase = "PM";
                            taskDeadlinePhaseValid = false;
                        } else {
                            std::cout << "The value you just entered is beyond our instruction, please try again.\n";
                        }
                    }
                    horizontalLine();
                    std::cout << "New task created\n";
                    horizontalLine();
                    capitalize(taskTitle);
                    std::cout << "Title      : " << taskTitle << "\nDeadline   : " << taskDeadline << " "
                              << taskDeadlinePhase << "\nDescription:\n";
                    printStringButWithBreaks(taskDescription);
                    std::cout << "Attachment(s):\n";
                    for (int i = 0; i < taskDocumentVector.size(); i++) {
                        std::cout << "> " << taskDocumentVector[i] << '\n';
                    }
                }
                horizontalLine();
                break;
            case 5:
                if(test.population < 1){
                    std::cout<<"List is empty!\n";
                } else {
                    std::cout << "Which students will receive a grade?\n";
                    test.printName();
                    std::cout << "0. Cancel\nInput:\n";
                    std::cin >> gradingSelection;
                    horizontalLine();
                    if (gradingSelection != 0) {
                        std::cout << "What is the value of the grade?\n";
                        std::cin >> newGrade;
                        for (int i = 0; i <= gradingSelection - 1; i++) {
                            if (target == nullptr) {
                                target = test.head;
                            } else {
                                target = target->next;
                            }
                        }
                        target->gpa += newGrade;
                        target->gpa /= 2.0;
                        horizontalLine();
                        std::cout << "Student successfully has received the grade!" << std::endl;
                        std::cout << target->name << " - GPA: " << target->gpa << '\n';
                    } else {
                        std::cout << "Grading has been cancelled" << std::endl;
                    }
                }
                horizontalLine();
                break;
            case 6:
                std::cout<<"1. Search by name\n2. Search by ID\n3. Exit\n";
                std::cin>>menuInput;
                std::cin.ignore(1, '\n');
                horizontalLine();
                if(menuInput == 1){
                    std::cout<<"Enter the name of the student you wish to search\n";
                    horizontalLine();
                    std::getline(std::cin,nameInput);
                    horizontalLine();
                    capitalize(nameInput);
                    linearSearchName(nameInput,test);
                } else if(menuInput == 2){
                    sortedTest = test;
                    quickSortByID(sortedTest, 0, test.population - 1);
                    std::cout<<"Enter the ID of the student you wish to search\n";
                    horizontalLine();
                    std::cin>>idInput;
                    horizontalLine();
                    searchIndex = binarySearchID(sortedTest,idInput);
                    test.elementAtIndex(searchIndex);
                } else{
                    std::cout<<"Exited search\n";
                }
                horizontalLine();
                break;
            case 7:
                programIsRunning = false;
                break;
            default:
                std::cout << "The value you just entered is beyond our instruction, please try again.\n";
                horizontalLine();
                break;
        }
    }while(programIsRunning);
}
