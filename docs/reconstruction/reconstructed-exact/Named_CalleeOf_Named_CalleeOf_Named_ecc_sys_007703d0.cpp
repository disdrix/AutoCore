// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_007703d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007703d0
// Callee of Named_CalleeOf_Named_ecc_sys
// Address:   0x007703d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_007703d0, malloc.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_ecc_sys
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_007703d0(void)



{

  uint in_EAX;

  uint uVar1;

  void *pvVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *unaff_EDI;

  

  uVar1 = in_EAX & 0x8000003f;

  if ((int)uVar1 < 0) {

    uVar1 = (uVar1 - 1 | 0xffffffc0) + 1;

  }

  iVar4 = in_EAX + (0x80 - uVar1);

  pvVar2 = malloc(iVar4 * 4);

  unaff_EDI[3] = pvVar2;

  if (pvVar2 != (void *)0x0) {

    iVar3 = 0;

    *unaff_EDI = 0;

    unaff_EDI[1] = iVar4;

    unaff_EDI[2] = 0;

    if (0 < iVar4) {

      do {

        *(uint32_t /* width from decompiler */ *)(unaff_EDI[3] + iVar3 * 4) = 0;

        iVar3 = iVar3 + 1;

      } while (iVar3 < iVar4);

    }

    return 0;

  }

  return 0xfffffffe;

}
