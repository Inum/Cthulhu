#include "colors.inc"    
#include "shapes.inc"
#include "shapes3.inc"

  camera {
    location <0, 3, 10>
    look_at  <0, 2,  2>
    rotate <0,clock*360,0>
  }
  

  
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
#declare duck =
    merge{ object{duckbody}
            object{duckhead
            translate<-1.5,0.6,0>
            rotate<0,180,0>}}
            
//object {duck }//translate < 1.0, 0, 0> rotate < 0,360*clock,0>}
  
light_source{ <2,1,0> color rgb <1,1,1>
              parallel
              point_at<1, 0, 0> 
            } 