// =============================================================================
// FUN_00856930
// -----------------------------------------------------------------------------
// Stable ID: aa_00856930
// Address:   0x00856930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00856930 @ 0x00856930
// Stable ID: aa_00856930
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007b5dd0, FUN_00856930.
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

int * FUN_00856930(int *param_1)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b36ef;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_007b5dd0(param_1,0);

  local_4 = 0;

  *param_1 = (int)&PTR_FUN_00a66dec;

  *(uint8_t *)((int)param_1 + 0x49a) = 0xff;

  *(uint8_t *)((int)param_1 + 0x499) = 0xff;

  *(uint8_t *)(param_1 + 0x126) = 0xff;

  *(uint8_t *)((int)param_1 + 0x49b) = 0xff;

  *(uint8_t *)(param_1 + 0x123) = 0;

  param_1[0x122] = 0;

  param_1[0x124] = 0;

  param_1[0x125] = 0;

  if (*(char *)((int)param_1 + 0xc9) != '\0') {

    *(uint8_t *)((int)param_1 + 0xc9) = 0;

    (**(code **)(*param_1 + 0x4c))();

    cVar2 = (**(code **)(*param_1 + 0xd8))();

    if ((cVar2 != '\0') && ((int *)param_1[0xac] != (int *)0x0)) {

      iVar1 = *(int *)param_1[0xac];

      uVar3 = (**(code **)(*param_1 + 0x78))();

      (**(code **)(iVar1 + 0x338))(0x16,uVar3);

    }

    *(uint8_t *)(param_1 + 0x23) = *(uint8_t *)((int)param_1 + 0xc9);

  }

  ExceptionList = local_c;

  return param_1;

}
