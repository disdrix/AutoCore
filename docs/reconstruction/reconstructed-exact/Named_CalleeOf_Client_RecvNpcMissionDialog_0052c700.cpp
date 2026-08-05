// =============================================================================
// Named_CalleeOf_Client_RecvNpcMissionDialog_0052c700
// -----------------------------------------------------------------------------
// Stable ID: aa_0052c700
// Callee of Client_RecvNpcMissionDialog (+1 other named callers)
// Address:   0x0052c700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RecvNpcMissionDialog: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_RecvNpcMissionDialog (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, return×1.
//  - Notable callees: FUN_00538a40×2, FUN_0052c700, FUN_00539cb0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_RecvNpcMissionDialog (+1 other named callers)
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

void __thiscall Named_CalleeOf_Client_RecvNpcMissionDialog_0052c700(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int local_40 [2];

  uint32_t /* width from decompiler */ local_38 [2];

  uint32_t /* width from decompiler */ local_30 [12];

  

  FUN_00538a40(local_40,&param_2);

  uVar1 = param_2;

  iVar3 = 0xc;

  if (local_40[0] == *(int *)(param_1 + 0x50c)) {

    local_38[0] = param_2;

    puVar4 = param_3;

    puVar5 = local_30;

    for (; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

    FUN_00539cb0(local_40,local_38);

  }

  else {

    puVar4 = param_3;

    puVar5 = (uint32_t /* width from decompiler */ *)(local_40[0] + 0x18);

    for (; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar5 = *puVar4;

      puVar4 = puVar4 + 1;

      puVar5 = puVar5 + 1;

    }

  }

  piVar2 = (int *)FUN_00538a40(&param_3,&param_2);

  *(uint32_t /* width from decompiler */ *)(*piVar2 + 0x40) = uVar1;

  return;

}
