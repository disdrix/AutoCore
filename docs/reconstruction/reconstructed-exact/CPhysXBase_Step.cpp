// =============================================================================
// CPhysXBase_Step
// -----------------------------------------------------------------------------
// Stable ID: aa_004b5220
// Address:   0x004b5220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias CPhysXBase_Step for FUN_004b5220 @ 0x004b5220
// Stable ID: aa_004b5220
// Embedded strings (evidence for future rename):
//   - "CPhysXBase::Step"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: CPhysXBase_Step, FUN_0076cef0, FUN_0076cf00.
//  - Strings: "CPhysXBase::Step".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CPhysXBase::Step"
 * Domain alias of FUN_004b5220 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall CPhysXBase_Step(int *param_1)



{

  int iVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1499;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0076cf00("CPhysXBase::Step");

  local_4 = 0;

  if ((*param_1 != 0) && ((char)param_1[2] == '\0')) {

    if ((int *)param_1[1] != (int *)0x0) {

      iVar1 = (**(code **)(*(int *)param_1[1] + 0x16c))();

      if (iVar1 == 0) {

        (**(code **)(*(int *)param_1[1] + 0xe0))(0x3d088889,2,0);

      }

      else {

        (**(code **)(*(int *)param_1[1] + 0xe0))(0x3d088889,1);

      }

      (**(code **)(*(int *)param_1[1] + 0xdc))();

      (**(code **)(*(int *)param_1[1] + 0x19c))(puStack_8);

    }

    *(uint8_t *)(param_1 + 2) = 1;

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = pvStack_c;

  return;

}
