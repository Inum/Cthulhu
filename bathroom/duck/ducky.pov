// ========================================
// Rubber ducky
// -----------------------------------------
// Made for Persistence of vision 3.6
//==========================================  
// Copyright 2007 Gilles Tran http://www.oyonale.com
// -----------------------------------------
// This work is licensed under the Creative Commons Attribution License. 
// To view a copy of this license, visit http://creativecommons.org/licenses/by/3.0/ 
// or send a letter to Creative Commons, 559 Nathan Abbott Way, Stanford, California 94305, USA.
// You are free:
// - to copy, distribute, display, and perform the work
// - to make derivative works
// - to make commercial use of the work
// Under the following conditions:
// - Attribution. You must give the original author credit.
// - For any reuse or distribution, you must make clear to others the license terms of this work.
// - Any of these conditions can be waived if you get permission from the copyright holder.
// Your fair use and other rights are in no way affected by the above. 
//========================================== 
// Render with +W800 +H600
// no antialiasing needed if the focal blur is turned on
#version 3.6;
 
#include "colors.inc"
#include "functions.inc"
#include "transforms.inc"


#declare PlaneOK= 0;
#declare FocalBlurOK=1;
#declare RadOK=1; // no radiosity
#declare AreaOK=0;
global_settings {
    assumed_gamma 1 // adapt is image is too light or too dark (see your display_gamma)
    max_trace_level 30
    #if (RadOK>0)
        radiosity{
            count 200 
            error_bound 1
            recursion_limit 1    // CHANGE
            low_error_factor 1  // leave this
            gray_threshold 0   // leave this
            minimum_reuse 0.015  // leave this
            brightness 0.5         // leave this
            adc_bailout 0.01/2   // CHANGE - use adc_bailo        
            normal on
        }
    #end
}

camera{
    location  <0,30, -100> // position of camera <X Y Z>
    direction 3.5*z            // which way are we looking <X Y Z> & zoom
    up        y                // which way is +up <X Y Z>
    right     image_width/image_height*x            // which way is +right <X Y Z> and aspect ratio
    look_at   0 // point center of view at this point <X Y Z>
    #if (FocalBlurOK=1)
            aperture 2           // [0...N] larger is narrower depth of field (blurrier)
            blur_samples 200        // number of rays per pixel for sampling
            focal_point <0,0,0>    // point that is in focus <X,Y,Z>
            confidence 0.95           // [0...<1] when to move on while sampling (smaller is less accurate)
            variance 1/200            // [0...1] how precise to calculate (smaller is more accurate)
    #end

}


light_source {
    -z*1000
    color rgb <255,230,200>*2/255
    #if (AreaOK=1)
        area_light 5*z,5*y, 5,5 adaptive 1 jitter orient circular
    #end
    rotate x*30
    rotate y*140
}
sphere{
    0,2000
    texture{
        pigment{image_map{jpeg "sky" map_type 1}}
        finish{ambient 2 diffuse 0}
    }
    no_shadow
}

// 
// -----------------------------------------
// Water
// -----------------------------------------
#declare Resolution=2000;
#declare M_Water =material {
            texture{
                pigment{rgbf <0.8,0.9,1,0.95>}
                finish {
                    phong 1
                    phong_size 100
                    specular 1//2
                    roughness 0.0005
                    ambient 0
                    diffuse 0.1      
                    reflection {0.3,1 fresnel on}
                    conserve_energy
                }
            }
            interior {
                ior 1.32
            }
        }

#declare Water=height_field{
    function Resolution,Resolution {
        f_noise3d(x*40,y*40,z)
    }
    translate -x*0.5-z*0.5 
    scale <300,2,300> translate -y*2.5
    material{M_Water}
}


// -----------------------------------------
// Ducky
// -----------------------------------------
#declare F_Plastic=finish{ambient 0 diffuse 1 phong 1} // reflection{0,0.1 fresnel}}
#declare T_Bill=texture{pigment{Red} finish{F_Plastic}}
#declare T_Eye=texture{pigment{White} finish{F_Plastic}}
#declare T_Body=texture{pigment{rgb <0.8,0.75,0>} finish{F_Plastic}}
#declare T_Pupil=texture{pigment{Black} finish{F_Plastic}}

#include "ducky.inc"

#declare Duck=union{
    object{Ducky}
    object{Ducky scale <-1,1,1>} 
//    interior{ior 5}
    rotate y*180
    scale 1/40
    translate -y*0.5
}    

//#declare Ducky=cylinder{0,5*y,0.3 pigment{Red}}
#declare rd=seed(416889);
#declare i=-100;
#while (i<100)
    #declare j=-100;
    #while (j<100)
        #declare posX=i+(-1+2*rand(rd))*2;
        #declare posZ=j+(-1+2*rand(rd))*2;
        #declare Norm = <0, 0, 0>; 
        #declare Start = <posX,100,posZ>; 
        #declare Inter=trace (Water, Start, -y, Norm ); 
        #if (vlength(Norm)!=0) 
            object { 
                    Ducky 
                    rotate y*360*rand(rd)
                    Reorient_Trans(y, Norm)
                    translate Inter
            } 
         #end



//        object{Ducky rotate x*(-10+20*rand(rd)) rotate z*(-10+20*rand(rd)) rotate y*360*rand(rd) translate <posX,posY,posZ>}
        #declare j=j+10;
    #end
    #declare i=i+10;
#end

object{Water}
plane{y,-100 texture{pigment{Black} finish{specular 0}}}
