// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, return×2.
//  - Notable callees: FUN_007a4480×6, FUN_00787d40×2, FUN_00787a30, FUN_00787c90, FUN_0080b3a0, FUN_0080bc40.
//  - Strings: "Unpacked too much! %d + %d > %d"; "VOG_DEBUG_STOP".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_0080bc40
// -----------------------------------------------------------------------------
// Stable ID: aa_0080bc40
// Address:   0x0080bc40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
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



void __thiscall Named_VOG_DEBUG_STOP_0080bc40(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  uint local_1c54;

  undefined **local_1c50;

  int local_c3c;

  int local_c38;

  int local_c34;

  void *local_c2c;

  uint32_t /* width from decompiler */ local_c1c;

  uint32_t /* width from decompiler */ local_c14;

  uint32_t /* width from decompiler */ local_c10;

  uint32_t /* width from decompiler */ local_c0c;

  uint32_t /* width from decompiler */ local_c08;

  byte local_c04;

  uint32_t /* width from decompiler */ local_c00 [764];

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009af065;

  local_c = ExceptionList;

  uStack_10 = 0x80bc5f;

  ExceptionList = &local_c;

  FUN_00787c90(param_1,param_3);

  local_4 = 0;

  FUN_00787d40(&local_1c54,4);

  FUN_00787d40(&local_1c54,2);

  local_c1c = 0x20aa;

  iVar6 = local_c34;

  uVar1 = local_1c54 & 0xffff;

  if ((local_1c54 & 0xffff) != 0) {

    do {

      local_1c54 = uVar1;

      iVar4 = iVar6 + 0x10;

      if (local_c38 < iVar4) {

        FUN_007a4480(1,"Unpacked too much! %d + %d > %d",iVar6,0x10,local_c38);

        FUN_007a4480(0,"VOG_DEBUG_STOP");

        iVar4 = iVar6;

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)(local_c3c + iVar6);

        local_c14 = *puVar2;

        local_c10 = puVar2[1];

        local_c0c = puVar2[2];

        local_c08 = puVar2[3];

        local_c34 = iVar4;

      }

      iVar6 = iVar4 + 1;

      if (local_c38 < iVar6) {

        FUN_007a4480(1,"Unpacked too much! %d + %d > %d",iVar4,1,local_c38);

        FUN_007a4480(0,"VOG_DEBUG_STOP");

        iVar6 = iVar4;

      }

      else {

        local_c04 = *(byte *)(local_c3c + iVar4);

        local_c34 = iVar6;

      }

      iVar4 = 0;

      if (local_c04 != 0) {

        puVar2 = local_c00;

        iVar5 = iVar6;

        do {

          iVar6 = iVar5 + 0xc;

          if (local_c38 < iVar6) {

            FUN_007a4480(1,"Unpacked too much! %d + %d > %d",iVar5,0xc,local_c38);

            FUN_007a4480(0,"VOG_DEBUG_STOP");

            iVar6 = iVar5;

          }

          else {

            puVar3 = (uint32_t /* width from decompiler */ *)(local_c3c + iVar5);

            *puVar2 = *puVar3;

            puVar2[1] = puVar3[1];

            puVar2[2] = puVar3[2];

            local_c34 = iVar6;

          }

          iVar4 = iVar4 + 1;

          puVar2 = puVar2 + 3;

          iVar5 = iVar6;

        } while (iVar4 < (int)(uint)local_c04);

      }

      FUN_0080b3a0(param_2);

      uVar1 = local_1c54 - 1;

    } while (local_1c54 - 1 != 0);

    local_1c54 = 0;

  }

  local_4 = 0xffffffff;

  local_1c50 = &PTR_FUN_00a9ab24;

  FUN_00787a30();

  if (local_c2c == (void *)0x0) {

    ExceptionList = local_c;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(local_c2c);

}
