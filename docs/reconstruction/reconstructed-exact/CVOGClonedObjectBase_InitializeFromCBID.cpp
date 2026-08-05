// =============================================================================
// CVOGClonedObjectBase_InitializeFromCBID
// -----------------------------------------------------------------------------
// Stable ID: aa_00517ab0
// Address:   0x00517ab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for CVOGClonedObjectBase_InitializeFromCBID @ 0x00517ab0
// Stable ID: aa_00517ab0
// Embedded strings (evidence for future rename):
//   - "CVOGClonedObjectBase::InitializeFromCBID"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0076cef0×2, FUN_00404d70, FUN_004f1e20, CVOGClonedObjectBase_InitializeFromCBID, FUN_0076cf00.
//  - Strings: "CVOGClonedObjectBase::InitializeFromCBID".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CVOGClonedObjectBase::InitializeFromCBID"
 * Domain alias of FUN_00517ab0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall CVOGClonedObjectBase_InitializeFromCBID(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  void *pvVar1;

  int iVar2;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  pvVar1 = DAT_00d1f040;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a35a2;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_0076cf00("CVOGClonedObjectBase::InitializeFromCBID");

  local_4 = 0;

  iVar2 = FUN_00404d70(param_2);

  param_1[0x2a] = iVar2;

  if (iVar2 != 0) {

    iVar2 = FUN_004f1e20(param_3,1);

    if (-1 < iVar2) {

      (**(code **)(*param_1 + 0xc))();

      if (DAT_00b03e64 == '\0') {

        (**(code **)(*param_1 + 0x22c))();

      }

      (**(code **)(*param_1 + 0x218))(param_2);

    }

    puStack_8 = (uint8_t *)0xffffffff;

    FUN_0076cef0();

    ExceptionList = pvVar1;

    return iVar2;

  }

  puStack_8 = (uint8_t *)0xffffffff;

  FUN_0076cef0();

  ExceptionList = pvVar1;

  return -0x7ff8ffa9;

}
