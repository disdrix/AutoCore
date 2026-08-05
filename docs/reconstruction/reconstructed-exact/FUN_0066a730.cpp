// =============================================================================
// FUN_0066a730
// -----------------------------------------------------------------------------
// Stable ID: aa_0066a730
// Address:   0x0066a730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066a730 @ 0x0066a730
// Stable ID: aa_0066a730
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: FUN_005b3300×2, FUN_0066a5f0, FUN_0066a730.
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

void __thiscall FUN_0066a730(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  *(uint8_t *)(param_1 + 0xc) = *(uint8_t *)(param_2 + 1);

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = *param_2;

  iVar3 = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  iVar4 = param_2[3];

  uVar1 = *(uint *)(param_1 + 0x18) & 0x7fffffff;

  if ((int)uVar1 < iVar4) {

    iVar2 = uVar1 * 2;

    if (iVar2 <= iVar4) {

      iVar2 = iVar4;

    }

    FUN_005b3300(param_1 + 0x10,iVar2,0x10);

  }

  uVar1 = *(uint *)(param_1 + 0x24) & 0x7fffffff;

  if ((int)uVar1 < iVar4) {

    iVar2 = uVar1 * 2;

    if (iVar2 <= iVar4) {

      iVar2 = iVar4;

    }

    FUN_005b3300(param_1 + 0x1c,iVar2,4);

  }

  if (0 < iVar4) {

    do {

      FUN_0066a5f0(param_2[2] + iVar3);

      iVar3 = iVar3 + 0x10;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

  }

  return;

}
