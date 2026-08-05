// =============================================================================
// FUN_00796520
// -----------------------------------------------------------------------------
// Stable ID: aa_00796520
// Address:   0x00796520  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00796520 @ 0x00796520
// Stable ID: aa_00796520
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×1.
//  - Notable callees: FUN_00796520.
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

void FUN_00796520(int param_1)



{

  int *piVar1;

  int in_EAX;

  int iVar2;

  int *piVar3;

  

  piVar3 = (int *)(in_EAX + 0xc);

  iVar2 = 0x19;

  do {

    piVar1 = (int *)*piVar3;

    if (piVar1 != (int *)0x0) {

      (**(code **)(*piVar1 + 0x20))(piVar1);

      if (param_1 == 0) {

        (**(code **)(*(int *)*piVar3 + 0x78))((int *)*piVar3,in_EAX + 0x84,0,1);

      }

      (**(code **)(*(int *)*piVar3 + 8))((int *)*piVar3);

      *piVar3 = 0;

    }

    piVar3 = piVar3 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  piVar3 = (int *)(in_EAX + 0x70);

  iVar2 = 3;

  do {

    piVar1 = (int *)*piVar3;

    if (piVar1 != (int *)0x0) {

      (**(code **)(*piVar1 + 0x20))(piVar1);

      (**(code **)(*(int *)*piVar3 + 8))((int *)*piVar3);

      *piVar3 = 0;

    }

    piVar3 = piVar3 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  return;

}
