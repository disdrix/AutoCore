// =============================================================================
// FUN_008bd3c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008bd3c0
// Address:   0x008bd3c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008bd3c0 @ 0x008bd3c0
// Stable ID: aa_008bd3c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, do×1, while×1.
//  - Notable callees: FUN_007916e0, FUN_008bd3c0.
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

void __thiscall FUN_008bd3c0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int *piVar2;

  

  FUN_007916e0(param_2);

  if (((char)param_2 != '\0') &&

     ((*(int *)(param_1 + 0x550) == 0 ||

      ((uint)(*(int *)(param_1 + 0x554) - *(int *)(param_1 + 0x550) >> 2) < 4)))) {

    if (*(int *)(param_1 + 0x550) == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(param_1 + 0x554) - *(int *)(param_1 + 0x550) >> 2;

      if (3 < iVar1) {

        return;

      }

    }

    piVar2 = (int *)(param_1 + 0x56c + iVar1 * 4);

    iVar1 = 4 - iVar1;

    do {

      if (piVar2[-4] != 0) {

        (**(code **)(*(int *)piVar2[-4] + 0xcc))(0);

      }

      if (*piVar2 != 0) {

        (**(code **)(*(int *)*piVar2 + 0xcc))(0);

      }

      if (piVar2[4] != 0) {

        (**(code **)(*(int *)piVar2[4] + 0xcc))(0);

      }

      if (piVar2[8] != 0) {

        (**(code **)(*(int *)piVar2[8] + 0xcc))(0);

      }

      if (piVar2[0xc] != 0) {

        (**(code **)(*(int *)piVar2[0xc] + 0xcc))(0);

      }

      piVar2 = piVar2 + 1;

      iVar1 = iVar1 + -1;

    } while (iVar1 != 0);

  }

  return;

}
