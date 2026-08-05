// =============================================================================
// FUN_0085b8d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0085b8d0
// Address:   0x0085b8d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0085b8d0 @ 0x0085b8d0
// Stable ID: aa_0085b8d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00414070, FUN_00792600, FUN_00857670, FUN_0085b8d0.
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

void __fastcall FUN_0085b8d0(int *param_1)



{

  float fVar1;

  void *pvVar2;

  int iVar3;

  float fVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b49c1;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar2 = operator_new(0x48c);

  local_4 = 0;

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_00414070(pvVar2);

  }

  local_4 = 0xffffffff;

  param_1[0x1a9] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x1a9] + 0x28))(param_1[0xa1]);

  (**(code **)(*(int *)param_1[0x1a9] + 0xfc))(1);

  (**(code **)(*(int *)param_1[0x1a9] + 0x300))(1);

  *(int **)(param_1[0x1a9] + 0x488) = param_1;

  FUN_00857670();

  fVar1 = g_flOne;

  fVar4 = DAT_00af9320;

  if (DAT_00af931c < DAT_00af9320) {

    fVar4 = DAT_00af931c;

  }

  fVar4 = (fVar4 * DAT_00a0f298) / (float)param_1[0x141];

  param_1[0x13f] = (int)fVar4;

  if (fVar4 < fVar1) {

    param_1[0x13f] = (int)fVar1;

  }

  (**(code **)(*param_1 + 0x444))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = (void *)0x3f000000;

  return;

}
