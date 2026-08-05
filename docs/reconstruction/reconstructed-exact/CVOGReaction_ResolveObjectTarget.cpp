// =============================================================================
// CVOGReaction_ResolveObjectTarget
// -----------------------------------------------------------------------------
// Stable ID: aa_004bae70
// Address:   0x004bae70  (autoassault.exe, image base 0x400000)
// System:    object-resolve / reaction
// Generated: 2026-07-23 scaffold; **strengthened 2026-07-29** from read_memory body
// Exactness: Behavior-preserving rewrite. Decompiler omitted table ECX select —
//            clean follows image (mov ecx,[ecx+4|8] before FUN_004e3260).
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes (2026-07-29 seal):
 * - __thiscall: ECX = resolve context; stack = bGlobal, coidLo, coidHi; ret 0x0c.
 * - Invalid TFID when (coidLo & coidHi) == 0xFFFFFFFF (both halves all-ones).
 * - bGlobal==0: gate ctx+0xd, lookup hash table *(ctx+0x8).
 * - bGlobal!=0: gate ctx+0xc, lookup hash table *(ctx+0x4).
 * - FUN_004e3260 is __thiscall on the selected table; returns object* at node+0xc.
 * - No stores; pure resolve.
 */

#include <cstdint>

// Hash-table lookup (aa_004e3260) — thiscall on table; not owned by this unit.
extern "C" void * __thiscall FUN_004e3260(void *pTable, std::uint32_t coidLo, std::uint32_t coidHi);

void * __thiscall CVOGReaction_ResolveObjectTarget(
    void *ctx,
    std::uint8_t bGlobal,
    std::uint32_t coidLo,
    std::uint32_t coidHi)
{
  if ((coidLo & coidHi) == 0xFFFFFFFFu) {
    return nullptr;
  }

  if (bGlobal != 0) {
    // Global / non-zero TFID domain
    if (*reinterpret_cast<std::uint8_t *>(reinterpret_cast<char *>(ctx) + 0xc) == 0) {
      return nullptr;
    }
    void *pTable = *reinterpret_cast<void **>(reinterpret_cast<char *>(ctx) + 0x4);
    return FUN_004e3260(pTable, coidLo, coidHi);
  }

  // Local / bGlobal==0 domain
  if (*reinterpret_cast<std::uint8_t *>(reinterpret_cast<char *>(ctx) + 0xd) == 0) {
    return nullptr;
  }
  void *pTable = *reinterpret_cast<void **>(reinterpret_cast<char *>(ctx) + 0x8);
  return FUN_004e3260(pTable, coidLo, coidHi);
}
