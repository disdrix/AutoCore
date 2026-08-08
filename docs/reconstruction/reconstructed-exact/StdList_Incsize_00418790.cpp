// =============================================================================
// StdList_Incsize_00418790
// -----------------------------------------------------------------------------
// Stable ID: aa_00418790
// Address:   0x00418790–0x004187fe  (autoassault.exe, image base 0x400000)
// System:    shared MSVC std::list (partition: missions-progression residual)
// Generated: 2026-07-23 scaffold as FUN_00418790; **sealed 2026-08-05** R10-024 dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept (A+B 2026-08-05) — leaf CF/ABI High; exception type name open
// Twin:      StdList_Incsize / aa_0043fe60 @ 0x0043fe60 (W23-E accept) — same CF/ABI/max
// =============================================================================

/*
 * Behavioral notes (2026-08-05 seal):
 * - MSVC-shaped std::list::_Incsize(size_type count).
 * - ABI: __fastcall ECX=count, EDX=list*; plain RET (C3).
 * - Gate: if (0x3fffffffU - list->_Mysize < count) throw with
 *   message "list<T> too long" @ 0x00a1581c via FUN_00401a40 + _CxxThrowException
 *   (ThrowInfo DAT_00acc388).
 * - Else list->_Mysize += count (field at list+8).
 * - SEH frame LAB_009bc919 present in retail.
 * - Does not allocate or relink nodes — insert wrappers call BuyNode then this leaf.
 * - Prior scaffold Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_00418790 retired
 *   (parent-seed; misleading — shared multi-domain leaf).
 * - Related not owned: FUN_00404840 thiscall size path; StdList_Incsize_Max1fffffff.
 */

#include <cstdint>

struct StdListHeader {
  void *_Myhead_or_pad;  // +0 (layout partial; head typically at +4)
  void *_Myhead;         // +4
  std::uint32_t _Mysize; // +8
};

// Image ABI: ECX = count, EDX = list*, no stack args, plain RET.
// VA-disambiguated symbol: twin of dualed StdList_Incsize @ 0x0043fe60.
extern "C" void __fastcall StdList_Incsize_00418790(
    std::uint32_t count /*ECX*/,
    StdListHeader *list /*EDX*/)
{
  // SEH frame present in retail (ExceptionList / LAB_009bc919); omitted here.
  const std::uint32_t size = list->_Mysize;
  if (0x3fffffffU - size < count) {
    // retail:
    //   basic_string ctor("list<T> too long");
    //   FUN_00401a40(...);  // Std_LengthError_CtorFromString
    //   _CxxThrowException(..., &DAT_00acc388);  // noreturn
    return; // unreachable in retail after throw — plate keeps structure only
  }
  list->_Mysize = size + count;
}

// Alias for Ghidra name
extern "C" void __fastcall FUN_00418790(std::uint32_t count, StdListHeader *list)
{
  StdList_Incsize_00418790(count, list);
}
