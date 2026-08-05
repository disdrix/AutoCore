// =============================================================================
// FUN_00583fa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00583fa0
// Address:   0x00583fa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00583fa0 @ 0x00583fa0
// Stable ID: aa_00583fa0
// Embedded strings (evidence for future rename):
//   - "ForceLoaded child <%s>"
//   - "CVOGGraphicsBase::LoadNextChildAsset() - loading asset <%s> resulted in error code(%d)"
//   - ".dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~154 non-empty decompiler lines.
//  - Control keywords: if×17, do×7, while×7, return×3, goto×2.
//  - Notable callees: FUN_0075d610×3, FUN_007a4480×2, FUN_007a6880×2, FUN_007a69d0×2, CVOGGraphicsBase::LoadNextChildAsset, FUN_004eb1c0, FUN_00581e20, FUN_00583fa0.
//  - Strings: "ForceLoaded child <%s>"; ".dds".
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __fastcall FUN_00583fa0(int param_1)



{

  char *pcVar1;

  int *piVar2;

  uint8_t uVar3;

  char cVar4;

  int iVar5;

  char *pcVar6;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *this;

  undefined *puVar7;

  uint uVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ *puVar10;

  int local_3c;

  int local_38;

  uint8_t local_34 [4];

  int local_30;

  int local_2c;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a5459;

  local_c = ExceptionList;

  if (*(int *)(DAT_00d1f050 + 100) != 0) {

    ExceptionList = &local_c;

    local_38 = param_1;

    FUN_004eb1c0(&local_3c);

    cVar4 = FUN_0075d610(&local_3c);

    if (cVar4 == '\0') {

      iVar5 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1);

      local_30 = iVar5 + 0x110;

      local_2c = *(int *)(iVar5 + 0x120) + *(int *)(iVar5 + 0x11c);

      do {

        iVar5 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1);

        if ((local_30 == iVar5 + 0x110) && (local_2c == *(int *)(iVar5 + 0x11c))) {

          ExceptionList = local_c;

          return 0;

        }

        uVar8 = local_2c - 1U >> 2;

        iVar5 = uVar8 * -4;

        if (*(uint *)(local_30 + 8) <= uVar8) {

          uVar8 = uVar8 - *(uint *)(local_30 + 8);

        }

        piVar2 = (int *)(*(int *)(*(int *)(local_30 + 4) + uVar8 * 4) +

                        ((local_2c - 1U) + iVar5) * 4);

        FUN_007a69d0();

        iVar5 = FUN_007a6880();

        if (iVar5 == 0) {

LAB_005841c6:

          cVar4 = FUN_0075d610(piVar2);

          if ((cVar4 == '\0') && (local_3c != *piVar2)) {

            iVar5 = FUN_00581e20(piVar2);

            if (iVar5 == 0) {

              puVar7 = (undefined *)*piVar2;

              if ((undefined *)*piVar2 == (undefined *)0x0) {

                puVar7 = PTR_DAT_00afa2bc;

              }

              FUN_007a4480(0xffffffff,"ForceLoaded child <%s>",puVar7);

              ExceptionList = local_c;

              return 1;

            }

            if (iVar5 != 99999) {

              this = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *

                     )FUN_0096a630(local_28);

              local_4 = 0;

              pcVar6 = std::

                       basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                       ::c_str(this);

              FUN_007a4480(0,

                           "CVOGGraphicsBase::LoadNextChildAsset() - loading asset <%s> resulted in error code(%d)"

                           ,pcVar6,iVar5);

              local_4 = 0xffffffff;

              std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

              ~basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                        (local_28);

            }

          }

        }

        else {

          pcVar6 = (char *)*piVar2;

          if ((char *)*piVar2 == (char *)0x0) {

            pcVar6 = PTR_DAT_00afa2bc;

          }

          pcVar6 = strstr(pcVar6,".dds");

          puVar7 = PTR_DAT_00afa2bc;

          if (pcVar6 == (char *)0x0) goto LAB_005841c6;

          pcVar6 = (char *)*piVar2;

          if ((char *)*piVar2 == (char *)0x0) {

            pcVar6 = PTR_DAT_00afa2bc;

          }

          iVar5 = (int)&DAT_00b04cb8 - (int)pcVar6;

          do {

            cVar4 = *pcVar6;

            pcVar6[iVar5] = cVar4;

            pcVar6 = pcVar6 + 1;

          } while (cVar4 != '\0');

          pcVar6 = (char *)*piVar2;

          if ((char *)*piVar2 == (char *)0x0) {

            pcVar6 = puVar7;

          }

          pcVar1 = pcVar6 + 1;

          do {

            cVar4 = *pcVar6;

            pcVar6 = pcVar6 + 1;

          } while (cVar4 != '\0');

          (&DAT_00b04cb4)[(int)pcVar6 - (int)pcVar1] = 0;

          FUN_007a69d0();

          iVar5 = FUN_007a6880();

          if (iVar5 == 1) {

            puVar9 = (uint32_t /* width from decompiler */ *)0xb04cb7;

            do {

              pcVar6 = (char *)((int)puVar9 + 1);

              puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

            } while (*pcVar6 != '\0');

            *puVar9 = DAT_00a9d99c;

          }

          else if (iVar5 == 2) {

            puVar9 = (uint32_t /* width from decompiler */ *)0xb04cb7;

            do {

              pcVar6 = (char *)((int)puVar9 + 1);

              puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

            } while (*pcVar6 != '\0');

            *puVar9 = DAT_00a9d998;

          }

          else if (iVar5 == 3) {

            puVar9 = (uint32_t /* width from decompiler */ *)0xb04cb7;

            do {

              pcVar6 = (char *)((int)puVar9 + 1);

              puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

            } while (*pcVar6 != '\0');

            *puVar9 = DAT_00a9d9a0;

          }

          uVar3 = DAT_00a2c540;

          puVar9 = (uint32_t /* width from decompiler */ *)0xb04cb7;

          do {

            puVar10 = puVar9;

            puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

          } while (*(char *)((int)puVar10 + 1) != '\0');

          *(uint32_t /* width from decompiler */ *)((int)puVar10 + 1) = DAT_00a2c53c;

          *(uint8_t *)((int)puVar10 + 5) = uVar3;

          FUN_00989e00(local_34,&DAT_00b04cb8);

          cVar4 = FUN_0075d610(local_34);

          param_1 = local_38;

          if (cVar4 == '\0') goto LAB_005841c6;

        }

        local_2c = local_2c + -1;

      } while( true );

    }

  }

  ExceptionList = local_c;

  return 0;

}
