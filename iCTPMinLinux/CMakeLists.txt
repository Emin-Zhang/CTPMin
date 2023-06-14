cmake_minimum_required (VERSION 3.2)

project (CTPMin)

add_definitions(-std=c++11)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(${PROJECT_NAME} 
    main.cpp
    MD.cpp
    MT.cpp
    MyTrade.cpp
    TD.cpp
    
    )  



add_library(thostmduserapi SHARED IMPORTED)
set_property(TARGET thostmduserapi PROPERTY
        IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/thostmduserapi_se.so)

add_library(thosttraderapi SHARED IMPORTED)
set_property(TARGET thosttraderapi PROPERTY
        IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/thosttraderapi_se.so)


target_link_libraries(${PROJECT_NAME} thostmduserapi  thosttraderapi )
