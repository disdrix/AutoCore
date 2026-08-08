// =============================================================================
// Host_DualCNDHash_TraverseNextObject_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004bae00
// Address:   0x004bae00  (autoassault.exe, image base 0x400000)
// Range:     0x004bae00–0x004bae63 inclusive (100 B / 0x64)
// System:    interaction-activation (pick-list / SelectBestPick residual)
// Generated: 2026-08-05 MEGA-011 dual seal (from live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler/assembly control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: OPEN (no Launcher this wave).
// =============================================================================
//
// PURPOSE
//   Single-step dual-CNDHash object enumerator on a host that holds two hash
//   tables (list A @ +0x4, list B @ +0x8) with enable bytes (+0xc / +0xd).
//
//   Per call:
//     1. Select list by listSelect (0 → B/+0x8; ≠0 → A/+0x4), gated by enable.
//     2. CNDHash_TraversalLock_Set(hash)           // +0x1d = 1
//     3. TraverseToNext(hash, cursor) → object*    // node payload @ +0xc
//     4. Clear TraversalLock (inline hash+0x1d = 0)
//     5. Return object* or NULL
//
//   Used by Client_Interact_SelectBestPickTarget (two passes flag 0 then 1),
//   world-object flush, and other host sweeps.
//
// ABI (sealed)
//   ECX = dual-list host*
//   stack0 = char listSelect
//   stack1 = int* cursor (node* walk state; 0 starts at hash+0x14 head)
//   EAX = object* (node+0xc) or NULL
//   cleanup: RET 8  (C2 08 00 ×3 exits)
//
// CALLEES
//   0x00402c40  CNDHash_TraversalLock_Set_Inferred  (dualed MEGA-110)
//   0x004bc530  CNDHash TraverseToNext payload@+0xc  (residual MEGA-029)
//
// DISTINCT FROM
//   List_TraversalLock / Unlock (CS family, flag +0x28)
//   CNDHash_TraverseToNext variants that keep lock across multi-step walks
//   Named_CalleeOf_* scaffold (retired — wrong parent chain)
//
// SUPERSEDES
//   FUN_004bae00.cpp scaffold
//   Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_LoadMapFile_004bae00.cpp
// =============================================================================

#include <cstdint>

// Dualed MEGA-110: soft-set TraversalLock flag at hash+0x1d.
extern void __fastcall CNDHash_TraversalLock_Set_Inferred(int hash /* ECX */);

// Residual MEGA-029: advance cursor; return *(node+0xc) or 0. ECX=hash, RET 4.
extern std::uint32_t __thiscall FUN_004bc530(int hash /* ECX */, int* cursor);

// Host dual-list step enumerator.
// listSelect == 0 → list B (enable host+0xd, hash host+0x8)
// listSelect != 0 → list A (enable host+0xc, hash host+0x4)
void* __thiscall Host_DualCNDHash_TraverseNextObject_Inferred(
    int host /* ECX */,
    char listSelect,
    int* cursor)
{
  std::uint32_t result;

  if (listSelect == '\0') {
    if ((*(char*)(host + 0xd) != '\0') && (*(int*)(host + 8) != 0)) {
      CNDHash_TraversalLock_Set_Inferred(*(int*)(host + 8));
      result = FUN_004bc530(*(int*)(host + 8), cursor);
      *(std::uint8_t*)(*(int*)(host + 8) + 0x1d) = 0;
      return (void*)result;
    }
  }
  else if ((*(char*)(host + 0xc) != '\0') && (*(int*)(host + 4) != 0)) {
    CNDHash_TraversalLock_Set_Inferred(*(int*)(host + 4));
    result = FUN_004bc530(*(int*)(host + 4), cursor);
    *(std::uint8_t*)(*(int*)(host + 4) + 0x1d) = 0;
    return (void*)result;
  }
  return 0;
}
