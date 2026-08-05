// =============================================================================
// FUN_005bf660
// -----------------------------------------------------------------------------
// Stable ID: aa_005bf660
// Address:   0x005bf660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005bf660 @ 0x005bf660
// Stable ID: aa_005bf660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_005bf660.
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

int __fastcall FUN_005bf660(int param_1)



{

  float fVar1;

  void *pvVar2;

  

  *(float *)(param_1 + 0x3c) = g_flOne;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = DAT_00aaa8a4;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = DAT_00aaaaec;

  fVar1 = g_flInferredThreatScale;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 8;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0x40;

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0x20;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0x21;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0x441;

  *(float *)(param_1 + 0x74) = fVar1;

  pvVar2 = operator_new__(0x330c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x28) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

  *(void **)(param_1 + 0x14) = pvVar2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 100) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x68) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x6c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = 0;

  return param_1;

}
