// =============================================================================
// FUN_0044d210
// -----------------------------------------------------------------------------
// Stable ID: aa_0044d210
// Address:   0x0044d210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044d210 @ 0x0044d210
// Stable ID: aa_0044d210
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_00746810×2, FUN_0044d210, FUN_0044d2b0.
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

void __thiscall

FUN_0044d210(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar1 = param_1;

  while( true ) {

    iVar4 = iVar1 * 2 + 2;

    if (param_3 <= iVar4) break;

    iVar2 = FUN_00746810();

    iVar3 = FUN_00746810();

    if (iVar2 < iVar3) {

      iVar4 = iVar1 * 2 + 1;

    }

    *(uint32_t /* width from decompiler */ *)(param_2 + iVar1 * 8) = *(uint32_t /* width from decompiler */ *)(param_2 + iVar4 * 8);

    *(uint32_t /* width from decompiler */ *)(param_2 + 4 + iVar1 * 8) = *(uint32_t /* width from decompiler */ *)(param_2 + 4 + iVar4 * 8);

    iVar1 = iVar4;

  }

  if (iVar4 == param_3) {

    *(uint32_t /* width from decompiler */ *)(param_2 + iVar1 * 8) = *(uint32_t /* width from decompiler */ *)(param_2 + -8 + param_3 * 8);

    *(uint32_t /* width from decompiler */ *)(param_2 + 4 + iVar1 * 8) = *(uint32_t /* width from decompiler */ *)(param_2 + -4 + param_3 * 8);

  }

  FUN_0044d2b0(param_2,param_1,param_4,param_5,param_6);

  return;

}
