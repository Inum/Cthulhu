#version 3.7;
#include "colors.inc"
#include "glass.inc"
#include "skies.inc"
#include "textures.inc"
#include "duck/duck.inc"

//human model
#include "bmpeople.inc"


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

camera {location <0 - clock*0.005,-0.5, 1 - clock*0.005> look_at <-0.22,-0.5+0.007*clock,0.31>}

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


    
object{ Duck 
        scale 0.05 
        rotate< 0, -60, 0> 
        translate <-0.22, -0.5+0.009*clock, 0.31> } // end
        
//cthulhu

#declare pt = 0;
#declare r = 0;

#declare tentacle = sphere_sweep{
cubic_spline
15, 
 #while(pt<14)
 <5*cos(pt)+5*5*cos(pt*0.1), pt*10, 5*sin(pt)+5*5*sin(pt*0.1)>, r
 #declare r = r+0.2;
 #declare pt = pt+1;
 #end
 <5*cos(15)+5*5*cos(15*0.1), 15*10, 5*sin(15)+5*5*sin(1.5)>, 1.5
   texture{Jade}
   normal{bumps 0.3}
    }


    
#declare head = merge{
sphere{<10.5, 152, 25>, 7.5
texture{Jade}
normal{crackle scale 1.7
turbulence 2.0}}   
sphere{<5.5, 136, 25>, 12
texture{Jade}
normal{crackle scale 1.7
turbulence 2.0}}    
object{tentacle translate <2, 8, 0>}
object{tentacle translate <4, 30, 0> scale 0.7}
object{tentacle translate <2, 30, 3> scale 0.8}
object{tentacle translate <6, 30, -4> scale 0.8}
object{tentacle translate <1, -20, -3> scale 1.2}
}

#declare eyes = merge{
sphere{<0, 112, 0>, 7
texture { pigment{ rgb<0,0,0>}}
	finish {diffuse 0.9
                           phong 1
			   emission 0	
			   ambient 0.3
			   reflection .1
			   specular 1.7
			   roughness 0.01
			  }
}
sphere{<15, 112, 0>, 7
texture { pigment{ rgb<0,0,0>}}
	finish {diffuse 0.9
                           phong 1
			   emission 0	
			   ambient 0.3
			   reflection .1
			   specular 1.7
			   roughness 0.01
			  }
}}


#declare BM_Skin_Tex= texture{Jade}
#declare BM_RA_E2W = <40+clock*0.8,0,0>;      
#declare BM_RH_Rot = <0, 90, 0>;
#declare BM_RFP_Pos = <5+clock,45+clock,5+clock,0>;   //Pinky   
#declare BM_RFR_Pos = <10+clock,30+clock,5+clock,0>;  //Ring 
#declare BM_RFM_Pos = <5+clock,15+clock,5+clock,0>;   //Middle
#declare BM_RFI_Pos = <0+clock,10+clock,0+clock,0>;   //Index
#declare BM_RFT_Pos = <0+clock,-10+clock,5+clock,10>; //Thumb

Blob_Man(Male,80)
merge{
object{eyes scale 0.3
       translate <-2, 38, 1.5   >}
object{head scale 0.3
            translate <-15, -122, -15>
            rotate <0, 90, 0>
            translate <8, 150, -10>
            }

object {BlobMan 
   
        transform BMO_Foot_R
        translate y*-1.5
}
scale 0.04
translate <0, -2, 0.2>
rotate<0, 60, 0>}