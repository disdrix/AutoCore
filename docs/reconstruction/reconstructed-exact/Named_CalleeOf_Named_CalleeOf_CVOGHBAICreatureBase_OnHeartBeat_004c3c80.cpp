// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGHBAICreatureBase_OnHeartBeat_004c3c80
// -----------------------------------------------------------------------------
// Stable ID: aa_004c3c80
// Callee of Named_CalleeOf_CVOGHBAICreatureBase_OnHeartBeat (+1 other named callers)
// Address:   0x004c3c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGHBAICreatureBase_OnHeartBeat: creature/setup helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_CVOGHBAICreatureBase_OnHeartBeat (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_004c3c80, FUN_005172d0, Object_ResolveFromTFID.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGHBAICreatureBase_OnHeartBeat (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_CalleeOf_CVOGHBAICreatureBase_OnHeartBeat_004c3c80(int param_1,char param_2)



{

  char cVar1;

  void *pvVar2;

  TFID_16 local_10;

  

  *(char *)(param_1 + 0x278) = param_2;

  if (param_2 == '\x01') {

    local_10.dwCoidLo = *(uint *)(param_1 + 0x228);

    local_10.dwCoidHi = *(uint *)(param_1 + 0x22c);

    local_10._8_4_ = *(uint32_t /* width from decompiler */ *)(param_1 + 0x230);

    local_10._12_4_ = *(uint32_t /* width from decompiler */ *)(param_1 + 0x234);

    pvVar2 = Object_ResolveFromTFID(&local_10);

    if (((pvVar2 != (void *)0x0) && (*(int *)((int)pvVar2 + 0xa0) != 0)) &&

       (cVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0x298))

                          (*(int *)((int)pvVar2 + 0xa0)), cVar1 != '\0')) {

      FUN_005172d0(*(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0xa0));

    }

  }

  return;

}
