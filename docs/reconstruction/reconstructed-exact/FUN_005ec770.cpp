// =============================================================================
// FUN_005ec770
// -----------------------------------------------------------------------------
// Stable ID: aa_005ec770
// Address:   0x005ec770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ec770 @ 0x005ec770
// Stable ID: aa_005ec770
// Embedded strings (evidence for future rename):
//   - " faces. Result will be undefined"
//   - "An edge is shared by "
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~211 non-empty decompiler lines.
//  - Control keywords: if×14, while×4, for×3, do×2, goto×2, return×1.
//  - Notable callees: free×2, malloc×2, FUN_005ec770.
//  - Strings: " faces. Result will be undefined"; "An edge is shared by ".
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

int * __thiscall FUN_005ec770(int *param_1,int *param_2,int *param_3)



{

  uint uVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  basic_ostream<char,struct_std::char_traits<char>_> *pbVar9;

  uint uVar10;

  int iVar11;

  uint32_t /* width from decompiler */ *puVar12;

  uint *puVar13;

  uint32_t /* width from decompiler */ *puVar14;

  uint uVar15;

  uint32_t /* width from decompiler */ *puVar16;

  bool bVar17;

  char *pcVar18;

  _func_basic_ostream<char,struct_std::char_traits<char>_>_ptr_basic_ostream<char,struct_std::char_traits<char>_>_ptr

  *p_Var19;

  uint *local_58;

  uint local_40 [7];

  uint local_24;

  uint8_t local_20;

  uint local_18;

  uint local_14;

  uint8_t local_10;

  uint8_t local_f;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a783a;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[5] = (int)param_2;

  param_1[4] = (int)param_3;

  uVar2 = (param_2[1] - *param_2) / 0xc;

  iVar5 = (param_3[1] - *param_3) / 0xc + uVar2;

  local_4 = 0;

  if (iVar5 != 0) {

    puVar6 = malloc(iVar5 * 0x1c);

    puVar8 = (uint32_t /* width from decompiler */ *)param_1[1];

    puVar3 = (uint32_t /* width from decompiler */ *)*param_1;

    puVar4 = puVar6;

    while (puVar3 != puVar8) {

      puVar7 = puVar3 + 7;

      puVar12 = puVar4 + 7;

      puVar14 = puVar3;

      puVar16 = puVar4;

      for (iVar11 = 7; puVar3 = puVar7, puVar4 = puVar12, iVar11 != 0; iVar11 = iVar11 + -1) {

        *puVar16 = *puVar14;

        puVar14 = puVar14 + 1;

        puVar16 = puVar16 + 1;

      }

    }

    if ((void *)*param_1 != (void *)0x0) {

      free((void *)*param_1);

    }

    param_1[2] = (int)(puVar6 + iVar5 * 7);

    param_1[1] = (int)(puVar6 + ((param_1[1] - *param_1) / 0x1c) * 7);

    *param_1 = (int)puVar6;

  }

  param_3 = (int *)0x0;

  if (uVar2 != 0) {

    param_2 = (int *)0x0;

    uVar15 = 0;

LAB_005ec8a0:

    do {

      p_Var19 = endl_exref;

      puVar13 = (uint *)(*(int *)param_1[5] + (int)param_2);

      puVar8 = (uint32_t /* width from decompiler */ *)(*(int *)param_1[5] + (int)param_2);

      local_40[3] = *puVar8;

      local_40[0] = *puVar13;

      local_40[4] = puVar8[1];

      local_40[5] = puVar8[2];

      local_40[2] = puVar13[2];

      uVar1 = uVar15 + 1;

      uVar15 = local_40[uVar15 + 3];

      local_40[1] = puVar13[1];

      uVar10 = local_40[uVar1 % 3];

      bVar17 = uVar10 <= uVar15;

      if (bVar17) {

        local_24 = uVar15;

        local_20 = 1;

      }

      else {

        local_24 = uVar10;

        local_20 = 0;

        uVar10 = uVar15;

      }

      puVar13 = (uint *)*param_1;

      iVar5 = param_1[1] - (int)puVar13 >> 0x1f;

      uVar15 = 0;

      local_20 = bVar17;

      if ((param_1[1] - (int)puVar13) / 0x1c + iVar5 != iVar5) {

        do {

          if ((*puVar13 == uVar10) && (puVar13[1] == local_24)) {

            uVar15 = puVar13[3];

            if (uVar15 < 2) {

              puVar13[uVar15 + 4] = (uint)param_3;

              *(bool *)(puVar13[3] + 0x18 + (int)puVar13) = bVar17;

              puVar13[3] = puVar13[3] + 1;

            }

            else {

              uVar15 = uVar15 + 1;

              pcVar18 = " faces. Result will be undefined";

              puVar13[3] = uVar15;

              pbVar9 = std::operator<<<struct_std::char_traits<char>_>

                                 ((basic_ostream<char,struct_std::char_traits<char>_> *)cout_exref,

                                  "An edge is shared by ");

              pbVar9 = std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<

                                 (pbVar9,uVar15);

              pbVar9 = std::operator<<<struct_std::char_traits<char>_>(pbVar9,pcVar18);

              std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(pbVar9,p_Var19);

            }

            goto LAB_005ecb62;

          }

          uVar15 = uVar15 + 1;

          puVar13 = puVar13 + 7;

        } while (uVar15 < (uint)((param_1[1] - *param_1) / 0x1c));

      }

      local_58 = operator_new(0x1c);

      if (local_58 == (uint *)0x0) {

        local_58 = (uint *)0x0;

      }

      else {

        local_58[1] = local_24;

        local_58[3] = 0;

        *local_58 = uVar10;

        local_58[4] = local_18;

        *(uint8_t *)(local_58 + 6) = local_10;

        local_58[5] = local_14;

        *(uint8_t *)((int)local_58 + 0x19) = local_f;

        *(uint8_t *)(local_58 + 2) = local_20;

      }

      p_Var19 = endl_exref;

      uVar15 = local_58[3];

      if (uVar15 < 2) {

        local_58[uVar15 + 4] = (uint)param_3;

        *(uint8_t *)((int)local_58 + local_58[3] + 0x18) = local_20;

        local_58[3] = local_58[3] + 1;

      }

      else {

        uVar15 = uVar15 + 1;

        pcVar18 = " faces. Result will be undefined";

        local_58[3] = uVar15;

        pbVar9 = std::operator<<<struct_std::char_traits<char>_>

                           ((basic_ostream<char,struct_std::char_traits<char>_> *)cout_exref,

                            "An edge is shared by ");

        pbVar9 = std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(pbVar9,uVar15);

        pbVar9 = std::operator<<<struct_std::char_traits<char>_>(pbVar9,pcVar18);

        std::basic_ostream<char,struct_std::char_traits<char>_>::operator<<(pbVar9,p_Var19);

      }

      if ((uint)param_1[2] <= (uint)param_1[1]) {

        iVar5 = *param_1;

        uVar15 = ((param_1[1] - iVar5) / 0x1c) * 2 + 2;

        if (iVar5 == 0) {

          uVar10 = 0;

        }

        else {

          uVar10 = (param_1[2] - iVar5) / 0x1c;

        }

        if (uVar10 < uVar15) {

          puVar6 = malloc(uVar15 * 0x1c);

          puVar8 = (uint32_t /* width from decompiler */ *)param_1[1];

          puVar3 = (uint32_t /* width from decompiler */ *)*param_1;

          puVar4 = puVar6;

          while (puVar3 != puVar8) {

            puVar7 = puVar3 + 7;

            puVar12 = puVar4 + 7;

            puVar14 = puVar3;

            puVar16 = puVar4;

            for (iVar5 = 7; puVar3 = puVar7, puVar4 = puVar12, iVar5 != 0; iVar5 = iVar5 + -1) {

              *puVar16 = *puVar14;

              puVar14 = puVar14 + 1;

              puVar16 = puVar16 + 1;

            }

          }

          if ((void *)*param_1 != (void *)0x0) {

            free((void *)*param_1);

          }

          param_1[2] = (int)(puVar6 + uVar15 * 7);

          param_1[1] = (int)(puVar6 + ((param_1[1] - *param_1) / 0x1c) * 7);

          *param_1 = (int)puVar6;

        }

      }

      puVar13 = (uint *)param_1[1];

      for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {

        *puVar13 = *local_58;

        local_58 = local_58 + 1;

        puVar13 = puVar13 + 1;

      }

      param_1[1] = param_1[1] + 0x1c;

LAB_005ecb62:

      uVar15 = uVar1;

    } while (uVar1 < 3);

    param_2 = (int *)((int)param_2 + 0xc);

    param_3 = (int *)((int)param_3 + 1);

    if (param_3 < uVar2) {

      uVar15 = 0;

      goto LAB_005ec8a0;

    }

  }

  ExceptionList = local_c;

  return param_1;

}
