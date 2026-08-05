// =============================================================================
// CVOGPhysics_SetRotation (inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00404dc0
// Address:   0x00404dc0  (autoassault.exe, image base 0x400000)
// System:    physics
// Generated: 2026-07-29 dual A/B (force path: live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Ghidra:    FUN_00404dc0
// =============================================================================

// PURPOSE:
//   CVOGPhysics helper: optional readiness prepare, then — only when not fully
//   ready (phys+0x40==0 OR phys+0x08==0) — forward rotation pointer to bound
//   rigid body via body vtbl +0x44 (setRotation).
//
// Siblings:
//   FUN_0040d2a0  setPosition          body vtbl +0x40  (same dual gates)
//   ApplyImpulse  set/apply linear vel body vtbl +0x50  (no fully-ready skip)
//   SetAngVel     set angular vel      body vtbl +0x54  (no fully-ready skip)
//
// Ready helpers (shared family):
//   FUN_005070b0  probe: if phys+0x44==0 → *out=0; else *out=*(*(phys+0x44)+0x29)
//   FUN_005070d0  prepare/attach when probe out==0 and phys+0x44≠0
//
// ABI: thiscall (ECX = phys); stack arg = rotation pointer; ret 4.

// Dual A/B: reviews/A_aa_00404dc0_CVOGPhysics_SetRotation.md
//           reviews/B_aa_00404dc0_CVOGPhysics_SetRotation.md

void __thiscall CVOGPhysics_SetRotation(int phys, undefined4 rotPtr)
{
  char *outReady;
  undefined4 uStack_4;

  // Decompiler artifact: out-byte lives on stack; asm is lea [esp+7] / push.
  uStack_4 = phys;
  outReady = (char *)FUN_005070b0((int)&uStack_4 + 3);
  if ((*outReady == '\0') && (*(int *)(phys + 0x44) != 0)) {
    FUN_005070d0();
  }

  // Fully-ready skip: only push rotation when NOT (byte_40 && field_08).
  if ((*(char *)(phys + 0x40) == '\0') || (*(int *)(phys + 8) == 0)) {
    // body = *(phys+0x3c); no null check — null body faults like retail.
    (**(code **)(**(int **)(phys + 0x3c) + 0x44))(rotPtr);
  }
  return;
}
