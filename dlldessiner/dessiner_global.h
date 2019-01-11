#ifndef DESSINER_GLOBAL_H
#define DESSINER_GLOBAL_H

#if defined(DESSINER_LIBRARY)
#  define DESSINERSHARED_EXPORT __declspec(dllexport)
#else
#  define DESSINERSHARED_EXPORT __declspec(dllimport)
#endif

#endif // DESSINER_GLOBAL_H
