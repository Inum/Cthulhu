/****************************************************************
Hand Macro for use with "bmpeople.inc" v4.0
refer to "bmmanual.txt" for usage information
*******************************************************************/
#ifndef (BM_Defaults) 
    #include "bmdefs.inc"
#end

#macro bmhand(Hand)
    #if (Hand>0)
        #local H_S2E=BM_LA_S2E;
        #local H_E2W=BM_LA_E2W;
        #local Hand_Rot=BM_LH_Rot;
        #local FP_Pos=BM_LFP_Pos;
        #local FR_Pos=BM_LFR_Pos;
        #local FM_Pos=BM_LFM_Pos;
        #local FI_Pos=BM_LFI_Pos;
        #local FT_Pos=BM_LFT_Pos;
    #else
        #local H_S2E=BM_RA_S2E;
        #local H_E2W=BM_RA_E2W;
        #local Hand_Rot=BM_RH_Rot;
        #local FP_Pos=BM_RFP_Pos;
        #local FR_Pos=BM_RFR_Pos;
        #local FM_Pos=BM_RFM_Pos;
        #local FI_Pos=BM_RFI_Pos;
        #local FT_Pos=BM_RFT_Pos;
    #end
    
    #if (BM_Gender=0)
        #local UpperarmLength= 11;
        #local ForearmLength = 10.5;
        #local Shoulder      = <8.25,1.5,0>;
    #end
    #if (BM_Gender=1)
        #local UpperarmLength= 10.85;
        #local ForearmLength = 10.5;
        #local Shoulder      = <6.25,1.5,.2>;
    #end
    
    #local H_Elbow=vrotate(<0,-UpperarmLength,0>,H_S2E);
    #local H_Wrist=vrotate(<0,-ForearmLength-.75,0> ,H_E2W);
    #local Hand_Trans=transform {rotate y*(90*Hand) rotate Hand_Rot rotate H_E2W translate H_Elbow+H_Wrist+<Shoulder.x*Hand,-UpperarmLength+Shoulder.y,Shoulder.z+1>}
    #local TorsoTrans=transform {translate <0,20,-3> rotate <BM_Torso_Rot.x,0,BM_Torso_Rot.z> translate <0,-20,3>
                                 translate <0,20,0>  rotate <0,BM_Torso_Rot.y,0> translate <0,-20,0>
                      }

    #if (Hand=-1)
        #local TempHand=BM_R_Hand;
    #else
        #local TempHand=BM_L_Hand;
    #end
   
    #local Finger_Joint_angle =
		array[5][4]
		{
			{FT_Pos.x,FT_Pos.y,FT_Pos.z,FT_Pos.t}, // 1st finger
			{FI_Pos.x,FI_Pos.y,FI_Pos.z,FI_Pos.t}, // 2nd finger
			{FM_Pos.x,FM_Pos.y,FM_Pos.z,FM_Pos.t}, // 3rd finger
			{FR_Pos.x,FR_Pos.y,FR_Pos.z,FR_Pos.t}, // 4th finger
			{FP_Pos.x,FP_Pos.y,FP_Pos.z,FP_Pos.t}  // 5th finger
		}

	#declare Finger_N = 1;
    union {
        union {
            #if (TempHand>=1)
        	    blob {   
        	    // part of palm
        		// palm length = 1
            		threshold BM_Build+.1
            		cylinder{<-0.3, 0.2, 0.00>, <-0.3, 0.85, 0.00>, 0.3, 1 scale <1,1,0.8>}
            		cylinder{<-0.2, 0.1, 0.05>, <-0.2, 0.90, 0.05>, 0.3, 1 scale <1,1,0.8>}
            		cylinder{<-0.1, 0.0 ,0.10>, <-0.1, 0.95, 0.10>, 0.3, 1 scale <1,1,0.8>}
            		cylinder{< 0.0, 0.0, 0.15>, < 0.1, 0.90, 0.15>, 0.3, 1 scale <1,1,0.8>} // palm center
            		cylinder{< 0.10, 0.00, 0.15>, < 0.10, 0.90, 0.15>, 0.30, 1 scale <1,1,0.8>}
            		cylinder{< 0.15, 0.10, 0.05>, < 0.20, 0.87, 0.0>, 0.30, 1 scale <1,1,0.8>}
            		cylinder{< 0.25, 0.05, 0.00>, < 0.35, 0.85, -0.025>, 0.30, 1 scale <1,1,0.8>}
            		cylinder{< 0.25, 0.15, 0.0>, < 0.40, 0.70, -0.05>, 0.28, 1 scale <1,1,0.8>}
            		cylinder{< 0.60, 0.40, 0.0>, < 0.75, 0.70, -0.1>, 0.28, 1 scale <0.6,1,0.8> }
        		//
            		sphere{<0, 0, 0>, 0.5, 1 // rize of 5th finger side
            			scale <0.6, 1.2, 0.5>
            			rotate -15*z
            			translate <0.15, 0.25, -0.10> 
            			
            		}
        		//
            		sphere{<0, 0, 0>, 0.4, 1 // rize of 1st finger side
            			scale <0.70, 1.0, 0.7>
            			rotate 30*z
            			translate <-0.15, 0.15, -0.10>
            		}
            		sphere { <-0.15, 0.15, -0.05>, 0.4, 1 scale <1,1, 0.6>}
        		
        		// finger 1 of first finger
            		cylinder { <-0.3, 0.1, 0>, <-0.45, 0.3, -0.25>,0.33, 1  
        	    		rotate <Finger_Joint_angle[0][3], -Finger_Joint_angle[0][0], 0>
        		    }
        	    }
        	//---------- finger 2 & 3 of 1st finger
            	object {
            		union{ // finger2
            			blob {
            				threshold BM_Build+.1
            				cylinder { <0, 0, 0 >, <0, 0.20, 0>, 0.30, 1 scale <1, 1, 1> }
            				sphere { <0,0,0>, 0.12, 1.5 scale < 1.2, 1.0, 0.8> translate <0, 0.26, 0.05> }
            			}
            			union { // finger3
            				blob {
            					threshold BM_Build+.1
            					cylinder { <0, 0, 0>, <0, 0.20, 0>, 0.26, 1 scale <0.9, 1, 0.9> }
            					sphere { <0,0,0>, 0.2, 1 scale <1.0, 1.3, 0.9> translate <0, 0.02, -0.02> }
            				}
            				// Nail
                            #if (BM_Nails=1)
                				difference {
                					cylinder { <0,0,0> <0,0.23, 0> 0.11 }
                					cylinder { <0,-0.1,0> <0,0.24, 0> 0.105 }
                					plane { z, 0.06 }
                					plane { -y, 0 rotate -50*x translate 0.08*y }
                                    #if (BM_Gender=0)
                  					    scale <1,.5,0.8>
                					#else
                					    scale <1,1,0.8>
                					#end
                					rotate -5*x
                					translate <0,0.15,0.045>
                					texture { BM_Nail_Tex }
                				}                                      
                            #else
                                object {BM_nul}
                            #end                				
            				rotate <-10-Finger_Joint_angle[0][2], 0, 0>
            				translate <0, 0.35, 0.0> // 3rd finger joint point
            			}
            			rotate <-15-Finger_Joint_angle[0][1], 0, 15>
            			translate < 0.0, 0.40, 0.0> // 2nd finger joint point
            		}
            		rotate -90*y
            		rotate 30*z
            		rotate -20*x
            		translate <-0.3, 0.05, -0.2>
            		rotate <Finger_Joint_angle[0][3], -Finger_Joint_angle[0][0], 0>
    	    		#if (Hand=-1)
    	    		    #if (BM_Map_R_Finger=0)
    	    		        texture {BM_Skin_Tex}
    	    		    #end
    	    		#else
    	    		    #if (BM_Map_L_Finger=0)
                            texture {BM_Skin_Tex}
    	    		    #end
    	    		#end            		
            	}
            
            	// Parts form 2nd to 5th finger
            	#while ( Finger_N < 5 )
            	// define finger
            	union {
            		blob { // finger 1
            			threshold BM_Build+.1
            			cylinder { <0,0,0>, <0,0.40,0>, 0.3, 1
                			#if (Hand=-1)
            	    		    #if (BM_Map_R_Finger=0)
            	    		        texture {BM_Skin_Tex}
            	    		    #end
            	    		#else
            	    		    #if (BM_Map_L_Finger=0)
                                    texture {BM_Skin_Tex}
            	    		    #end
            	    		#end 
        	    		 }
            			sphere { < 0,0,0 >, 0.20, 1 scale < 0.7, 1, 1.0> translate 0.01*z}
            			sphere { < 0,0,0 >, 0.10, 1 scale < 1.2, 1, 0.6> translate <0, 0.46, 0.08>}
            			
            		}
            		union { // finger 2
            			blob {
            				threshold BM_Build+.1
            				cylinder { <0,0,0>, <0,0.25,0>, 0.28, 1 }
            				sphere { < 0,0,0 >, 0.10, 1 scale < 1.2, 1, 0.6> translate <0, -0.01, 0.08>}
            				sphere { < 0,0,0 >, 0.10, 1 scale < 1.2, 1, 0.6> translate <0, 0.26, 0.08>} 
            			}
            			union{ // finger 3
            				blob{
            					threshold 0.6
            					cylinder { <0,0,0>, <0,0.25,0>, 0.26, 1 }
            					sphere { <0,0,0>, 0.12, 1 scale < 1, 1.2, 1> translate <0,0.30,0.01> }
            					sphere { < 0,0,0 >, 0.10, 1 scale < 1.2, 1, 0.6> translate <0, -0.01, 0.08>}
            				}
            				// Nail
                            #if (BM_Nails=1)
                				difference {
                					cylinder { <0,0,0> <0,0.30, 0> 0.11 }
                					cylinder { <0,-0.1,0> <0,0.31, 0> 0.105 }
                					plane { z, 0.06 }
                					plane { -y, 0 rotate -50*x translate 0.14*y }
                					#if (BM_Gender=0)
                					    scale <1,.5,0.8>
                					#else
                					    scale <1,1,0.8>
                					#end
                					translate <0,0.15,0.04>
                					texture { BM_Nail_Tex }
                				}          
                		    #else
                		        object {BM_nul}
                		    #end

            				rotate <-Finger_Joint_angle[Finger_N][2], 0, 0 >
            				translate <0,0.3,0> // 3rd finger joitnt point
            			}
            			rotate <-Finger_Joint_angle[Finger_N][1], 0, 0 >
            			translate <0,0.40,0> // 2nd finger joitnt point
        	    		#if (Hand=-1)
        	    		    #if (BM_Map_R_Finger=0)
        	    		        texture {BM_Skin_Tex}
        	    		    #end
        	    		#else
        	    		    #if (BM_Map_L_Finger=0)
                                texture {BM_Skin_Tex}
        	    		    #end
        	    		#end            			
            		}
            		#switch ( Finger_N )
            			#case(1) scale 0.9 #break
            			#case(3) scale <0.85,0.90,0.85> #break
            			#case(4) scale <0.80,0.75,0.80> #break
            		#else
            		#end
            		rotate <-Finger_Joint_angle[Finger_N][0], 0, Finger_Joint_angle[Finger_N][3] >
            		#switch ( Finger_N )
            			#case(1) translate <-0.30, 0.95, 0.03> #break // 1st finger joitnt point of 2nd finger
            			#case(2) translate < 0.00, 1.00, 0.10> #break
            			#case(3) translate < 0.27, 0.95, 0.08> #break
            			#case(4) translate < 0.47, 0.75, -0.05> #break
            			#else
            		#end
            		#declare Finger_N = Finger_N + 1;
            	}
            	#end // while end
            #else
                object {BM_nul}
            #end
            scale <-Hand,-1,1>
            translate <0,0,.05*Hand>
            scale 3
        }    
        #if (Hand=-1)
// Right Hand Object
            object {BM_Hand_R_Object rotate y*(-90*Hand)}
        #else
// Left Hand Object
            object {BM_Hand_L_Object rotate y*(-90*Hand)}
        #end
        #if (BM_Gender=0)            
            scale <1,1,1.25>
            scale 1.1 
        #end

        #if (Hand=-1)
            material {
                #ifdef (BM_Hand_R_Tex)
                    texture {BM_Hand_R_Tex}
                #else
                    texture {BM_Skin_Tex}
                #end
                #ifdef (Hand_R_IMap)
                    texture {
                        pigment {
                            image_map {
                                png Hand_R_IMap
                                map_type 2 
                                interpolate 4
                                once
                            }
                            rotate y*90
                            scale 9.5
                            translate <0,-8.5,0>
                        }
                        #ifdef (BM_Map_Finish)
                            finish {BM_Map_Finish}
                        #end
                        #ifdef (BM_Map_Normal)
                            normal {BM_Map_Normal}
                        #end
                        #ifdef (Hand_R_BMap)
                            normal {
                                bump_map {
                                    png Hand_R_BMap
                                    map_type 2
                                    interpolate 4
                                    once
                                    bump_size BM_Bump_Map_Size
                                }
                                rotate y*90
                                scale 9.5
                                translate <0,-8.5,0>
                            }
                        #end
                    }
                #end
            }
        #else
            material {
                #ifdef (BM_Hand_L_Tex)
                    texture {BM_Hand_L_Tex}
                #else
                    texture {BM_Skin_Tex}
                #end
                #ifdef (Hand_L_IMap)
                    texture {
                        pigment {
                            image_map {
                                png Hand_L_IMap
                                map_type 2 
                                interpolate 4
                                once
                            } 
                            rotate y*-90
                            scale 9.5
                            translate <0,-8.5,0>
                        }
                        #ifdef (BM_Map_Finish)
                            finish {BM_Map_Finish}
                        #end
                        #ifdef (BM_Map_Normal)
                            normal {BM_Map_Normal}
                        #end
                        #ifdef (Hand_L_BMap)
                            normal {
                                bump_map {
                                    png Hand_L_BMap
                                    map_type 2 
                                    interpolate 4
                                    once
                                    bump_size BM_Bump_Map_Size
                                }
                                rotate y*-90
                                scale 9.5
                                translate <0,-8.5,0>
                            }
                        #end
                    }
                #end
            }
        #end
        transform Hand_Trans
        transform TorsoTrans
        
    }
// Origin Variables

    #local ReverseTorso=transform {translate <0,20,0> rotate <0,-BM_Torso_Rot.y,0> translate <0,-20,0>
                                   translate <0,20,-3> rotate <-BM_Torso_Rot.x,0,-BM_Torso_Rot.z> translate <0,-20,3>
                                  }
                               
    #if (Hand=-1)
        #declare BMOPR=transform {transform ReverseTorso
                                  translate -H_Elbow+-H_Wrist+<-Shoulder.x*Hand,UpperarmLength-Shoulder.y,-Shoulder.z+1>
                                  rotate -H_E2W
                                  rotate -Hand_Rot
                                  rotate y*-(270*Hand)     
                                  rotate x*-(90*Hand)
                                  rotate y*(25*Hand)
                                  translate y*.5
                                  translate x*-Hand
                                 }
    #else                                      
        #declare BMOPL=transform {transform ReverseTorso
                                  translate -H_Elbow+-H_Wrist+<-Shoulder.x*Hand,UpperarmLength-Shoulder.y,-Shoulder.z+1>
                                  rotate -H_E2W
                                  rotate -Hand_Rot
                                  rotate y*-(270*Hand)
                                  rotate x*(90*Hand)
                                  rotate y*(25*Hand)
                                  translate y*.5
                                  translate x*-Hand
                                 }
    #end                                      
    
#end                                            

// End of Hand Macro
