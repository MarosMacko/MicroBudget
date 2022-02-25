cmake_minimum_required(VERSION 3.19)
project(MicroBudget)

set(CMAKE_C_STANDARD 11)

file(GLOB MicroBudget_SRC
        "*.h"
        "*.c"
        "*.cpp"
        )

add_executable(MicroBudget ${MicroBudget_SRC})