// =============================================================================
// StdVector_InsertOne_RebindIt_Via419880_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0040b6d0
// Address:   0x0040b6d0  (autoassault.exe, image base 0x400000)
// Body:      0x0040b6d0–0x0040b713 (68 B / 0x44); ret 8; pad CC
// System:    util / container (std::vector dword)
// Generated: 2026-08-04 WQ7R-E dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// Dual A/B: accept (2026-08-04).
// Ghidra:    FUN_0040b6d0
// =============================================================================
//
// PURPOSE:
//   Insert exactly one 4-byte element into an MSVC-style vector, then rebind an
//   out-iterator so it remains valid after a possible reallocation of begin.
//
// ABI (customcc — sealed from bytes C2 08 00 + parent FUN_00411180):
//   EDI        = vector*  (begin@+4, end@+8, capEnd@+0xC)
//   EBX        = T** outIt
//   stack arg0 = T*  insert position (push_back passes end)
//   stack arg1 = const T* value
//   return     = EAX = EBX; ret 8
//
// CALLEE:
//   FUN_00419880 = StdVector_InsertN_Dword_CountEcx_Inferred (count forced to 1)
//
// TWINS:
//   aa_0040dbf0 StdVector_InsertOne_RebindIt_Thiscall_Inferred → FUN_004073a0
//   aa_00466da0 StdVector_InsertOne_RebindIt_Inferred           → FUN_00456960
//
// PARENT:
//   FUN_00411180 push_back: fast path *end++ when room; else this unit.
// =============================================================================

#include <cstdint>

// Count in ECX; stack (vec*, where*, value*); ret 0xC — dual-owned W23-D
extern "C" void StdVector_InsertN_Dword_CountEcx_Inferred(
    /*ECX*/ uint32_t count,
    /*stack*/ void* vec,
    /*stack*/ uint32_t* where,
    /*stack*/ const uint32_t* value);

// Customcc cannot be expressed portably; document register contract in plate.
// Body below mirrors recovered CF with explicit vec/out parameters for readability.

extern "C" uint32_t** StdVector_InsertOne_RebindIt_Via419880_Inferred(
    void* vec /*EDI*/,
    uint32_t** outIt /*EBX*/,
    uint32_t* where,
    const uint32_t* value)
{
  int begin = *reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 4);
  int index;
  if (begin == 0 ||
      ((*reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 8) - begin) >> 2) == 0) {
    index = 0;
  } else {
    index = (reinterpret_cast<int>(where) - begin) >> 2;
  }

  // Bytes: push value; push where; push vec; mov ecx,1; call FUN_00419880
  StdVector_InsertN_Dword_CountEcx_Inferred(1, vec, where, value);

  *outIt = reinterpret_cast<uint32_t*>(
      *reinterpret_cast<int*>(reinterpret_cast<char*>(vec) + 4) + index * 4);
  return outIt; // EAX = EBX; ret 8
}

// Scaffold alias — decompiler signature (registers lost as unaff_*)
extern "C" void FUN_0040b6d0(int where, const uint32_t* value)
{
  (void)where;
  (void)value;
  // Real entry requires EDI=vec, EBX=outIt; see named plate above.
}
