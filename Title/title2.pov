#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "shapes.inc"

global_settings {assumed_gamma 1.0}


#local step=2 * pi * clock / final_clock;

//  #declare font = "LiberationSansNarrow-Bold.ttf"

//  #if ( mod(clock, 2) = 0)
//   #declare font = "lovecrafts-diary.regular.ttf" 
//  #else
//   #declare font = "LiberationSansNarrow-Bold.ttf"
//  #end

#local camera_z=8/exp(1-min(1,clock/(0.25*final_clock)));


camera {
    location <0, 0, camera_z>
    look_at 0
    angle 50+clock*0.5
}
light_source { <0,50,0.5> White }

// ------------------------------------ Water simulation
sphere{<0,0,camera_z>, camera_z-1
      texture{ Green_Glass
          normal{bumps phase clock scale 1 turbulence 0.1 translate 10*x}
          //normal{ripples phase clock scale 0.8 + 0.1*sin(step) turbulence 0.1}
          finish{ambient 0 diffuse 0.0 reflection 0.0}
      }
      interior{I_Glass}
}

// ------------------------------------ Floor
plane{<0,0,1>,-1
    pigment{color rgb <0.6,0.6,0.2>*0.3 * step}
    normal {marble .5 scale 0.5 turbulence 1.0}
}

// ------------------------------------ Texts

object{
        Bevelled_Text
        ("LiberationSansNarrow-Bold.ttf", // Fontbezeichnung
            "Duckwich Horror!",// testo
            10 ,      // Schnitte
            35,       // Abschrägungswinkel
            0.045,    // Abschrägungstiefe
            1,        // Schrifttiefe in z-Richtung
            0.00,     // Anstieg pro Zeichen
            0)        // 1 = "merge"
            texture{
                //pigment{color rgb<1,0.70,0>}
    pigment {crackle scale 0.1-step * 0.01 turbulence 0.1
            color_map {[0.00 color rgb<0,0,0>]
                     [0.08 color rgb<.5,.5,.25>*(1-step/10)]
                     [0.32 color rgb<1,0.65,0>]
                     [1.00 color rgb<1,1.0,0.5>]}  }
                normal { bumps 0.5 scale 0.005}
                finish{ambient rgb <0.6,0,0>*clock/final_clock diffuse 0.75 phong 1}
            } // end of texture
    translate -z-3.4*x
    rotate <0,180,0>
    scale <1,1,0.05>
}

text {
    ttf "lovecrafts-diary.regular.ttf" "Cthulu Myth" 1, 0
    //pigment{Red}
    pigment { rgbt 1 }
    hollow

    interior{ //---------------------
        media{ scattering{ 1, <1,1,1>
                extinction  5.5 }
                absorption rgb< 0.61, 0.85, 0.85>*50
                // density 1
                density{ spiral2 10
                    turbulence 0.10
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
                        [1.00 rgb 0.10] // center
                    } // end color_map
                    scale<10,2,1>
                } // ----------- end of density 2
            } // end of media ------------------
        } // ------------------ end of interior
        translate -3.0*x
        translate 1.50*y
        scale<0.8,0.8,0.8>
        rotate <0,180,0>
    }

// ---------------------------------------- Fog
sphere{ <0,0,-0.5>,8
    pigment{ rgbt 1 }
    hollow
 interior{ //-----------
 media{
     absorption 5
  density{ gradient y
    turbulence 0.4 + 0.02*sin(step)
    frequency 3
    color_map {
     [0.0 rgb 1]//border
     [0.5 rgb 0.03]
     [1.0 rgb 0.0]//center
     } // end color_map
   } // end of density
  density{ spherical 
    turbulence 0.0
    color_map {
     [0.0 rgb 1]//border
     [0.1 rgb 0.1]
     [0.5 rgb 0.03]
     [1.0 rgb 0.0]//center
     } // end color_map
   }
  } // end of media ----
 } // end of interior
 scale <1,1,0.125>
} //------- end of sphere
