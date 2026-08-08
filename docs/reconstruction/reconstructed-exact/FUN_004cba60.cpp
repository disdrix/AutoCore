// =============================================================================
// FUN_004cba60  (clean twin — Ghidra symbol)
// Named: SkillCNDHash_DestroyBucketTable_Inferred
// Stable ID: aa_004cba60 | VA 0x004cba60–0x004cba93 | WQ9E-A 2026-08-04
// =============================================================================

#include <cstdint>
#include <cstdlib>

extern void FUN_004cb680(void);
extern void operator delete[](void *p);

void __thiscall FUN_004cba60(int param_1)
{
  *reinterpret_cast<uint32_t *>(param_1 + 0x0c) = 0;
  FUN_004cb680();
  void **table = *reinterpret_cast<void ***>(param_1 + 0x10);
  if (table != nullptr) {
    std::free(*table);
    operator delete[](table);
    *reinterpret_cast<uint32_t *>(param_1 + 0x10) = 0;
  }
}
