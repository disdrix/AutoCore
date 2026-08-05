// =============================================================================
// CVOGSectorMap_StepTo
// -----------------------------------------------------------------------------
// Stable ID: aa_004d6c80
// Address:   0x004d6c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias CVOGSectorMap_StepTo for FUN_004d6c80 @ 0x004d6c80
// Stable ID: aa_004d6c80
// Embedded strings (evidence for future rename):
//   - "CVOGSectorMap::StepTo"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_0076cef0×3, FUN_0076cf00×3, FUN_004d4da0×2, FUN_004d3420, FUN_004d3980, CVOGSectorMap_StepTo, FUN_00561910, FUN_00561b60.
//  - Strings: "CVOGSectorMap::StepTo".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CVOGSectorMap::StepTo"
 * Domain alias of FUN_004d6c80 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall CVOGSectorMap_StepTo(int param_1,float param_2)



{

  float fVar1;

  int iVar2;

  double dVar3;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a213a;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("CVOGSectorMap::StepTo");

  local_4 = 0;

  FUN_004d3420(param_2);

  if (*(char *)(param_1 + 0x7d) == '\0') {

    if (g_flMultiKillCountBlend < param_2) {

      param_2 = g_flMultiKillCountBlend;

    }

    dVar3 = floor((double)(param_2 * _DAT_009cc798));

    fVar1 = (float)dVar3 + g_flOne;

    iVar2 = (int)ROUND(fVar1);

    if (0 < iVar2) {

      do {

        *(float *)(param_1 + 0x70) = param_2 / fVar1 + *(float *)(param_1 + 0x70);

        FUN_0076cf00();

        local_4._0_1_ = 1;

        FUN_00561910();

        local_4._0_1_ = 0;

        FUN_0076cef0();

        FUN_0076cf00();

        local_4._0_1_ = 2;

        FUN_00561b60();

        local_4 = (uint)local_4._1_3_ << 8;

        FUN_0076cef0();

        FUN_004d4da0();

        iVar2 = iVar2 + -1;

      } while (iVar2 != 0);

    }

    FUN_004d3980();

  }

  else {

    FUN_004d4da0(param_2);

    FUN_00562bf0(param_2);

    *(float *)(param_1 + 0x70) = param_2 + *(float *)(param_1 + 0x70);

  }

  if (*(int *)(param_1 + 0xe4a8) != 0) {

    FUN_005d86f0(0);

    FUN_005d83f0();

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return;

}
