cmake_minimum_required(VERSION 3.10)

project(RedisIP VERSION 0.1.0 DESCRIPTION "Redis Module for IP discovery")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)


include_directories(include)
add_library(redisip SHARED
    src/ipmodule.c
)


set_target_properties(redisip PROPERTIES VERSION ${PROJECT_VERSION})




