// =============================================================================
// StdList_Incsize
// -----------------------------------------------------------------------------
// Stable ID: aa_0043fe60
// Address:   0x0043fe60–0x0043fece  (autoassault.exe, image base 0x400000)
// System:    shared MSVC std::list
// Generated: 2026-07-23 scaffold as FUN_0043fe60; **sealed 2026-07-29** W23-E dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept (A+B 2026-07-29) — leaf CF/ABI High; exception type name open
// =============================================================================

/*
 * Behavioral notes (2026-07-29 seal):
 * - MSVC-shaped std::list::_Incsize(size_type count).
 * - ABI: __fastcall ECX=count, EDX=list*; plain RET.
 * - Gate: if (0x3fffffffU - list->_Mysize < count) throw with
 *   message "list<T> too long" @ 0x00a1581c via FUN_00401a40 + _CxxThrowException
 *   (ThrowInfo DAT_00acc388).
 * - Else list->_Mysize += count (field at list+8).
 * - Twin leaf FUN_00403600 uses __thiscall + max 0x6666666 (not owned).
 * - Callers include StdList_PushPayloadNode (count=1) and many Auth/UI inserts.
 */

#include <cstdint>

struct StdListHeader {
  void *_Myhead_or_pad;  // +0 (layout partial; head typically at +4)
  void *_Myhead;         // +4
  std::uint32_t _Mysize; // +8
};

// Image ABI: ECX = count, EDX = list*, no stack args, plain RET.
extern "C" void __fastcall StdList_Incsize(
    std::uint32_t count /*ECX*/,
    StdListHeader *list /*EDX*/)
{
  // SEH frame present in retail (ExceptionList / LAB_009bc919); omitted here.
  const std::uint32_t size = list->_Mysize;
  if (0x3fffffffU - size < count) {
    // retail:
    //   basic_string ctor("list<T> too long");
    //   FUN_00401a40(...);
    //   _CxxThrowException(..., &DAT_00acc388);  // noreturn
    return; // unreachable in retail after throw — plate keeps structure only
  }
  list->_Mysize = size + count;
}

// Alias for Ghidra name
extern "C" void __fastcall FUN_0043fe60(std::uint32_t count, StdListHeader *list)
{
  StdList_Incsize(count, list);
}
