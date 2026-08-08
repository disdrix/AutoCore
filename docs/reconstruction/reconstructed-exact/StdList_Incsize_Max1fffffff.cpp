// =============================================================================
// StdList_Incsize_Max1fffffff
// -----------------------------------------------------------------------------
// Stable ID: aa_00416010
// Address:   0x00416010–0x0041607e  (autoassault.exe, image base 0x400000)
// System:    shared MSVC std::list
// Generated: 2026-07-23 scaffold as FUN_00416010; **sealed 2026-08-04** WQ9I-E dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-08-04) — CF/ABI/max/string High; product throw type open
// Ghidra:    FUN_00416010
// =============================================================================

/*
 * Behavioral notes (2026-08-04 seal):
 * - MSVC-shaped std::list::_Incsize(size_type count).
 * - ABI: __fastcall ECX=count, EDX=list*; plain RET.
 * - Gate: if (0x1fffffffU - list->_Mysize < count) throw with
 *   message "list<T> too long" @ 0x00a1581c via FUN_00401a40 + _CxxThrowException
 *   (ThrowInfo DAT_00acc388).
 * - Else list->_Mysize += count (field at list+8).
 * - Distinct from StdList_Incsize @ 0x0043fe60 (max 0x3fffffff, same ABI/string).
 * - Distinct from FUN_00403600 (__thiscall, max 0x6666666).
 * - Callers (WQ9I-E): FUN_00415dd0, FUN_00834700, FUN_008dfc60 — always count=1
 *   after buy-node FUN_00415ed0 (0x10 node).
 */

#include <cstdint>

struct StdListHeader {
  void *_pad0;           // +0 (layout partial)
  void *_Myhead;         // +4 (callers link via head)
  std::uint32_t _Mysize; // +8
};

// Image ABI: ECX = count, EDX = list*, no stack args, plain RET.
extern "C" void __fastcall StdList_Incsize_Max1fffffff(
    std::uint32_t count /*ECX*/,
    StdListHeader *list /*EDX*/)
{
  // SEH frame present in retail (ExceptionList / LAB_009bc919); omitted here.
  const std::uint32_t size = list->_Mysize;
  if (0x1fffffffU - size < count) {
    // retail:
    //   basic_string ctor("list<T> too long");
    //   FUN_00401a40(...);
    //   _CxxThrowException(..., &DAT_00acc388);  // noreturn
    return; // unreachable in retail after throw — plate keeps structure only
  }
  list->_Mysize = size + count;
}
