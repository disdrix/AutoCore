// =============================================================================
// FUN_004bc7a0 → CNDHash_AllocBucketTable_009cb348
// -----------------------------------------------------------------------------
// Stable ID: aa_004bc7a0
// Address:   0x004bc7a0–0x004bc830  (autoassault.exe @ 0x400000)
// System:    container / CNDHash (sentinel stamp 0x009cb348)
// Dual A/B:  2026-07-29 W29-K
// Exactness: Behavior-preserving. Prefer named plate CNDHash_AllocBucketTable_009cb348.cpp
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================

#include <cstdint>
#include <cstdlib>

extern void *operator new[](std::size_t n);
extern void FUN_007a4480(int level, const char *msg);
extern void _CxxThrowException(void *pExceptionObject, void *pThrowInfo);
extern void *PTR_LAB_009cb348;
extern void *DAT_00acc430;

// void __thiscall — ECX = this; plain ret or noreturn throw
void __fastcall FUN_004bc7a0(int param_1)
{
  char log2 = *reinterpret_cast<char *>(param_1 + 0x1c);
  if (!(log2 >= 1 && log2 <= 0x10)) {
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
      *sent = reinterpret_cast<std::uint32_t>(&PTR_LAB_009cb348);
      sent[1] = 0;
      sent[2] = 0;
    } while (i < static_cast<std::uint32_t>(N));
  }

  *reinterpret_cast<int *>(param_1 + 8) = N - 1;
}
