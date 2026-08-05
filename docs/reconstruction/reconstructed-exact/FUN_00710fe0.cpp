// =============================================================================
// FUN_00710fe0
// -----------------------------------------------------------------------------
// Stable ID: aa_00710fe0
// Address:   0x00710fe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00710fe0 @ 0x00710fe0
// Stable ID: aa_00710fe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: CONCAT22×4, CONCAT31, FUN_00710fe0, FUN_007110f0, FUN_00712650, FUN_00712740, FUN_00712800, FUN_00712810.
//  - Return sites: 2.

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

uint FUN_00710fe0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  short sVar1;

  uint16_t uVar2;

  uint16_t extraout_var;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint uVar5;

  uint16_t extraout_var_00;

  uint16_t extraout_var_01;

  uint16_t extraout_var_02;

  float10 fVar6;

  float10 fVar7;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = param_2;

  fVar6 = (float10)FUN_00712800(*(uint32_t /* width from decompiler */ *)(param_1 + 8));

  sVar1 = *(short *)(param_1 + 0x16);

  if (*(short *)(param_1 + 0x18) == 0) {

    *(uint16_t *)(param_1 + 0x18) = 1;

  }

  if (*(short *)(param_1 + 0x1a) == 0) {

    *(uint16_t *)(param_1 + 0x1a) = 0x5a;

  }

  fVar7 = (float10)FUN_007110f0(param_2);

  FUN_007128b0(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 4));

  FUN_00712910((float)fVar7,(float)fVar6,CONCAT22(extraout_var_01,*(uint16_t *)(param_1 + 0x18)),

               *(uint32_t /* width from decompiler */ *)(param_1 + 4));

  FUN_00712980(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 4));

  uVar2 = FUN_00712b90((float)fVar7,CONCAT22(extraout_var_00,*(uint16_t *)(param_1 + 0x18)),

                       CONCAT22(extraout_var,*(uint16_t *)(param_1 + 0x1a)),

                       *(uint32_t /* width from decompiler */ *)(param_1 + 4));

  *(uint16_t *)(param_1 + 0x1c) = uVar2;

  iVar3 = FUN_00712c20(*(uint32_t /* width from decompiler */ *)(param_1 + 4),-1 < sVar1,param_3);

  if (iVar3 == 0) {

    uVar5 = FUN_00712810(*(uint32_t /* width from decompiler */ *)(param_1 + 8));

  }

  else {

    uVar4 = ftol();

    uVar4 = FUN_00712740(uVar4);

    uVar5 = CONCAT31((int3)((uint)uVar4 >> 8),*(char *)(param_1 + 0x1e));

    if (*(char *)(param_1 + 0x1e) != '\0') {

      uVar5 = FUN_00712650(*(uint32_t /* width from decompiler */ *)(param_1 + 8),

                           CONCAT22(extraout_var_02,*(uint16_t *)(param_1 + 0x16)));

      *(short *)(param_1 + 0x14) = (short)uVar5;

      return uVar5 & 0xffff0000;

    }

  }

  return uVar5 & 0xffff0000;

}
