// =============================================================================
// FUN_008bee80
// -----------------------------------------------------------------------------
// Stable ID: aa_008bee80
// Address:   0x008bee80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008bee80 @ 0x008bee80
// Stable ID: aa_008bee80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×8, do×1, while×1, return×1.
//  - Notable callees: FUN_008becd0, FUN_008bee80.
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

void FUN_008bee80(void)



{

  int in_EAX;

  uint uVar1;

  int *piVar2;

  int iVar3;

  

  iVar3 = 0;

  piVar2 = (int *)(in_EAX + 0x54c);

  do {

    if (*(int *)(in_EAX + 0x52c) == 0) {

      uVar1 = 0;

    }

    else {

      uVar1 = *(int *)(in_EAX + 0x530) - *(int *)(in_EAX + 0x52c) >> 3;

    }

    if ((uint)(*(int *)(in_EAX + 0x524) + iVar3) < uVar1) {

      FUN_008becd0();

    }

    else {

      if (piVar2[-3] != 0) {

        (**(code **)(*(int *)piVar2[-3] + 4))(0);

      }

      if (*piVar2 != 0) {

        (**(code **)(*(int *)*piVar2 + 4))(0);

      }

      if (piVar2[9] != 0) {

        (**(code **)(*(int *)piVar2[9] + 4))(0);

      }

      if (piVar2[3] != 0) {

        (**(code **)(*(int *)piVar2[3] + 4))(0);

      }

      if (piVar2[0xc] != 0) {

        (**(code **)(*(int *)piVar2[0xc] + 4))(0);

      }

      if (piVar2[6] != 0) {

        (**(code **)(*(int *)piVar2[6] + 4))(0);

      }

    }

    iVar3 = iVar3 + 1;

    piVar2 = piVar2 + 1;

  } while (iVar3 < 3);

  return;

}
