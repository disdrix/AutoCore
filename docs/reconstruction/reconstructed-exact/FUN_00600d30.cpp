// =============================================================================
// FUN_00600d30
// -----------------------------------------------------------------------------
// Stable ID: aa_00600d30
// Address:   0x00600d30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00600d30 @ 0x00600d30
// Stable ID: aa_00600d30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_006a3db0×7, CONCAT22×5, ceil×4, floor×4, FUN_00600d30.
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

uint __thiscall FUN_00600d30(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3,char param_4)



{

  short sVar1;

  uint in_EAX;

  uint16_t extraout_var;

  uint16_t extraout_var_00;

  uint16_t extraout_var_01;

  float unaff_EBX;

  float unaff_ESI;

  float unaff_EDI;

  int iVar2;

  float fStack_1c;

  

  if (param_3 != (int *)0x0) {

    sVar1 = (short)param_3[0x50];

    if (199 < sVar1) {

      sVar1 = 200;

    }

    if (param_4 == '\0') {

      (**(code **)(*param_3 + 0x98))(CONCAT22(sVar1 >> 0xf,*(short *)(param_1 + 0xa0)));

      iVar2 = *param_3;

      ceil((double)(fStack_1c * *(float *)(param_1 + 0xa8) - fStack_1c));

      FUN_006a3db0();

      (**(code **)(iVar2 + 0x98))();

      (**(code **)(*param_3 + 0x94))(CONCAT22(extraout_var,*(uint16_t *)(param_1 + 0xa6)));

      iVar2 = *param_3;

      ceil((double)(unaff_EBX * *(float *)(param_1 + 0xb4) - unaff_EBX));

      FUN_006a3db0();

      (**(code **)(iVar2 + 0x94))();

      (**(code **)(*param_3 + 0xa0))(CONCAT22(extraout_var_00,*(uint16_t *)(param_1 + 0xa2)));

      iVar2 = *param_3;

      ceil((double)(unaff_ESI * *(float *)(param_1 + 0xac)));

      FUN_006a3db0();

      (**(code **)(iVar2 + 0xa0))();

      (**(code **)(*param_3 + 0x9c))(CONCAT22(extraout_var_01,*(uint16_t *)(param_1 + 0xa4)));

      iVar2 = *param_3;

      ceil((double)(unaff_EDI * *(float *)(param_1 + 0xb0) - unaff_EDI));

    }

    else {

      (**(code **)(*param_3 + 0x98))(CONCAT22(sVar1 >> 0xf,-*(short *)(param_1 + 0xa0)));

      iVar2 = *param_3;

      floor((double)(fStack_1c - fStack_1c * *(float *)(param_1 + 0xa8)));

      FUN_006a3db0();

      (**(code **)(iVar2 + 0x98))();

      (**(code **)(*param_3 + 0x94))(-*(short *)(param_1 + 0xa6));

      iVar2 = *param_3;

      floor((double)(unaff_EBX - unaff_EBX * *(float *)(param_1 + 0xb4)));

      FUN_006a3db0();

      (**(code **)(iVar2 + 0x94))();

      (**(code **)(*param_3 + 0xa0))(-*(short *)(param_1 + 0xa2));

      iVar2 = *param_3;

      floor((double)(unaff_ESI - unaff_ESI * *(float *)(param_1 + 0xac)));

      FUN_006a3db0();

      (**(code **)(iVar2 + 0xa0))();

      (**(code **)(*param_3 + 0x9c))(-*(short *)(param_1 + 0xa4));

      iVar2 = *param_3;

      floor((double)(unaff_EDI - unaff_EDI * *(float *)(param_1 + 0xb0)));

    }

    FUN_006a3db0();

    in_EAX = (**(code **)(iVar2 + 0x9c))();

  }

  return in_EAX & 0xffffff00;

}
