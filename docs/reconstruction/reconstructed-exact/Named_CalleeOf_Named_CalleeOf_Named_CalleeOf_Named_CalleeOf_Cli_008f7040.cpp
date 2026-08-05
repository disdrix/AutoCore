// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_008f7040
// -----------------------------------------------------------------------------
// Stable ID: aa_008f7040
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_OnBadCharac (+1 other named callers)
// Address:   0x008f7040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_OnBadCharac: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_OnBadCharac (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_008f7040.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_OnBadCharac (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_008f7040(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int unaff_EDI;

  float fVar3;

  int *piStack_1c;

  int iStack_18;

  int local_10 [2];

  uint8_t local_8 [8];

  

  if (*(int *)(unaff_EDI + 0x548) != 0) {

    if (DAT_00af9210 == -1) {

      iStack_18 = 1;

      piStack_1c = local_10;

      fVar3 = (float)*(int *)(unaff_EDI + 0x528) * (float)DAT_00d1e81c * DAT_00aaa678;

      iVar1 = (**(code **)(**(int **)(unaff_EDI + 0x548) + 0x140))();

      if (DAT_00d17944 == 0) {

        local_10[0] = 0;

        DAT_00af9210 = 0;

      }

      else {

        local_10[0] = (int)(0.0 / (float)DAT_00d1e818);

        DAT_00af9210 = (int)(((float)((int)fVar3 - *(int *)(iVar1 + 4) / 2) * DAT_00aaa670) /

                            (float)DAT_00d1e81c);

      }

    }

    iStack_18 = 0;

    piStack_1c = (int *)0x1;

    fVar3 = (float)DAT_00d1e81c * (float)DAT_00af9210 * DAT_00aaa678;

    puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(**(int **)(unaff_EDI + 0x548) + 0x120))(local_8);

    piStack_1c = (int *)*puVar2;

    iStack_18 = (int)fVar3;

    (**(code **)(**(int **)(unaff_EDI + 0x548) + 0x110))(&piStack_1c);

  }

  return;

}
