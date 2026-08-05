// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxBodyMassageMachine_0044d470
// -----------------------------------------------------------------------------
// Stable ID: aa_0044d470
// Callee of Named_CalleeOf_Named_gfxBodyMassageMachine
// Address:   0x0044d470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxBodyMassageMachine: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×9, return×3, goto×2.
//  - Notable callees: FUN_0044d470, _access.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxBodyMassageMachine
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

bool __fastcall Named_CalleeOf_Named_CalleeOf_Named_gfxBodyMassageMachine_0044d470(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int iVar1;

  char *_Filename;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  int *piVar4;

  uint uVar5;

  

  if (*(uint *)(param_2 + 0x14) != 0) {

    uVar5 = *(uint *)(param_2 + 0x18);

    piVar4 = (int *)(param_2 + 4);

    piVar3 = piVar4;

    if (0xf < uVar5) {

      piVar3 = (int *)*piVar4;

    }

    if (*(char *)piVar3 == '\\') goto LAB_0044d4bf;

    if (0xf < uVar5) {

      piVar4 = (int *)*piVar4;

    }

    if ((char)*piVar4 == '/') goto LAB_0044d4bf;

  }

  if (*(uint *)(param_2 + 0x14) < 2) {

    return false;

  }

  uVar5 = *(uint *)(param_2 + 0x18);

  puVar2 = (uint32_t /* width from decompiler */ *)(param_2 + 4);

  if (0xf < uVar5) {

    puVar2 = (uint32_t /* width from decompiler */ *)*puVar2;

  }

  if (*(char *)((int)puVar2 + 1) != ':') {

    return false;

  }

LAB_0044d4bf:

  _Filename = (char *)(param_2 + 4);

  if (0xf < uVar5) {

    _Filename = *(char **)_Filename;

  }

  iVar1 = _access(_Filename,0);

  return iVar1 == 0;

}
