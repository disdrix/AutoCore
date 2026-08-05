// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PlayNamedIn_0071f700
// -----------------------------------------------------------------------------
// Stable ID: aa_0071f700
// Callee of Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound
// Address:   0x0071f700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_0071f700.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound
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

byte Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PlayNamedIn_0071f700(void)



{

  int *piVar1;

  byte bVar2;

  uint uVar3;

  int unaff_EDI;

  uint local_4;

  

  bVar2 = 0;

  if (*(int *)(unaff_EDI + 0x10) != 0) {

    uVar3 = 0;

    if (*(int *)(unaff_EDI + 0x1c) != 0) {

      do {

        if (*(int *)(*(int *)(unaff_EDI + 0x10) + uVar3 * 4) != 0) {

          local_4 = 0;

          piVar1 = *(int **)(*(int *)(unaff_EDI + 0x10) + uVar3 * 4);

          (**(code **)(*piVar1 + 0x24))(piVar1,&local_4);

          bVar2 = bVar2 | (local_4 & 1) != 0;

        }

        uVar3 = uVar3 + 1;

      } while (uVar3 < *(uint *)(unaff_EDI + 0x1c));

    }

    *(byte *)(unaff_EDI + 0x1c5) = bVar2;

    return bVar2;

  }

  return 0;

}
