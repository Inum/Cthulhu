#include "colors.inc"    
#include "shapes.inc"
#include "shapes3.inc"

  camera {
    location <0, 2, 10>
    look_at  <0, 2,  2>
  }
  

  
#declare duckbody = 
    object{
        Spheroid( //CenterVector,
                <-0,0,0>,
             // RadiusVector Rx,Ry,Rz )
                <2.0,1.2,2.0> )
            texture{ pigment{Yellow}
                finish { phong 1}}
            scale<1,1,1>
            rotate<0,0,0>
            translate<0,0.0,0>
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
            
            sphere{<0,0,0>, 0.2 //eyes
                    texture{pigment{White}
                    finish {phong 1}}
                    scale<1,1.5,1> //elliptic
                    translate<-0.45, 1.2, -0.5 >}
            sphere{<0,0,0>, 0.2
                    texture{pigment{White}
                    finish {phong 1}}
                    scale<1,1.5,1> 
                    translate<-0.45, 1.2, 0.5 >}
            cone{<0,0,0>, 0.5, <-2,0,0>, 0.2 //beak
                 texture{ pigment{Orange}
                 finish{phong 1}}
                 scale<1,1,1>
                 translate<0.5, 1, 0>}}
    
//object {duckhead translate < 1.0, 0, 0> rotate < 0,360*clock,0>}
#declare duck =
    merge{ object{duckbody}
            object{duckhead
            translate<-1.5,0.8,0>
            rotate<0,180,0>}}
            
object {duck translate < 1.0, 0, 0> rotate < 0,360*clock,0>}
  
light_source { <2, 4, -3> color White} 