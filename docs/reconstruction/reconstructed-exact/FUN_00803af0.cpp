// =============================================================================
// FUN_00803af0
// -----------------------------------------------------------------------------
// Stable ID: aa_00803af0
// Address:   0x00803af0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00803af0 @ 0x00803af0
// Stable ID: aa_00803af0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00803870, FUN_00803af0, GetStockObject, GetTickCount.
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

uint32_t /* width from decompiler */ __fastcall FUN_00803af0(int param_1)



{

  DWORD DVar1;

  HGDIOBJ pvVar2;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 2000;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 7;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 7;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

  DVar1 = GetTickCount();

  *(DWORD *)(param_1 + 0x50) = DVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x268) = 0;

  pvVar2 = GetStockObject(0x11);

  *(HGDIOBJ *)(param_1 + 0x260) = pvVar2;

  if (pvVar2 != (HGDIOBJ)0x0) {

    FUN_00803870(8);

  }

  return 0;

}
