// =============================================================================
// FUN_0058cc40
// -----------------------------------------------------------------------------
// Stable ID: aa_0058cc40
// Address:   0x0058cc40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058cc40 @ 0x0058cc40
// Stable ID: aa_0058cc40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: CONCAT22, Client_EnqueueCombatFloater_INFERRED, FUN_0058cc40.
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

int FUN_0058cc40(int *param_1,int *param_2,float param_3)



{

  int *piVar1;

  int iVar2;

  int iStack_38;

  int iStack_34;

  int iStack_30;

  int iStack_2c;

  int iStack_28;

  int iStack_24;

  int iStack_20;

  int iStack_1c;

  int iStack_18;

  uint8_t uStack_10;

  uint8_t uStack_f;

  uint8_t uStack_e;

  uint32_t /* width from decompiler */ uStack_8;

  

  if ((param_2 == (int *)0x0) && (param_1 != (int *)0x0)) {

    piVar1 = (int *)(**(code **)(*param_1 + 0x214))();

  }

  else {

    piVar1 = (int *)(**(code **)(*param_2 + 0x214))();

  }

  iVar2 = 0;

  if (piVar1 != (int *)0x0) {

    if ((param_3 <= g_flOne) && (DAT_00aaa668 <= param_3)) {

      param_3 = (float)(int)*(short *)((int)piVar1 + 0x12e) * param_3;

    }

    iVar2 = piVar1[0x4b];

    (**(code **)(*piVar1 + 0xac))

              ((int)param_3 + CONCAT22((short)((uint)param_1 >> 0x10),(short)iVar2));

    iVar2 = (int)(short)piVar1[0x4b] - (int)(short)iVar2;

  }

  piVar1 = param_1 + 0x58;

  if (param_1 == (int *)0x0) {

    piVar1 = &DAT_009d4d28;

  }

  iStack_38 = *piVar1;

  iStack_34 = piVar1[1];

  iStack_30 = piVar1[2];

  iStack_2c = piVar1[3];

  iStack_28 = param_2[0x58];

  iStack_24 = param_2[0x59];

  iStack_20 = param_2[0x5a];

  iStack_1c = param_2[0x5b];

  uStack_e = 0;

  uStack_f = 0;

  uStack_10 = 0;

  uStack_8 = 2;

  iStack_18 = iVar2;

  Client_EnqueueCombatFloater_INFERRED(&iStack_38);

  return iVar2;

}
