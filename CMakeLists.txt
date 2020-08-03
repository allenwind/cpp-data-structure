cmake_minimum_required (VERSION 3.2.0)

project (cpp_template_examples)

add_executable(stack_test stack0.cpp stack.h)

add_executable(queue_test queue0.cpp queue.h)

add_executable(liststack_test liststack.h liststack0.cpp)