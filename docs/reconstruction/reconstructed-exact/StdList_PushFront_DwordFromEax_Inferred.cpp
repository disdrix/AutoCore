// =============================================================================
// StdList_PushFront_DwordFromEax_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004027f0
// Address:   0x004027f0 – 0x0040281e  (autoassault.exe, image base 0x400000)
// System:    missions-progression (partition) + multi-system list host
// Generated: 2026-08-05 MEGA-089 dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow + sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED.
//
// PURPOSE:
//   MSVC std::list-style push_front for a 4-byte element:
//   allocate 0xC node (prev/next/val), inc size, splice after head sentinel.
//
// ABI (sealed from disassemble_function + read_memory):
//   stack       list*                 (arg cleaned by ret 4)
//   EAX         const uint32_t* val   (pointer to dword copied into node+8)
//   epilogue    ret 4
//   NOT thiscall — list is on the stack, not ECX.
//
// Layout (sealed):
//   list+0x04  _Myhead sentinel*
//   list+0x08  _Mysize (via FUN_00418790)
//   node+0x00  _Prev
//   node+0x04  _Next
//   node+0x08  _Myval (dword)
//
// Callees:
//   FUN_00418700  _Buynode(prev, next, const T*) — operator_new(0xC)
//   FUN_00418790  _Incsize — __fastcall(ECX=count, EDX=list); may throw
//                 length_error("list<T> too long") via FUN_00401a40
//
// Ghidra alias:  FUN_004027f0
// Prior scaffold (retired): Named_CalleeOf_Client_RecvCreateCharacter_004027f0
// Dual reviews:  A_/B_aa_004027f0_StdList_PushFront_DwordFromEax_Inferred.md
// =============================================================================

#include <cstdint>

// External retail helpers (symbols unresolved beyond sealed role).
extern "C" int FUN_00418700(int prev, int next, const uint32_t *val);
// __fastcall: ECX = delta, EDX = list*
extern "C" void __fastcall FUN_00418790(uint32_t delta, int list);

// Register EAX holds val* at entry (MSVC custom / optimized internal ABI).
// Modeled as an explicit second parameter for reconstruction readability;
// call sites set EAX then push list before CALL.
void StdList_PushFront_DwordFromEax_Inferred(int list, const uint32_t *val_in_eax)
{
  int head;
  int node;

  head = *reinterpret_cast<int *>(list + 4);
  node = FUN_00418700(head, *reinterpret_cast<int *>(head + 4), val_in_eax);
  FUN_00418790(/*ecx=*/1u, /*edx=*/list);
  *reinterpret_cast<int *>(head + 4) = node;
  **reinterpret_cast<int **>(node + 4) = node;
}
