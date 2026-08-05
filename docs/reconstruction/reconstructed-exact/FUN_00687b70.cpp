// =============================================================================
// FUN_00687b70
// -----------------------------------------------------------------------------
// Stable ID: aa_00687b70
// Address:   0x00687b70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00687b70 @ 0x00687b70
// Stable ID: aa_00687b70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, for×1, return×1.
//  - Notable callees: FUN_00687b70, FUN_0069f3c0, FUN_0069f400.
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

void __thiscall FUN_00687b70(ushort *param_1,ushort param_2)



{

  void *pvVar1;

  uint uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9f9b;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  operator_delete__(*(void **)(param_1 + 2));

  uVar2 = (uint)param_2;

  *param_1 = param_2;

  pvVar1 = operator_new__(uVar2 << 6);

  local_4 = 0;

  if (pvVar1 == (void *)0x0) {

    pvVar1 = (void *)0x0;

  }

  else {

    _param_2 = uVar2;

    if (-1 < (int)(uVar2 - 1)) {

      do {

        FUN_0069f400();

        _param_2 = _param_2 - 1;

      } while (_param_2 != 0);

    }

  }

  local_4 = 0xffffffff;

  *(void **)(param_1 + 2) = pvVar1;

  for (; uVar2 != 0; uVar2 = uVar2 - 1) {

    FUN_0069f3c0();

  }

  ExceptionList = local_c;

  return;

}
