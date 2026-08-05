// =============================================================================
// Named_CalleeOf_CVOGCharacter_LevelUp_00531330
// -----------------------------------------------------------------------------
// Stable ID: aa_00531330
// Callee of CVOGCharacter_LevelUp (+1 other named callers)
// Address:   0x00531330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGCharacter_LevelUp: progression/economy helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. CVOGCharacter_LevelUp (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: Client_SendLogicUiPacket×4, FUN_004a1620, FUN_004a16d0, FUN_004a6390, FUN_004b7550, FUN_004b7e50, FUN_00531330.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of CVOGCharacter_LevelUp (+1 other named callers)
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

void __thiscall Named_CalleeOf_CVOGCharacter_LevelUp_00531330(int param_1,char param_2)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int *piVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a3c69;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (param_2 == '\x01') {

    ExceptionList = &pvStack_c;

    if (*(int *)(param_1 + 0xcb8) == 0) {

      ExceptionList = &pvStack_c;

      pvVar1 = operator_new(8);

      local_4 = 0;

      if (pvVar1 == (void *)0x0) {

        uVar2 = 0;

      }

      else {

        uVar2 = FUN_004a1620();

      }

      local_4 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xcb8) = uVar2;

      FUN_004a6390();

    }

    iVar3 = FUN_004a16d0();

    if (iVar3 != 0) {

      FUN_004b7550();

      iVar3 = *(int *)(param_1 + 0x250);

      if (iVar3 == 0) {

        piVar4 = (int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1);

      }

      else {

        piVar4 = (int *)(*(int *)(*(int *)(iVar3 + 4) + 4) + 4 + iVar3);

      }

      (**(code **)(*piVar4 + 0xf8))();

      FUN_004b7e50(0,0,0);

    }

    Client_SendLogicUiPacket();

  }

  if (*(short *)(param_1 + 0x6cc) != 0) {

    Client_SendLogicUiPacket();

  }

  if (*(short *)(param_1 + 0x6ce) != 0) {

    Client_SendLogicUiPacket();

  }

  if (*(short *)(param_1 + 0x580) != 0) {

    Client_SendLogicUiPacket();

  }

  ExceptionList = pvStack_c;

  return;

}
