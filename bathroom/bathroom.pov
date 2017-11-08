// PoVRay 3.7 Scene File "tub.pov"
// author: Lars Henning Kayser, November-2017
// email: henningkayser@mail.de
// description: A simple animated bathroom scene with a duck floating in a tub.

// basic default includes
#include "functions.inc"
#include "math.inc"
#include "shapes.inc"
#include "shapes2.inc"
#include "transforms.inc"
#include "colors.inc"
#include "textures.inc"

// non-default shapes3
//http://www.f-lohmueller.de/pov_tut/all_shapes/shapes3_0000d.htm
#include "../include/shapes3.inc"

// duck model originally taken from: http://www.oyonale.com/modeles.php?lang=en&page=53
#include "duck/duck.inc"

// A bunch of included materials which might or might not be necessary
// (didn't have the patience to check which one caused)
#include "glass.inc"
#include "metals.inc"
#include "golds.inc"
#include "stones.inc"
#include "woods.inc"

// global settings
global_settings { assumed_gamma 1.0 }

// Scaled clock step to allow full animation circles of 2*pi
#local step=2 * pi * clock / final_clock;

// Camera 
#declare Cam0 = camera{ angle 65
                        location <-0.5, 1.0, -2>
                        look_at <0.0, 0.0, 0.0> } //end

#declare Cam1 = camera{ angle 65
                        location <-2, 2, -1>
                        look_at <0.0, 0.0, 0.0> } //end
camera{Cam0}



// #######################################################################################################
//   
// ROOM --------------------------------------------------------------------------------------------------
//
// #######################################################################################################

//TODO: Adjust sky and room lighting
// Sky 
sky_sphere { pigment { gradient <0,1,0>
                       color_map { [0.00 rgb <0.6,0.7,1.0>]
                                   [0.35 rgb <0.0,0.1,0.8>]
                                   [0.65 rgb <0.0,0.1,0.8>]
                                   [1.00 rgb <0.6,0.7,1.0>] } 
                       scale 2 } } // end

// ------- Light 
light_source{ <0, 2, -1.5> color White }


// ------- Floor
plane{<0,1,0>, -0.9
    texture{
        pigment{ checker
                 color White
                 color Black
                 scale 0.5 }
        normal{ bumps 0.3 scale 0.01 }
        finish{ diffuse 0.3 phong 1.0 } } } // end

// ------- Wall
difference{
    box{ <-2.6, -1.0, 1.1>, <3.1, 2.2, -4.1> } // outside
    box{ <-2.5, -1.0, 1.0>, <3.0, 2.1, -4.0> } // inside 
    // Wallpaper taken from https://www.tapeten-in-berlin.de/tapete/blumen/kaufen-blumen-tapeten-80.jpg
    // TODO: Changed to wallpaper with free license
    pigment{ image_map{ png "textures/wall.png" map_type 0 }
             scale <0.8,0.8,0.8>} } // end





// #######################################################################################################
//   
// TUB ---------------------------------------------------------------------------------------------------
//
// #######################################################################################################

// Variables copied from shapes3.inc to reuse for water simulation
#local D = 0.000001;
#local Len_total = 3.2; 
#local R_out = 0.9; 
#local R_Border = 0.1; 
#local R_in = R_out - R_Border ;
#local Len = Len_total-2*R_out; // length of linear kernel  
#local R_Border = (R_out-R_in)/2 ; // Radius of the upper borders

// ------ Tub
// Half_Hollowed_Rounded_Cylinder1 from http://www.f-lohmueller.de/pov_tut/all_shapes/shapes3_70e.htm
object{ Half_Hollowed_Rounded_Cylinder1(Len_total,R_out,R_Border,1,0)
        texture { 
            pigment{ color rgb<1,1,1> }
            finish { phong 0.1 } }
        scale <1,1,1>
        rotate <0,0,0>
        translate <0,0.1,0> } // end


// Shape of the inside of the tub which is used for contained water
#declare TUB_inside = difference{
                        merge{
                            cylinder { <-Len/2,0,0>,<Len/2,0,0>,R_in }
                            sphere   { <-Len/2,0,0>,R_in }
                            sphere   { < Len/2,0,0>,R_in } } } //end




// #######################################################################################################
//   
// WATER -------------------------------------------------------------------------------------------------
//
// #######################################################################################################
//
// Realistic water taken from http://www.f-lohmueller.de/pov_tut/backgrnd/p_wat6.htm

// ------- Water Material
#declare Water_Material = material{    
                            texture{ 
                              pigment{ rgbf <0.92,0.99,0.96,0.45> }
                              finish { diffuse 0.1 reflection 0.5  
                                       specular 0.8 roughness 0.0003 
                                       phong 1 phong_size 400 } } 
                            interior{ ior 1.3 caustics 0.15 } } // end

// ------- Pigment Pattern for Modulation
// TODO: Adjust type (optional), phase and scale for random waves
#declare Pigment_01 =  pigment{ bumps 
                                phase clock
                                turbulence 0.1
                                scale 1.0 + 0.1*sin(step) } // end


// ------- Pigment Function
#declare Pigment_Function_01 = function { pigment { Pigment_01 } } // end 

// ------- Water Model
// Isosurfaces only support primitive shapes (box, sphere).
// To model the irregular tub shape we create a box isosurface and compute the
// intersection with the inside of the tub.
// This is quite costly but works however.
intersection{ 
    // Inside of the tub scaled slightly larger to avoid artifacts at the border
    object{ TUB_inside scale 1.05 }
    isosurface{ function{
                    y
                    +Pigment_Function_01(x,y,z).gray*0.2 } 
                contained_by{
                    //TODO: Parameterize box boundaries
                    box{ <-1.5, -1.0, -0.8>, <1.5, 0.1, 0.8> } } // end contained_by
                accuracy 0.01
                max_gradient 2
                material{ Water_Material }
                // adjust vertical offset of the floor
                transform{ translate<0,0.1,0>} } } // end




// ------- DUCK 
// TODO: (optional) Extract normal function of iso surface to use for duck floating animation
object{ Duck 
        scale 0.05 
        rotate< 5*sin(step), -60, 5*cos(step)> 
        translate <0, 0.08+0.01*cos(step), 0> } // end
