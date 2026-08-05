// =============================================================================
// Named_CalleeOf_Named_ecc_sys_00771c00
// -----------------------------------------------------------------------------
// Stable ID: aa_00771c00
// Callee of Named_ecc_sys
// Address:   0x00771c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1, for×1.
//  - Notable callees: FUN_00770490, FUN_00771c00.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_ecc_sys
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

int Named_CalleeOf_Named_ecc_sys_00771c00(void)



{

  int *in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_EBX;

  

  if (0 < unaff_EBX) {

    if ((in_EAX[1] < *in_EAX + unaff_EBX) && (iVar1 = FUN_00770490(), iVar1 != 0)) {

      return iVar1;

    }

    *in_EAX = *in_EAX + unaff_EBX;

    iVar1 = *in_EAX;

    puVar2 = (uint32_t /* width from decompiler */ *)(in_EAX[3] + -4 + iVar1 * 4);

    puVar3 = (uint32_t /* width from decompiler */ *)(in_EAX[3] + -4 + (iVar1 - unaff_EBX) * 4);

    if (unaff_EBX <= iVar1 + -1) {

      iVar1 = ((iVar1 + -1) - unaff_EBX) + 1;

      do {

        *puVar2 = *puVar3;

        puVar2 = puVar2 + -1;

        puVar3 = puVar3 + -1;

        iVar1 = iVar1 + -1;

      } while (iVar1 != 0);

    }

    puVar2 = (uint32_t /* width from decompiler */ *)in_EAX[3];

    if (0 < unaff_EBX) {

      for (; unaff_EBX != 0; unaff_EBX = unaff_EBX + -1) {

        *puVar2 = 0;

        puVar2 = puVar2 + 1;

      }

    }

  }

  return 0;

}
