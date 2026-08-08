// =============================================================================
// FUN_004040f0  (twin of StdList_InsertOne_BeforeNode_Dword_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004040f0
// Address:   0x004040f0–0x00404122 inclusive (51 B / 0x33)
// Module:    autoassault.exe (image base 0x400000)
// System:    shared MSVC std::list
// Generated: 2026-07-23 scaffold; **sealed 2026-08-05** R10-005 dual A/B
// Exactness: Behavior-preserving rewrite of sealed control flow / ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical: StdList_InsertOne_BeforeNode_Dword_Inferred
// =============================================================================

#include <cstdint>

extern "C" void* __stdcall FUN_00418700(void* next, void* prev, const std::uint32_t* pValue);
extern "C" void __thiscall FUN_00404840(void* list /*ECX*/, std::uint32_t count /*stack*/);

struct StdListNodeDword {
  StdListNodeDword* _Next;  // +0
  StdListNodeDword* _Prev;  // +4
  std::uint32_t     _Myval; // +8
};

struct StdListHeaderDword {
  void*             _PadOrProxy; // +0
  StdListNodeDword* _Myhead;     // +4
  std::uint32_t     _Mysize;     // +8
};

// Retail: __thiscall ECX=list*, stack (where*, val*), RET 0x8.
// Insert one dword before `where` (BuyNode 0xC + Incsize(1) + splice).
void __thiscall FUN_004040f0(
    StdListHeaderDword* list /*ECX*/,
    StdListNodeDword* where,
    const std::uint32_t* val)
{
  StdListNodeDword* node = reinterpret_cast<StdListNodeDword*>(
      FUN_00418700(where, where->_Prev, val));
  FUN_00404840(list, 1);
  where->_Prev = node;
  node->_Prev->_Next = node;
}
