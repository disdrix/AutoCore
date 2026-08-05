// =============================================================================
// FUN_004d4890
// -----------------------------------------------------------------------------
// Stable ID: aa_004d4890
// Address:   0x004d4890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d4890 @ 0x004d4890
// Stable ID: aa_004d4890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~110 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_006c6d00×31, FUN_006c6d40×19, FUN_006c6d80×11, FUN_004b4eb0, FUN_004cfca0, FUN_004d4890, FUN_004e4b10, FUN_0055e9b0.
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

uint32_t /* width from decompiler */ __fastcall FUN_004d4890(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *pvVar4;

  void *pvStack_2c;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a20c2;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  FUN_004e4b10();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = 0;

  FUN_005e1ae0();

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))();

  *(uint16_t *)(iVar1 + 4) = 0x260;

  pvStack_1c = (void *)0x0;

  uVar2 = FUN_00561e20();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4a4) = uVar2;

  pvStack_1c = (void *)0xffffffff;

  FUN_006c70a0();

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))();

  *(uint16_t *)(iVar1 + 4) = 0x9c;

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_006c6fd0();

  FUN_006c6d40(6);

  FUN_006c6d40(6);

  FUN_006c6d40(6);

  FUN_006c6d80(0x20);

  FUN_006c6d00(5);

  FUN_006c6d40(4);

  FUN_006c6d40(2);

  FUN_006c6d40(2);

  FUN_006c6d80(0x80);

  FUN_006c6d00(7);

  FUN_006c6d00(7);

  FUN_006c6d40(3);

  FUN_006c6d80(0x10000);

  FUN_006c6d40(8);

  FUN_006c6d40(8);

  FUN_006c6d40(8);

  FUN_006c6d40(8);

  FUN_006c6d40(8);

  FUN_006c6d40(9);

  FUN_006c6d40(9);

  FUN_006c6d40(9);

  FUN_006c6d40(9);

  FUN_006c6d40(9);

  FUN_006c6d80(0x2000);

  FUN_006c6d00(0xd);

  FUN_006c6d80(0x4000);

  FUN_006c6d00(0xe);

  FUN_006c6d80(0x8000);

  FUN_006c6d00(0xf);

  FUN_006c6d00(0xf);

  FUN_006c6d80(8);

  FUN_006c6d00(3);

  FUN_006c6d00(3);

  FUN_006c6d00(3);

  FUN_006c6d00(3);

  FUN_006c6d80(0x20000);

  FUN_006c6d00(0x11);

  FUN_006c6d00(0x11);

  FUN_006c6d00(0x11);

  FUN_006c6d00(0x14);

  FUN_006c6d00(0x14);

  FUN_006c6d00(0x14);

  FUN_006c6d00(0x14);

  FUN_006c6d00(0x14);

  FUN_006c6d80(0x40000);

  FUN_006c6d00(0x12);

  FUN_006c6d00(0x12);

  FUN_006c6d00(0x12);

  FUN_006c6d80(0x80000);

  FUN_006c6d00(0x13);

  FUN_006c6d00(0x13);

  FUN_006c6d80(0x200000);

  FUN_006c6d00(0x15);

  FUN_006c6d00(0x15);

  FUN_006c6d00(0x15);

  FUN_006c6d00(0x15);

  FUN_006c6d00(0x15);

  FUN_006c6d00(0x15);

  FUN_006c6d00(0x15);

  FUN_006c6d40(0x16);

  FUN_006c6d40(0x16);

  FUN_00562530(puVar3);

  *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + -1;

  if (*(short *)((int)puVar3 + 6) == 0) {

    (**(code **)*puVar3)();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x90) = 0;

  pvVar4 = operator_new(0x48);

  if (pvVar4 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_005d9020();

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4f4) = uVar2;

  FUN_0055e9b0();

  FUN_004b4eb0();

  if ((*(int *)(param_1 + 0xe4ec) != 0) || (*(char *)(param_1 + 0x7d) != '\0')) {

    FUN_004cfca0();

  }

  ExceptionList = pvStack_2c;

  return 1;

}
