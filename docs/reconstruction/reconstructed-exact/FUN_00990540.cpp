// =============================================================================
// FUN_00990540
// -----------------------------------------------------------------------------
// Stable ID: aa_00990540
// Address:   0x00990540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00990540 @ 0x00990540
// Stable ID: aa_00990540
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: block×8, FUN_00440680, FUN_00465af0, FUN_00990540.
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

/* WARNING: Removing unreachable block (ram,0x0099061f) */

/* WARNING: Removing unreachable block (ram,0x00990630) */

/* WARNING: Removing unreachable block (ram,0x0099064e) */

/* WARNING: Removing unreachable block (ram,0x0099069d) */

/* WARNING: Removing unreachable block (ram,0x0099065c) */

/* WARNING: Removing unreachable block (ram,0x0099069f) */

/* WARNING: Removing unreachable block (ram,0x009906b3) */

/* WARNING: Removing unreachable block (ram,0x009906bc) */



uint32_t /* width from decompiler */ FUN_00990540(int param_1,int *param_2)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  int iVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  piVar2 = param_2;

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009ad62c;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  (**(code **)(*param_2 + 0x34))();

  (**(code **)(*param_2 + 0x38))();

  iVar4 = 0;

  uStack_4 = 0;

  if (*(int *)(param_1 + 0xc0) == 0) {

    param_2 = (int *)0x0;

  }

  else {

    param_2 = (int *)(*(int *)(param_1 + 0xc4) - *(int *)(param_1 + 0xc0) >> 2);

  }

  FUN_00465af0(param_2);

  if (0 < (int)param_2) {

    do {

      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0xc0) + iVar4 * 4) + 0x90);

      if ((iVar1 != 0) && (piVar3 = (int *)(**(code **)(*piVar2 + 0x34))(), iVar1 == *piVar3)) {

        (**(code **)(*piVar2 + 0x38))();

        FUN_00440680();

      }

      iVar4 = iVar4 + 1;

    } while (iVar4 < (int)param_2);

  }

  ExceptionList = pvStack_c;

  return 0;

}
