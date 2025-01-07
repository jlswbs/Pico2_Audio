declare filename "marimba.dsp";
declare name "marimba";
import("stdfaust.lib");

freq = hslider("freq", 440, 20, 2000, 0.01);
gain = hslider("gain", 0.5, 0, 1, 0.001);
gate = button("gate");

operator(f, a, d, s, r, amp) =  os.oscp(f) * en.adsre(a,d,s,r,gate) * amp;
freqMod = en.adsre(0.001, 0.005, 0, 0.005, gate);

A = no.pink_noise : operator( (freq*2.34)+(freqMod*4000), 0.001, 0.07, 0, 0.07, 2.5) * gain : pm.djembeModel(freq*2) * 0.08;

process = A <:_ , _;