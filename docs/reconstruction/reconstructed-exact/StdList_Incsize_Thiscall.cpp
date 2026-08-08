// =============================================================================
// StdList_Incsize_Thiscall
// -----------------------------------------------------------------------------
// Stable ID: aa_00404840
// Address:   0x00404840–0x004048AE  (autoassault.exe, image base 0x400000)
// System:    shared MSVC std::list
// Generated: 2026-07-23 scaffold as FUN_00404840; **sealed 2026-08-05** R10-006 dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept (A+B 2026-08-05) — leaf CF/ABI High; exception type name open
// =============================================================================

/*
 * Behavioral notes (2026-08-05 seal):
 * - MSVC-shaped std::list::_Incsize(size_type count).
 * - ABI: __thiscall ECX=list*, stack count, RET 4.
 * - Gate: if (0x3fffffffU - list->_Mysize < count) throw with
 *   message "list<T> too long" @ 0x00a1581c via FUN_00401a40 + _CxxThrowException
 *   (ThrowInfo DAT_00acc388).
 * - Else list->_Mysize += count (field at list+8).
 * - Distinct from sealed fastcall twin StdList_Incsize @ 0x0043fe60
 *   (ECX=count, EDX=list*, bare RET, same max).
 * - Distinct from StdList_Incsize_Max1fffffff @ 0x00416010 (max 0x1fffffff).
 * - Parent dual residual BuyNode 0x00418700; partition seed missions-progression
 *   (shared leaf — not mission-only).
 */

#include <cstdint>

struct StdListHeader {
  void *_Myhead_or_pad;  // +0 (layout partial; head typically at +4)
  void *_Myhead;         // +4
  std::uint32_t _Mysize; // +8
};

// Image ABI: ECX = list*, stack count, RET 4.
extern "C" void __thiscall StdList_Incsize_Thiscall(
    StdListHeader *list /*ECX*/,
    std::uint32_t count /*stack*/)
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
