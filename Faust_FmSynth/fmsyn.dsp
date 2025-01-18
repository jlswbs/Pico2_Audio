declare filename "fmsyn.dsp";
declare name "fmsyn";
import("stdfaust.lib");

gate = button("gate");
freq = hslider("freq", 440, 20, 4000, 1);
feed = hslider("feed", 0, 0, 1, 0.001);
shape = hslider("shape",1,0,4,0.01);
lfo = (hslider("lfo",0,0,2,0.01));
gain = hslider("gain", 0.5, 0, 1, 0.01);

envelop = en.adsre(0.1,0.5,0.5,0.5,gate);
FMdepth = envelop * 1000 * (1+lfo);
FMfeedback(frq) = (+(_,frq):os.osci) ~ (*((freq-1) * feed));

A = gain * (envelop * os.osci(freq + (FMdepth*FMfeedback(freq*shape))));
process = A <:_ , _;