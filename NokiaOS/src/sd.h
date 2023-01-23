#include "FS.h"
#include "SD_MMC.h"

void initMicroSDCard() {
  // Start the MicroSD card
 
  Serial.println("Mounting MicroSD Card");
  if (!SD_MMC.begin("/sdcard", false, true)) {
    Serial.println("MicroSD Card Mount Failed");
    return;
  }
  uint8_t cardType = SD_MMC.cardType();
  if (cardType == CARD_NONE) {
    Serial.println("No MicroSD Card found");
    return;
  }
}