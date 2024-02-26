cmake_minimum_required(VERSION 3.27)

project(CodeChallenges LANGUAGES CXX)

# Set global C++ standard for the project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories for each language-specific codebase
add_subdirectory(..)

