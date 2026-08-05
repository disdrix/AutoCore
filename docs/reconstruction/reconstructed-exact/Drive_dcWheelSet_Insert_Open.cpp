// =============================================================================
// Drive_dcWheelSet_Insert_Open
// -----------------------------------------------------------------------------
// Stable ID: aa_007e7fd0
// Address:   0x007e7fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Drive_dcWheelSet_Insert_Open @ 0x007e7fd0
// Stable ID: aa_007e7fd0
// Embedded strings (evidence for future rename):
//   - "DBReader: %u against %s"
//   - "dcWheelSet_Insert::Open"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00422fb0×12, CONCAT22×6, FUN_00423170×2, wcscpy×2, FUN_0041a4b0, FUN_0041b670, FUN_004230d0, FUN_007a4480.
//  - Strings: "DBReader: %u against %s"; "dcWheelSet_Insert::Open".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "dcWheelSet_Insert::Open"
 * Domain alias of FUN_007e7fd0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall

Drive_dcWheelSet_Insert_Open(char *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint16_t *param_4,

            uint32_t /* width from decompiler */ *param_5)



{

  int iVar1;

  wchar_t *pwVar2;

  uint16_t uVar3;

  uint16_t extraout_var;

  uint16_t extraout_var_00;

  uint32_t /* width from decompiler */ local_148;

  uint32_t /* width from decompiler */ local_144;

  uint32_t /* width from decompiler */ local_140;

  uint32_t /* width from decompiler */ local_13c;

  uint32_t /* width from decompiler */ local_138;

  uint32_t /* width from decompiler */ local_134;

  uint32_t /* width from decompiler */ local_130;

  uint32_t /* width from decompiler */ local_12c;

  uint32_t /* width from decompiler */ local_128;

  uint32_t /* width from decompiler */ local_124;

  uint32_t /* width from decompiler */ local_120;

  uint32_t /* width from decompiler */ local_11c;

  uint32_t /* width from decompiler */ local_118;

  wchar_t local_114 [66];

  wchar_t local_90 [66];

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009b0c10;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    iVar1 = -0x7fffbffc;

  }

  else if (DAT_00d1793c == '\0') {

    ExceptionList = &local_c;

    iVar1 = FUN_007e1fb0(param_2,param_3,param_5);

    if (-1 < iVar1) {

      local_130 = *param_5;

      wcscpy(local_114,param_4 + 8);

      pwVar2 = wcscpy(local_90,param_4 + 0x49);

      local_124 = CONCAT22(extraout_var,*param_4);

      local_120 = CONCAT22(extraout_var_00,param_4[1]);

      uVar3 = (uint16_t)((uint)pwVar2 >> 0x10);

      local_12c = CONCAT22(uVar3,param_4[2]);

      local_148 = 0;

      local_118 = CONCAT22(extraout_var,param_4[3]);

      local_11c = CONCAT22(extraout_var_00,param_4[4]);

      local_128 = CONCAT22(uVar3,param_4[5]);

      local_144 = 0;

      local_140 = 0;

      local_13c = 0;

      local_138 = 0;

      local_134 = 0;

      local_4 = 0;

      FUN_004230d0(&local_148,&local_130);

      iVar1 = FUN_00422fb0(1,1,4);

      if (((((iVar1 < 0) || (iVar1 = FUN_00422fb0(1,2,0x82), iVar1 < 0)) ||

           (iVar1 = FUN_00422fb0(1,3,0x82), iVar1 < 0)) ||

          (((iVar1 = FUN_00422fb0(1,4,1), iVar1 < 0 || (iVar1 = FUN_00422fb0(1,5,1), iVar1 < 0)) ||

           ((iVar1 = FUN_00422fb0(1,6,1), iVar1 < 0 ||

            ((iVar1 = FUN_00422fb0(1,7,2), iVar1 < 0 || (iVar1 = FUN_00422fb0(1,8,2), iVar1 < 0)))))

           ))) || ((iVar1 = FUN_00422fb0(1,9,2), iVar1 < 0 ||

                   ((((iVar1 = FUN_00422fb0(1,10,2), iVar1 < 0 ||

                      (iVar1 = FUN_00422fb0(1,0xb,2), iVar1 < 0)) ||

                     (iVar1 = FUN_00422fb0(1,0xc,2), iVar1 < 0)) ||

                    (iVar1 = FUN_0041b670(&local_148,param_1 + 0x28,0,0,&DAT_00a140c8,0,0),

                    iVar1 < 0)))))) {

        FUN_00423170();

        FUN_007a4480(1,"DBReader: %u against %s",iVar1,"dcWheelSet_Insert::Open");

      }

      else {

        FUN_00423170();

      }

      local_4 = 0xffffffff;

      FUN_0041a4b0(&local_148);

      iVar1 = 0;

    }

  }

  else {

    iVar1 = 0;

  }

  ExceptionList = local_c;

  return iVar1;

}
