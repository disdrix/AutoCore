// =============================================================================
// FUN_00853be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00853be0
// Address:   0x00853be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00853be0 @ 0x00853be0
// Stable ID: aa_00853be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: FUN_007916e0, FUN_00853be0.
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

void __thiscall FUN_00853be0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int iVar2;

  

  FUN_007916e0(param_2);

  if (((char)param_2 != '\0') && (iVar2 = *(int *)(param_1 + 0x55c), iVar2 < 4)) {

    piVar1 = (int *)(param_1 + 0x52c + iVar2 * 4);

    iVar2 = 4 - iVar2;

    do {

      if (piVar1[-4] != 0) {

        (**(code **)(*(int *)piVar1[-4] + 0xcc))(0);

      }

      if (*piVar1 != 0) {

        (**(code **)(*(int *)*piVar1 + 0xcc))(0);

      }

      if (piVar1[4] != 0) {

        (**(code **)(*(int *)piVar1[4] + 0xcc))(0);

      }

      if (piVar1[8] != 0) {

        (**(code **)(*(int *)piVar1[8] + 0xcc))(0);

      }

      piVar1 = piVar1 + 1;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

  }

  return;

}
