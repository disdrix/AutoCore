// =============================================================================
// FUN_00579820
// -----------------------------------------------------------------------------
// Stable ID: aa_00579820
// Address:   0x00579820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00579820 @ 0x00579820
// Stable ID: aa_00579820
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1, switch×1.
//  - Notable callees: FUN_00518150×5, FUN_00579820.
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

void __thiscall FUN_00579820(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  

  piVar3 = *(int **)(param_1 + 0x20c);

  if (piVar3 != *(int **)(param_1 + 0x210)) {

    do {

      if ((*piVar3 != 0) && (piVar3[1] != 0)) {

        iVar1 = FUN_00518150(param_2,*piVar3);

        *piVar3 = iVar1;

        iVar1 = FUN_00518150(param_2,piVar3[1]);

        piVar3[1] = iVar1;

      }

      piVar3 = piVar3 + 3;

    } while (piVar3 != *(int **)(param_1 + 0x210));

  }

  switch(*(uint8_t *)(param_1 + 0x1d1)) {

  case 0xd:

  case 0xe:

  case 0xf:

  case 0x31:

  case 0x32:

    uVar2 = FUN_00518150(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 0x25c));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x25c) = uVar2;

    uVar2 = FUN_00518150(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 0x264));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x264) = uVar2;

    return;

  case 0x16:

  case 0x17:

  case 0x18:

  case 0x1a:

  case 0x1b:

  case 0x1c:

  case 0x30:

  case 0x37:

  case 0x4f:

  case 0x50:

  case 0x51:

    uVar2 = FUN_00518150(param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 0x25c));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x25c) = uVar2;

  }

  return;

}
