// =============================================================================
// StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004062a0
// Address:   0x004062a0  (autoassault.exe, image base 0x400000)
// Body:      0x004062a0–0x00406316 exclusive (118 B / 0x76); ret 0; pad CC
// System:    util / container (std::vector elem stride 0xC / 12)
// Generated: 2026-08-04 WQ9H-C dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// Dual A/B: accept-with-gaps (2026-08-04).
// Ghidra:    FUN_004062a0
// =============================================================================
//
// PURPOSE:
//   MSVC-style vector::push_back for 12-byte POD elements.
//   Fast path: construct one element at end when size < capacity.
//   Slow path: insert-one + rebind at end via dualed 0x00406e70.
//
// ABI (sealed from bytes + sole caller site):
//   EAX  = vector*  (begin@+4, end@+8, capEnd@+0xC)
//   ECX  = const T* value (pointer to 12-byte POD)
//   ret  = none (plain C3)
//
// CALLEES:
//   FUN_00409db0 — ConstructN for elem 0xC (copy leaf FUN_00409f50)
//   FUN_00406e70 — StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred (WQ9G-I)
//
// CALLERS (1):
//   0x00930d53 — MOV EAX,0x00d1a82c (static vec); LEA ECX,[ESP] local T[12]
//
// TWIN:
//   aa_00406220 StdVector_PushBack_Elem0x28_EaxVec_EcxVal_Inferred (stride 0x28)
// =============================================================================

#include <cstdint>

extern "C" void FUN_00409db0(/*stack*/ void* dest, /*stack*/ int count);

extern "C" void** StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred(
    void* vec /*EDI*/,
    void** outIt,
    void* where,
    const void* value);

extern "C" void StdVector_PushBack_Elem12_EaxVec_EcxVal_Inferred(
    void* vec /*EAX*/,
    const void* value /*ECX*/)
{
  int begin = *reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 4);

  if (begin != 0) {
    unsigned size =
        static_cast<unsigned>(
            (*reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 8) - begin) /
            0xc);
    unsigned capacity =
        static_cast<unsigned>(
            (*reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 0xc) - begin) /
            0xc);
    if (size < capacity) {
      int end = *reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 8);
      FUN_00409db0(reinterpret_cast<void*>(end), 1);
      *reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 8) = end + 0xc;
      return;
    }
  }

  void* outScratch = const_cast<void*>(value);
  void* end = *reinterpret_cast<void**>(reinterpret_cast<char*>(vec) + 8);
  StdVector_InsertOne_RebindIt_Elem12_EdiVec_Inferred(
      vec, &outScratch, end, value);
}
