// =============================================================================
// FUN_00561910  (Ghidra symbol twin of PhysSim_LtSimulate_Collide)
// -----------------------------------------------------------------------------
// Stable ID: aa_00561910
// Address:   0x00561910 – 0x00561B5B  (autoassault.exe, image base 0x400000)
// Named:     PhysSim_LtSimulate_Collide
// Generated: 2026-07-29 W23-L dual seal
// Exactness: Behavior-preserving. Bit-for-bit: DEFERRED.
// See:       reconstructed-exact/PhysSim_LtSimulate_Collide.cpp
// =============================================================================

void __thiscall FUN_00561910(int island, float *stepInfo)
{
  undefined4 *agent;
  int i;
  int sub;

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
      FUN_00629d90(sub, *(undefined4 *)(island + 0xc4), (undefined4 *)(island + 0x140));
      if (*(int *)(island + 0xac) != 0) {
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
  FUN_0062a8a0(island, stepInfo);
  return;
}
