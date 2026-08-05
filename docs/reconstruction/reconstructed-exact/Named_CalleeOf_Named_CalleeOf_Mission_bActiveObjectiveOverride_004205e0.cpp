// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Mission_bActiveObjectiveOverride_004205e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004205e0
// Callee of Named_CalleeOf_Mission_bActiveObjectiveOverride
// Address:   0x004205e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Mission_bActiveObjectiveOverride: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_004205e0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Mission_bActiveObjectiveOverride
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

int Named_CalleeOf_Named_CalleeOf_Mission_bActiveObjectiveOverride_004205e0(void)



{

  uint uVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint uVar4;

  

  uVar1 = *(uint *)(unaff_ESI[2] + 4);

  iVar3 = 0;

  uVar4 = 0;

  if (uVar1 != 0) {

    do {

      piVar2 = (int *)unaff_ESI[2];

      if ((*(char *)(*piVar2 + 4 + uVar4 * 8) != '\0') &&

         (iVar3 = (**(code **)(*(int *)*unaff_ESI + 0x10))

                            ((int *)*unaff_ESI,unaff_ESI[3],*(uint32_t /* width from decompiler */ *)(*piVar2 + uVar4 * 8),

                             piVar2[2]), iVar3 < 0)) {

        return iVar3;

      }

      uVar4 = uVar4 + 1;

    } while (uVar4 < uVar1);

  }

  return iVar3;

}
