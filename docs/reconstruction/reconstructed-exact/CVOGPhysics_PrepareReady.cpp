// =============================================================================
// CVOGPhysics_PrepareReady
// -----------------------------------------------------------------------------
// Stable ID: aa_005070d0
// Address:   0x005070d0  (autoassault.exe, image base 0x400000)
// System:    physics
// Generated: 2026-07-29 dual A/B (asm-correct ABI; Ghidra one-arg forms rejected)
// Exactness: Behavior-preserving rewrite of decompiler control flow + sealed call ABI.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE:
// Ensure the physics host at phys+0x44 is activated in the sim context at phys+8
// and marked ready (host+0x29 = 1 via FUN_0055eb80). Shared write-enable used
// before rigid-body vtbl stores (lin/ang/impulse/pos helpers).
//
// Sibling probe: FUN_005070b0 @ 0x005070b0 (read host+0x29; 0 if host null).
//
// Standard caller pattern:
//   FUN_005070b0(phys, &out);
//   if (*out == 0 && *(phys+0x44) != 0) CVOGPhysics_PrepareReady(phys);
//   body = *(phys+0x3c); body->vtbl[slot](...);

/*
 * Offsets (this = CVOGPhysics*):
 *   +0x08  world / sim context (null → no-op)
 *   +0x44  host object (ready flag at host+0x29; index at host+0x24)
 *
 * Callees (interface only):
 *   FUN_0055e490(world, phys)  — world-side list bookkeeping (often no-op)
 *   FUN_0055eb80(world, host)  — activate host; sets host+0x29 = 1
 */

// Callee decls (names tentative; signatures from call-site asm + callee prologues)
void __thiscall FUN_0055e490(void *world, void *phys);
void __thiscall FUN_0055eb80(void *world, void *host);

void __fastcall CVOGPhysics_PrepareReady(void *phys)
{
  void *world;
  void *host;

  world = *(void **)((char *)phys + 0x08);
  if (world == 0) {
    return;
  }

  FUN_0055e490(world, phys);

  host = *(void **)((char *)phys + 0x44);
  /* no null check — callers usually gate via probe + (phys+0x44)!=0 */
  if (*(unsigned char *)((char *)host + 0x29) == 0 &&
      *(int *)((char *)host + 0x24) != -1) {
    FUN_0055eb80(world, host);
  }
  return;
}
