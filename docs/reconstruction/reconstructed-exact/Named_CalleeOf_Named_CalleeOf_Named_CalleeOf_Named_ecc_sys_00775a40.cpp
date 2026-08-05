// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00775a40
// -----------------------------------------------------------------------------
// Stable ID: aa_00775a40
// Callee of Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
// Address:   0x00775a40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_007707d0×2, FUN_007701d0, FUN_00770440, FUN_00770650, FUN_00774b50, FUN_00774e60, FUN_00775a40.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00775a40(uint32_t /* width from decompiler */ param_1,uint param_2)



{

  int iVar1;

  int iVar2;

  uint *unaff_EBX;

  

  iVar1 = FUN_00770440();

  if (iVar1 == 0) {

    iVar1 = FUN_00770650();

    if (iVar1 == 0) {

      FUN_007701d0();

      *(uint32_t /* width from decompiler */ *)unaff_EBX[3] = 1;

      iVar1 = 0;

      *unaff_EBX = (uint)(*(int *)unaff_EBX[3] != 0);

      do {

        iVar2 = FUN_00774b50();

        if (iVar2 != 0) {

LAB_00775acd:

          FUN_007707d0();

          return iVar2;

        }

        if ((param_2 & 0x8000000) != 0) {

          iVar2 = FUN_00774e60();

          if (iVar2 != 0) goto LAB_00775acd;

        }

        iVar1 = iVar1 + 1;

        param_2 = param_2 * 2;

      } while (iVar1 < 0x1c);

      FUN_007707d0();

      iVar1 = 0;

    }

  }

  return iVar1;

}
