// =============================================================================
// FUN_00746b90
// -----------------------------------------------------------------------------
// Stable ID: aa_00746b90
// Address:   0x00746b90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00746b90 @ 0x00746b90
// Stable ID: aa_00746b90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×3, while×2, do×1, return×1.
//  - Notable callees: FUN_00746910, FUN_00746b90.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ FUN_00746b90(void)



{

  bool bVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  puVar4 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 4);

  puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 8) + -8);

  bVar1 = false;

  if (puVar4 != puVar3) {

    do {

      puVar5 = puVar4;

      if ((*(byte *)((int)puVar4 + 6) != 0) && (*(byte *)((int)puVar4 + 6) < 3)) {

        puVar3 = *(uint32_t /* width from decompiler */ **)(unaff_ESI + 8);

        puVar5 = puVar4 + -2;

        puVar2 = puVar4;

        while (puVar2 = puVar2 + 2, puVar2 != puVar3) {

          *puVar4 = *puVar2;

          puVar4[1] = puVar2[1];

          puVar4 = puVar4 + 2;

        }

        *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -8;

        bVar1 = true;

        puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 8) + -8);

      }

      puVar4 = puVar5 + 2;

    } while (puVar4 != puVar3);

    if (bVar1) {

      FUN_00746910();

    }

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = 0;

  return 0;

}
