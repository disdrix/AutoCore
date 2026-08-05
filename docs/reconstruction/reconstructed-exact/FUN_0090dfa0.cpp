// =============================================================================
// FUN_0090dfa0
// -----------------------------------------------------------------------------
// Stable ID: aa_0090dfa0
// Address:   0x0090dfa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090dfa0 @ 0x0090dfa0
// Stable ID: aa_0090dfa0
// Embedded strings (evidence for future rename):
//   - "Color"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0090dfa0.
//  - Strings: "Color".
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

void __thiscall

FUN_0090dfa0(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if ((char)param_3 != '\0') {

    *(uint8_t *)(param_1 + 0x508) = 1;

    iVar1 = (**(code **)(*param_2 + 0x10))();

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0xbc) = 0xffffffff;

    *(int *)(iVar1 + 0xb4) = *(int *)(iVar1 + 0xb4) + 1;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x90) = param_3;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x94) = param_4;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x98) = param_5;

    return;

  }

  *(uint8_t *)(param_1 + 0x508) = 0;

  uVar2 = (**(code **)(*(int *)param_2[0x23] + 0x40))("Color");

  (**(code **)(*(int *)param_2[0x23] + 0x4c))(uVar2,&stack0xffffffec);

  return;

}
