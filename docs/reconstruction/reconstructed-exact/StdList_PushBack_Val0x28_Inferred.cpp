// =============================================================================
// StdList_PushBack_Val0x28_Inferred  (FUN_004025e0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004025e0
// Address:   0x004025e0–0x00402611  (autoassault.exe, image base 0x400000)
// Body size: 50 B / 0x32; pad CC before Client_EnqueueCombatFloater_INFERRED @ 0x00402620
// System:    shared MSVC std::list (seed: missions-progression / CVOGReaction_TransferMap)
// Generated: 2026-07-23 scaffold; **sealed 2026-08-05** MEGA-059 dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher / runtime Confirmed)
// Dual:      accept-with-gaps (A+B 2026-08-05)
// Prior:     Named_CalleeOf_CVOGReaction_TransferMap_004025e0 — RETIRED scaffold
// =============================================================================
//
// PURPOSE: MSVC-shaped std::list::push_back / _Insert(_Myhead, val) for T size 0x28.
//   1) head = list->_Myhead (+4)
//   2) node = Buynode(head, head->_Prev, val) — FUN_00403560: operator_new(0x30)
//      + FUN_00404390 (Next, Prev, 10×dword value copy)
//   3) _Incsize(1) — FUN_00403600: max 0x6666666; "list<T> too long" @ 0x00a1581c
//   4) head->_Prev = node; node->_Prev->_Next = node
//
// ABI (sealed via disassemble_function + call site 0x004d3893):
//   __thiscall ECX = list*; stack const T*; RET 4; void
//
// CALLERS: sole UNCONDITIONAL_CALL from CVOGReaction_TransferMap @ 0x004d3893
//   ECX = reaction+0xe778 (embedded list); stack = &local T (0x28 built on parent frame)
//
// RELATED (context, not this unit):
//   - FUN_00403560 / FUN_00404390 buynode+ctor (node 0x30 / val 0x28)
//   - FUN_00403600 Incsize max 0x6666666 (thiscall RET 4)
//   - Twin pattern StdList_PushPayloadNode (dword T / different buynode+incsize)
//   - CVOGReaction_TransferMap 0x004d37f0 (sole parent)
//

#include <cstdint>

struct ListNode0x30 {
  ListNode0x30 *_Next;   // +0
  ListNode0x30 *_Prev;   // +4
  std::uint32_t _Val[10]; // +8 .. +0x2F  (T size 0x28)
};

struct StdListShell_Val0x28 {
  void *_Pad0;              // +0 (allocator / unused in this unit)
  ListNode0x30 *_Myhead;    // +4
  std::uint32_t _Mysize;    // +8 (mutated by FUN_00403600)
};

// Callees (image names retained)
extern "C" ListNode0x30 *FUN_00403560(ListNode0x30 *next, ListNode0x30 *prev, const void *value);
extern "C" void __thiscall FUN_00403600(StdListShell_Val0x28 *list, std::uint32_t count);

// Exact CF from live decompile ≡ raw ≡ bytes.
void __thiscall StdList_PushBack_Val0x28_Inferred(
    StdListShell_Val0x28 *list /*ECX*/,
    const void *value /*stack; T size 0x28*/)
{
  ListNode0x30 *head = list->_Myhead;
  ListNode0x30 *node = FUN_00403560(head, head->_Prev, value);
  FUN_00403600(list, 1);
  head->_Prev = node;
  node->_Prev->_Next = node;
}

// Ghidra name alias
void __thiscall FUN_004025e0(StdListShell_Val0x28 *param_1, const void *param_2)
{
  StdList_PushBack_Val0x28_Inferred(param_1, param_2);
}
