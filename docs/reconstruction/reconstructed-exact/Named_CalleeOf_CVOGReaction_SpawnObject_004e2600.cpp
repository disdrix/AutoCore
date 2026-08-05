// =============================================================================
// Named_CalleeOf_CVOGReaction_SpawnObject_004e2600
// -----------------------------------------------------------------------------
// Stable ID: aa_004e2600
// Callee of CVOGReaction_SpawnObject (+2 other named callers)
// Address:   0x004e2600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_SpawnObject: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. CVOGReaction_SpawnObject (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×2, while×2, goto×1.
//  - Notable callees: LeaveCriticalSection×2, EnterCriticalSection, FUN_004e2600.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_SpawnObject (+2 other named callers)
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

void __thiscall Named_CalleeOf_CVOGReaction_SpawnObject_004e2600(int param_1,code *param_2,uint32_t /* width from decompiler */ param_3,char param_4)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  char cVar4;

  LPCRITICAL_SECTION lpCriticalSection;

  char local_5;

  LPCRITICAL_SECTION local_4;

  

  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 4);

  local_4 = lpCriticalSection;

  EnterCriticalSection(lpCriticalSection);

  if (*(char *)(param_1 + 0x28) != '\0') {

    LeaveCriticalSection(lpCriticalSection);

    return;

  }

  local_5 = '\0';

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1c);

  do {

    do {

      puVar3 = puVar2;

      if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) goto LAB_004e26b1;

      cVar4 = (*param_2)(puVar3[1],param_3,&local_5);

      piVar1 = puVar3 + 2;

      puVar2 = (uint32_t /* width from decompiler */ *)*piVar1;

      lpCriticalSection = local_4;

    } while (cVar4 == '\0');

    if (puVar2 == (uint32_t /* width from decompiler */ *)0x0) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = puVar3[3];

    }

    else {

      puVar2[3] = puVar3[3];

    }

    if (puVar3[3] == 0) {

      *(int *)(param_1 + 0x1c) = *piVar1;

    }

    else {

      *(int *)(puVar3[3] + 8) = *piVar1;

    }

    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;

    if (param_4 == '\0') {

      puVar3[1] = 0;

    }

    (**(code **)*puVar3)(1);

    lpCriticalSection = local_4;

  } while (local_5 == '\0');

LAB_004e26b1:

  LeaveCriticalSection(lpCriticalSection);

  return;

}
