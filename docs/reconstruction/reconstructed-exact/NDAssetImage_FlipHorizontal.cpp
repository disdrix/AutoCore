// =============================================================================
// NDAssetImage_FlipHorizontal
// -----------------------------------------------------------------------------
// Stable ID: aa_0098acc0
// Address:   0x0098acc0–0x0098ae77  (autoassault.exe, image base 0x400000)
// System:    client assets / NDAssetImage (TGA right-origin bit4 normalize)
// Generated: 2026-07-29 W20-L dual seal (body ≡ 2026-07-23 raw)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes (W20-L sealed):
 * - this in EDI; return AL = 0 fail / 1 success; plain RET after ADD ESP,0x10.
 * - Sole caller NDAssetImage_LoadTGA when TGA image-descriptor bit4 (0x10) set.
 * - Sibling NDAssetImage_FlipVertical @ 0x004332e0 (bit5 + 32bpp at LoadTGA).
 * - Allocates temp NDAssetImage (0x1b8), reverse-copies pixels bpp-aware into
 *   temp+0x34, post-processes via FUN_00433390 / FUN_00432580, destroys temp.
 * - Runtime / differential verification: OPEN.
 */

// this in EDI (decompiler: unaff_EDI)
uint8_t /* bool in AL */ NDAssetImage_FlipHorizontal(void /* NDAssetImage* this in EDI */)
{
  short bpp;
  uint32_t *tmp;
  uint8_t *pSrcWalk;
  int lastPxOff;
  uint8_t *pSrcRow;
  int x;
  uint uCount;
  int destOrY;
  uint8_t *pTriplet;
  int /* NDAssetImage* */ self; /* EDI */
  int y;

  self = /* EDI */;

  if (*(int *)(self + 4) == 0) {
    return 0;
  }
  tmp = operator_new(0x1b8);
  if (tmp == (uint32_t *)0x0) {
    return 0;
  }
  *tmp = (uint32_t)&PTR_FUN_00a9bcac;
  FUN_004320d0();
  FUN_00432260(self, 0, 0, 1);
  bpp = *(short *)(self + 0x16);
  /* ((bpp==24)*2 + 1) * (width - 1)  →  last pixel byte offset in row */
  lastPxOff = ((uint)(bpp == 0x18) * 2 + 1) * (*(int *)(self + 0xc) + -1);
  destOrY = tmp[0xd]; /* temp+0x34 pixel store */
  pSrcRow = (uint8_t *)(*(int *)(self + 0x34) + lastPxOff);
  if (bpp == 8) {
    y = 0;
    if (0 < *(int *)(self + 0x10)) {
      do {
        x = 0;
        pSrcWalk = pSrcRow;
        if (-1 < lastPxOff) {
          do {
            *(uint8_t *)(x + destOrY) = *pSrcWalk;
            x = x + 1;
            pSrcWalk = pSrcWalk + -1;
          } while (x <= lastPxOff);
        }
        pSrcRow = pSrcRow + *(int *)(self + 0x30);
        destOrY = destOrY + *(int *)(self + 0x30);
        y = y + 1;
      } while (y < *(int *)(self + 0x10));
    }
  }
  else if (bpp == 0x18) {
    y = 0;
    if (0 < *(int *)(self + 0x10)) {
      do {
        if (-1 < lastPxOff) {
          pSrcWalk = (uint8_t *)(destOrY + 1);
          pTriplet = pSrcRow + 2;
          uCount = (lastPxOff + 3U) / 3;
          do {
            pSrcWalk[-1] = pTriplet[-2];
            *pSrcWalk = pTriplet[-1];
            pSrcWalk[1] = *pTriplet;
            pSrcWalk = pSrcWalk + 3;
            pTriplet = pTriplet + -3;
            uCount = uCount - 1;
          } while (uCount != 0);
        }
        pSrcRow = pSrcRow + *(int *)(self + 0x30);
        destOrY = destOrY + *(int *)(self + 0x30);
        y = y + 1;
      } while (y < *(int *)(self + 0x10));
    }
  }
  else {
    destOrY = 0;
    if (0 < *(int *)(self + 0x10)) {
      do {
        x = 0;
        if (-1 < lastPxOff) {
          do {
            FUN_00433530();
            FUN_004337d0(destOrY);
            x = x + 1;
          } while (x <= lastPxOff);
        }
        destOrY = destOrY + 1;
      } while (destOrY < *(int *)(self + 0x10));
    }
  }
  FUN_00433390();
  FUN_00432580(self);
  (**(code **)*tmp)(1);
  return 1;
}
