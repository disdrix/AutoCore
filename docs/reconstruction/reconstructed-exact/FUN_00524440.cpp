// =============================================================================
// FUN_00524440
// -----------------------------------------------------------------------------
// Stable ID: aa_00524440
// Address:   0x00524440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00524440 @ 0x00524440
// Stable ID: aa_00524440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004baec0, FUN_00524440.
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

uint32_t /* width from decompiler */ __thiscall FUN_00524440(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  uint uVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  uVar3 = *(uint *)(param_1 + 8);

  uVar4 = *(uint *)(param_1 + 0xc);

  if (((uVar3 & uVar4) == 0xffffffff) || (uVar3 == 0 && uVar4 == 0)) {

    *param_2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

    param_2[1] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

    param_2[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

  }

  else {

    iVar5 = FUN_004baec0(1,uVar3,uVar4);

    if (iVar5 != 0) {

      if (*(int *)(iVar5 + 8) == 0) {

        puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar5 + 4) + 4) + 0x84 + iVar5);

      }

      else {

        puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar5 + 8) + 0x3c) + 0xb0);

      }

      uVar1 = puVar6[1];

      uVar2 = puVar6[2];

      *param_2 = *puVar6;

      param_2[1] = uVar1;

      param_2[2] = uVar2;

      return 1;

    }

  }

  return 1;

}
