/*
 *  Attribut.c
 *
 */

#include "Attribut.h"
#include <stdio.h>
#include "Table_des_symboles.h"
#define MAX 10

int regIdCounter = 0;

int newReg()
{
		regIdCounter ++;
		return regIdCounter;
}

int getCurrentReg()
{
	return regIdCounter;
}


char* getType(symb_type t)
{
  switch (t) {
    case 0: return "int";
    case 1: return "float";
  }
}

// return a bool for a comparaison
int comp(int g, int d, int op)
{
  bool a=false;
  switch(op)
  {
    case 0: //LT
      a = (g < d);
      break;
    case 1://GT
      a =  (g > d);
      break;
    case 2: //LEQ
      a =  (g <= d);
      break;
    case 3: //GEQ
      a =  (g >= d);
      break;
    case 4: // EQ
      a =  (g == d);
      break;
  }
  return a;
}

int branch(int b, int t, int e)
{
  if (b==0)
  {
    return e;
  }
  return t;
}

void affecter(symb_value_type id, symb_value_type value)
{

  if(value.reg == 0)
  {
    fprintf(test_c, "%s = %d;\n", id.sid , value.value);
    fprintf(test_c, "r%d = %s; \n",id.reg, id.sid );
  }
  else
    fprintf(test_c, "%s = r%d;\n", id.sid , value.reg);


}

void effectuerPlus(symb_value_type un, symb_value_type trois)
{
  if( un.reg == 0 && trois.reg == 0)
  {
    fprintf(test_c, "%d + %d;\n", un.value , trois.value);
  }
  else if (un.reg != 0 && trois.reg == 0)
  {
    fprintf(test_c, "r%d + %d;\n", un.reg , trois.value);
  }
  else if (un.reg == 0 && trois.reg != 0)
  {
    fprintf(test_c, "%d + r%d;\n", un.value , trois.reg);
  }
  else
  if(un.reg != 0 && trois.usereg != 0 )
  {
    fprintf(test_c, "r%d + r%d;\n", un.reg , trois.reg);
  }

}
