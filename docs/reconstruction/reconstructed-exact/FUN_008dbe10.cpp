// =============================================================================
// FUN_008dbe10
// -----------------------------------------------------------------------------
// Stable ID: aa_008dbe10
// Address:   0x008dbe10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008dbe10 @ 0x008dbe10
// Stable ID: aa_008dbe10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, goto×2.
//  - Notable callees: FUN_007a69d0, FUN_007a6de0, FUN_008aab00, FUN_008dbe10.
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

void __thiscall FUN_008dbe10(int param_1,int param_2)



{

  int iVar1;

  char *pcVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  if (*(int *)(param_1 + 0x580) == 0) {

    return;

  }

  if (param_2 < 0) {

    return;

  }

  if (0x31 < param_2) {

    return;

  }

  FUN_007a69d0();

  if (param_2 == 0x30) {

    if (DAT_00d1b6d8 == 0) goto LAB_008dbf34;

    (**(code **)(**(int **)(param_1 + 0x580) + 0x1d8))(0,1,1);

    uVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x580);

    pcVar2 = "Shield generators are standard on all Human vehicles, providing a constantly regenerating damage buffer.  Keep an eye on the thin blue shield gauge next to your green HP gauge.  Later you will be able to upgrade your vehicle with Hazard Mode enabled shields, and launch devestating shield inversion attacks on your enemies."

             + (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +

                                                DAT_00d1b6d8) + 0x3c) + 0x532) * 0x200;

  }

  else if (param_2 == 0x31) {

    if (DAT_00d1b6d8 == 0) goto LAB_008dbf34;

    (**(code **)(**(int **)(param_1 + 0x580) + 0x1d8))(0,1,1);

    iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac + DAT_00d1b6d8) + 0x3c

                    );

    uVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x580);

    pcVar2 = "Commandos begin their career with 1 skill rank in Defense Grid.  This activates a short term shield grid boost around your vehicle that reduces damage from a variety of possible sources.  By default, this is mapped to the #1 slot in your QuickBar.  Left-Click that button or use the [$key]QuickBar 1[$/key] key to use the skill."

             + ((uint)*(byte *)(iVar1 + 0x531) + (uint)*(byte *)(iVar1 + 0x532) * 4) * 0x200;

  }

  else {

    (**(code **)(**(int **)(param_1 + 0x580) + 0x1d8))(0,1,1);

    uVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x580);

    pcVar2 = &DAT_00a15f10 + param_2 * 0x200;

  }

  FUN_007a6de0(pcVar2,0xffffffff);

  FUN_008aab00(uVar3);

LAB_008dbf34:

  (**(code **)(**(int **)(param_1 + 0x580) + 0x34c))();

  return;

}
