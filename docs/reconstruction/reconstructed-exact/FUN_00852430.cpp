// =============================================================================
// FUN_00852430
// -----------------------------------------------------------------------------
// Stable ID: aa_00852430
// Address:   0x00852430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00852430 @ 0x00852430
// Stable ID: aa_00852430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00414de0, FUN_00792600, FUN_0084f760, FUN_00852430.
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

void __fastcall FUN_00852430(int *param_1)



{

  void *pvVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint8_t *puVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b48ca;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00792600();

  pvVar1 = operator_new(0x48c);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    iVar2 = 0;

  }

  else {

    iVar2 = FUN_00414de0();

  }

  local_4 = 0xffffffff;

  param_1[0x19a] = iVar2;

  (**(code **)(*param_1 + 0xa8))();

  (**(code **)(*(int *)param_1[0x19a] + 0x28))(param_1[0xa1]);

  (**(code **)(*(int *)param_1[0x19a] + 0x110))(&stack0xffffffe4);

  iVar2 = *(int *)param_1[0x19a];

  puVar4 = &stack0xffffffe0;

  uVar3 = (**(code **)(*param_1 + 0x140))(puVar4,1);

  (**(code **)(iVar2 + 0x130))(uVar3);

  (**(code **)(*(int *)param_1[0x19a] + 0xfc))(1,0x3f000000);

  (**(code **)(*(int *)param_1[0x19a] + 0x300))(1);

  *(int **)(param_1[0x19a] + 0x488) = param_1;

  FUN_0084f760();

  (**(code **)(*param_1 + 0x444))();

  (**(code **)(*param_1 + 0x34c))();

  ExceptionList = puVar4;

  return;

}
