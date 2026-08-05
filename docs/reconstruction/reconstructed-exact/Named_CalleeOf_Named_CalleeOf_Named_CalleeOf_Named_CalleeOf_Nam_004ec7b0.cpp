// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004ec7b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004ec7b0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
// Address:   0x004ec7b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam: callee helper. Evidence string: "CollectAllPhysicsPreloads". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "CollectAllPhysicsPreloads"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0043d670, FUN_004a04f0, FUN_004eb3b0, FUN_004ec7b0, FUN_0076cef0, FUN_0076cf00, FUN_007b6730, FUN_007b6a20.
//  - Strings: "CollectAllPhysicsPreloads"; "%S%s".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004ec7b0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint8_t local_118 [4];

  uint32_t /* width from decompiler */ local_114;

  char local_110 [260];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a2816;

  local_c = ExceptionList;

  local_114 = DAT_00d1f040;

  ExceptionList = &local_c;

  FUN_0076cf00("CollectAllPhysicsPreloads");

  iVar2 = *(int *)(param_1 + 0x3c);

  local_4 = 0;

  if (iVar2 != 0) {

    iVar2 = iVar2 + 0x40a;

  }

  _snprintf(local_110,0x104,"%S%s",iVar2,&DAT_009cb318);

  pcVar3 = local_110;

  uVar4 = 0xffffffff;

  FUN_007b6a20(pcVar3,0xffffffff);

  cVar1 = FUN_007b6730(pcVar3,uVar4);

  if (cVar1 != '\0') {

    FUN_00989e00(local_118,local_110);

    FUN_0043d670(local_118);

  }

  FUN_004eb3b0();

  if (*(int *)(param_1 + 0x88) != 0) {

    FUN_004a04f0(param_2,0,0,1);

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return;

}
