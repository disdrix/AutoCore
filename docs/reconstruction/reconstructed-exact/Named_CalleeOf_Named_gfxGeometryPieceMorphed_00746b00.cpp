// =============================================================================
// Named_CalleeOf_Named_gfxGeometryPieceMorphed_00746b00
// -----------------------------------------------------------------------------
// Stable ID: aa_00746b00
// Callee of Named_gfxGeometryPieceMorphed
// Address:   0x00746b00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxGeometryPieceMorphed: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×6, while×2, goto×2, do×1, return×1.
//  - Notable callees: FUN_00746910, FUN_00746b00.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxGeometryPieceMorphed
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

uint32_t /* width from decompiler */ Named_CalleeOf_Named_gfxGeometryPieceMorphed_00746b00(void)



{

  char cVar1;

  bool bVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  puVar5 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 4);

  puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 8) + -8);

  bVar2 = false;

  if (puVar5 != puVar4) {

    do {

      cVar1 = *(char *)((int)puVar5 + 6);

      puVar6 = puVar5;

      if (cVar1 == '\0') {

LAB_00746b24:

        if (*(char *)((int)puVar5 + 7) != '\0') {

LAB_00746b2a:

          puVar4 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8);

          puVar6 = puVar5 + -2;

          puVar3 = puVar5;

          while (puVar3 = puVar3 + 2, puVar3 != puVar4) {

            *puVar5 = *puVar3;

            puVar5[1] = puVar3[1];

            puVar5 = puVar5 + 2;

          }

          *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -8;

          bVar2 = true;

          puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 8) + -8);

        }

      }

      else {

        if (cVar1 == '\x02') goto LAB_00746b2a;

        if (cVar1 == '\x03') goto LAB_00746b24;

      }

      puVar5 = puVar6 + 2;

    } while (puVar5 != puVar4);

    if (bVar2) {

      FUN_00746910();

    }

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = 0;

  return 0;

}
