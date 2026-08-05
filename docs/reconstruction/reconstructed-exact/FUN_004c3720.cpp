// =============================================================================
// FUN_004c3720
// -----------------------------------------------------------------------------
// Stable ID: aa_004c3720
// Address:   0x004c3720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c3720 @ 0x004c3720
// Stable ID: aa_004c3720
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: GetTickCount×7, FUN_004c3720.
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

void __thiscall FUN_004c3720(int param_1,uint param_2)



{

  DWORD DVar1;

  

  if ((param_2 & 2) != 0) {

    *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 2;

    DVar1 = GetTickCount();

    *(DWORD *)(param_1 + 0x31c) = DVar1;

  }

  if ((param_2 & 4) != 0) {

    *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 4;

    DVar1 = GetTickCount();

    *(DWORD *)(param_1 + 800) = DVar1;

  }

  if ((param_2 & 8) != 0) {

    *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 8;

    DVar1 = GetTickCount();

    *(DWORD *)(param_1 + 0x324) = DVar1;

  }

  if ((param_2 & 0x10) != 0) {

    *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 0x10;

    DVar1 = GetTickCount();

    *(DWORD *)(param_1 + 0x328) = DVar1;

  }

  if ((param_2 & 0x200) != 0) {

    *(byte *)(param_1 + 0x319) = *(byte *)(param_1 + 0x319) | 2;

    DVar1 = GetTickCount();

    *(DWORD *)(param_1 + 0x32c) = DVar1;

  }

  if ((param_2 & 0x40) != 0) {

    *(uint *)(param_1 + 0x318) = *(uint *)(param_1 + 0x318) | 0x40;

    DVar1 = GetTickCount();

    *(DWORD *)(param_1 + 0x330) = DVar1;

  }

  if ((param_2 & 0x1000) != 0) {

    *(byte *)(param_1 + 0x319) = *(byte *)(param_1 + 0x319) | 0x10;

    DVar1 = GetTickCount();

    *(DWORD *)(param_1 + 0x334) = DVar1;

  }

  if (*(int *)(param_1 + 0x318) == -1) {

    *(uint8_t *)(param_1 + 0x315) = 0;

  }

  return;

}
