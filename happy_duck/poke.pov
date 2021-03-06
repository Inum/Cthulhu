#version 3.7;
#include "colors.inc"
#include "glass.inc"
#include "skies.inc"
#include "textures.inc"
#include "shapes.inc"
#include "shapes3.inc"
// duck model originally taken from: http://www.oyonale.com/modeles.php?lang=en&page=53
//#include "duck/duck.inc"
//#include "rubberduck.inc"

global_settings{ assumed_gamma 1.0 }
//---------------------------------------
// Scaled clock step to allow full animation circles of 2*pi
#local progress=clock/final_clock;
#local step=2 * pi * progress;

#local start_fade=final_clock*0.2;
#local end_fade=final_clock*0.7;
#local storm_arrived = final_clock*0.85;

#declare fac=function(v){v * min(1, max(0.3, 1 - max(0, clock - 0.05*final_clock)))}

// Camera 
//#declare Cam0 = camera{ angle 65
//                        location <fac(6) - progress, fac(3), -fac(5) + progress>
//                        look_at <0, 10 * max(0, 0.1*final_clock - clock), 0>} //end

#declare parab=function(x,low,high){-4*pow((x-low)/(high-low),2) + 4 * (x-low)/(high-low)}

#declare Cam0 = camera{ angle 65
                        #if (clock <= start_fade)
                        location <1.5, 1, -1>
                        look_at <0, 0, 0>
                    #end
                    #if (clock > start_fade & clock < storm_arrived)
                        location <1.5 - 1.5 * (clock-start_fade) / (storm_arrived-start_fade), 1 + parab(clock,start_fade,storm_arrived) + 4 * (clock-start_fade) / (storm_arrived-start_fade), -1 - 4 * (clock-start_fade) / (storm_arrived-start_fade)>
                        look_at <(clock-start_fade) / (storm_arrived-start_fade) * 1.5,parab(clock,start_fade,storm_arrived) * 5-(clock-start_fade) / (storm_arrived-start_fade),0>
                    #end
                    #if (clock >= storm_arrived)
                        location <0, 5, -5>
                        look_at <1.5,-1,0.0>
                    #end
                    } //end


#declare Cam1 = camera{ angle 65
                        location <1.5, 1, -1>
                        look_at <0.0, 10, 0.0>} //end



//---------------------- end of camera 
//#if (clock < end_fade)
//    camera{Cam0}
//#end
//#if (clock >= end_fade & clock < storm_arrived)
//    camera{Cam0}
//#end
//#if (clock >= storm_arrived)
//    camera{Cam0}
//#end
//#if (clock >= start_fade & clock < storm_arrived)
//    camera{Cam0}
//    //fog{distance 10 color rgbt <0.2,0.2,0.2,0.1> fog_offset 0.0 fog_alt 1 turbulence 0.05}
//#end
    camera{Cam0}

//---------------------------------------
light_source{ <1500,2500,-2500>
              color rgb<1,1,1> 
              looks_like{sphere {<0,0,0>, 80 texture{pigment{color White} finish{ambient 10}}}}}

#if (clock < end_fade)
    sky_sphere{S_Cloud3}
#else
    sky_sphere{S_Cloud4 rotate <clock*0.1,0,0>}
#end
//---------------------------------------
#local render_water=1;
              

//Water
#declare s=function(x,y){3/(x*x+y*y+.5)}
#declare g=function{pattern{granite scale 6-y*2}}
#declare f=function(x,y,z,a,b){pow(g(x*a+z*b,y+clock,x*b-z*a),.6)}
#declare h=function(x,y,z,a){f(x,y,z,sin(a),cos(a))}

//--------------------------------------- 


#declare duckbody = 
merge{
    object{
        Spheroid( //CenterVector,
                <-0,0,0>,
             // RadiusVector Rx,Ry,Rz )
                <1.5,1.2,1.5> )
            texture{ pigment{Yellow}
                finish { phong 1}}
            scale<1,1,1>
            rotate<0,0,0>
            translate<0,0.0,0>
            }
            object{ Round_Conic_Torus( //wings
                0.90, // >0, vertical center distance
                0.85, // >0, upper radius
                0.30, // >0, lower radius
                0.30, //>2*border radius, length in z-                
                // max. = min(lower radius, upper radius)!
                0) // Merge_On: 0 or 1
                 // ------------------------------------
                texture{ pigment{Yellow}
                    finish { phong 1}
                    } // end texture
                scale <1,1,1>
                rotate <0,0,270>
                translate < -1, 0.3, 1.1>
                } 
            object{ Round_Conic_Torus( //wings
                0.90, // >0, vertical center distance
                0.85, // >0, upper radius
                0.30, // >0, lower radius
                0.30, //>2*border radius, length in z- 
                0) // Merge_On: 0 or 1
                 // ------------------------------------
                texture{ pigment{Yellow}
                    finish { phong 1}
                    } // end texture
                scale <1,1,1>
                rotate <0,0,270>
                translate < -1, 0.3, -1.1>
                } 
            object{ Egg_Shape( 1.0, 2.2) //tail
                texture{
                    pigment{ Yellow}
                    finish { phong 1 }
                } // end of texture
                rotate < 0, 0, 25>
                translate < -0.7, -0.4, 0>
} // end of object 
}
  
#declare duckhead =
     merge{
      object{
        Egg_Shape(1.15,1.55)
            texture{ pigment{Yellow}
                finish {phong 1}}
            scale 1
            rotate <0,0,0>
            translate < 0, 0, 0>}
            merge{
            sphere{<0,0,0>, 0.2 //eyes
                    texture{pigment{White}
                    finish {phong 1}}
                    scale<1,1.5,1> //elliptic
                    translate<-0.45, 1.2, -0.5 >}
                         sphere{<0,0,0>, 0.1 //pupils
                            texture{pigment{Black}
                            finish {phong 1}}
                            scale<1,1.5,1> //elliptic
                            translate<-0.6, 1.2, -0.5 >}}
            merge{
            sphere{<0,0,0>, 0.2
                    texture{pigment{White}
                    finish {phong 1}}
                    scale<1,1.5,1> 
                    translate<-0.45, 1.2, 0.5 >}
                        sphere{<0,0,0>, 0.1 //pupils
                            texture{pigment{Black}
                            finish {phong 1}}
                            scale<1,1.5,1> //elliptic
                            translate<-0.6, 1.2, 0.5 >}}
            cone{<0,0,0>, 0.5, <-2,0,0>, 0.2 //beak
                 texture{ pigment{Orange}
                 finish{phong 1}}
                 scale<1,1,1>
                 translate<0.5, 1, 0>}}
    
//object {duckhead translate < 1.0, 0, 0> rotate < 0,360*clock,0>}

#local down=final_clock * 0.1;
#local wait=final_clock*0.18;
#local upwards=final_clock * 0.25;
#local done=final_clock * 0.35;

#declare duck =
    merge{ object{duckbody}
        object{duckhead
            #if (clock < down)
                rotate<0,180,0>
            #end
            #if (clock > down & clock < wait)
                rotate<0,180, - 60 * (clock - down) / (wait - down)>
            #end
            #if (clock > wait & clock < upwards)
                rotate<0,180, - 60>
            #end
            #if (clock > upwards & clock < done)
                rotate<0,180,- 60 + 60 * (clock - upwards) / (done - upwards)>
            #end
            #if (clock > done)
                rotate<0,180,0>
            #end
            //#if (clock >= toright & clock < back)
            //    rotate<0,145 + 70 * (clock - toright) / (back - toright),0>
            //#end
            //#if (clock >= back & clock < tocamera)
            //    rotate<0,215 - 35 * (clock - back) / (tocamera - back),0>
            //#end
            //#if (clock >= tocamera & clock < done)
            //    rotate<-10 *(clock-tocamera)/(done-tocamera),180 + 35 * (clock - tocamera) / (done - tocamera),35 * (clock - tocamera) / (done - tocamera)>
            //#end
            //#if (clock >= done)
            //    rotate<-10,215,35>
            //#end
            translate<1.5,0.6,0>}}

#local start_bounce=final_clock*0.0;
#local end_bounce=final_clock*0.04;
#local bounce_x = max(0,min(end_bounce-start_bounce, (clock-start_bounce)));
#declare bounce_y = function(x){-pow(x,2)+ (end_bounce-start_bounce) * x}


object {duck 
 scale 0.05
 rotate <0.1*sin(clock*10),0,0>
 translate <0,0.01*sin(clock*10) + bounce_y(bounce_x)*3,0>
}


#declare fade=function(v,low,high){min(1,max(0,(v-low) / (high-low)))}

plane {y, 0 
    #if (clock >((storm_arrived*0.8 + start_fade) / 2))
        texture{pigment {rgb<.5,.8,.7>} finish{ diffuse .3 phong 1 specular .5 reflection {.2, .75 fresnel} }
            #if (render_water)
                normal{function{h(x,y,z,s(x,z))}-1.5}
            #end
            translate <3,0,0>
        }
    #else
    texture {pigment {rgbf <0.92,0.99,0.96,0.45>}
        finish {diffuse 0.1 
            reflection 0.5 
            specular 0.8 
            roughness 0.0003 
            phong 1 
            phong_size 400 }
                normal {ripples 
                    phase clock
                    turbulence 0.1}
                //                #if (clock>end_bounce)
                //                    normal {ripples 0.1 / (clock-end_bounce) phase clock * 2
                //                            scale 0.1+clock/10
                //                            turbulence 0.1}
//                        #end
                }
            #end
            }


#if (clock > start_fade & clock < end_fade)
    plane {y, 100
        texture{pigment{rgbt <0.0,0.0,0.0,1 - 0.6 * parab(clock,start_fade,storm_arrived)>}}}
#end

        
//#if (clock > done & 0)
//lathe{bezier_spline 4<0,-2>0 1<4,2>
//    texture{pigment{rgb<.5,.8,.7>}finish{diffuse .3 phong 1 specular .5 reflection {.2, .75 fresnel}}
//        #if (render_water)
//            normal{function{h(x,y,z,s(x,z))}-1.5}
//        #end
//    }
//    no_shadow
//    translate <0,-2,-2>
//    scale 0.1}
//#end

