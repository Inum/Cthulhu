/***************************************************************
             
                 ___ _     _    __  __
                | _ ) |___| |__|  \/  |__ _ _ _
                | _ \ / _ \ '_ \ |\/| / _` | ' \  
                |___/_\___/_.__/_|  |_\__,_|_||_|
                    | _ \___ ___ _ __| |___
                    |  _/ -_) _ \ '_ \ / -_)
                    |_| \___\___/ .__/_\___|
                                |_|                09 April 2000

by Peter Houston <houston.graphics@iname.com>
                < http://welcome.to/HoustonGraphics >
                < http://members.xoom.com/HoustonGraph >
based on Blob Man model by Govert Zoethout < zoethout@gmx.net >
                < http://victorian.fortunecity.com/dada/507/ >
and lady.inc by Yasunari Iwanaga < iwaentcl@po.saganet.ne.jp >
                < http://yasucg.site.ne.jp/ >                

Refer to "bmmanual.txt" for full usage details.

****************************************************************/

#local BlobMan_People_Version = version;
#version 3.1;

#ifndef (BM_Defaults) 
    #include "bmdefs.inc"
#end

#include "bmhead.inc"
#include "bmtorso.inc"
#include "bmhand.inc"
#include "bmfeet.inc"
#include "bmhair.inc"

/***************************************************************
Blob_Man Macro
Syntax
 Blob_Man(Gender, Height)
 
Gender : 0=Male ; 1=Female
Height : In POV Units
****************************************************************/
#macro Blob_Man(Gender,Height)
    #declare BM_Gender=Gender;
    #if (BM_PoseNo>=0)
        #declare BM_Head_Rot     = BM_Pose[BM_PoseNo][0];
        #declare BM_Neck_Rot     = BM_Pose[BM_PoseNo][1];
        #declare BM_Torso_Rot    = BM_Pose[BM_PoseNo][2];
        #declare BM_RA_S2E       = BM_Pose[BM_PoseNo][3];
        #declare BM_RA_E2W       = BM_Pose[BM_PoseNo][4];
        #declare BM_LA_S2E       = BM_Pose[BM_PoseNo][5];
        #declare BM_LA_E2W       = BM_Pose[BM_PoseNo][6];
        #declare BM_RL_H2K       = BM_Pose[BM_PoseNo][7];
        #declare BM_RL_K2A       = BM_Pose[BM_PoseNo][8];
        #declare BM_LL_H2K       = BM_Pose[BM_PoseNo][9];
        #declare BM_LL_K2A       = BM_Pose[BM_PoseNo][10];
        #declare BM_RF_Rot       = BM_Pose[BM_PoseNo][11];
        #declare BM_LF_Rot       = BM_Pose[BM_PoseNo][12];
        #declare BM_Toe_Angle    = BM_Pose[BM_PoseNo][13];
        #declare BM_RH_Rot       = BM_Pose[BM_PoseNo][14];
        #declare BM_LH_Rot       = BM_Pose[BM_PoseNo][15];        
        #if (BM_Pose_RHand<0)
            #declare BM_Pose_RHand = BM_Pose[BM_PoseNo][16].z;
        #end
        #if (BM_Pose_LHand<0)                              
            #declare BM_Pose_LHand = BM_Pose[BM_PoseNo][16].x;
        #end
        #declare BM_RFP_Pos    = BM_Hands[BM_Pose_RHand][0];
        #declare BM_RFR_Pos    = BM_Hands[BM_Pose_RHand][1];
        #declare BM_RFM_Pos    = BM_Hands[BM_Pose_RHand][2];
        #declare BM_RFI_Pos    = BM_Hands[BM_Pose_RHand][3];
        #declare BM_RFT_Pos    = BM_Hands[BM_Pose_RHand][4];
        #declare BM_LFP_Pos    = BM_Hands[BM_Pose_LHand][0];
        #declare BM_LFR_Pos    = BM_Hands[BM_Pose_LHand][1];
        #declare BM_LFM_Pos    = BM_Hands[BM_Pose_LHand][2];
        #declare BM_LFI_Pos    = BM_Hands[BM_Pose_LHand][3];
        #declare BM_LFT_Pos    = BM_Hands[BM_Pose_LHand][4];    
    #else
        #if (BM_Pose_RHand>=0)
            #declare BM_RFP_Pos    = BM_Hands[BM_Pose_RHand][0];
            #declare BM_RFR_Pos    = BM_Hands[BM_Pose_RHand][1];
            #declare BM_RFM_Pos    = BM_Hands[BM_Pose_RHand][2];
            #declare BM_RFI_Pos    = BM_Hands[BM_Pose_RHand][3];
            #declare BM_RFT_Pos    = BM_Hands[BM_Pose_RHand][4];
        #end
        #if (BM_Pose_LHand>=0)
            #declare BM_LFP_Pos    = BM_Hands[BM_Pose_LHand][0];
            #declare BM_LFR_Pos    = BM_Hands[BM_Pose_LHand][1];
            #declare BM_LFM_Pos    = BM_Hands[BM_Pose_LHand][2];
            #declare BM_LFI_Pos    = BM_Hands[BM_Pose_LHand][3];
            #declare BM_LFT_Pos    = BM_Hands[BM_Pose_LHand][4];           
        #end
    #end                      
    
    #if (BM_HairStyle>=0)
        #declare BM_Hair_Rot   = BM_Pose_Hair_1[BM_HairStyle][0];
    
        #declare BM_Hair_On    = BM_Pose_Hair_2[BM_HairStyle][0];
        #declare BM_Hair_Arch  = BM_Pose_Hair_2[BM_HairStyle][1];
        #declare BM_Hair_Thck  = BM_Pose_Hair_2[BM_HairStyle][2];
        #declare BM_Hair_Line  = BM_Pose_Hair_2[BM_HairStyle][3];
        #declare BM_Hair_LDpth = BM_Pose_Hair_2[BM_HairStyle][4];
        #declare BM_Hair_Wght  = BM_Pose_Hair_2[BM_HairStyle][5];
        #declare BM_Hair_Hght  = BM_Pose_Hair_2[BM_HairStyle][6];
        #declare BM_Hair_Length= BM_Pose_Hair_2[BM_HairStyle][7];
        #declare BM_Hair_Curl  = BM_Pose_Hair_2[BM_HairStyle][8];
    #end
    #declare BM_Pose_RHand=-1;
    #declare BM_Pose_LHand=-1;
    #declare BlobMan= union {
        object { bmhead (  )}
        object { bmtorso(  )}
        object { bmhand ( 1)}
        object { bmhand (-1)}
        object { bmfeet (  )}
        object { bmhair (  )}
    }   
    #declare BM_Scale=(((Height*1000)/66)/30)*1.2/40;
    
    #if (BM_Gender=1)
        #declare BM_Scale=BM_Scale*.977;            
    #end 

// Origin Variables including Scale
    #declare BMO_Foot_R     =transform {transform BMOFR scale BM_Scale}
    #declare BMO_Foot_L     =transform {transform BMOFL scale BM_Scale}
    #declare BMO_Toe_R      =transform {transform BMOFR rotate <-BM_Toe_Angle.z,0,0> scale BM_Scale}
    #declare BMO_Toe_L      =transform {transform BMOFL rotate <-BM_Toe_Angle.x,0,0> scale BM_Scale}
    #declare BMO_Knee_R     =transform {transform BMOKR scale BM_Scale}
    #declare BMO_Knee_L     =transform {transform BMOKL scale BM_Scale}
    #declare BMO_Hip_R      =transform {transform BMOHR scale BM_Scale}
    #declare BMO_Hip_L      =transform {transform BMOHL scale BM_Scale}
    #declare BMO_Abdomen_F  =transform {transform BMOAF scale BM_Scale}
    #declare BMO_Abdomen_B  =transform {transform BMOAB scale BM_Scale}
    #declare BMO_Abdomen_U  =transform {transform BMOAU scale BM_Scale}
    #declare BMO_Abdomen_R  =transform {transform BMOAR scale BM_Scale}
    #declare BMO_Abdomen_L  =transform {transform BMOAL scale BM_Scale}
    #declare BMO_Torso_F    =transform {transform BMOTF scale BM_Scale}
    #declare BMO_Torso_B    =transform {transform BMOTB scale BM_Scale}
    #declare BMO_Torso_R    =transform {transform BMOTR scale BM_Scale}    
    #declare BMO_Torso_L    =transform {transform BMOTL scale BM_Scale}
    #declare BMO_Torso_T    =transform {transform BMOTT scale BM_Scale}
    #declare BMO_Shoulder_R =transform {transform BMOSR scale BM_Scale}
    #declare BMO_Shoulder_L =transform {transform BMOSL scale BM_Scale}
    #declare BMO_Elbow_R    =transform {transform BMOER scale BM_Scale}
    #declare BMO_Elbow_L    =transform {transform BMOEL scale BM_Scale}
    #declare BMO_Hand_R     =transform {transform BMOPR scale BM_Scale}
    #declare BMO_Hand_L     =transform {transform BMOPL scale BM_Scale}
    #declare BMO_Head_F     =transform {transform BMOHF scale BM_Scale}
    #declare BMO_Head_B     =transform {transform BMOHB scale BM_Scale}
    #declare BMO_Head_T     =transform {transform BMOHT scale BM_Scale}
    #declare BMO_Ear_R      =transform {transform BMOeR scale BM_Scale}
    #declare BMO_Ear_L      =transform {transform BMOeL scale BM_Scale}
    #declare BMO_Nose       =transform {transform BMONs scale BM_Scale}
    #declare BM_RF_Location =BM_RF_Location*BM_Scale;
    #declare BM_LF_Location =BM_LF_Location*BM_Scale;
    #if (vlength(<0,0,0>-<0,BM_RF_Location.y,0>)>vlength(<0,0,0>-<0,BM_LF_Location.y,0>))
        #if (BM_RF_Location.x<0)
            #declare BM_StrideRL=<-(vlength(<0,0,0>-<BM_RF_Location.x,0,0>)),vlength(<0,0,0>-<0,BM_RF_Location.y,0>),0>;
        #else
            #declare BM_StrideRL=<vlength(<0,0,0>-<BM_RF_Location.x,0,0>),vlength(<0,0,0>-<0,BM_RF_Location.y,0>),0>;        
        #end 
        #if (BM_LF_Location.x<0)
            #declare BM_StrideLL=<-(vlength(<0,0,0>-<BM_LF_Location.x,0,0>)),vlength(<0,0,0>-<0,BM_RF_Location.y,0>),0>;
        #else
            #declare BM_StrideLL=<vlength(<0,0,0>-<BM_LF_Location.x,0,0>),vlength(<0,0,0>-<0,BM_RF_Location.y,0>),0>;        
        #end        
    #else                                                                
        #if (BM_RF_Location.x<0)
            #declare BM_StrideRL=<-(vlength(<0,0,0>-<BM_RF_Location.x,0,0>)),vlength(<0,0,0>-<0,BM_LF_Location.y,0>),0>;
        #else
            #declare BM_StrideRL=<vlength(<0,0,0>-<BM_RF_Location.x,0,0>),vlength(<0,0,0>-<0,BM_LF_Location.y,0>),0>;        
        #end 
        #if (BM_LF_Location.x<0)
            #declare BM_StrideLL=<-(vlength(<0,0,0>-<BM_LF_Location.x,0,0>)),vlength(<0,0,0>-<0,BM_LF_Location.y,0>),0>;
        #else
            #declare BM_StrideLL=<vlength(<0,0,0>-<BM_LF_Location.x,0,0>),vlength(<0,0,0>-<0,BM_LF_Location.y,0>),0>;        
        #end 
    #end
#end

#version BlobMan_People_Version;

//End of Blob Man People Include File