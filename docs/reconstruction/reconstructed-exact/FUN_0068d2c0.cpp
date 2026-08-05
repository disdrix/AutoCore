// =============================================================================
// FUN_0068d2c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0068d2c0
// Address:   0x0068d2c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0068d2c0 @ 0x0068d2c0
// Stable ID: aa_0068d2c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0068b650, FUN_0068d020, FUN_0068d2c0.
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

void __thiscall FUN_0068d2c0(int param_1,uint param_2,uint32_t /* width from decompiler */ param_3)



{

  void *pvVar1;

  uint uVar2;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009aa3e0;

  local_10 = ExceptionList;

  ExceptionList = &local_10;

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  if (param_2 != 0) {

    if (0xfffffff < param_2) {

      FUN_0068b650();

    }

    uVar2 = param_2 * 0x10;

    pvVar1 = operator_new(uVar2);

    *(void **)(param_1 + 0xc) = (void *)(uVar2 + (int)pvVar1);

    *(void **)(param_1 + 4) = pvVar1;

    *(void **)(param_1 + 8) = pvVar1;

    local_8 = 0;

    FUN_0068d020(pvVar1,param_2,param_3,param_1,param_2);

    *(void **)(param_1 + 8) = (void *)(uVar2 + (int)pvVar1);

  }

  ExceptionList = local_10;

  return;

}
