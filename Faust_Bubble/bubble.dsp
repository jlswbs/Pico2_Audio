declare filename "bubble.dsp";
declare name "bubble";
import("stdfaust.lib");

    shape = hslider("shape", 600, 150, 2000, 1);
    gain = hslider("gain",0.5,0,1,0.01);
    gate = button("gate");

bubble(f0,trig) = os.osc(f) * (exp(-damp*time) : si.smooth(0.99))
	with {
		damp = 0.043*f0 + 0.0014*f0^(3/2);
		f = f0*(1+sigma*time);
		sigma = eta * damp;
		eta = 0.075;
		time = 0 : (select2(trig>trig'):+(1)) ~ _ : ba.samp2sec;
	};

A = gain * bubble(shape, gate);

process = A <:_ , _;