
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
  Pulser ((SD("ba"), "v -- Init"),  ResetA, 'v', 10001);
  Pulser ((SD("ca"), "c -- Clock"), clock_Strobe, 'c', 10000);

  circuits( SD("1b-4b"), Init, Clock, w, x, y, z );

  // Insert your Probes here
  Probe ((SD("bh"), "w"), w_probe);
  Probe ((SD("ch"), "x"), x_probe);
  Probe ((SD("dh"), "y"), y_probe);
  Probe ((SD("eh"), "z"), z_probe);
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits
******************************************************************************/

void circuits( SD sd, Signal Init, Signal Clock, 
  Signal w, Signal x, Signal y, Signal z )
{
  Module( (sd, "circuits"), (Init, Clock), (w, x, y, z) );

  // Insert your declarations for any auxiliary Signals here

  // Insert your DFFs here

  // Insert your combinational logic here (Not, And, Or gates)
}

