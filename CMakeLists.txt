cmake_minimum_required(VERSION 3.10)
project(pamtest C)

add_executable(${PROJECT_NAME}
    pamtest.c
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    pam
    pam_misc
)
