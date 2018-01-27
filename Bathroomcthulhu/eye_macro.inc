// ##################################################################

// TYPE OF INC FILE: Eye Material MACRO                      
// CREATOR : Toni Bratincevic                                       
// E-MAIL  : tbrat@mail.geocities.com                                
// HOMEPAGE: http://members.xoom.com/Intercepto                     
// Created in POVRay 3.1 on Pentium 133 (64MB Ram, 1.6GB HD, WinNT) 

// ##################################################################

// osize  - size of material (rec. 0.5)
// ocolor - eye color
// ct     - shadow (default = 1)
// or     - material rotation
// os     - material scale
// ot     - material translation


#macro eye(osize,okocolor,ct,or,os,ot)
   material {   
      texture {      
         normal {
            bumps 0.01
            scale 0.01
         }
         finish {
            ambient 0.1
            diffuse 0.7
            brilliance 2
            phong 1
            phong_size 100
            reflection 0.15
            crand 0.01
         }
         pigment {
            onion
            pigment_map {
               [ 0.00/osize  rgb <0.0, 0.0, 0.0> ]
               [ 0.37/osize  rgb <0.0, 0.0, 0.0> ]
               [ 0.43/osize  rgb okocolor ]
               [ 0.60/osize
                  radial
                  pigment_map {
                  [ 0.3
                  agate
                  color_map {
                     [ 0 color rgb okocolor ]
                     [ .7 color rgb okocolor*0.8 ]
                     [ 1 color rgb okocolor*0.8 ]
                  }
                  scale <1,1/20,1>
                  scale 0.3
                  ]
                  #if(ct) [ 1 color rgb 0 ] #end
                  }
                  triangle_wave
               ]
               [ 0.70/osize
                  radial
                  pigment_map{
                  [ 0.3
                  granite
                  color_map {
                     [ 0 color rgb okocolor ]
                     [ .7 color rgb okocolor*0.5 ]
                     [ 1 color rgb okocolor*0.5 ]
                  }
                  scale <1,1/20,1>
                  scale 0.3
                  ]
                  #if(ct) [ 1 color rgb 0 ] #end
                  }
                  triangle_wave
               ]
               [ 0.76/osize
                  radial
                  pigment_map{
                  [ 0.3
                  granite
                  color_map {
                     [ 0 color rgb okocolor ]
                     [ .7 color rgb okocolor*0.5 ]
                     [ 1 color rgb okocolor*0.5 ]
                  }
                  scale <1,1/20,1>
                  scale 0.3
                  ]
                  #if(ct) [ 1 color rgb 0 ] #end
                  }
                  triangle_wave
               ]
               [ 0.86/osize
                  radial
                  pigment_map{
                  [ 0.3
                  granite
                  color_map {
                     [ 0 color rgb okocolor*0.5 ]
                     [ .7 color rgb okocolor*0.5*0.5 ]
                     [ 1 color rgb okocolor*0.5*0.5 ]
                  }
                  scale <1,1/20,1>
                  scale 0.3
                  ]
                  #if(ct) [ 1 color rgb 0 ] #end
                  }
                  triangle_wave
               ]
               [ 0.88/osize
                  agate
                  color_map {
                     [ 0.0 color rgb <1,1,1> ]
                     [ 0.95 color rgb <1,1,1> ]
                     [ 1.0 color rgb <1,.9,.9> ]
                  }
                  scale <1,1/20,1>
                  scale 0.3
               ]
         }
            scale  <1.0, 20.0, 1.0>
      }}
      rotate or
      scale os
      translate ot
   }
#end
/*          
// TEST          
camera {
   location <0,5,0>
   look_at  <0,0,0>
}

light_source {
   <5,10,-5>
   color rgb 1
}

sphere {
   <0,0,0>,1
   eye(2,<.22,.69,.87>,1,0,1,0)
} 

*/