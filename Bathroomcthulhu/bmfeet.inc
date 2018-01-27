/****************************************************************
Feet Macro for use with "bmpeople.inc" v4.0
refer to "bmmanual.txt" for usage information
*******************************************************************/
#ifndef (BM_Defaults) 
    #include "bmdefs.inc"
#end

#macro FootModel (LR,ToeAng)
     union {
    	blob{
    		threshold BM_Build
    		cylinder { <0,0,0>,<0,.00001,0> 0.36, .75 // joint
    			scale <1, 0.8, .5>
    			translate <0.0, 0.08, -0.03>

    		}                                 
    		 /*
    		sphere { <0,0,0>, 0.36, -.75 // joint
    			scale <1, 1, 1.5>
    			translate <0.0, 0.1, 0.1>

    		} */    		
            /*
            sphere {0,.3,-.75 
    		    scale <2,1,1>
    		    translate <0,-.1,0> pigment {rgb x}
    		} 
    		*/
            cylinder { <-.1,.05,-.1>,<.1,.05,-.15>,.1,1 }
    		cylinder { <0, 0, -0.1>, <0, .1, -0.25>, 0.4, 1 //
    			scale <0.6,0.6, 1>
    			translate <-0.01, 0, 0>    
    		}
    		cylinder { <0, 0, -0.05>, <0, 0, -0.45>, 0.3, 1
    			scale <0.9,0.7, 1>
    			translate <0.05, -0.08, 0>  
    		}
    		cylinder { <0, 0, -0.5>, <0, 0, -0.75>, 0.3, 1 // side
    			scale <0.9, 0.5, 1>
    			translate <0.15, -0.15, 0>  
    		}

    		cylinder { <0, 0, -0.15>, <0, 0, -0.65>, 0.4, 1 // bottom & heel
    			scale <0.9,0.55, 1>
    			translate <0, -0.17,0>    
    		}        
                   
   		                              
    		sphere { 0,.1, 1 
    		    scale <1,1,1.5> 
    		    translate <-0.12, -.21, -0.8>
    		}  
    		sphere { 0,.1, 1 
    		    scale <1,1,1.5>  
    		    translate <0.01, -.22, -0.8>
    		}   
            sphere { 0,.1, 1 
    		    scale <1,1,1.5>  
    		    translate <0.12, -.22, -0.8>
    		}
            sphere { <0,0,0>,.1, 1 
    		    scale <1,1,1.5>  
    		    translate <0.22, -.2, -0.8>
    		}
    		sphere { 0,.1, 1 
    		    scale <1,1,1.5>
    		    translate <0.28, -.18, -0.8> 
    	    }
    	    // Heel
    	    cylinder {<0,0,0>,<0,.4,0>,.3,.5 
    	        scale <1,.5,1>
    	        rotate x*-15
    	        translate <0.00, -0.17,0>  
    	    }                                    
            sphere {0,.3,1 
    	        scale <.75,.5,.8>
    	        translate <0.05, -0.15,-.7> 
    	    }
    	    
    	    sphere {0,.3,-.85
    	            scale <.75,2,.9>
    	            rotate z*55
    	            translate <-.3,-.27,-.45>
    	    } 
    	    
    	}
        // Toes
    	union {
    		// 1st Toe (Big)
    		blob {
    			threshold BM_Build
    			cylinder { <0, 0, .1>, <0, 0, -0.2>, 0.16, 1
    				}
                sphere { <0,0,.2>,.25,-.7 }    				
    		    rotate <ToeAng, 0, 0>
    		    translate <-0.12, 0, -0.8>
    			//sturm
    		}
    		// 2nd Toe
    		blob {
    			threshold BM_Build
    			cylinder { <0, 0, 0>, <0, 0, -0.19>, 0.14, 1
    				rotate ToeAng*x
    				translate <0.01, 0.01, -0.8>}
    			//sturm
    		}
    		// 3rd Toe
    		blob {
    			threshold BM_Build
    			cylinder { <0, 0, 0>, <0, 0, -0.17>, 0.13, 1
    				rotate ToeAng*x
    				translate <0.12, 0.005, -0.8>}
    			//sturm
    		}
    		// 4th Toe
    		blob {
    			threshold BM_Build
    			cylinder { <0, 0, 0>, <0, 0, -0.15>, 0.12, 1
    				rotate <ToeAng, 5, 0>
    				translate <0.22, 0, -0.8>}
    			sturm
    		}
    		// 5th Toe (Little)
    		blob {
    			threshold BM_Build
    			cylinder { <0, 0, 0>, <0, 0, -0.13>, 0.11, 1
    				rotate <ToeAng, 10, 0>
    				translate <0.3, 0,-0.8>}
    			//sturm
    		}
    		translate <0, -0.175, 0>
    	}
        translate <0,.05,0>
        #if (BM_Gender=0)
            scale <8.5,8,8>
        #end
        #if (BM_Gender=1)
            scale 7                             
    	#end
    	rotate -3*z
    	scale <LR,1,1>
    }                             
#end    


#macro bmfeet()

    #if (BM_Gender=0)
        #local Hips             =<1.5,1.5,1.5>;
        #local ThighLength      =14;
        #local CalfLength       =17;     
        #local Ankle            =<.15,-1.5,1.35>;
        #local R_Foot            =< 0,-1,-1.4>;
        #local L_Foot            =< 0,-1,-1.4>;       
    #end
    #if (BM_Gender=1)
        #local Hips             =<.75,-2.5,1.5>;
        #local ThighLength      =14.7;                
        #local CalfLength       =18.9; 
        #local Ankle            =<0,-1,.25>;
        #local R_Foot           =<-.55,2,-1>;
        #local L_Foot           =< .55,2,-1>;        
    #end

    #local RL_Knee =vrotate(<0,-ThighLength,0>,BM_RL_H2K);
    #local RL_Ankle=vrotate(<0,-CalfLength,0> ,BM_RL_K2A);
    #local LL_Knee =vrotate(<0,-ThighLength,0>,BM_LL_H2K);
    #local LL_Ankle=vrotate(<0,-CalfLength,0> ,BM_LL_K2A);
    
    
    #local R_HipReplace=<BM_RL_H2K.y/-50,0,BM_RL_H2K.y/-50>-<BM_RL_K2A.y/-50,0,BM_RL_K2A.y/-50>;
    #local L_HipReplace=<BM_LL_H2K.y/-50,0,BM_LL_H2K.y/ 50>-<BM_LL_K2A.y/-50,0,BM_LL_K2A.y/ 50>;

    #local R_Foot_Trans=transform {rotate BM_RF_Rot rotate BM_RL_K2A translate RL_Knee+RL_Ankle+<-Hips.x+R_HipReplace.x,-29+Hips.y+BM_Gender,R_HipReplace.z+Hips.z> translate R_Foot}
    #local L_Foot_Trans=transform {rotate BM_LF_Rot rotate BM_LL_K2A translate LL_Knee+LL_Ankle+< Hips.x+L_HipReplace.x,-29+Hips.y+BM_Gender,L_HipReplace.z+Hips.z> translate L_Foot}
    
    #declare BMOFL=transform {translate -(LL_Knee+LL_Ankle+<0,-ThighLength-CalfLength,0>) 
                            #if (BM_Gender=0)
                                translate -L_Foot-<0,.5,0>
                            #end
                            #if (BM_Gender=1)
                                translate -L_Foot-<0,1,0>
                            #end
                            rotate -BM_LF_Rot                 
                            rotate -BM_LL_K2A
                            translate z*4
                           }                     
                                 
    #declare BMOFR=transform {translate -(RL_Knee+RL_Ankle+<0,-ThighLength-CalfLength,0>) 
                            #if (BM_Gender=0)
                                translate -R_Foot-<0,.5,0>
                            #end
                            #if (BM_Gender=1)
                                translate -R_Foot-<0,1,0>
                            #end
                            rotate -BM_RF_Rot
                            rotate -BM_RL_K2A 
                            translate z*4 
                           } 
    
    //#declare BM_RF_Location=<0,0,4>+R_Foot+<-Hips.x+R_HipReplace.x,-29+Hips.y+BM_Gender,R_HipReplace.z+Hips.z>+RL_Ankle+RL_Knee;
    #declare BM_RF_Location=vrotate (<0,0,4>,BM_RF_Rot);
    #declare BM_LF_Location=vrotate (<0,0,-4>,BM_LF_Rot);
    #if (BM_Gender=1)
        #declare BM_RF_Location=BM_RF_Location+<0,6,0>+< Hips.x,Hips.y,Hips.z>+RL_Ankle+RL_Knee;
        #declare BM_LF_Location=BM_LF_Location+<0,6,0>+<-Hips.x,Hips.y,Hips.z>+LL_Ankle+LL_Knee;
    #end
    #if (BM_Gender=0)
        #declare BM_RF_Location=BM_RF_Location+<0,.25,0>+< Hips.x,Hips.y,Hips.z>+RL_Ankle+RL_Knee;
        #declare BM_LF_Location=BM_LF_Location+<0,.25,0>+<-Hips.x,Hips.y,Hips.z>+LL_Ankle+LL_Knee;
    #end



    union {
 // Right Foot
           union {
               object {
                    #if (BM_R_Foot>0)
                        FootModel (-1,BM_Toe_Angle.z)
                    #else
                        BM_nul
                    #end
            	    translate Ankle                        
               } 
                                                            
            object {BM_Foot_R_Object}
            material {
                #ifdef (BM_Foot_R_Tex)
                    texture {BM_Foot_R_Tex}
                #else
                    texture {BM_Skin_Tex}
                #end
                #ifdef (Foot_R_IMap)
                    texture {
                        pigment {
                            image_map {
                                png Foot_R_IMap
                                map_type 0 
                                interpolate 4
                                once
                            } 
                            scale 8
                            translate <-4,-4,-4>
                        }
                        #ifdef (BM_Map_Finish)
                            finish {BM_Map_Finish}
                        #end
                        #ifdef (BM_Map_Normal)
                            normal {BM_Map_Normal}
                        #end
                        #ifdef (Foot_R_BMap)
                            normal {
                                bump_map {
                                    png Foot_R_BMap
                                    map_type 2 
                                    interpolate 4
                                    once
                                    bump_size BM_Bump_Map_Size
                                }
                                scale 8
                                translate <-4,-4,-4>
                            }
                        #end
                    }
                #end
            }
            transform R_Foot_Trans
        }
// Left Foot
        union {
               object {
                    #if (BM_L_Foot>0)
                        FootModel (1,BM_Toe_Angle.x)
                    #else
                        BM_nul
                    #end
            	    translate Ankle                        
               } 

            object {BM_Foot_L_Object}
            material {
                #ifdef (BM_Foot_L_Tex)
                    texture {BM_Foot_L_Tex}
                #else
                    texture {BM_Skin_Tex}
                #end
                #ifdef (Foot_L_IMap)
                    texture {
                        pigment {
                            image_map {
                                png Foot_L_IMap
                                map_type 0
                                interpolate 4
                                once
                            } 
                            scale 8
                            translate <-4,-4,-4>
                        }
                        #ifdef (BM_Map_Finish)
                            finish {BM_Map_Finish}
                        #end
                        #ifdef (BM_Map_Normal)
                            normal {BM_Map_Normal}
                        #end
                        #ifdef (Foot_L_BMap)
                            normal {
                                bump_map {
                                    png Foot_L_BMap
                                    map_type 2
                                    interpolate 4
                                    once
                                    bump_size BM_Bump_Map_Size
                                }
                                scale 8
                                translate <-4,-4,-4>
                            }
                        #end
                    }
                #end
            }
            transform L_Foot_Trans
        }
    }
#end

// End of Feet Macro