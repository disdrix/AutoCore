// =============================================================================
// FUN_007e7df0
// -----------------------------------------------------------------------------
// Stable ID: aa_007e7df0
// Address:   0x007e7df0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007e7df0 @ 0x007e7df0
// Stable ID: aa_007e7df0
// Embedded strings (evidence for future rename):
//   - "DBReader: %u against %s"
//   - "dcCommodity_Insert::Open"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_00422fb0×5, CONCAT31×2, FUN_00423170×2, FUN_0041a4b0, FUN_0041b670, FUN_004230d0, FUN_007a4480, FUN_007e1fb0.
//  - Strings: "DBReader: %u against %s"; "dcCommodity_Insert::Open".
//  - Return sites: 4.

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

int __thiscall

FUN_007e7df0(char *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4,uint32_t /* width from decompiler */ *param_5)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puVar1 = param_5;

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009b0bf9;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    return -0x7fffbffc;

  }

  if (DAT_00d1793c == '\0') {

    ExceptionList = &local_c;

    iVar2 = FUN_007e1fb0(param_2,param_3,param_5);

    if (-1 < iVar2) {

      param_2 = *puVar1;

      param_5 = (uint32_t /* width from decompiler */ *)CONCAT31(param_5._1_3_,*(uint8_t *)(param_4 + 8));

      param_3 = CONCAT31(param_3._1_3_,*(uint8_t *)(param_4 + 9));

      local_24 = 0;

      local_20 = 0;

      local_1c = 0;

      local_18 = 0;

      local_14 = 0;

      local_10 = 0;

      local_4 = 0;

      FUN_004230d0(&local_24,&param_2);

      iVar2 = FUN_00422fb0(1,1,4);

      if ((((iVar2 < 0) || (iVar2 = FUN_00422fb0(1,2,1), iVar2 < 0)) ||

          (iVar2 = FUN_00422fb0(1,3,1), iVar2 < 0)) ||

         (((iVar2 = FUN_00422fb0(1,4,4), iVar2 < 0 || (iVar2 = FUN_00422fb0(1,5,4), iVar2 < 0)) ||

          (iVar2 = FUN_0041b670(&local_24,param_1 + 0x28,0,0,&DAT_00a140c8,0,0), iVar2 < 0)))) {

        FUN_00423170();

        FUN_007a4480(1,"DBReader: %u against %s",iVar2,"dcCommodity_Insert::Open");

      }

      else {

        FUN_00423170();

      }

      local_4 = 0xffffffff;

      FUN_0041a4b0(&local_24);

      ExceptionList = local_c;

      return 0;

    }

    ExceptionList = local_c;

    return iVar2;

  }

  return 0;

}
