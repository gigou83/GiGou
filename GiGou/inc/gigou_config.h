#ifndef GIGOU_CONFIG_H
#define GIGOU_CONFIG_H

/*#define GIGOU_DEBUG*/

#ifdef GIGOU_DOUBLE
typedef double REAL;
#else
typedef float REAL;
#endif

typedef signed char             INT8;
typedef unsigned char           UINT8;
typedef signed int              INT16;
typedef unsigned int            UINT16;
typedef signed long int         INT32;
typedef unsigned long int       UINT32;

typedef const signed char       CINT8;
typedef const unsigned char     CUINT8;
typedef const signed int        CINT16;
typedef const unsigned int      CUINT16;
typedef const signed long int   CINT32;
typedef const unsigned long int CUINT32;

/* typedef signed long long int      INT64; */
/* typedef unsigned long long int    UINT64; */

#endif