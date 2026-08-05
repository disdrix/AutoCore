// =============================================================================
// FUN_008cd070
// -----------------------------------------------------------------------------
// Stable ID: aa_008cd070
// Address:   0x008cd070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008cd070 @ 0x008cd070
// Stable ID: aa_008cd070
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_008d8a10×2, FUN_008cd070, FUN_008d7480, FUN_008d7620, FUN_008d80c0, FUN_0090ed80.
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

void FUN_008cd070(void)



{

  int iVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar2;

  

  if ((&DAT_00d1b6dc)[DAT_00d1a980] == 0) {

    FUN_008d8a10(in_EAX);

    return;

  }

  FUN_008d80c0(in_EAX);

  iVar1 = (&DAT_00d1b6dc)[DAT_00d1a980];

  *(int *)(in_EAX + 0x544) = iVar1;

  if (iVar1 != 0) {

    FUN_008d8a10(in_EAX);

    (**(code **)(**(int **)(in_EAX + 0x590) + 0xd4))(1);

    (**(code **)(**(int **)(in_EAX + 0x590) + 0x34c))();

    FUN_008d7620(&LAB_008cc370);

    iVar1 = *(int *)(*(int *)(in_EAX + 0x544) + 0x250);

    if (iVar1 != 0) {

      uVar2 = FUN_0090ed80(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x1a8),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x1ac),

                           *(uint32_t /* width from decompiler */ *)(iVar1 + 0x248),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x24c),

                           *(uint8_t *)(iVar1 + 0x288),8,iVar1 + 0x28c);

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x548) = uVar2;

      FUN_008d7480(&LAB_008ccfe0,&LAB_008cd010,&LAB_008cd040);

    }

  }

  return;

}
