// =============================================================================
// StdList_PushBack_DwordFromEcx_Inferred  (was FUN_00517db0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00517db0
// Address:   0x00517db0–0x00517de9  (autoassault.exe, image base 0x400000)
// System:    shared MSVC std::list helper (missions-progression partition seed)
// Generated: 2026-07-23 scaffold; **sealed 2026-08-05** R10-032 dual A/B
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte ABI.
// Bit-for-bit vs retail EXE: DEFERRED
// Dual:      accept-with-gaps (A+B 2026-08-05)
//
// PURPOSE:
//   MSVC-shaped std::list push_back of a dword-sized element whose value is
//   the incoming ECX register (typically the caller's adjusted `this`):
//     head = list->_Myhead
//     node = BuyNode(head, head->_Prev, &ecx_value)  // FUN_00418700, 0xC node
//     _Incsize(1)                                    // FUN_00404840, may throw
//     head->_Prev = node;  old_prev->_Next = node
//
// ABI (byte-sealed via read_memory):
//   ECX        = uint32_t value  (stored at node+8; NOT list*)
//   stack arg0 = list*
//   void; RET 4  (C2 04 00)
//   Contrast StdList_PushBack_Dword_Inferred (0x00402d10): ECX=list, stack=T*
//
// LAYOUT:
//   list+0x04  _Myhead*
//   list+0x08  _Mysize
//   node+0x00  _Next*
//   node+0x04  _Prev*
//   node+0x08  _Myval (dword = entry ECX)
//
// CALLEES:
//   FUN_00418700  StdList_BuyNode_Dword_Seh  RET 0xC
//   FUN_00404840  StdList_Incsize_Thiscall   RET 4
//
// CALLERS (5 code + many DATA vtable slots):
//   FUN_004c30d0 @ 0x004c30e9
//   FUN_004f46c0 @ 0x004f46d9
//   FUN_00562fa0 @ 0x00562fb9
//   FUN_00587680 @ 0x00587699
//   FUN_00569ba0 @ 0x00569bb0 (this-adjust + tail JMP)
//
// HEX SEAL (58 B through RET 4):
//   51538b5c240c568b730457894c240c8b4e048d44240c5051568bcbe83009f0ff
//   6a018bcb8bf8e865caeeff897e048b5704893a5f5e5b59c20400
// =============================================================================

#include <cstdint>

// External retail helpers (roles sealed; full duals elsewhere).
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

// Exact CF: spill ECX → buy node → incsize(1) → link as new tail (before sentinel).
// Call sites set ECX (often adjusted this) then PUSH list before CALL.
void StdList_PushBack_DwordFromEcx_Inferred(
    StdListHeaderDword* list /*stack*/,
    std::uint32_t value_in_ecx /*ECX*/)
{
  StdListNodeDword* head = list->_Myhead;
  // Retail: PUSH ECX creates stack slot; LEA passes &slot to BuyNode.
  std::uint32_t value = value_in_ecx;
  StdListNodeDword* node = reinterpret_cast<StdListNodeDword*>(
      FUN_00418700(head, head->_Prev, &value));
  FUN_00404840(list, 1);
  head->_Prev = node;
  node->_Prev->_Next = node;
}

// Ghidra symbol alias (scaffold twin kept in FUN_00517db0.cpp)
void FUN_00517db0(StdListHeaderDword* list, std::uint32_t value_in_ecx)
{
  StdList_PushBack_DwordFromEcx_Inferred(list, value_in_ecx);
}
