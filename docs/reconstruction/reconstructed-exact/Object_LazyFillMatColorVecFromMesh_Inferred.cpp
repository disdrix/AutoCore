// =============================================================================
// Object_LazyFillMatColorVecFromMesh_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b2a0
// Address:   0x0051b2a0–0x0051b302 exclusive (autoassault.exe, image base 0x400000)
// System:    object / mesh material color bank
// Generated: 2026-07-23 scaffold; **sealed 2026-08-04** dual A/B WQ9R-H
// Exactness: Behavior-preserving. Seals empty-vector guard, vtbl+0x1CC probe,
//            FUN_00519280 forward, RET 0x10 from read_memory.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-08-04)
// Product:   open; material strings live in callee FUN_00519280
// =============================================================================

/*
 * Behavioral notes (2026-08-04 seal):
 * - __thiscall + 4 stack dwords; RET 0x10.
 * - If vector at this+0x148/0x14C non-empty (stride 0x10), return.
 * - Else vcall vtbl+0x1CC; if probe && probe+8: FUN_00519280(probe+8, this+0x144, c0..c3).
 * - FUN_00519280 fills MatDiffuse/Ambient/Emissive float4 bank (owned dual elsewhere).
 */

#include <cstdint>

using VProbe = void *(__thiscall *)(void *self);

extern "C" void FUN_00519280(
    void *mesh_mat_list,
    void *color_bank_host,
    std::uint32_t c0,
    std::uint32_t c1,
    std::uint32_t c2,
    std::uint32_t c3);

extern "C" void __thiscall Object_LazyFillMatColorVecFromMesh_Inferred(
    void *self,
    std::uint32_t c0,
    std::uint32_t c1,
    std::uint32_t c2,
    std::uint32_t c3)
{
  auto *base = reinterpret_cast<std::uint8_t *>(self);
  auto *begin = *reinterpret_cast<std::uint8_t **>(base + 0x148);
  auto *end   = *reinterpret_cast<std::uint8_t **>(base + 0x14C);

  if (begin != nullptr) {
    const std::ptrdiff_t count = (end - begin) >> 4;
    if (count != 0) {
      return;
    }
  }

  auto *vtbl = *reinterpret_cast<std::uint8_t **>(self);
  auto probe_fn = *reinterpret_cast<VProbe *>(vtbl + 0x1CC);
  void *probe = probe_fn(self);
  if (probe == nullptr) {
    return;
  }

  void *mat_list = *reinterpret_cast<void **>(reinterpret_cast<std::uint8_t *>(probe) + 8);
  if (mat_list == nullptr) {
    return;
  }

  FUN_00519280(mat_list, base + 0x144, c0, c1, c2, c3);
}
