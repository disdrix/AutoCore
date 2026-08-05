// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006c0b20
// -----------------------------------------------------------------------------
// Stable ID: aa_006c0b20
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x006c0b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_006bb1c0×2, FUN_006bb3a0×2, FUN_005b3370, FUN_006bd1c0, FUN_006c0850, FUN_006c0950, FUN_006c0b20.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

uint8_t *

Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006c0b20(uint8_t *param_1,int param_2,uint32_t /* width from decompiler */ *param_3,int param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  uint8_t uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint8_t *puVar7;

  uint8_t local_7d;

  char local_7c [4];

  uint32_t /* width from decompiler */ local_78;

  int local_74;

  uint local_70;

  uint local_6c;

  uint32_t /* width from decompiler */ local_68;

  uint32_t /* width from decompiler */ local_64;

  int local_60;

  uint32_t /* width from decompiler */ local_5c;

  uint32_t /* width from decompiler */ local_58;

  int local_54;

  uint8_t local_50 [16];

  uint8_t local_40 [16];

  uint8_t local_30 [16];

  uint8_t local_20 [28];

  

  local_78 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x14);

  local_7c[0] = '\0';

  local_5c = 0;

  local_58 = 0;

  local_54 = -0x80000000;

  local_68 = 0;

  local_64 = 0;

  local_60 = -0x80000000;

  local_74 = 0;

  local_70 = 0;

  local_6c = 0x80000000;

  if (0 < param_4) {

    do {

      if (local_70 == (local_6c & 0x7fffffff)) {

        FUN_005b3370(&local_74,0x10);

      }

      uVar2 = *param_3;

      uVar3 = param_3[1];

      uVar4 = param_3[2];

      uVar5 = param_3[3];

      puVar6 = (uint32_t /* width from decompiler */ *)(local_70 * 0x10 + local_74);

      local_70 = local_70 + 1;

      param_3 = param_3 + 4;

      param_4 = param_4 + -1;

      *puVar6 = uVar2;

      puVar6[1] = uVar3;

      puVar6[2] = uVar4;

      puVar6[3] = uVar5;

    } while (param_4 != 0);

  }

  FUN_006bb1c0(param_6,local_40,local_50);

  FUN_006bb1c0(&local_74,local_20,local_30);

  FUN_006bd1c0(&local_7d,param_2,param_5,param_6,&local_68,&local_5c,local_7c);

  if (local_7c[0] == '\0') {

    puVar7 = (uint8_t *)

             FUN_006c0950(&local_7d,&local_74,param_5,param_6,&local_68,&local_5c,local_78);

  }

  else {

    puVar7 = (uint8_t *)

             FUN_006c0850(&local_7d,&local_74,param_5,param_6,&local_68,&local_5c,local_78);

  }

  uVar1 = *puVar7;

  FUN_006bb3a0(param_6,local_40,local_50);

  FUN_006bb3a0(&local_74,local_20,local_30);

  *param_1 = uVar1;

  if (-1 < (int)local_6c) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_74,local_6c << 4,0x12);

  }

  if (-1 < local_60) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_68,local_60 << 4,0x12);

  }

  if (-1 < local_54) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_5c,local_54 << 5,0x12);

  }

  return param_1;

}
