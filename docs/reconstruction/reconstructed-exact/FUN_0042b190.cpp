// =============================================================================
// FUN_0042b190
// -----------------------------------------------------------------------------
// Stable ID: aa_0042b190
// Address:   0x0042b190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042b190 @ 0x0042b190
// Stable ID: aa_0042b190
// Embedded strings (evidence for future rename):
//   - "%s (Initial) - Count: %d   Avg Size: %g"
//   - "%s (Partial) - Count: %d   Avg Size: %g"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×6, for×1, return×1.
//  - Notable callees: FUN_00783aa0×3, s×2, FUN_0042b190.
//  - Strings: "%s (Initial) - Count: %d   Avg Size: %g"; "%s (Partial) - Count: %d   Avg Size: %g".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0042b190(void)



{

  int iVar1;

  int iVar2;

  float fVar3;

  float fVar4;

  

  FUN_00783aa0();

  for (iVar2 = DAT_00d179a4; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x34)) {

    if (*(int *)(iVar2 + 0x2c) != 0) {

      fVar3 = (float)*(int *)(iVar2 + 0x24);

      iVar1 = *(int *)(iVar2 + 0x2c);

      if (*(int *)(iVar2 + 0x24) < 0) {

        fVar3 = fVar3 + _DAT_00aaa5dc;

      }

      fVar4 = (float)iVar1;

      if (iVar1 < 0) {

        fVar4 = fVar4 + _DAT_00aaa5dc;

      }

      FUN_00783aa0("%s (Initial) - Count: %d   Avg Size: %g",*(uint32_t /* width from decompiler */ *)(iVar2 + 0x20),iVar1,

                   (double)(fVar3 / fVar4));

    }

    if (*(int *)(iVar2 + 0x30) != 0) {

      fVar3 = (float)*(int *)(iVar2 + 0x28);

      iVar1 = *(int *)(iVar2 + 0x30);

      if (*(int *)(iVar2 + 0x28) < 0) {

        fVar3 = fVar3 + _DAT_00aaa5dc;

      }

      fVar4 = (float)iVar1;

      if (iVar1 < 0) {

        fVar4 = fVar4 + _DAT_00aaa5dc;

      }

      FUN_00783aa0("%s (Partial) - Count: %d   Avg Size: %g",*(uint32_t /* width from decompiler */ *)(iVar2 + 0x20),iVar1,

                   (double)(fVar3 / fVar4));

    }

  }

  return;

}
