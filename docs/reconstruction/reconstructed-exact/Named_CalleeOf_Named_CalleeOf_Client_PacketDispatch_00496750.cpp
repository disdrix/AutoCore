// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00496750
// -----------------------------------------------------------------------------
// Stable ID: aa_00496750
// Callee of Named_CalleeOf_Client_PacketDispatch
// Address:   0x00496750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00496210, FUN_00496750.
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00496750(int param_1,int param_2)



{

  int iVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  

  if (*(int *)(param_2 + 8) == 0) {

    if (*(char *)(param_2 + 0xf) == '\0') {

      iVar1 = *(int *)(*(int *)(param_2 + 4) + 4);

      fVar2 = (float)*(int *)(iVar1 + 0x118 + param_2) + DAT_00aaa670;

      fVar4 = (float)s__T_JDynamic_culling_009c7a04._0_4_;

      if ((*(uint *)(iVar1 + param_2 + 0x180) >> 0x12 & 1) == 0) {

        fVar4 = DAT_00a0f6f4;

      }

      if (0 < *(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 0x118 + param_2)) {

        fVar4 = fVar2 * fVar2;

      }

      iVar1 = *(int *)(*(int *)(param_2 + 4) + 4);

      fVar3 = *(float *)(iVar1 + 0x8c + param_2) - *(float *)(param_1 + 0x94);

      fVar2 = *(float *)(iVar1 + 0x84 + param_2) - *(float *)(param_1 + 0x8c);

      if (fVar3 * fVar3 + fVar2 * fVar2 < fVar4) {

        FUN_00496210(param_2);

      }

    }

    return 1;

  }

  return 0;

}
