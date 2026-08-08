// =============================================================================
// StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00418d70
// Address:   0x00418d70  (autoassault.exe, image base 0x400000)
// Body:      0x00418d70–0x00418dc6 exclusive (86 B / 0x56); dual RET 4; pad CC
// System:    util / container (std::vector elem stride 8)
//            Partition residual: skills-abilities under parent 0x005755b0
// Generated: 2026-08-05 R10-025 dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// Dual A/B: accept-with-gaps (2026-08-05).
// Ghidra:    FUN_00418d70
// Prior:     Named_CalleeOf_Named_VOG_DEBUG_STOP_00418d70 (rejected parent-string plate)
// =============================================================================
//
// PURPOSE:
//   MSVC-style vector::push_back for 8-byte POD elements (two dwords).
//   Fast path: raw copy value[0], value[1] at end when begin!=0 and size < capacity.
//   Slow path: insert-one + rebind at end via FUN_00418e10 (undualed residual).
//
// ABI (sealed from bytes + parent call site):
//   ECX      = vector*  (begin@+4, end@+8, capEnd@+0xC)
//   [ESP+4]  = const T* value (pointer to 8-byte POD)
//   ret      = none; RET 4 (thiscall, 1 stack arg)
//
// CALLEES:
//   FUN_00418e10 — insert-one / rebind at end (grow)
//
// CALLERS (13 xrefs / 8 named + orphans):
//   0x0057567e — VehicleCrew_InsertMember_Inferred (parent dual; LEA ECX,[ESI+0x1F4])
//   FUN_004d4040 x2, FUN_004deb20, FUN_004dfcc0, FUN_005acef0,
//   FUN_005ea300, FUN_006082e0 x2, FUN_0080af70, orphans 00564eab/00564f4b/005ad471
//
// RELATED:
//   Twin shape: StdVector_PushBack_Elem12 / Elem0x28 (different ABI/stride)
//   Parent: VehicleCrew_InsertMember_Inferred pushes COID pair into host+0x1F4
// =============================================================================

#include <cstdint>

// Slow-path insert-one (ECX=vec). Signature simplified; undualed.
extern "C" void FUN_00418e10(
    void* vec /*ECX*/,
    void** outIt,
    void* where,
    const void* value);

extern "C" void StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred(
    void* vec /*ECX*/,
    const uint32_t* value /*stack*/)
{
  int begin = *reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 4);
  unsigned size;
  if (begin == 0) {
    size = 0;
  } else {
    size = static_cast<unsigned>(
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 8) - begin) >> 3);
  }

  if (begin != 0) {
    unsigned capacity = static_cast<unsigned>(
        (*reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 0xc) - begin) >> 3);
    if (size < capacity) {
      uint32_t* end =
          *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(vec) + 8);
      end[0] = value[0];
      end[1] = value[1];
      *reinterpret_cast<uint32_t**>(reinterpret_cast<char*>(vec) + 8) = end + 2;
      return;
    }
  }

  void* outScratch = const_cast<uint32_t*>(value);
  void* end = *reinterpret_cast<void**>(reinterpret_cast<char*>(vec) + 8);
  FUN_00418e10(vec, &outScratch, end, value);
}
