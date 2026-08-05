// =============================================================================
// FUN_005be310  (scaffold twin of Emitter_ReleaseToFreelist_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_005be310
// Address:   0x005be310–0x005be32e exclusive (30 B / 0x1e)
// Dual:      W30-R 2026-07-29 — accept
// Prefer:    Emitter_ReleaseToFreelist_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_005bbc50(void *node);

// Ghidra shape (param_1 = this freelist head*; param_2 = stack node).
// Bytes rebind ECX = param_2 before FUN_005bbc50; decompiler omits that.
void __thiscall FUN_005be310(uint32_t *param_1, uint32_t *param_2)
{
  FUN_005bbc50(param_2);

  if (param_2 != nullptr) {
    *param_2 = *param_1;
    *param_1 = reinterpret_cast<uint32_t>(param_2);
  }
}
