// =============================================================================
// FUN_004c5510  (inventory twin → Object_ApplyPrimaryAndLocalMaterialBanks_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004c5510
// Address:   0x004c5510–0x004c555d  (autoassault.exe, image base 0x400000)
// System:    object / gfx material bank
// Generated: 2026-07-23 scaffold; **sealed 2026-08-05** dual A/B R10-029
// Exactness: Behavior-preserving rewrite of decompiler + sealed primary this-adjust.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-08-05)
// =============================================================================

/*
 * Behavioral notes (2026-08-05 seal):
 * - Canonical name: Object_ApplyPrimaryAndLocalMaterialBanks_Inferred
 * - thiscall ECX = MI subobject; JMP adjustor entries at 0x004cc9f3 / 0x0053bcf9
 * - Path A: primary = (this-0x4FC) + *(vbptr+4); FUN_0051b310(primary)
 * - Path B: if host@-0x27C and bank begin@-0x208 non-null and count>>4:
 *           FUN_005194f0(host, this-0x20C)
 * - See Object_ApplyPrimaryAndLocalMaterialBanks_Inferred.cpp for typed port body.
 */

#include <cstdint>

extern "C" void __fastcall FUN_0051b310(void *self);
extern "C" void FUN_005194f0(void *shaderHost, void *colorVecHeader);

extern "C" void __fastcall FUN_004c5510(void *subThis)
{
  auto *base = reinterpret_cast<std::uint8_t *>(subThis);

  auto *vbptr = *reinterpret_cast<std::uint8_t **>(base - 0x4FC);
  auto delta = *reinterpret_cast<std::int32_t *>(vbptr + 4);
  void *primary = base - 0x4FC + delta;
  FUN_0051b310(primary);

  void *host = *reinterpret_cast<void **>(base - 0x27C);
  if (host == nullptr) {
    return;
  }

  void *begin = *reinterpret_cast<void **>(base - 0x208);
  void *bankHeader = base - 0x20C;
  if (begin == nullptr) {
    return;
  }

  void *end = *reinterpret_cast<void **>(static_cast<std::uint8_t *>(bankHeader) + 8);
  auto count = static_cast<std::intptr_t>(
      reinterpret_cast<std::uint8_t *>(end) -
      reinterpret_cast<std::uint8_t *>(begin)) >> 4;
  if (count == 0) {
    return;
  }

  FUN_005194f0(host, bankHeader);
}
