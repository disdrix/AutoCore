// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_007843e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007843e0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut
// Address:   0x007843e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CONCAT11×3, CONCAT21×2, CONCAT31×2, htons×2, FUN_007843e0, htonl.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Aut
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_007843e0(void)



{

  uint8_t uVar1;

  short sVar2;

  u_short uVar3;

  u_long uVar4;

  short *unaff_ESI;

  uint16_t *unaff_EDI;

  

  if (*unaff_ESI == 2) {

    *unaff_EDI = 0;

    uVar3 = htons(unaff_ESI[1]);

    unaff_EDI[1] = uVar3;

    uVar4 = htonl(*(u_long *)(unaff_ESI + 2));

    *(u_long *)(unaff_EDI + 2) = uVar4;

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 4) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 6) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8) = 0;

    return;

  }

  if (*unaff_ESI == 6) {

    *unaff_EDI = 2;

    uVar3 = htons(unaff_ESI[6]);

    unaff_EDI[1] = uVar3;

    *(uint *)(unaff_EDI + 2) =

         CONCAT31(CONCAT21(CONCAT11((char)unaff_ESI[1],*(uint8_t *)((int)unaff_ESI + 3)),

                           (char)unaff_ESI[2]),*(uint8_t *)((int)unaff_ESI + 5));

    *(uint *)(unaff_EDI + 4) =

         CONCAT31(CONCAT21(CONCAT11((char)unaff_ESI[3],*(uint8_t *)((int)unaff_ESI + 7)),

                           (char)unaff_ESI[4]),*(uint8_t *)((int)unaff_ESI + 9));

    sVar2 = unaff_ESI[5];

    uVar1 = *(uint8_t *)((int)unaff_ESI + 0xb);

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8) = 0;

    *(uint *)(unaff_EDI + 6) = (uint)CONCAT11((char)sVar2,uVar1);

  }

  return;

}
