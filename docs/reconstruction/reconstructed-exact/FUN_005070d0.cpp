// =============================================================================
// FUN_005070d0  /  CVOGPhysics_PrepareReady
// -----------------------------------------------------------------------------
// Stable ID: aa_005070d0
// Address:   0x005070d0  (autoassault.exe, image base 0x400000)
// System:    physics
// Generated: 2026-07-29 dual A/B seal (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite. Call ABI corrected from read_memory
//            (Ghidra decompile drops ECX=*(param_1+8) on both callees).
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE: Physics prepare / ensure-ready before body vtbl writes.
// See: reconstructed-exact/CVOGPhysics_PrepareReady.cpp
// Dual: reviews/A_aa_005070d0_CVOGPhysics_PrepareReady.md
//       reviews/B_aa_005070d0_CVOGPhysics_PrepareReady.md

void __thiscall FUN_0055e490(int world, int phys);
void __thiscall FUN_0055eb80(int world, int host);

void __fastcall FUN_005070d0(int param_1)
{
  int world;
  int host;

  world = *(int *)(param_1 + 8);
  if (world != 0) {
    FUN_0055e490(world, param_1);
    host = *(int *)(param_1 + 0x44);
    if ((*(char *)(host + 0x29) == '\0') && (*(int *)(host + 0x24) != -1)) {
      FUN_0055eb80(world, host);
    }
  }
  return;
}
