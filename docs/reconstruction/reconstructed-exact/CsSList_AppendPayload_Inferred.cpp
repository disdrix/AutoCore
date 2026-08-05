// =============================================================================
// CsSList_AppendPayload_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004024d0
// Address:   0x004024d0  (autoassault.exe, image base 0x400000)
// System:    client containers / deferred-queue append
// Generated: 2026-07-29 dual A/B seal (W18-B)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
//
// PURPOSE:
//   CS-protected singly-linked tail-append of a payload pointer into a list host.
//   Allocates a 0xC node with vtbl PTR_FUN_009cb340, links at tail, bumps count
//   via InterlockedIncrement after unlock.
//
// ABI (sealed):
//   __thiscall  ECX = list*
//   stack       void* payload
//   epilogue    ret 4
//   returns     0 if payload null; 1 on success (via FUN_00402598)
//
// Layout (sealed):
//   list+0x04 head*, +0x08 tail*, +0x0C count (Interlocked),
//   +0x10 CRITICAL_SECTION (always), +0x28 CRITICAL_SECTION (if count ≤ 3)
//   node: +0 vtbl, +4 payload*, +8 next*
//
// Ghidra alias: FUN_004024d0
// Scaffold:     FUN_004024d0.cpp (prior)
// Dual reviews: A_/B_aa_004024d0_CsSList_AppendPayload_Inferred.md
// =============================================================================

#include <windows.h>
#include <cstdint>

extern "C" void *operator_new(unsigned size);
extern "C" uint8_t FUN_00402598(void); // Leave CS(s) + InterlockedIncrement(list+0xC)
extern "C" void *ExceptionList;
extern "C" uint32_t PTR_FUN_009cb340; // node vtbl

// MSVC thiscall: ECX = list
uint32_t __thiscall CsSList_AppendPayload_Inferred(int list, int payload)
{
  uint32_t *node;
  uint32_t uVar2;
  void *local_10;
  uint8_t *puStack_c;
  uint32_t local_8;

  puStack_c = (uint8_t *)&/*LAB_009bc1ab*/ ExceptionList; // SEH handler placeholder
  local_10 = ExceptionList;
  if (payload == 0) {
    // bytes: xor al, al; ret 4 — decompiler may show ExceptionList high bits
    return (uint32_t)ExceptionList & 0xffffff00;
  }
  local_8 = 0;
  ExceptionList = &local_10;
  node = (uint32_t *)operator_new(0xC);
  if (node == (uint32_t *)0) {
    node = (uint32_t *)0;
  } else {
    *node = (uint32_t)&PTR_FUN_009cb340;
    node[2] = 0; // next
    node[1] = 0; // payload
  }
  local_8 = local_8 & 0xffffff00;
  node[1] = (uint32_t)payload;
  if (*(int *)(list + 0xC) < 4) {
    EnterCriticalSection((LPCRITICAL_SECTION)(list + 0x28));
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(list + 0x10));
  if (*(int *)(list + 8) == 0) {
    *(uint32_t **)(list + 4) = node;
    *(uint32_t **)(list + 8) = node;
    uVar2 = FUN_00402598();
    return uVar2;
  }
  *(uint32_t **)(*(int *)(list + 8) + 8) = node;
  *(uint32_t **)(list + 8) = node;
  uVar2 = FUN_00402598();
  return uVar2;
}
