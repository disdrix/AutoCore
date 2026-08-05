// =============================================================================
// CPhysXBase_RenderResults
// -----------------------------------------------------------------------------
// Stable ID: aa_004b50f0
// Address:   0x004b50f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Domain alias CPhysXBase_RenderResults for FUN_004b50f0 @ 0x004b50f0
// Stable ID: aa_004b50f0
// Embedded strings (evidence for future rename):
//   - "CPhysXBase::RenderResults"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: CPhysXBase_RenderResults, FUN_0076cef0, FUN_0076cf00.
//  - Strings: "CPhysXBase::RenderResults".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CPhysXBase::RenderResults"
 * Domain alias of FUN_004b50f0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall CPhysXBase_RenderResults(int *param_1)



{

  float fVar1;

  uint uVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  uint8_t auStack_48 [4];

  int *piStack_44;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a1487;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0076cf00("CPhysXBase::RenderResults");

  uVar5 = 0;

  local_4 = 0;

  if ((*param_1 != 0) && ((char)param_1[2] == '\x01')) {

    if ((int *)param_1[1] != (int *)0x0) {

      (**(code **)(*(int *)param_1[1] + 0xdc))();

      (**(code **)(*(int *)param_1[1] + 0x1a4))(1,1,0);

      (**(code **)(*(int *)param_1[1] + 0xa4))();

      fVar1 = (float)DAT_00af06f0;

      if (DAT_00af06f0 < 0) {

        fVar1 = fVar1 + _DAT_00aaa5dc;

      }

      *(bool *)(param_1 + 5) = fVar1 * DAT_00aefb3c <= (float)param_1[6];

      uVar4 = 0;

      uVar2 = (**(code **)(*(int *)param_1[1] + 0x16c))();

      if ((uVar2 != 0) && (iVar3 = (**(code **)(*(int *)param_1[1] + 0x170))(), uVar2 != 0)) {

        do {

          (**(code **)(**(int **)(iVar3 + uVar5 * 4) + 0x30))(auStack_48);

          uVar4 = uVar4 + *piStack_44;

          uVar5 = uVar5 + 1;

        } while (uVar5 < uVar2);

      }

      *(bool *)((int)param_1 + 0x15) = DAT_00af06ec < uVar4;

    }

    *(uint8_t *)(param_1 + 2) = 0;

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = pvStack_c;

  return;

}
