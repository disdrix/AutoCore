// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_007995a0
// -----------------------------------------------------------------------------
// Stable ID: aa_007995a0
// Callee of Named_VOG_DEBUG_STOP (+2 other named callers)
// Address:   0x007995a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_VOG_DEBUG_STOP (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: FUN_00798850, FUN_00798bb0, FUN_00799060, FUN_00799110, FUN_007995a0, _wtol.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP (+2 other named callers)
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

char Named_CalleeOf_Named_VOG_DEBUG_STOP_007995a0(uint32_t /* width from decompiler */ param_1,long *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,int param_5

                 ,uint8_t *param_6,uint8_t *param_7)



{

  char cVar1;

  long lVar2;

  short *local_84;

  short local_80;

  wchar_t local_7e [63];

  

  *param_2 = -1;

  if (param_6 != (uint8_t *)0x0) {

    *param_6 = 0;

  }

  if (param_7 != (uint8_t *)0x0) {

    *param_7 = 0;

  }

  cVar1 = FUN_00798bb0(param_1,param_3,&local_80);

  if (cVar1 != '\0') {

    if ((local_80 != 0x70) && (local_80 != 0x50)) {

      if (param_5 == 0) {

        local_84 = &local_80;

        FUN_00798850(&local_84,param_4);

        return cVar1;

      }

      if (param_7 == (uint8_t *)0x0) {

        local_84 = &local_80;

        FUN_00799060(&local_84,param_6);

        return cVar1;

      }

      local_84 = &local_80;

      FUN_00799110(param_4,param_5);

      return cVar1;

    }

    lVar2 = _wtol(local_7e);

    *param_2 = lVar2;

  }

  return cVar1;

}
