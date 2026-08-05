// =============================================================================
// Emitter_ReleaseToFreelist_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005be310
// Address:   0x005be310–0x005be32e exclusive (30 B / 0x1e)
// Module:    autoassault.exe (image base 0x400000)
// System:    client NDSpecialFX / emitter freelist
// Dual:      W30-R 2026-07-29 — accept
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte ABI.
// Bit-for-bit / runtime / differential: OPEN
// =============================================================================
//
// PURPOSE:
//   Teardown an emitter payload body, then freelist-push it onto the global
//   emitter freelist head (call sites always pass ECX = &DAT_00b454fc).
//
// ABI:
//   __thiscall; ECX = freelist head*; stack Emitter* node; RET 4; void
//
// CALLERS (sealed sites):
//   - NDSpecialFX_HostTick_Inferred (FUN_004b8ed0) @ 0x004b913b
//       kill path after Emitter_UpdateTick_Inferred returns 0
//   - NDSpecialFX_ClearChildLists_Inferred (FUN_004b85d0) @ 0x004b85eb
//       walk host list +0x1E0; release each node[2] payload
//   - FUN_004a34f0 ×7 (same B9 FC 54 B4 00 freelist load)
//
// CALLEE:
//   FUN_005bbc50 — heavy emitter/host body teardown (W30-S owns full dual).
//   Bytes rebind ECX = node before call; decompiler shows bare FUN_005bbc50().
//
// NOTES:
//   - Does NOT operator_delete the emitter — recycles via freelist dword0 next.
//   - HostTick owns list-node unlink/delete; this unit only releases the payload.
//   - Distinct freelist from ObjectMotion slots (DAT_00b036c0).
// =============================================================================

#include <cstdint>

// Forward: full dual owned by W30-S (not sealed here).
extern "C" void __fastcall FUN_005bbc50(void *emitter_node);

// Global freelist head used by all known call sites.
extern "C" void *DAT_00b454fc;

struct EmitterFreelistNode {
  EmitterFreelistNode *next; // dword0
  // ... remainder of emitter body owned by teardown child ...
};

// __thiscall; ECX = freelist head*; stack node; ret 4
extern "C" void __thiscall Emitter_ReleaseToFreelist_Inferred(
    EmitterFreelistNode **freelist_head,
    EmitterFreelistNode *node)
{
  // Bytes: mov ecx, node; call FUN_005bbc50
  FUN_005bbc50(node);

  if (node != nullptr) {
    node->next = *freelist_head;
    *freelist_head = node;
  }
}
