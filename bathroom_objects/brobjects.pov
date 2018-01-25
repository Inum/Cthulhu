#include "colors.inc"    
#include "shapes.inc"
#include "shapes3.inc"

  camera {
    location <0, 3, 10>
    look_at  <0, 2,  2>
    rotate <0,clock*360,0>
  }
  

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
            
//2D Soap ////////////////////////////////////////////////////////////
#declare soap =
box{<0,0,0>, <2.23,1.64,0.01>
     texture{ pigment { image_map{ png "images/soap1.png"
                        map_type 0 interpolate 2 once }
                        scale <2.23,1.64,2> }
              finish  { diffuse 0.9 phong 1}}
     scale 1 rotate<0,0,0> translate<0,0,0>}
     
     object{soap translate<2,2,0>} //so that you can see it 
////////////////////////////////////////////////////////////////////////     
     
//2D towel stack///////////////////////////////////////////////////////
#declare towels =
box{<0,0,0>, <2.47,2.04,0.01>
     texture{ pigment { image_map{ png "images/towels1.png"
                        map_type 0 interpolate 2 once }
                        scale <2.47,2.04,2> }
              finish  { diffuse 0.9 phong 1}}
     scale 2 rotate<0,0,0> translate<0,0,0>}
     object{towels translate<-2,-2,0>}
///////////////////////////////////////////////////////////////////////

// 2D NoName Shampoo///////////////////////////////////////////////////
#declare shampoo =
box{<0,0,0>, <1.83,2.75,0.01>
     texture{ pigment { image_map{ png "images/shampoo1.png"
                        map_type 0 interpolate 2 once }
                        scale <1.83,2.75,2> }
              finish  { diffuse 0.9 phong 1}}
     scale 0.75 rotate<0,0,0> translate<0,0,0>}
     object{shampoo translate<4,0,0>}


    
    