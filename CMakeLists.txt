cmake_minimum_required(VERSION 3.30)
project(FawryChallenge)

set(CMAKE_CXX_STANDARD 23)

add_executable(FawryChallenge main.cpp
        System.h
        Stock.cpp
        Stock.h
        Customer.cpp
        Customer.h
        Shop.cpp
        Shop.h
        ShippingService.cpp
        ShippingService.h
        Product.cpp
        Product.h)
