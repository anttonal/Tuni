#include "car.hh"
#include <iostream>

Car::Car() : brand_(""), model_(""), color_(""), registerNum_(""), kilometresDriven_(0)
{
    service_data_ = std::unique_ptr<ServiceData>(new ServiceData());
}

Car::Car(const std::string &brand, const std::string &model, const std::string &color, const std::string &regNum)
: brand_(brand), model_(model), color_(color), registerNum_(regNum), kilometresDriven_(0)
{
    service_data_ = std::unique_ptr<ServiceData>(new ServiceData());
}

Car::Car(const Car &other)
: brand_(other.brand()), model_(other.model()), color_(other.color()), registerNum_(""), kilometresDriven_(0)
{
    service_data_ = std::unique_ptr<ServiceData>(new ServiceData());
}

Car::~Car()
{}

Car& Car::operator=(const Car &other)
{
    if (this == &other) {
        return *this;
    }

    brand_ = other.brand();
    color_ = other.color();
    registerNum_ = other.registerNum();
    model_ = other.model();
    kilometresDriven_ = other.kilometresDriven();
    service_data_ = std::unique_ptr<ServiceData>(new ServiceData(other.serviceData()));

    return *this;
}

void Car::setRegisterNum(const std::string &regNum)
{
    registerNum_ = regNum;
}

void Car::setColor(const std::string &color)
{
    color_ = color;
}

std::string Car::brand() const
{
    return brand_;
}

std::string Car::model() const
{
    return model_;
}

std::string Car::color() const
{
    return color_;
}

std::string Car::registerNum() const
{
    return registerNum_;
}

int Car::kilometresDriven() const
{
    return kilometresDriven_;
}

const ServiceData& Car::serviceData() const
{
    return *service_data_;
}

void Car::drive(int kilometres)
{
    kilometresDriven_ += kilometres;
}

bool Car::service(const Service &service)
{
    return service_data_->makeService(service, kilometresDriven_);
}

bool Car::service(const std::string &date, const std::vector<std::string> &operations)
{
    Service service{date, operations};
    return service_data_->makeService(service, kilometresDriven_);
}

void Car::print() const
{
    std::cout << registerNum_ << " : " << brand_ << " : " <<  model_ << " : " << color_ << std::endl;
    service_data_->print();
}
