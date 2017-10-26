#version 3.7;
#include "colors.inc"
#include "glass.inc"
#include "skies.inc"
#include "textures.inc"

global_settings {  assumed_gamma 1.0 
		   }
//---------------------------------------
camera{ right x*image_width/image_height
        location  <0 , 60 , -100>
        look_at   <0.0 , 80 , 0.0> }
//---------------------------------------
light_source{ <1500,2500,-2500>
              color rgb<1,1,1> }
//---------------------------------------
              
sky_sphere{S_Cloud1}
plane {y, 50
texture{pigment{rgb <.2,.2,.2>}
finish{ambient 0.15
       diffuse 0.3
       brilliance 6.0
       phong 0.8
       phong_size 120
       reflection 0.6
        }
    }
normal{ bumps 0.03
        scale <1, 0.25, 0.25>*1
        turbulence 0.6}
}
// fog ---------------------------------------------------------------
fog{fog_type   3   distance 250  color rgb<0.5,0.5,0.5>
    fog_offset 1 fog_alt  20.0 turbulence 0.5}

//--------------------------------------- 

#declare sp = torus{2, 1
    texture {Jade}
    finish { diffuse 1
             phong 1
             emission 0
             ambient 0.2
             reflection 0
             specular 1
             roughness 0.03
			  }
    }
    
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


merge{
sphere{<13, 122, 20>, 15
texture{Jade}
normal{crackle scale 1.7
turbulence 2.0}}    
sphere{<3, 132, 20>, 20
texture{Jade}
normal{crackle scale 1.7
turbulence 2.0}}    
object{tentacle translate <0, 10, 0>}
object{tentacle translate <5, 40, 0> scale 0.7}
object{tentacle translate <2, 40, 3> scale 0.8}
object{tentacle rotate<45, 0, 0> translate <2, 100, -30> scale 0.8}
object{tentacle rotate<0, 45, 0> translate <-8, -20, 16> scale 1.2}
}


