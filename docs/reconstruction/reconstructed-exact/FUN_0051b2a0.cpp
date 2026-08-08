// =============================================================================
// FUN_0051b2a0  (clean twin of Object_LazyFillMatColorVecFromMesh_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b2a0
// Address:   0x0051b2a0–0x0051b302 exclusive
// Dual:      2026-08-04 WQ9R-H — see Object_LazyFillMatColorVecFromMesh_Inferred.cpp
// =============================================================================

#include <cstdint>

using VProbe = void *(__thiscall *)(void *self);

extern "C" void FUN_00519280(
    void *mesh_mat_list,
    void *color_bank_host,
    std::uint32_t c0,
    std::uint32_t c1,
    std::uint32_t c2,
    std::uint32_t c3);

extern "C" void __thiscall FUN_0051b2a0(
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
