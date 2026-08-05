// =============================================================================
// FUN_004c4930
// -----------------------------------------------------------------------------
// Stable ID: aa_004c4930
// Address:   0x004c4930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c4930 @ 0x004c4930
// Stable ID: aa_004c4930
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004bc180×2, FUN_004c4930.
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

void __thiscall FUN_004c4930(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int iVar2;

  

  if (*(int *)(param_1 + -0x2b0) != 0) {

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x2b0) + 4) + 4) + 4 +

                         *(int *)(param_1 + -0x2b0)) + 0x2a4))(param_2);

  }

  iVar1 = *(int *)(*(int *)(param_1 + -0x4fc) + 4);

  iVar2 = iVar1 + param_1;

  iVar2 = CVOGReaction_ResolveObjectTarget

                    (*(uint8_t *)(iVar2 + -0x394),*(uint32_t /* width from decompiler */ *)(iVar1 + -0x39c + param_1),

                     *(uint32_t /* width from decompiler */ *)(iVar2 + -0x398));

  if (iVar2 == 0) {

    if (param_1 == 0x500) {

      FUN_004bc180(0);

      return;

    }

    FUN_004bc180(*(int *)(*(int *)(param_1 + -0x4fc) + 4) + -0x4fc + param_1);

  }

  return;

}
