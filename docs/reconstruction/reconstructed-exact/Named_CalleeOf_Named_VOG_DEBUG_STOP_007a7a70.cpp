// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_007a7a70
// -----------------------------------------------------------------------------
// Stable ID: aa_007a7a70
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x007a7a70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_007a7a70.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_007a7a70(int *param_1,char param_2)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  if (param_2 != *(char *)((int)param_1 + 0xc9)) {

    *(char *)((int)param_1 + 0xc9) = param_2;

    if (param_2 != '\0') {

      (**(code **)(*param_1 + 0x48))();

      cVar2 = (**(code **)(*param_1 + 0xd8))();

      if ((cVar2 != '\0') && ((int *)param_1[0xac] != (int *)0x0)) {

        iVar1 = *(int *)param_1[0xac];

        uVar3 = (**(code **)(*param_1 + 0x78))();

        (**(code **)(iVar1 + 0x338))(0x17,uVar3);

      }

      (**(code **)(*param_1 + 0x1f0))();

      *(uint8_t *)(param_1 + 0x23) = *(uint8_t *)((int)param_1 + 0xc9);

      return;

    }

    (**(code **)(*param_1 + 0x4c))();

    cVar2 = (**(code **)(*param_1 + 0xd8))();

    if ((cVar2 != '\0') && ((int *)param_1[0xac] != (int *)0x0)) {

      iVar1 = *(int *)param_1[0xac];

      uVar3 = (**(code **)(*param_1 + 0x78))();

      (**(code **)(iVar1 + 0x338))(0x16,uVar3);

    }

    *(uint8_t *)(param_1 + 0x23) = *(uint8_t *)((int)param_1 + 0xc9);

  }

  return;

}
