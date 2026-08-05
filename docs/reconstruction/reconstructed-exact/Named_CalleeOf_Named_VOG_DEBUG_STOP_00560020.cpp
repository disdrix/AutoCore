// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_00560020
// -----------------------------------------------------------------------------
// Stable ID: aa_00560020
// Callee of Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x00560020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, goto×1, while×1, return×1.
//  - Notable callees: FUN_0055f4c0, FUN_00560020, FUN_0062a510, FUN_0062d960, FUN_006caaa0, FUN_006cad30.
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

void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_00560020(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  short *psVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int unaff_EBX;

  uint32_t /* width from decompiler */ unaff_ESI;

  uint8_t local_14 [20];

  

  FUN_0062d960(*(uint32_t /* width from decompiler */ *)(param_1 + 0x234));

  if (param_2 == (uint32_t /* width from decompiler */ *)0xfffffff4) {

    puVar2 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar2 = param_2 + 7;

  }

  (**(code **)(**(int **)(param_1 + 0xc4) + 0xc))(puVar2,local_14);

  if (unaff_EBX != 0) {

    FUN_006cad30(unaff_ESI,unaff_EBX);

    if (*(int *)(param_1 + 0xd0) == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(param_1 + 0xd0) + 8;

    }

    FUN_006caaa0(0,0,unaff_ESI,unaff_EBX,iVar3);

  }

  FUN_0062a510(param_1,param_2);

  psVar1 = (short *)((int)param_2 + 6);

  *psVar1 = *psVar1 + -1;

  param_2[2] = 0;

  if (*psVar1 == 0) {

    (**(code **)*param_2)(1);

  }

  iVar3 = 0;

  if (0 < *(int *)(param_1 + 0x124)) {

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x120);

    do {

      if ((uint32_t /* width from decompiler */ *)*puVar2 == param_2) goto LAB_005600e4;

      iVar3 = iVar3 + 1;

      puVar2 = puVar2 + 1;

    } while (iVar3 < *(int *)(param_1 + 0x124));

  }

  iVar3 = -1;

LAB_005600e4:

  *(int *)(param_1 + 0x124) = *(int *)(param_1 + 0x124) + -1;

  *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x120) + iVar3 * 4) =

       *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x120) + *(int *)(param_1 + 0x124) * 4);

  FUN_0055f4c0();

  return;

}
