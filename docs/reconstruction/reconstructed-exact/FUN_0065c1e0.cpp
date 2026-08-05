// =============================================================================
// FUN_0065c1e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0065c1e0
// Address:   0x0065c1e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065c1e0 @ 0x0065c1e0
// Stable ID: aa_0065c1e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_00651f60, FUN_0065c1e0.
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

int __fastcall FUN_0065c1e0(int param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  

  FUN_00651f60();

  fVar1 = g_flOne;

  *(uint8_t *)(param_1 + 0xc) = 1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0x38);

  iVar3 = 2;

  do {

    puVar2[-3] = 0;

    puVar2[-4] = 0;

    puVar2[-5] = 0;

    puVar2[-6] = 0;

    puVar2[1] = 0;

    *puVar2 = 0;

    puVar2[-1] = 0;

    puVar2[-2] = 0;

    puVar2[5] = 0;

    puVar2[4] = 0;

    puVar2[3] = 0;

    puVar2[2] = 0;

    puVar2[-6] = fVar1;

    puVar2[-1] = fVar1;

    puVar2[4] = fVar1;

    puVar2[9] = 0;

    puVar2[8] = 0;

    puVar2[7] = 0;

    puVar2[6] = 0;

    puVar2 = puVar2 + 0x10;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  return param_1;

}
