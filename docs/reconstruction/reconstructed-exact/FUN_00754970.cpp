// =============================================================================
// FUN_00754970
// -----------------------------------------------------------------------------
// Stable ID: aa_00754970
// Address:   0x00754970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00754970 @ 0x00754970
// Stable ID: aa_00754970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: FUN_00754970, ROUND.
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

void FUN_00754970(void)



{

  float fVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  uint8_t *puVar5;

  int local_8;

  int local_4;

  

  fVar1 = DAT_00aaa7a4;

  iVar4 = 0;

  puVar5 = &DAT_00d0dfe8;

  do {

    iVar2 = 0;

    do {

      if (iVar2 < 1) {

        puVar5[iVar2] = (char)iVar4;

      }

      else {

        local_8 = 0xf;

        local_4 = (int)ROUND(((float)iVar4 * fVar1) / (float)iVar2);

        if (local_4 < 0) {

          puVar5[iVar2] = 0;

        }

        else {

          piVar3 = &local_8;

          if (local_4 < 0x10) {

            piVar3 = &local_4;

          }

          puVar5[iVar2] = (char)*piVar3;

        }

      }

      iVar2 = iVar2 + 1;

    } while (iVar2 < 0x10);

    puVar5 = puVar5 + 0x10;

    iVar4 = iVar4 + 1;

  } while ((int)puVar5 < 0xd0e0e8);

  DAT_00d1a548 = 1;

  return;

}
