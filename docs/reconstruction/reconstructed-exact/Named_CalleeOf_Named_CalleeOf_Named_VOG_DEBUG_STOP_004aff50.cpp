// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004aff50
// -----------------------------------------------------------------------------
// Stable ID: aa_004aff50
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004aff50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×5, while×2, do×1, return×1.
//  - Notable callees: FUN_0044d320×2, FUN_004aff50.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004aff50(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,code *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char cVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  puVar2 = param_1;

  if (param_1 != param_2) {

    while (puVar2 = puVar2 + 2, puVar2 != param_2) {

      cVar3 = (*param_3)(*puVar2,puVar2[1],*param_1,param_1[1]);

      if (cVar3 == '\0') {

        cVar3 = (*param_3)(*puVar2,puVar2[1],puVar2[-2],puVar2[-1]);

        puVar1 = puVar2;

        if (cVar3 != '\0') {

          do {

            puVar4 = puVar1 + -2;

            cVar3 = (*param_3)(*puVar2,puVar2[1],puVar1[-4],puVar1[-3]);

            puVar1 = puVar4;

          } while (cVar3 != '\0');

          if ((puVar4 != puVar2) && (puVar2 != puVar2 + 2)) {

            FUN_0044d320(puVar4,puVar2,puVar2 + 2,0,0);

          }

        }

      }

      else if ((param_1 != puVar2) && (puVar2 != puVar2 + 2)) {

        FUN_0044d320(param_1,puVar2,puVar2 + 2,0,0);

      }

    }

  }

  return;

}
