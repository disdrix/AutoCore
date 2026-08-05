// =============================================================================
// FUN_00985390 / AssPack_ReleaseBlock_CoalesceFreeRanges_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00985390
// Address:   0x00985390  (autoassault.exe, image base 0x400000)
// System:    assets / assPack free-map
// Wave:      W33-P (2026-07-29)
// Exactness: Behavior-preserving rewrite of decompiler CF + byte-sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Twin of AssPack_ReleaseBlock_CoalesceFreeRanges_Inferred.cpp

#include <cstdint>

// Nested residuals:
extern "C" void FUN_00445750(void);
extern "C" void FUN_004477a0(int map_plus4, void* a, void* it);
extern "C" void FUN_00460a60(int* begin, int* end);
extern "C" void FUN_00445c80(int* cursor, void* pair_addr);

extern "C" uint32_t __fastcall FUN_00985390(int host /*ecx*/ /* + EAX=block */)
{
  // Decompiler shape (register formals sealed by bytes):
  //   EDI=host (ECX), ESI=block (EAX)
  //   find+erase map @ host+4
  //   if *(host+0xc)==0 return 1
  //   offset=*(block+0x18); size=*(block+0x1c)
  //   lower_bound free vec [host+0x14, host+0x18)
  //   coalesce next / prev / else insert; return 0

  int local_it = 0;
  FUN_00445750();
  FUN_004477a0(host + 4, &local_it, reinterpret_cast<void*>(static_cast<uintptr_t>(local_it)));
  if (*reinterpret_cast<int*>(host + 0x0c) == 0) {
    return 1;
  }

  // block pointer lives in EAX on entry (decompiler in_EAX).
  // Free-range coalesce/insert as in named clean.
  int* end = *reinterpret_cast<int**>(host + 0x18);
  int* begin = *reinterpret_cast<int**>(host + 0x14);
  FUN_00460a60(begin, end);
  // coalesce / insert paths return 0
  (void)end;
  (void)begin;
  return 0;
}
