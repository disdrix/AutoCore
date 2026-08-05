// READABILITY (auto CF):
//  - Body size: ~128 non-empty decompiler lines.
//  - Control keywords: if×12, do×2, while×2, for×1, return×1.
//  - Notable callees: FUN_00768760×4, FUN_00435df0×3, FUN_00437050, FUN_007450b0, FUN_00745760, FUN_0076cec0, FUN_0096a630, value.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\assets\\assCatalog.cpp".
//  - Return sites: 1.

// =============================================================================
// Named_assCatalog_00745760
// -----------------------------------------------------------------------------
// Stable ID: aa_00745760
// Address:   0x00745760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "assCatalog"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_assCatalog_00745760(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint uVar6;

  int iVar7;

  int local_54;

  int local_50;

  int local_4c;

  uint32_t /* width from decompiler */ *local_48;

  uint local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar3 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1248;

  local_c = ExceptionList;

  local_4c = 0;

  if (*(int *)(param_2 + 0x4044) == 0) {

    ExceptionList = &local_c;

    FUN_00437050(&local_4c);

  }

  else {

    ExceptionList = &local_c;

    FUN_00768760(&local_4c);

  }

  local_50 = 0;

  if (0 < local_4c) {

    local_30 = 0;

    local_2c = 0;

    do {

      iVar7 = 0;

      local_54 = 0;

      if (*(int *)(iVar3 + 0x4044) == 0) {

        if ((*(int *)(iVar3 + 0x18) + 4 <= *(int *)(iVar3 + 0x20)) ||

           ((iVar1 = FUN_00435df0(*(int *)(iVar3 + 0x1c) + *(int *)(iVar3 + 0x18)), -1 < iVar1 &&

            (3 < *(int *)(iVar3 + 0x20))))) {

          local_54 = *(int *)(*(int *)(iVar3 + 0x18) + iVar3 + 0x2c);

          *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 4;

        }

      }

      else {

        FUN_00768760(&local_54);

      }

      local_50 = local_50 + 1;

      local_48 = (uint32_t /* width from decompiler */ *)0x0;

      if (*(int *)(iVar3 + 0x4044) == 0) {

        if ((*(int *)(iVar3 + 0x18) + 4 <= *(int *)(iVar3 + 0x20)) ||

           ((iVar1 = FUN_00435df0(*(int *)(iVar3 + 0x1c) + *(int *)(iVar3 + 0x18)),

            puVar5 = (uint32_t /* width from decompiler */ *)0x0, -1 < iVar1 && (3 < *(int *)(iVar3 + 0x20))))) {

          puVar5 = *(uint32_t /* width from decompiler */ **)(*(int *)(iVar3 + 0x18) + iVar3 + 0x2c);

          *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 4;

        }

      }

      else {

        FUN_00768760(&local_48);

        puVar5 = local_48;

      }

      iVar3 = *(int *)(param_1 + 0x50);

      local_48 = (uint32_t /* width from decompiler */ *)0x0;

      if ((iVar3 != 0) && (puVar5 < (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x54) - iVar3 >> 2))) {

        local_48 = (uint32_t /* width from decompiler */ *)(iVar3 + (int)puVar5 * 4);

      }

      local_34 = *local_48;

      if (local_54 != 1 && -1 < local_54 + -1) {

        do {

          iVar3 = param_2;

          local_44 = 0;

          if (*(int *)(param_2 + 0x4044) == 0) {

            iVar1 = param_2 + 0x2c;

            if ((*(int *)(param_2 + 0x18) + 4 <= *(int *)(param_2 + 0x20)) ||

               ((iVar2 = FUN_00435df0(*(int *)(param_2 + 0x1c) + *(int *)(param_2 + 0x18)),

                uVar6 = 0, -1 < iVar2 && (3 < *(int *)(iVar3 + 0x20))))) {

              uVar6 = *(uint *)(*(int *)(iVar3 + 0x18) + iVar1);

              *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 4;

            }

          }

          else {

            FUN_00768760(&local_44);

            uVar6 = local_44;

          }

          iVar3 = *(int *)(param_1 + 0x50);

          if (((iVar3 == 0) || ((uint)(*(int *)(param_1 + 0x54) - iVar3 >> 2) <= uVar6)) ||

             (puVar5 = (uint32_t /* width from decompiler */ *)(iVar3 + uVar6 * 4), puVar5 == (uint32_t /* width from decompiler */ *)0x0)) {

            iVar3 = FUN_0096a630(local_28);

            local_4 = 0;

            if (*(uint *)(iVar3 + 0x18) < 0x10) {

              iVar3 = iVar3 + 4;

            }

            else {

              iVar3 = *(int *)(iVar3 + 4);

            }

            uVar4 = FUN_0076cec0(&param_2,

                                 "UnserializeDependencyInfo found an invalid value(%d) for Entry=%d, Value=%d, key=<%s>!"

                                 ,uVar6,local_50,iVar7,iVar3);

            vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\assets\\assCatalog.cpp",0x1e1,2,

                           uVar4);

            local_4 = 0xffffffff;

            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

            ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_28);

          }

          else {

            local_40 = *puVar5;

            local_3c = 0;

            local_38 = 0;

            FUN_007450b0(param_1,&local_34,&local_40);

          }

          iVar7 = iVar7 + 1;

        } while (iVar7 < local_54 + -1);

      }

      local_50 = local_50 + local_54;

      iVar3 = param_2;

    } while (local_50 < local_4c);

  }

  ExceptionList = local_c;

  return 0;

}
