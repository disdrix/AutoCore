// =============================================================================
// FUN_00723510
// -----------------------------------------------------------------------------
// Stable ID: aa_00723510
// Address:   0x00723510  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00723510 @ 0x00723510
// Stable ID: aa_00723510
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~126 non-empty decompiler lines.
//  - Control keywords: for×1, do×1, while×1, return×1.
//  - Notable callees: InitializeCriticalSection×2, CONCAT31, FUN_004933f0, FUN_00723510, GetTickCount.
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

uint32_t /* width from decompiler */ * FUN_00723510(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  DWORD DVar3;

  void *pvVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int *piVar7;

  void *local_c;

  uint8_t *puStack_8;

  uint8_t local_4;

  undefined3 uStack_3;

  

  puStack_8 = &LAB_009abe30;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = 0;

  param_1[1] = 0;

  *(uint8_t *)(param_1 + 2) = 0;

  param_1[0x1b] = 0;

  param_1[0x80] = 0;

  param_1[0x81] = 0;

  param_1[0x82] = 0;

  param_1[0x83] = 0;

  param_1[0x84] = 0x18;

  param_1[0x85] = 6;

  param_1[0x88] = 0;

  param_1[0x89] = 0;

  param_1[0x8a] = 0;

  param_1[0x8b] = 0;

  param_1[0x8c] = 0;

  param_1[0x8d] = 0;

  param_1[0x8e] = 0;

  param_1[0x8f] = 0;

  param_1[0x90] = 0;

  param_1[0x91] = 0;

  param_1[0x92] = 0;

  param_1[0x93] = 0;

  param_1[0x94] = 0;

  param_1[0x95] = 0;

  *(uint8_t *)((int)param_1 + 0x259) = 1;

  *(uint8_t *)((int)param_1 + 0x25a) = 0;

  param_1[0x97] = 0;

  param_1[0xa1] = 0;

  param_1[0xa3] = 0;

  param_1[0xa4] = 0;

  param_1[0xa5] = 0;

  param_1[0xa7] = 0;

  param_1[0xa8] = 0;

  param_1[0xa9] = 0;

  uVar2 = DAT_00aaa668;

  local_4 = 1;

  uStack_3 = 0;

  param_1[0xb2] = DAT_00aaa668;

  param_1[0xb3] = uVar2;

  param_1[0xb4] = uVar2;

  param_1[0xb5] = uVar2;

  param_1[0xb6] = uVar2;

  param_1[0xb7] = g_flOne;

  uVar2 = DAT_00aaa688;

  param_1[0xb0] = 0xffffffff;

  param_1[0xb1] = 0xffffffff;

  param_1[0xb8] = uVar2;

  *(uint8_t *)(param_1 + 0xb9) = 2;

  *(uint8_t *)((int)param_1 + 0x2e5) = 8;

  param_1[0xba] = 0xfffffffe;

  *(uint8_t *)(param_1 + 0xbb) = 1;

  param_1[0xbc] = 0xac44;

  *(uint8_t *)(param_1 + 0xbd) = 0;

  *(uint8_t *)((int)param_1 + 0x2f5) = 0;

  *(uint8_t *)((int)param_1 + 0x2f6) = 0;

  *(uint8_t *)((int)param_1 + 0x2f7) = 0;

  *(uint8_t *)(param_1 + 0xbe) = 0;

  *(uint8_t *)((int)param_1 + 0x2f9) = 0;

  param_1[0xbf] = 0;

  *(uint8_t *)(param_1 + 0xc0) = 0;

  *(uint8_t *)((int)param_1 + 0x301) = 0;

  *(uint8_t *)((int)param_1 + 0x303) = 0;

  param_1[0xc1] = 0;

  *(uint8_t *)(param_1 + 0xc2) = 1;

  param_1[0xc3] = 0;

  uVar2 = FUN_004933f0();

  param_1[0xc5] = uVar2;

  param_1[0xc6] = 0;

  _local_4 = CONCAT31(uStack_3,2);

  DVar3 = GetTickCount();

  param_1[0xf7] = DVar3;

  *(uint8_t *)(param_1 + 0x104) = 0;

  param_1[0x105] = 0;

  puVar6 = param_1 + 199;

  for (iVar5 = 0x30; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  piVar7 = param_1 + 0x1c;

  iVar5 = 100;

  do {

    pvVar4 = operator_new(0x114);

    *piVar7 = (int)pvVar4;

    *(uint32_t /* width from decompiler */ *)((int)pvVar4 + 0x104) = 0;

    *(uint32_t /* width from decompiler */ *)(*piVar7 + 0x110) = 0;

    iVar1 = *piVar7;

    piVar7 = piVar7 + 1;

    iVar5 = iVar5 + -1;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x10c) = 0;

  } while (iVar5 != 0);

  param_1[0xaa] = 0;

  param_1[0xab] = 0;

  param_1[0xac] = 0;

  param_1[0xad] = 0;

  param_1[0xae] = 0;

  param_1[0x98] = 0;

  param_1[0x99] = 1;

  param_1[0x9a] = 2;

  param_1[0x9b] = 3;

  param_1[0x9c] = 4;

  param_1[0x9d] = 5;

  param_1[0x9e] = 6;

  param_1[0x9f] = 7;

  param_1[0xa0] = 8;

  param_1[0x98] = 9;

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xf8));

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xfe));

  ExceptionList = local_c;

  return param_1;

}
