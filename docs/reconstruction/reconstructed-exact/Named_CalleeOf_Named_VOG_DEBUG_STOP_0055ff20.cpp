// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0055ff20
// -----------------------------------------------------------------------------
// Stable ID: aa_0055ff20
// Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x0055ff20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0055f4c0, FUN_0055ff20, FUN_005b3370, FUN_0062a4d0, FUN_0062d960, FUN_006caaa0, FUN_006cad30.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
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

int * __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_0055ff20(int param_1,int *param_2)



{

  int *piVar1;

  int iVar2;

  int unaff_EDI;

  uint8_t *puVar3;

  uint8_t auStack_34 [4];

  uint8_t local_30 [44];

  

  param_2[2] = param_1;

  FUN_0062d960(*(uint32_t /* width from decompiler */ *)(param_1 + 0x234));

  puVar3 = local_30;

  (**(code **)(*param_2 + 0x18))(puVar3);

  if (param_2 == (int *)0xfffffff4) {

    piVar1 = (int *)0x0;

  }

  else {

    piVar1 = param_2 + 7;

  }

  (**(code **)(**(int **)(param_1 + 0xc4) + 4))(piVar1,auStack_34,&stack0xffffffb8);

  iVar2 = *(int *)(param_1 + 0x130);

  *(int *)(param_1 + 0x130) = iVar2 + 1;

  param_2[8] = iVar2;

  if (unaff_EDI != 0) {

    FUN_006cad30(puVar3,unaff_EDI);

    if (*(int *)(param_1 + 0xd0) == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(param_1 + 0xd0) + 8;

    }

    FUN_006caaa0(puVar3,unaff_EDI,0,0,iVar2);

  }

  *(short *)((int)param_2 + 6) = *(short *)((int)param_2 + 6) + 1;

  if (*(uint *)(param_1 + 0x124) == (*(uint *)(param_1 + 0x128) & 0x7fffffff)) {

    FUN_005b3370((int *)(param_1 + 0x120),4);

  }

  *(int **)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x124) * 4) = param_2;

  *(int *)(param_1 + 0x124) = *(int *)(param_1 + 0x124) + 1;

  FUN_0062a4d0(param_1,param_2);

  FUN_0055f4c0();

  return param_2;

}
