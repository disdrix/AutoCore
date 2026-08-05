// =============================================================================
// FUN_006f7ca0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f7ca0
// Address:   0x006f7ca0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f7ca0 @ 0x006f7ca0
// Stable ID: aa_006f7ca0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_006f7ca0.
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

void FUN_006f7ca0(int param_1)



{

  byte bVar1;

  byte bVar2;

  byte bVar3;

  int in_EAX;

  uint uVar4;

  uint *unaff_EBX;

  int iVar5;

  

  uVar4 = in_EAX >> 4;

  bVar3 = ~(byte)(uVar4 >> 3) & 1;

  bVar1 = ~(byte)(uVar4 >> 2) & 1;

  bVar2 = ~(byte)(uVar4 >> 1) & 1;

  if (param_1 != 0) {

    iVar5 = 1 << (bVar1 + bVar2 * '\x02') * '\x02';

    if ((*unaff_EBX & iVar5 * 2) == 0) {

      *unaff_EBX = *unaff_EBX + iVar5;

    }

  }

  if (param_1 != 1) {

    iVar5 = 1 << ((bVar3 + 4 + bVar2 * '\x02') * '\x02' & 0x1f);

    if ((*unaff_EBX & iVar5 * 2) == 0) {

      *unaff_EBX = *unaff_EBX + iVar5;

    }

  }

  if (param_1 != 2) {

    iVar5 = 1 << ((bVar3 + 8 + bVar1 * '\x02') * '\x02' & 0x1f);

    if ((*unaff_EBX & iVar5 * 2) == 0) {

      *unaff_EBX = *unaff_EBX + iVar5;

    }

  }

  return;

}
