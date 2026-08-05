// =============================================================================
// FUN_0056a770
// -----------------------------------------------------------------------------
// Stable ID: aa_0056a770
// Address:   0x0056a770  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056a770 @ 0x0056a770
// Stable ID: aa_0056a770
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_004b8dc0, FUN_0056a770, NDSpecialFX_LoadFromScriptName.
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

void __fastcall FUN_0056a770(int param_1)



{

  void *pvVar1;

  short *psVar2;

  char *pszName;

  

  pszName = s_generic_physical_00af2ea0;

  psVar2 = (short *)(param_1 + 0x130);

  do {

    if (0 < *psVar2) {

      pvVar1 = NDSpecialFX_LoadFromScriptName(pszName,-1,0);

      if (pvVar1 != (void *)0x0) {

        FUN_004b8dc0(1,0);

        (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0xf8))

                  (pvVar1,1,0);

      }

    }

    pszName = pszName + 0x20;

    psVar2 = psVar2 + 1;

  } while ((int)pszName < 0xaf2f60);

  return;

}
