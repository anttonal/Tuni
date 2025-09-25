#include "list.hh"
#include <iostream>

List::List()
{

}

List::~List()
{

}

void List::insert_at_the_beginning(int i)
{
    if (first_ == nullptr){
        first_ = std::make_shared<List_item>();
        first_->data = i;
        last_ = first_;
    }
    else if (first_->next == nullptr){
        std::shared_ptr<List_item> new_item = std::make_shared<List_item>();
        new_item->data = i;
        new_item->next = first_;
        first_ = std::move(new_item);
    }
    else {
        std::shared_ptr<List_item> new_item = std::make_shared<List_item>();
        new_item->next = first_;
        new_item->data = i;
        first_ = std::move(new_item);
    }

}

void List::insert_at_the_end(int i)
{
    std::string a;
    if (first_ == nullptr){
        first_ = std::make_shared<List_item>();
        first_->data = i;
        last_ = first_;
    }
    else if (first_->next == nullptr){
        std::shared_ptr<List_item> new_item = std::make_shared<List_item>();
        new_item->data = i;
        first_->next = new_item;
        last_ = std::move(new_item);
    }
    else {
        std::shared_ptr<List_item> new_item = std::make_shared<List_item>();
        last_->next = new_item;
        new_item->data = i;
        last_ = std::move(new_item);
    }
}

void List::remove_first()
{
    if (first_ == nullptr){
        return;
    }
    else if (first_->next == nullptr){
        first_ = nullptr;
        last_ = nullptr;
    }
    else {
        first_ = std::move(first_->next);
    }
}

void List::remove_last()
{
    if (first_ == nullptr){
        return;
    }
    else if (first_->next == nullptr){
        first_ = nullptr;
        last_ = nullptr;
    }
    else {
        std::weak_ptr<List_item> wp = first_;
        std::shared_ptr<List_item> sp = wp.lock();

        while (sp->next) {
            wp = sp;
            sp = sp->next;
        }
        sp = wp.lock();
        sp->next = nullptr;
        last_ = sp;

    }
}

void List::print()
{
    if (first_ == nullptr){
        return;
    }
    std::cout << "List elements: ";
    std::weak_ptr<List_item> wp = first_;

    while (std::shared_ptr<List_item> sp = wp.lock())
    {
        std::cout << sp->data << ' ';
        wp = sp->next;
    }
    std::cout << std::endl;
}






















