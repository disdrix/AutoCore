// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_0063ff50
// -----------------------------------------------------------------------------
// Stable ID: aa_0063ff50
// Callee of Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x
// Address:   0x0063ff50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x: callee helper. Evidence string: "unnamed_%x". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "unnamed_%x"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, for×1.
//  - Notable callees: FUN_005b3300×2, FUN_00637f30, FUN_0063ff50.
//  - Strings: "unnamed_%x".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x
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

void Named_CalleeOf_Named_CalleeOf_Named_SERVER_GOT_GIGO_0x_x_0063ff50(int *param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *unaff_EBP;

  int *unaff_EDI;

  

  iVar2 = (**(code **)(*param_1 + 4))(0,0);

  if (iVar2 == 0) {

    if ((unaff_EDI[2] & 0x7fffffffU) < 0x19) {

      FUN_005b3300();

    }

    unaff_EDI[1] = 0x19;

    FUN_00637f30(*unaff_EDI,0x19,"unnamed_%x",param_1);

    return;

  }

  iVar3 = unaff_EDI[1];

  iVar1 = iVar2 + 1;

  if (iVar3 < iVar1) {

    if ((int)(unaff_EDI[2] & 0x7fffffffU) < iVar1) {

      FUN_005b3300();

    }

    for (; iVar3 < iVar1; iVar3 = iVar3 + 1) {

      *(uint8_t *)(iVar3 + *unaff_EDI) = 0;

    }

  }

  unaff_EDI[1] = iVar1;

  (**(code **)(*unaff_EBP + 4))(*unaff_EDI,iVar2);

  return;

}
