// =============================================================================
// FUN_004bcce0  (scaffold twin of CNDHash_Recreate_009cb450)
// -----------------------------------------------------------------------------
// Stable ID: aa_004bcce0
// Address:   0x004bcce0  (autoassault.exe, image base 0x400000)
// System:    container / CNDHash
// Generated: 2026-07-23 scaffold; refined W30-G 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Named clean: CNDHash_Recreate_009cb450.cpp
// =============================================================================

void __thiscall FUN_004bcce0(int param_1, unsigned char param_2)
{
  if (*(char *)(param_1 + 0x1d) != '\0') {
    FUN_007a4480(0, "HashError:Recreate, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  FUN_004bcc60();
  *(unsigned char *)(param_1 + 0x1c) = param_2;
  *(unsigned int *)(param_1 + 0x18) = 0;
  *(int *)(param_1 + 8) = 1 << (param_2 & 0x1f);
  *(unsigned int *)(param_1 + 0x14) = 0;
  FUN_004bc7a0();
  return;
}
