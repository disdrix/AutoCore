// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00524190
// -----------------------------------------------------------------------------
// Stable ID: aa_00524190
// Callee of Named_CalleeOf_Client_PacketDispatch
// Address:   0x00524190  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×7, return×5.
//  - Notable callees: FUN_004bb970, FUN_00524190, FUN_00599dd0.
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PacketDispatch
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00524190(int param_1,byte param_2,int param_3)



{

  uint uVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  byte bVar4;

  int iVar5;

  uint uVar6;

  

  bVar4 = (*(byte *)(param_1 + 0x59a) >> 1) + 3;

  if (7 < bVar4) {

    bVar4 = 8;

  }

  if (bVar4 <= param_2) {

    return 0;

  }

  if (param_3 != 0) {

    if ((*(int *)(*(int *)(param_3 + 0xa8) + 0x3c) != 0) && (iVar5 = FUN_00599dd0(), iVar5 == 0)) {

      return 0;

    }

    if (*(int *)(*(int *)(param_3 + 0xa8) + 0x3c) == 0) {

      return 0;

    }

  }

  uVar6 = (uint)param_2;

  uVar1 = *(uint *)(param_1 + 0x5a0 + uVar6 * 8);

  uVar2 = *(uint *)(param_1 + 0x5a4 + uVar6 * 8);

  if ((uVar1 & uVar2) != 0xffffffff) {

    FUN_004bb970(1,uVar1,uVar2);

  }

  if (param_3 == 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5a0 + uVar6 * 8) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5a4 + uVar6 * 8) = 0xffffffff;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5e0 + uVar6 * 4) = 0;

    return 1;

  }

  *(ushort *)(param_3 + 0x180) = *(byte *)(param_1 + 0x59a) + 10;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5a0 + uVar6 * 8) = *(uint32_t /* width from decompiler */ *)(param_3 + 0x160);

  uVar3 = *(uint32_t /* width from decompiler */ *)(param_3 + 0x164);

  *(int *)(param_1 + 0x5e0 + uVar6 * 4) = param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5a4 + uVar6 * 8) = uVar3;

  return 1;

}
