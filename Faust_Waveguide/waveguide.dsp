declare filename "waveguide.dsp";
declare name "waveguide";
// waveguide_string.dsp
//
// waveguide model of a string 
//
// - one-pole lowpass termination
//
// Henrik von Coler
// 2020-06-09

import("all.lib"); 

// use '(pm.)l2s' to calculate number of samples
// from length in meters:

segment(maxLength,length) = waveguide(nMax,n)
with{
    nMax = maxLength : l2s;
    n = length : l2s/2;
};



// one lowpass terminator 
fc = hslider("lowpass",1000,10,10000,1);
rt = rTermination(basicBlock,*(-1) : si.smooth(1.0-2*(fc/ma.SR)));

// one gain terminator with control
gain = hslider("gain",0.99,0,1,0.01);
lt = lTermination(*(-1)* gain,basicBlock);


idString(length,pos,excite) = endChain(wg)
with{

    nUp   = length*pos;  
    nDown = length*(1-pos);  

    wg = chain(lt : segment(6,nUp) : in(excite) : out : segment(6,nDown) : rt); // waveguide chain
};

exc = select2(gain>0.9,1,0);

length = hslider("length",1,0.1,10,0.01):si.smoo;

process = idString(length,0.15, button("trigger")) <: _,_;