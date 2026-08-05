// =============================================================================
// Named_CalleeOf_Named_anmAnimMaster_00963fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00963fb0
// Callee of Named_anmAnimMaster
// Address:   0x00963fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_anmAnimMaster: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~199 non-empty decompiler lines.
//  - Control keywords: if×27, do×3, goto×3, while×3, return×1.
//  - Notable callees: CONCAT31×6, block×4, stoChunkReader_readF32Array×4, FUN_00437050×3, FUN_00436f10×2, FUN_00449000×2, FUN_00768760×2, FUN_007689e0×2.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_anmAnimMaster
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Removing unreachable block (ram,0x00964344) */

/* WARNING: Removing unreachable block (ram,0x00964600) */

/* WARNING: Removing unreachable block (ram,0x00964361) */

/* WARNING: Removing unreachable block (ram,0x009645e1) */



uint32_t /* width from decompiler */ Named_CalleeOf_Named_anmAnimMaster_00963fb0(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  uint32_t /* width from decompiler */ local_ec;

  int local_e8;

  int local_e4;

  int local_cc;

  char local_8c;

  int local_88;

  int local_84;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_48 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_2c [32];

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b18d1;

  local_c = ExceptionList;

  local_ec = 0xffffffff;

  if (*(int *)(param_3 + 0xc) == 0x414e494d) {

    if ((*(int *)(param_3 + 0x10) == 0) || (*(int *)(param_3 + 0x10) == 1)) {

      if (*(int *)(param_2 + 0x4044) == 0) {

        ExceptionList = &local_c;

        FUN_00437050();

      }

      else {

        ExceptionList = &local_c;

        FUN_007689e0();

      }

      if (*(int *)(param_2 + 0x4044) == 0) {

        FUN_00437000();

      }

      else {

        FUN_00769660();

      }

      FUN_00456780();

      if (local_e8 != 0) {

        iVar6 = 0;

        local_cc = local_e8;

        do {

          if (*(int *)(param_2 + 0x4044) == 0) {

            if ((*(int *)(param_2 + 0x18) + 4 <= *(int *)(param_2 + 0x20)) ||

               ((iVar2 = FUN_00435df0(), -1 < iVar2 && (3 < *(int *)(param_2 + 0x20))))) {

              *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + 4;

            }

          }

          else {

            FUN_007689e0();

          }

          stoChunkReader_EnterChunkScope();

          local_4 = 0;

          if (local_88 == 0x49524f54) {

            if (local_84 == 0) {

              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_2c)

              ;

              local_4 = CONCAT31(local_4._1_3_,1);

              if (*(int *)(param_2 + 0x4044) == 0) {

                FUN_00436f10();

              }

              else {

                FUN_0076a200();

              }

              if (*(int *)(param_2 + 0x4044) == 0) {

                FUN_00437050();

              }

              else {

                FUN_00768760();

              }

              local_4 = CONCAT31(local_4._1_3_,3);

              FUN_0043ffb0();

              FUN_00449000();

              if (0 < local_e4) {

                stoChunkReader_readF32Array();

                stoChunkReader_readF32Array();

              }

              pvVar3 = operator_new(0x30);

              local_4._0_1_ = 8;

              if (pvVar3 == (void *)0x0) {

                uVar4 = 0;

              }

              else {

                uVar4 = FUN_00458020();

              }

              local_4 = CONCAT31(local_4._1_3_,3);

              *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc) + iVar6) = uVar4;

              *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0xc) + iVar6) + 0x10) = 0x534b454c;

              iVar2 = *(int *)(*(int *)(param_1 + 0xc) + iVar6);

              puVar5 = (uint32_t /* width from decompiler */ *)FUN_00989e00();

              *(uint32_t /* width from decompiler */ *)(iVar2 + 0x14) = *puVar5;

              (**(code **)(**(int **)(*(int *)(param_1 + 0xc) + iVar6) + 0x24))();

              if (0 < local_e4) {

                iVar2 = 0;

                do {

                  iVar1 = *(int *)(*(int *)(param_1 + 0xc) + iVar6);

                  if ((*(int *)(iVar1 + 0x20) == 0) ||

                     ((*(int *)(iVar1 + 0x24) - *(int *)(iVar1 + 0x20)) / 0x14 == 0)) {

                    if (*(float *)(iVar2 * 4) == g_flZero) goto LAB_00964312;

                  }

                  else if (*(float *)(*(int *)(iVar1 + 0x24) + -4) < *(float *)(iVar2 * 4)) {

LAB_00964312:

                    FUN_00467180();

                  }

                  iVar2 = iVar2 + 1;

                } while (iVar2 < local_e4);

              }

              local_4 = local_4 & 0xffffff00;

              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (local_2c);

LAB_00964633:

              local_ec = 0;

            }

          }

          else if ((local_88 == 0x49525452) && (local_84 == 0)) {

            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_48);

            local_4 = CONCAT31(local_4._1_3_,0xd);

            if (*(int *)(param_2 + 0x4044) == 0) {

              FUN_00436f10();

            }

            else {

              FUN_0076a200();

            }

            if (*(int *)(param_2 + 0x4044) == 0) {

              FUN_00437050();

            }

            else {

              FUN_00768760();

            }

            local_4 = CONCAT31(local_4._1_3_,0xf);

            FUN_00466df0();

            FUN_00449000();

            if (0 < local_e8) {

              stoChunkReader_readF32Array();

              stoChunkReader_readF32Array();

            }

            pvVar3 = operator_new(0x30);

            local_4._0_1_ = 0x11;

            if (pvVar3 == (void *)0x0) {

              uVar4 = 0;

            }

            else {

              uVar4 = FUN_00457f30();

            }

            local_4 = CONCAT31(local_4._1_3_,0xf);

            *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc) + iVar6) = uVar4;

            *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0xc) + iVar6) + 0x10) = 0x534b454c;

            iVar2 = *(int *)(*(int *)(param_1 + 0xc) + iVar6);

            puVar5 = (uint32_t /* width from decompiler */ *)FUN_00989e00();

            *(uint32_t /* width from decompiler */ *)(iVar2 + 0x14) = *puVar5;

            (**(code **)(**(int **)(*(int *)(param_1 + 0xc) + iVar6) + 0x24))();

            iVar2 = 0;

            if (0 < local_e8) {

              do {

                iVar1 = *(int *)(*(int *)(param_1 + 0xc) + iVar6);

                if ((*(int *)(iVar1 + 0x20) == 0) ||

                   (*(int *)(iVar1 + 0x24) - *(int *)(iVar1 + 0x20) >> 5 == 0)) {

                  if (*(float *)(iVar2 * 4) == g_flZero) goto LAB_009645b5;

                }

                else if (*(float *)(*(int *)(iVar1 + 0x24) + -4) < *(float *)(iVar2 * 4)) {

LAB_009645b5:

                  FUN_00467200();

                }

                iVar2 = iVar2 + 1;

              } while (iVar2 < local_e8);

            }

            local_4 = local_4 & 0xffffff00;

            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

            ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>(local_48);

            goto LAB_00964633;

          }

          local_4 = 0xffffffff;

          if (local_8c != '\0') {

            FUN_00769e40();

          }

          iVar6 = iVar6 + 4;

          local_cc = local_cc + -1;

        } while (local_cc != 0);

      }

    }

  }

  else {

    ExceptionList = &local_c;

    vog_LogMessage();

    local_ec = 0xffffffff;

  }

  ExceptionList = local_c;

  return local_ec;

}
