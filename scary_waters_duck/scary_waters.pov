#version 3.7;
#include "colors.inc"
#include "glass.inc"
#include "skies.inc"
#include "textures.inc"
// duck model originally taken from: http://www.oyonale.com/modeles.php?lang=en&page=53
//#include "duck/duck.inc"
#include "rubberduck.inc"

global_settings {  assumed_gamma 1.0 
		   }
//---------------------------------------
// Scaled clock step to allow full animation circles of 2*pi
#local step=2 * pi * clock / final_clock;

// Camera 
#declare Cam0 = camera{ angle 65
                        location <-0.5, 1.0, -2>
                        look_at <0.0, 0.0, 0.0> 
                        rotate <0,clock*360,0>} //end

#declare Cam1 = camera{ angle 65
                        location <-2, 2, -1>
                        look_at <0.0, 0.0, 0.0> } //end
//camera{Cam0}

// the rotating camera: ----------
#declare CamR = camera{ 
  angle    35
  location <-0.75, 1, -4.75>                       
  right    x*image_width/image_height
  look_at <0 , 1, 0>
 }
//---------------------- end of camera 
camera{CamR
        rotate   <0,-360*(clock+0.10),0>}

//---------------------------------------
light_source{ <1500,2500,-2500>
              color rgb<1,1,1> }
//---------------------------------------
              
sky_sphere{S_Cloud1}
//Water

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
}
// fog ---------------------------------------------------------------
fog{fog_type   3   distance 250  color rgb<0.5,0.5,0.5>
    fog_offset 1 fog_alt  20.0 turbulence 0.5}

//--------------------------------------- 

// ------- DUCK 
// TODO: (optional) Extract normal function of iso surface to use for duck floating animation
//object{ Duck 
  //      scale 0.05 
    //    rotate< 5*sin(step), -60, 5*cos(step)> 
      //  translate <0, 0.08+0.01*cos(step), 0> } // end
      object {duck 
       scale 0.05
        rotate< 5*sin(step), -60, 5*cos(step)> 
        translate <0.08+0.01*cos(step), 0, 0> }


