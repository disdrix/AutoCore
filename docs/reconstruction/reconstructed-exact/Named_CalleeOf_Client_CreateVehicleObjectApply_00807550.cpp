// =============================================================================
// Named_CalleeOf_Client_CreateVehicleObjectApply_00807550
// -----------------------------------------------------------------------------
// Stable ID: aa_00807550
// Callee of Client_CreateVehicleObjectApply
// Address:   0x00807550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_CreateVehicleObjectApply: vehicle/entity helper. Evidence string: "Assigned a pending ghost to %I64d". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Assigned a pending ghost to %I64d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00409220, FUN_004cba00, FUN_007a4480, FUN_00807550.
//  - Strings: "Assigned a pending ghost to %I64d".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_CreateVehicleObjectApply
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

void Named_CalleeOf_Client_CreateVehicleObjectApply_00807550(int *param_1)



{

  int *piVar1;

  int *piVar2;

  int in_EAX;

  int iVar3;

  

  piVar1 = param_1;

  iVar3 = (**(code **)(**(int **)(in_EAX + 0xc78) + 0x48))();

  if (iVar3 != 0) {

    FUN_004cba00(&param_1,piVar1 + 0x58);

    piVar2 = param_1;

    if ((param_1 != *(int **)(iVar3 + 0x248)) && (*(int *)(param_1[8] + 0x5c) == 0)) {

      FUN_007a4480(0xffffffff,"Assigned a pending ghost to %I64d",piVar1[0x58],piVar1[0x59]);

      (**(code **)(*piVar1 + 0x2b8))(piVar2[8]);

      FUN_00409220(&stack0x00000000,piVar2);

    }

  }

  return;

}
