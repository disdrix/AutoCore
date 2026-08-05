// =============================================================================
// FUN_00890660
// -----------------------------------------------------------------------------
// Stable ID: aa_00890660
// Address:   0x00890660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00890660 @ 0x00890660
// Stable ID: aa_00890660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×4, while×1, return×1.
//  - Notable callees: FUN_004113b0×2, FUN_00416c90, FUN_004294f0, FUN_00890660, LeaveCriticalSection.
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

void FUN_00890660(int *param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  char cVar4;

  int iVar5;

  

  piVar3 = param_1;

  piVar1 = param_1 + 0x143;

  FUN_004294f0();

  iVar5 = FUN_004113b0(piVar1,&param_1);

  piVar2 = param_1;

  while (param_1 = piVar2, iVar5 == 0) {

    if (piVar2 != (int *)0x0) {

      cVar4 = (**(code **)(*piVar2 + 0x3d8))();

      if (cVar4 != '\0') {

        (**(code **)(*piVar2 + 0x440))();

      }

      (**(code **)(*piVar3 + 0xb0))(piVar2);

    }

    iVar5 = FUN_004113b0(piVar1,&param_1);

    piVar2 = param_1;

  }

  if ((char)piVar3[0x14d] != '\0') {

    *(uint8_t *)(piVar3 + 0x14d) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(piVar3 + 0x144));

  }

  FUN_00416c90();

  if (piVar3[0x14e] != 0) {

    (**(code **)(*(int *)piVar3[0x14e] + 4))(0);

  }

  DAT_00d17910 = 0;

  return;

}
