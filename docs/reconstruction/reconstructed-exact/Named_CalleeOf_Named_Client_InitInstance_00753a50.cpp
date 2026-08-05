// =============================================================================
// Named_CalleeOf_Named_Client_InitInstance_00753a50
// -----------------------------------------------------------------------------
// Stable ID: aa_00753a50
// Callee of Named_Client_InitInstance
// Address:   0x00753a50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_InitInstance: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×4, for×1, return×1.
//  - Notable callees: FUN_0076c3c0×3, FUN_00753710, FUN_00753a50.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Client_InitInstance
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_CalleeOf_Named_Client_InitInstance_00753a50(int param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar4 = DAT_00d1f614;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009acc1e;

  pvStack_c = ExceptionList;

  uVar2 = *(uint32_t /* width from decompiler */ *)(DAT_00d1f614 + 0xc4);

  ExceptionList = &pvStack_c;

  if (*(char *)(DAT_00d1f614 + 200) == '\0') {

    ExceptionList = &pvStack_c;

    iVar5 = FUN_0076c3c0();

    piVar1 = (int *)(iVar4 + 0x34 + *(int *)(iVar4 + 0xc4) * 4);

    *piVar1 = *piVar1 + (iVar5 - *(int *)(iVar4 + 0x30));

    *(int *)(iVar4 + 0x30) = iVar5;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc4) = 3;

  }

  local_4 = 0;

  iVar6 = FUN_0076c3c0();

  iVar5 = *(int *)(param_1 + 0xec);

  *(int *)(param_1 + 0xec) = iVar6;

  *(int *)(param_1 + 0xe8) = iVar6 - iVar5;

  puVar7 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x108);

  if ((puVar7 != (uint32_t /* width from decompiler */ *)0x0) && (*(int *)(param_1 + 0x10c) - (int)puVar7 >> 2 != 0)) {

    puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x10c);

    for (; puVar7 != puVar3; puVar7 = puVar7 + 1) {

      (**(code **)(*(int *)*puVar7 + 8))(param_1);

    }

  }

  if ((*(char *)(param_1 + 0xf2) != '\0') || (g_flZero < *(float *)(param_1 + 0xf4))) {

    FUN_00753710();

  }

  if (*(char *)(iVar4 + 200) == '\0') {

    iVar5 = FUN_0076c3c0();

    piVar1 = (int *)(iVar4 + 0x34 + *(int *)(iVar4 + 0xc4) * 4);

    *piVar1 = *piVar1 + (iVar5 - *(int *)(iVar4 + 0x30));

    *(int *)(iVar4 + 0x30) = iVar5;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc4) = uVar2;

  }

  ExceptionList = pvStack_c;

  return;

}
