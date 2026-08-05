// =============================================================================
// FUN_0092a440
// -----------------------------------------------------------------------------
// Stable ID: aa_0092a440
// Address:   0x0092a440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092a440 @ 0x0092a440
// Stable ID: aa_0092a440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00411180, FUN_004de760, FUN_0092a440.
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

int * __thiscall FUN_0092a440(int *param_1,int *param_2)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ac623;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  piVar1 = operator_new(0x20);

  local_4 = 0xffffffff;

  piVar1[4] = 0;

  piVar1[5] = 0;

  piVar1[6] = 0;

  piVar1[7] = 0;

  if (param_1 == (int *)0x0) {

    *piVar1 = DAT_00a158a0;

    piVar1[1] = DAT_00a158a4;

    piVar1[2] = DAT_00a158a8;

    iVar2 = DAT_00a158ac;

  }

  else {

    iVar2 = (**(code **)(*param_1 + 0x1d8))();

    if ((((iVar2 != 0) && (*param_2 != 0)) && (*(int *)(*param_2 + 0xe98) != 0)) &&

       (param_1[0x47] == 0)) {

      uVar3 = (**(code **)(*param_1 + 0x1d8))();

      FUN_004de760(*(uint32_t /* width from decompiler */ *)(*param_2 + 0xe98),uVar3);

    }

    *piVar1 = param_1[0x58];

    piVar1[1] = param_1[0x59];

    piVar1[2] = param_1[0x5a];

    iVar2 = param_1[0x5b];

  }

  piVar1[3] = iVar2;

  FUN_00411180();

  ExceptionList = pvStack_c;

  return piVar1;

}
