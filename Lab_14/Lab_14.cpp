#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int MAX_SEATS = 2;


struct PassengerNode {
    string name;
    PassengerNode* next;
};


class TrainReservationSystem {
private:
    PassengerNode* passengerList;  
    stack<string> waitingList;      
    queue<string> bookingQueue;     

public:
    
    TrainReservationSystem() : passengerList(nullptr) {}

    
    void bookTicket(string passengerName) {
        PassengerNode* newPassenger = new PassengerNode{passengerName, nullptr};

        
        if (bookingQueue.size() < MAX_SEATS) {
            bookingQueue.push(passengerName);
            addToPassengerList(newPassenger);
            cout << "Booking confirmed for " << passengerName << endl;
        } else {
            
            waitingList.push(passengerName);
            cout << "Train is fully booked. Added to the waiting list for " << passengerName << endl;
        }
    }

    
    void cancelBooking(string passengerName) {
        
        if (!bookingQueue.empty() && bookingQueue.front() == passengerName) {
            bookingQueue.pop();
        } else {
            
            removeWaitingList(passengerName);
        }

        
        removeFromPassengerList(passengerName);

        cout << "Booking canceled for " << passengerName << endl;
    }

    
    void displayPassengers() {
        cout << "Passengers with confirmed bookings:" << endl;
        displayQueue(bookingQueue);

        cout << "\nPassengers on the waiting list:" << endl;
        displayStack(waitingList);

        cout << "\nPassengers in the order they booked:" << endl;
        displayLinkedList(passengerList);
    }

private:
    
    void addToPassengerList(PassengerNode* newPassenger) {
        newPassenger->next = passengerList;
        passengerList = newPassenger;
    }

    
    void removeFromPassengerList(string passengerName) {
        PassengerNode* current = passengerList;
        PassengerNode* previous = nullptr;

        while (current != nullptr && current->name != passengerName) {
            previous = current;
            current = current->next;
        }

        if (current != nullptr) {
            if (previous != nullptr) {
                previous->next = current->next;
            } else {
                passengerList = current->next;
            }
            delete current;
        }
    }
    
    void removeWaitingList(string passengerName) {
        stack<string> tempStack;

        while (!waitingList.empty()) {
            if (waitingList.top() != passengerName) {
                tempStack.push(waitingList.top());
            }
            waitingList.pop();
        }

        while (!tempStack.empty()) {
            waitingList.push(tempStack.top());
            tempStack.pop();
        }
    }

    
    void displayQueue(queue<string> q) {
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }

    
    void displayStack(stack<string> s) {
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    
    void displayLinkedList(PassengerNode* head) {
        while (head != nullptr) {
            cout << head->name << " ";
            head = head->next;
        }
        cout << endl;
    }
};


int main() {
    TrainReservationSystem trainSystem;

    
    trainSystem.bookTicket("Hammad");
    trainSystem.bookTicket("Musa");
    trainSystem.bookTicket("Umair");
    trainSystem.displayPassengers();

    trainSystem.cancelBooking("Umar");
    trainSystem.bookTicket("Waqar");
    trainSystem.displayPassengers();

    return 0;
}
