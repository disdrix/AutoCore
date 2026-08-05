// =============================================================================
// FUN_008908c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008908c0
// Address:   0x008908c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008908c0 @ 0x008908c0
// Stable ID: aa_008908c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_004113b0×2, FUN_004294f0, FUN_00890710, FUN_008908c0, LeaveCriticalSection.
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

void FUN_008908c0(int *param_1)



{

  int *piVar1;

  int *piVar2;

  char cVar3;

  int iVar4;

  

  piVar2 = param_1;

  cVar3 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar3 != '\0') {

    FUN_004294f0();

    iVar4 = FUN_004113b0(piVar2 + 0x143,&param_1);

    piVar1 = param_1;

    while (param_1 = piVar1, iVar4 == 0) {

      if ((piVar1 != (int *)0x0) && (cVar3 = (**(code **)(*piVar1 + 0x3d8))(), cVar3 == '\0')) {

        (**(code **)(*piVar2 + 0xa8))(piVar1);

        (**(code **)(*piVar1 + 0x43c))();

      }

      iVar4 = FUN_004113b0(piVar2 + 0x143,&param_1);

      piVar1 = param_1;

    }

    if ((char)piVar2[0x14d] != '\0') {

      *(uint8_t *)(piVar2 + 0x14d) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(piVar2 + 0x144));

    }

  }

  FUN_00890710();

  return;

}
