#include<iostream>
#include<climits>
#include<string>
#include<cstring>
#include<vector>
#include<climits>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int adminID = 0;
string adminPass = "1234";

struct adminLogIn {
    int id;
    string name;
    string password;
};

bool adminLogin() {
    adminLogIn *add = new adminLogIn;
    cout << "\n\t\tA D M I N\n";
    cout << "\nEnter ID: ";
    cin >> add -> id;
    cout << "Enter password: ";
    cin >> add -> password;
    if (add -> id == adminID && add -> password == adminPass) {
        return true;
    }
    else return false;
}
vector<string> flights = {"emirates", "	PIA", "Air Sial", "turkey"};
vector<double> cost = {10000.0, 20000.0, 55000.0, 60000.0};

void addflight() {
    string temp;
    double tempbill = 0.0;
    cout << "\nEnter new flight: ";
    cin >> temp;
    cout << "Enter cost: ";
    cin >> tempbill;
    flights.push_back(temp);
    cost.push_back(tempbill);
    cout << "\nSuccessful\n";
}

void delflight() {
    string temp;
    cout << "\nEnter flight to remove: ";
    cin >> temp;
    int tempindex = -1;
    for (int i = 0; i < flights.size(); i++) {
        if (flights[i] == temp) {
            tempindex = i;
            break;
        }
    }
    if (tempindex == -1) cout << "\nNot found\n";
    else {
        flights.erase(flights.begin() + tempindex);
        cost.erase(cost.begin() + tempindex);
        cout << "\nSuccessful\n";
    } 
}
struct flightRecord {
    string flightNo;
    string address;
    double amount = 0.0;
    flightRecord *forw = NULL;
};
struct flightOperator {
    string id;
    string password;
    string name;
    
    int totalflights = 0;
    flightOperator *next = NULL;
    flightRecord *record = NULL;
};

flightOperator *head = NULL, *tail = NULL, *current = NULL;
flightOperator *s = NULL;

bool flightOperatorLogIN() {
    string tempid, tempPass;
    cout << "\n\t\tF L I G H T O P E R A T O R\n";
    cout << "\nEnter ID: ";
    cin >> tempid;
    cout << "Enter password: ";
    cin >> tempPass;
    bool validation = false;
    flightOperator *p = head;
    while (p != NULL) {
        if (p -> id == tempid && p -> password == tempPass) {
            validation = true;
            break;
        }
        p = p -> next;
    }
    s = p;
    return validation;
}
vector<string> addresses= {"LONDON" ,"UAE", "AUSTRALIA" ,"QATAR", "TURKEY", "OMAN","newzeland","bangladesh"};
int totalAdd = 0;
void destinationAddresses() {
	cout<<"\n\t Destination adresses\n";
	for(int i=0;i<addresses.size();i++){
		cout<<addresses[i]<<endl;
	}
    
    }


void dijkstra(int **graph, int n, int target) {
    int distance[n];
    int parent[n];
    bool visited[n];
    for (int i = 0; i < n; i++) {
        distance[i] = INT_MAX;
        parent[i]=INT_MAX;
        visited[i] = false;
    }
    distance[0] = 0;
    for (int p = 0; p < n; p++) {
        int min = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (min == -1 || distance[j] < distance[min])) {
                min = j;
            }
        }
        visited[min] = true;
        for (int k = 0; k < n; k++) {
            if (graph[min][k] != 0 && (distance[min] + graph[min][k]) < distance[k]) {
                distance[k] = distance[min] + graph[min][k];
            }
        }
    }
    string temp="PAKISTAN";
    if (parent[target] != 0) {
        int a = parent[target];
        while (a != 0) {
            temp += addresses[a] + " -> ";
            a = parent[a];
        }
        temp += addresses[target];
        cout << "Shortest path is " << temp << " with total cost: " << distance[target] << endl;
}
else{
	cout << "Shortest distance from cafe to " << addresses[target] << " is: " << distance[target] << endl;
}
}

void getDistance() {
	int totaladd=8;
    int **graph = new int*[totalAdd];
    for (int i = 0; i < totalAdd; i++) {
        graph[i] = new int[totalAdd];
    }
    for (int i = 0; i < totalAdd; i++) {
        for (int j = 0; j < totalAdd; j++) {
            graph[i][j] = 0;
        }
    }
    // source(Pakistan) to other locations
    graph[0][1] = 3;
    graph[0][2] = 4;
    graph[0][3] = 9;
    graph[0][5] = 7;
    graph[0][6] = 13;

    graph[1][3] = 10;
    graph[1][5] = 1;

    graph[2][4] = 4;
    graph[2][6] = 8;
    graph[2][7] = 4;
    
    graph[3][1] = 10;
    graph[3][4] = 5;
    graph[3][5] = 12;
    graph[3][7] = 6;

    graph[4][2] = 4;
    graph[4][3] = 5;
    graph[4][5] = 6;
    graph[4][7] = 5;

    graph[5][1] = 1;
    graph[5][3] = 12;
    graph[5][4] = 6;
    
    graph[6][2] = 8;
    graph[6][7] = 1;

    graph[7][2] = 4;
    graph[7][3] = 6;
    graph[7][4] = 5;
    graph[7][6] = 1;
    // getting location
    flightOperator *p = s;
    flightRecord *a = p -> record;
    string destinationAdd = a -> address;
    int index = -1;
    for (int i = 0; i < addresses.size(); i++) {
        if (destinationAdd == addresses[i]) {
            index = i;
            break;
        }
    }
        dijkstra(graph, totalAdd, index);

    
}
void registerflightOperator() {
    current = new flightOperator;
    cout << "\nSet logIn ID: ";
    cin >> current -> id; 
    cout << "Set password: ";
    cin >> current -> password;
    cout << "Enter name of rider: ";
    cin >> current -> name;
    if (head == NULL) {
        head = tail = current;
    }
    else {
        tail -> next = current;
        tail = current;
    }
    cout << "\nSuccessful\n";
}
flightOperator *tempH = NULL, *tempT = NULL;
void newflightOperator(string flightNo, string addresss, double amount) {
    flightOperator *p = head;
    flightOperator *q = tempH;
    if (q != NULL) {
        while (p != NULL) {
            while (p -> id != q -> id && q != NULL) {
                q = q -> next;
            }
            if (p -> id == q -> id) {
                p = p -> next;
            }
            else break;
        }
    }
    flightRecord *a = new flightRecord;
    a -> flightNo = flightNo;
    a -> address = addresss;
    a -> amount = amount;
    p -> totalflights += 1;
    if (p -> record == NULL) {
        p -> record = a;
    }
    else {
        a -> forw = p -> record;
        p -> record = a;
    }
    if (tempH == NULL) {
        tempH = tempT = p;
    }
    else {
        tempT -> next = p;
        tempT = p;
    }
}
void flightOperatorrecord() {
    flightOperator *a = head;
    if (a != NULL) {
        while (a != NULL) {
            cout << "\nOperator name: " << a -> name << endl;
            cout << "Total Flights: " << a -> totalflights << endl;
            flightRecord *b = a -> record;
            while (b != NULL) {
                cout << "Flight number: " << b -> flightNo << endl;
                cout << "Flight destination: " << b -> address << endl;
                cout << "Order bill: " << b -> amount << endl;
                b = b -> forw;
            }
            a = a -> next;
        }
    }
    else cout << "\nNo flights yet!\n";
}
void flightOperatorProfile() {
    if (flightOperatorLogIN()) {
        cout << "\n name: " << s -> name << endl;
        cout << "id: " << s -> id << endl;
        cout << "Total order: " << s -> totalflights << endl;
        flightRecord *n = s -> record;
        while (n != NULL) {
            cout << "Flight number: " << n -> flightNo << endl;
            cout << "flight address: " << n -> address << endl;
            cout << "flight bill: " << n -> amount << endl;
            n = n -> forw;
        }
    }
    else cout << "\nWrong password or user ID\n";
}
void flightOperator1() {
    int opt;
    do {
        cout << "\nEnter 1 to register as a new operator"
        "\nEnter 2 to access r profile \nEnter 0 to exit --> ";
        cin >> opt;
        switch(opt) {
            case 0:
                break;
            case 1:
                registerflightOperator();
                break;
            case 2:
                flightOperatorProfile();
                break;
        }
    } while (opt != 0);
}
struct passengerRecord {
    int no_of_seats;
    double amount = 0.0;
    passengerRecord *Cforw = NULL;
};
struct passenger {
    string id;
    string password;
    string name;
    string address;
    passenger *Cnext = NULL;
    passengerRecord *record = NULL;
};

passenger *Chead = NULL, *Ctail = NULL, *Ccurrent = NULL;
passenger *person = NULL;

bool passengerLogIN() {
    string tempid, tempPass; 
    cout << "\n\t\tP A S S E N G E R\n";
    cout << "\nEnter ID: ";
    cin >> tempid;
    cout << "Enter password: ";
    cin >> tempPass;
    bool validation = false;
    passenger *p = Chead;
    while (p != NULL) {
        if (p -> id == tempid && p -> password == tempPass) {
            validation = true;
            break;
        }
        p = p -> Cnext;
    }
    person = p;
    return validation;
}
//new passenger registration
void newpassengerReg() {
    Ccurrent = new passenger;
    cout << "\nSet log-in ID: ";
    cin >> Ccurrent -> id;
    cout << "Set password: ";
    cin >> Ccurrent -> password;
    cout << "Enter name: ";
    cin >> Ccurrent -> name;
    cout << "Enter address: ";
    cin >> Ccurrent -> address;
    if (Chead == NULL) {
        Chead = Ctail = Ccurrent;
    }
    else {
        Ctail -> Cnext = Ccurrent;
        Ctail = Ccurrent;
    }
    cout << "\nSuccessful\n";
}
void displayflights() {
    cout << "\n\t\tF L I G H T S\n";
    for (int i = 0; i < flights.size(); i++) {
        cout << flights[i] << " -> " << cost[i] << endl;
    }
}
vector<string> flightRecord;
double totalBill;
void Booking() {
    int opt;
    while (true) {
        double tempBill = totalBill;
        string choose;
        displayflights();
        cin >> choose;
        for (int i = 0; i < flights.size(); i++) {
            if (flights[i] == choose) {
                flightRecord.push_back(choose);
                totalBill += cost[i];
            }
        }
        if (tempBill == totalBill) {
            cout << "\nSorry, we don't offer your selected flight\n";
        }
        cout << "\nEnter 1 to continue booking or \nEnter any other key to exit: ";
        cin >> opt;
        if (opt != 1) {
            break;
        }
    }
}
void displayPassenger() {
    passenger *p = Chead;
    if (p != NULL) {
        while (p != NULL) {
            cout << "\nID: " << p -> id << endl;
            cout << "Name: " << p -> name << endl;
            cout << "Address: " << p -> address << endl;
            p = p -> Cnext;
        }
    }
    else cout << "\nNo passenger to display!\n";
}
void passengerRecord2() {
    if (passengerLogIN()) {
        passengerRecord *q = person -> record;
        while (q != NULL) {
            cout << "\n no of seats: " << q -> no_of_seats << endl;
            cout << "Bill : " << q -> amount << endl;
            q = q -> Cforw;
        }
    }
    else cout << "\nInvalid password or user ID!\n";
}
void passenger1() {
    int opt;
    do {
        cout << "\nEnter 1 to register a \nEnter 2 for booking"
        "\nEnter 3 to access profile \nEnter 0 to exit --> ";
        cin >> opt;
        switch(opt) {
            case 0:
                break;
            case 1:
                newpassengerReg();
                break;
            case 2:
                Booking();
                break;
            case 3:
                passengerRecord2();
                break;
        }
    } while (opt != 0);
}

void displayflightOperator() {
    flightOperator *p = head;
    if (p != NULL) {
        while (p != NULL) {
            cout << "\n\t\tR I D E R S";
            cout << "\nID: " << p -> id << endl;
            cout << "Name: " << p -> name << endl;
            //end pa check arni ya cheez lazmi
            cout << "total fligts: " << p ->totalflights << endl;
            p = p -> next;
        }
    }
    else cout << "\nNo operator to display to display!\n";
}
void removeflightOperator() {
    flightOperator *p = head, *q = NULL;
    if (p != NULL) {
        displayflightOperator();
        string Id;
        cout << "\nEnter ID  to remove: ";
        cin >> Id;
        while (p -> id != Id && p != NULL) {
            q = p;
            p = p -> next;
        }
        if (p -> id == Id && q == NULL) {
            head = p -> next;
            delete p;
        }
        else if (p -> id == Id && p == tail && q != NULL) {
            q -> next = NULL;
            tail = q;
            delete p;
        }
        else {
            q -> next = p -> next;
            delete p;
        }
        cout << "\nSuccessful\n";
    }
    else cout << "\nNo flight Operator to remove!\n";
}
//admin handles
void adminflightOperator() {
    int opt;
    do {
        cout << "\nEnter 1 to add a flight operator \nEnter 2 remove  \nEnter 3 to view  record"
        "\nEnter 0 to exit --> ";
        cin >> opt;
        switch(opt) {
            case 0:
                break;
            case 1:
                registerflightOperator();
                break;
            case 2:
                removeflightOperator();
                break;
            case 3:
                flightOperatorrecord();
                break;
        }
    } while (opt != 0);
}
void removepassenger() {
    passenger *p = Chead, *q = NULL;
    if (p != NULL) {
        displayPassenger();
        string Id;
        cout << "\nEnter ID  to remove: ";
        cin >> Id;
        while (p -> id != Id && p != NULL) {
            q = p;
            p = p -> Cnext;
        }
        if (p -> id == Id && q == NULL) {
            Chead = p -> Cnext;
            delete p;
        }
        else if (p -> id == Id && p == Ctail && q != NULL) {
            q -> Cnext = NULL;
            Ctail = q;
            delete p;
        }
        else {
            q -> Cnext = p -> Cnext;
            delete p;
        }
        cout << "\nSuccessful\n";
    }
    else cout << "\nNo passenger to remove!\n";
}
void adminpassenger() {
    int opt;
    do {
        cout << "\nEnter 1 to add a passenger \nEnter 2 remove a passenger"
        "\nEnter 3 to display all passenger \nEnter 0 to exit --> ";
        cin >> opt;
        switch(opt) {
            case 0:
                break;
            case 1:
                newpassengerReg();
                break;
            case 2:
                removepassenger();
                break;
            case 3:
                displayPassenger();
                break; 
        }
    } while (opt != 0);
}

//void displayflights1() {
//    flightRecord *p = dHead;
//    if (p != NULL) {
//        while (p != NULL) {
//            cout << "\n\t\tO R D E R S";
//            cout << "\nOrder: " << p -> flightNo << endl;
//            cout << "Address: " << p -> address << endl;
//            cout << "Bill amount: " << p -> amount << endl;
//            p = p -> forw;
//        }
//    }
//    else cout << "\nNo order to deliver";
//}

void admin() {
    if (adminLogin()) {
        int opt;
        do {
            cout << "\nEnter 1 to add flights \nEnter 2 to delete flights \nEnter 3 to display flights details"
            "\nEnter 4 to access flightOperator  profile \nEnter 5 to access passenger profiles"
            
            "\nEnter 0 to exit --> ";
            cin >> opt;
            switch (opt) {
                case 0:
                    break;
                case 1:
                    addflight();
                    break;
                case 2:
                    delflight();
                    break;
                case 3:
                    displayflights();
                    break;
                case 4:
                    adminflightOperator();
                    break;
                case 5:
                    adminpassenger();
                    break;
            }
        } while (opt != 0);
    }
    else cout << "\nInvalid password or user ID!\n";
}
int main() {
    int opt;
    do {
        cout << "\nEnter 1 for admin menu \nEnter 2 for passenger menu" 
           "\nEnter 3 for flightOperator menu"
           
           "\nEnter 4 for getting shortest distance"
           "\nEnter 0 to QUIT --> ";
        cin >> opt;
        switch (opt) {
            case 0:
                break;
            case 1:
                admin();
                break;
            case 2:
                passenger1();
                break;
            case 3:
                flightOperator1();
                break;
            case 4:
                getDistance();
                break;
        }
    } while (opt != 0);
}


