/***************************************************************
  Default Settings for the "bmpeople.inc" and associated files
****************************************************************/
// Default Settings
#declare BM_Defaults=true;
#declare Male=0;
#declare Female=1;
#ifndef (BM_Guide_Rad)       #declare BM_Guide_Rad=2; #end
#ifndef (BM_PoseNo)          #declare BM_PoseNo=-1; #end
#ifndef (BM_Pose_RHand)      #declare BM_Pose_RHand=-1; #end
#ifndef (BM_Pose_LHand)      #declare BM_Pose_LHand=-1; #end
#ifndef (BM_Hair_Seed)       #declare BM_Hair_Seed=77; #end
#ifndef (BM_Gender)          #declare BM_Gender=0; #end    
#ifndef (BM_HairCol)         #declare BM_HairCol=<.5,.5,.5,>; #end
#ifndef (BM_Navel)           #declare BM_Navel=0; #end
#ifndef (BM_Nipples)         #declare BM_Nipples=0; #end
#ifndef (BM_Flex)            #declare BM_Flex=1; #end    
#ifndef (BM_TShirt)          #declare BM_TShirt=0; #end
#ifndef (BM_Build)           #declare BM_Build=0.5; #end    
#ifndef (BM_Mouth)           #declare BM_Mouth=1; #end
#ifndef (BM_MouthShape)      #declare BM_MouthShape=.5; #end
#ifndef (BM_EyeCol)          #declare BM_EyeCol=<.22,.69,.87>; #end
#ifndef (BM_EyeLids)         #declare BM_EyeLids=<0,0,0>; #end
#ifndef (BM_RA_S2E)          #declare BM_RA_S2E= <-8,0,-8>; #end
#ifndef (BM_RA_E2W)          #declare BM_RA_E2W= <8,0,-3>; #end
#ifndef (BM_LA_S2E)          #declare BM_LA_S2E= <-8,0,8>; #end
#ifndef (BM_LA_E2W)          #declare BM_LA_E2W= <8,0,3>; #end
#ifndef (BM_RL_H2K)          #declare BM_RL_H2K= <8,0,-5>; #end
#ifndef (BM_RL_K2A)          #declare BM_RL_K2A= <-8,0,3>; #end
#ifndef (BM_LL_H2K)          #declare BM_LL_H2K= <8,0,5>; #end
#ifndef (BM_LL_K2A)          #declare BM_LL_K2A= <-8,0,-3>; #end
#ifndef (BM_RH_Rot)          #declare BM_RH_Rot= <0,0,0>; #end
#ifndef (BM_LH_Rot)          #declare BM_LH_Rot= <0,0,0>; #end
#ifndef (BM_RF_Rot)          #declare BM_RF_Rot= <8,0,-3>; #end
#ifndef (BM_LF_Rot)          #declare BM_LF_Rot= <8,0,3>; #end
#ifndef (BM_Toe_Angle)       #declare BM_Toe_Angle=<0,0,0>; #end                  
#ifndef (BM_Head_Rot)        #declare BM_Head_Rot= <0,0,0>; #end                
#ifndef (BM_Neck_Rot)        #declare BM_Neck_Rot= <0,0,0>; #end    
#ifndef (BM_Torso_Rot)       #declare BM_Torso_Rot= <0,0,0>; #end    
#ifndef (BM_LFP_Pos)         #declare BM_LFP_Pos= <5,45,5,0>; #end
#ifndef (BM_LFR_Pos)         #declare BM_LFR_Pos= <10,30,5,0>; #end
#ifndef (BM_LFM_Pos)         #declare BM_LFM_Pos= <5,15,5,0>; #end
#ifndef (BM_LFI_Pos)         #declare BM_LFI_Pos= <0,10,0,0>; #end
#ifndef (BM_LFT_Pos)         #declare BM_LFT_Pos= <0,-10,5,10>; #end
#ifndef (BM_RFP_Pos)         #declare BM_RFP_Pos= <5,45,5,0>; #end
#ifndef (BM_RFR_Pos)         #declare BM_RFR_Pos= <10,30,5,0>; #end
#ifndef (BM_RFM_Pos)         #declare BM_RFM_Pos= <5,15,5,0>; #end
#ifndef (BM_RFI_Pos)         #declare BM_RFI_Pos= <0,10,0,0>; #end
#ifndef (BM_RFT_Pos)         #declare BM_RFT_Pos= <0,-10,5,10>; #end
#ifndef (BM_Map_R_Finger)    #declare BM_Map_R_Finger=1; #end
#ifndef (BM_Map_L_Finger)    #declare BM_Map_L_Finger=1; #end
#ifndef (BM_Nails)           #declare BM_Nails=1; #end    
#ifndef (BM_Ears)            #declare BM_Ears=2; #end
#ifndef (BM_Jaw)             #declare BM_Jaw=.5; #end
#ifndef (BM_Teeth)           #declare BM_Teeth=1; #end    
#ifndef (BM_Jowls)           #declare BM_Jowls=0; #end    
#ifndef (BM_Nose)            #declare BM_Nose=.4; #end               
#ifndef (BM_Face)            #declare BM_Face=1; #end         
#ifndef (BM_R_Foot)          #declare BM_R_Foot=1; #end
#ifndef (BM_L_Foot)          #declare BM_L_Foot=1; #end
#ifndef (BM_R_Hand)          #declare BM_R_Hand=1; #end
#ifndef (BM_L_Hand)          #declare BM_L_Hand=1; #end
#ifndef (BM_Eyes)            #declare BM_Eyes=1; #end
#ifndef (BM_HairStyle)       #declare BM_HairStyle=-1; #end
#ifndef (BM_Hair_Col)        #declare BM_Hair_Col=<.5,.5,.5>; #end
#ifndef (BM_Hair_Rot)        #declare BM_Hair_Rot=<0,0,0>; #end
#ifndef (BM_Hair_On)         #declare BM_Hair_On=0; #end
#ifndef (BM_Hair_Arch)       #declare BM_Hair_Arch=0; #end
#ifndef (BM_Hair_Thck)       #declare BM_Hair_Thck=0; #end
#ifndef (BM_Hair_Line)       #declare BM_Hair_Line=0; #end
#ifndef (BM_Hair_LDpth)      #declare BM_Hair_LDpth=0; #end
#ifndef (BM_Hair_Wght)       #declare BM_Hair_Wght=0; #end
#ifndef (BM_Hair_Hght)       #declare BM_Hair_Hght=0; #end
#ifndef (BM_Hair_Length)     #declare BM_Hair_Length=0; #end
#ifndef (BM_Hair_Curl)       #declare BM_Hair_Curl=0; #end

#ifndef (BM_R_Upperarm_Mass) #declare BM_R_Upperarm_Mass=2; #end
#ifndef (BM_L_Upperarm_Mass) #declare BM_L_Upperarm_Mass=2; #end
#ifndef (BM_R_Forearm_Mass)  #declare BM_R_Forearm_Mass=2; #end
#ifndef (BM_L_Forearm_Mass)  #declare BM_L_Forearm_Mass=2; #end
#ifndef (BM_R_Thigh_Mass)    #declare BM_R_Thigh_Mass=2; #end
#ifndef (BM_L_Thigh_Mass)    #declare BM_L_Thigh_Mass=2; #end
#ifndef (BM_R_Calf_Mass)     #declare BM_R_Calf_Mass=2; #end
#ifndef (BM_L_Calf_Mass)     #declare BM_L_Calf_Mass=2; #end
#ifndef (BM_Neck_Mass)       #declare BM_Neck_Mass=1; #end
#ifndef (BM_Torso_Mass)      #declare BM_Torso_Mass=1; #end                         
#ifndef (BM_Abdomen_Mass)    #declare BM_Abdomen_Mass=1; #end
#ifndef (BM_Head_Mass)       #declare BM_Head_Mass=1; #end
#ifndef (BM_Bump_Map_Size)   #declare BM_Bump_Map_Size=0.25; #end

// Define Default Textures
#ifndef (BM_Skin_Tex)
    #declare BM_Skin_Tex=
    texture {
        pigment{rgb <0.96,0.80,0.69>}
        finish{
            phong .1 
            phong_size 40
        }
    }
#end

#ifndef (BM_Lip_Tex)
    #declare BM_Lip_Tex =
        texture {
            pigment{rgb <.7,.3,.2>}
            finish{
                phong .3 
                phong_size 40
            }
            normal{
                crackle .2 
                turbulence .7 
                scale .7
            }
        }
#end

#ifndef (BM_Nail_Tex)
	#declare BM_Nail_Tex =
        texture{BM_Skin_Tex
    		finish {
    		    ambient -.25
    		} 
		}
#end
#ifndef (BM_Tooth_Tex)
    #declare BM_Tooth_Tex=
        texture {
            pigment {rgb 1}
            finish {phong .9 phong_size 90}
        }
#end

// Declare Default nul Objects
#ifndef (BM_DeBug)
    #declare BM_DeBug=off;
#end

#declare BM_Vector_Locator=
    union {
        cylinder {<-8,0,0><8,0,0> .5 pigment {rgb x}}
        cylinder {<0,0,-8><0,0,8> .5 pigment {rgb y}}
        cylinder {<0,-8,0><0,8,0> .5 pigment {rgb z}}
        torus {5,.4 pigment {rgb <1,1,0>}}
    }

#declare BM_nul=sphere{0,.0000001 pigment {rgbft 1}}

#ifndef (BM_Head_Object)       #declare BM_Head_Object=object{BM_nul} #end
#ifndef (BM_Neck_Object)       #declare BM_Neck_Object=object{BM_nul} #end    
#ifndef (BM_Torso_Object)      #declare BM_Torso_Object=object{BM_nul} #end  
#ifndef (BM_Abdomen_Object)    #declare BM_Abdomen_Object=object{BM_nul} #end
#ifndef (BM_Upperarm_R_Object) #declare BM_Upperarm_R_Object=object{BM_nul} #end
#ifndef (BM_Upperarm_L_Object) #declare BM_Upperarm_L_Object=object{BM_nul} #end
#ifndef (BM_Forearm_R_Object)  #declare BM_Forearm_R_Object=object{BM_nul} #end
#ifndef (BM_Forearm_L_Object)  #declare BM_Forearm_L_Object=object{BM_nul} #end
#ifndef (BM_Hand_R_Object)     #declare BM_Hand_R_Object=object{BM_nul} #end
#ifndef (BM_Hand_L_Object)     #declare BM_Hand_L_Object=object{BM_nul} #end
#ifndef (BM_Thigh_R_Object)    #declare BM_Thigh_R_Object=object{BM_nul} #end
#ifndef (BM_Thigh_L_Object)    #declare BM_Thigh_L_Object=object{BM_nul} #end
#ifndef (BM_Calf_R_Object)     #declare BM_Calf_R_Object=object{BM_nul} #end
#ifndef (BM_Calf_L_Object)     #declare BM_Calf_L_Object=object{BM_nul} #end
#ifndef (BM_Foot_R_Object)     #declare BM_Foot_R_Object=object{BM_nul} #end
#ifndef (BM_Foot_L_Object)     #declare BM_Foot_L_Object=object{BM_nul} #end

#if (BM_DeBug=yes)
    #declare BM_Head_Object=
        union {
            object{BM_Head_Object}
            object{BM_Vector_Locator scale 1.5}
        }
    #declare BM_Torso_Object=object{BM_nul}
    #declare BM_Upperarm_R_Object=
        union {
            object {BM_Upperarm_R_Object}
            object {BM_Vector_Locator rotate z*90}
        }
    #declare BM_Upperarm_L_Object=
        union {
            object {BM_Upperarm_L_Object}
            object {BM_Vector_Locator rotate z*90}
        }
    #declare BM_Forearm_R_Object=
        union {
            object {BM_Forearm_R_Object}
            object {BM_Vector_Locator}
        }
    #declare BM_Forearm_L_Object=
        union {
            object {BM_Forearm_L_Object}
            object {BM_Vector_Locator}
        }
    #declare BM_Hand_R_Object=
        union {
            object {BM_Hand_R_Object}
            object {BM_Vector_Locator}
        }
    #declare BM_Hand_L_Object=
        union {
            object {BM_Hand_L_Object}
            object {BM_Vector_Locator}
        }
    #declare BM_Thigh_R_Object=
        union {
            object {BM_Thigh_R_Object}
            object {BM_Vector_Locator rotate z*90 scale 1.25}
        }
    #declare BM_Thigh_L_Object=
        union {
            object {BM_Thigh_L_Object}
            object {BM_Vector_Locator rotate z*90 scale 1.25}
        }
    #declare BM_Calf_R_Object=
        union {
            object {BM_Calf_R_Object}
            object {BM_Vector_Locator}
        }
    #declare BM_Calf_L_Object=
        union {
            object {BM_Calf_L_Object}
            object {BM_Vector_Locator}
        }
    #declare BM_Foot_R_Object=
        union {
            object {BM_Foot_R_Object}
            cylinder {<0,-3.25,0><0,-3.0,0>6.5 pigment {rgb <1,0,0>}}
            object {BM_Vector_Locator}
        }
    #declare BM_Foot_L_Object=
        union {
            object {BM_Foot_L_Object}
            cylinder {<0,-3.25,0><0,-3.0,0>6.5 pigment {rgb <1,0,0>}}
            object {BM_Vector_Locator}
        }
#end

// End of Defaults File