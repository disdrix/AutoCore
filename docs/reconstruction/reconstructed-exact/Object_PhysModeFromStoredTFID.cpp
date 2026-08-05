// =============================================================================
// Object_PhysModeFromStoredTFID
// -----------------------------------------------------------------------------
// Stable ID: aa_004c4620
// Address:   0x004c4620–0x004c4658  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_004c4620
// System:    object / TFID / phys mode
// Sealed:    2026-07-29 W27-G (live decompile + read_memory + analyze_function_complete)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Classify the TFID_16 stored at object+0x108 into a phys mode constant:
//   0xB when TFID is the shared invalid/unassigned pattern, else 10.
//   Pure leaf — no callees, no stores.
//
// EVIDENCE:
//   - Identical predicate to Object_SetTFID_ApplyPhysMode_Rebind (FUN_004c4880)
//     which writes this mode to phys+0x28.
//   - Inverse gate of FUN_004c4440 (that unit skips resolve on invalid).
//
// ABI: thiscall; RET 0; ECX=this; EAX = 0xB | 10
// Body: 0x004c4620–0x004c4658 (57 B)

#include <stdint.h>

extern "C" uint32_t __thiscall Object_PhysModeFromStoredTFID(int self)
{
  uint32_t lo = *(uint32_t *)(self + 0x108);
  uint32_t hi = *(uint32_t *)(self + 0x10c);
  uint32_t w2 = *(uint32_t *)(self + 0x110);

  if (((lo & hi) == 0xFFFFFFFFu) && ((char)w2 == 0)) {
    return 0xBu;
  }
  return 10u;
}

// Ghidra twin
extern "C" uint32_t __thiscall FUN_004c4620(int param_1)
{
  return Object_PhysModeFromStoredTFID(param_1);
}
