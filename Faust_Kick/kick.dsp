declare filename "kick.dsp";
declare name "kick";
import("stdfaust.lib");

freq = hslider("freq", 55, 20, 1000, 0.01);
gate = button("gate");
gain = hslider("gain", 0.5, 0, 1, 0.001);

freqDepth = hslider("depth", 12, 0, 24, 0.1);

attF = hslider("attf", 0.001, 0.001, 1, 0.001);
decF = hslider("decf", 0.1, 0.001, 1, 0.001);

att = hslider("att", 0.001, 0.001, 1, 0.001);
dec = hslider("dec", 0.5, 0.001, 5, 0.001);

freqEnv(d) = en.adsre(attF, decF, 0, decF, gate) * d;
ampEnv = _, en.adsre(att, dec, 0, dec, gate) : *;

freqModder = ba.midikey2hz( ba.hz2midikey( freq ) + freqEnv(freqDepth));

A = os.oscp( freqModder, 0 ) : gain * ampEnv;

process = A <:_ , _;