
/******************************************************************************
  Project #4 skeleton
  Author James Mithcell
  Section 1 
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal Init, Clock, w, x, y, z;

  // Insert your Pulsers here
  // A pulser is used to generate a temporary value of "One" on a specified
  // signal line (signal value:  Zero ==> One ==> Zero)
  Pulser ((SD("ba"), "i -- Init"),  Init, 'i', 10000);
  Pulser ((SD("ca"), "c -- Clock"), Clock, 'c', 10000);

  circuits( SD("bb-cb"), Init, Clock, w, x, y, z);

  // Insert your Probes here
  Probe ((SD("bh"), "w"), w);
  Probe ((SD("ch"), "x"), x);
  Probe ((SD("dh"), "y"), y);
  Probe ((SD("eh"), "z"), z);
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits
******************************************************************************/

void circuits( SD sd, Signal Init, Signal Clock, 
  Signal w, Signal x, Signal y, Signal z )
{
  Module( (sd, "circuits"), (Init, Clock), (w, x, y, z) );

  // Insert your declarations for any auxiliary Signals here
  Signal notw, notx, noty, notz, wand1, wand2, wand3, xand1, xand2, xand3, yand1, yand2, yand3, zand1, zand2, zand3, W, X, Y, Z;
  
  // Insert your DFFs here
  Dff ((SD("eb"), "Dff3"), (Init, W, Clock, Zero), w);
  Dff ((SD("fb"), "Dff2"), (Zero, X, Clock, Init), x);
  Dff ((SD("gb"), "Dff1"), (Init, Y, Clock, Zero), y);
  Dff ((SD("hb"), "Dff0"), (Zero, Z, Clock, Init), z);

  // Insert your combinational logic here (Not, And, Or gates)
  Not ( SD(sd, "1a"), w, notw);
  Not ( SD(sd, "2a"), x, notx);
  Not ( SD(sd, "3a"), y, noty);
  Not ( SD(sd, "4a"), z, notz);
  
  And ( SD(sd, "2d"), (w, notx, noty, notz), wand1); // For W()
  And ( SD(sd, "2d"), (w, notx, noty, z), wand2);
  And ( SD(sd, "2d"), (w, notx, y, notz), wand3);
  Or ( SD(sd, "2d"), (wand1, wand2, wand3), W);
  
  And ( SD(sd, "2d"), (notw, x, noty, notz), xand1); // For X()
  And ( SD(sd, "2d"), (notw, x, noty, z), xand2);
  And ( SD(sd, "2d"), (notw, x, y, notz), xand3);
  Or ( SD(sd, "2d"), (xand1, xand2, xand3), X);
  
  And ( SD(sd, "2d"), (notw, notx, y, notz), yand1); // For Y()
  And ( SD(sd, "1c"), (notw, x, y, notz), yand2);
  And ( SD(sd, "2c"), (w, notx, y, notz), yand3);
  Or ( SD(sd, "2d"), (yand1, yand2, yand3), Y);
  
  And ( SD(sd, "2d"), (notw, x, noty, z), zand1); // For Z()
  And ( SD(sd, "1c"), (w, notx, noty, z), zand2);
  Or ( SD(sd, "2d"), (zand1, zand2), Z);
  
}

