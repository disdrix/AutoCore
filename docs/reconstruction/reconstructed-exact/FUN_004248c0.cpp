// =============================================================================
// FUN_004248c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004248c0
// Address:   0x004248c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004248c0 @ 0x004248c0
// Stable ID: aa_004248c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: do×2, while×2, return×1.
//  - Notable callees: FUN_004248c0.
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

void FUN_004248c0(void)



{

  uint *puVar1;

  uint *puVar2;

  int iVar3;

  uint *unaff_ESI;

  

  iVar3 = 0xe3;

  puVar1 = unaff_ESI;

  do {

    puVar2 = puVar1 + 1;

    iVar3 = iVar3 + -1;

    *puVar1 = ((*puVar1 ^ puVar1[1]) & 0x7ffffffe ^ *puVar1) >> 1 ^ -(puVar1[1] & 1) & 0x9908b0df ^

              puVar1[0x18d];

    puVar1 = puVar2;

  } while (iVar3 != 0);

  iVar3 = 0x18c;

  do {

    puVar1 = puVar2;

    puVar2 = puVar1 + 1;

    iVar3 = iVar3 + -1;

    *puVar1 = ((*puVar1 ^ puVar1[1]) & 0x7ffffffe ^ *puVar1) >> 1 ^ -(puVar1[1] & 1) & 0x9908b0df ^

              puVar1[-0xe3];

  } while (iVar3 != 0);

  *puVar2 = ((*puVar2 ^ *unaff_ESI) & 0x7ffffffe ^ *puVar2) >> 1 ^ -(*unaff_ESI & 1) & 0x9908b0df ^

            puVar1[-0xe2];

  unaff_ESI[0x271] = 0x270;

  unaff_ESI[0x270] = (uint)unaff_ESI;

  return;

}
