// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp_004e1830
// -----------------------------------------------------------------------------
// Stable ID: aa_004e1830
// Callee of Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp (+1 other named callers)
// Address:   0x004e1830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp: combat/reward helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×5, return×4.
//  - Notable callees: LeaveCriticalSection×3, FUN_004e1830, TryEnterCriticalSection.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp (+1 other named callers)
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

uint __thiscall Named_CalleeOf_Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp_004e1830(int param_1,int *param_2,uint32_t /* width from decompiler */ *param_3)



{

  LPCRITICAL_SECTION lpCriticalSection;

  int iVar1;

  BOOL BVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  iVar1 = *param_2;

  if (*(char *)(param_1 + 0x28) != '\0') {

    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);

    BVar2 = TryEnterCriticalSection(lpCriticalSection);

    if (BVar2 != 0) {

      if (*param_2 == 0) {

        if (*(int *)(param_1 + 0x1c) == 0) {

          uVar3 = 0;

        }

        else {

          uVar3 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1c) + 4);

        }

        *param_3 = uVar3;

        *param_2 = *(int *)(param_1 + 0x1c);

        LeaveCriticalSection(lpCriticalSection);

        return (uint)(*(int *)(param_1 + 0x1c) == 0);

      }

      if (*(int *)(iVar1 + 8) != 0) {

        *param_2 = *(int *)(iVar1 + 8);

        *param_3 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 8) + 4);

        LeaveCriticalSection(lpCriticalSection);

        return 0;

      }

      *param_2 = 0;

      *param_3 = 0;

      LeaveCriticalSection(lpCriticalSection);

      return 1;

    }

  }

  return 0x80070005;

}
