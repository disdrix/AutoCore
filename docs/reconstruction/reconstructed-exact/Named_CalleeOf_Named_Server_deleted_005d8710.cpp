// =============================================================================
// Named_CalleeOf_Named_Server_deleted_005d8710
// -----------------------------------------------------------------------------
// Stable ID: aa_005d8710
// Callee of Named_Server_deleted (+1 other named callers)
// Address:   0x005d8710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Server_deleted: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_Server_deleted (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: FUN_005d8710, FUN_0063fc20, FUN_00640bf0, FUN_00640c90, FUN_00641190.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Server_deleted (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_Named_Server_deleted_005d8710(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  

  param_2 = param_2 * 0x14;

  piVar3 = (int *)(*(int *)(param_1 + 0x14) + param_2);

  if (*(int *)(*(int *)(param_1 + 0x14) + 0xc + param_2) != 0) {

    FUN_00641190(0);

    puVar1 = (uint32_t /* width from decompiler */ *)piVar3[3];

    *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

    if (*(short *)((int)puVar1 + 6) == 0) {

      (**(code **)*puVar1)(1);

    }

  }

  if (piVar3[2] != 0) {

    FUN_00640bf0(0);

    FUN_00640c90();

    puVar1 = (uint32_t /* width from decompiler */ *)piVar3[2];

    *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

    if (*(short *)((int)puVar1 + 6) == 0) {

      (**(code **)*puVar1)(1);

    }

  }

  if (piVar3[4] != 0) {

    FUN_0063fc20(0);

    puVar1 = (uint32_t /* width from decompiler */ *)piVar3[4];

    *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

    if (*(short *)((int)puVar1 + 6) == 0) {

      (**(code **)*puVar1)(1);

    }

  }

  (**(code **)(*(int *)piVar3[1] + 0x38))(0);

  puVar1 = (uint32_t /* width from decompiler */ *)piVar3[1];

  *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

  if (*(short *)((int)puVar1 + 6) == 0) {

    (**(code **)*puVar1)(1);

  }

  puVar1 = (uint32_t /* width from decompiler */ *)*piVar3;

  if ((puVar1 != (uint32_t /* width from decompiler */ *)0x0) &&

     (*(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1,

     *(short *)((int)puVar1 + 6) == 0)) {

    (**(code **)*puVar1)(1);

  }

  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;

  puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x18) * 0x14);

  puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + param_2);

  *puVar2 = *puVar1;

  puVar2[1] = puVar1[1];

  puVar2[2] = puVar1[2];

  puVar2[3] = puVar1[3];

  puVar2[4] = puVar1[4];

  return;

}
