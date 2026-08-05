// =============================================================================
// FUN_006f3ec0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f3ec0
// Address:   0x006f3ec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f3ec0 @ 0x006f3ec0
// Stable ID: aa_006f3ec0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×12, return×11, while×2, do×1.
//  - Notable callees: FUN_006f3ec0.
//  - Return sites: 11.

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

void __thiscall FUN_006f3ec0(int *param_1,float param_2)



{

  int *piVar1;

  int iVar2;

  

  iVar2 = *param_1 + -1;

  if (3 < *param_1) {

    do {

      piVar1 = (int *)(param_1[2] + iVar2 * 4);

      if (*piVar1 == 0) {

        return;

      }

      if (param_2 <= *(float *)(*piVar1 + 0xc)) {

        return;

      }

      param_1[3] = *piVar1;

      *piVar1 = 0;

      *param_1 = *param_1 + -1;

      piVar1 = (int *)(param_1[2] + -4 + iVar2 * 4);

      if (*piVar1 == 0) {

        return;

      }

      if (param_2 <= *(float *)(*piVar1 + 0xc)) {

        return;

      }

      param_1[3] = *piVar1;

      *piVar1 = 0;

      *param_1 = *param_1 + -1;

      piVar1 = (int *)(param_1[2] + -8 + iVar2 * 4);

      if (*piVar1 == 0) {

        return;

      }

      if (param_2 <= *(float *)(*piVar1 + 0xc)) {

        return;

      }

      param_1[3] = *piVar1;

      *piVar1 = 0;

      *param_1 = *param_1 + -1;

      piVar1 = (int *)(param_1[2] + -0xc + iVar2 * 4);

      if (*piVar1 == 0) {

        return;

      }

      if (param_2 <= *(float *)(*piVar1 + 0xc)) {

        return;

      }

      param_1[3] = *piVar1;

      *piVar1 = 0;

      iVar2 = iVar2 + -4;

      *param_1 = *param_1 + -1;

    } while (2 < iVar2);

  }

  while( true ) {

    if (iVar2 < 0) {

      return;

    }

    piVar1 = (int *)(param_1[2] + iVar2 * 4);

    if (*piVar1 == 0) break;

    if (param_2 <= *(float *)(*piVar1 + 0xc)) {

      return;

    }

    param_1[3] = *piVar1;

    *piVar1 = 0;

    iVar2 = iVar2 + -1;

    *param_1 = *param_1 + -1;

  }

  return;

}
