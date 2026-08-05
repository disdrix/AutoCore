// =============================================================================
// Gfx_Bmp_ReadInfoError
// -----------------------------------------------------------------------------
// Stable ID: aa_00433dc0
// Address:   0x00433dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias Gfx_Bmp_ReadInfoError for FUN_00433dc0 @ 0x00433dc0
// Stable ID: aa_00433dc0
// Embedded strings (evidence for future rename):
//   - "Not a BMP"
//   - "Error reading BMP info"
//   - "output dimensions returned"
//   - "Can\'t allocate memory"
//   - "Cancelled"
//   - "compression type not supported"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~368 non-empty decompiler lines.
//  - Control keywords: if×44, return×12, while×4, for×3, switch×1, goto×1.
//  - Notable callees: _CxxThrowException×10, FUN_00433d70×4, FUN_00432630×2, FUN_00433d30×2, ROUND×2, floor×2, CONCAT22, FUN_004323e0.
//  - Strings: "Not a BMP"; "Error reading BMP info"; "output dimensions returned"; "Can\'t allocate memory".
//  - Return sites: 12.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Error reading BMP info"
 * Domain alias of FUN_00433dc0 (FUN_* retained)
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



uint32_t /* width from decompiler */ __thiscall Gfx_Bmp_ReadInfoError(int *param_1,int param_2)



{

  size_t _Size;

  void *_Memory;

  char cVar1;

  int iVar2;

  int iVar3;

  byte *pbVar4;

  uint8_t *puVar5;

  byte *pbVar6;

  uint uVar7;

  ushort in_FPUControlWord;

  double dVar8;

  int local_e0;

  uint32_t /* width from decompiler */ local_dc;

  int local_d8;

  ushort local_d2;

  uint16_t uStack_d0;

  uint16_t uStack_ce;

  int local_c8;

  int local_c4;

  int local_c0;

  char *local_b8;

  char *local_b4;

  char *local_b0;

  short local_ac [5];

  int local_a2;

  char *local_9c;

  uint local_98;

  char *local_94;

  char *local_90;

  uint local_8c;

  uint local_88;

  char *local_84;

  int local_80;

  int local_7c;

  uint local_78;

  uint local_74;

  char *local_70;

  int local_6c;

  char *local_68;

  char *local_64;

  uint32_t /* width from decompiler */ local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  void *local_54;

  int local_50;

  int local_4c;

  uint local_48;

  int local_44;

  int local_40;

  int local_3c;

  uint local_38;

  int local_30;

  int local_2c;

  byte local_26;

  byte local_25;

  uint local_24;

  byte local_20;

  char local_1f;

  char local_1e;

  byte local_1d;

  int local_1c;

  uint8_t local_18;

  byte local_17;

  byte local_16;

  byte local_15;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bd6f0;

  local_10 = ExceptionList;

  local_14 = &stack0xfffffed0;

  if (param_1 == (int *)0x0) {

    return 0;

  }

  ExceptionList = &local_10;

  iVar2 = (**(code **)(*param_1 + 0x14))();

  local_8 = 0;

  local_40 = iVar2;

  iVar3 = (**(code **)(*param_1 + 8))(local_ac,0xe,1);

  if (iVar3 == 0) {

    local_b8 = "Not a BMP";

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(&local_b8,(ThrowInfo *)&DAT_00acc49c);

  }

  if (local_ac[0] != 0x4d42) {

    local_a2 = 0;

    (**(code **)(*param_1 + 0x10))(iVar2);

  }

  cVar1 = FUN_00434690();

  if (cVar1 == '\0') {

    local_64 = "Error reading BMP info";

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(&local_64,(ThrowInfo *)&DAT_00acc49c);

  }

  local_3c = CONCAT22(uStack_ce,uStack_d0);

  local_8c = (uint)local_d2;

  local_1e = local_e0 == 0xc;

  local_1f = local_d8 < 0;

  if ((bool)local_1f) {

    local_d8 = -local_d8;

  }

  if (*(int *)(param_2 + 0x148) == -1) {

    *(uint32_t /* width from decompiler */ *)(param_2 + 0xc) = local_dc;

    *(int *)(param_2 + 0x10) = local_d8;

    local_84 = "output dimensions returned";

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(&local_84,(ThrowInfo *)&DAT_00acc49c);

  }

  iVar2 = FUN_004323e0(local_dc,local_8c,1);

  if (iVar2 == 0) {

    local_70 = "Can\'t allocate memory";

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(&local_70,(ThrowInfo *)&DAT_00acc49c);

  }

  *(int *)(param_2 + 0x20) = local_c8;

  *(int *)(param_2 + 0x24) = local_c4;

  dVar8 = floor((double)local_c8 * _DAT_00aaa970 + _DAT_00aaa5e0);

  local_88 = (uint)(in_FPUControlWord | 0xc00);

  *(int *)(param_2 + 0x164) = (int)ROUND(dVar8);

  dVar8 = floor((double)local_c4 * _DAT_00aaa970 + _DAT_00aaa5e0);

  local_78 = (uint)(in_FPUControlWord | 0xc00);

  *(int *)(param_2 + 0x168) = (int)ROUND(dVar8);

  if (*(int *)(param_2 + 0x148) != 0) {

    local_90 = "Cancelled";

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(&local_90,(ThrowInfo *)&DAT_00acc49c);

  }

  iVar2 = FUN_00433490();

  if (iVar2 != 0) {

    if (local_1e == '\0') {

      if ((local_c0 == 0) && (local_d2 < 9)) {

        local_c0 = 1 << ((byte)local_d2 & 0x1f);

      }

      (**(code **)(*param_1 + 8))(iVar2,local_c0 * 4);

      for (local_98 = 0; local_98 < *(uint *)(param_2 + 0x28); local_98 = local_98 + 1) {

        *(uint8_t *)(iVar2 + 3 + local_98 * 4) = 0;

      }

    }

    else {

      if ((local_c0 == 0) && (local_d2 < 9)) {

        local_c0 = 1 << ((byte)local_d2 & 0x1f);

      }

      (**(code **)(*param_1 + 8))(iVar2,local_c0 * 3);

      local_80 = *(int *)(param_2 + 0x28);

      if ((local_80 == 0) && (*(ushort *)(param_2 + 0x16) < 9)) {

        local_80 = 1 << ((byte)*(ushort *)(param_2 + 0x16) & 0x1f);

      }

      while (local_80 = local_80 + -1, -1 < local_80) {

        puVar5 = (uint8_t *)(iVar2 + local_80 * 2 + local_80);

        *(uint8_t *)(iVar2 + 2 + local_80 * 4) = puVar5[2];

        *(uint8_t *)(iVar2 + local_80 * 4) = *puVar5;

        *(uint8_t *)(iVar2 + 1 + local_80 * 4) = puVar5[1];

        *(uint8_t *)(iVar2 + 3 + local_80 * 4) = 0;

      }

    }

  }

  if (*(int *)(param_2 + 0x148) != 0) {

    local_b0 = "Cancelled";

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(&local_b0,(ThrowInfo *)&DAT_00acc49c);

  }

  switch(local_8c) {

  case 1:

  case 4:

  case 8:

    if (local_a2 != 0) {

      (**(code **)(*param_1 + 0x10))(local_a2 + local_40);

    }

    if (local_3c == 0) {

      (**(code **)(*param_1 + 8))(*(uint32_t /* width from decompiler */ *)(param_2 + 0x34),*(uint32_t /* width from decompiler */ *)(param_2 + 0x1c),1)

      ;

    }

    else if (local_3c == 1) {

      local_17 = 0;

      local_18 = 0;

      uVar7 = 0;

      local_30 = 0;

      local_38 = 0;

      FUN_00433d30();

      local_44 = 1;

      while (local_44 != 0) {

        (**(code **)(*param_1 + 8))(&local_17,1,1);

        if (local_17 == 0) {

          (**(code **)(*param_1 + 8))(&local_17,1,1);

          if (local_17 == 0) {

            uVar7 = 0;

            local_38 = 0;

            local_30 = local_30 + 1;

          }

          else if (local_17 == 1) {

LAB_004345bb:

            local_44 = 0;

          }

          else if (local_17 == 2) {

            (**(code **)(*param_1 + 8))(&local_20);

            (**(code **)(*param_1 + 8))(&local_1d,1,1);

            uVar7 = uVar7 + local_20;

            local_30 = local_30 + (uint)local_1d;

            local_38 = uVar7;

          }

          else {

            local_7c = *param_1;

            iVar2 = FUN_00433d70();

            (**(code **)(local_7c + 8))(iVar2 + uVar7);

            if ((local_17 & 1) != 0) {

              (**(code **)(*param_1 + 8))(&local_18);

            }

            uVar7 = uVar7 + local_17;

            local_38 = uVar7;

          }

        }

        else {

          iVar2 = FUN_00433d70();

          (**(code **)(*param_1 + 8))(&local_18,1,1);

          for (local_74 = 0; local_74 < local_17; local_74 = local_74 + 1) {

            if (*(uint *)(param_2 + 0x30) <= uVar7) goto LAB_004345bb;

            *(uint8_t *)(iVar2 + uVar7) = local_18;

            uVar7 = uVar7 + 1;

            local_38 = uVar7;

          }

        }

      }

    }

    else {

      if (local_3c != 2) {

        local_68 = "compression type not supported";

                    /* WARNING: Subroutine does not return */

        _CxxThrowException(&local_68,(ThrowInfo *)&DAT_00acc49c);

      }

      local_16 = 0;

      local_15 = 0;

      local_2c = 0;

      local_1c = 0;

      local_24 = 0;

      FUN_00433d30();

      local_50 = 1;

      while (local_50 != 0) {

        (**(code **)(*param_1 + 8))(&local_16,1,1);

        if (local_16 == 0) {

          (**(code **)(*param_1 + 8))(&local_16,1,1);

          if (local_16 == 0) {

            local_1c = 0;

            local_2c = local_2c + 1;

            local_24 = 0;

          }

          else if (local_16 == 1) {

            local_50 = 0;

          }

          else if (local_16 == 2) {

            (**(code **)(*param_1 + 8))(&local_26);

            (**(code **)(*param_1 + 8))(&local_25,1,1);

            local_1c = local_1c + (uint)(local_26 >> 1);

            local_2c = local_2c + (uint)local_25;

          }

          else {

            (**(code **)(*param_1 + 8))(&local_15);

            local_4c = FUN_00433d70();

            iVar2 = 0;

            while (local_6c = iVar2, iVar2 < (int)(uint)local_16) {

              pbVar6 = (byte *)(*(int *)(param_2 + 0x34) + *(int *)(param_2 + 0x1c));

              pbVar4 = (byte *)(local_1c + local_4c);

              if (local_24 == 0) {

                if (pbVar4 < pbVar6) {

                  *pbVar4 = local_15 & 0xf0;

                }

                local_24 = 1;

                iVar2 = iVar2 + 1;

              }

              else {

                if (pbVar4 < pbVar6) {

                  *pbVar4 = local_15 & 0xf | *pbVar4;

                }

                if (iVar2 != local_16 - 1) {

                  (**(code **)(*param_1 + 8))(&local_15);

                }

                local_1c = local_1c + 1;

                local_24 = (uint)(local_24 == 0);

                iVar2 = iVar2 + 1;

              }

            }

            if ((local_16 + 1 & 2) != 0) {

              (**(code **)(*param_1 + 8))(&local_15);

            }

          }

        }

        else {

          iVar2 = FUN_00433d70();

          (**(code **)(*param_1 + 8))(&local_15,1,1);

          for (local_48 = 0; local_48 < local_16; local_48 = local_48 + 1) {

            pbVar6 = (byte *)(*(int *)(param_2 + 0x34) + *(int *)(param_2 + 0x1c));

            pbVar4 = (byte *)(iVar2 + local_1c);

            if (local_24 == 0) {

              if (pbVar4 < pbVar6) {

                *pbVar4 = local_15 & 0xf0;

              }

            }

            else {

              if (pbVar4 < pbVar6) {

                *pbVar4 = local_15 & 0xf | *pbVar4;

              }

              local_1c = local_1c + 1;

            }

            local_24 = (uint)(local_24 == 0);

          }

        }

      }

    }

    break;

  case 0x10:

    if (local_3c == 3) {

      (**(code **)(*param_1 + 8))(&local_60,0xc,1);

    }

    else {

      local_60 = 0x7c00;

      local_5c = 0x3e0;

      local_58 = 0x1f;

    }

    if (local_a2 != 0) {

      (**(code **)(*param_1 + 0x10))(local_a2 + local_40,0);

    }

    (**(code **)(*param_1 + 8))

              (*(uint32_t /* width from decompiler */ *)(param_2 + 0x34),

               ((*(int *)(param_2 + 0xc) + 1) / 2) * *(int *)(param_2 + 0x10) * 4,1);

    FUN_00432630(param_2,*(uint32_t /* width from decompiler */ *)(param_2 + 0x34),local_60,local_5c,local_58);

    break;

  case 0x18:

    if (local_a2 != 0) {

      (**(code **)(*param_1 + 0x10))(local_a2 + local_40);

    }

    if (local_3c != 0) {

      local_b4 = "unknown compression";

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(&local_b4,(ThrowInfo *)&DAT_00acc49c);

    }

    (**(code **)(*param_1 + 8))(*(uint32_t /* width from decompiler */ *)(param_2 + 0x34),*(uint32_t /* width from decompiler */ *)(param_2 + 0x1c),1);

    break;

  case 0x20:

    if (local_a2 != 0) {

      (**(code **)(*param_1 + 0x10))(local_a2 + local_40);

    }

    if ((local_3c != 3) && (local_3c != 0)) {

      local_9c = "unknown compression";

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(&local_9c,(ThrowInfo *)&DAT_00acc49c);

    }

    _Size = *(int *)(param_2 + 0x10) * *(int *)(param_2 + 0xc) * 4;

    local_54 = malloc(_Size);

    if (local_54 == (void *)0x0) {

      local_94 = "can\'t allocate memory";

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(&local_94,(ThrowInfo *)&DAT_00acc49c);

    }

    (**(code **)(*param_1 + 8))(local_54,_Size);

    _Memory = local_54;

    FUN_00432630(param_2,local_54,0,0,0);

    free(_Memory);

  }

  if (local_1f != '\0') {

    FUN_0098ae80();

  }

  ExceptionList = local_10;

  return 1;

}
