//  camera {
  //  location <0, 3, 10>
    //look_at  <0, 0,  0>
    
  //}

//text{
  // ttf "LiberationSansNarrow-Bold.ttf",
   //"text object",10, 0
   //texture{
    // pigment{color rgb<1,0.65,0>}
     //finish{ambient 0.15
       //     diffuse 0.85}
         // }}
          
          
  #include "colors.inc"
  camera {
    location <0, 0, -20>
    look_at 0
    angle 35
  }
  light_source { <500,500,-1000> White }

  
   text {
    ttf "LiberationSansNarrow-Bold.ttf" "Duckwich Horror!" 1, 0
    pigment { Red }
    translate -3*x}
    
   text {
   ttf "lovecrafts-diary.regular.ttf" "Cthulu Myth" 1, 0
   pigment{Red}
   translate -3.0*x
   translate 1.50*y
   scale<0.8,0.8,0.8>
   
}
    //hollow
    //interior{ //---------------------
    // media{ method 3
      //     emission <1,1,1>*10
        //   scattering{ 1, // Type
          //    <1,1,1>*5.00
           // } // end scattering
           //density{ spherical
             //       scale 1
               //     turbulence 0.85
                 //   color_map {
                   // [0.00 rgb 0]
                    //[0.05 rgb 0]
                    //[0.20 rgb 0.2]
                    //[0.30 rgb 0.6]
                    //[0.40 rgb 1]
                    //[1.00 rgb 1]
                   //} // end color_map
          // } // end of density
           //samples 20 // higher = more precise

     //} // end of media --------------------------
 // } // end of interior
//} //-
  