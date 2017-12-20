#version 3.7;
#include "colors.inc"
#include "glass.inc"
#include "skies.inc"
#include "textures.inc"
#include "rubberduck.inc"


global_settings {  assumed_gamma 1.0 
		   }
// above=+1 or below=-1 water surface
#declare ViewPoint= -1;
#local step=2 * pi * clock / final_clock;
    

// water
fog {fog_type 2 distance 10 color rgb<.47,.79,.79>//<.33,.67,.95>
     fog_offset -9 // drop fog under plane
     fog_alt 4.5 // vertical murkiness
}



// water surface
plane {y, -0.01
texture{pigment{ rgbf <0.92,0.99,0.96,0.45>}
finish{ diffuse 0.1 reflection 0.5 specular 0.8 
        roughness 0.0003 phong 1 phong_size 400 
        }
    }
normal{ bumps 
        phase clock
        turbulence 0.1
        scale 1.0 + 0.1*sin(step)}
inverse
}


// sea bed
plane {y,-9 pigment {rgb<0, 0, 0>}//<1,.75,.5>}
 normal {wrinkles .5 scale 3}
  finish {diffuse .75 specular .1 roughness .1}}


// sky
sky_sphere{S_Cloud1}


// sunlight
light_source {<100,1000,1000>, 1.5}
// bright daylight
light_source {<-100,1000,-1000>, <.33,.5,.6> shadowless}

camera {location <0,-2.5,-5 + clock*0.5> look_at <0,0,0>}

#declare pt = 0;
#declare r = 0;

#declare tentacle = sphere_sweep{
cubic_spline
14, 
 #while(pt<14)
 <5*cos(pt+clock)+5*5*cos(pt*0.1), pt*10, 5*sin(pt+clock)+5*5*sin(pt*0.1)>, r
 #declare r = r+0.2;
 #declare pt = pt+1;
 #end
   texture{Jade}
   normal{bumps 0.3}
    }


    
object {duck 
        scale 0.09
        translate <0, 0, 0>
        rotate<0, 0, 0> 
        translate <0, 0, 0>
        rotate<5*sin(step), 0, 5*cos(step)> 
        translate <0.08+0.01*cos(step), 0.01, 0> }

merge{
object {tentacle translate <0, 0, 0> rotate <180, -10, -5> translate <-25, 10, 11> scale 0.3} // near
object {tentacle translate <0, 0, 0> rotate <180, 10, 5> translate <-36, 5, 17> scale 0.5} // near
object {tentacle translate <0, 0, 0> rotate <180, 15, 5> translate <-20, 2, 17> scale 0.08} // near
object {tentacle translate <0, 0, 0> rotate <180, 20, 5> translate <-25, 7, 17> scale 0.08} // near
object {tentacle translate <0, 0, 0> rotate <180, 25, 5> translate <-30, 1, 17> scale 0.08} // near
object {tentacle translate <0, 0, 0> rotate <180, -15, 0> translate <-33, 10, 19> scale 0.11} // near
object {tentacle translate <0, 0, 0> rotate <180, -10, 0> translate <-20, 0, 10> scale 0.07} // near
translate<0, -5 + clock, 0>}