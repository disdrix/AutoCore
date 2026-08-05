// =============================================================================
// Named_dcCreature_Insert_Open
// -----------------------------------------------------------------------------
// Stable ID: aa_007e7530
// Address:   0x007e7530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_dcCreature_Insert_Open @ 0x007e7530
// Stable ID: aa_007e7530
// Embedded strings (evidence for future rename):
//   - "DBReader: %u against %s"
//   - "dcCreature_Insert::Open"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_00422fb0×17, FUN_00423170×2, FUN_0041a4b0, FUN_0041b670, FUN_004230d0, FUN_007a4480, FUN_007e1fb0, Named_dcCreature_Insert_Open.
//  - Strings: "DBReader: %u against %s"; "dcCreature_Insert::Open".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "dcCreature_Insert::Open"
 * Domain alias of FUN_007e7530 (FUN_* retained)
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

Named_dcCreature_Insert_Open(char *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ *param_5)



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

  puStack_8 = &DAT_009b0bbd;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    return -0x7fffbffc;

  }

  if (DAT_00d1793c == '\0') {

    ExceptionList = &local_c;

    iVar2 = FUN_007e1fb0(param_2,param_3,param_5);

    if (-1 < iVar2) {

      param_5 = (uint32_t /* width from decompiler */ *)*puVar1;

      local_24 = 0;

      local_20 = 0;

      local_1c = 0;

      local_18 = 0;

      local_14 = 0;

      local_10 = 0;

      local_4 = 0;

      FUN_004230d0(&local_24,&param_5);

      iVar2 = FUN_00422fb0(1,1,4);

      if (((((((iVar2 < 0) || (iVar2 = FUN_00422fb0(1,2,4), iVar2 < 0)) ||

             (iVar2 = FUN_00422fb0(1,3,4), iVar2 < 0)) ||

            ((iVar2 = FUN_00422fb0(1,4,4), iVar2 < 0 || (iVar2 = FUN_00422fb0(1,5,4), iVar2 < 0))))

           || ((iVar2 = FUN_00422fb0(1,6,4), iVar2 < 0 ||

               ((iVar2 = FUN_00422fb0(1,7,4), iVar2 < 0 || (iVar2 = FUN_00422fb0(1,8,2), iVar2 < 0))

               )))) || (iVar2 = FUN_00422fb0(1,9,2), iVar2 < 0)) ||

         (((((iVar2 = FUN_00422fb0(1,10,4), iVar2 < 0 || (iVar2 = FUN_00422fb0(1,0xb,2), iVar2 < 0))

            || (iVar2 = FUN_00422fb0(1,0xc,4), iVar2 < 0)) ||

           (((iVar2 = FUN_00422fb0(1,0xd,2), iVar2 < 0 || (iVar2 = FUN_00422fb0(1,0xe,4), iVar2 < 0)

             ) || ((iVar2 = FUN_00422fb0(1,0xf,4), iVar2 < 0 ||

                   ((iVar2 = FUN_00422fb0(1,0x10,4), iVar2 < 0 ||

                    (iVar2 = FUN_00422fb0(1,0x11,2), iVar2 < 0)))))))) ||

          (iVar2 = FUN_0041b670(&local_24,param_1 + 0x28,0,0,&DAT_00a140c8,0,0), iVar2 < 0)))) {

        FUN_00423170();

        FUN_007a4480(1,"DBReader: %u against %s",iVar2,"dcCreature_Insert::Open");

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
