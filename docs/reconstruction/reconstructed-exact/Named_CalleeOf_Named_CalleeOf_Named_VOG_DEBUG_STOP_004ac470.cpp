// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004ac470
// -----------------------------------------------------------------------------
// Stable ID: aa_004ac470
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004ac470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, while×1.
//  - Notable callees: FUN_004ac470, FUN_004aefa0, FUN_004afad0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004ac470(int param_1,uint32_t /* width from decompiler */ param_2,char param_3)



{

  char *pcVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  char cStack0000000d;

  

  iVar2 = *(int *)(param_1 + 4);

  iVar4 = 0;

  while( true ) {

    if (iVar2 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(param_1 + 8) - iVar2 >> 1;

    }

    if (iVar3 <= iVar4) break;

    if (*(char *)(iVar2 + iVar4 * 2) == param_3) {

      pcVar1 = (char *)(iVar2 + 1 + iVar4 * 2);

      *pcVar1 = *pcVar1 + (char)param_2;

      return;

    }

    iVar4 = iVar4 + 1;

  }

  cStack0000000d = (char)param_2;

  if ((iVar2 != 0) &&

     ((uint)(*(int *)(param_1 + 8) - iVar2 >> 1) < (uint)(*(int *)(param_1 + 0xc) - iVar2 >> 1))) {

    iVar2 = *(int *)(param_1 + 8);

    FUN_004aefa0(iVar2,1,&param_3,param_1,param_2);

    *(int *)(param_1 + 8) = iVar2 + 2;

    return;

  }

  FUN_004afad0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),1,&param_3);

  return;

}
