// =============================================================================
// Named_CalleeOf_Named_Palantir_00968b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00968b20
// Callee of Named_Palantir
// Address:   0x00968b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Palantir: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_0075ece0, FUN_0075fb90, FUN_00968b20.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Palantir
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

uint Named_CalleeOf_Named_Palantir_00968b20(void)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  int *piVar4;

  

  uVar1 = FUN_0075fb90();

  if ((int)uVar1 < 0) {

    return 0xffffffff;

  }

  piVar4 = (int *)*DAT_00d1ee30;

  if (piVar4 != DAT_00d1ee30) {

    do {

      if ((int *)piVar4[2] != (int *)0x0) {

        iVar2 = (**(code **)(*(int *)piVar4[2] + 0x14))(&DAT_00d1f024,3);

        if (iVar2 < 0) {

          uVar1 = 0xffffffff;

        }

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != DAT_00d1ee30);

  }

  uVar3 = FUN_0075ece0();

  return uVar3 | uVar1;

}
