// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0055c250
// -----------------------------------------------------------------------------
// Stable ID: aa_0055c250
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0055c250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_0055b470, FUN_0055be00, FUN_0055c250.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_0055c250(int param_1,uint param_2)



{

  int iVar1;

  uint uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  iVar3 = *(int *)(param_1 + 4);

  if (iVar3 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = (*(int *)(param_1 + 8) - iVar3) / 0x1c;

  }

  if (param_2 <= uVar2) {

    if (((iVar3 != 0) && (iVar1 = *(int *)(param_1 + 8), param_2 < (uint)((iVar1 - iVar3) / 0x1c)))

       && (iVar3 = iVar3 + param_2 * 0x1c, iVar3 != iVar1)) {

      uVar4 = FUN_0055b470(iVar1,iVar1,iVar3,param_2);

      *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar4;

    }

    return;

  }

  if (iVar3 == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = (*(int *)(param_1 + 8) - iVar3) / 0x1c;

  }

  FUN_0055be00(*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2 - iVar3,&stack0x00000008);

  return;

}
