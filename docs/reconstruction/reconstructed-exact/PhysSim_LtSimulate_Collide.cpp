// =============================================================================
// PhysSim_LtSimulate_Collide
// -----------------------------------------------------------------------------
// Stable ID: aa_00561910
// Address:   0x00561910 – 0x00561B5B  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_00561910
// System:    physics / island simulate (collide half)
// Generated: 2026-07-29 W23-L dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Collide half of island "LtSimulate": install {dt, inv_dt} and derived scales
//   on the island manager, flush pending body pairs, run LtBroadPhase/narrowphase
//   per sub-island (FUN_00629d90), optional island post-collide callbacks, deferred
//   deletes, then StPostCollideCB list.
//
//   Does NOT run VehicleAction::applyAction or rigid-body integrate — those live
//   in companion FUN_00561b60 → FUN_00628f70.
//
// STRING EVIDENCE: "LtSimulate", "TtIslandPostCollideCb", "StPostCollideCB"
// CALLERS: CVOGSectorMap::StepTo (FUN_004d6c80) @ 0x004d6d90; FUN_00562bf0 @ 0x00562c19
//
// ABI (sealed from bytes):
//   __thiscall RET 4
//   ECX = island/world manager*
//   stack0 = float* stepInfo  // {substep_dt, 1/substep_dt}
//
// DECOMPILER RESIDUAL:
//   FUN_00629d90 call site — true this is subIslands[i]; decompile omits it.
//   Fixed in the loop body below using call-site bytes.
// =============================================================================

void __thiscall PhysSim_LtSimulate_Collide(int island, float *stepInfo)
{
  undefined4 *agent;
  int i;
  int sub;

  // profile enter "LtSimulate" (DAT_00bc5644 RDTSC stack) — elided shape preserved via calls below

  agent = *(undefined4 **)(island + 0xcc);
  *(float *)(island + 0x150) = *stepInfo;
  *(float *)(island + 0x154) = stepInfo[1];
  *(undefined4 *)(island + 0x140) = *agent;
  *(undefined4 *)(island + 0x144) = agent[1];
  *(undefined4 *)(island + 0x148) = agent[2];
  *(undefined4 *)(island + 0x14c) = agent[3];
  *(float *)(island + 0x170) = *stepInfo * *(float *)(island + 0x180);
  *(float *)(island + 0x174) = (float)*(int *)(island + 0x17c) * stepInfo[1];
  *(undefined4 *)(island + 0x198) = *(undefined4 *)(island + 0x170);
  *(undefined4 *)(island + 0x19c) = *(undefined4 *)(island + 0x174);
  *(float *)(island + 0x1a0) = (float)*(int *)(island + 0x17c) * *(float *)(island + 0x170);
  *(float *)(island + 0x1a4) = *(float *)(island + 0x180) * *(float *)(island + 0x174);

  *(undefined1 *)(island + 0x12c) = 1;
  if (0 < *(int *)(island + 0x24)) {
    FUN_00561320();
  }

  i = 0;
  *(undefined1 *)(island + 0x12d) = 1;
  if (0 < *(int *)(island + 0xc)) {
    do {
      sub = *(int *)(*(int *)(island + 8) + i * 4);
      // Bytes @ 0x00561a13: ECX=sub; PUSH island+0x140; PUSH *(island+0xc4)
      FUN_00629d90(sub, *(undefined4 *)(island + 0xc4), (undefined4 *)(island + 0x140));
      if (*(int *)(island + 0xac) != 0) {
        // profile "TtIslandPostCollideCb"
        *(undefined1 *)(island + 0x12d) = 0;
        FUN_0062a930(island, sub, stepInfo);
        *(undefined1 *)(island + 0x12d) = 1;
      }
      i = i + 1;
    } while (i < *(int *)(island + 0xc));
  }

  *(undefined1 *)(island + 0x12d) = 0;
  *(undefined1 *)(island + 0x12c) = 0;

  if (0 < *(int *)(island + 0x24)) {
    FUN_00561320();
  }
  if (*(int *)(island + 0xf4) != 0) {
    FUN_005618b0();
  }
  if (*(int *)(island + 0x100) != 0) {
    FUN_0055ec40();
  }
  if (0 < *(int *)(island + 0x24)) {
    FUN_00561320();
  }

  // profile "StPostCollideCB"
  FUN_0062a8a0(island, stepInfo);
  return;
}
