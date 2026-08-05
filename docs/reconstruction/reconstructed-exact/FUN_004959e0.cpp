// =============================================================================
// FUN_004959e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004959e0
// Address:   0x004959e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004959e0 @ 0x004959e0
// Stable ID: aa_004959e0
// Embedded strings (evidence for future rename):
//   - "Opaque"
//   - "Translucent"
//   - "MatDiffuse"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~228 non-empty decompiler lines.
//  - Control keywords: if×25, while×5, goto×4, do×1, return×1.
//  - Notable callees: FUN_00746210×3, FUN_007522a0×3, FUN_0096f540×3, FUN_0096f840×3, FUN_0096fdf0×3, FUN_009700f0×3, FUN_004959e0, SQRT.
//  - Strings: "Opaque"; "Translucent"; "MatDiffuse".
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

void __thiscall FUN_004959e0(int param_1,uint param_2,uint32_t /* width from decompiler */ param_3,float *param_4)



{

  int iVar1;

  float fVar2;

  bool bVar3;

  char cVar4;

  bool bVar5;

  float *pfVar6;

  int iVar7;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar8;

  int *piVar9;

  uint uVar10;

  int iVar11;

  int iVar12;

  float fVar13;

  int iStack_90;

  float fStack_8c;

  uint local_80;

  uint32_t /* width from decompiler */ local_7c;

  uint32_t /* width from decompiler */ local_78;

  uint32_t /* width from decompiler */ local_74;

  float local_70;

  float fStack_6c;

  float fStack_68;

  float fStack_64;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_60 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_44 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> abStack_28 [28];

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a0c77;

  pvStack_c = ExceptionList;

  bVar3 = false;

  local_7c = 0;

  local_78 = 0;

  local_74 = 0;

  local_70 = g_flOne;

  local_80 = param_2;

  iVar12 = param_2 * 4;

  ExceptionList = &pvStack_c;

  do {

    iVar11 = *(int *)(param_1 + 0xac);

    if ((iVar11 == 0) || ((uint)(*(int *)(param_1 + 0xb0) - iVar11 >> 2) <= local_80)) {

      ExceptionList = pvStack_c;

      return;

    }

    piVar9 = *(int **)(iVar12 + iVar11);

    if (piVar9[0x52] == -1) {

LAB_004960a5:

      (**(code **)(*piVar9 + 0x3c))(param_3);

    }

    else {

      fStack_8c = *(float *)(param_1 + 0x58) + *(float *)(param_1 + 0x54);

      if (*(int *)(*(int *)(iVar12 + iVar11) + 0x148) != 0) {

        fStack_8c = (float)*(int *)(*(int *)(iVar12 + iVar11) + 0x148) + fStack_8c;

      }

      pfVar6 = (float *)(**(code **)(**(int **)(iVar12 + iVar11) + 0x28))();

      fStack_64 = (param_4[1] - pfVar6[1]) * (param_4[1] - pfVar6[1]) +

                  (param_4[2] - pfVar6[2]) * (param_4[2] - pfVar6[2]) +

                  (*param_4 - *pfVar6) * (*param_4 - *pfVar6);

      fVar2 = (fStack_8c - (*(float *)(param_1 + 0x58) + *(float *)(param_1 + 0x54))) +

              SQRT(fStack_64);

      if (*(int *)(*(int *)(iVar12 + *(int *)(param_1 + 0xac)) + 0x140) < DAT_00aefa60) {

        iVar11 = 0;

        while( true ) {

          iVar7 = *(int *)(*(int *)(param_1 + 0xac) + iVar12);

          iVar1 = *(int *)(iVar7 + 0xc0);

          if (iVar1 == 0) {

            iVar7 = 0;

          }

          else {

            iVar7 = *(int *)(iVar7 + 0xc4) - iVar1 >> 2;

          }

          if (iVar7 <= iVar11) break;

          cVar4 = FUN_0096f540();

          if (cVar4 != '\0') {

            fVar13 = (float)*(int *)(*(int *)(*(int *)(param_1 + 0xac) + iVar12) + 0x140) *

                     DAT_00a0f718;

            uVar10 = 4;

            fStack_68 = g_flOne;

            while( true ) {

              if ((uVar10 & 1) != 0) {

                fStack_68 = fStack_68 * fVar13;

              }

              uVar10 = uVar10 >> 1;

              if (uVar10 == 0) break;

              fVar13 = fVar13 * fVar13;

            }

            fStack_68 = fStack_68 * DAT_00aaa690;

            fStack_6c = g_flOne;

            if (DAT_00aefa5c * fStack_8c <= fVar2) {

              fVar13 = (DAT_00aefa58 * fStack_8c - fVar2) /

                       (DAT_00aefa58 * fStack_8c - DAT_00aefa5c * fStack_8c);

              fStack_6c = fVar13 * g_flLevelUpUiBase_Inferred - fVar13 * fVar13;

            }

            FUN_0096fdf0();

            pbVar8 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *

                     )FUN_00746210(abStack_28,

                                   *(uint32_t /* width from decompiler */ *)

                                    (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xac) +

                                                                        iVar12) + 0xc0) + iVar11 * 4

                                                      ) + 0x20) + 0x1c));

            uStack_4 = 2;

            bVar5 = std::operator==<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                              ("Opaque",pbVar8);

            uStack_4 = 0xffffffff;

            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

            ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (abStack_28);

            if (bVar5) {

              FUN_007522a0("Translucent");

            }

            FUN_0096f840("MatDiffuse",&local_7c);

            local_70 = fStack_6c;

            if (fStack_68 < fStack_6c) {

              local_70 = fStack_68;

            }

            FUN_009700f0("MatDiffuse",&local_7c);

          }

          iVar11 = iVar11 + 1;

        }

        piVar9 = (int *)(*(int *)(*(int *)(param_1 + 0xac) + iVar12) + 0x140);

        *piVar9 = *piVar9 + 1;

LAB_0049609b:

        piVar9 = *(int **)(*(int *)(param_1 + 0xac) + iVar12);

        goto LAB_004960a5;

      }

      if ((fVar2 <= DAT_00aefa58 * fStack_8c) && (DAT_00aefa5c * fStack_8c <= fVar2)) {

        iVar11 = 0;

        while( true ) {

          iVar7 = *(int *)(iVar12 + *(int *)(param_1 + 0xac));

          iVar1 = *(int *)(iVar7 + 0xc0);

          if (iVar1 == 0) {

            iVar7 = 0;

          }

          else {

            iVar7 = *(int *)(iVar7 + 0xc4) - iVar1 >> 2;

          }

          if (iVar7 <= iVar11) break;

          cVar4 = FUN_0096f540();

          if (cVar4 != '\0') {

            FUN_0096fdf0();

            pbVar8 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *

                     )FUN_00746210(abStack_60,

                                   *(uint32_t /* width from decompiler */ *)

                                    (*(int *)(*(int *)(*(int *)(*(int *)(iVar12 + *(int *)(param_1 +

                                                                                          0xac)) +

                                                               0xc0) + iVar11 * 4) + 0x20) + 0x1c));

            uStack_4 = 0;

            bVar5 = std::operator==<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                              ("Opaque",pbVar8);

            uStack_4 = 0xffffffff;

            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

            ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (abStack_60);

            if (bVar5) {

              FUN_007522a0("Translucent");

            }

            FUN_0096f840("MatDiffuse",&local_7c);

            fVar13 = (DAT_00aefa58 * fStack_8c - fVar2) /

                     (DAT_00aefa58 * fStack_8c - DAT_00aefa5c * fStack_8c);

            local_70 = fVar13 * g_flLevelUpUiBase_Inferred - fVar13 * fVar13;

            FUN_009700f0("MatDiffuse",&local_7c);

          }

          iVar11 = iVar11 + 1;

        }

        goto LAB_0049609b;

      }

      if (fVar2 < DAT_00aefa5c * fStack_8c) {

        iStack_90 = 0;

        while( true ) {

          iVar11 = *(int *)(iVar12 + *(int *)(param_1 + 0xac));

          iVar7 = *(int *)(iVar11 + 0xc0);

          if (iVar7 == 0) {

            iVar11 = 0;

          }

          else {

            iVar11 = *(int *)(iVar11 + 0xc4) - iVar7 >> 2;

          }

          if (iVar11 <= iStack_90) break;

          cVar4 = FUN_0096f540();

          FUN_0096fdf0();

          if (cVar4 == '\0') {

LAB_00495dc7:

            bVar5 = false;

          }

          else {

            pbVar8 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *

                     )FUN_00746210(abStack_44,

                                   *(uint32_t /* width from decompiler */ *)

                                    (*(int *)(*(int *)(*(int *)(*(int *)(iVar12 + *(int *)(param_1 +

                                                                                          0xac)) +

                                                               0xc0) + iStack_90 * 4) + 0x20) + 0x1c

                                    ));

            bVar3 = true;

            uStack_4 = 1;

            bVar5 = std::operator==<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                              ("Translucent",pbVar8);

            if (!bVar5) goto LAB_00495dc7;

            bVar5 = true;

          }

          uStack_4 = 0xffffffff;

          if (bVar3) {

            bVar3 = false;

            std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

            ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                      (abStack_44);

          }

          if (bVar5) {

            FUN_007522a0("Opaque");

          }

          FUN_0096f840("MatDiffuse",&local_7c);

          local_70 = g_flOne;

          FUN_009700f0("MatDiffuse",&local_7c);

          iStack_90 = iStack_90 + 1;

        }

        goto LAB_0049609b;

      }

    }

    if (*(char *)(DAT_00d1f048 + 0xf) != '\0') {

      (**(code **)(**(int **)(*(int *)(param_1 + 0xac) + iVar12) + 0x40))(param_3);

    }

    local_80 = local_80 + 1;

    iVar12 = iVar12 + 4;

  } while( true );

}
