// =============================================================================
// FUN_007ae450
// -----------------------------------------------------------------------------
// Stable ID: aa_007ae450
// Address:   0x007ae450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007ae450 @ 0x007ae450
// Stable ID: aa_007ae450
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, while×2, do×1, return×1.
//  - Notable callees: FUN_00423f40×2, FUN_004294f0, FUN_007ae450, LeaveCriticalSection.
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

char * __fastcall FUN_007ae450(int param_1)



{

  char *pcVar1;

  char cVar2;

  int iVar3;

  char *pcVar4;

  char *pcVar5;

  int *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0;

  pcVar5 = (char *)0x0;

  FUN_004294f0();

  iVar3 = FUN_00423f40(&local_8);

  while (iVar3 == 0) {

    if (((*local_8 == 1) && (pcVar4 = (char *)local_8[1], pcVar4 != (char *)0x0)) &&

       (*pcVar4 != '\0')) {

      pcVar1 = pcVar4 + 1;

      do {

        cVar2 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar2 != '\0');

      pcVar5 = pcVar4 + ((int)pcVar5 - (int)pcVar1);

    }

    else if ((*local_8 == 0xc) && (local_8[1] != 0)) {

      pcVar5 = pcVar5 + 1;

    }

    iVar3 = FUN_00423f40(&local_8);

  }

  if (*(char *)(param_1 + 0x210) != '\0') {

    *(uint8_t *)(param_1 + 0x210) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1ec));

  }

  return pcVar5;

}
