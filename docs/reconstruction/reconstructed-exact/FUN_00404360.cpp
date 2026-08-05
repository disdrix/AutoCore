// =============================================================================
// FUN_00404360
// -----------------------------------------------------------------------------
// Stable ID: aa_00404360
// Address:   0x00404360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00404360 @ 0x00404360
// Stable ID: aa_00404360
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00404360.
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

void __fastcall

FUN_00404360(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4,

            uint8_t param_5)



{

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  *in_EAX = param_1;

  in_EAX[2] = param_3;

  in_EAX[1] = param_2;

  puVar2 = in_EAX + 4;

  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar2 = *param_4;

    param_4 = param_4 + 1;

    puVar2 = puVar2 + 1;

  }

  *(uint8_t *)(in_EAX + 0xc) = param_5;

  *(uint8_t *)((int)in_EAX + 0x31) = 0;

  return;

}
