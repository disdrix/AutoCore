// =============================================================================
// FUN_0059f150
// -----------------------------------------------------------------------------
// Stable ID: aa_0059f150
// Address:   0x0059f150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0059f150 @ 0x0059f150
// Stable ID: aa_0059f150
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_0059f150, FUN_00780820.
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

uint32_t /* width from decompiler */ *

FUN_0059f150(uint32_t /* width from decompiler */ param_1,uint16_t param_2,uint16_t param_3,uint16_t param_4,

            int *param_5)



{

  int *piVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  int local_4;

  

  puStack_8 = &LAB_009a5e88;

  pvStack_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  puVar3 = operator_new(0x30);

  local_4._0_1_ = 1;

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    FUN_00780820(1,1);

    *puVar3 = &PTR_LAB_009d7cec;

    puVar3[6] = &PTR_FUN_009d7c0c;

    puVar3[7] = &LAB_005a2110;

    puVar3[0xb] = 0;

    puVar3[5] = puVar3 + 6;

  }

  puVar3[8] = param_1;

  *(uint16_t *)(puVar3 + 9) = param_2;

  *(uint16_t *)((int)puVar3 + 0x26) = param_3;

  *(uint16_t *)(puVar3 + 10) = param_4;

  piVar2 = (int *)puVar3[0xb];

  local_4 = (uint)local_4._1_3_ << 8;

  if (piVar2 != (int *)0x0) {

    piVar1 = piVar2 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*piVar2 + 8))();

    }

  }

  puVar3[0xb] = param_5;

  if (param_5 != (int *)0x0) {

    param_5[2] = param_5[2] + 1;

  }

  local_4 = 0xffffffff;

  if (param_5 != (int *)0x0) {

    piVar2 = param_5 + 2;

    *piVar2 = *piVar2 + -1;

    if (*piVar2 == 0) {

      (**(code **)(*param_5 + 8))();

    }

  }

  ExceptionList = pvStack_c;

  return puVar3;

}
