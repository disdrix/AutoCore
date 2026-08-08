// =============================================================================
// StdList_InsertOne_BeforeNode_Dword_Inferred  (was FUN_004040f0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004040f0
// Address:   0x004040f0–0x00404122 inclusive (51 B / 0x33)
// Module:    autoassault.exe (image base 0x400000)
// System:    shared MSVC std::list (partition hint: missions-progression nested)
// Generated: 2026-07-23 scaffold; **sealed 2026-08-05** R10-005 dual A/B
// Exactness: Behavior-preserving rewrite of sealed control flow / ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual:      accept-with-gaps (A+B 2026-08-05 R10-005)
//
// PURPOSE:
//   Insert one dword-sized element immediately before list node `where`:
//     node = BuyNode(where, where->_Prev, val*)   // FUN_00418700, 0xC node
//     _Incsize(list, 1)                           // FUN_00404840, may throw
//     where->_Prev = node;  node->_Prev->_Next = node
//   When where == list->_Myhead (sentinel) this is push_back — same splice as
//   dualed StdList_PushBack_Dword_Inferred @ 0x00402d10 (where fixed to head).
//
// ABI (byte-sealed — disassemble_function + read_memory):
//   __thiscall  ECX = list*
//   stack arg0  = ListNodeDword* where
//   stack arg1  = const uint32_t* val
//   void; RET 0x8  (C2 08 00)
//
// LAYOUT:
//   list+0x04  _Myhead*
//   list+0x08  _Mysize  (mutated by FUN_00404840)
//   node+0x00  _Next*
//   node+0x04  _Prev*
//   node+0x08  _Myval (dword)
//
// CALLEES:
//   FUN_00418700  StdList_BuyNode_Dword_Seh  (dualed MEGA-081)
//   FUN_00404840  _Incsize; "list<T> too long" / ThrowInfo DAT_00acc388
//
// CALLERS:
//   FUN_004034c0  StdList_InsertN_BeforeNode_Dword_Inferred @ 0x004034fc
//   FUN_00404560  insert-range @ 0x004045a0
//   orphan CALL @ 0x004cd020 (no function)
//
// RETIRES: Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_DebugListMi_004040f0
// RELATED: StdList_PushBack_Dword_Inferred (0x00402d10);
//          StdList_InsertN_BeforeNode_Dword_Inferred (0x004034c0);
//          StdList_BuyNode_Dword_Seh (0x00418700)
// =============================================================================

#include <cstdint>

// External retail helpers (roles sealed; duals elsewhere / residual).
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

// Exact CF: buy node → incsize(1) → splice before `where`.
void __thiscall StdList_InsertOne_BeforeNode_Dword_Inferred(
    StdListHeaderDword* list /*ECX*/,
    StdListNodeDword* where /*stack*/,
    const std::uint32_t* val /*stack*/)
{
  StdListNodeDword* node = reinterpret_cast<StdListNodeDword*>(
      FUN_00418700(where, where->_Prev, val));
  FUN_00404840(list, 1);
  where->_Prev = node;
  node->_Prev->_Next = node;
}

// Ghidra symbol alias (scaffold twin kept in FUN_004040f0.cpp)
void __thiscall FUN_004040f0(
    StdListHeaderDword* list,
    StdListNodeDword* where,
    const std::uint32_t* val)
{
  StdList_InsertOne_BeforeNode_Dword_Inferred(list, where, val);
}
