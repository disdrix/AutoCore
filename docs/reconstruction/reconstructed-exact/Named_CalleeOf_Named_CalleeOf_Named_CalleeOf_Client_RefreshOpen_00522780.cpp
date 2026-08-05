// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_00522780
// -----------------------------------------------------------------------------
// Stable ID: aa_00522780
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow
// Address:   0x00522780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, switch×1, goto×1.
//  - Notable callees: FUN_00520340, FUN_00522710, FUN_00522780.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow
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

float10 __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_00522780(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  float fVar4;

  

  iVar1 = FUN_00522710(param_2,param_3);

  iVar2 = FUN_00520340(param_2);

  if (iVar2 - iVar1 < 0) {

switchD_005227b2_default:

    return (float10)g_flZero;

  }

  switch(param_2) {

  case 1:

    iVar3 = 0x32;

    fVar4 = DAT_00aaa6c4;

    break;

  case 2:

    iVar3 = 0x28;

    fVar4 = g_flLevelUpUiBase_Inferred;

    break;

  case 3:

    iVar3 = 0x1e;

    fVar4 = DAT_00aaa68c;

    break;

  case 4:

    iVar3 = 0x14;

    fVar4 = g_flOne;

    break;

  case 5:

    iVar3 = 10;

    fVar4 = DAT_00a0f298;

    break;

  default:

    goto switchD_005227b2_default;

  }

  return ((float10)*(byte *)(param_1 + 0x599) * (float10)fVar4 +

         (float10)(iVar3 + (iVar2 - iVar1) * 2)) * (float10)DAT_00a0f718;

}
