// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00422ee0
// -----------------------------------------------------------------------------
// Stable ID: aa_00422ee0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x00422ee0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, for×4.
//  - Notable callees: FUN_00422ee0, SysAllocStringLen, SysFreeString, SysStringLen.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_00422ee0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,int param_3)



{

  BSTR pOVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  BSTR pOVar4;

  UINT local_8;

  

  if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

    return 0;

  }

  if ((BSTR)*param_1 == (BSTR)0x0) {

    local_8 = 0;

  }

  else {

    if (param_3 == 0) {

      return 0;

    }

    local_8 = SysStringLen((BSTR)*param_1);

  }

  pOVar1 = SysAllocStringLen((OLECHAR *)0x0,param_3 + local_8);

  if (pOVar1 == (BSTR)0x0) {

    return 0x8007000e;

  }

  if ((uint32_t /* width from decompiler */ *)*param_1 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar3 = (uint32_t /* width from decompiler */ *)*param_1;

    pOVar4 = pOVar1;

    for (uVar2 = local_8 * 2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

      *(uint32_t /* width from decompiler */ *)pOVar4 = *puVar3;

      puVar3 = puVar3 + 1;

      pOVar4 = pOVar4 + 2;

    }

    for (uVar2 = local_8 * 2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

      *(uint8_t *)pOVar4 = *(uint8_t *)puVar3;

      puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

      pOVar4 = (BSTR)((int)pOVar4 + 1);

    }

  }

  pOVar4 = pOVar1 + local_8;

  for (uVar2 = (uint)(param_3 * 2) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

    *(uint32_t /* width from decompiler */ *)pOVar4 = *param_2;

    param_2 = param_2 + 1;

    pOVar4 = pOVar4 + 2;

  }

  for (uVar2 = param_3 * 2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

    *(uint8_t *)pOVar4 = *(uint8_t *)param_2;

    param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

    pOVar4 = (BSTR)((int)pOVar4 + 1);

  }

  pOVar1[param_3 + local_8] = L'\0';

  SysFreeString((BSTR)*param_1);

  *param_1 = pOVar1;

  return 0;

}
