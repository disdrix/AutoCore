// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×16, return×5, goto×1.
//  - Notable callees: Client_UnpackSpecialMessage, EMSG_Sector_Damage_Unpack, FUN_006374f0, FUN_00637990, TNL_ByteBuffer_UnpackData.
//  - Return sites: 5.

// =============================================================================
// Client_UnpackSpecialMessage
// -----------------------------------------------------------------------------
// Stable ID: aa_00637c20
// Address:   0x00637c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

uint32_t /* width from decompiler */ * Client_UnpackSpecialMessage(uint32_t /* width from decompiler */ *param_1,uint param_2,int *param_3)



{

  int *piVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint local_4;

  

  puStack_8 = &LAB_009a8e13;

  local_c = ExceptionList;

  local_4 = 1;

  if (param_2 < 0x206d) {

    if (param_2 == 0x206c) {

      ExceptionList = &local_c;

      if (param_3 != (int *)0x0) {

        ExceptionList = &local_c;

        param_3[2] = param_3[2] + 1;

      }

      FUN_006374f0(param_1);

    }

    else {

      if (param_2 == 0x2005) {

        ExceptionList = &local_c;

        if (param_3 != (int *)0x0) {

          ExceptionList = &local_c;

          param_3[2] = param_3[2] + 1;

        }

        FUN_00637990(param_1);

        local_4 = local_4 & 0xffffff00;

        if (param_3 == (int *)0x0) {

          ExceptionList = local_c;

          return param_1;

        }

        piVar1 = param_3 + 2;

        *piVar1 = *piVar1 + -1;

        if (*piVar1 != 0) {

          ExceptionList = local_c;

          return param_1;

        }

        (**(code **)(*param_3 + 8))();

        ExceptionList = local_c;

        return param_1;

      }

      if (param_2 != 0x2023) goto LAB_00637d12;

      ExceptionList = &local_c;

      if (param_3 != (int *)0x0) {

        ExceptionList = &local_c;

        param_3[2] = param_3[2] + 1;

      }

      EMSG_Sector_Damage_Unpack(param_1);

    }

  }

  else {

    if (param_2 != 0x804d) {

LAB_00637d12:

      ExceptionList = &local_c;

      *param_1 = param_3;

      if (param_3 != (int *)0x0) {

        param_3[2] = param_3[2] + 1;

      }

      local_4 = 0;

      if (param_3 != (int *)0x0) {

        piVar1 = param_3 + 2;

        *piVar1 = *piVar1 + -1;

        if (*piVar1 == 0) {

          (**(code **)(*param_3 + 8))();

        }

      }

      ExceptionList = local_c;

      return param_1;

    }

    ExceptionList = &local_c;

    if (param_3 != (int *)0x0) {

      ExceptionList = &local_c;

      param_3[2] = param_3[2] + 1;

    }

    TNL_ByteBuffer_UnpackData(param_1);

  }

  local_4 = local_4 & 0xffffff00;

  if (param_3 != (int *)0x0) {

    piVar1 = param_3 + 2;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*param_3 + 8))();

    }

  }

  ExceptionList = local_c;

  return param_1;

}
