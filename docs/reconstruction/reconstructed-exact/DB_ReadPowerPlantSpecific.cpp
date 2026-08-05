// =============================================================================
// DB_ReadPowerPlantSpecific
// -----------------------------------------------------------------------------
// Stable ID: aa_007f4c50
// Address:   0x007f4c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* WARNING: Removing unreachable block (ram,0x007f50b7) */

/* WARNING: Removing unreachable block (ram,0x007f503e) */

/* WARNING: Removing unreachable block (ram,0x007f4fd0) */

/* WARNING: Removing unreachable block (ram,0x007f4fae) */

/* WARNING: Removing unreachable block (ram,0x007f4ffc) */

/* WARNING: Removing unreachable block (ram,0x007f5002) */

/* WARNING: Removing unreachable block (ram,0x007f5044) */

/* WARNING: Removing unreachable block (ram,0x007f507a) */

/* WARNING: Removing unreachable block (ram,0x007f5080) */

/* WARNING: Removing unreachable block (ram,0x007f50bd) */

/* WARNING: Removing unreachable block (ram,0x007f50d9) */

/* DB_ReadPowerPlantSpecific - load tPowerPlant row into SPowerPlant_Specific.

   

   SELECT intHeatMaximum, intPowerMaximum, sinPowerRegenRate, sinCoolRate

   FROM tPowerPlant WHERE IDCloneBase=?

   

   Out struct 0xC: +0 HeatMax, +4 PowerMax, +8 PowerRegenRate short, +A CoolRate short.

   Copied onto clonebase plant fields used at +0xB0..+0xBA. */



int __thiscall

DB_ReadPowerPlantSpecific(void *this,char *pDbContext,SPowerPlant_Specific *pOutSpecific)



{

  int iVar1;

  int *unaff_EBX;

  uint16_t unaff_retaddr;

  int iStack_78;

  BSTR pOStack_74;

  uint32_t /* width from decompiler */ local_70;

  uint32_t /* width from decompiler */ uStack_6c;

  wchar_t awStack_68 [20];

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ *puStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  int iStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ *puStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  void *pvStack_14;

  void *local_c;

  uint8_t *puStack_8;

  uint8_t *puStack_4;

  

  puStack_4 = (uint8_t *)0xffffffff;

  puStack_8 = &LAB_009b0f70;

  local_c = ExceptionList;

  local_70 = *(uint32_t /* width from decompiler */ *)pDbContext;

  if (*(char *)this == '\0') {

    return -0x7fffbffc;

  }

  ExceptionList = &local_c;

  iVar1 = FUN_007e59d0();

  if (-1 < iVar1) {

    if (DAT_00d1793c == '\0') {

      puStack_28 = &uStack_40;

      uStack_40 = 0;

      uStack_3c = 0;

      puStack_38 = (uint32_t /* width from decompiler */ *)0x0;

      uStack_34 = 0;

      iStack_30 = 0;

      uStack_2c = 0;

      uStack_20 = 0;

      uStack_24 = 0;

      uStack_1c = 0;

      uStack_18 = 0;

      local_c = (void *)0x0;

      FUN_004230d0();

      iVar1 = FUN_00422fb0(1);

      if (-1 < iVar1) {

        iVar1 = FUN_0041a810(&uStack_40,(int)this + 0x28,0,0,&DAT_00a140c8);

      }

      puStack_38 = &local_70;

      if ((((iVar1 < 0) || (iVar1 = FUN_004231d0(&uStack_40), iVar1 < 0)) ||

          (iVar1 = FUN_004231d0(&uStack_40), iVar1 < 0)) ||

         (((iVar1 = FUN_004231d0(&uStack_40), iVar1 < 0 ||

           (iVar1 = FUN_004231d0(&uStack_40), iVar1 < 0)) || (iStack_30 == 0)))) {

        FUN_00423170();

        FUN_007a4480(1,"DBReader: %u against %s");

        local_c = (void *)0xffffffff;

        FUN_0041a3e0();

      }

      else {

        iVar1 = FUN_0041a9b0();

        if (iVar1 == 0) {

          *(uint32_t /* width from decompiler */ *)pDbContext = local_70;

          *(uint32_t /* width from decompiler */ *)(pDbContext + 4) = uStack_6c;

          *(uint16_t *)(pDbContext + 8) = puStack_4._0_2_;

          *(uint16_t *)(pDbContext + 10) = unaff_retaddr;

          FUN_0041a990();

          FUN_00423170();

          local_c = (void *)0xffffffff;

          FUN_0041a3e0();

        }

        else {

          FUN_0041a990();

          FUN_00423170();

          FUN_007a4480(1,"DBReader: %u against %s");

          local_c = (void *)0xffffffff;

          FUN_0041a3e0();

        }

      }

    }

    else {

      FUN_00423670();

      local_c = (void *)0x1;

      _itow(iStack_78,awStack_68,10);

      FUN_00422eb0();

      lstrlenW(L"\']");

      iVar1 = FUN_00422ee0();

      if (iVar1 < 0) {

                    /* WARNING: Subroutine does not return */

        FUN_004048e0();

      }

      puStack_4 = &stack0xffffff6c;

      FUN_00419ca0();

      local_c._0_1_ = 2;

      if (DAT_00d1e56c == 0) {

        _com_issue_error(-0x7fffbffd);

      }

      local_c._0_1_ = 1;

      FUN_00419ed0();

      local_c = (void *)CONCAT31(local_c._1_3_,4);

      if (unaff_EBX == (int *)0x0) {

        _com_issue_error(-0x7fffbffd);

      }

      iVar1 = FUN_00419ff0();

      if (0 < iVar1) {

        if (unaff_EBX == (int *)0x0) {

          _com_issue_error(-0x7fffbffd);

        }

        (**(code **)(*unaff_EBX + 0x1c))(unaff_EBX);

      }

      local_c = (void *)CONCAT31(local_c._1_3_,1);

      if (unaff_EBX != (int *)0x0) {

        (**(code **)(*unaff_EBX + 8))();

      }

      SysFreeString(pOStack_74);

    }

    iVar1 = 0;

  }

  ExceptionList = pvStack_14;

  return iVar1;

}
