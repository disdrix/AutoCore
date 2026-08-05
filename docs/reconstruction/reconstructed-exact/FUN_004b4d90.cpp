// =============================================================================
// FUN_004b4d90
// -----------------------------------------------------------------------------
// Stable ID: aa_004b4d90
// Address:   0x004b4d90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004b4d90 @ 0x004b4d90
// Stable ID: aa_004b4d90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_004b4d90, FUN_005c5930.
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

void __thiscall FUN_004b4d90(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  void *pvVar1;

  int iVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1460;

  local_c = ExceptionList;

  if ((*param_1 != 0) && (s___AVNxUserOutputStream___00af06fc[0x19] != '\0')) {

    ExceptionList = &local_c;

    pvVar1 = operator_new(8);

    local_4 = 0;

    if (pvVar1 != (void *)0x0) {

      iVar2 = FUN_005c5930(param_2,param_1[1]);

      param_1[3] = iVar2;

      ExceptionList = local_c;

      return;

    }

    param_1[3] = 0;

  }

  ExceptionList = local_c;

  return;

}
