// READABILITY (auto CF):
//  - Body size: ~116 non-empty decompiler lines.
//  - Control keywords: if×14, return×3.
//  - Notable callees: FUN_00769e40×6, FUN_0043d4a0×3, FUN_00691630×2, stoChunkReader_EnterChunkScope×2, CONCAT11, D3DXCreateEffect, FUN_00437050, FUN_00445b80.
//  - Return sites: 3.

// =============================================================================
// Named_effDeviceEffect_00751ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_00751ac0
// Address:   0x00751ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effDeviceEffect"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



uint32_t /* width from decompiler */ Named_effDeviceEffect_00751ac0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  char cVar1;

  int iVar2;

  uint8_t local_40d9;

  int *local_40d8;

  int local_40d4 [3];

  char local_40c8;

  char local_40b4;

  int local_40b0;

  int local_40ac;

  undefined **local_40a8;

  uint local_40a4;

  uint32_t /* width from decompiler */ local_409c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_4090 [28];

  uint8_t local_4074 [16452];

  int local_30;

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b30b9;

  local_c = ExceptionList;

  uStack_10 = 0x751adf;

  ExceptionList = &local_c;

  FUN_0076a150(param_3);

  local_4 = 0;

  stoChunkReader_EnterChunkScope(local_4074);

  local_4._0_1_ = 1;

  cVar1 = FUN_00751a10(local_4074,param_4);

  if (cVar1 != '\0') {

    local_40a4 = (uint)CONCAT11(1,-(*(char *)(DAT_00d1f044 + 0x1de) != '\x01') & 5);

    stoChunkReader_EnterChunkScope(local_4074);

    local_4._0_1_ = 2;

    if ((local_40b0 == 0x42494658) && (local_40ac == 1)) {

      if (local_30 == 0) {

        FUN_00437050(local_40d4);

      }

      else {

        FUN_007689e0(local_40d4);

      }

      if (local_40d4[0] != 0) {

        local_40d9 = 0;

        FUN_00445b80(&local_40d9);

        local_4._0_1_ = 3;

        iVar2 = FUN_00447c10(local_409c,local_40d4[0]);

        if (-1 < iVar2) {

          local_40d8 = (int *)0x0;

          local_40a8 = &PTR_LAB_00a9fa84;

          iVar2 = D3DXCreateEffect(*DAT_00d1f044,local_409c,local_40d4[0],

                                   *(uint32_t /* width from decompiler */ *)(param_4 + 4),&local_40a8,local_40a4,

                                   *(uint32_t /* width from decompiler */ *)(DAT_00d1f05c + 0x140),param_1 + 0xc,&local_40d8);

          if ((local_40d8 == (int *)0x0) && (-1 < iVar2)) {

            FUN_00691630();

            local_4._0_1_ = 1;

            if (local_40b4 != '\0') {

              FUN_00769e40();

            }

            local_4 = (uint)local_4._1_3_ << 8;

            if (local_40c8 != '\0') {

              FUN_00769e40();

            }

            local_4 = 0xffffffff;

            FUN_0043d4a0();

            ExceptionList = local_c;

            return 0;

          }

          iVar2 = FUN_0096a630(local_4090);

          local_4._0_1_ = 4;

          if (*(uint *)(iVar2 + 0x18) < 0x10) {

            iVar2 = iVar2 + 4;

          }

          else {

            iVar2 = *(int *)(iVar2 + 4);

          }

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effDeviceEffect.cpp"

                         ,0x3f9,2,iVar2);

          local_4._0_1_ = 3;

          std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

          ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_4090);

          if (local_40d8 != (int *)0x0) {

            (**(code **)(*local_40d8 + 8))(local_40d8);

          }

          local_40d8 = (int *)0x0;

        }

        FUN_00691630();

      }

      local_4._0_1_ = 1;

      if (local_40b4 != '\0') {

        FUN_00769e40();

      }

      local_4 = (uint)local_4._1_3_ << 8;

      if (local_40c8 != '\0') {

        FUN_00769e40();

      }

      local_4 = 0xffffffff;

      FUN_0043d4a0();

      ExceptionList = local_c;

      return 0xffffffff;

    }

    local_4._0_1_ = 1;

    if (local_40b4 != '\0') {

      FUN_00769e40();

    }

  }

  local_4 = (uint)local_4._1_3_ << 8;

  if (local_40c8 != '\0') {

    FUN_00769e40();

  }

  local_4 = 0xffffffff;

  FUN_0043d4a0();

  ExceptionList = local_c;

  return 0xffffffff;

}
