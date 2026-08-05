// =============================================================================
// FUN_00563760
// -----------------------------------------------------------------------------
// Stable ID: aa_00563760
// Address:   0x00563760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00563760 @ 0x00563760
// Stable ID: aa_00563760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_00563760.
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

uint FUN_00563760(int *param_1)



{

  uint *puVar1;

  uint *puVar2;

  int iVar3;

  uint uVar4;

  

  if (*(int *)(param_1[0x2a] + 0x38) == 0x12) {

    iVar3 = (**(code **)(*param_1 + 0x1d8))();

    if (iVar3 != 0) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 600) = 0;

    }

  }

  if (*(int *)(param_1[0x2a] + 0x38) == 0xe) {

    iVar3 = (**(code **)(*param_1 + 0x1d4))();

    if (iVar3 != 0) {

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x280) = 0;

    }

  }

  uVar4 = (**(code **)(*param_1 + 0x1d8))();

  if ((uVar4 != 0) && (*(char *)(uVar4 + 0x204) != '\0')) {

    puVar1 = (uint *)(uVar4 + 0x210);

    puVar2 = (uint *)(uVar4 + 0x214);

    uVar4 = *(uint *)(*(int *)(*(int *)(uVar4 + 4) + 4) + 0xa8 + uVar4);

    if ((*puVar1 & *puVar2) != 0xffffffff) {

      *(int *)(uVar4 + 0x2c) = *(int *)(uVar4 + 0x2c) + -1;

      return uVar4 & 0xffffff00;

    }

    *(int *)(uVar4 + 0x28) = *(int *)(uVar4 + 0x28) + -1;

  }

  return uVar4 & 0xffffff00;

}
