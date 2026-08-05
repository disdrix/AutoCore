// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Palantir_0096a440
// -----------------------------------------------------------------------------
// Stable ID: aa_0096a440
// Callee of Named_CalleeOf_Named_Palantir
// Address:   0x0096a440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Palantir: callee helper. Evidence string: "gWorldEyePos". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "gWorldEyePos"
//   - "gFogEnable"
//   - "gFogDensity"
//   - "gFogColor"
//   - "gViewMatrix"
//   - "gProjectionMatrix"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~105 non-empty decompiler lines.
//  - Control keywords: if×11, return×3.
//  - Notable callees: D3DXCreateEffectPool, FUN_0096a440, NDResourceCache_LookupOrCreate, NDResource_AcquireInnerObject, _atexit.
//  - Strings: "gWorldEyePos"; "gFogEnable"; "gFogDensity"; "gFogColor".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Palantir
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ Named_CalleeOf_Named_CalleeOf_Named_Palantir_0096a440(uint32_t /* width from decompiler */ param_1)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  D3DXCreateEffectPool(unaff_ESI + 0x50);

  puVar2 = operator_new(0x1c);

  if (puVar2 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar2 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    uVar5 = *DAT_00d1f044;

    DAT_00d1f610 = puVar2;

    *puVar2 = &PTR_LAB_00aa5ddc;

    puVar2[1] = 1;

    puVar2[2] = uVar5;

    puVar2[4] = 0xffffffff;

    puVar2[5] = 0xffffffff;

    puVar2[6] = 0;

  }

  uVar1 = _DAT_00d1f7e0 & 1;

  unaff_ESI[0x51] = puVar2;

  if (uVar1 == 0) {

    _DAT_00d1f7e0 = _DAT_00d1f7e0 | 1;

    _DAT_00d1f7dc = &PTR_FUN_00a9f9a0;

    _atexit((_func_4879 *)&LAB_009c33f0);

  }

  piVar3 = (int *)NDResourceCache_LookupOrCreate(DAT_00d1f050,param_1,&DAT_00d1f7dc,0,0);

  *unaff_ESI = piVar3;

  if (piVar3 == (int *)0x0) {

    return 0xffffffff;

  }

  (**(code **)(*piVar3 + 4))();

  iVar4 = NDResource_AcquireInnerObject();

  unaff_ESI[1] = iVar4;

  if (*(int *)(iVar4 + 0xc) == 0) {

    uVar5 = 0;

  }

  else {

    uVar5 = (**(code **)(**(int **)(iVar4 + 0xc) + 0x24))(*(int **)(iVar4 + 0xc),0,"gWorldEyePos");

  }

  unaff_ESI[2] = uVar5;

  if (*(int *)(unaff_ESI[1] + 0xc) == 0) {

    uVar5 = 0;

  }

  else {

    piVar3 = *(int **)(unaff_ESI[1] + 0xc);

    uVar5 = (**(code **)(*piVar3 + 0x24))(piVar3,0,"gFogEnable");

  }

  unaff_ESI[3] = uVar5;

  if (*(int *)(unaff_ESI[1] + 0xc) == 0) {

    uVar5 = 0;

  }

  else {

    piVar3 = *(int **)(unaff_ESI[1] + 0xc);

    uVar5 = (**(code **)(*piVar3 + 0x24))(piVar3,0,"gFogDensity");

  }

  unaff_ESI[4] = uVar5;

  if (*(int *)(unaff_ESI[1] + 0xc) == 0) {

    uVar5 = 0;

  }

  else {

    piVar3 = *(int **)(unaff_ESI[1] + 0xc);

    uVar5 = (**(code **)(*piVar3 + 0x24))(piVar3,0,"gFogColor");

  }

  unaff_ESI[5] = uVar5;

  if (*(int *)(unaff_ESI[1] + 0xc) == 0) {

    uVar5 = 0;

  }

  else {

    piVar3 = *(int **)(unaff_ESI[1] + 0xc);

    uVar5 = (**(code **)(*piVar3 + 0x24))(piVar3,0,"gViewMatrix");

  }

  unaff_ESI[6] = uVar5;

  if (*(int *)(unaff_ESI[1] + 0xc) == 0) {

    uVar5 = 0;

  }

  else {

    piVar3 = *(int **)(unaff_ESI[1] + 0xc);

    uVar5 = (**(code **)(*piVar3 + 0x24))(piVar3,0,"gProjectionMatrix");

  }

  unaff_ESI[7] = uVar5;

  if (*(int *)(unaff_ESI[1] + 0xc) == 0) {

    uVar5 = 0;

  }

  else {

    piVar3 = *(int **)(unaff_ESI[1] + 0xc);

    uVar5 = (**(code **)(*piVar3 + 0x24))(piVar3,0,"gViewProjectionMatrix");

  }

  unaff_ESI[8] = uVar5;

  if (*(int *)(unaff_ESI[1] + 0xc) != 0) {

    piVar3 = *(int **)(unaff_ESI[1] + 0xc);

    uVar5 = (**(code **)(*piVar3 + 0x24))(piVar3,0,"gMaxWeightsPerVertex");

    unaff_ESI[9] = uVar5;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI[1] + 0x28) = 0;

    return 0;

  }

  unaff_ESI[9] = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI[1] + 0x28) = 0;

  return 0;

}
