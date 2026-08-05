// =============================================================================
// Named_CalleeOf_Named_ecc_sys_00774cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00774cc0
// Callee of Named_ecc_sys (+1 other named callers)
// Address:   0x00774cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_ecc_sys (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, while×1.
//  - Notable callees: FUN_007701d0, FUN_00770490, FUN_00770820, FUN_00772b90, FUN_00774cc0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_ecc_sys (+1 other named callers)
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

int __fastcall Named_CalleeOf_Named_ecc_sys_00774cc0(byte *param_1,int *param_2)



{

  int in_EAX;

  int iVar1;

  

  if ((1 < param_2[1]) || (iVar1 = FUN_00770490(), iVar1 == 0)) {

    FUN_007701d0();

    while (0 < in_EAX) {

      in_EAX = in_EAX + -1;

      iVar1 = FUN_00772b90(8);

      if (iVar1 != 0) {

        return iVar1;

      }

      *(uint *)param_2[3] = *(uint *)param_2[3] | (uint)*param_1;

      *param_2 = *param_2 + 1;

      param_1 = param_1 + 1;

    }

    FUN_00770820();

    iVar1 = 0;

  }

  return iVar1;

}
