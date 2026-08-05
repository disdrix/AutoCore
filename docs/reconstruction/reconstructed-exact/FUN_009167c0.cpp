// =============================================================================
// FUN_009167c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009167c0
// Address:   0x009167c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009167c0 @ 0x009167c0
// Stable ID: aa_009167c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0090e570, FUN_009167c0, memmove.
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

void __fastcall FUN_009167c0(int param_1)



{

  void *_Src;

  void *pvVar1;

  

  FUN_0090e570();

  *(uint8_t *)(param_1 + 0xa30) = 0;

  *(uint8_t *)(param_1 + 0xa31) = 0;

  *(uint8_t *)(param_1 + 0xa32) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc70) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc74) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc78) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xcb4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xd24) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc7c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc80) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc84) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc88) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc8c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc90) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc94) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc98) = 0;

  pvVar1 = *(void **)(param_1 + 0xca0);

  if (pvVar1 != (void *)0x0) {

    _Src = *(void **)(param_1 + 0xca4);

    if (((int)_Src - (int)pvVar1 >> 2 != 0) && (pvVar1 != _Src)) {

      pvVar1 = memmove(pvVar1,_Src,0);

      *(void **)(param_1 + 0xca4) = pvVar1;

    }

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xcac) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xcb8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xcb0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xcc0) = 0;

  *(uint8_t *)(param_1 + 0xc65) = 0;

  *(uint8_t *)(param_1 + 0xc66) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc68) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc6c) = 0;

  *(uint8_t *)(param_1 + 0xb94) = 0;

  *(uint8_t *)(param_1 + 0xbb4) = 0;

  *(uint8_t *)(param_1 + 0xbd4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xcbc) = 0;

  return;

}
