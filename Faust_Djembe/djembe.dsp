declare filename "djembe.dsp";
declare name "djembe";
import("stdfaust.lib");

gain = 0.7; 
trigger = (ba.pulsen (1, 10000));
freq = 55 + 440 * (no.noise : abs : ba.sAndH(trigger));
strikePosition = 0.5;
strikeSharpness = 0.5;

A = pm.djembe(freq,strikePosition,strikeSharpness,gain,trigger);

process = A <:_ , _;