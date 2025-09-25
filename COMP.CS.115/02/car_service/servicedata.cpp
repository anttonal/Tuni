#include "servicedata.hh"
#include <iostream>

ServiceData::ServiceData()
{}

ServiceData::~ServiceData()
{}

bool ServiceData::makeService(const Service& service, int kilometres)
{
    auto result = services_.insert(std::make_pair(kilometres, service));

    if (!result.second) {
        std::cout << "Error: already serviced with the same kilometres" << std::endl;
        return false;
    }

    return true;
}


void ServiceData::print() const
{
    for (const auto& pair : services_){
        std::cout << "* Kilometres driven " << pair.first << " until " << pair.second.date_ << std::endl;
        for (const auto& operation : pair.second.operations_){
            std::cout << "--- " << operation << std::endl;
        }
    }
    std::cout << std::endl;
}

const std::map<int, Service> &ServiceData::getServices() const
{
    return services_;
}
