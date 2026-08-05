// =============================================================================
// FUN_00597ec0
// -----------------------------------------------------------------------------
// Stable ID: aa_00597ec0
// Address:   0x00597ec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00597ec0 @ 0x00597ec0
// Stable ID: aa_00597ec0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0055f210, FUN_00597ec0, FUN_00636490, FUN_00690170, hkpVehicleSteering_setSteeringAngle.
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

void __fastcall FUN_00597ec0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  void *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  undefined *puVar6;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a5abb;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0x60,0x27);

  *(uint16_t *)(iVar1 + 4) = 0x60;

  uVar3 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x44) + 8);

  puVar6 = &DAT_00af33b0;

  puVar5 = &DAT_00af33a0;

  puVar4 = &DAT_00af3390;

  pvStack_c = (void *)0x0;

  uVar2 = FUN_00690170(&DAT_00af3390,&DAT_00af33a0,&DAT_00af33b0);

  uVar3 = FUN_00636490(uVar3,uVar2,puVar4,puVar5,puVar6);

  pvStack_c = (void *)0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = uVar3;

  hkpVehicleSteering_setSteeringAngle(0);

  FUN_0055f210(*(uint32_t /* width from decompiler */ *)(param_1 + 0x3c));

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x3c);

  *(short *)((int)puVar4 + 6) = *(short *)((int)puVar4 + 6) + -1;

  if (*(short *)((int)puVar4 + 6) == 0) {

    (**(code **)*puVar4)(1,iVar1);

  }

  ExceptionList = unaff_EBX;

  return;

}
