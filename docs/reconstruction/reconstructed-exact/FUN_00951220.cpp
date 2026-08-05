// =============================================================================
// FUN_00951220
// -----------------------------------------------------------------------------
// Stable ID: aa_00951220
// Address:   0x00951220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00951220 @ 0x00951220
// Stable ID: aa_00951220
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, goto×2, while×2, do×1, return×1.
//  - Notable callees: FUN_004022a0×2, FUN_004294f0, FUN_004bade0, FUN_004badf0, FUN_00502970, FUN_00951220, LeaveCriticalSection.
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

uint32_t /* width from decompiler */ __fastcall FUN_00951220(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  FUN_004bade0();

  iVar3 = *(int *)(*(int *)(param_1 + 0xd34) + 0x18);

  iVar3 = *(int *)(*(int *)(*(int *)(iVar3 + 0x10) + (*(uint *)(iVar3 + 8) & 0xe) * 4) + 4);

  local_4 = 0;

  if (iVar3 == 0) {

LAB_0095126b:

    iVar3 = 0;

  }

  else {

    do {

      if (*(int *)(iVar3 + 0x10) == 0xe) {

        if (iVar3 == 0) goto LAB_0095126b;

        iVar3 = *(int *)(iVar3 + 8);

        goto LAB_00951272;

      }

      iVar3 = *(int *)(iVar3 + 0xc);

    } while (iVar3 != 0);

    iVar3 = 0;

  }

LAB_00951272:

  local_8 = (int *)0x0;

  if (iVar3 != 0) {

    FUN_004294f0();

    iVar2 = FUN_004022a0(&local_4,&local_8);

    piVar1 = local_8;

    while (local_8 = piVar1, iVar2 == 0) {

      iVar2 = (**(code **)(*piVar1 + 0x1d4))();

      if (iVar2 != 0) {

        (**(code **)(*piVar1 + 0x1d4))();

        FUN_00502970();

      }

      iVar2 = FUN_004022a0(&local_4,&local_8);

      piVar1 = local_8;

    }

    if (*(char *)(iVar3 + 0x28) != '\0') {

      *(uint8_t *)(iVar3 + 0x28) = 0;

      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 4));

    }

  }

  FUN_004badf0();

  return 1;

}
