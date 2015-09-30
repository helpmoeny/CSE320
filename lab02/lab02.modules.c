
/******************************************************************************
  Implements the Boolean function F = ab' + bc'd'

  Uses a two-level hierarchy (function "simnet" calls function "circuit")
******************************************************************************/

#include <Sim.h>

void circuit( SD, Signal, Signal, Signal, Signal, Signal );

/******************************************************************************
  Function "simnet" -- test bed for circuit
******************************************************************************/

void simnet()
{
  Signal a, b, c, d, F;                   // Switch and output objects 

  Switch ( SD("1a"), a, 'a' );            // Switch a controlled by 'a' key
  Switch ( SD("2a"), b, 'b' );            // Switch b controlled by 'b' key
  Switch ( SD("3a"), c, 'c' );            // Switch c controlled by 'c' key
  Switch ( SD("4a"), d, 'd' );            // Switch d controlled by 'd' key
 
  circuit( SD("1c-4c"), a, b, c, d, F );

  Probe ( (SD("2e"), "F"), F );           // Probe
}


/******************************************************************************
  Function "circuit" -- implementation of function F
******************************************************************************/

void circuit( SD sd, Signal a, Signal b, Signal c, Signal d, Signal F )
{
  Module( (sd, "circuit"), (a, b, c, d), (F) );
 
  Signal notb, notc, notd;
  Signal and1, and2;                      // Intermediate objects 
 
  Not ( SD(sd,"2a"), b, notb );           // NOT gates
  Not ( SD(sd,"3a"), c, notc );
  Not ( SD(sd,"4a"), d, notd );
 
  And ( SD(sd,"2c"), (a, notb), and1 );   // AND gates                                     
  And ( SD(sd,"3c"), (b, notc, notd), and2 );    
 
  Or ( SD(sd,"2e"), (and1, and2), F );    // OR gate
}

