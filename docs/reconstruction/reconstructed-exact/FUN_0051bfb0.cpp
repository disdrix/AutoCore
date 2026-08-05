// =============================================================================
// FUN_0051bfb0  — scaffold twin of CNDHash_ReclaimAll_ValueOwning_009ce0a8
// -----------------------------------------------------------------------------
// Stable ID: aa_0051bfb0
// Address:   0x0051bfb0–0x0051c021  (autoassault.exe @ 0x400000)
// Dual A/B:  2026-07-29 W25-F
// Prefer named plate: CNDHash_ReclaimAll_ValueOwning_009ce0a8.cpp
// =============================================================================

#include <cstdint>

extern void operator_delete(void *p);
extern void __fastcall FUN_00604e30(void *value);
extern void *PTR_FUN_009ce0a8;

void __fastcall FUN_0051bfb0(int param_1)
{
  std::uint32_t uVar5 = 0;
  do {
    std::uint32_t *puVar4 = *reinterpret_cast<std::uint32_t **>(
        *reinterpret_cast<int *>(*reinterpret_cast<int *>(param_1 + 0x10) + uVar5 * 4) + 4);
    while (puVar4 != nullptr) {
      void *pvVar2 = reinterpret_cast<void *>(puVar4[2]);
      std::uint32_t *puVar3 = reinterpret_cast<std::uint32_t *>(puVar4[3]);
      *puVar4 = reinterpret_cast<std::uint32_t>(&PTR_FUN_009ce0a8);
      if (pvVar2 != nullptr) {
        FUN_00604e30(pvVar2);
        operator_delete(pvVar2);
      }
      puVar4[2] = 0;
      *puVar4 = *reinterpret_cast<std::uint32_t *>(param_1 + 0x20);
      *reinterpret_cast<std::uint32_t **>(param_1 + 0x20) = puVar4;
      puVar4 = puVar3;
    }
    int iVar1 = static_cast<int>(uVar5 * 4);
    uVar5 = uVar5 + 1;
    *reinterpret_cast<std::uint32_t *>(
        *reinterpret_cast<int *>(*reinterpret_cast<int *>(param_1 + 0x10) + iVar1) + 4) = 0;
  } while (uVar5 <= *reinterpret_cast<std::uint32_t *>(param_1 + 8));
}
