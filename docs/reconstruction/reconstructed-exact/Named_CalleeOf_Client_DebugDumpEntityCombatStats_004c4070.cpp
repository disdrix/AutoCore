// =============================================================================
// Named_CalleeOf_Client_DebugDumpEntityCombatStats_004c4070
// -----------------------------------------------------------------------------
// Stable ID: aa_004c4070
// Callee of Client_DebugDumpEntityCombatStats
// Address:   0x004c4070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_DebugDumpEntityCombatStats: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×7, return×3.
//  - Notable callees: FUN_004c4070.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Client_DebugDumpEntityCombatStats
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

int __fastcall Named_CalleeOf_Client_DebugDumpEntityCombatStats_004c4070(int param_1)



{

  short sVar1;

  int iVar2;

  short sVar3;

  int iVar4;

  

  sVar1 = *(short *)(param_1 + 0x13e);

  sVar3 = sVar1;

  if (199 < sVar1) {

    sVar3 = 200;

  }

  if ((int)sVar3 + (int)*(short *)(param_1 + 0x146) < 0xfa) {

    if (199 < sVar1) {

      sVar1 = 200;

    }

    iVar4 = (int)sVar1 + (int)*(short *)(param_1 + 0x146);

  }

  else {

    iVar4 = 0xfa;

  }

  iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1dc))();

  if ((int)((-(uint)(iVar2 != 0) & 0x65) - 100) < iVar4) {

    sVar1 = *(short *)(param_1 + 0x13e);

    sVar3 = sVar1;

    if (199 < sVar1) {

      sVar3 = 200;

    }

    if ((int)sVar3 + (int)*(short *)(param_1 + 0x146) < 0xfa) {

      if (199 < sVar1) {

        sVar1 = 200;

      }

      return (int)sVar1 + (int)*(short *)(param_1 + 0x146);

    }

    return 0xfa;

  }

  iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x1dc))();

  return (-(uint)(iVar4 != 0) & 0x65) - 100;

}
