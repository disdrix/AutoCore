// =============================================================================
// FUN_00521f20
// -----------------------------------------------------------------------------
// Stable ID: aa_00521f20
// Address:   0x00521f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00521f20 @ 0x00521f20
// Stable ID: aa_00521f20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: return×3, if×2, switch×1.
//  - Notable callees: FUN_00521eb0, FUN_00521f20.
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

float10 __thiscall FUN_00521f20(int param_1,int *param_2,int param_3)



{

  char cVar1;

  int iVar2;

  byte extraout_DL;

  float local_4;

  

  if (0 < *(int *)(param_1 + 0x6b4)) {

    return (float10)g_flOne;

  }

  local_4 = 0.0;

  cVar1 = (**(code **)(*param_2 + 0x8c))();

  iVar2 = FUN_00521eb0();

  if ((int)(uint)(byte)(cVar1 + 1) <= iVar2) {

    switch((uint)(byte)(cVar1 + 1)) {

    case 1:

      local_4 = DAT_00a0f720;

      break;

    case 2:

      local_4 = DAT_00a0f728;

      break;

    case 3:

      local_4 = g_flOverheatCoolFrac;

      break;

    case 4:

      local_4 = DAT_00a0f704;

      break;

    case 5:

      local_4 = DAT_009ceea8;

    }

    return (float10)(int)(short)((ushort)*(byte *)(param_1 + 0x59b) + (ushort)extraout_DL * -2 +

                                *(short *)(param_3 + 0xb0)) * (float10)DAT_00aaa8f4 +

           (float10)local_4;

  }

  return (float10)g_flZero;

}
