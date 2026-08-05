// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_00607550
// -----------------------------------------------------------------------------
// Stable ID: aa_00607550
// Callee of Named_CalleeOf_CVOGReaction_Dispatch
// Address:   0x00607550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_Dispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_00607550, FUN_00608620.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_Dispatch
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_00607550(int param_1)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ uVar4;

  undefined *puVar5;

  

  puVar5 = &DAT_00d029e0;

  if (*(char *)(param_1 + 0x220) == '\0') {

    puVar5 = &DAT_00d029f0;

  }

  uVar1 = *(uint *)(param_1 + 0x23c);

  if (-1 < (int)uVar1) {

    iVar2 = *(int *)(puVar5 + 4);

    if (iVar2 == 0) {

      uVar3 = 0;

    }

    else {

      uVar3 = *(int *)(puVar5 + 8) - iVar2 >> 4;

    }

    if (uVar1 < uVar3) {

      if ((iVar2 != 0) && (uVar1 < (uint)(*(int *)(puVar5 + 8) - iVar2 >> 4))) {

        return *(uint32_t /* width from decompiler */ *)(uVar1 * 0x10 + 4 + iVar2);

      }

      uVar4 = FUN_00608620();

      return uVar4;

    }

  }

  return 0;

}
