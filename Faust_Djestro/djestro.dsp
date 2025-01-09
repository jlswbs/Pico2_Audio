declare filename "djestro.dsp";
declare name "djestro";
import("stdfaust.lib");

    freq = hslider("freq",0.5,0,1,0.01);
    damp = hslider("damp" ,0.01,0,1,0.01);
    gain = hslider("gain",0.5,0,1,0.01);
    gate = button("gate");

A = gate : (ba.impulsify * gain : 0.5 * pm.ks(freq, damp)) + (0.5 * pm.djembe(880*freq, 0.5, 0.5, gain, gate));

process = A <:_ , _;