// =============================================================================
// FUN_00442470
// -----------------------------------------------------------------------------
// Stable ID: aa_00442470
// Address:   0x00442470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00442470 @ 0x00442470
// Stable ID: aa_00442470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00442470×3, FUN_00441f60.
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

uint32_t /* width from decompiler */ * __thiscall FUN_00442470(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *local_18;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  local_8 = 0xffffffff;

  puStack_c = &LAB_009bed70;

  local_10 = ExceptionList;

  local_18 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  if (*(char *)((int)param_2 + 0x3d) == '\0') {

    ExceptionList = &local_10;

    puVar1 = (uint32_t /* width from decompiler */ *)

             FUN_00441f60(local_18,param_3,local_18,param_2 + 3,*(uint8_t *)(param_2 + 0xf));

    if (*(char *)((int)local_18 + 0x3d) != '\0') {

      local_18 = puVar1;

    }

    local_8 = 0;

    uVar2 = FUN_00442470(*param_2,puVar1);

    *puVar1 = uVar2;

    uVar2 = FUN_00442470(param_2[2],puVar1);

    puVar1[2] = uVar2;

  }

  ExceptionList = local_10;

  return local_18;

}
