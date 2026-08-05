// =============================================================================
// OleDb_AllocCtxBlock_Inferred  (FUN_00422880)
// -----------------------------------------------------------------------------
// Stable ID: aa_00422880
// Address:   0x00422880–0x004228c7 Ghidra body; logical ret via FUN_004228d1
//            (autoassault.exe, image base 0x400000)
// Body size: 72 bytes (Ghidra body) + SEH status tail
// System:    COM / OLE DB ctx gate alloc
// Generated: 2026-07-23 scaffold as FUN_00422880; dual A/B seal 2026-07-29 (W24-B)
// Exactness: Behavior-preserving rewrite of decompiler + entry-byte CF.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Initialize a two-field ctx block:
//     +0  void*  heap buffer
//     +4  int32  count
//   Allocate count * 8 bytes via operator_new[], store pointer, return HRESULT.
//
// ABI (retail)
//   __stdcall  (void** block, int32_t count)   → ret 8
//   EAX = S_OK (0) if alloc non-null, else E_OUTOFMEMORY (0x8007000E)
//   SEH frame (LAB_009bc010); status epilogue is Ghidra-split FUN_004228d1
//
// SOLE CALLER (live)
//   OleDb_BuildBindingsAllocRow_Inferred (FUN_0042139b) @ 0x00421604:
//     push 1; push ebx; call  — when *ctx == 0
//
// READABILITY CF:
//   SEH install → store count → zero ptr → new[](count*8) → store ptr
//   → HRESULT = (ptr!=0)?0:0x8007000E → ret 8
//

#include <cstdint>
#include <cstddef>

#ifndef E_OUTOFMEMORY
#define E_OUTOFMEMORY ((int32_t)0x8007000E)
#endif

struct OleDbCtxBlock {
  void* buf;      // +0
  int32_t count;  // +4
};

// CRT operator_new[] @ 0x00489834
extern "C" void* operator_new__(std::size_t size);

// Clean plate: explicit HRESULT. Retail uses SEH + stdcall ret 8.
int32_t OleDb_AllocCtxBlock_Inferred(OleDbCtxBlock* block, int32_t count)
{
  block->count = count;
  block->buf = nullptr;
  block->buf = operator_new__(static_cast<std::size_t>(count) * 8u);
  // FUN_004228d1 idiom: (-(buf!=0) & 0x7FF8FFF2) + 0x8007000E
  if (block->buf != nullptr) {
    return 0; // S_OK
  }
  return E_OUTOFMEMORY;
}

// Legacy Ghidra name — see FUN_00422880.cpp
// void FUN_00422880(undefined4 *param_1, int param_2);
