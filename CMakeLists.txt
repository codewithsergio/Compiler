cmake_minimum_required(VERSION 3.23)
project(CPlusPlayGround)

set(CMAKE_CXX_STANDARD 20)

add_executable(CPlusPlayGround main.cpp includes/Token.cpp includes/Token.h includes/IdentifierToken.cpp includes/IdentifierToken.h includes/NumberToken.cpp includes/NumberToken.h includes/IntToken.cpp includes/IntToken.h includes/BoolToken.cpp includes/BoolToken.h includes/VarDecToken.cpp includes/VarDecToken.h includes/TrueToken.cpp includes/TrueToken.h includes/FalseToken.cpp includes/FalseToken.h includes/WhileToken.cpp includes/WhileToken.h includes/LeftParenToken.cpp includes/LeftParenToken.h includes/RightParenToken.cpp includes/RightParenToken.h includes/Tokenizer.cpp includes/Tokenizer.h)
