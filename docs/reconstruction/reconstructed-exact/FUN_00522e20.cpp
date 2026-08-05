// =============================================================================
// FUN_00522e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00522e20
// Address:   0x00522e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00522e20 @ 0x00522e20
// Stable ID: aa_00522e20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00522e20.
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

void __fastcall FUN_00522e20(int param_1)



{

  byte bVar1;

  byte bVar2;

  int iVar3;

  uint *puVar4;

  

  iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);

  bVar1 = *(byte *)(iVar3 + 0x531);

  bVar2 = *(byte *)(iVar3 + 0x532);

  puVar4 = DAT_00b046a8;

  if (DAT_00b046a8 != DAT_00b046ac) {

    do {

      if ((puVar4[1] == (uint)bVar1) && (*puVar4 == (uint)bVar2)) {

        *(uint *)(param_1 + 0xd58) = puVar4[0xb];

        *(uint *)(param_1 + 0xd5c) = puVar4[0xc];

        *(uint *)(param_1 + 0xd60) = puVar4[0xd];

      }

      puVar4 = puVar4 + 0xe;

    } while (puVar4 != DAT_00b046ac);

  }

  return;

}
