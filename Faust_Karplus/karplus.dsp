declare filename "karplus.dsp";
declare name "karplus";
import("stdfaust.lib");

    freq = hslider("freq",1.0,0,3,0.01);
    gain = hslider("gain",0.5,0,1,0.01);
    damp = hslider("damp" ,0.01,0,1,0.01);
    gate = button("gate");

A = gate : pm.impulseExcitation * gain : pm.ks(freq , damp);

process = A <:_ , _;