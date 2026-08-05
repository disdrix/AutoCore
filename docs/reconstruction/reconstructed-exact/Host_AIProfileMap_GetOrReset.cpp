// =============================================================================
// Host_AIProfileMap_GetOrReset
// -----------------------------------------------------------------------------
// Stable ID: aa_00540890
// Address:   0x00540890 – 0x005408e9 (90 B inclusive last RET)
// Module:    autoassault.exe base 0x400000
// System:    npc-ai / host tables / profile map
// Generated: 2026-07-29 W26-N dual seal (live decompile ≡ raw 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// =============================================================================
//
// PURPOSE: Return the host AI-profile std::map-like container at host+0xF00.
//   If map size is 0 OR forceReset != 0: free RB nodes, re-link sentinel head,
//   zero size, call FUN_007c3b80(map). Callers (HBAI DoLogic twins, etc.) then
//   lower_bound via FUN_004cbd50 on def float key +0x4DC.
//
// Convention: MSVC __thiscall
//   this        host* (call sites: MOV ECX,[DAT_00b041fc])
//   forceReset  char stack; RET 4
//   return      EAX = this+0xF00 (map base; end iterator = *(map+4) head)
//
// Layout:
//   host+0xF00  map object (return)
//   host+0xF04  head / sentinel node*
//   host+0xF08  size (dword)
//
// Dual A/B: reviews/A_aa_00540890_*.md + B_aa_00540890_*.md (W26-N)
// =============================================================================

#include <stdint.h>

extern void FUN_005436c0(void *node);   // recursive tree free (not owned)
extern void FUN_007c3b80(void *map);    // global ECX=DAT_00b0469c at call (not owned)

uint32_t __thiscall Host_AIProfileMap_GetOrReset(int host, char forceReset)
{
  if ((*(int *)(host + 0xf08) == 0) || (forceReset != '\0')) {
    FUN_005436c0(*(void **)(*(int *)(host + 0xf04) + 4));
    *(int *)(*(int *)(host + 0xf04) + 4) = *(int *)(host + 0xf04);
    *(uint32_t *)(host + 0xf08) = 0;
    **(uint32_t **)(host + 0xf04) = *(uint32_t *)(host + 0xf04);
    *(int *)(*(int *)(host + 0xf04) + 8) = *(int *)(host + 0xf04);
    FUN_007c3b80((void *)(host + 0xf00));
  }
  return (uint32_t)(host + 0xf00);
}
