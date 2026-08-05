// =============================================================================
// StdVector_DwordEraseRange_EbxVec_Inferred  (Ghidra: FUN_00469f10)
// -----------------------------------------------------------------------------
// Stable ID: aa_00469f10
// Address:   0x00469f10  (autoassault.exe, image base 0x400000)
// System:    STL / container utility (dword vector erase-range)
// Generated: 2026-08-04 W38-N dual A/B
// Exactness: Behavior-preserving rewrite of decompiler CF + byte ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   MSVC-style vector<uint32_t>::erase(first, last) for POD dword:
//     EBX = vec*                 (end published at +8)
//     EAX = outIt*               (*outIt = first always)
//     stack: first, last
//     RET 8
//   Closes the hole [first, last) by sliding [last, end) down with dword stores.
//   No dtors, no free, no capacity change, begin (+4) untouched.
//
// TWIN:
//   FUN_00410490 StdVector_EraseRange_Dword_Inferred — thiscall ECX=vec,
//   stack outIt/first/last, RET 0xC, memmove. Same algorithm class; different ABI.
//
// CALLER:
//   FUN_0044a380 StdVector_DwordResize_EaxCount_Inferred shrink arm (W37-Z):
//     LEA first, [begin+n*4]; PUSH end; PUSH first;
//     LEA EAX, [esp+out]; MOV EBX, ECX; CALL
//
// BODY: 0x00469f10–0x00469f41 exclusive (49 B). Dual: accept.
// =============================================================================

#include <cstdint>

struct VecDwordControl {
  uint32_t reserved0;  // +0x00
  uint32_t* begin;     // +0x04 (not written here)
  uint32_t* end;       // +0x08
  // uint32_t* capacity_end; // +0x0C — unused here
};

// Algorithm as sealed by bytes (register formals bound by caller):
//   vec   = EBX
//   outIt = EAX
//   first, last = stack
static inline void StdVector_DwordEraseRange_EbxVec_Algorithm(
    VecDwordControl* vec,
    uint32_t** out_it,
    uint32_t* first,
    uint32_t* last)
{
  if (first != last) {
    uint32_t* end = vec->end;
    uint32_t* dest = first;
    for (; last != end; ++last, ++dest) {
      *dest = *last;
    }
    vec->end = dest;
  }
  *out_it = first;
}

// Documentary entry — real ABI is register-heavy (see plate).
// Ports must: EBX=vec, EAX=outIt*, push last then first (caller order yields
// [esp]=first, [esp+4]=last after both pushes), call, expect RET 8.
extern "C" void StdVector_DwordEraseRange_EbxVec_Inferred(
    uint32_t* first,
    uint32_t* last)
{
  // Cannot express EBX/EAX formals in portable C; see algorithm helper + plate.
  (void)first;
  (void)last;
  // Sole sealed consumer binds registers then calls FUN_00469f10.
}
