/***************************************************************
Torso Macro for use with "bmpeople.inc" v4.0
refer to "bmmanual.txt" for usage information
****************************************************************/
#ifndef (BM_Defaults) 
    #include "bmdefs.inc"
#end

#macro bmtorso()
    #if (BM_Flex>0)  
        #declare BM_Flex=1;  
    #else 
        #declare BM_Flex=0;
    #end
    #if (BM_Gender=0)
        #local Shoulder         =<8.25,1,0>;
        #local Hips             =<1.5,2,1.5>;
        #local UpperarmLength   =11;
        #local ForearmLength    =10.5;
        #local ThighLength      =14;
        #local CalfLength       =17;     
        #local R_Leg            =transform {translate <-0,-2,-.75>}
        #local L_Leg            =transform {translate < 0,-2,-.75>}
    #end
    #if (BM_Gender=1)
        #local Shoulder         =<6.25,1,.25>;
        #local Hips             =<.75,-3,1>;
        #local UpperarmLength   =10.85;
        #local ForearmLength    =10.5;
        #local ThighLength      =14.7;
        #local CalfLength       =18.9; 
        #local R_Leg            =transform {translate <-.55,2,-1>}
        #local L_Leg            =transform {translate < .55,2,-1>}
    #end

    #local NeckTrans=transform {rotate <BM_Neck_Rot.x,0,BM_Neck_Rot.z>}
    
    #local R_Elbow=vrotate(<0,-UpperarmLength,0>,BM_RA_S2E);
    #local R_Wrist=vrotate(<0,-ForearmLength,0> ,BM_RA_E2W);
    #local L_Elbow=vrotate(<0,-UpperarmLength,0>,BM_LA_S2E);
    #local L_Wrist=vrotate(<0,-ForearmLength,0> ,BM_LA_E2W);

    #local R_Knee =vrotate(<0,-ThighLength,0>,BM_RL_H2K);
    #local R_Ankle=vrotate(<0,-CalfLength,0> ,BM_RL_K2A);
    #local L_Knee =vrotate(<0,-ThighLength,0>,BM_LL_H2K);
    #local L_Ankle=vrotate(<0,-CalfLength,0> ,BM_LL_K2A);

    #local R_Upperarm=transform {rotate BM_RA_S2E translate <-Shoulder.x,-UpperarmLength+Shoulder.y,1+Shoulder.z>}
    #local L_Upperarm=transform {rotate BM_LA_S2E translate < Shoulder.x,-UpperarmLength+Shoulder.y,1+Shoulder.z>}
    #local R_Forearm =transform {rotate BM_RA_E2W translate R_Elbow translate < -Shoulder.x,1.25-UpperarmLength,1+Shoulder.z>}
    #local L_Forearm =transform {rotate BM_LA_E2W translate L_Elbow translate < Shoulder.x,1.25-UpperarmLength,1+Shoulder.z>}
    #local R_HipReplace=<BM_RL_H2K.y/-50,0,BM_RL_H2K.y/-50>;
    #local L_HipReplace=<BM_LL_H2K.y/-50,0,BM_LL_H2K.y/50>;
    #local R_Thigh=transform {rotate BM_RL_H2K translate <-Hips.x+R_HipReplace.x,-29+Hips.y,R_HipReplace.z+Hips.z>}
    #local L_Thigh=transform {rotate BM_LL_H2K translate < Hips.x+L_HipReplace.x,-29+Hips.y,L_HipReplace.z+Hips.z>}
    #local R_Calf =transform {rotate BM_RL_K2A translate R_Knee translate <-Hips.x+R_HipReplace.x,-29+Hips.y+BM_Gender,R_HipReplace.z+Hips.z>}
    #local L_Calf =transform {rotate BM_LL_K2A translate L_Knee translate < Hips.x+L_HipReplace.x,-29+Hips.y+BM_Gender,L_HipReplace.z+Hips.z>}
    #local TorsoTrans=transform {translate <0,20,-3> rotate <BM_Torso_Rot.x,0,BM_Torso_Rot.z> translate <0,-20,3>
                                 translate <0,20,0>  rotate <0,BM_Torso_Rot.y,0> translate <0,-20,0>
                                }
    #declare NeckTrans=transform {rotate <BM_Neck_Rot.x,0,BM_Neck_Rot.z>}
    
    #local UpperArmModel=#if (BM_Gender=0)
                             blob {
                            	threshold BM_Build
                            	sphere   { 0, 5, 1 scale <1.0, 0.8, 0.9> rotate 45*z }// Shoulder Joint
                            	cylinder { <0, 0, 0>, <UpperarmLength, 0, 0>, 3, 1 }
                            	sphere   { 0, 3.5, 1	scale <2, 1, 1> translate x*(UpperarmLength*.387)}
                            	rotate z*-90
                            }
                         #end
                         #if (BM_Gender=1)
                             blob {
                            	threshold BM_Build
                            	sphere { 0, 4.2, 1 scale <1.0, 0.8, 0.9> rotate 45*z }// Shoulder Joint
                            	cylinder { <0, 0, 0>, <UpperarmLength, 0, 0>, 2.45, 1 }
                            	sphere { 0, 2.8, 1	scale <2, 1, 1> translate 4.2*x	}
                            	rotate z*-90
                            }
                         #end

    #local ForearmModel=#if (BM_Gender=0)
                             blob {
                            	threshold BM_Build
                            	cylinder { <0, 0, 0 >, <ForearmLength, 0, 0>, 2.0, 1
                            		scale <1, 1, 0.7>}
                            	sphere { <0, 0, 0>, 3.5, 1 scale <2.0, 1, 1> translate x*(ForearmLength*.4) }
                            	cylinder { <0,0,0>, <(ForearmLength*.4), 0, 0>, 2.0, 1 }
                            	rotate z*-90
                             }
                         #end
                         #if (BM_Gender=1)
                             blob {
                            	threshold BM_Build
                            	cylinder { <0, 0, 0 >, <ForearmLength, 0, 0>, 1.96, 1
                            		scale <1, 1, 0.7>}
                            	sphere { <0, 0, 0>, 2.8, 1 scale <2.0, 1, 1> translate 4.2*x }
                            	cylinder { <0,0,0>, <4.2, 0, 0>, 1.68, 1 }
                            	rotate z*-90
                            }
                         #end                         
                         
      #local ThighModel=blob{
                    		threshold BM_Build
                    		// Thigh Left
                    		
                    		#if (BM_Gender=0)
                    		    // Main Thigh
                    		    cylinder {<0, -1.4, 0>+<1, -2.8, -0>, <0, -ThighLength, 1>, 4.3, 1}
                        		// Muscle
                        		sphere { <0, 0, 0>, 4, .5 
                        		    scale <1.2, 2.0, 1.1>
                        		    scale <1.25,1,1.25>
                        		    rotate z*-20 
                        		    translate <-1.5, -ThighLength*.452, 0.35>+<3.5, -2.8, -1.5>
                        		}    
                                // Knee
                        		sphere { <0, 0, 0>, 2.1, .5 scale <1,1,1> translate <0, -ThighLength, 0> }                                         
                        		sphere { <0, 0, 0>, 4, -.35 scale <2,1.5,1> translate <0, -ThighLength, 1.65>}
                            #end
                            #if (BM_Gender=1)
                                // Main Thigh
                                cylinder {<0, -1.4, 0>+<2, -2.8, -1>, <0, -ThighLength, .5>, 3.43, 1}                         		    
                        		// Muscle
                        		sphere { <0, 0, 0>, 4, .5 
                        		    scale <1.2, 2.0, 1.0>
                        		    scale <1.25,1,1.25>
                        		    rotate z*-20 
                        		    translate <-1.5, -ThighLength*.452, 0.35>+<3.5, -2.8, -1.5>
                        		} 
                                // Knee
                        		sphere { <0, 0, 0>, 1.8, 1 translate <0, -ThighLength, .1> }                                         
                        		sphere { <0, 0, 0>, 4, -.45 scale <2,1.5,1> translate <0, -ThighLength, 3>}
                    		#end
                    		// Hip
                    		sphere { <0,0,0>, 7, 1
                    			scale <0.9, 1.4, 1.1> 
                    			translate <-1.05, 1.75, 1.05>+<3.5, -2.8, -1.4>}
                    		
                    		sphere { <0,0,0>, 7, 1
                    			scale <0.7, 0.8, 0.7> 
                    			translate <-3.5, 2.8, 1.4>+<3.5, -2.8, -1.4>}
                                         
                    	}    

    #local CalfModel=#if (BM_Gender=0) 
                            blob {
                            threshold BM_Build
                        		// Main
                        		cylinder {<0,0,0>, <0, -CalfLength, 0>, 2.75, 1}
                        		// Muscles
                        		sphere { <0, 0, 0>, 5.5, 1
                        			scale <1, 2, 1>
                        			translate <-.14, -6.65, .84>
                        	    }  
                        	    sphere { <0, 0, 0>, 4, -.1
                        			scale <2, 4, .75>
                        			translate <0, -CalfLength-2, -1> 
                        	    }
                            }
                      #end
                      #if (BM_Gender=1)
                        	blob{
                        		threshold BM_Build
                        		// Main
                        		cylinder {<0,-1.5,0>, <0, -CalfLength, 0>, 2.52, 1}
                        		// Muscles
                        		sphere { <0, 0, 0>, 4.13, 1
                        			scale <1, 2.4, 1>
                        			translate <-.14, -6.65, .84>
                        	    }  
                        	    sphere { <0, 0, 0>, 2, -.1
                        			scale <2, 4, .75>
                        			translate <0, -CalfLength-2, -1>
                        	    }
                        	}   
                      #end                       
    #local HalfFemaleTorso=difference {
                                #if (BM_Torso_Mass>0)
                            		blob{
                            			threshold BM_Build
                            			// Upper Chest		
                            			cylinder { <0,0,0>, <0,1.0,0>, 1, 1
                            				scale <1.3,.98,0.8> rotate <10,-10, 0 > }
                            			// Ribs
                            			cylinder { <0,0,0>, <0,0.7,0>, 1, 1
                            				scale <1,0.6,0.5> rotate <10,0,-15> translate <0, 0.2, -0.20> }
                            			// Lower chest
                            			cylinder { <0,0,0>, <0,1.0,0>, 1, 1
                            				scale <0.75,0.5,0.6> translate <0.0,-0.6, -0.10> }
                            			// Breasts
                            			    sphere { <0,0,0>, 1, 1    scale <0.45,0.6,0.4> rotate <20,-5,0> translate <0.4, 0.4, -0.50> }
                            			    sphere { <0,0,0>, 0.42, 1 scale <1,1,0.5> rotate <0,-15,0> translate <0.4, 0.25, -0.52> }

                                			#if (BM_TShirt)
                            			        sphere { <0,0,0>, 1, 1 scale <.8,0.55,0.4> translate <0, 0.35, -0.5> }
                            			        sphere { <0,0,0>, 1, 1 scale <.8,0.55,0.4> translate <0, 0.28, -0.5> }
                                			#end
                                			#if (BM_Nipples)
                                			    sphere {0,.1,1 scale <1,1,.25> rotate y*-5 rotate x*-5 translate <0.4,0.25,-.71>
                                			    #ifdef (BM_Nipple_Tex) 
                                                    texture (BM_Nipple_Tex) 
                                                #end
                                			    }
                                			    sphere {0,.05,1 translate <0.4,0.25,-.71>
                                                #ifdef (BM_Nipple_Tex) 
                                                    texture (BM_Nipple_Tex) 
                                                #end                                    			    
                                			    }
                            			    #end 
                            			// Shoulder
                            			cylinder {<0,0,0><.1,0,0>,1,1
                            				scale <0.6, 0.5, 0.4>
                            				translate < 0.7, 0.9, 0.2 >
                            		    }
                            			// Clavicle
                            			cylinder { <0, 0, 0>, <0.35, 0, 0 >, 0.3, -.8 
                            						scale <1.75, 1, 2> 
                            						rotate <-25,-4, 5> 
                            						translate <0.0, 1.2, -0.25 >}
                                        sphere {<1.4,.8,.2>,.5,-1  }	
                            		}
                            		#end
                            		#if (BM_Torso_Mass<=0)
                                        object {BM_nul}
                                    #end  
                                    
                                    #if (BM_Torso_Mass<0)
                                    // Object Guides
                                       blob {
                                             threshold BM_Build-.3
                                             #local Loop=-3;
                                             #while (Loop>-20)
                                                 sphere{0,BM_Guide_Rad,2 translate<0,Loop-3,sin((Loop+2)*pi/(4+abs(Loop)/4))*(.25+abs(Loop/15))+1+Shoulder.z>}
                                                 #local Loop=Loop-1;
                                             #end
                                             cylinder{<0,-10,Shoulder.z+1><Shoulder.x,-10,Shoulder.z+1>,BM_Guide_Rad,2}
                                       } 
                                    #end                                         
                                    
                            		plane { x, -0.000001 }

                                    translate y*-2.25
                                    scale 7.5
                                 }   
                                       
                                	
    
    #local HalfMaleTorso=difference {#if (BM_Torso_Mass>0)
                                      blob {
                                          threshold BM_Build-.3
                                      // Spine
                                          #local Loop=-6;
                                          #while (Loop>-15)
                                              sphere{0,2*.75,2 translate<0,Loop-3,sin((Loop+2)*pi/(4+abs(Loop)/4))*(.25+abs(Loop/15))+.8>}
                                              #if (mod(Loop+2,3)=0)
                                                  sphere{0,.5*.75,1 translate<0,Loop-3,sin((Loop+2)*pi/(4+abs(Loop)/4))*(.25+abs(Loop/15))+1>}
                                              #end
                                              #local Loop=Loop-1;
                                          #end
                                       //Shoulders
                                          cylinder{< 8,-9,.5><1,-6.75,1>,1.2,2}
                                          cylinder{< 0,0,1><8,0,1>,3,2 scale <1,1.25,1>translate y*-10.25}
                                          // Upper Chest
                                          cylinder{<8,-9,.5><1,-9.5,-1.25>,1,2}
                                          cylinder{<0,-10.5,-.5><6,-10.5,-.5>,2,2 }
                                          sphere {0,2,2 scale <1.5,2,1.5> translate <7,-12,.85> }
                                          // Chest and Shoulder Blades
                                          sphere{0,4,2.5   scale <1.4,2,1.3>   rotate x*22  translate < 2.8,-14,0>} // Left
                                          sphere{0,4,3   scale <1.4,1,1.3>   rotate x*20  rotate z*-20 translate< 3,-13,-.25>} 
                                          sphere{0,4,-.8 scale <1.4,2,1.3>   rotate x*20  translate < 2.8,-14,-3.5> } 
                                          sphere{0,4,-.8 scale <1.4,1,.5>   rotate x*20  translate < 2.8,-12,-3.7> } 
                                          sphere{0,2,-2  scale <2,2.75,2>    rotate z*-10 translate < 9.25,-15.25,1> rotate y*15 }
                                          sphere{0,2,-.8 scale <2.5,1.8,.75> rotate y*-45 rotate x*-15 translate < 5,-18,-3.3>}
                                          // Nipples
                                          #if (BM_Nipples)
                                            sphere {0,1,1 scale <1,1,.25> rotate y*-5 translate <4.5,-14,-3.5> 
                                                #ifdef (BM_Nipple_Tex) 
                                                    texture (BM_Nipple_Tex) 
                                                #end
                                            }
                                          #end
                                    }
                                 #end
                                 #if (BM_Torso_Mass=0)
                                     object {BM_nul}
                                 #end
                                 #if (BM_Torso_Mass<0)
                                 // Object Guides
                                     blob {
                                         threshold BM_Build-.3
                                          #local Loop=0;
                                          #while (Loop>-20)
                                              sphere{0,BM_Guide_Rad,2 translate<0,Loop-3,sin((Loop+2)*pi/(4+abs(Loop)/4))*(.25+abs(Loop/15))+1>}
                                              #local Loop=Loop-1;
                                          #end
                                          cylinder{<0,-10,1><Shoulder.x,-10,1>,BM_Guide_Rad,2}
                                       }
                                 #end
                      
                                 plane {x,-0.00000001}
                            }

    #local FemaleAbdomen=#if (BM_Abdomen_Mass>0)
                            blob{
                             	threshold BM_Build
                             	// main 
                             	cylinder { <0,0.5,0>, <0,0.95,0>, 1, 1 scale <1.05, 0.95, 0.85> }
                             	// 
                             	sphere { 0, 1, 1 scale < 1.15, 0.75, 0.55> translate <0, 0.3, 0.0> }
                             	sphere { 0, 1, 1 scale <0.5, 0.8, 0.5 > translate <0, 0, 0 > }
                             	sphere { 0, 1,-.5 scale <.75,.75,.8> translate <.65,-.3,.75> }
                             	sphere { 0, 1,-.5 scale <.75,.75,.8> translate <-.65,-.3,.75>}
                                // Navel
                                #if (BM_Navel<0)
                                    sphere {0,.3,-1 scale <.14,.1,2.1> translate <0,1, -.7> }
                                #end
                                #if (BM_Navel>0)
                                    sphere {0,.3,1 scale <.14,.14,.14> translate <0,1, -.45> }
                                #end                                
                          	
                             	
                             	scale <1.15, 1.2, 1.2>
                                scale <7,7,7>
                                translate y*-30
                                
                            }
                         #end
                         #if (BM_Abdomen_Mass=0)   
                            object {BM_nul}
                         #end
                         #if (BM_Abdomen_Mass<0)
                             // Object Guides
                                 blob {
                                     threshold BM_Build-.3
                                      #local Loop=-21;
                                      #while (Loop>-27)
                                          sphere{0,BM_Guide_Rad,2 translate<0,Loop-3,sin((Loop+2)*pi/(4+abs(Loop)/4))*(.25+abs(Loop/15))+1+Hips.z>
                                          }
                                          #local Loop=Loop-1;
                                      #end
                                      cylinder{<-Hips.x-BM_Guide_Rad,Hips.y-27,Hips.z-1>,<Hips.x+BM_Guide_Rad,Hips.y-27,Hips.z-1>,BM_Guide_Rad,2 }
                                          
                                }
                         #end

    #local MaleAbdomen=object {#if (BM_Abdomen_Mass>0)
                              blob {
                                  threshold BM_Build-.3
                              // Spine
                                  #local Loop=-17;
                                  #while (Loop>-29)
                                      sphere{0,2*.75,2 translate<0,Loop-3,sin((Loop+2)*pi/(4+abs(Loop)/4))*(.25+abs(Loop/15))+.75>}
                                      #if (mod(Loop+2,3)=0)
                                          sphere{0,.5*.75,1 translate<0,Loop-3,sin((Loop+2)*pi/(4+abs(Loop)/4))*(.25+abs(Loop/15))+1>}
                                      #end
                                      #local Loop=Loop-1;
                                  #end
                                  sphere{0,3,1   scale <1.5,2,1.2>   rotate <(BM_Torso_Rot.x)*BM_Flex,0,0>  translate < 2.8,-19,(BM_Torso_Rot.x/100)*BM_Flex> rotate <0,(BM_Torso_Rot.y/1.5)*BM_Flex,0>}
                                  sphere{0,3,1   scale <1.5,2,1.2>   rotate <(BM_Torso_Rot.x)*BM_Flex,0,0> translate <-2.8,-19,(BM_Torso_Rot.x/100)*BM_Flex> rotate <0,(BM_Torso_Rot.y/1.5)*BM_Flex,0>}
                                  // Abdomen
                                  //Left
                                  sphere{0,3,1 scale <1.5,1.5,.6>  rotate x*-20 rotate z*-45 translate < 3,-25.5,1.9>}
                                  sphere{0,3,1 scale <.8,1.5,.5>  rotate x*-10 rotate y*90 translate < 5.4,-25,0>}
                                  sphere{0,3,1 scale <1.5,1.5,1 >   translate < 2.5,-24,0>}
                                  sphere{0,3,2 scale <1,1,1>        translate < 1.5,-17.5,-1.5+BM_Torso_Rot.x/60> rotate <0,(BM_Torso_Rot.y/1.3)*BM_Flex,0>}
                                  sphere{0,3,2 scale <1,1,1.2>      translate < 1.5,-20,-1.25> rotate <0,(BM_Torso_Rot.y/1.2)*BM_Flex,0>}
                                  sphere{0,3,2 scale <1,1.2,1.2>    translate < 1.5,-22.5,-1.25> rotate <0,(BM_Torso_Rot.y/1.1)*BM_Flex,0>}
                                  sphere{0,3,2 scale <1,1,1.2>      translate < 1.5,-25,-1> rotate <0,(BM_Torso_Rot.y/1.05)*BM_Flex,0>}
                                  //Right
                                  sphere{0,3,1 scale <1.5,1.5,.6> rotate x*-20 rotate z*45 translate <-3,-25.5,1.9>}
                                  sphere{0,3,1 scale <.8,1.7,.5>  rotate x*-10 rotate y*-90 translate < -5.4,-25,0>}
                                  sphere{0,3,1 scale <1.5,1.5,1 >   translate <-2.5,-24,0>}
                                  sphere{0,3,2 scale <1,1,1>        translate <-1.5,-17.5,-1.5+BM_Torso_Rot.x/60> rotate <0,(BM_Torso_Rot.y/1.3)*BM_Flex,0>}
                                  sphere{0,3,2 scale <1,1,1.2>      translate <-1.5,-20,-1.25> rotate <0,(BM_Torso_Rot.y/1.2)*BM_Flex,0>}
                                  sphere{0,3,2 scale <1,1.2,1.2>    translate <-1.5,-22.5,-1.25> rotate <0,(BM_Torso_Rot.y/1.1)*BM_Flex,0>}
                                  sphere{0,3,2 scale <1,1,1.2>      translate <-1.5,-25,-1> rotate <0,(BM_Torso_Rot.y/1.05)*BM_Flex,0>}
                                  
                                  // Pelvis
                                  sphere{0,5,2 scale <1.2,1.4,1>  translate<0,-27,-.5> } //Front & Back
                                  // Left
                                  sphere{0,3,1 scale <1.4,.8,1.5> rotate z* 75 translate< 4,-28,-.5>}
                                  // Right
                                  sphere{0,3,1 scale <1.4,.8,1.5> rotate z*-75 translate<-4,-28,-.5>}
                                  // Navel
                                  #if (BM_Navel<0)
                                      sphere {0,.75,-1 scale <1,.75,3> translate <0,-22, -5.25> }
                                  #end
                                  #if (BM_Navel>0)
                                      sphere {0,.6,1 scale <1,1,2> translate <0,-22, -3.15> }
                                  #end
                                  
                              }   
                         #end
                         #if (BM_Abdomen_Mass=0)
                             object {BM_nul}
                         #end
                         #if (BM_Abdomen_Mass<0)
                         // Object Guides
                             blob {
                                 threshold BM_Build-.3
                                  #local Loop=-21;
                                  #while (Loop>-27)
                                      sphere{0,BM_Guide_Rad,2 translate<0,Loop-3,sin((Loop+2)*pi/(4+abs(Loop)/4))*(.25+abs(Loop/15))+1+Hips.z>}
                                      #local Loop=Loop-1;
                                  #end
                                  cylinder{<-Hips.x-BM_Guide_Rad,Hips.y-31,Hips.z-1>,<Hips.x+BM_Guide_Rad,Hips.y-31,Hips.z-1>,BM_Guide_Rad,2 }
                             }
                         #end
                    }        

// Build the Torso
    union {
            union {
                    union {
                        #if (BM_Gender=0)
                            object {HalfMaleTorso scale <1,1,1.15> }
                            object {HalfMaleTorso scale<-1,1,1.15> }
                            // Neck
                            union {
                                #if (BM_Neck_Mass>=1)
                                    blob {
                                    	threshold BM_Build
                                    	cylinder { <0,0,0>, <0,0.6,0>, 0.6, 1
                                    		scale <.9, 1.5, 0.7> rotate -5*x translate 0.15*z}
                                    	cylinder { <0,0,0>, <0,0.6,0>, 0.4, 1
                                    		scale <.85, 1.5, 0.7> translate -0.085*z }
                                    	sphere {<0,1,0>,1,-2} 
                                    	scale 7
                                    	scale <1,1,.85> 
                                    }
                                #end
                                #if (BM_Neck_Mass=0)
                                    object {BM_nul}
                                #end
                                #if (BM_Neck_Mass<0)
                                    blob {
                                    	threshold BM_Build
                                    	cylinder { <0,0,0>, <0,0.6,0>, BM_Guide_Rad, 1
                                    		rotate -5*x translate 0.15*z}
                                    }
                                #end                              
                            	object {BM_Neck_Object}
                                material {
                                    #ifdef (BM_Neck_Tex)
                                        texture {BM_Neck_Tex}
                                    #else
                                        texture {BM_Skin_Tex}
                                    #end
                                    #ifdef (Neck_IMap)
                                        texture {
                                            pigment {
                                                image_map {
                                                    png Neck_IMap
                                                    map_type 2
                                                    interpolate 4
                                                    once
                                                } 
                                                rotate y*-90
                                                scale 40
                                                translate <0,-40,0>
                                            }
                                            #ifdef (BM_Map_Finish)
                                                finish {BM_Map_Finish}
                                            #end
                                            #ifdef (BM_Map_Normal)
                                                normal {BM_Map_Normal}
                                            #end
                                            #ifdef (Neck_BMap)
                                                normal {
                                                    bump_map {
                                                        png Neck_BMap
                                                        map_type 2
                                                        interpolate 4
                                                        once
                                                        bump_size Bump_Map_Size
                                                    }
                                                    rotate y*-90
                                                    scale 40
                                                    translate <0,-40,0>
                                                }
                                            #end
                                        }
                                    #end
                                }
                            	transform NeckTrans
                            	translate y*-6 
                            	translate z*.75                                
                            }                            	
                        #end
                        #if (BM_Gender=1)
                            object {HalfFemaleTorso }
                            object {HalfFemaleTorso scale<-1,1,1> }
                            // Neck
                            union {
                                #if (BM_Neck_Mass>=1)
                                    blob {
                                    	threshold BM_Build
                                    	cylinder { <0,0,0>, <0,0.6,0>, 0.6, 1
                                    		scale <.9, 1.5, 0.7> rotate -5*x translate 0.15*z}
                                    	cylinder { <0,0,0>, <0,0.6,0>, 0.4, 1
                                    		scale <.85, 1.5, 0.7> translate -0.085*z }
                                    	sphere {<0,1,0>,1,-2}
                                    	scale 7
                                    	scale <1,1,.85>*.9
                                    }
                                #end
                                #if (BM_Neck_Mass=0)
                                    object {BM_nul}
                                #end
                                #if (BM_Neck_Mass<0)
                                    blob {
                                    	threshold BM_Build
                                    	cylinder { <0,0,0>, <0,0.6,0>, BM_Guide_Rad, 1
                                    		rotate -5*x translate 0.15*z}
                                    }
                                #end                                        
                                object {BM_Neck_Object}  
                                material {
                                    #ifdef (BM_Neck_Tex)
                                        texture {BM_Neck_Tex}
                                    #else
                                        texture {BM_Skin_Tex}
                                    #end
                                    #ifdef (Neck_IMap)
                                        texture {
                                            pigment {
                                                image_map {
                                                    png Neck_IMap
                                                    map_type 2
                                                    interpolate 4
                                                    once
                                                } 
                                                rotate y*-90
                                                scale 40
                                                translate <0,-40,0>
                                            }
                                            #ifdef (BM_Map_Finish)
                                                finish {BM_Map_Finish}
                                            #end
                                            #ifdef (BM_Map_Normal)
                                                normal {BM_Map_Normal}
                                            #end
                                            #ifdef (Neck_BMap)
                                                normal {
                                                    bump_map {
                                                        png Neck_BMap
                                                        map_type 2
                                                        interpolate 4
                                                        once
                                                        bump_size Bump_Map_Size
                                                    }
                                                    rotate y*-90
                                                    scale 40
                                                    translate <0,-40,0>
                                                }
                                            #end
                                        }
                                    #end
                                }
                            	
                            	transform NeckTrans
                            	translate y*-6 
                            	translate z*.75
                            }

                        #end                
                        object {BM_Torso_Object}
            //Material
                        material {
                            #ifdef (BM_Torso_Tex)
                                texture {BM_Torso_Tex}
                            #else
                                texture {BM_Skin_Tex}
                            #end
                            #ifdef (Torso_IMap)
                                texture {
                                    pigment {
                                        image_map {
                                            png Torso_IMap
                                            map_type 2
                                            interpolate 4
                                            once
                                        } 
                                        rotate y*-90
                                        scale 40
                                        translate <0,-40,0>
                                    }
                                    #ifdef (BM_Map_Finish)
                                        finish {BM_Map_Finish}
                                    #end
                                    #ifdef (BM_Map_Normal)
                                        normal {BM_Map_Normal}
                                    #end
                                    #ifdef (Torso_BMap)
                                        normal {
                                            bump_map {
                                                png Torso_BMap
                                                map_type 2
                                                interpolate 4
                                                once
                                                bump_size Bump_Map_Size
                                            }
                                            rotate y*-90
                                            scale 40
                                            translate <0,-40,0>
                                        }
                                    #end
                                }
                            #end
                        }
                    }
            //Arms
            // Upperarm - Right
                    union {
                            #if (BM_R_Upperarm_Mass> 0)
                                object {UpperArmModel}
                            #end
                            #if (BM_R_Upperarm_Mass= 0)
                                object {BM_nul}
                            #end
                            #if (BM_R_Upperarm_Mass< 0)
            // Object Guides
                                blob {
                                    threshold BM_Build-.3 
                                    cylinder{<0,0,0>,<0,-UpperarmLength,0>,BM_Guide_Rad,2}
                                }
                            #end
                        object {BM_Upperarm_R_Object}
                        material {
                            #ifdef (BM_Upperarm_R_Tex)
                                texture {BM_Upperarm_R_Tex}
                            #else
                                texture {BM_Skin_Tex}
                            #end
                            #ifdef (Upperarm_R_IMap)
                                texture {
                                    pigment {
                                        image_map {
                                            png Upperarm_R_IMap
                                            map_type 2 
                                            interpolate 4
                                            once
                                        }
                                        scale 20
                                        translate <0,-15,0>
                                    }
                                    #ifdef (BM_Map_Finish)
                                        finish {BM_Map_Finish}
                                    #end
                                    #ifdef (BM_Map_Normal)
                                        normal {BM_Map_Normal}
                                    #end
                                    #ifdef (Upperarm_R_BMap)
                                        normal {
                                            bump_map {
                                                png Upperarm_R_BMap
                                                map_type 2
                                                interpolate 4
                                                once
                                                bump_size Bump_Map_Size
                                            }
                                            scale 20
                                            translate <0,-15,0>
                                        }
                                    #end
                                }
                            #end
                        }
                        transform R_Upperarm
                    }
            // Upperarm - Left
                    union {
                            #if (BM_L_Upperarm_Mass> 0)
                                object {UpperArmModel scale <-1,1,1>}
                            #end
                            #if (BM_L_Upperarm_Mass= 0)
                                object {BM_nul}
                            #end
                            #if (BM_L_Upperarm_Mass<0)
            // Object Guides
                                blob {
                                    threshold BM_Build-.3
                                    cylinder{<0,0,0>,<0,-UpperarmLength,0>,BM_Guide_Rad,2}
                                }
                            #end
                        object {BM_Upperarm_L_Object}
                        material {
                            #ifdef (BM_Upperarm_L_Tex)
                                texture {BM_Upperarm_L_Tex}
                            #else
                                texture {BM_Skin_Tex}
                            #end
                            #ifdef (Upperarm_L_IMap)
                                texture {
                                    pigment {
                                        image_map {
                                            png Upperarm_L_IMap
                                            map_type 2 
                                            interpolate 4
                                            once
                                        } 
                                        rotate y*180
                                        scale 20
                                        translate <0,-15,0>
                                    }
                                    #ifdef (BM_Map_Finish)
                                        finish {BM_Map_Finish}
                                    #end
                                    #ifdef (BM_Map_Normal)
                                        normal {BM_Map_Normal}
                                    #end
                                    #ifdef (Upperarm_L_BMap)
                                        normal {
                                            bump_map {
                                                png Upperarm_L_BMap
                                                map_type 2
                                                interpolate 4
                                                once
                                                bump_size Bump_Map_Size
                                            }
                                            rotate y*180
                                            scale 20
                                            translate <0,-15,0>
                                        }
                                    #end
                                }
                            #end
                        }
                        transform L_Upperarm
                    }
            // Forearm - Right
                    union {
                            #if (BM_R_Forearm_Mass>0)
                                object {ForearmModel}
                            #end
                            #if (BM_R_Forearm_Mass=0)
                                object {BM_nul}
                            #end
                            #if (BM_R_Forearm_Mass<0)
            // Object Guides
                                blob {
                                    threshold BM_Build-.3
                                    cylinder{0,<0,-ForearmLength,0>,BM_Guide_Rad,2}
                                }
                            #end
                        object {BM_Forearm_R_Object}
                        material {
                            #ifdef (BM_Forearm_R_Tex)
                                texture {BM_Forerarm_R_Tex}
                            #else
                                texture {BM_Skin_Tex}
                            #end
                            #ifdef (Forearm_R_IMap)
                                texture {
                                    pigment {
                                        image_map {
                                        png Forearm_R_IMap
                                        map_type 2
                                        interpolate 4
                                        once
                                        }
                                        scale 15
                                        translate <0,-12,0>
                                    }
                                    #ifdef (BM_Map_Finish)
                                        finish {BM_Map_Finish}
                                    #end
                                    #ifdef (BM_Map_Normal)
                                        normal {BM_Map_Normal}
                                    #end
                                    #ifdef (Forearm_R_BMap)
                                        normal {
                                            bump_map {
                                                png Forearm_R_BMap
                                                map_type 2
                                                interpolate 4
                                                once
                                                bump_size Bump_Map_Size
                                            }
                                            scale 15
                                            translate <0,-15,0>
                                        }
                                    #end
                                }
                            #end
                        }
                        transform R_Forearm
                    }
            // Forearm - Left
                    union {
                            #if (BM_L_Forearm_Mass> 0)
                                object {ForearmModel scale <-1,1,1>}
                            #end
                            #if (BM_L_Forearm_Mass=0)
                                object {BM_nul}
                            #end
                            #if (BM_L_Forearm_Mass<0)
            // Object Guides
                                blob {
                                    threshold BM_Build-.3
                                    cylinder{0,<0,-ForearmLength,0>,BM_Guide_Rad,2}
                                }
                            #end
                    
                        object {BM_Forearm_L_Object}
                        material {
                            #ifdef (BM_Forerarm_L_Tex)
                                texture {BM_Forerarm_L_Tex}
                            #else
                                texture {BM_Skin_Tex}
                            #end
                            #ifdef (Forearm_L_IMap)
                                texture {
                                    pigment {
                                        image_map {
                                            png Forearm_L_IMap
                                            map_type 2
                                            interpolate 4
                                            once
                                        } 
                                        rotate y*180
                                        scale 15
                                        translate <0,-12,0>
                                    }
                                    #ifdef (BM_Map_Finish)
                                        finish {BM_Map_Finish}
                                    #end
                                    #ifdef (BM_Map_Normal)
                                        normal {BM_Map_Normal}
                                    #end
                                    #ifdef (Forearm_L_BMap)
                                        normal {
                                            bump_map {
                                                png Forearm_L_BMap
                                                map_type 2 
                                                interpolate 4
                                                once
                                                bump_size Bump_Map_Size
                                            }
                                            rotate y*180
                                            scale 15
                                            translate <0,-15,0>
                                        }
                                    #end
                                }
                            #end
                        }
                        transform L_Forearm
                    }
                transform TorsoTrans
            }                              
// Abdomen              
            union { #if (BM_Gender=0)
                        object {MaleAbdomen}
                    #end
                    #if (BM_Gender=1)
                        object {FemaleAbdomen scale <1,1,.95> translate <0,0,-.5>}
                    #end
                    object {BM_Abdomen_Object}
                    
//Material
                    material {
                            #ifdef (BM_Abdomen_Tex)
                                texture {BM_Abdomen_Tex}
                            #else
                                texture {BM_Skin_Tex}
                            #end
                        #ifdef (Abdomen_IMap)
                            texture {
                                pigment {
                                    image_map {
                                        png Abdomen_IMap
                                        map_type 2
                                        interpolate 4
                                        once
                                    } 
                                    rotate y*-90
                                    scale 40
                                    translate <0,-40,0>
                                }
                                #ifdef (BM_Map_Finish)
                                    finish {BM_Map_Finish}
                                #end
                                #ifdef (BM_Map_Normal)
                                    normal {BM_Map_Normal}
                                #end
                                #ifdef (Abdomen_BMap)
                                    normal {
                                        bump_map {
                                            png Abdomen_BMap
                                            map_type 2
                                            interpolate 4
                                            once
                                            bump_size BM_Bump_Map_Size
                                        }
                                        rotate y*-90
                                        scale 40
                                        translate <0,-40,0>
                                    }
                                #end
                            }
                        #end
                    }
         
         }
// Right Leg
         union {
         // Thigh - Right
                union {
                        #if (BM_R_Thigh_Mass> 0)
                            object {ThighModel scale <-1,1,1>}
                        #end
                       #if (BM_R_Thigh_Mass= 0)
                            object {BM_nul}
                        #end
                        #if (BM_R_Thigh_Mass< 0)
        // Object Guides
                            blob{
                                threshold BM_Build-.3
                                cylinder{<-Hips.x,0,0>,<0,-ThighLength,0>,BM_Guide_Rad,2}
                            }
                        #end
                    object {BM_Thigh_R_Object}
                    material {
                        #ifdef (BM_Thigh_R_Tex)
                            texture {BM_Thigh_R_Tex}
                        #else
                            texture {BM_Skin_Tex}
                        #end
                        #ifdef (Thigh_R_IMap)
                            texture {
                                pigment {
                                    image_map {
                                        png Thigh_R_IMap
                                        map_type 2 
                                        interpolate 4
                                        once
                                    }
                                    rotate y*-90
                                    scale 25
                                    translate <0,-17.5,0>
                                }
                                #ifdef (BM_Map_Finish)
                                    finish {BM_Map_Finish}
                                #end
                                #ifdef (BM_Map_Normal)
                                    normal {BM_Map_Normal}
                                #end
                                #ifdef (Thigh_R_BMap)
                                    normal {
                                        bump_map {
                                            png Thigh_R_BMap
                                            map_type 2 
                                            interpolate 4
                                            once
                                            bump_size Bump_Map_Size
                                        }
                                        rotate y*-90
                                        scale 25
                                        translate <0,-17.5,0>
                                    }
                                #end
                            }
                        #end
                    }
                    transform R_Thigh
                }
        // Calf - Right
                union {
                        #if (BM_R_Calf_Mass>0)
                            object {CalfModel}
                        #end
                        #if (BM_R_Calf_Mass=0)
                            object {BM_nul}
                        #end
                        #if (BM_R_Calf_Mass<0)
        // Object Guides    
                            blob{
                                threshold BM_Build-.3
                                cylinder{<0,0,0>,<0,-CalfLength,0>,BM_Guide_Rad,2}
                            }
                        #end
                    object {BM_Calf_R_Object}
                    material {
                        #ifdef (BM_Calf_R_Tex)
                            texture {BM_Calf_R_Tex}
                        #else
                            texture {BM_Skin_Tex}
                        #end
                        #ifdef (Calf_R_IMap)
                            texture {
                                pigment {
                                    image_map {
                                        png Calf_R_IMap
                                        map_type 2
                                        interpolate 4
                                        once
                                    } 
                                    rotate y*-90
                                    scale 25
                                    translate <0,-20,0>
                                }
                                #ifdef (BM_Map_Finish)
                                    finish {BM_Map_Finish}
                                #end
                                #ifdef (BM_Map_Normal)
                                    normal {BM_Map_Normal}
                                #end
                                #ifdef (Calf_R_BMap)
                                    normal {
                                        bump_map {
                                            png Calf_R_BMap
                                            map_type 2
                                            interpolate 4
                                            once
                                            bump_size Bump_Map_Size
                                        }
                                        rotate y*-90
                                        scale 25
                                        translate <0,-20,0>
                                    }
                                #end
                            }
                        #end
                    }
                    transform R_Calf
                }
                transform R_Leg
        }
// Thigh - Left
        union {
                union {
                        #if (BM_L_Thigh_Mass>0)
                            object {ThighModel}
                        #end
                        #if (BM_L_Thigh_Mass=0)
                            object {BM_nul}
                        #end
                        #if (BM_L_Thigh_Mass<0)
        // Object Guides
                            blob{
                                threshold BM_Build-.3
                                cylinder{<Hips.x,0,0>,<0,-ThighLength,0>,BM_Guide_Rad,2}
                            }
                        #end
                    object {BM_Thigh_L_Object}
                    material {
                        #ifdef (BM_Thigh_L_Tex)
                            texture {BM_Thigh_L_Tex}
                        #else
                            texture {BM_Skin_Tex}
                        #end
                        #ifdef (Thigh_L_IMap)
                            texture {
                                pigment {
                                    image_map {
                                        png Thigh_L_IMap
                                        map_type 2 
                                        interpolate 4
                                        once
                                    } 
                                    rotate y*-90
                                    scale 25
                                    translate <0,-17.5,0>
                                }
                                #ifdef (BM_Map_Finish)
                                    finish {BM_Map_Finish}
                                #end
                                #ifdef (BM_Map_Normal)
                                    normal {BM_Map_Normal}
                                #end
                                #ifdef (Thigh_L_BMap)
                                    normal {
                                        bump_map {
                                            png Thigh_L_BMap
                                            map_type 2 
                                            interpolate 4
                                            once
                                            bump_size Bump_Map_Size
                                        }
                                        rotate y*-90
                                        scale 25
                                        translate <0,-17.5,0>
                                    }
                                #end
                            }
                        #end
                    }
                    transform L_Thigh
                }
        
        // Calf - Left
                union {
                        #if (BM_L_Calf_Mass>0)
                            object {CalfModel scale <-1,1,1>}
                        #end
                        #if (BM_L_Calf_Mass=0)
                            object {BM_nul}
                        #end
                        #if (BM_L_Calf_Mass<0)
        // Object Guides    
                            blob{
                                threshold BM_Build-.3
                                cylinder{<0,0,0>,<0,-CalfLength,0>,BM_Guide_Rad,2}
                            }
                        #end
                    object {BM_Calf_L_Object}
                    material {
                        #ifdef (BM_Calf_L_Tex)
                            texture {BM_Calf_L_Tex}
                        #else
                            texture {BM_Skin_Tex}
                        #end
                        #ifdef (Calf_L_IMap)
                            texture {
                                pigment {
                                    image_map {
                                        png Calf_L_IMap
                                        map_type 2 
                                        interpolate 4
                                        once
                                    } 
                                    rotate y*-90
                                    scale 25
                                    translate <0,-20,0>
                                }
                                #ifdef (BM_Map_Finish)
                                    finish {BM_Map_Finish}
                                #end
                                #ifdef (BM_Map_Normal)
                                    normal {BM_Map_Normal}
                                #end
                                #ifdef (Calf_L_BMap)
                                    normal {
                                        bump_map {
                                            png Calf_L_BMap
                                            map_type 2 
                                            interpolate 4
                                            once
                                            bump_size Bump_Map_Size
                                        }
                                        rotate y*-90
                                        scale 25
                                        translate <0,-20,0>
                                    }
                                #end
                            }
                        #end
                    }
                    transform L_Calf
                }
                transform L_Leg
            }
            
        }
//Origin Variables before Scale Applied
    #local ReverseTorso=transform {translate <0,20,0> rotate <0,-BM_Torso_Rot.y,0> translate <0,-20,0>
                                   translate <0,20,-3> rotate <-BM_Torso_Rot.x,0,-BM_Torso_Rot.z> translate <0,-20,3>
                                  }
    #declare BMOKR=transform {translate <Hips.x,31-Hips.y,Hips.z-1>-R_Knee}
    #declare BMOKL=transform {translate <-Hips.x,31-Hips.y,Hips.z-1>-L_Knee}

    #declare BMOAF=transform {translate <0,29,4.5-(BM_Gender/4)>}
    #declare BMOAB=transform {translate <0,29,-4.5+(BM_Gender/1.5)>}
    #declare BMOAR=transform {translate <5+(BM_Gender/2)+Hips.x,27,0>}
    #declare BMOAL=transform {translate <-(5+(BM_Gender/2)+Hips.x),27,0>}
    #if (BM_Gender=0)
        #declare BMOKR=transform {translate <Hips.x,31-Hips.y,Hips.z-1>-R_Knee}
        #declare BMOKL=transform {translate <-Hips.x,31-Hips.y,Hips.z-1>-L_Knee}
        #declare BMOHR=transform {translate <Hips.x+3,31-Hips.y,Hips.z>}
        #declare BMOHL=transform {translate <-Hips.x-3,31-Hips.y,Hips.z>}
        #declare BMOAU=transform {translate <0,34.75-Hips.y,0>}
        #declare BMOTF=transform {transform ReverseTorso translate <0,13.5,4.25>}
        #declare BMOTR=transform {transform ReverseTorso 
                                  translate <8,13.5,0>
                                  rotate z*-15
                                  translate <-.35,0,0>
                                 } 
        #declare BMOTL=transform {transform ReverseTorso 
                                  translate <-8,13.5,0>
                                  rotate z*15
                                  translate <.35,0,0>
                                 }                                 
                                  
        #declare BMOTB=transform {transform ReverseTorso
                                  translate <0,13.5,-5.5>
                                  rotate x*-20
                                 }                             
        #declare BMOTT=transform {transform ReverseTorso
                                  translate <0,8,-3.5>
                                 }                                 
    #end
    #if (BM_Gender=1)
        #declare BMOKR=transform {translate <Hips.x,27-Hips.y,Hips.z-1>-R_Knee}
        #declare BMOKL=transform {translate <-Hips.x,27-Hips.y,Hips.z-1>-L_Knee}
        #declare BMOHR=transform {translate <Hips.x+3,27-Hips.y,Hips.z>}
        #declare BMOHL=transform {translate <-Hips.x-3,27-Hips.y,Hips.z>}
        #declare BMOAU=transform {translate <0,30.5-Hips.y,0>}
        #declare BMOTF=transform {transform ReverseTorso translate <0,14.5,5.5>}                                                            
        #declare BMOTR=transform {transform ReverseTorso 
                                  translate <7,13.5,0>
                                  rotate z*-15
                                  translate <-.35,0,0>
                                 } 
        #declare BMOTL=transform {transform ReverseTorso 
                                  translate <-7,13.5,0>
                                  rotate z*15
                                  translate <.35,0,0>
                                 } 
        #declare BMOTB=transform {transform ReverseTorso
                                  translate <0,10,-4.5>
                                  rotate x*-9
                                 }
        #declare BMOTT=transform {transform ReverseTorso
                                  translate <0,6.5,-3.5>
                                 }
    #end
    #declare BMOSR=transform {transform ReverseTorso translate < Shoulder.x,UpperarmLength-Shoulder.y,-1-Shoulder.z>}
    #declare BMOSL=transform {transform ReverseTorso translate <-Shoulder.x,UpperarmLength-Shoulder.y,-1-Shoulder.z>}
    #declare BMOER=transform {transform ReverseTorso translate < Shoulder.x,UpperarmLength-Shoulder.y,-1-Shoulder.z>-R_Elbow}
    #declare BMOEL=transform {transform ReverseTorso translate <-Shoulder.x,UpperarmLength-Shoulder.y,-1-Shoulder.z>-L_Elbow}
#end     

// End of Torso Macro