// =============================================================================
// Named_CalleeOf_Client_ShowNpcMissionDialogUI_0052dac0
// -----------------------------------------------------------------------------
// Stable ID: aa_0052dac0
// Callee of Client_ShowNpcMissionDialogUI
// Address:   0x0052dac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_ShowNpcMissionDialogUI: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_0052c700, FUN_0052dac0, FUN_00538a40.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Client_ShowNpcMissionDialogUI
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Type propagation algorithm not settling */



int __thiscall Named_CalleeOf_Client_ShowNpcMissionDialogUI_0052dac0(int param_1,uint32_t /* width from decompiler */ param_2,char param_3)



{

  int iVar1;

  int local_34 [12];

  uint8_t local_4;

  

  FUN_00538a40(local_34,&param_2);

  if (local_34[0] != *(int *)(param_1 + 0x50c)) {

    return local_34[0] + 0x18;

  }

  if (param_3 != '\0') {

    local_34[9] = 0xffffffff;

    local_34[10] = 0xffffffff;

    local_34[0xb] = 0xffffffff;

    local_34[1] = 0xffffffff;

    local_34[2] = 0xffffffff;

    local_34[3] = 0xffffffff;

    local_34[4] = 0xffffffff;

    local_34[5] = 0xffffffff;

    local_34[6] = 0xffffffff;

    local_34[7] = 0xffffffff;

    local_34[8] = 0xffffffff;

    local_4 = 0;

    iVar1 = FUN_0052c700(param_2,local_34 + 1);

    return iVar1;

  }

  return 0;

}
