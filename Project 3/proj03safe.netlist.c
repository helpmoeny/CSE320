
/******************************************************************************
  Project #3 Author: cse320
******************************************************************************/

#include <Sim.h>

void circuits( SD, Signal, Signal, Signal, Signal, 
  Signal, Signal, Signal, Signal, Signal, Signal, Signal, Signal );


/******************************************************************************
  Function "simnet"   -- test bed for student circuits
******************************************************************************/

void simnet()
{
  Signal w, x, y, z, Present, a, b, c, d, e, f, g;

  // Code to generate four input signals
  Signal Strobe (1);   // Counter strobe input
  Signal ResetA (1);   // Counter reset signal (before complemented)
  Signal ResetB (1);   // Counter reset signal (after complemented)
  Signal Output (1);   // Counter output
  Switch ( SD("1b"), w, 'w' );            // Switch w controlled by 'w' key
  Switch ( SD("2b"), x, 'x' );            // Switch x controlled by 'x' key
  Switch ( SD("3b"), y, 'y' );            // Switch y controlled by 'y' key
  Switch ( SD("4b"), z, 'z' );            // Switch z controlled by 'z' key
  
  
  /* //a()
  And( SD("0d"), (x,notz), and1);
  And( SD("1e"), (notx,noty,z), and2);
  And( SD("2d"), (notw,notx,noty), and3);
  And( SD("3e"), (w,y,notz), and4);
  Or ( SD("1f"), (and1, and2), or1 );
  Or ( SD("2f"), (and3, and4), or2 );
  Or ( SD("3f"), (or1, or2), or3 ); */
  
  
  /* // P() = w'xy' + w'yz' + wx'yz' + wx'y'
  And( SD("0d-21d"), (notw, x, noty), and1);
  And( SD("1e-21e"), (notw, y, notz), and2);
  And( SD("0d-21d"), (w, notx, y, notz), and3);
  And( SD("1e-21e"), (w, notx, noty), and4);
  Or ( SD("1f"), (and1, and2), or1 );
  Or ( SD("2f"), (or1, and3), or2 );
  Or ( SD("3f"), (or2, and4), or3 );
  
  // a() = wx'y' + w'xy'z + yz'
  And( SD("0d-21d"), (w, notx, noty), and5);
  And( SD("1e-21e"), (notw, x ,noty, z), and6);
  And( SD("0d-21d"), (y, notz), and7);
  Or ( SD("4f"), (and5, and6), or4 );
  Or ( SD("5f"), (or4, and7), or5 );
  
  // b() = wx'y' + w'xy'z' + x'yz'
  And( SD("1e-21e"), (w, notx, noty), and8);
  And( SD("0d-21d"), (notw, x, noty, notz), and9);
  And( SD("1e-21e"), (notx, y, notz), and10);
  Or ( SD("5f"), (and8, and9), or6 );
  Or ( SD("5f"), (or6, and10), or7 );
  
  //c() = wx' + w'x
  //f() = wx' + w'x
  And( SD("0d-21d"), (w,notx), and11);
  And( SD("1e-21e"), (notw,x), and12);
  Or ( SD("2f"), (and1, and2), or8 );
  
  //d() = wx'y' + w'yz' + w'xy'z
  And( SD("0d-21d"), (w, notx, noty), and13);
  And( SD("1e-21e"), (notw, y, notz), and14);
  And( SD("0d-21d"), (notw, x, noty, z), and15);
  Or ( SD("2f"), (and13, and14), or9 );
  Or ( SD("2f"), (or9, and15), or10 );
  
  //e() = wx'z' + yz'
  And( SD("1e-21e"), (w, notx, notz), and16);
  And( SD("0d-21d"), (y, notz), and17);
  Or ( SD("2f"), (and16, and17), or11 );
  
  //g() = w'xy' + wx'y' + yz'
  And( SD("1e-21e"), (notw, x, noty), and18);
  And( SD("0d-21d"), (w, notx, noty), and19);
  And( SD("1e-21e"), (y, notz), and20);
  Or ( SD("2f"), (and18, and19), or12 );
  Or ( SD("2f"), (or12, and20), or13 ); */
  
  circuits( SD("1d-4d"), w, x, y, z, Present, a, b, c, d, e, f, g);
  
  // A pulser is used to generate a temporary value of "One" on a specified
  // signal line (signal value:  Zero ==> One ==> Zero)

  Pulser ((SD("3a"), "r -- Reset counter"),  ResetA, 'r', 10000);
  Pulser ((SD("4a"), "s -- Strobe counter"), Strobe, 's', 10000);
  
  // Complement the reset signal (counter reset is active low)
  //Not (SD("3b"), ResetA, ResetB);
  
  //Counter ((SD("3a-4a"), "4-bit counter"), (ResetB, Strobe), Output);
  
  // Code to display eight output signals
  Probe ((SD("0h"), "Present"), Present);
  Probe ((SD("1h"), "a()"), a);
  Probe ((SD("2i"), "b()"), b);
  Probe ((SD("4i"), "c()"), c);
  Probe ((SD("5h"), "d()"), d);
  Probe ((SD("4g"), "e()"), e);
  Probe ((SD("2g"), "f()"), f);
  Probe ((SD("3h"), "g()"), g);
  
  
}


/******************************************************************************
  Function "circuits" -- implementation of student circuits

  Do not alter the interface -- function "circuits" must receive four
  signals as inputs and return eight signals as outputs.
******************************************************************************/

void circuits( SD sd, Signal w, Signal x, Signal y, Signal z, 
  Signal Present, Signal a, Signal b, Signal c, Signal d, Signal e,
  Signal f, Signal g )    
{
  Module( (sd, "circuits"), (w, x, y, z), (Present, a, b, c, d, e, f, g) );

  // Declarations for any auxiliary Signals
  Signal notw, notx, noty, notz;
  Signal and1, and2, and3, and4, and5, and6, and7, and8, and9, and10, and11, and12, and13, and14, and15, and16, and17, and18, and19, and20, and21, and22, and23, and24, and25, and26, and27, and28, and29, and30;// Intermediate objects
  Signal or1, or2, or3, or4, or5, or6, or7, or8, or9, or10, or11, or12, or13, or14, or15, or16, or17, or18, or19, or20, or21, or22, or23;
  

  // Circuit implementation (Not, And, Or gates)
  Not ( SD("1c"), w, notw );// NOT gates
  Not ( SD("2c"), x, notx );
  Not ( SD("3c"), y, noty );
  Not ( SD("4c"), z, notz );
  

  // Circuit implementation (Not, And, Or gates)
  //a()
  And( SD("0d"), (notz, x), and5);
  And( SD("1e"), (z, noty, notx), and6);
  And( SD("2d"), (notz, y, w), and7);
  And( SD("3e"), (noty, notx, notw), and8);
  Or ( SD("1f"), (and5, and6), or4 );
  Or ( SD("2f"), (or4, and6), or5 );
  Or ( SD("3f"), (or5, and7), or6 );
  Or ( SD("3f"), (or6, and8), a );
  
  //b()
  And( SD("0d"), (notz, noty), and9);
  And( SD("1e"), (noty, notx), and10);
  And( SD("2d"), (notz, y, w), and11);
  And( SD("3e"), (notz, notx, notw), and12);
  Or ( SD("1f"), (and9, and10), or8 );
  Or ( SD("2f"), (or8, and11), or9 );
  Or ( SD("3f"), (or9, and12), b );
  
  //c()
  And( SD("0d"), (notz, y), and13);
  And( SD("1e"), (noty, notx), and14);
  And( SD("2d"), (notz, w), and15);
  Or ( SD("1f"), (and13, and14), or11 );
  Or ( SD("2f"), (or11, and15), c );
  
  //d
  And( SD("0d"), (notz, noty, x), and16);
  And( SD("1e"), (z, noty, notx), and17);
  And( SD("2d"), (notz, x, notw), and18);
  And( SD("1e"), (notz, y, notx, w), and19);
  And( SD("2d"), (noty, notx, notw), and20);
  Or ( SD("1f"), (and16, and17), or13 );
  Or ( SD("2f"), (or13, and18), or14 );
  Or ( SD("3f"), (or14, and19), or15 );
  Or ( SD("3f"), (or15, and20), d );
  
  //e
  And( SD("0d"), (notz, x, notw), and21);
  And( SD("1e"), (noty, notx, notw), and22);
  Or ( SD("3f"), (and21, and22), e );
  
  //f
  And( SD("0d"), (notz, y, notx), and23);
  And( SD("1e"), (z, noty, notx), and24);
  And( SD("2d"), (notz, y, notw), and25);
  And( SD("1e"), (noty, notx, notw), and26);
  Or ( SD("2f"), (and23, and24), or18 );
  Or ( SD("3f"), (or18, and25), or19 );
  Or ( SD("3f"), (or19, and26), f );
  
  //g
  And( SD("0d"), (notz, noty, x), and27);
  And( SD("1e"), (notz, y, notx), and28);
  And( SD("2d"), (z, noty, notx), and29);
  And( SD("1e"), (notz, y, notw), and30);
  Or ( SD("2f"), (and27, and28), or21 );
  Or ( SD("3f"), (or21, and29), or22 );
  Or ( SD("3f"), (or22, and30), g );
}
