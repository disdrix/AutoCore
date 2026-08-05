// =============================================================================
// Named_CalleeOf_Named_gfxLightTriage_0073e480
// -----------------------------------------------------------------------------
// Stable ID: aa_0073e480
// Callee of Named_gfxLightTriage
// Address:   0x0073e480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxLightTriage: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×2, do×2, while×2, return×1.
//  - Notable callees: FUN_0073e480.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxLightTriage
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

void Named_CalleeOf_Named_gfxLightTriage_0073e480(void)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_EDI;

  

  iVar2 = 0;

  piVar1 = (int *)*DAT_00d1f044;

  if (0 < *(int *)(unaff_EDI + 0x14)) {

    puVar3 = (uint32_t /* width from decompiler */ *)(unaff_EDI + 0x18);

    do {

      (**(code **)(*piVar1 + 0xd4))(piVar1,*puVar3,0);

      iVar2 = iVar2 + 1;

      puVar3 = puVar3 + 1;

    } while (iVar2 < *(int *)(unaff_EDI + 0x14));

  }

  iVar2 = 0;

  if (0 < *(int *)(unaff_EDI + 0x38)) {

    puVar3 = (uint32_t /* width from decompiler */ *)(unaff_EDI + 0x18);

    do {

      *puVar3 = puVar3[9];

      (**(code **)(*piVar1 + 0xd4))(piVar1,puVar3[9],1);

      iVar2 = iVar2 + 1;

      puVar3 = puVar3 + 1;

    } while (iVar2 < *(int *)(unaff_EDI + 0x38));

  }

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x14) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x38);

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x38) = 0;

  return;

}
