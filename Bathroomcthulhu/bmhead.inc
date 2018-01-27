/****************************************************************
Head Macro for use with "bmpeople.inc" v4.0
refer to "bmmanual.txt" for usage information
*****************************************************************/
#ifndef (BM_Defaults) 
    #include "bmdefs.inc"
#end
#include "eye_macro.inc"
#macro bmhead()
    
    #local Eyes=BM_EyeLids;
    #if (Eyes.x>1) #local Eyes=<1,Eyes.y,Eyes.z>; #end 
    #if (Eyes.x<0) #local Eyes=<0,Eyes.y,Eyes.z>; #end
    #if (Eyes.z>1) #local Eyes=<Eyes.x,Eyes.y,1>; #end
    #if (Eyes.z<0) #local Eyes=<Eyes.x,Eyes.y,0>; #end
    #ifndef (BM_Eye_Shadow)
        #local BM_Eye_Shadow=texture {BM_Skin_Tex}
    #end
    #local MouthWidth=BM_Mouth;
    #local MouthHeight=BM_Jaw;
    #local MouthPos=<0,-4,-2.75>;
    #local NeckTrans=transform {rotate <BM_Neck_Rot.x,0,BM_Neck_Rot.z>}
    #local TorsoTrans=transform {translate <0,20,-3> rotate <BM_Torso_Rot.x,0,BM_Torso_Rot.z> translate <0,-20,3>
                                 translate <0,20,0>  rotate <0,BM_Torso_Rot.y,0> translate <0,-20,0>
                      }
    #local MouthRot=<0,0,BM_MouthShape*15>;
    #local HalfHead=difference {
                            blob {
                                threshold BM_Build
                                #if (BM_Head_Mass>= 1)
                                    sphere{0,5.6,2 scale <1,1,.95> translate z*-1 } // Top Front of Skull
                                    sphere{0,5.6,2 scale <1,1,.9> translate z*1 } // Top of Back Skull  
                                    cylinder{<0,2.5,0><0,4,0>,1,1 scale <2.5,1,3> translate <0,-5,-1.3> }
                                    cylinder{<0,1.5,0><0,2,0>,1,1 scale <1.5,1,3>translate <0,-5,-1.3> }
                                    sphere{0,4,1 scale <.75,.5,.75> rotate x*10 translate  <0,-3.5,.75>} // Base of Skull                                    
                                    sphere {0,2.85,2 translate <0,-2.75,-1.3> rotate y*-35}
                                    cylinder{<0,0,0><0,1,0>,1,1 scale <3-(BM_Gender/2),1,3> translate <0,-5,-1.75> rotate x*(BM_Jaw*-12)}
                                    sphere {0,4,1.5 scale <1,1,.75> translate <0,-3.5,0>}

                                    #if (BM_Face>0)
                                        cylinder {<1,0,0><2.5,0,0>,1,-.75 rotate y*-35 translate <0,-.8,-4.25> }
                                        sphere {0,1,-.25 scale <3,1,1> translate <.5,-1,-4.25> }
                    // Nose
                                        
                                        #if (BM_Gender=0)
                                            cylinder{<-.5-(BM_Gender/6),1.5,1><-.15-(BM_Gender/6),-1,-BM_Nose>,1,2 translate <0,-.7-.75,-4.>}   // Nose
                                            cylinder{<-.7-(BM_Gender/4),0,0><.7-(BM_Gender/4),0,0>,.5,2 translate<0,-1.75-.75,-4.3>} // Nostrils
                                        #end
                                        #if (BM_Gender=1)
                                            sphere {0,1,1 scale <.75,1,1> translate <-.15,-1.5,-3.8>}
                                            sphere {0,1,1 scale <.75,1,1> translate <-.15,-2,-3.9>}
                                            sphere {0,1,1 scale <.75,1,1> translate <-.10,-2.5,-4>}
                                            sphere {0,.75,1 scale <.75,1,1> translate <-.05,-2.75,-4.25>}
                                        #end                                            
                                    #end
                    // Eye Ridge Socket
                                    #if (BM_Face>0)
                                        cylinder{<0,0,0>,<10,0,0>,1,-1.5  scale <1,1.75,1> rotate y*-20 rotate z*0 translate <1.5,-1.8,-4.5>  texture {BM_Eye_Shadow}}
                                        cylinder{<0,0,0>,<10,0,0>,1,-1 scale <1,1.75,1> rotate y*-20 rotate z*0 translate <1.5,-1.8,-4.5> rotate y*-20 texture {BM_Eye_Shadow}}
                                        cylinder{<0,0,0>,<10,0,0>,1,-1 scale <1,1.75,1> rotate y*-20 rotate z*0 translate <1.5,-1.9,-4.5> rotate y*-40 }
                                        cylinder{<0,0,0>,<10,0,0>,1,-1.5 scale <1,1,1> rotate y*-20 rotate z*7.5 translate <1.5,-1.8,-4.5> }
                                    #else
                                        cylinder{<0,0,0>,<10,0,0>,1,-1.5 scale <1,1.75,1> rotate y*-20 rotate z*0 translate <1.5,-1.8,-4.5> }
                                        cylinder{<0,0,0>,<10,0,0>,1,-1 scale <1,1.75,1> rotate y*-20 rotate z*-30 translate <1.5,-1.8,-4.5> rotate y*-20}

                                    #end
                    // Cheeks
                                    sphere{0,1.5,BM_Jowls+.0000001 scale <1.25,1.5,.75> rotate x*-20 translate <0,-3,-3> rotate y*-55 }
                    // Ears
                                    #if (BM_Ears>= 2)
                                        sphere{0,1,2 scale<1,1.75,.7> rotate y*-45 rotate z*-10 translate<4.2,-.85-.5,0> } // Outer Ear Left
                                        sphere{0,1,-2 scale<1,1.75,.7>*.7 rotate y*-45 rotate z*-10 translate<4.2,-.7-.5,-.35>} // Inner Ear Left
                                        sphere{0,1,2 scale<1,1.75,.7>/3.5 rotate y*-45 rotate z*-10 translate<4.025,-.7-.5,-.35>} // Inner Ear Canal Left
                                    #end
                                    #if (BM_Ears = 1)
                                        sphere{0,1,2 scale<1,1.0,.9> scale <1,1.75,1.5> rotate z*-5 translate<3.8,-.85-.75,0> } // Outer Ear Left
                                    #end
                    // Mouth     
                                    #if (BM_Face>0)
                                         #if (BM_Jaw>1)              
                                             #local MouthHeight=1;
                                         #end
                                         #if (MouthHeight<=.25)
                                             #local MouthHeight=.5;
                                         #end
                                       #local MouthHeight=BM_Jaw+(BM_Jaw/10)+.0001;
                    // Inside of Mouth

                                         sphere {0,1,-4 scale <.1+BM_Mouth*1.5,.1+BM_Jaw,1> rotate MouthRot translate MouthPos-<0,BM_Jaw/2-(BM_Jaw/3),0> pigment {rgb -1.5}}

                                   #end         

                                #end

                                #if (BM_Head_Mass= 0)
                                    sphere  {<0,0,0>.00001,0.0000001 pigment {rgbft 1}}
                                #end
                                #if (BM_Head_Mass< 0)
                    // Object Guides
                                    sphere{0,5.6,2 scale <1,1,.95> translate z*-1 } // Top Front of Skull
                                    sphere{0,5.6,2 scale <1,1,.9> translate z*1 } // Top of Back Skull  
                                    sphere{0,4,1 scale <.75,.5,.75> rotate x*10 translate  <0,-3.5,.75>} // Base of Skull                                                                                                            
                                    cylinder{<0,2.5,0><0,4,0>,1,1 scale <2.5,1,3> translate <0,-5,-1.3> }
                                    cylinder{<0,1.5,0><0,2,0>,1,1 scale <1.5,1,3>translate <0,-5,-1.3> }
                                    sphere {0,2.85,2 translate <0,-2.75,-1.3> rotate y*-35}
                                    cylinder{<0,0,0><0,1,0>,1,1 scale <3-(BM_Gender/2),1,3> translate <0,-5,-1.75> rotate x*(BM_Jaw*-12)}
                                    sphere {0,4,1.5 scale <1,1,.75> translate <0,-3.5,0>}


                                #end  
                            }
                            plane {x,-0.0000001}
                     }
    union {
            object {HalfHead}
            object {HalfHead scale <-1,1,1>}
// Teeth
            #local Loop=90;
            #local Denture=union {
                    #while (Loop>-90)
                        superellipsoid {<.25,.25> scale <.2,.5,.1> translate z*-2.2 rotate y*Loop}
                        #local Loop=Loop-11;
                    #end  
                        texture {BM_Tooth_Tex} 
                        scale <.8,.75,1>  
                        translate z*-.5
                    }                                                                     
            #if (BM_Teeth)
                union {
                    object {Denture  translate <0,MouthPos.y+1.2,-1.25>}
                    object {Denture scale <1,-1,1> translate y*-.5 rotate x*-MouthHeight*6 translate <0,MouthPos.y+.65,-.75>}
                    rotate x*-15
                    translate y*.15
                }
            #end    
    // Eyes
            #if (BM_Eyes>0)
                union {      // Left Eye
                    sphere {0,1
                            eye(2.5,BM_EyeCol,1,0,1,0) 
                            rotate x*90
                            rotate y*0
                    }
                    difference {
                        sphere{0,1.1 }
                        box {<5,5,0><-5,-5,-10> }
                        rotate z*-15
                        rotate x*-(Eyes.x*65+65)
                        texture {BM_Eye_Shadow}
                    }
                    rotate <0,Eyes.y,0>
                    translate<1.5,-.75,-2.8>
                }

                union {    // Right Eye
                    sphere {0,1
                            eye(2.5,BM_EyeCol,1,0,1,0)
                            rotate x*90 
                            rotate y*0
                    }
                    difference {
                        sphere{0,1.1 }
                        box {<5,5,0><-5,-5,-10> }
                        rotate z*15
                        rotate x*-(Eyes.z*65+65)
                        texture {BM_Eye_Shadow}
                    } 
                    rotate <0,Eyes.y,0>
                    translate<-1.5,-.75,-2.8>
            }
        
        #else
            object {BM_nul}
        #end
        object {BM_Head_Object}
        material {
            #ifdef (BM_Head_Tex)
                texture {BM_Head_Tex}
            #else
                texture {BM_Skin_Tex}
            #end
            #ifdef (Face_IMap)
                texture {
                    pigment {
                        image_map {
                            png Face_IMap
                            map_type 2 
                            interpolate 4
                            once
                        } 
                        rotate y*-90
                        translate <0,-.55,0>
                        scale 12
                    }
                    #ifdef (BM_Map_Finish)
                        finish {BM_Map_Finish}
                    #end             
                    #ifdef (BM_Map_Normal)
                        normal {BM_Map_Normal}
                    #end
                    #ifdef (Face_BMap)
                        normal {
                            bump_map {
                                png Face_BMap
                                map_type 2
                                interpolate 4
                                once
                                bump_size BM_Bump_Map_Size
                            } 
                            rotate y*-90
                            translate <0,-.55,0>
                            scale 12
                        }
                    #end
                }
            #end
        }
        #if (BM_Gender=1)
            scale <.95,1.1,1>*.9
        #end                 
            
        translate <0,5,-1>
        rotate z*BM_Head_Rot.z
        rotate x*BM_Head_Rot.x
        rotate y*BM_Head_Rot.y
        transform NeckTrans
        translate <0,-5.5,1>
        transform TorsoTrans
    }
// Origin Variables
    #local ReverseAll=transform {
                                 translate <0,20,0> rotate <0,-BM_Torso_Rot.y,0> translate <0,-20,0>
                                 translate <0,20,-3> rotate <-BM_Torso_Rot.x,0,-BM_Torso_Rot.z> translate <0,-20,3>
                                 translate <0,5,-1>
                                 rotate -<BM_Neck_Rot.x,0,BM_Neck_Rot.z>
                                 rotate -y*BM_Head_Rot.y
                                 rotate -x*BM_Head_Rot.x
                                 rotate -z*BM_Head_Rot.z
                                 translate <0,-5.5,1>
                                }              
                                                         
    #declare BMOHF=transform {transform ReverseAll
                              translate z*4.5
                             }
    #declare BMOHB=transform {transform ReverseAll
                              translate z*-4
                             }
    #declare BMOHT=transform {transform ReverseAll
                              translate y*-3.5
                             }
    #declare BMOeR=transform {transform ReverseAll
                              translate y*3
                              translate x*-3.5
                             }                             
    #declare BMOeL=transform {transform ReverseAll
                              translate y*3
                              translate x*3.5
                             }                             
                              
    #declare BMONs=transform {transform ReverseAll
                              translate y*3
                              translate z*4.75
                             }                             
                              
                              

                              


#end       



// End of Head Macro