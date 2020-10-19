/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include <iostream>
#include <ostream>
#include <cstdio>
#include <cstddef>
#include <dlfcn.h>
template <typename T>
class DLLoader {
    public:
        DLLoader() {};
        ~DLLoader() {};
        T* getInstance(const char *libname, void**handle) {
            T *(*func) (void);
            char *error;

            (*handle) = dlopen(libname, RTLD_GLOBAL | RTLD_LAZY);
            if (!(*handle)) {
                std::cout << std::endl;
                fprintf(stderr, "%s\n", dlerror());
                return NULL;
            }
            dlerror();

            func = (T *(*) (void)) dlsym((*handle), "getModule");

            if ((error = dlerror()) != NULL)  {
                std::cout << std::endl;
                fprintf(stderr, "%s\n", error);
                return NULL;
            }

            return ((*func)());
        }
    private:
};

#endif /* !DLLOADER_HPP_ */
