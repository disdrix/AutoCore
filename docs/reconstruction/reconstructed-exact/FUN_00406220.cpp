// =============================================================================
// FUN_00406220 — scaffold twin of StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00406220
// Address:   0x00406220  (autoassault.exe, image base 0x400000)
// System:    util / container (elem 0x28)
// Generated: 2026-08-04 WQ9H-C (refined from 2026-07-23 scaffold)
// Prefer named clean: StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void FUN_00409d40(void* dest, int count);
extern "C" void** FUN_00406de0(void* vec, void** outIt, void* where, const void* value);

// Ghidra surface: void __fastcall FUN_00406220(undefined4 param_1) + in_EAX host.
// Recovered: EAX=vec*, ECX=value*, ret 0.

extern "C" void FUN_00406220(
    /*EAX*/ void* vec,
    /*ECX*/ const void* value)
{
  int begin = *reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 4);

  if (begin != 0 &&
      static_cast<unsigned>(
          (*reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 8) - begin) /
          0x28) <
          static_cast<unsigned>(
              (*reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 0xc) - begin) /
              0x28)) {
    int end = *reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 8);
    FUN_00409d40(reinterpret_cast<void*>(end), 1);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 8) = end + 0x28;
    return;
  }

  void* outScratch = const_cast<void*>(value);
  FUN_00406de0(
      vec,
      &outScratch,
      *reinterpret_cast<void**>(reinterpret_cast<char*>(vec) + 8),
      value);
}
