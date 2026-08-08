// =============================================================================
// StdList_PushBack_Dword_Inferred  (was FUN_00402d10)
// -----------------------------------------------------------------------------
// Stable ID: aa_00402d10
// Address:   0x00402d10–0x00402d41  (autoassault.exe, image base 0x400000)
// System:    shared MSVC std::list helper (missions-progression + item/reaction)
// Generated: 2026-07-23 scaffold; **sealed 2026-08-05** MEGA-126 dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-08-05)
//
// PURPOSE:
//   MSVC-shaped std::list push_back of a dword-sized element:
//     head = list->_Myhead
//     node = BuyNode(head, head->_Prev, pValue)   // FUN_00418700, 0xC node
//     _Incsize(1)                                 // FUN_00404840, may throw
//     head->_Prev = node;  old_prev->_Next = node
//
// ABI (byte-sealed):
//   __thiscall  ECX = list*
//   stack arg0  = const uint32_t* pValue  (dereferenced by BuyNode)
//   void; RET 4  (C2 04 00)
//
// LAYOUT:
//   list+0x04  _Myhead*
//   list+0x08  _Mysize
//   node+0x00  _Next*
//   node+0x04  _Prev*
//   node+0x08  _Myval (dword)
//
// CALLEES:
//   FUN_00418700  buy 0xC node (Next/Prev/value)  RET 0xC
//   FUN_00404840  _Incsize; "list<T> too long" @ 0x00a1581c / ThrowInfo DAT_00acc388
//
// CALLERS (7 sites / 3 parents):
//   FUN_009572e0 Client_DebugListMissionsStatus @ 0x00957467
//   FUN_00509010 @ 0x00509280
//   FUN_0057ade0 @ 0x0057aeee / 0x0057af49 / 0x0057af92 / 0x0057b080 / 0x0057b0c0
//
// RETIRES: Named_CalleeOf_Client_DebugListMissionsStatus_00402d10 (parent-seed only)
// RELATED: StdList_PushPayloadNode_Inferred (0x00480350) — same splice; payload via EAX;
//          twin BuyNode StdList_BuyNode_Dword (0x006759b0); Incsize twin 0x0043fe60
// =============================================================================

#include <cstdint>

// External retail helpers (roles sealed; full duals elsewhere / residual).
extern "C" void* __stdcall FUN_00418700(void* next, void* prev, const std::uint32_t* pValue);
extern "C" void __thiscall FUN_00404840(void* list /*ECX*/, std::uint32_t count /*stack*/);

struct StdListNodeDword {
  StdListNodeDword* _Next;  // +0
  StdListNodeDword* _Prev;  // +4
  std::uint32_t     _Myval; // +8
};

struct StdListHeaderDword {
  void*             _PadOrProxy; // +0  (not read by this unit)
  StdListNodeDword* _Myhead;     // +4
  std::uint32_t     _Mysize;     // +8  (mutated by FUN_00404840)
};

// Exact CF: buy node → incsize(1) → link as new tail (before sentinel).
void __thiscall StdList_PushBack_Dword_Inferred(
    StdListHeaderDword* list /*ECX*/,
    const std::uint32_t* pValue /*stack*/)
{
  StdListNodeDword* head = list->_Myhead;
  StdListNodeDword* node = reinterpret_cast<StdListNodeDword*>(
      FUN_00418700(head, head->_Prev, pValue));
  FUN_00404840(list, 1);
  head->_Prev = node;
  node->_Prev->_Next = node;
}

// Ghidra symbol alias (scaffold twin kept in FUN_00402d10.cpp)
void __thiscall FUN_00402d10(StdListHeaderDword* list, const std::uint32_t* pValue)
{
  StdList_PushBack_Dword_Inferred(list, pValue);
}
