#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <typeinfo>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

typedef Base* (*CreateFunc)(void);

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

Base* CreateA(void);
Base* CreateB(void);
Base* CreateC(void);

#endif