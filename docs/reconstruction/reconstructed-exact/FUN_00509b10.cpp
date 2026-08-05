// =============================================================================
// FUN_00509b10
// -----------------------------------------------------------------------------
// Stable ID: aa_00509b10
// Address:   0x00509b10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00509b10 @ 0x00509b10
// Stable ID: aa_00509b10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×9, return×4, do×1, while×1.
//  - Notable callees: FUN_004073a0, FUN_00509b10, FUN_005e0580, FUN_005e1150.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */

FUN_00509b10(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5)



{

  short sVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  void **ppvVar5;

  void *pvStack_1c;

  uint *local_18;

  int local_14;

  void *local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a3288;

  pvStack_c = ExceptionList;

  uVar4 = 0;

  local_18 = (uint *)0x0;

  local_14 = 0;

  local_10 = (void *)0x0;

  local_4 = 0;

  ExceptionList = &pvStack_c;

  iVar2 = (**(code **)(*param_1 + 0x60))();

  if (iVar2 != 0) {

    do {

      uVar3 = (**(code **)(*param_1 + 0x5c))(uVar4);

      if ((uVar3 & 0xffff) != 0xffffffff) {

        uVar3 = (**(code **)(*param_1 + 0x5c))(uVar4);

        if ((pvStack_1c == (void *)0x0) ||

           ((uint)(local_14 - (int)pvStack_1c >> 2) <= (uint)((int)local_18 - (int)pvStack_1c >> 2))

           ) {

          FUN_004073a0(local_18,1,&stack0x00000000);

        }

        else {

          *local_18 = uVar3 & 0xffff;

          local_18 = local_18 + 1;

        }

      }

      uVar4 = uVar4 + 1;

      uVar3 = (**(code **)(*param_1 + 0x60))();

    } while (uVar4 < uVar3);

  }

  iVar2 = *(int *)(param_1[0x2a] + 0x38);

  if (iVar2 == 6) {

    sVar1 = *(short *)(*(int *)(param_1[0x2a] + 0x3c) + 0x3f4);

    if (sVar1 == 10) {

      iVar2 = 0x44;

    }

    else if (sVar1 == 0xb) {

      iVar2 = 0x46;

    }

  }

  ppvVar5 = &pvStack_1c;

  FUN_005e0580(iVar2,param_2,param_3,param_4,ppvVar5,param_5);

  iVar2 = FUN_005e1150(iVar2,param_2,param_3,param_4,ppvVar5,param_5);

  if (iVar2 < 0) {

    if (local_18 == (uint *)0x0) {

      ExceptionList = pvStack_c;

      return 0;

    }

                    /* WARNING: Subroutine does not return */

    operator_delete(local_18);

  }

  (**(code **)(*param_1 + 0x54))(iVar2);

  if (pvStack_1c == (void *)0x0) {

    ExceptionList = local_10;

    return 1;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvStack_1c);

}
