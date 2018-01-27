/****************************************************************
Hair Macro for use with "bmpeople.inc" v4.0
refer to "bmmanual.txt" for usage information
*******************************************************************/
#ifndef (BM_Defaults) 
    #include "bmdefs.inc"
#end

#macro bmhair()
    #local NeckTrans=transform {rotate <BM_Neck_Rot.x,0,BM_Neck_Rot.z>}
    #local TorsoTrans=transform {translate <0,20,-3> rotate <BM_Torso_Rot.x,0,BM_Torso_Rot.z> translate <0,-20,3>
                                 translate <0,20,0>  rotate <0,BM_Torso_Rot.y,0> translate <0,-20,0>
                      }
    #if (BM_Hair_On=1)
        union{
            #ifdef (Hair_Seed)
                #local rr=seed(Hair_Seed);
            #else
                #local rr=seed(77);
            #end
            #local tt=0;
            #while (tt<20)
                #local zz=tt*3+3;
                #local cc=0;
                #while (cc<zz)
                    #local yy=cc*360/zz+rand(rr)*6;
                    #local xx=BM_Hair_Line-sin((yy+15)*pi/30)*BM_Hair_LDpth;
                    #local hh=vrotate(<0,.8,0>,<tt*xx+rand(rr)*5,yy,45>);
                    #local hx=hh.x;
                    #local hy=hh.y;
                    #local hz=hh.z;
                    #local dx=hx/50;
                    #local dy=hy/50*BM_Hair_Hght;
                    #local dz=hz/50;
                    #if (BM_Hair_Arch=1 & dx>0)
                    #local dy=dy+dx;
                    #local dx=-dx;
                #end
                #if (hy>-.25)
                    blob{
                        threshold .5
                        #local ll=0;
                        #local length=BM_Hair_Length-rand(rr)*BM_Hair_Length/5;
                        #local vv=rand(rr)*length;
                        #while (ll<length) 
                            sphere{<hx+BM_Hair_Curl*sin((vv+ll)*pi/3),hy,hz+BM_Hair_Curl*cos((vv+ll)*pi/3)>,BM_Hair_Thck/5,1}
                            #local ll=ll+BM_Hair_Thck;
                            #local hx=hx+dx;
                            #local hy=hy+dy;
                            #local hz=hz+dz;
                            #local dx=dx*(1-BM_Hair_Wght*2);
                            #local dy=dy*(1-BM_Hair_Wght/2)-BM_Hair_Wght/20;
                            #local dz=dz*(1-BM_Hair_Wght);
                            #if (BM_Hair_Arch=1 & dx>0)
                                #local dy=dy+0.001;
                                #if (hx>-.5)
                                    #local hx=hx+dx;
                                #end
                            #end
                        #end
                        #ifndef (BM_Hair_Tex)
                            pigment{rgb BM_Hair_Col+<rand(rr)/10,rand(rr)/10,rand(rr)/10>}
                        #else
                            texture {BM_Hair_Tex}
                        #end
			}
                    #end
                    #local cc=cc+1;
                #end
                #local tt=tt+1;
            #end
            rotate y*90
            rotate BM_Hair_Rot
            scale 4.5
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
    #else
        object {BM_nul}
    #end
#end             

// End of Hair Macro