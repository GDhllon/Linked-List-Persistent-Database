#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum BOOLEAN
{
	false,
	true
};

enum param_t
{
	INT_TYPE,
	REAL_TYPE,
	BOOLEAN_TYPE,
	STRING_TYPE,
	LIST_TYPE
};

typedef struct Parameter Parameter;
typedef struct Boolean Boolean;
typedef struct ParameterList ParameterList;
typedef struct ParameterManager ParameterManager;
typedef enum param_t param_t;

struct Boolean
{
    int tf;
};

union param_value
{
    int int_val;
    float real_val;
    Boolean bool_val;
    char *str_val;
    ParameterList *list_val;
};

struct Parameter
{
    char * key;
    Boolean req;
    union param_value value;
    struct Parameter * next;
};

struct ParameterList
{
    char * value;
    struct ParameterList * next;
};

struct ParameterManager
{
    Parameter * hashTable[100];
};

ParameterManager * PM_create(int size);

int PM_destroy(ParameterManager *p);

int PM_parseFrom(ParameterManager * p, FILE * fp, char comment);

int PM_manage(ParameterManager *p, char *pname, param_t ptype, int required);

int PM_hasValue(ParameterManager *p, char *pname);

union param_value PM_getValue(ParameterManager *p, char *pname);

char * PL_next(ParameterList *l);

int hash(char *key);



