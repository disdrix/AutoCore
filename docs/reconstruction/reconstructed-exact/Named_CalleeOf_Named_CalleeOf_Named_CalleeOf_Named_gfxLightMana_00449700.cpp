// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxLightMana_00449700
// -----------------------------------------------------------------------------
// Stable ID: aa_00449700
// Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxLightManager
// Address:   0x00449700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_gfxLightManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×6, goto×2, while×2, return×2, do×1.
//  - Notable callees: FUN_00449700.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_gfxLightManager
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxLightMana_00449700(uint *param_1)



{

  int *piVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *in_EAX;

  uint uVar4;

  int *piVar5;

  int *piVar6;

  int unaff_EDI;

  

  uVar2 = *param_1;

  uVar4 = uVar2 & *(uint *)(unaff_EDI + 0x20);

  if (*(uint *)(unaff_EDI + 0x24) <= uVar4) {

    uVar4 = uVar4 + (-1 - (*(uint *)(unaff_EDI + 0x20) >> 1));

  }

  piVar1 = (int *)(*(int *)(unaff_EDI + 0x14) + uVar4 * 4);

  piVar5 = (int *)*piVar1;

  if (piVar5 != (int *)piVar1[1]) {

    do {

      if (uVar2 <= (uint)piVar5[2]) {

        if (piVar5 != (int *)piVar1[1]) {

          piVar6 = piVar5;

          goto LAB_00449750;

        }

        break;

      }

      piVar5 = (int *)*piVar5;

    } while (piVar5 != (int *)piVar1[1]);

  }

  goto LAB_0044973b;

  while (piVar6 = (int *)*piVar6, piVar6 != (int *)piVar1[1]) {

LAB_00449750:

    if (uVar2 < (uint)piVar6[2]) break;

  }

  if (piVar5 != piVar6) {

    *in_EAX = piVar5;

    in_EAX[1] = piVar6;

    return;

  }

LAB_0044973b:

  uVar3 = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8);

  *in_EAX = uVar3;

  in_EAX[1] = uVar3;

  return;

}
