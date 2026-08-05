// =============================================================================
// FUN_0051ba40  — scaffold twin of CNDHash_AllocBucketTable_009ce090
// -----------------------------------------------------------------------------
// Stable ID: aa_0051ba40
// Address:   0x0051ba40–0x0051bad0  (autoassault.exe @ 0x400000)
// Dual A/B:  2026-07-29 W25-F
// Prefer named plate: CNDHash_AllocBucketTable_009ce090.cpp
// =============================================================================

#include <cstdint>
#include <cstdlib>

extern void *operator new[](std::size_t n);
extern void FUN_007a4480(int level, const char *msg);
extern void _CxxThrowException(void *pExceptionObject, void *pThrowInfo);
extern void *PTR_LAB_009ce090;
extern void *DAT_00acc430;

void __fastcall FUN_0051ba40(int param_1)
{
  int local_4 = param_1;
  if (('\0' < *reinterpret_cast<char *>(param_1 + 0x1c)) &&
      (*reinterpret_cast<char *>(param_1 + 0x1c) < '\x11')) {
    void *pvVar2 = operator new[](
        static_cast<std::size_t>(*reinterpret_cast<int *>(param_1 + 8)) * 4u);
    *reinterpret_cast<void **>(param_1 + 0x10) = pvVar2;
    pvVar2 = std::malloc(
        static_cast<std::size_t>(*reinterpret_cast<int *>(param_1 + 8)) * 0xCu);
    std::uint32_t uVar3 = 0;
    if (*reinterpret_cast<int *>(param_1 + 8) != 0) {
      do {
        *reinterpret_cast<void **>(
            *reinterpret_cast<int *>(param_1 + 0x10) + uVar3 * 4) = pvVar2;
        std::uint32_t *puVar1 = *reinterpret_cast<std::uint32_t **>(
            *reinterpret_cast<int *>(param_1 + 0x10) + uVar3 * 4);
        uVar3 = uVar3 + 1;
        *puVar1 = reinterpret_cast<std::uint32_t>(&PTR_LAB_009ce090);
        puVar1[1] = 0;
        puVar1[2] = 0;
        pvVar2 = reinterpret_cast<void *>(
            reinterpret_cast<char *>(pvVar2) + 0xC);
      } while (uVar3 < *reinterpret_cast<std::uint32_t *>(param_1 + 8));
    }
    *reinterpret_cast<int *>(param_1 + 8) =
        *reinterpret_cast<int *>(param_1 + 8) + -1;
    return;
  }
  FUN_007a4480(0, "VOG_DEBUG_STOP");
  local_4 = -0x7fffbffd; // 0x80004003
  _CxxThrowException(&local_4, &DAT_00acc430);
}
