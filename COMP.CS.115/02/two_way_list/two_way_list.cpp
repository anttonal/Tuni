#include "two_way_list.hh"
#include <iostream>
#include <memory>

using namespace std;

TwoWayList::TwoWayList():
    first_(nullptr),
    last_(),
    count_(0) {
}

int TwoWayList::length() const {
    return count_;
}

bool TwoWayList::has_value(int value) const {
    shared_ptr<List_item> current_ptr = first_;

    while ( current_ptr != nullptr ) {
        if ( current_ptr->data == value ) {
            return true;
        } else if ( current_ptr->data > value ) {
            return false;
        }

        current_ptr = current_ptr->next;
    }

    return false;
}

void TwoWayList::print() const {
    shared_ptr<List_item> printable_ptr = first_;

    cout << "Number of elements in the list: " << length() << endl;

    while ( printable_ptr != nullptr ) {
        cout << printable_ptr->data << " ";

        printable_ptr = printable_ptr->next;
    }

    cout << endl;
}

void TwoWayList::print_reverse() const {
    List_item* printable_ptr = last_.lock().get();;

    cout << "Number of elements in the list: " << length() << endl;

    while ( printable_ptr != nullptr ) {
        cout << printable_ptr->data << " ";

        printable_ptr = printable_ptr->prev.lock().get();
    }

    cout << endl;
}

bool TwoWayList::remove_value(int removable_item) {
    shared_ptr<List_item> sp = last_.lock();
    if ( length() == 0 ) {
        return false;
    }

    shared_ptr<List_item> removable_ptr = first_;

    while ( true ) {
        if ( removable_ptr->data == removable_item ) {
            break;         // Removable value found.

        } else if ( removable_ptr->data > removable_item ) {
            return false;  // Value cannot lie in the rest of the list.

        } else if ( removable_ptr->next == nullptr ) {
            return false;  // Last element processed.

        } else {
            removable_ptr = removable_ptr->next;
        }
    }

    // At this point, we have found the removable value
    // and removable_ptr points to it.

    // Removable element is the only element of the list.
    if ( first_ == sp ) {

        first_ = nullptr;
        last_.reset();

        // Removable element is the first element of the list.
    } else if ( removable_ptr == first_ ) {

        first_ = first_->next;
        first_->prev.reset();

        // Removable element is the last element of the list.
    } else if ( removable_ptr == sp ) {

        last_ = sp->prev;
        sp->next = nullptr;

        // Removable element lies between the first and the last element.
    } else {

        removable_ptr->prev.lock()->next = removable_ptr->next;
        removable_ptr->next->prev = removable_ptr->prev;
    }

    --count_;

    return true;
}

bool TwoWayList::insert_in_numerical_order(int insertable_item) {
    shared_ptr<List_item> insertable_ptr = make_shared<List_item>();
    shared_ptr<List_item> sp = last_.lock();
    insertable_ptr->data = insertable_item;

    // Inserting to an empty list
    if ( length() == 0 ) {

        insertable_ptr->next = nullptr;
        insertable_ptr->prev.reset();

        first_ = insertable_ptr;
        last_ = insertable_ptr;

        // Inserting to the front of the list
    } else if ( insertable_item <= first_->data ) {

        insertable_ptr->next = first_;
        insertable_ptr->prev.reset();

        first_->prev = insertable_ptr;
        first_ = insertable_ptr;

        // Inserting to the back of the list
    } else if ( insertable_item >= sp->data ) {

        insertable_ptr->next = nullptr;
        insertable_ptr->prev = last_;

        sp->next = insertable_ptr;
        last_ = insertable_ptr;

        // Inserting in the middle of the list
    } else {
        shared_ptr<List_item>
                current_ptr = first_;

        // Finding out the first element, the value of which is greater
        // or equal to insertable_item
        while ( current_ptr->data < insertable_item ) {
            current_ptr = current_ptr->next;
        }

        // Now current_ptr points to the first one of such elements in the list
        // that have greater value than insertable_item:
        // the new element will be inserted in the front of it.

        insertable_ptr->next = current_ptr;
        insertable_ptr->prev = current_ptr->prev;

        insertable_ptr->prev.lock()->next = insertable_ptr;
        insertable_ptr->next->prev = insertable_ptr;
    }

    ++count_;

    return true;
}

void TwoWayList::remove_duplicates()
{
    shared_ptr<List_item> current = first_;

    while (current) {
        while (current->next && current->next->data == current->data) {
            shared_ptr<List_item> duplicate = current->next;
            current->next = duplicate->next;
            // If there's a node after the duplicate, update its prev pointer
            if (duplicate->next) {
                duplicate->next->prev = current;
            } else {
                // If duplicate was the last node, update last_
                last_ = current;
            }
            count_--;  // Adjust the count accordingly
        }
        current = current->next;
    }
}
