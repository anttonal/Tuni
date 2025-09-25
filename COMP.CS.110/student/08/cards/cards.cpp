#include "cards.hh"

using namespace std;

Cards::Cards(): top_(nullptr) {

}

Cards::~Cards(){
    while ( top_ != nullptr ) {
        Card_data* card_to_delete = top_;
        top_ = top_->next;

        delete card_to_delete;
    }
}

Card_data* Cards::get_topmost() {
    return top_;
}

void Cards::add(int id) {
    Card_data* new_card = new Card_data{id, nullptr};

    if ( top_ == nullptr ) {
       top_ = new_card;
    } else {
       new_card->next = top_;
       top_ = new_card;
    }
}

void Cards::print_from_top_to_bottom(ostream& s){
    Card_data* card_to_be_printed = top_;
    int running_number = 1;

    while ( card_to_be_printed != nullptr ) {
        s << running_number << ": " << card_to_be_printed->data << endl;
        ++ running_number;
        card_to_be_printed = card_to_be_printed->next;
    }
}

bool Cards::remove(int& id){
    if ( top_ == nullptr ){
        return false;
    }

    Card_data* card_to_be_removed = top_;
    id = card_to_be_removed->data;
    top_ = card_to_be_removed->next;
    delete card_to_be_removed;

    card_to_be_removed = nullptr;

    return true;
}

bool Cards::bottom_to_top() {
    if (top_ == nullptr) {
        return false;
    }

    Card_data* card_in_turn = top_;

    if (card_in_turn->next == nullptr) {
        top_ = nullptr;
        Cards::add(card_in_turn->data);
        delete card_in_turn;
        return true;
    }

    while (card_in_turn->next->next != nullptr) {
        card_in_turn = card_in_turn->next;
    }

    Cards::add(card_in_turn->next->data);

    delete card_in_turn->next;
    card_in_turn->next = nullptr;

    return true;
}


bool Cards::top_to_bottom() {
    if ( top_ == nullptr ){
        return false;
    }

    Card_data* card_in_turn = top_;
    while ( card_in_turn->next != nullptr ){
        card_in_turn = card_in_turn->next;
    }
    card_in_turn->next = top_;
    top_ = top_->next;
    card_in_turn->next->next = nullptr;

    return true;
}

int Cards::recursive_print(Card_data* top, ostream& s) {
    if ( top == nullptr ){
        return 0;
    }

    int count = recursive_print(top->next, s) + 1;

    s << count << ": " << top->data << endl;

    return count;
}

void Cards::print_from_bottom_to_top(ostream& s){
    recursive_print(top_, s);
}
