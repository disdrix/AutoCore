// =============================================================================
// Named_CalleeOf_Mission_numberPerEmission_00798e50
// -----------------------------------------------------------------------------
// Stable ID: aa_00798e50
// Callee of Mission_numberPerEmission
// Address:   0x00798e50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_numberPerEmission: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_007988e0×2, FUN_00798bb0, FUN_00798e50, _wtol.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Mission_numberPerEmission
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

char Named_CalleeOf_Mission_numberPerEmission_00798e50(uint32_t /* width from decompiler */ param_1,long *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4,

                 uint32_t /* width from decompiler */ *param_5,uint8_t *param_6)



{

  char cVar1;

  long lVar2;

  short *local_84;

  short local_80;

  wchar_t local_7e;

  short local_7c;

  uint16_t local_7a [61];

  

  *param_2 = -1;

  if (param_6 != (uint8_t *)0x0) {

    *param_6 = 0;

  }

  cVar1 = FUN_00798bb0(param_1,param_3,&local_80);

  if (cVar1 != '\0') {

    if ((local_80 != 0x70) && (local_80 != 0x50)) {

      local_84 = &local_80;

      FUN_007988e0(&local_84,param_4,param_4,param_6);

      return cVar1;

    }

    lVar2 = _wtol(&local_7e);

    *param_2 = lVar2;

    if (local_7c == 0x3b) {

      local_84 = local_7a;

      FUN_007988e0(&local_84,param_4,0,param_6);

      *param_6 = 1;

      *param_5 = *param_4;

    }

  }

  return cVar1;

}
