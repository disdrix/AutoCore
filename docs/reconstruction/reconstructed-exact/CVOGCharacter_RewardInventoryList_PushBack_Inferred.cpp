// =============================================================================
// CVOGCharacter_RewardInventoryList_PushBack_Inferred  (FUN_0052b350)
// -----------------------------------------------------------------------------
// Stable ID: aa_0052b350
// Address:   0x0052b350–0x0052b388 inclusive (57 B / 0x39)
// Module:    autoassault.exe (image base 0x400000)
// System:    missions-progression / character reward-inventory list
// Generated: 2026-07-23 scaffold; **sealed 2026-08-05** MEGA-013 dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-08-05)
//
// PURPOSE:
//   Character-bound MSVC std::list push_back of a dword (item/object pointer):
//     list  = this + 0xcc4
//     head  = *(this + 0xcc8)           // list->_Myhead
//     node  = BuyNode(head, head->_Prev, &value)  // FUN_00418700, 0xC node
//     Incsize(list, 1)                  // FUN_00404840, may throw
//     head->_Prev = node;  old_prev->_Next = node
//
// ABI (byte-sealed):
//   __thiscall  ECX = owner* (CVOGCharacter-class cluster)
//   stack arg0  = uint32_t value  (by value; BuyNode takes &stack_slot)
//   void; RET 4  (C2 04 00)
//
// LAYOUT:
//   this+0xcc4  list header base
//   this+0xcc8  _Myhead*  (list+4)
//   list+0x08   _Mysize   (mutated by FUN_00404840)
//   node+0x00   _Next*
//   node+0x04   _Prev*
//   node+0x08   _Myval (dword)
//
// CALLEES:
//   FUN_00418700  StdList_BuyNode_Dword_Seh (dualed MEGA-081)  RET 0xC
//   FUN_00404840  _Incsize; "list<T> too long" / length_error path
//
// CALLERS (1 site):
//   FUN_004d08c0 @ 0x004d0980 — CompleteObjective reward-slot loop (4 slots):
//     resolve item (FUN_004cf120), flag item+0x17c |= 4, copy TFID, PUSH item, CALL
//
// RETIRES: Named_CalleeOf_Named_CalleeOf_CVOGReaction_CompleteObjective_0052b350
// RELATED: StdList_PushBack_Dword_Inferred (0x00402d10) — same splice, ECX=list*;
//          StdList_BuyNode_Dword_Seh (0x00418700)
// =============================================================================

#include <cstdint>

// External retail helpers (roles sealed; full duals elsewhere / residual).
extern "C" void *__stdcall FUN_00418700(void *next, void *prev, const std::uint32_t *pValue);
extern "C" void __thiscall FUN_00404840(void *list /*ECX*/, std::uint32_t count /*stack*/);

struct StdListNodeDword {
  StdListNodeDword *_Next;  // +0
  StdListNodeDword *_Prev;  // +4
  std::uint32_t     _Myval; // +8
};

struct StdListHeaderDword {
  void *            _PadOrProxy; // +0  (not read by this unit)
  StdListNodeDword *_Myhead;     // +4  == *(owner + 0xcc8)
  std::uint32_t     _Mysize;     // +8  (mutated by FUN_00404840)
};

// Exact CF: buy node → incsize(1) → link as new tail (before sentinel).
// __thiscall; RET 4
void __thiscall CVOGCharacter_RewardInventoryList_PushBack_Inferred(
    void *this_owner /*ECX*/,
    std::uint32_t value /*stack by value*/)
{
  auto *list = reinterpret_cast<StdListHeaderDword *>(
      reinterpret_cast<std::uint8_t *>(this_owner) + 0xcc4);
  StdListNodeDword *head = list->_Myhead; /* also *(owner+0xcc8) */

  StdListNodeDword *node = reinterpret_cast<StdListNodeDword *>(
      FUN_00418700(head, head->_Prev, &value));
  FUN_00404840(list, 1);
  head->_Prev = node;
  node->_Prev->_Next = node;
}
