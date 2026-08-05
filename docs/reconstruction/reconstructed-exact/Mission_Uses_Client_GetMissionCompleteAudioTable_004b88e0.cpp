// READABILITY (auto CF):
//  - Body size: ~225 non-empty decompiler lines.
//  - Control keywords: if×18, while×16, do×14, for×2, return×1.
//  - Notable callees: FUN_0043d670×9, FUN_00989e00×9, Client_GetMissionCompleteAudioTable×2, FUN_004a05c0×2, FUN_00722790×2, c_str×2, strtok×2, FUN_004b88e0.
//  - Return sites: 1.

// =============================================================================
// Mission_Uses_Client_GetMissionCompleteAudioTable_004b88e0
// -----------------------------------------------------------------------------
// Purpose:  String-driven human alias for decompiled bulk unit.
//           Primary evidence: "Client_GetMissionCompleteAudioTable"
//           Named entry point for reconstruction indexing / coverage ledger.
//           Behavior preserved from FUN_004b88e0 clean capture (not modernized).
//
// Address:  0x004b88e0  (autoassault.exe, image base 0x400000)
// Stable:   aa_004b88e0
// Stable ID: aa_004b88e0
// System:   missions-progression
//
// Naming:   From informative string/keyword evidence in
//           docs/reconstruction/raw/aa_004b88e0_*.md
//           Original Ghidra symbol: FUN_004b88e0
//
// Exactness: Body mirrors reconstructed-exact/FUN_004b88e0*.cpp when present.
//            Offsets and control flow are not invented here.
// =============================================================================

// =============================================================================
// Mission_Uses_Client_GetMissionCompleteAudioTable_004b88e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004b88e0
// Address:   0x004b88e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven human alias evidence: "Client_GetMissionCompleteAudioTable"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Mission_Uses_Client_GetMissionCompleteAudioTable_004b88e0(int param_1,uint32_t /* width from decompiler */ param_2,char param_3,char param_4,char param_5)



{

  char cVar1;

  int iVar2;

  void **ppvVar3;

  char *pcVar4;

  char *pcVar5;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar6;

  uint uVar7;

  int *piVar8;

  int iVar9;

  char *pcVar10;

  int iVar11;

  char *pcVar12;

  uint8_t local_464 [4];

  int *local_460;

  int local_45c;

  uint8_t local_458 [4];

  int local_454;

  uint8_t local_450 [4];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_44c [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_430 [27];

  char cStack_415;

  char local_414 [260];

  char local_310 [260];

  char local_20c [512];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a154b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  local_45c = param_1;

  if ((param_5 != '\0') &&

     (piVar8 = (int *)**(int **)(param_1 + 0x204), ExceptionList = &local_c, ppvVar3 = &local_c,

     piVar8 != *(int **)(param_1 + 0x204))) {

    do {

      ExceptionList = ppvVar3;

      iVar11 = piVar8[2];

      if ((*(byte *)(iVar11 + 0x90d) & 4) != 0) {

        FUN_00989e00(&local_460,iVar11 + 0x1d0);

        FUN_0043d670(&local_460);

      }

      if ((*(byte *)(iVar11 + 0x90c) & 0x80) != 0) {

        pcVar4 = (char *)(iVar11 + 0x2be);

        iVar11 = -(int)pcVar4;

        do {

          cVar1 = *pcVar4;

          pcVar4[(int)(local_414 + iVar11)] = cVar1;

          pcVar4 = pcVar4 + 1;

        } while (cVar1 != '\0');

        pcVar4 = &cStack_415;

        do {

          pcVar5 = pcVar4 + 1;

          pcVar4 = pcVar4 + 1;

        } while (*pcVar5 != '\0');

        *(uint32_t /* width from decompiler */ *)pcVar4 = DAT_009cb318;

        FUN_00989e00(local_450,local_414);

        FUN_0043d670(local_450);

        param_1 = local_45c;

      }

      piVar8 = (int *)*piVar8;

      ppvVar3 = ExceptionList;

    } while (piVar8 != (int *)*(int *)(param_1 + 0x204));

  }

  if (param_3 != '\0') {

    local_460 = (int *)**(int **)(param_1 + 0x204);

    if (local_460 != *(int **)(param_1 + 0x204)) {

      do {

        iVar11 = local_460[2];

        pcVar4 = (char *)(iVar11 + 0x33d);

        do {

          cVar1 = *pcVar4;

          pcVar4 = pcVar4 + 1;

        } while (cVar1 != '\0');

        local_454 = iVar11;

        if (3 < (uint)((int)pcVar4 - (iVar11 + 0x33e))) {

          FUN_00989e00(local_450,iVar11 + 0x33d);

          FUN_0043d670(local_450);

          iVar9 = iVar11 + 0x3bc;

          while (iVar9 != 0) {

            if ((*(byte *)(iVar9 + 0x3c9) & 0x10) != 0) {

              if ((*(byte *)(iVar11 + 0x90e) & 0x20) == 0) {

                pcVar4 = (char *)(iVar9 + 0x379);

                iVar2 = -(int)pcVar4;

                do {

                  cVar1 = *pcVar4;

                  pcVar4[(int)(local_414 + iVar2)] = cVar1;

                  pcVar4 = pcVar4 + 1;

                } while (cVar1 != '\0');

              }

              else {

                pcVar4 = (char *)(iVar11 + 0x33d);

                iVar11 = -(int)pcVar4;

                do {

                  cVar1 = *pcVar4;

                  pcVar4[(int)(local_414 + iVar11)] = cVar1;

                  pcVar4 = pcVar4 + 1;

                } while (cVar1 != '\0');

                pcVar4 = (char *)(iVar9 + 0x379);

                pcVar5 = pcVar4;

                do {

                  cVar1 = *pcVar5;

                  pcVar5 = pcVar5 + 1;

                } while (cVar1 != '\0');

                pcVar12 = &cStack_415;

                do {

                  pcVar10 = pcVar12 + 1;

                  pcVar12 = pcVar12 + 1;

                } while (*pcVar10 != '\0');

                pcVar10 = pcVar4;

                for (uVar7 = (uint)((int)pcVar5 - (int)pcVar4) >> 2; uVar7 != 0; uVar7 = uVar7 - 1)

                {

                  *(uint32_t /* width from decompiler */ *)pcVar12 = *(uint32_t /* width from decompiler */ *)pcVar10;

                  pcVar10 = pcVar10 + 4;

                  pcVar12 = pcVar12 + 4;

                }

                for (uVar7 = (int)pcVar5 - (int)pcVar4 & 3; iVar11 = local_454, param_1 = local_45c,

                    uVar7 != 0; uVar7 = uVar7 - 1) {

                  *pcVar12 = *pcVar10;

                  pcVar10 = pcVar10 + 1;

                  pcVar12 = pcVar12 + 1;

                }

              }

              FUN_00989e00(local_458,local_414);

              FUN_0043d670(local_458);

            }

            if ((*(byte *)(iVar9 + 0x3c9) & 8) != 0) {

              FUN_00989e00(local_464,iVar9 + 0x338);

              FUN_0043d670(local_464);

            }

            iVar9 = *(int *)(iVar9 + 0x2f4);

            if ((iVar9 == 0) || (iVar9 == iVar11 + 0x3bc)) break;

          }

        }

        local_460 = (int *)*local_460;

      } while (local_460 != (int *)*(int *)(param_1 + 0x204));

    }

    piVar8 = (int *)**(int **)(param_1 + 0x1e0);

    if (piVar8 != *(int **)(param_1 + 0x1e0)) {

      do {

        if (*(char *)(piVar8[2] + 0x7fc) != '\0') {

          iVar11 = piVar8[2] + 0x3f8;

          iVar9 = iVar11;

          while (param_1 = local_45c, iVar9 != 0) {

            if (0 < *(short *)(iVar9 + 0x1de)) {

              pbVar6 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        *)FUN_004a05c0(local_44c,*(short *)(iVar9 + 0x1de));

              local_4 = 0;

              pcVar4 = std::

                       basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                       ::c_str(pbVar6);

              FUN_00989e00(local_464,pcVar4);

              FUN_0043d670(local_464);

              local_4 = 0xffffffff;

              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (local_44c);

            }

            if (0 < *(short *)(iVar9 + 0x1dc)) {

              pbVar6 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        *)FUN_004a05c0(local_430,*(short *)(iVar9 + 0x1dc));

              local_4 = 1;

              pcVar4 = std::

                       basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                       ::c_str(pbVar6);

              FUN_00989e00(local_458,pcVar4);

              FUN_0043d670(local_458);

              local_4 = 0xffffffff;

              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (local_430);

            }

            iVar9 = *(int *)(iVar9 + 0x2f4);

            param_1 = local_45c;

            if ((iVar9 == 0) || (iVar9 == iVar11)) break;

          }

        }

        piVar8 = (int *)*piVar8;

      } while (piVar8 != (int *)*(int *)(param_1 + 0x1e0));

    }

  }

  if ((param_4 != '\0') &&

     (piVar8 = (int *)**(int **)(param_1 + 0x1ec), piVar8 != *(int **)(param_1 + 0x1ec))) {

    do {

      pcVar4 = (char *)piVar8[2];

      if (*(int *)(pcVar4 + 0x104) != 0x50) {

        iVar11 = -(int)pcVar4;

        do {

          cVar1 = *pcVar4;

          pcVar4[(int)(local_20c + iVar11)] = cVar1;

          pcVar4 = pcVar4 + 1;

        } while (cVar1 != '\0');

        pcVar4 = strtok(local_20c,"|");

        if (pcVar4 == (char *)0x0) {

          pcVar4 = local_20c;

          Client_GetMissionCompleteAudioTable(pcVar4);

          FUN_00722790(pcVar4);

          FUN_00989e00(local_464,local_20c);

          FUN_0043d670(local_464);

        }

        else {

          do {

            iVar11 = -(int)pcVar4;

            do {

              cVar1 = *pcVar4;

              pcVar4[(int)(local_310 + iVar11)] = cVar1;

              pcVar4 = pcVar4 + 1;

            } while (cVar1 != '\0');

            pcVar4 = local_310;

            Client_GetMissionCompleteAudioTable(pcVar4);

            FUN_00722790(pcVar4);

            FUN_00989e00(&local_454,local_310);

            FUN_0043d670(&local_454);

            pcVar4 = strtok((char *)0x0,"|");

          } while (pcVar4 != (char *)0x0);

        }

      }

      piVar8 = (int *)*piVar8;

    } while (piVar8 != (int *)*(int *)(param_1 + 0x1ec));

  }

  ExceptionList = local_c;

  return;

}
