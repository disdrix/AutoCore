// =============================================================================
// FUN_004062a0 — scaffold twin of StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004062a0
// Address:   0x004062a0  (autoassault.exe, image base 0x400000)
// System:    util / container (elem 0xC)
// Generated: 2026-08-04 WQ9H-C (refined from 2026-07-23 scaffold)
// Prefer named clean: StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred.cpp
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" void FUN_00409db0(void* dest, int count);
extern "C" void** FUN_00406e70(void* vec, void** outIt, void* where, const void* value);

// Ghidra surface: void __fastcall FUN_004062a0(undefined4 param_1) + in_EAX host.
// Recovered: EAX=vec*, ECX=value*, ret 0.

extern "C" void FUN_004062a0(
    /*EAX*/ void* vec,
    /*ECX*/ const void* value)
{
  int begin = *reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 4);

  if (begin != 0 &&
      static_cast<unsigned>(
          (*reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 8) - begin) /
          0xc) <
          static_cast<unsigned>(
              (*reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 0xc) - begin) /
              0xc)) {
    int end = *reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 8);
    FUN_00409db0(reinterpret_cast<void*>(end), 1);
    *reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 8) = end + 0xc;
    return;
  }

  void* outScratch = const_cast<void*>(value);
  FUN_00406e70(
      vec,
      &outScratch,
      *reinterpret_cast<void**>(reinterpret_cast<char*>(vec) + 8),
      value);
}
