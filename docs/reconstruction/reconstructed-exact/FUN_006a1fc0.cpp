// =============================================================================
// FUN_006a1fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_006a1fc0
// Address:   0x006a1fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a1fc0 @ 0x006a1fc0
// Stable ID: aa_006a1fc0
// Embedded strings (evidence for future rename):
//   - "malformed general branch information"
//   - "malformed branch data"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~201 non-empty decompiler lines.
//  - Control keywords: if×20, return×12, do×1, switch×1, while×1.
//  - Notable callees: FUN_006902a0×9, FUN_006a1100×9, FUN_00699ed0×5, FUN_00699ee0×5, FUN_006874b0×2, _CxxThrowException×2, FUN_006a1cf0, FUN_006a1fc0.
//  - Strings: "malformed general branch information"; "malformed branch data".
//  - Return sites: 12.

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

uint32_t /* width from decompiler */ * FUN_006a1fc0(int *param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  float10 fVar6;

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_94 [28];

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_78 [28];

  uint8_t local_5c [40];

  uint8_t local_34 [40];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ab2c3;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pvVar1 = operator_new(0x74);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    puVar2 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_006a1cf0();

  }

  local_4 = 0xffffffff;

  iVar3 = FUN_00699ee0();

  if (iVar3 == 0x3f8) {

    iVar3 = FUN_00699ee0();

    do {

      switch(iVar3) {

      case 6000:

        pvVar4 = (void *)FUN_006902a0();

        pvVar1 = (void *)puVar2[0x14];

        if (pvVar1 != pvVar4) {

          if (pvVar1 != (void *)0x0) {

            FUN_006a1100();

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar1);

          }

          puVar2[0x14] = pvVar4;

        }

        break;

      case 0x1771:

        pvVar4 = (void *)FUN_006902a0();

        pvVar1 = (void *)puVar2[0x15];

        if (pvVar1 != pvVar4) {

          if (pvVar1 != (void *)0x0) {

            FUN_006a1100();

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar1);

          }

          puVar2[0x15] = pvVar4;

        }

        break;

      case 0x1772:

        pvVar4 = (void *)FUN_006902a0();

        pvVar1 = (void *)puVar2[0x16];

        if (pvVar1 != pvVar4) {

          if (pvVar1 != (void *)0x0) {

            FUN_006a1100();

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar1);

          }

          puVar2[0x16] = pvVar4;

        }

        break;

      case 0x1773:

        pvVar4 = (void *)FUN_006902a0();

        pvVar1 = (void *)puVar2[0x17];

        if (pvVar1 != pvVar4) {

          if (pvVar1 != (void *)0x0) {

            FUN_006a1100();

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar1);

          }

          puVar2[0x17] = pvVar4;

        }

        break;

      case 0x1774:

        pvVar4 = (void *)FUN_006902a0();

        pvVar1 = (void *)puVar2[0x18];

        if (pvVar1 != pvVar4) {

          if (pvVar1 != (void *)0x0) {

            FUN_006a1100();

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar1);

          }

          puVar2[0x18] = pvVar4;

        }

        break;

      case 0x1775:

        pvVar4 = (void *)FUN_006902a0();

        pvVar1 = (void *)puVar2[0x19];

        if (pvVar1 != pvVar4) {

          if (pvVar1 != (void *)0x0) {

            FUN_006a1100();

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar1);

          }

          puVar2[0x19] = pvVar4;

        }

        break;

      case 0x1776:

        pvVar4 = (void *)FUN_006902a0();

        pvVar1 = (void *)puVar2[0x1a];

        if (pvVar1 != pvVar4) {

          if (pvVar1 != (void *)0x0) {

            FUN_006a1100();

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar1);

          }

          puVar2[0x1a] = pvVar4;

        }

        break;

      case 0x1777:

        pvVar4 = (void *)FUN_006902a0();

        pvVar1 = (void *)puVar2[0x1b];

        if (pvVar1 != pvVar4) {

          if (pvVar1 != (void *)0x0) {

            FUN_006a1100();

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar1);

          }

          puVar2[0x1b] = pvVar4;

        }

        break;

      case 0x1778:

        uVar5 = FUN_00699ee0();

        *puVar2 = uVar5;

        break;

      case 0x1779:

        uVar5 = FUN_00699ee0();

        puVar2[1] = uVar5;

        break;

      case 0x177a:

        fVar6 = (float10)FUN_00699ed0();

        puVar2[2] = (float)fVar6;

        break;

      case 0x177b:

        fVar6 = (float10)FUN_00699ed0();

        puVar2[3] = (float)fVar6;

        break;

      case 0x177c:

        fVar6 = (float10)FUN_00699ed0();

        puVar2[4] = (float)fVar6;

        break;

      case 0x177d:

        fVar6 = (float10)FUN_00699ed0();

        puVar2[5] = (float)fVar6;

        break;

      case 0x177e:

        fVar6 = (float10)FUN_00699ed0();

        puVar2[6] = (float)fVar6;

        break;

      case 0x177f:

        iVar3 = *param_1;

        *param_1 = iVar3 + 1;

        *(bool *)(puVar2 + 7) = *(char *)(param_1[2] + iVar3) != '\0';

        break;

      case 0x1780:

        iVar3 = *param_1;

        *param_1 = iVar3 + 1;

        *(bool *)((int)puVar2 + 0x1d) = *(char *)(param_1[2] + iVar3) != '\0';

        break;

      case 0x1781:

        pvVar4 = (void *)FUN_006902a0();

        pvVar1 = (void *)puVar2[0x1c];

        if (pvVar1 != pvVar4) {

          if (pvVar1 != (void *)0x0) {

            FUN_006a1100();

                    /* WARNING: Subroutine does not return */

            operator_delete(pvVar1);

          }

          puVar2[0x1c] = pvVar4;

        }

        break;

      default:

        std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

        basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  (local_94,"malformed general branch information");

        local_4 = 2;

        FUN_006874b0(local_94,0);

                    /* WARNING: Subroutine does not return */

        _CxxThrowException(local_34,(ThrowInfo *)&DAT_00ac9e00);

      }

      iVar3 = FUN_00699ee0();

    } while (iVar3 != 0x3f9);

    ExceptionList = local_c;

    return puVar2;

  }

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::

  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

            (local_78,"malformed branch data");

  local_4 = 1;

  FUN_006874b0(local_78,0);

                    /* WARNING: Subroutine does not return */

  _CxxThrowException(local_5c,(ThrowInfo *)&DAT_00ac9e00);

}
