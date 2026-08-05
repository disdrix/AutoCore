// =============================================================================
// CVOGMission_EnsurePendingObjectiveState_Inferred (FUN_00531bd0)
// -----------------------------------------------------------------------------
// Stable ID: aa_00531bd0
// Address:   0x00531bd0  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-29 dual A/B seal (from raw + live Ghidra)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual: reviews/A_aa_00531bd0_* + B_aa_00531bd0_*
// =============================================================================
//
// PURPOSE:
//   Sibling of CVOGMission_AddActiveObjective (0x00531b00). Ensure pending
//   objective state node in char+0x55c and write 4-dword progress blob.
//   Sole caller: CVOGCharacter_ApplyCreateFromPacket.
//   Does NOT: insert def hash +0x548, evaluator vcalls, dirty +0x634.
//
// ABI: __thiscall(character, objDef, slotBlob4) -> void; ret 8
// =============================================================================

// CNDHash_LookupByKey, FUN_0053c760 (CNDHash_Insert state family), operator_new
// declared elsewhere.

void __thiscall FUN_00531bd0(int character, int objDef, int *slotBlob4)
{
  bool isNew;
  int *node;

  if (objDef == 0) {
    return;
  }
  if (*(int *)(objDef + 0x158) == 0) {
    return;
  }
  if ((*(int *)(objDef + 0x15c) - *(int *)(objDef + 0x158)) >> 2 == 0) {
    return;
  }

  // Lookup: ECX = *(character+0x55c), key = *(objDef+0x10)
  node = (int *)CNDHash_LookupByKey(*(void **)(character + 0x55c),
                                    *(unsigned int *)(objDef + 0x10));
  isNew = false;
  if (node == 0) {
    node = (int *)operator_new(0x14);
    if (node == 0) {
      node = 0;
    } else {
      node[0] = 0;
      node[1] = 0;
      node[2] = 0;
      node[3] = 0;
      node[4] = 0;
    }
    isNew = true;
  }

  // Retail writes through node even if operator_new failed (OOM residual).
  *node = objDef;
  node[1] = slotBlob4[0];
  node[2] = slotBlob4[1];
  node[3] = slotBlob4[2];
  node[4] = slotBlob4[3];

  if (isNew) {
    // asm: mov ecx, [character+0x55c]; push 0; push node; push key; call FUN_0053c760
    // Decompiler drops hash this — restore for fidelity notes.
    FUN_0053c760(*(unsigned int *)(objDef + 0x10), node, 0);
  }
  return;
}
