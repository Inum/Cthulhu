#include "colors.inc"
#include "textures.inc"

//declare textures
#declare F_Plastic=finish{ambient 0 diffuse 1 phong 1} // reflection{0,0.1 fresnel}}
#declare T_Bill=texture{pigment{Red} finish{F_Plastic}}
#declare T_Eye=texture{pigment{White} finish{F_Plastic}}
#declare T_Body=texture{pigment{rgb <0.8,0.75,0>} finish{F_Plastic}}
#declare T_Pupil=texture{pigment{Black} finish{F_Plastic}}

// include ducky moodel
#include "duck/ducky.inc"

// full duck model
#declare Duck=union{
    object{Ducky}
    object{Ducky scale <-1,1,1>}
    rotate y*180
    scale 1/100
    translate -y*0.5 }
