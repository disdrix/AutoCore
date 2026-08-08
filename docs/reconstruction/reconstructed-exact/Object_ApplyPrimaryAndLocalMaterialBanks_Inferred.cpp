// =============================================================================
// Object_ApplyPrimaryAndLocalMaterialBanks_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004c5510
// Address:   0x004c5510–0x004c555d  (autoassault.exe, image base 0x400000)
// System:    object / gfx material bank
// Generated: 2026-07-23 scaffold as FUN_004c5510; **sealed 2026-08-05** dual A/B R10-029
// Exactness: Behavior-preserving. Primary this-adjust + local bank gates sealed from
//            decompile + disassemble_function + read_memory (not modernization).
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-08-05)
// =============================================================================

/*
 * Behavioral notes (2026-08-05 seal):
 * - thiscall: ECX = multiple-inheritance **subobject** this (entry via JMP adjustors).
 * - Path A: recompute primary object from vbptr-like at this-0x4FC:
 *     primary = (this - 0x4FC) + *(int*)(*(this-0x4FC) + 4)
 *   then Object_ApplyMaterialBank_Inferred(primary)  // FUN_0051b310
 *   (that callee owns bank +0x144 and vtbl+0x1CC host resolution — not re-owned here).
 * - Path B: if host*(this-0x27C) and local bank begin*(this-0x208) non-null and
 *   count ((end-begin)>>4) non-zero, call
 *   Gfx_BindMatDiffuseAmbientEmissive_Inferred(host, this-0x20C)  // FUN_005194f0
 *   bank header layout: begin@+4 end@+8, float4 stride 0x10.
 * - Decompiler shows FUN_0051b310() without this rewrite — **bytes win**.
 * - Preserves ECX (PUSH/POP ECX); ESI holds subThis until count clobber.
 * - cdecl binder cleaned with ADD ESP,8; bare RET.
 * - Not a skill-cast helper; residual R10 skills-abilities partition address only.
 */

#include <cstdint>

// Nested callees — dual-owned elsewhere (not rewritten here).
extern "C" void __fastcall Object_ApplyMaterialBank_Inferred(void *self /* ECX */);
extern "C" void Gfx_BindMatDiffuseAmbientEmissive_Inferred(
    void *shaderHost, void *colorVecHeader /* begin@+4 end@+8 */);

extern "C" void __fastcall Object_ApplyPrimaryAndLocalMaterialBanks_Inferred(void *subThis)
{
  auto *base = reinterpret_cast<std::uint8_t *>(subThis);

  // Path A — primary material bank apply (bytes: [ESI-0x4FC] table + LEA)
  auto *vbptr = *reinterpret_cast<std::uint8_t **>(base - 0x4FC);
  auto delta = *reinterpret_cast<std::int32_t *>(vbptr + 4);
  void *primary = base - 0x4FC + delta;
  Object_ApplyMaterialBank_Inferred(primary);

  // Path B — local host + local color bank
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

  Gfx_BindMatDiffuseAmbientEmissive_Inferred(host, bankHeader);
}
