// =============================================================================
// Named_CalleeOf_Client_Input_PollBoundActions_00925670
// -----------------------------------------------------------------------------
// Stable ID: aa_00925670
// Callee of Client_Input_PollBoundActions
// Address:   0x00925670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0058cd60, FUN_00925580, FUN_00925670, GetTickCount.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_Input_PollBoundActions
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Named_CalleeOf_Client_Input_PollBoundActions_00925670(void)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar4;

  uint local_30;

  uint local_2c;

  

  if (*(int *)(in_EAX + 0xcd0) == 0) {

    _DAT_00d218d4 = GetTickCount();

    if (99 < _DAT_00d218d4 - _DAT_00d1f0d4) {

      local_30 = 0xffffffff;

      local_2c = 0xffffffff;

      iVar2 = *(int *)(*(int *)(in_EAX + 4) + 4);

      iVar1 = *(int *)(*(int *)(in_EAX + 4) + 4) + in_EAX;

      uVar3 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0xa8);

      _DAT_00d1f0d4 = _DAT_00d218d4;

      uVar4 = (**(code **)(*(int *)(iVar1 + 4) + 0x1a0))(0x41a00000,1,6,0,0,1);

      FUN_0058cd60(&local_30,0,uVar3,iVar2 + 4 + in_EAX,uVar4);

      if ((local_30 & local_2c) != 0xffffffff) {

        FUN_00925580();

      }

    }

  }

  return;

}
