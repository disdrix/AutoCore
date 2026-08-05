// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_00604500, FUN_00604ab0, FUN_007a4480.
//  - Strings: "VOG_DEBUG_STOP".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_00604ab0
// -----------------------------------------------------------------------------
// Stable ID: aa_00604ab0
// Address:   0x00604ab0  (autoassault.exe, image base 0x400000)
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

void __thiscall Named_VOG_DEBUG_STOP_00604ab0(int *param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int local_18;

  uint32_t /* width from decompiler */ *local_14;

  int *local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a7ffb;

  local_c = ExceptionList;

  local_10 = param_1;

  if (*param_1 < 1) {

    if (0 < param_2) {

      local_18 = param_2;

      ExceptionList = &local_c;

      do {

        local_14 = operator_new(0x14);

        if (local_14 == (uint32_t /* width from decompiler */ *)0x0) {

          local_14 = (uint32_t /* width from decompiler */ *)0x0;

        }

        else {

          local_14[2] = 0;

          local_14[3] = 0;

          local_14[4] = 0;

          *local_14 = 0;

        }

        iVar1 = param_1[2];

        local_4 = 0xffffffff;

        if ((iVar1 == 0) || ((uint)(param_1[4] - iVar1 >> 2) <= (uint)(param_1[3] - iVar1 >> 2))) {

          FUN_00604500(param_1[3],1,&local_14);

        }

        else {

          puVar2 = (uint32_t /* width from decompiler */ *)param_1[3];

          *puVar2 = local_14;

          param_1[3] = (int)(puVar2 + 1);

        }

        local_18 = local_18 + -1;

      } while (local_18 != 0);

    }

    *local_10 = param_2;

    ExceptionList = local_c;

    return;

  }

  ExceptionList = &local_c;

  FUN_007a4480(0,"VOG_DEBUG_STOP");

  ExceptionList = local_c;

  return;

}
