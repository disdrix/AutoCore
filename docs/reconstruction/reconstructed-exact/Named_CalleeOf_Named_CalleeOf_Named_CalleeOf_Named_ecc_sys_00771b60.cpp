// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00771b60
// -----------------------------------------------------------------------------
// Stable ID: aa_00771b60
// Callee of Named_CalleeOf_Named_CalleeOf_Named_ecc_sys
// Address:   0x00771b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, while×1.
//  - Notable callees: FUN_00770650×2, FUN_007701d0, FUN_00770820, FUN_00771b60.
//  - Return sites: 3.

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

int Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00771b60(uint param_1)



{

  uint *puVar1;

  int *in_EAX;

  int iVar2;

  int *unaff_ESI;

  

  if ((int)param_1 < 1) {

    FUN_007701d0();

    return 0;

  }

  if ((int)param_1 < *in_EAX * 0x1c) {

    iVar2 = FUN_00770650();

    if (iVar2 == 0) {

      iVar2 = (uint)((int)param_1 % 0x1c != 0) + (int)param_1 / 0x1c;

      if (iVar2 < *unaff_ESI) {

        do {

          *(uint32_t /* width from decompiler */ *)(unaff_ESI[3] + iVar2 * 4) = 0;

          iVar2 = iVar2 + 1;

        } while (iVar2 < *unaff_ESI);

      }

      puVar1 = (uint *)(unaff_ESI[3] + ((int)param_1 / 0x1c) * 4);

      *puVar1 = *puVar1 & (1 << (sbyte)((ulonglong)param_1 % 0x1c)) - 1U;

      FUN_00770820();

      iVar2 = 0;

    }

    return iVar2;

  }

  iVar2 = FUN_00770650();

  return iVar2;

}
