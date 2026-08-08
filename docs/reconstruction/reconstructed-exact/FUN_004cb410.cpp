// =============================================================================
// FUN_004cb410  (clean twin — Ghidra symbol)
// Named: SkillCNDHash_AllocBucketTable_Inferred
// Stable ID: aa_004cb410 | VA 0x004cb410–0x004cb4a0 | WQ9E-A 2026-08-04
// =============================================================================

#include <cstdint>
#include <cstdlib>

extern void *operator new[](std::size_t n);
extern void FUN_007a4480(int level, const char *msg);
extern void _CxxThrowException(void *pExceptionObject, void *pThrowInfo);
extern void *PTR_LAB_009cb970;
extern void *DAT_00acc430;

void __thiscall FUN_004cb410(int param_1)
{
  char log2 = *reinterpret_cast<char *>(param_1 + 0x1c);
  if (!(log2 > 0 && log2 < 0x11)) {
    FUN_007a4480(0, "VOG_DEBUG_STOP");
    int code = static_cast<int>(0x80004003u);
    _CxxThrowException(&code, &DAT_00acc430);
  }

  int N = *reinterpret_cast<int *>(param_1 + 8);
  void **table = static_cast<void **>(operator new[](static_cast<std::size_t>(N) * 4u));
  *reinterpret_cast<void ***>(param_1 + 0x10) = table;

  void *slab = std::malloc(static_cast<std::size_t>(N) * 0xCu);
  std::uint32_t i = 0;
  if (N != 0) {
    do {
      table[i] = static_cast<char *>(slab) + i * 0xC;
      std::uint32_t *sent = static_cast<std::uint32_t *>(table[i]);
      i = i + 1;
      *sent = reinterpret_cast<std::uint32_t>(&PTR_LAB_009cb970);
      sent[1] = 0;
      sent[2] = 0;
    } while (i < static_cast<std::uint32_t>(N));
  }

  *reinterpret_cast<int *>(param_1 + 8) = N - 1;
}
