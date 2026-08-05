// =============================================================================
// FUN_00856380
// -----------------------------------------------------------------------------
// Stable ID: aa_00856380
// Address:   0x00856380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00856380 @ 0x00856380
// Stable ID: aa_00856380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_004bfd10, FUN_00755db0, FUN_00755e80, FUN_0076c4d0, FUN_0078ca80, FUN_007afdc0, FUN_00856380.
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

void __fastcall FUN_00856380(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  int iVar2;

  char cVar3;

  uint32_t /* width from decompiler */ uVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b4940;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a671a4;

  local_4 = 0;

  FUN_007afdc0();

  iVar1 = param_1[0x145];

  if (iVar1 != 0) {

    iVar2 = param_1[0xaa];

    *(uint8_t *)(iVar2 + 0x48) = 1;

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x40);

    FUN_0076c4d0();

    cVar3 = (**(code **)(**(int **)(iVar2 + 8) + 8))(iVar1);

    if (cVar3 != '\0') {

      FUN_00755db0(iVar1);

      FUN_00755e80(iVar1);

    }

    if ((uint32_t /* width from decompiler */ *)param_1[0x145] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x145])(1);

    }

    param_1[0x145] = 0;

  }

  if ((int *)param_1[0x140] != (int *)0x0) {

    uVar4 = (**(code **)(*(int *)param_1[0x140] + 0x1cc))();

    FUN_004bfd10(uVar4);

    if ((uint32_t /* width from decompiler */ *)param_1[0x140] != (uint32_t /* width from decompiler */ *)0x0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x140])(1);

    }

    param_1[0x140] = 0;

  }

  param_1[0xa6] = 0;

  param_1[0x145] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0x146] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0x146])(1);

  }

  param_1[0x146] = 0;

  *(uint8_t *)(param_1 + 0x2f) = 0;

  local_4 = 0xffffffff;

  FUN_0078ca80();

  ExceptionList = pvStack_c;

  return;

}
