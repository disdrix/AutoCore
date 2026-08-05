// =============================================================================
// FUN_0048d1e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0048d1e0
// Address:   0x0048d1e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048d1e0 @ 0x0048d1e0
// Stable ID: aa_0048d1e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: CONCAT31, FUN_0048d1e0, isspace.
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

uint32_t /* width from decompiler */ __fastcall FUN_0048d1e0(int param_1)



{

  byte bVar1;

  uint *puVar2;

  int iVar3;

  uint uVar4;

  

  puVar2 = *(uint **)(param_1 + 0x20);

  uVar4 = 0;

  if (*puVar2 != 0) {

    do {

      bVar1 = *(byte *)((int)puVar2 + uVar4 + 8);

      iVar3 = isspace((uint)bVar1);

      if (((iVar3 == 0) && (bVar1 != 10)) && (bVar1 != 0xd)) {

        return 0;

      }

      puVar2 = *(uint **)(param_1 + 0x20);

      uVar4 = uVar4 + 1;

    } while (uVar4 < *puVar2);

  }

  return CONCAT31((int3)((uint)puVar2 >> 8),1);

}
