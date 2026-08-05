// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_0090e570
// -----------------------------------------------------------------------------
// Stable ID: aa_0090e570
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI
// Address:   0x0090e570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0090e570, GetDoubleClickTime.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI
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



void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_0090e570(int param_1)



{

  float fVar1;

  uint32_t /* width from decompiler */ uVar2;

  UINT UVar3;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa2c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x758) = 0;

  UVar3 = GetDoubleClickTime();

  uVar2 = DAT_00aaa668;

  fVar1 = (float)(int)UVar3;

  if ((int)UVar3 < 0) {

    fVar1 = fVar1 + _DAT_00aaa5dc;

  }

  fVar1 = fVar1 * g_flMsToSeconds_Inferred;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x558) = DAT_00aaa668;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x55c) = uVar2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x560) = uVar2;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5e8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5ec) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5f0) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x600) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x604) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x608) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5f4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5f8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5fc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5cc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5d0) = 0;

  fVar1 = fVar1 + DAT_00a10e78;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa20) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa24) = 0;

  *(float *)(param_1 + 0x54c) = fVar1;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x568) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x554) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x544) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x548) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5d4) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5d8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5b8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5bc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c0) = 0;

  return;

}
