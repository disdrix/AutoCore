// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_0056a9e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0056a9e0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
// Address:   0x0056a9e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_004b7550×4, FUN_004b68c0, FUN_004b7e50, FUN_004b99c0, FUN_0056a9e0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_PacketDispa_0056a9e0(int param_1,void *param_2,int *param_3,int param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ local_2c [3];

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  if (param_2 == (void *)0x0) {

    return;

  }

  local_2c[0] = 0;

  FUN_004b7550(local_2c,1);

  local_2c[0] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe8);

  FUN_004b7550(local_2c,2);

  local_2c[0] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc);

  FUN_004b7550(local_2c,3);

  local_2c[0] = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe0);

  FUN_004b7550(local_2c,4);

  if (param_4 == 0) {

    puVar1 = &DAT_009d2f68;

  }

  else {

    puVar1 = (uint32_t /* width from decompiler */ *)(param_4 + 0x160);

  }

  local_18 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xe8);

  local_20 = 0;

  local_1c = 0;

  local_14 = 0;

  FUN_004b68c0(*puVar1,puVar1[1],puVar1[2],puVar1[3],&local_20);

  uVar3 = 0;

  if (param_3 != (int *)0x0) {

    iVar2 = (**(code **)(*param_3 + 0x1cc))();

    if (iVar2 != 0) {

      uVar3 = (**(code **)(*param_3 + 0x1cc))();

    }

  }

  FUN_004b7e50(0,uVar3,0,0,0,0);

  if (param_3 != (int *)0x0) {

    (**(code **)(*param_3 + 0xf8))(param_2,1,0);

    return;

  }

  FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

  operator_delete(param_2);

}
