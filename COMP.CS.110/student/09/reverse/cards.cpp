#include <iostream>
#include <memory>
#include "cards.hh"


Cards::Cards(): top_( nullptr ) {
}


void Cards::add(int id) {
    std::shared_ptr<Card_data> new_card 
            = std::make_shared<Card_data>(Card_data{id, top_});
    top_ = new_card;
}

void Cards::print(std::ostream& s) {
   std::shared_ptr<Card_data> to_be_printed = top_;
   int nr = 1;

   while( to_be_printed != 0 ) {
      s << nr << ": " << to_be_printed->data << std::endl;
      to_be_printed = to_be_printed->next;
      ++nr;
   }
}

bool Cards::remove(int &id)
{
    if ( top_ != nullptr ){
        id = top_->data;
        top_ = top_->next;
        return true;
    } else {
        return false;
    }
}

void Cards::reverse()
{
    if ( top_ == nullptr || top_->next == nullptr){
        return;
    } else {
        std::shared_ptr<Card_data> card_on_bottom = top_;
        std::shared_ptr<Card_data> card_in_iteration = top_;
        while ( card_in_iteration->next != nullptr ) {
            card_in_iteration = card_in_iteration->next;
            Cards::add( card_in_iteration->data );
        }
        card_on_bottom->next = nullptr;
    }
}

// Tip for writing code more efficiently:
// Do not write the stubs of the methods remove and reverse by yourself here,
// but open the file cards.hh and click the declaration of the method
// by the right mouse button and select
// Refactor > Add definition in cards.cpp
