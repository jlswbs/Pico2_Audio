declare filename "djembe.dsp";
declare name "djembe";
import("stdfaust.lib");

    freq = hslider("freq",440.0,0,880,1);
    position = hslider("position" ,0.5,0,1,0.01);
    sharpness = hslider("sharpness" ,0.5,0,1,0.01);
    gain = hslider("gain",0.5,0,1,0.01);
    gate = button("gate");

A = pm.djembe(freq, position, sharpness, gain, gate);

process = A <:_ , _;