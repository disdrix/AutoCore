// =============================================================================
// Named_Failed_find_selected_shard
// -----------------------------------------------------------------------------
// Stable ID: aa_00821d00
// Address:   0x00821d00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Failed_find_selected_shard @ 0x00821d00
// Stable ID: aa_00821d00
// Embedded strings (evidence for future rename):
//   - "Failed to find selected shard! %u"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×6, while×1, goto×1, return×1.
//  - Notable callees: FUN_00728990, FUN_007a4480, Named_Failed_find_selected_shard, FUN_0092d900.
//  - Strings: "Failed to find selected shard! %u".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Failed to find selected shard! %u"
 * Domain alias of FUN_00821d00 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_Failed_find_selected_shard(byte param_1)



{

  uint uVar1;

  int iVar2;

  int iVar3;

  int unaff_ESI;

  int iVar4;

  

  *(uint *)(unaff_ESI + 0x68) = (uint)param_1;

  *(byte *)(unaff_ESI + 0x74) = param_1;

  iVar3 = 0;

  iVar4 = 0;

  while( true ) {

    if (*(int *)(unaff_ESI + 0x5c) == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = (*(int *)(unaff_ESI + 0x60) - *(int *)(unaff_ESI + 0x5c)) / 0x14;

    }

    if (iVar2 <= iVar3) goto LAB_00821d92;

    if (*(byte *)(*(int *)(unaff_ESI + 0x5c) + iVar4) == param_1) break;

    iVar3 = iVar3 + 1;

    iVar4 = iVar4 + 0x14;

  }

  uVar1 = *(uint *)(*(int *)(unaff_ESI + 0x5c) + iVar3 * 0x14 + 4);

  FUN_0092d900((uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8 | (uVar1 & 0xff00 | uVar1 << 0x10) << 8,

               &DAT_00d1af70);

LAB_00821d92:

  iVar4 = 0;

  if (*(int *)(unaff_ESI + 0x5c) != 0) {

    iVar4 = (*(int *)(unaff_ESI + 0x60) - *(int *)(unaff_ESI + 0x5c)) / 0x14;

  }

  if (iVar4 <= iVar3) {

    FUN_007a4480(1,"Failed to find selected shard! %u",(uint)param_1);

  }

  if (*(int *)(unaff_ESI + 4) != 0) {

    FUN_00728990(*(int *)(unaff_ESI + 4),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x50),

                 *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x54),*(uint8_t *)(unaff_ESI + 0x74));

  }

  return;

}
