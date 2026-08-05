// =============================================================================
// FUN_007178b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007178b0
// Address:   0x007178b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007178b0 @ 0x007178b0
// Stable ID: aa_007178b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, return×1.
//  - Notable callees: FUN_007178b0.
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

void FUN_007178b0(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint uVar3;

  uint uVar4;

  int iVar5;

  

  uVar4 = 0xa280;

  uVar3 = 0xff;

  puVar1 = (uint32_t /* width from decompiler */ *)(param_2 + 0x3fc);

  do {

    uVar4 = uVar4 - 0xa2;

    puVar2 = puVar1 + -1;

    iVar5 = ((uVar4 >> 8) + 0x41) * uVar3;

    uVar3 = uVar3 - 1;

    *puVar1 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x74 + (iVar5 + 0xd1U >> 8) * 4);

    puVar1 = puVar2;

  } while (0x56 < uVar3);

  uVar3 = 0x457d;

  iVar5 = 0x57;

  do {

    uVar3 = uVar3 - 0xcb;

    iVar5 = iVar5 + -1;

    *puVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + (uVar3 >> 8) * 4);

    puVar2 = puVar2 + -1;

  } while (iVar5 != 0);

  return;

}
