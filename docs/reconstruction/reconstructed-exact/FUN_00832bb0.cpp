// =============================================================================
// FUN_00832bb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00832bb0
// Address:   0x00832bb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00832bb0 @ 0x00832bb0
// Stable ID: aa_00832bb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00832bb0.
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

void __thiscall FUN_00832bb0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  float fVar1;

  char cVar2;

  float fVar3;

  

  fVar1 = DAT_00aaa690;

  if ((char)param_1[0x129] != '\0') {

    fVar3 = (float)param_1[0x128] + DAT_00a10e78;

    param_1[0x128] = (int)fVar3;

    if (fVar1 < fVar3) {

      param_1[0x128] = (int)g_flOne;

      *(uint8_t *)(param_1 + 0x129) = 0;

    }

  }

  (**(code **)(*param_1 + 500))(param_2);

  cVar2 = (**(code **)(*param_1 + 0xf8))();

  if (cVar2 != '\0') {

    (**(code **)(*param_1 + 0x348))(param_2);

  }

  if ((int *)param_1[0xad] != (int *)0x0) {

    (**(code **)(*(int *)param_1[0xad] + 8))(param_2);

  }

  return;

}
