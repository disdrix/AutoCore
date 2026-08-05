// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_0044cff0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044cff0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB
// Address:   0x0044cff0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×4, while×2, do×1, return×1.
//  - Notable callees: FUN_00746810×4, FUN_0044d320×2, FUN_0044cff0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_0044cff0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  

  iVar1 = param_1;

  if (param_1 != param_2) {

    while (iVar2 = iVar1, iVar1 = iVar2 + 8, iVar1 != param_2) {

      iVar4 = FUN_00746810();

      iVar5 = FUN_00746810();

      iVar3 = iVar1;

      if (iVar4 < iVar5) {

        if ((param_1 != iVar1) && (iVar1 != iVar2 + 0x10)) {

          FUN_0044d320(param_1,iVar1,iVar2 + 0x10);

        }

      }

      else {

        do {

          iVar6 = iVar3;

          iVar4 = FUN_00746810();

          iVar5 = FUN_00746810();

          iVar3 = iVar6 + -8;

        } while (iVar5 < iVar4);

        if ((iVar6 != iVar1) && (iVar1 != iVar2 + 0x10)) {

          FUN_0044d320(iVar6,iVar1,iVar2 + 0x10);

        }

      }

    }

  }

  return;

}
