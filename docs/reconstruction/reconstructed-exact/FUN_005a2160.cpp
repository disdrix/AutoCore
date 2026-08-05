// =============================================================================
// FUN_005a2160
// -----------------------------------------------------------------------------
// Stable ID: aa_005a2160
// Address:   0x005a2160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a2160 @ 0x005a2160
// Stable ID: aa_005a2160
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_005a2160.
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

void __thiscall

FUN_005a2160(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,char *param_3,uint32_t /* width from decompiler */ param_4,

            uint8_t param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,

            uint32_t /* width from decompiler */ param_9,uint8_t param_10)



{

  char cVar1;

  int iVar2;

  

  param_1[2] = param_2;

  *(uint8_t *)(param_1 + 3) = param_5;

  *param_1 = &PTR_LAB_009d7b14;

  iVar2 = 0x14 - (int)param_3;

  do {

    cVar1 = *param_3;

    param_3[(int)param_1 + iVar2] = cVar1;

    param_3 = param_3 + 1;

  } while (cVar1 != '\0');

  param_1[4] = param_4;

  param_1[0x26] = param_6;

  param_1[0x27] = param_7;

  param_1[0x28] = param_8;

  param_1[0x29] = param_9;

  *(uint8_t *)(param_1 + 0x2a) = param_10;

  return;

}
