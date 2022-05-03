# Teensy3x_QuadDecode
Quadrature Decoder library for Teensy 3.x 

[From user TLB on the PJRC Forum](https://forum.pjrc.com/threads/26803-Hardware-Quadrature-Code-for-Teensy-3-x) (edited/reformatted for clarity):

> Attached is my code for utilizing the hardware quadrature decode for Teensy3.x. As others have noted, it is not straightforward. The marketing department must have decided the applications that utilized more than 64K encoder counts or were not at least piecewise uni-directional were a small part of the market.
> 
> I designed the code to minimize interrupt latency requirements and interrupt overhead. The code could have been a bit more straightforward if I had used both compare channels, but I wanted to save one for an exact position latch on hardware trigger feature (coming later).
> 
> There is the class QuadDecode<n> (it is templated to use either the FTM1 or FTM2 channel).
>
> The routines that can be called are:
>
> * ```setup()``` - constructor. Order of execution is not guaranteed, this is called to set everyting up at the appropriate time. It overwrites some registers setup in teensy.c for the tone() library, so has to be called after that.
> * ```start()``` - starts the counter counting at zero
> * ```zeroFTM()``` - zeroes the counter
> * ```calcPosn()``` - gets the current position. Needs to add the current counter position to the basePosn. Accurate to within interrupt latency and processing delay.
> 
> The programs attached are:
> 
> * ```QuadDecode.h```, ```QuadDecode_def.h``` - the important ones. Code to utilize the hardware quadrature decode channels on Teensy3.x
> * ```main.cpp``` - an example of use. As I mentioned, it is templated, and I did not Arduinofy it, so this shows how to use the templates.
> * ```GenEncoder.h```, ```GenEncoder.cpp``` - program that generates simulated encoder signals for debug and development.
> 
> Have fun. Let me know of questions or comments.
> 
> -TLB
 
 
This fork also includes [the changes introduced by user TMcGahee](https://forum.pjrc.com/threads/26803-Hardware-Quadrature-Code-for-Teensy-3-x?p=203606&viewfull=1#post203606) on the same thread:
 
> Sorry for the necro. This is a great library, but there's one catch - tlb uses pointers and non-template functions in the headers.
> 
> If you try to include the library in your sketch and into another library (e.g. trying to allow a communications library to use encoder data), you'll get a pile of multiple definition errors from the linker (despite the compile guards and even a #pragma once). It's a particularly tricky thing to debug if you haven't worked much with template classes.
> 
> I separated out those non-template parts into its own cpp. I'm uploading it here in case it helps someone else with the same problem.
> 
> I haven't changed anything except the arrangement of the code in files.
> 
> I also added an arduino sketch showing example use of the library (but not the encoder simulator).


A ```library.json``` was added for compatibility with platform.io