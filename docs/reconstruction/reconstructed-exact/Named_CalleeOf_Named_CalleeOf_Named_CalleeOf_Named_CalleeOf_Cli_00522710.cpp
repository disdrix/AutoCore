// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00522710
// -----------------------------------------------------------------------------
// Stable ID: aa_00522710
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen
// Address:   0x00522710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, while×1.
//  - Notable callees: FUN_00522710, FUN_00571010.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen
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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00522710(uint32_t /* width from decompiler */ param_1,int param_2)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  iVar4 = 1;

  iVar5 = 0;

  do {

    uVar1 = *(uint *)(param_2 + iVar5 * 8);

    uVar2 = *(uint *)(param_2 + 4 + iVar5 * 8);

    if ((uVar1 & uVar2) != 0xffffffff) {

      iVar3 = FUN_00571010(uVar1,uVar2);

      if (iVar3 == 0) {

        return iVar4;

      }

      if (*(int *)(*(int *)(iVar3 + 0xa8) + 0x38) != 0x1a) {

        return iVar4;

      }

      iVar4 = iVar4 + (uint)*(byte *)(*(int *)(*(int *)(iVar3 + 0xa8) + 0x3c) + 0x4c8) + iVar5;

    }

    iVar5 = iVar5 + 1;

    if (4 < iVar5) {

      return iVar4;

    }

  } while( true );

}
