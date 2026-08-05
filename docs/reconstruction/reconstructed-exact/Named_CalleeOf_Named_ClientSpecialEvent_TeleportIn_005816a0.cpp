// =============================================================================
// Named_CalleeOf_Named_ClientSpecialEvent_TeleportIn_005816a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005816a0
// Callee of Named_ClientSpecialEvent_TeleportIn (+1 other named callers)
// Address:   0x005816a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ClientSpecialEvent_TeleportIn: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_ClientSpecialEvent_TeleportIn (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_005816a0, FUN_0074e910, FUN_0079a110.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_ClientSpecialEvent_TeleportIn (+1 other named callers)
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_ClientSpecialEvent_TeleportIn_005816a0(int param_1,int param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  float10 fVar4;

  

  piVar3 = (int *)(param_1 + 0x2c);

  iVar2 = 0x13;

  do {

    if (*piVar3 != 0) {

      (**(code **)(**(int **)(param_1 + 0x24) + 0x18))(*piVar3,param_3,0);

    }

    piVar3 = piVar3 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  if (*(int *)(param_1 + 0x2c + param_2 * 4) != 0) {

    fVar4 = (float10)FUN_0079a110();

    FUN_0074e910(0,(float)fVar4);

    cVar1 = (**(code **)(**(int **)(param_1 + 0x24) + 0x18))

                      (*(uint32_t /* width from decompiler */ *)(param_1 + 0x2c + param_2 * 4),param_3,0x3f800000);

    if (cVar1 == '\0') {

      return 1;

    }

  }

  return 0;

}
