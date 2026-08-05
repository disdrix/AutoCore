// =============================================================================
// FUN_004d18a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d18a0
// Address:   0x004d18a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d18a0 @ 0x004d18a0
// Stable ID: aa_004d18a0
// Embedded strings (evidence for future rename):
//   - "CVOGSectorMap::PostPhysX"
//   - "Delayed operations"
//   - "Fluids"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0076cef0×3, FUN_0076cf00×3, FUN_0049b940, FUN_004b50f0, FUN_004cfd50, FUN_004d18a0, FUN_00590a80, FUN_00594290.
//  - Strings: "CVOGSectorMap::PostPhysX"; "Delayed operations"; "Fluids".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_004d18a0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a2020;

  local_c = ExceptionList;

  if (*(int *)(DAT_00b037f0 + 4) != 0) {

    ExceptionList = &local_c;

    FUN_0076cf00("CVOGSectorMap::PostPhysX");

    local_4 = 0;

    local_18 = 0;

    local_14 = 0;

    local_10 = 0;

    if (*(int *)(param_1 + 0xe890) != 0) {

      iVar1 = *(int *)(*(int *)(param_1 + 0xe890) + 8);

      if ((_DAT_00b03624 & 1) == 0) {

        _DAT_00b03624 = _DAT_00b03624 | 1;

      }

      _DAT_00b03620 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x98);

      _DAT_00b0361c = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x94);

      _DAT_00b03618 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x90);

      local_18 = _DAT_00b03618;

      local_14 = _DAT_00b0361c;

      local_10 = _DAT_00b03620;

    }

    FUN_004b50f0(&local_18);

    FUN_0076cf00("Delayed operations");

    local_4._0_1_ = 1;

    FUN_00590a80(param_1);

    FUN_00594290();

    local_4._0_1_ = 0;

    FUN_0076cef0();

    FUN_004cfd50();

    if (*(int *)(param_1 + 0xe890) != 0) {

      FUN_0076cf00("Fluids");

      local_4._0_1_ = 2;

      FUN_0049b940(*(uint32_t /* width from decompiler */ *)(param_1 + 0xe890),param_2);

      local_4 = (uint)local_4._1_3_ << 8;

      FUN_0076cef0();

    }

    local_4 = 0xffffffff;

    FUN_0076cef0();

  }

  ExceptionList = local_c;

  return;

}
