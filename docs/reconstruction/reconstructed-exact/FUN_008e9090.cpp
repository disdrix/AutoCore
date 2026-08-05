// =============================================================================
// FUN_008e9090
// -----------------------------------------------------------------------------
// Stable ID: aa_008e9090
// Address:   0x008e9090  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e9090 @ 0x008e9090
// Stable ID: aa_008e9090
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_008e9090.
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

void __fastcall FUN_008e9090(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4b4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x504) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x508) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x544) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5a8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5ac) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5b0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5b4) = 0;

  puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0x5d8);

  iVar2 = 4;

  do {

    puVar1[-8] = 0;

    *puVar1 = 0;

    puVar1[4] = 0;

    puVar1[0xc] = 0;

    puVar1[0x10] = 0;

    puVar1[0x14] = 0;

    puVar1[-4] = 0;

    puVar1[8] = 0;

    puVar1 = puVar1 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5a0) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5a4) = 0xffffffff;

  return;

}
