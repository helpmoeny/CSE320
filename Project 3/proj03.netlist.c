
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
  Signal w, x, y, z, Present, a, b, c, d, e, f, g;//Initializing,declaring
  // Code to generate four input signals
  Signal Strobe (1);   // Counter strobe input
  Signal ResetA (1);   // Counter reset signal (before complemented)
  Signal ResetB (1);   // Counter reset signal (after complemented)
  
  //These are used only for testing
  /* Switch ( SD("bb"), w, 'w' );            // Switch w controlled by 'w' key
  Switch ( SD("cb"), x, 'x' );            // Switch x controlled by 'x' key
  Switch ( SD("db"), y, 'y' );            // Switch y controlled by 'y' key
  Switch ( SD("eb"), z, 'z' ); */            // Switch z controlled by 'z' key
  
  Counter ((SD("da-ea"), "4-bit counter"), (ResetB, Strobe), (z,y,x,w));
  circuits( SD("ac-zf"), w, x, y, z, Present, a, b, c, d, e, f, g);
  
  // A pulser is used to generate a temporary value of "One" on a specified
  // signal line (signal value:  Zero ==> One ==> Zero)
  Pulser ((SD("ba"), "r -- Reset counter"),  ResetA, 'r', 10001);
  Pulser ((SD("ca"), "s -- Strobe counter"), Strobe, 's', 10000);
  
  // Complement the reset signal (counter reset is active low)
  Not (SD("ab"), ResetA, ResetB);
  
  // Code to display eight output signals
  Probe ((SD("ah"), "Present"), Present);
  Probe ((SD("bh"), "a()"), a);
  Probe ((SD("ci"), "b()"), b);
  Probe ((SD("ei"), "c()"), c);
  Probe ((SD("fh"), "d()"), d);
  Probe ((SD("eg"), "e()"), e);
  Probe ((SD("cg"), "f()"), f);
  Probe ((SD("dh"), "g()"), g);
  
  
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
  Signal and1, and2, and3, and4, and5, and6, and7, and8, and9, and10, and11, and12, and13, and14, and15, and16, and17, and18, and19, and20, and21, and22, and23, and24, and25, and26, and27, and28, and29, and30, and31, and32, and33, and34, and35, and36, and37, and38, and39, and40;// Intermediate objects
  Signal or1, or2, or3, or4, or5, or6, or7, or8, or9, or10, or11, or12, or13, or14, or15, or16, or17, or18, or19, or20, or21, or22, or23, or24;
  

  // Circuit implementation (Not, And, Or gates)
  Not ( SD("bc"), w, notw );// NOT gates
  Not ( SD("cc"), x, notx );
  Not ( SD("dc"), y, noty );
  Not ( SD("ec"), z, notz );
  

  // Circuit implementation (Not, And, Or gates)
  //Implementation for component p()
  Or ( SD("ah"), (w, x, y, z), Present );//Present is light for everything other than Zero
  
  //Implementation for component a()
  And( SD("bd"), (notz, x), and5);
  And( SD("be"), (y, x), and6);
  And( SD("cd"), (z, notw), and7);
  And( SD("ce"), (noty, notw), and8);
  And( SD("dd"), (z, noty, notx), and9);
  And( SD("de"), (notz, y, w), and10);
  Or ( SD("bf"), (and5, and6), or4 );
  Or ( SD("cf"), (and7, and8), or5 );
  Or ( SD("df"), (and9, and10), or6 );
  Or ( SD("ef"), (or4, or5), or7 );
  Or ( SD("ff"), (or7, or6), a );
  
  //Implementation for component b()
  And( SD("ed"), (noty, notw), and11);
  And( SD("ee"), (notz, x, w), and12);
  And( SD("fd"), (z, notx, w), and13);
  And( SD("fe"), (notz, notx, notw), and14);
  And( SD("ge"), (noty, notx), and15);
  Or ( SD("gf"), (and11, and12), or8 );
  Or ( SD("hf"), (or8, and13), or9 );
  Or ( SD("if"), (or9, and14), or10 );
  Or ( SD("jf"), (or10, and15), b );
  
  //Implementation for component c()
  And( SD("gd"), (notz, y), and16);
  And( SD("he"), (z, noty), and17);
  And( SD("hd"), (notx, w), and18);
  And( SD("ie"), (noty, notx), and19);
  And( SD("id"), (noty, w), and20);
  Or ( SD("kf"), (and16, and17), or11 );
  Or ( SD("lf"), (or11, and18), or12 );
  Or ( SD("mf"), (or12, and19), or13 );
  Or ( SD("nf"), (or13, and20), c );
  
  //Implementation for component d
  And( SD("jd"), (y, notx, w), and21);
  And( SD("je"), (z, notx), and22);
  And( SD("kd"), (noty, x, w), and23);
  And( SD("ke"), (notz, noty, notw), and24);
  And( SD("ld"), (y, x, notw), and25);
  Or ( SD("of"), (and21, and22), or14 );
  Or ( SD("pf"), (or14, and23), or15 );
  Or ( SD("qf"), (or15, and24), or16 );
  Or ( SD("rf"), (or16, and25), d );
  
  //Implementation for component e
  And( SD("ld"), (z, y), and26);
  And( SD("me"), (z, x), and27);
  And( SD("md"), (noty, notw), and28);
  And( SD("ne"), (x, notw), and29);
  Or ( SD("sf"), (and26, and27), or17 );
  Or ( SD("tf"), (or17, and28), or18 );
  Or ( SD("uf"), (or18, and29), e );
  
  //Implementation for component f
  And( SD("nd"), (z, noty), and30);
  And( SD("oe"), (z, x), and31);
  And( SD("od"), (y, notw), and32);
  And( SD("pe"), (notx, notw), and33);
  And( SD("pe"), (notz, y, notx), and34);
  Or ( SD("vf"), (and30, and31), or19 );
  Or ( SD("wf"), (or19, and32), or20 );
  Or ( SD("xf"), (or20, and33), or21 );
  Or ( SD("yf"), (or21, and34), f );
  
  //Implementation for component g
  And( SD("qd"), (z, noty), and35);
  And( SD("qe"), (noty, x), and36);
  And( SD("rd"), (z, x), and37);
  And( SD("re"), (y, notx, w), and38);
  And( SD("se"), (notz, y, notw), and39);
  Or ( SD("zf"), (and35, and36), or22 );
  Or ( SD("xf"), (or22, and37), or23 );
  Or ( SD("yf"), (or23, and38), or24 );
  Or ( SD("zf"), (or24, and39), g );
}
