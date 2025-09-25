#include "queue.hh"

// Constructor that initializes the attribute cycle_.
// (The other attibutes are initialized in the private part below.)
Queue::Queue(unsigned int cycle): cycle_(cycle) {
}

// Destructor that deletes all the remaining vehicles from the queue.
Queue::~Queue(){

}

// If the color of traffic light is red, inserts a vehicle, the register
// number of which is reg, to the queue.
void Queue::enqueue(string const& reg){
    Vehicle* new_vehicle = new Vehicle{reg, nullptr};

    if ( first_ == nullptr ){
        first_ = new_vehicle;
        last_ = new_vehicle;
    } else {
        new_vehicle->next = last_;
        last_ = new_vehicle;
    }

    if ( is_green_ ){
        cout << "GREEN: The vehicle ";
        dequeue();
        cout << "need not stop to wait" << endl;
    }
}

bool Queue::dequeue(){
    if ( first_ == nullptr ){
        return true;
    } else if ( first_ == last_ ){
        cout << first_->reg_num << " ";
        delete first_;
        first_ = nullptr;
        last_ = nullptr;
        return false;
    } else {
        Vehicle* new_first_vehicle = last_;
        while ( new_first_vehicle->next != first_ ){
            new_first_vehicle = new_first_vehicle->next;
        }
        new_first_vehicle->next = nullptr;
        cout << first_->reg_num << " ";
        delete first_;
        first_ = new_first_vehicle;
        return false;
    }
}

void Queue::switch_light(){
    if ( is_green_ ){
        cout << "RED: No vehicles waiting in traffic lights" << endl;
        is_green_ = false;
    } else {
        if ( first_ == nullptr) {
            cout << "GREEN: No vehicles waiting in traffic lights" << endl;
            is_green_ = true;
        } else {
            cout << "GREEN: Vehicle(s) ";
            if ( not dequeue() ) {
                is_green_ = false;
                for ( unsigned int i = 1; i<cycle_; ++i ){
                    dequeue();
                }
            }
            cout << "can go on" << endl;
        }
    }
}

void Queue::reset_cycle(unsigned int cycle){
cycle_ = cycle;
}

void Queue::recursive_printing(Vehicle* last) const {
    if ( last == nullptr ){
        return;
    } else {
        recursive_printing(last->next);
        cout << last->reg_num << " ";
    }
}

// Prints the color of traffic light and the register numbers of those
// cars that are waiting in the traffic light queue (if any).
void Queue::print() const {
    if ( is_green_ ){
        cout << "GREEN: No vehicles waiting in traffic lights" << endl;
    } else {
        cout << "RED: ";
        if ( first_ == nullptr) {
            cout << "No vehicles waiting in traffic lights" << endl;
        } else {
            cout << "Vehicle(s) ";
            recursive_printing(last_);
            cout << "waiting in traffic lights" << endl;
        }

    }
}
