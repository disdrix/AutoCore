// =============================================================================
// FUN_007524b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007524b0
// Address:   0x007524b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007524b0 @ 0x007524b0
// Stable ID: aa_007524b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: for×2, return×2, if×1.
//  - Notable callees: FUN_007524b0.
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

uint32_t /* width from decompiler */ __fastcall FUN_007524b0(uint32_t /* width from decompiler */ param_1,int param_2,int param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  ushort uVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  if (-1 < param_3) {

    iVar1 = *(int *)(*(int *)(param_2 + 8) + 0x10) + param_3 * 8;

    uVar2 = *(ushort *)(iVar1 + 6);

    puVar4 = (uint32_t /* width from decompiler */ *)((uint)*(ushort *)(iVar1 + 4) + *(int *)(param_2 + 0xc));

    for (uVar3 = (uint)(uVar2 >> 2); uVar3 != 0; uVar3 = uVar3 - 1) {

      *param_4 = *puVar4;

      puVar4 = puVar4 + 1;

      param_4 = param_4 + 1;

    }

    for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint8_t *)param_4 = *(uint8_t *)puVar4;

      puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

      param_4 = (uint32_t /* width from decompiler */ *)((int)param_4 + 1);

    }

    return 0;

  }

  return 0xffffffff;

}
