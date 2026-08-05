// =============================================================================
// FUN_005c7cd0
// -----------------------------------------------------------------------------
// Stable ID: aa_005c7cd0
// Address:   0x005c7cd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c7cd0 @ 0x005c7cd0
// Stable ID: aa_005c7cd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×11, return×11.
//  - Notable callees: CLoadNode_initAI, FUN_005c6960, FUN_005c69e0, FUN_005c6a10, FUN_005c72f0, FUN_005c7400, FUN_005c74e0, FUN_005c76f0.
//  - Return sites: 11.

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

int __thiscall FUN_005c7cd0(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  

  if ((*(char *)(param_1 + 0x66) != '\0') && (iVar1 = FUN_005c72f0(param_2,param_3), iVar1 != 1)) {

    return iVar1;

  }

  if ((*(char *)(param_1 + 0x67) != '\0') && (iVar1 = FUN_005c76f0(param_2,param_3), iVar1 != 1)) {

    return iVar1;

  }

  if ((*(char *)(param_1 + 0x60) != '\0') && (iVar1 = FUN_005c79f0(param_2,param_3), iVar1 != 1)) {

    return iVar1;

  }

  if ((*(char *)(param_1 + 0x61) != '\0') && (iVar1 = FUN_005c7400(param_2,param_3), iVar1 != 1)) {

    return iVar1;

  }

  if (((*(char *)(param_1 + 0x62) != '\0') && (*(char *)(param_1 + 0x51) != '\0')) &&

     (iVar1 = FUN_005c74e0(param_2), iVar1 != 1)) {

    return iVar1;

  }

  if (((*(char *)(param_1 + 99) != '\0') && (*(char *)(param_1 + 0x51) != '\0')) &&

     (iVar1 = FUN_005c78a0(param_2,param_3), iVar1 != 1)) {

    return iVar1;

  }

  if ((*(char *)(param_1 + 100) != '\0') && (iVar1 = CLoadNode_initAI(param_2), iVar1 != 1)) {

    return iVar1;

  }

  if ((*(char *)(param_1 + 0x65) != '\0') && (iVar1 = FUN_005c6960(param_2), iVar1 != 1)) {

    return iVar1;

  }

  if ((*(char *)(param_1 + 0x68) != '\0') && (iVar1 = FUN_005c69e0(param_2), iVar1 != 1)) {

    return iVar1;

  }

  if ((*(int *)(param_1 + 0x6c) != 0) && (iVar1 = FUN_005c6a10(param_2), iVar1 != 1)) {

    return iVar1;

  }

  if (*(char *)(param_1 + 0x51) == '\0') {

    (**(code **)(*(int *)(*(int *)(param_2[1] + 4) + 4 + (int)param_2) + 0xfc))();

    (**(code **)(*param_2 + 0x1c))(0);

  }

  return 2;

}
