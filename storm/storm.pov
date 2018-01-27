#version 3.7;
#include "colors.inc"
#include "glass.inc"
#include "skies.inc"
#include "textures.inc"
// duck model originally taken from: http://www.oyonale.com/modeles.php?lang=en&page=53
//#include "duck/duck.inc"
#include "rubberduck.inc"

global_settings{ assumed_gamma 1.0 }
//---------------------------------------
// Scaled clock step to allow full animation circles of 2*pi
#local progress=clock/final_clock;
#local step=2 * pi * progress;

// Camera 
#declare Cam0 = camera{ angle 65
                        location <0.1, 0.1, -5>
                        look_at <0.0, 0.0, 0.0>} //end

#declare cam_r=function(v, frac){v * (frac * (1 - progress)+ 1 - frac)}

#declare Cam1 = camera{ angle 65
                        location <sin(progress) * cam_r(5,0.6), 5 - 2 * (final_clock - clock) / final_clock, -cos(progress) * cam_r(5, 0.6)>
                        look_at <0.0, -1, 0.0> } //end
//camera{Cam0}

// the rotating camera: ----------
#declare CamR = camera{ 
  angle    35
  location <-0.75, 1, -4.75>                       
  right    x*image_width/image_height
  look_at <0 , 1, 0>
 }
//---------------------- end of camera 
camera{Cam1}

//---------------------------------------
light_source{ <1500,2500,-2500>
              color rgb<1,1,1> }

//---------------------------------------
#local render_water=1;
              
sky_sphere{S_Cloud4 rotate <clock*0.1,0,0>}
//Water
#declare s=function(x,y){3/(x*x+y*y+.5)}
#declare g=function{pattern{granite scale 6-y*2}}
#declare f=function(x,y,z,a,b){pow(g(x*a+z*b,y+clock*3,x*b-z*a),.6)}
#declare h=function(x,y,z,a){f(x,y,z,sin(a),cos(a))}
difference {
    plane {y, 0 
        texture{pigment{rgb<.5,.8,.7>}finish{diffuse .3 phong 1 specular .5 reflection {.2, .75 fresnel}}
            #if (render_water)
                normal{function{h(x,y,z,s(x,z))}-1.5}
            #end
        }
        //texture {pigment {rgbf <0.92,0.99,0.96,0.45>}
        //    finish {diffuse 0.1 
        //        reflection 0.5 
        //        specular 0.8 
        //        roughness 0.0003 
        //        phong 1 
        //        phong_size 400 }}
        //        normal {bumps phase clock 
        //            turbulence 0.1}
                }
                cylinder {<0,-4,0>, <0,0.1,0>, 4}
    }

    lathe{bezier_spline 4<0,-2>0 1<4,2>
        texture{pigment{rgb<.5,.8,.7>}finish{diffuse .3 phong 1 specular .5 reflection {.2, .75 fresnel}}

            #if (render_water)
                normal{function{h(x,y,z,s(x,z))}-1.5}
            #end
        }
        no_shadow
        translate <0,-2,0>}

// fog ---------------------------------------------------------------

#if (1)
  fog{distance 100 color rgbt<0.4,0.4,0.5,0.5>
    fog_offset 0.0 fog_alt 1 turbulence 0.05}
#end

//--------------------------------------- 
#local duck_gone_clock=final_clock*0.8;

#declare r=function(v){v - v * clock / duck_gone_clock}

// ------- DUCK 
// TODO: (optional) Extract normal function of iso surface to use for duck floating animation
//object{ Duck 
//      scale 0.05 
//    rotate< 5*sin(step), -60, 5*cos(step)> 
//  translate <0, 0.08+0.01*cos(step), 0> } // end
object {duck 
 scale 0.05
 //translate <-cos(clock) * r(4), - 2 * clock / final_clock, sin(clock) * r(4)>
 rotate< sin(clock), -progress * progress * 3000, cos(clock)>
 translate <-cos(clock) * r(3.5), - 2.1 * clock / duck_gone_clock, sin(clock) * r(3.5)>
 #if (clock > duck_gone_clock)
     translate <0, - 2.1 - (clock-duck_gone_clock) * 0.01, 0>
 #end
 no_shadow

}

    /*
//Tentacle
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
    
object{tentacle
scale 0.05
        translate <0.08+0.01*cos(step), 0, 0> }

    */
