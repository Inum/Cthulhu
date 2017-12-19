
          
          
  #include "colors.inc"
  
  #local step=2 * pi * clock / final_clock;
  
//  #declare font = "LiberationSansNarrow-Bold.ttf"
  
//  #if ( mod(clock, 2) = 0)
//   #declare font = "lovecrafts-diary.regular.ttf" 
//  #else
//   #declare font = "LiberationSansNarrow-Bold.ttf"
//  #end
  
  camera {
    location <0, 0, -20>
    look_at 0
    angle 35
  }
  light_source { <500,500,-1000> White }
  
  
//  plane {y, -0.02
//   texture{pigment{ rgbf <0.92,0.99,0.96,0.45>}
//   finish{ diffuse 0.1 reflection 0.5 specular 0.8 
//        roughness 0.0003 phong 1 phong_size 400 
//        }
//    }
//    normal{ bumps 
//        phase clock
//        turbulence 0.1
//        scale 1.0 + 0.1*sin(step)}
//}

  
   text {
    ttf "LiberationSansNarrow-Bold.ttf" "Duckwich Horror!" 1, 0
    pigment { Red }
    translate -3*x}
    
   text {
   ttf "lovecrafts-diary.regular.ttf" "Cthulu Myth" 1, 0
    //pigment{Red}
    pigment { rgbt 1 }
           hollow

       interior{ //---------------------
          media{ scattering{ 1, <1,1,1>
                             extinction  2.5 }
                 absorption rgb< 0.61, 0.85, 0.85>*2
                 // density 1
                 density{ spiral2 10
                          turbulence 0.20
                          color_map {
                                [0.00 rgb 0.00] // border
                                [0.50 rgb 0.20] //
                                [1.00 rgb 1.00] // center
                              } // end color_map
                          rotate<90,0,0>
                          scale<10,0.5,1>
                        } // ----------- end of density 1
                 // density 2
                 density{ cylindrical
                          turbulence 1.0
                          frequency 1
                          color_map {
                                [0.00 rgb 0.00] // border
                                [0.50 rgb 0.20] //
                                [0.80 rgb 1.00] //
                                [1.00 rgb 0.50] // center
                              } // end color_map
                          scale<10,2,1>
                        } // ----------- end of density 2
          } // end of media ------------------
         } // ------------------ end of interior
    translate -3.0*x
    translate 1.50*y
    scale<0.8,0.8,0.8>}
   

