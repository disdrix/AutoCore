// =============================================================================
// FUN_004c0380
// -----------------------------------------------------------------------------
// Stable ID: aa_004c0380
// Address:   0x004c0380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c0380 @ 0x004c0380
// Stable ID: aa_004c0380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004bff90, FUN_004c0380.
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

uint32_t /* width from decompiler */

FUN_004c0380(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint8_t param_5

            ,char param_6,uint32_t /* width from decompiler */ param_7)



{

  int iVar1;

  

  if ((param_1 != 0) && (*(char *)(param_1 + 0xf) == '\0')) {

    iVar1 = FUN_004bff90(param_1,param_2,param_3,param_4,0,0);

    if (iVar1 != 0) {

      *(uint8_t *)(iVar1 + 0x67) = param_5;

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0x70) = param_7;

      if (param_6 == '\0') {

        *(int *)(iVar1 + 0x10) = param_1;

      }

      return 1;

    }

  }

  return 0;

}
