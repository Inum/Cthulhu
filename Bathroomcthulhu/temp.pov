//2D Soap ////////////////////////////////////////////////////////////
#declare soap =
box{<0,0,0>, <2.23,1.64,0.01>
     texture{ pigment { image_map{ png "images/soap1.png"
                        map_type 0 interpolate 2 once }
                        scale <2.23,1.64,2> }
              finish  { diffuse 0.9 phong 1}}
     scale 1 rotate<0,0,0> translate<0,0,0>}
     
     object{soap translate<-0.5,2,0.5>} //so that you can see it 
////////////////////////////////////////////////////////////////////////     
     
//2D towel stack///////////////////////////////////////////////////////
#declare towels =
box{<0,0,0>, <2.47,2.04,0.01>
     texture{ pigment { image_map{ png "images/towels1.png"
                        map_type 0 interpolate 2 once }
                        scale <2.47,2.04,2> }
              finish  { diffuse 0.9 phong 1}}
     scale 2 rotate<0,0,0> translate<0,0,0>}
     object{towels translate<0,-2,-6>
                   scale 0.15}
///////////////////////////////////////////////////////////////////////

// 2D NoName Shampoo///////////////////////////////////////////////////
#declare shampoo =
box{<0,0,0>, <1.83,2.75,0.01>
     texture{ pigment { image_map{ png "images/shampoo1.png"
                        map_type 0 interpolate 2 once }
                        scale <1.83,2.75,2> }
              finish  { diffuse 0.9 phong 1}}
     scale 0.75 rotate<0,0,0> translate<0,0,0>}
     object{shampoo translate<-1.9,0, -6>
                    scale 0.15}



0.08+0.01*cos(step)