// =============================================================================
// FUN_007e82f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007e82f0
// Address:   0x007e82f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007e82f0 @ 0x007e82f0
// Stable ID: aa_007e82f0
// Embedded strings (evidence for future rename):
//   - "DBReader: %u against %s"
//   - "dcWeapon_Insert::Open"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~141 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_00422fb0×25, CONCAT22×8, CONCAT31×6, FUN_007bfa70×4, FUN_00423170×2, FUN_0041a4b0, FUN_0041b670, FUN_004230d0.
//  - Strings: "DBReader: %u against %s"; "dcWeapon_Insert::Open".
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

int __thiscall

FUN_007e82f0(char *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4,

            uint32_t /* width from decompiler */ *param_5)



{

  byte bVar1;

  int iVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ extraout_ECX;

  uint uVar4;

  uint16_t uVar5;

  uint32_t /* width from decompiler */ local_84;

  uint32_t /* width from decompiler */ local_80;

  uint32_t /* width from decompiler */ local_7c;

  uint32_t /* width from decompiler */ local_78;

  uint32_t /* width from decompiler */ local_74;

  uint32_t /* width from decompiler */ local_70;

  uint32_t /* width from decompiler */ local_6c;

  uint32_t /* width from decompiler */ local_68;

  uint32_t /* width from decompiler */ local_64;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009b0c24;

  local_c = ExceptionList;

  if (*param_1 == '\0') {

    iVar2 = -0x7fffbffc;

  }

  else if (DAT_00d1793c == '\0') {

    ExceptionList = &local_c;

    iVar2 = FUN_007e1fb0(param_2,param_3,param_5);

    if (-1 < iVar2) {

      local_84 = *param_5;

      local_70 = param_4[0x15];

      bVar1 = *(byte *)((int)param_4 + 0x76);

      uVar3 = CONCAT31((int3)((uint)extraout_ECX >> 8),bVar1 >> 1) & 0xffffff01;

      uVar5 = (uint16_t)((uint)local_84 >> 0x10);

      local_4c = CONCAT22(uVar5,(ushort)(byte)uVar3);

      uVar3 = CONCAT31((int3)(uVar3 >> 8),bVar1 >> 2) & 0xffffff01;

      local_6c = param_4[0xf];

      local_68 = param_4[0x10];

      local_64 = param_4[0x11];

      local_48 = CONCAT22(uVar5,(ushort)(byte)uVar3);

      uVar3 = CONCAT31((int3)(uVar3 >> 8),bVar1 >> 4) & 0xffffff01;

      local_60 = param_4[0x12];

      local_5c = param_4[0x13];

      local_44 = CONCAT22(uVar5,(ushort)(byte)uVar3);

      uVar3 = CONCAT31((int3)(uVar3 >> 8),bVar1 >> 5) & 0xffffff01;

      local_58 = *param_4;

      local_54 = param_4[1];

      local_50 = param_4[2];

      local_40 = CONCAT22(uVar5,(ushort)(byte)uVar3);

      uVar4 = CONCAT31((int3)(uVar3 >> 8),bVar1) & 0xffffff01;

      uVar3 = CONCAT31((int3)((uint)local_70 >> 8),bVar1 >> 6) & 0xffffff01;

      local_38 = CONCAT22((short)(uVar3 >> 0x10),(ushort)(byte)uVar3);

      local_3c = CONCAT22(uVar5,(ushort)(byte)uVar4);

      local_34 = CONCAT22((short)(uVar4 >> 0x10),*(uint16_t *)((int)param_4 + 0x72));

      local_2c = param_4[0x14];

      local_7c = param_4[0x17];

      local_30 = param_4[0x1b];

      local_80 = param_4[0x16];

      local_78 = param_4[0x18];

      local_28 = CONCAT22((short)((uint)local_78 >> 0x10),*(uint16_t *)(param_4 + 0x1e));

      local_74 = param_4[0x19];

      iVar2 = FUN_007bfa70(param_4 + 3,&local_80);

      if ((((-1 < iVar2) && (iVar2 = FUN_007bfa70(param_4 + 6,&local_7c), -1 < iVar2)) &&

          (iVar2 = FUN_007bfa70(param_4 + 9,&local_78), -1 < iVar2)) &&

         (iVar2 = FUN_007bfa70(param_4 + 0xc,&local_74), -1 < iVar2)) {

        local_24 = 0;

        local_20 = 0;

        local_1c = 0;

        local_18 = 0;

        local_14 = 0;

        local_10 = 0;

        local_4 = 0;

        FUN_004230d0(&local_24,&local_84);

        iVar2 = FUN_00422fb0(1,1,4);

        if ((((((iVar2 < 0) || (iVar2 = FUN_00422fb0(1,2,4), iVar2 < 0)) ||

              ((iVar2 = FUN_00422fb0(1,3,4), iVar2 < 0 ||

               ((iVar2 = FUN_00422fb0(1,4,4), iVar2 < 0 || (iVar2 = FUN_00422fb0(1,5,4), iVar2 < 0))

               )))) || ((iVar2 = FUN_00422fb0(1,6,4), iVar2 < 0 ||

                        (((((iVar2 = FUN_00422fb0(1,7,4), iVar2 < 0 ||

                            (iVar2 = FUN_00422fb0(1,8,4), iVar2 < 0)) ||

                           (iVar2 = FUN_00422fb0(1,9,4), iVar2 < 0)) ||

                          ((iVar2 = FUN_00422fb0(1,10,4), iVar2 < 0 ||

                           (iVar2 = FUN_00422fb0(1,0xb,2), iVar2 < 0)))) ||

                         (((iVar2 = FUN_00422fb0(1,0xc,2), iVar2 < 0 ||

                           ((iVar2 = FUN_00422fb0(1,0xd,2), iVar2 < 0 ||

                            (iVar2 = FUN_00422fb0(1,0xe,2), iVar2 < 0)))) ||

                          (iVar2 = FUN_00422fb0(1,0xf,2), iVar2 < 0)))))))) ||

            ((((iVar2 = FUN_00422fb0(1,0x10,2), iVar2 < 0 ||

               (iVar2 = FUN_00422fb0(1,0x11,4), iVar2 < 0)) ||

              (iVar2 = FUN_00422fb0(1,0x12,4), iVar2 < 0)) ||

             (((iVar2 = FUN_00422fb0(1,0x13,4), iVar2 < 0 ||

               (iVar2 = FUN_00422fb0(1,0x14,4), iVar2 < 0)) ||

              ((iVar2 = FUN_00422fb0(1,0x15,1), iVar2 < 0 ||

               ((iVar2 = FUN_00422fb0(1,0x16,2), iVar2 < 0 ||

                (iVar2 = FUN_00422fb0(1,0x17,4), iVar2 < 0)))))))))) ||

           ((iVar2 = FUN_00422fb0(1,0x18,4), iVar2 < 0 ||

            ((iVar2 = FUN_00422fb0(1,0x19,2), iVar2 < 0 ||

             (iVar2 = FUN_0041b670(&local_24,param_1 + 0x28,0,0,&DAT_00a140c8,0,0), iVar2 < 0))))))

        {

          FUN_00423170();

          FUN_007a4480(1,"DBReader: %u against %s",iVar2,"dcWeapon_Insert::Open");

        }

        else {

          FUN_00423170();

        }

        local_4 = 0xffffffff;

        FUN_0041a4b0(&local_24);

        iVar2 = 0;

      }

    }

  }

  else {

    iVar2 = 0;

  }

  ExceptionList = local_c;

  return iVar2;

}
