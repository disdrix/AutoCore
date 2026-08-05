// =============================================================================
// ClientCamera_ApplyModeDistanceBand
// -----------------------------------------------------------------------------
// Stable ID: aa_0090dd50
// Address:   0x0090dd50  (autoassault.exe, image base 0x400000)
// Body:      0x0090dd50 – 0x0090df0f
// System:    client / camera
// Prior:     FUN_0090dd50, Named_CalleeOf_Client_RecvCreateCharacter_0090dd50
// Dual A/B:  2026-07-29 W17-H
// Tools:     decompile_function + read_memory (no disassemble_bytes)
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime: DEFERRED / OPEN
// =============================================================================
//
// PURPOSE
//   Recompute camera distance min/max/rate from integer mode at cam+0x60c, then
//   clamp primary (+0x530) and secondary (+0x52c) current-distance slots into the
//   new [min,max] band.
//
//   Callers (Respawn phase 4→5 / dtor, TeleportIn/Out ctors, CreateCharacter, …)
//   typically store a saved mode cookie into DAT_00d1b778+0x60c then call with
//   the camera object in EAX.
//
// ABI (sealed)
//   void ClientCamera_ApplyModeDistanceBand(Camera* cam /* in EAX */);
//   No stack args. Plain RET (C3). Leaf — zero callees.
//
// FLOAT POOL (read_memory sealed)
//   af9150=16  af9154=2  af9158=11  af915c=16  af9160=6
//   af9164=20  af9168=30  af916c=12  af9170=20  a0f298=0.5  g_flOne=1
// =============================================================================

extern float _DAT_00af9150;  // 16.0f — band span divisor
extern float DAT_00af9154;   // 2.0f
extern float DAT_00af9158;   // 11.0f
extern float DAT_00af915c;   // 16.0f
extern float DAT_00af9160;   // 6.0f
extern float DAT_00af9164;   // 20.0f
extern float DAT_00af9168;   // 30.0f
extern float DAT_00af916c;   // 12.0f
extern float DAT_00af9170;   // 20.0f
extern float DAT_00a0f298;   // 0.5f
extern float g_flOne;        // 1.0f
extern char  DAT_00d1b26c;   // selects wide vs narrow max
extern int   DAT_00d1b6d8;   // local entity singleton; flag at +0x6b9

// Camera fields used:
//   +0x60c int   mode (0 / 1 / other)
//   +0x524 float minDistance
//   +0x528 float maxDistance
//   +0x52c float secondaryCurrent
//   +0x530 float primaryCurrent
//   +0x534 float rate = (max-min)/16

void ClientCamera_ApplyModeDistanceBand(void *cam /* EAX */)
{
  float maxD;
  float invSpan;
  float span;
  float mid;
  float minD;
  float cur;
  int mode;

  mode = *(int *)((char *)cam + 0x60c);

  if (mode == 0) {
    *(float *)((char *)cam + 0x524) = DAT_00af9154;               // 2.0
    maxD = DAT_00af915c;                                          // 16.0
    if (DAT_00d1b26c == '\0') {
      maxD = DAT_00af9158;                                        // 11.0
    }
    invSpan = g_flOne / _DAT_00af9150;                            // 1/16
    *(float *)((char *)cam + 0x528) = maxD;
    *(float *)((char *)cam + 0x534) =
        (maxD - *(float *)((char *)cam + 0x524)) * invSpan;

    // Optional secondary/current init when local entity flag +0x6b9 set
    if ((DAT_00d1b6d8 != 0) && (*(char *)(DAT_00d1b6d8 + 0x6b9) != '\0')) {
      maxD = DAT_00af9168;                                        // 30.0
      if (DAT_00d1b26c == '\0') {
        maxD = DAT_00af9164;                                      // 20.0
      }
      span = maxD - DAT_00af9160;                                 // -6.0
      mid = span * DAT_00a0f298;                                  // *0.5 → 7 or 12
      *(float *)((char *)cam + 0x52c) = mid;
      *(float *)((char *)cam + 0x530) = span * invSpan + mid;     // 7.875 or 13.5
    }
  }
  else {
    if (mode == 1) {
      *(float *)((char *)cam + 0x524) = DAT_00af9160;             // 6.0
      maxD = DAT_00af9168;                                        // 30.0
      if (DAT_00d1b26c == '\0') {
        maxD = DAT_00af9164;                                      // 20.0
      }
      *(float *)((char *)cam + 0x528) = maxD;
    }
    else {
      // mode != 0 && mode != 1
      *(float *)((char *)cam + 0x524) = DAT_00af916c;             // 12.0
      *(float *)((char *)cam + 0x528) = DAT_00af9170;             // 20.0
      *(float *)((char *)cam + 0x530) = DAT_00af9170;
      *(float *)((char *)cam + 0x52c) = DAT_00af9170;
    }
    *(float *)((char *)cam + 0x534) =
        (*(float *)((char *)cam + 0x528) - *(float *)((char *)cam + 0x524))
        / _DAT_00af9150;
  }

  // Clamp primary current (+0x530) into [min, max]
  // Raw decompiler expands fcom as:
  //   if (cur < max || cur == max) { if (cur <= min && min != cur) cur = min; }
  //   else cur = max;
  // which is ordinary inclusive clamp.
  minD = *(float *)((char *)cam + 0x524);
  maxD = *(float *)((char *)cam + 0x528);
  cur  = *(float *)((char *)cam + 0x530);
  if (!(cur < maxD || cur == maxD)) {
    *(float *)((char *)cam + 0x530) = maxD;
  }
  else if (cur <= minD && minD != cur) {
    *(float *)((char *)cam + 0x530) = minD;
  }

  // Clamp secondary (+0x52c) into [min, max]
  cur = *(float *)((char *)cam + 0x52c);
  if (maxD <= cur && cur != maxD) {
    *(float *)((char *)cam + 0x52c) = maxD;
    return;
  }
  if (cur <= minD && minD != cur) {
    *(float *)((char *)cam + 0x52c) = minD;
  }
}

// Ghidra symbol alias
void FUN_0090dd50(void)
{
  // object in EAX — see ClientCamera_ApplyModeDistanceBand
}
