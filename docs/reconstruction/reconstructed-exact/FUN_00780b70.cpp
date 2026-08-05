// =============================================================================
// FUN_00780b70
// -----------------------------------------------------------------------------
// Stable ID: aa_00780b70
// Address:   0x00780b70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00780b70 @ 0x00780b70
// Stable ID: aa_00780b70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, while×1.
//  - Notable callees: FUN_00429bd0, FUN_00780b70.
//  - Return sites: 2.

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

void FUN_00780b70(void)



{

  uint *puVar1;

  uint *puVar2;

  uint *unaff_ESI;

  int unaff_EDI;

  

  unaff_ESI[10] = unaff_ESI[10] | 0x10;

  if (unaff_ESI[2] == 0 && unaff_ESI[3] == 0) {

    unaff_ESI[2] = 0xffffffff;

    unaff_ESI[3] = 0xffffffff;

    FUN_00429bd0();

  }

  if (*unaff_ESI != 0) {

    if (unaff_ESI[6] == 0) {

      *(uint *)(*unaff_ESI + 0x24) = unaff_ESI[5];

    }

    else {

      *(uint *)(unaff_ESI[6] + 0x14) = unaff_ESI[5];

    }

    if (unaff_ESI[5] != 0) {

      *(uint *)(unaff_ESI[5] + 0x18) = unaff_ESI[6];

    }

    puVar2 = (uint *)(*(int *)(unaff_EDI + 0x224) + (*unaff_ESI & 0x3ff) * 4);

    if (*(int *)(*(int *)(unaff_EDI + 0x224) + (*unaff_ESI & 0x3ff) * 4) != 0) {

      while (puVar1 = (uint *)*puVar2, puVar1 != unaff_ESI) {

        puVar2 = puVar1 + 8;

        if (puVar1[8] == 0) {

          unaff_ESI[5] = 0;

          unaff_ESI[6] = 0;

          *unaff_ESI = 0;

          return;

        }

      }

      *puVar2 = puVar1[8];

    }

    unaff_ESI[5] = 0;

    unaff_ESI[6] = 0;

    *unaff_ESI = 0;

  }

  return;

}
