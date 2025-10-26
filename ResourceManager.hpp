#pragma once

#include "Resource.hpp"


class ResourceManager
{
private:
    Resource* res; 

public:
    ResourceManager() : res(new Resource()) {}

    ~ResourceManager() { delete res; }

    ResourceManager(const ResourceManager& other) : res(new Resource(*other.res)) {}

    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            ResourceManager temp(other); 
            std::swap(res, temp.res);    
        }
        return *this;
    }


    double get() const { return res->get(); }
};

