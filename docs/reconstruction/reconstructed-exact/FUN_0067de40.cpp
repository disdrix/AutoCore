// =============================================================================
// FUN_0067de40
// -----------------------------------------------------------------------------
// Stable ID: aa_0067de40
// Address:   0x0067de40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067de40 @ 0x0067de40
// Stable ID: aa_0067de40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: CONCAT31, FUN_0067dab0, FUN_0067de40.
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

void __fastcall FUN_0067de40(uint param_1)



{

  char cVar1;

  byte bVar2;

  uint local_4;

  

  local_4 = param_1;

  if (((*(int *)(param_1 + 0x2968) == 0) ||

      (local_4 = *(int *)(param_1 + 0x296c) - *(int *)(param_1 + 0x2968) >> 2, local_4 == 0)) &&

     (*(char *)(param_1 + 6) != '\0')) {

    bVar2 = 0;

    local_4 = local_4 & 0xffffff00;

    if (*(char *)(param_1 + 6) != '\0') {

      do {

        cVar1 = FUN_0067dab0(local_4);

        if (cVar1 != '\0') {

          bVar2 = bVar2 + 1;

          local_4 = CONCAT31(local_4._1_3_,bVar2);

        }

      } while (bVar2 < *(byte *)(param_1 + 6));

    }

  }

  return;

}
