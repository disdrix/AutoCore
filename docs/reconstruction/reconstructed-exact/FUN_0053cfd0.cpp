// =============================================================================
// FUN_0053cfd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0053cfd0
// Address:   0x0053cfd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053cfd0 @ 0x0053cfd0
// Stable ID: aa_0053cfd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: fwrite×2, FUN_0053cfd0, FUN_00567ce0.
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

uint32_t /* width from decompiler */ __thiscall FUN_0053cfd0(int param_1,FILE *param_2)



{

  int iVar1;

  int iVar2;

  code *pcVar3;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  

  if (param_2 == (FILE *)0x0) {

    return 0;

  }

  (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + -0x4c + param_1) + 0xac))(param_2)

  ;

  pcVar3 = fwrite_exref;

  iVar1 = *(int *)(param_1 + -0x48);

  if (iVar1 == 0) {

    uStack_44 = 0;

    uStack_40 = 0;

    uStack_3c = 0;

    uStack_38 = 0;

    FUN_00567ce0(&DAT_00af2460,0x38d1b717);

    pcVar3 = fwrite_exref;

    uStack_34 = uStack_24;

    uStack_30 = uStack_20;

    uStack_2c = uStack_1c;

    uStack_28 = uStack_18;

    fwrite(&uStack_44,0x10,1,param_2);

  }

  else {

    iVar2 = *(int *)(iVar1 + 0x3c);

    uStack_44 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xb0);

    uStack_40 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xb4);

    uStack_3c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xb8);

    uStack_38 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0xbc);

    iVar1 = *(int *)(iVar1 + 0x3c);

    uStack_34 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x30);

    uStack_30 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    uStack_2c = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x38);

    uStack_28 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x3c);

    fwrite(&uStack_44,0x10,1,param_2);

  }

  (*pcVar3)(&uStack_34,0x10,1,param_2);

  (*pcVar3)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + 0x6c + param_1,4,1,param_2);

  (*pcVar3)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + 0x70 + param_1,4,1,param_2);

  (*pcVar3)(&stack0xffffffbb,1,1,param_2);

  return 1;

}
