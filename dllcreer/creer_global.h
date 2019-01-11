#ifndef CREER_GLOBAL_H
#define CREER_GLOBAL_H

#if defined(CREER_LIBRARY)
#  define CREERSHARED_EXPORT __declspec(dllexport)
#else
#  define CREERSHARED_EXPORT __declspec(dllimport)
#endif


#endif // CREER_GLOBAL_H
