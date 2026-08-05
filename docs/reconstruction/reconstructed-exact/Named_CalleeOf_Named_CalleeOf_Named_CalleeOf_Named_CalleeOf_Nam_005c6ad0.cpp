// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005c6ad0
// -----------------------------------------------------------------------------
// Stable ID: aa_005c6ad0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x005c6ad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: CONCAT31, FUN_004ed310, FUN_005c6ad0, FUN_00971820.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_005c6ad0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  char cVar3;

  

  iVar2 = param_2;

  if (*(int *)(param_2 + 0x10) != 0) {

    iVar1 = *(int *)(param_1 + 0x54);

    if ((iVar1 < 1) || (6 < iVar1)) {

      if (6 < iVar1) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

      }

      if (*(int *)(DAT_00d1f050 + 0x6c) != 0) {

        FUN_00971820(param_2);

      }

    }

    param_2 = CONCAT31(param_2._1_3_,1);

    cVar3 = FUN_004ed310(iVar2,&param_2,param_1 + 0x5c);

    if (cVar3 == '\0') {

      *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;

      return 3;

    }

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

  return 0;

}
