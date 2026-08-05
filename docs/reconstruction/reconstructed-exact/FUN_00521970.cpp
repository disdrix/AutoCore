// =============================================================================
// FUN_00521970
// -----------------------------------------------------------------------------
// Stable ID: aa_00521970
// Address:   0x00521970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00521970 @ 0x00521970
// Stable ID: aa_00521970
// Embedded strings (evidence for future rename):
//   - "Level"
//   - "%s, %s %i"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_007a69d0×3, FUN_007a6de0×3, FUN_0051f940×2, sprintf×2, FUN_00521970.
//  - Strings: "Level"; "%s, %s %i".
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

void __thiscall FUN_00521970(int param_1,char *param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  

  FUN_007a69d0();

  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x27c))();

  if (-1 < iVar1) {

    iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);

    uVar4 = 0xffffffff;

    uVar2 = FUN_0051f940(*(uint8_t *)(iVar1 + 0x531),*(uint8_t *)(iVar1 + 0x532),0xffffffff);

    FUN_007a69d0(uVar2);

    uVar2 = FUN_007a6de0(uVar2,uVar4);

    uVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x27c))();

    uVar3 = FUN_007a6de0("Level",0xffffffff);

    sprintf(param_2,"%s, %s %i",uVar2,uVar3,uVar4);

    return;

  }

  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);

  uVar4 = 0xffffffff;

  uVar2 = FUN_0051f940(*(uint8_t *)(iVar1 + 0x531),*(uint8_t *)(iVar1 + 0x532),0xffffffff);

  FUN_007a69d0(uVar2);

  uVar2 = FUN_007a6de0(uVar2,uVar4);

  sprintf(param_2,"%s",uVar2);

  return;

}
