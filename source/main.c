#include <stdio.h>
#include <string.h>
#include <3ds.h>
#include <time.h>



int main()
{ 
  // Initializations
  srvInit();        // services
  aptInit();        // applets
  hidInit(NULL);    // input
  gfxInitDefault(); // graphics
  gfxSet3D(false);  // stereoscopy (true == on / false == off)
  u32 kDown;        // keys down
  u32 kHeld;        // keys pressed
  u32 kUp;          // keys up
  u8* fbTopLeft;    // top left screen's framebuffer
  u8* fbTopRight;   // top right screen's framebuffer
  u8* fbBottom;     // bottom screen's framebuffer
  consoleInit(GFX_TOP, NULL); //console on top screen
  // Main loop
  while (aptMainLoop())
  {

    // Wait for next frame
    gspWaitForVBlank();

    // Read which buttons are currently pressed or not
    hidScanInput();
    kDown = hidKeysDown();
    kHeld = hidKeysHeld();
    kUp = hidKeysUp();

    // Reset framebuffers
    fbTopLeft = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
    fbTopRight = gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, NULL, NULL);
    fbBottom = gfxGetFramebuffer(GFX_BOTTOM, 0, NULL, NULL);
    memset(fbTopLeft, 0, 240 * 400 * 3);
    memset(fbTopRight, 0, 240 * 400 * 3);
    memset(fbBottom, 0, 240 * 320 * 3);
    
    // If START button is pressed, break loop and quit
    if (kDown & KEY_START){
      printf("\x1b[15;19HGoodbye");
      break;
    }
    
    

    if (kHeld & KEY_A){
      printf("\x1b[15;19HThe A Button is Pressed!");
    }else if (kHeld & KEY_B){
      printf("\x1b[15;19HThe B Button is Pressed!");
    }else if (kHeld & KEY_X){
      printf("\x1b[15;19HThe X Button is Pressed!");
    }else if (kHeld & KEY_Y){
      printf("\x1b[15;19HThe Y Button is Pressed!");
    }else {
      printf("\x1b[15;19HNothing is Pressed :[ ");
    }

    
    // Flush and swap framebuffers
    gfxFlushBuffers();
    gfxSwapBuffers();
  }

  // Exit
  gfxExit();
  hidExit();
  aptExit();
  srvExit();

  // Return to hbmenu
  return 0;
}