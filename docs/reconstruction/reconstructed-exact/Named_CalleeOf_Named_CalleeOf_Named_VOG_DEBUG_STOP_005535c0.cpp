// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_005535c0
// -----------------------------------------------------------------------------
// Stable ID: aa_005535c0
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x005535c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_00552f50, FUN_005535c0, Skill_ReevaluateForCurrentRank.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_005535c0(void *param_1,short param_2,int param_3)



{

  short sVar1;

  uint uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  if (param_3 != 0) {

    if (*(float *)((int)param_1 + 4) == g_flZero) {

      uVar2 = (uint)*(byte *)((int)param_1 + 0x5f4);

    }

    else {

      uVar2 = FUN_00552f50(param_3);

    }

    sVar1 = *(short *)((int)param_1 + 0x5f6);

    if ((sVar1 != 0) && ((int)sVar1 < (int)uVar2)) {

      iVar3 = uVar2 - (int)sVar1;

      iVar4 = (int)param_2;

      iVar5 = iVar4;

      if (iVar3 <= iVar4) {

        iVar5 = iVar3;

      }

      if (iVar5 < 0) {

        iVar3 = 0;

      }

      else if (iVar4 < iVar3) {

        iVar3 = iVar4;

      }

      *(short *)((int)param_1 + 0x174) = (short)iVar3;

      Skill_ReevaluateForCurrentRank(param_1);

      return 1;

    }

    *(uint16_t *)((int)param_1 + 0x174) = 0;

  }

  return 0;

}
