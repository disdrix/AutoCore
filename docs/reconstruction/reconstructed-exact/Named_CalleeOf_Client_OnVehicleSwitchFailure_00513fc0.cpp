// =============================================================================
// Named_CalleeOf_Client_OnVehicleSwitchFailure_00513fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00513fc0
// Callee of Client_OnVehicleSwitchFailure (+2 other named callers)
// Address:   0x00513fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_OnVehicleSwitchFailure: vehicle/entity helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Client_OnVehicleSwitchFailure (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, FUN_00513fc0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Client_OnVehicleSwitchFailure (+2 other named callers)
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

bool Named_CalleeOf_Client_OnVehicleSwitchFailure_00513fc0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  short sVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  bool bVar5;

  

  piVar3 = (int *)CVOGReaction_ResolveObjectTarget(1,param_1,param_2);

  bVar5 = false;

  if (piVar3 == (int *)0x0) {

    return false;

  }

  iVar4 = piVar3[0x2a];

  iVar2 = *(int *)(iVar4 + 0x38);

  if (((((iVar2 == 0xc) || (iVar2 == 0x1c)) || (iVar2 == 10)) || ((iVar2 == 0x10 || (iVar2 == 0xe)))

      ) || ((iVar2 == 6 &&

            ((sVar1 = *(short *)(*(int *)(iVar4 + 0x3c) + 0x3f4), sVar1 == 10 || (sVar1 == 0xb))))))

  {

    bVar5 = 1 < *(short *)(*(int *)(iVar4 + 0x3c) + 0x4b8);

    iVar4 = (**(code **)(*piVar3 + 0x60))();

    if (iVar4 != 0) {

      return true;

    }

  }

  return bVar5;

}
