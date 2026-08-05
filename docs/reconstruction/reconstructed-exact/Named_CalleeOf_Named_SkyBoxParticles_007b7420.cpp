// =============================================================================
// Named_CalleeOf_Named_SkyBoxParticles_007b7420
// -----------------------------------------------------------------------------
// Stable ID: aa_007b7420
// Callee of Named_SkyBoxParticles (+1 other named callers)
// Address:   0x007b7420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_SkyBoxParticles (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: if×13, return×3, goto×1.
//  - Notable callees: strrchr×2, EnterCriticalSection, FUN_00744ea0, FUN_007b7420, FUN_00989e00, LeaveCriticalSection, NDResourceCache_LookupOrCreate, NDResource_AcquireInnerObject.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_SkyBoxParticles (+1 other named callers)
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



uint32_t /* width from decompiler */ * Named_CalleeOf_Named_SkyBoxParticles_007b7420(char *param_1)



{

  char *pcVar1;

  char *pcVar2;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  char *_Str;

  int *piVar7;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  _Str = param_1;

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b0ba9;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  pcVar1 = strrchr(param_1,0x5c);

  pcVar2 = strrchr(_Str,0x2f);

  if (pcVar1 == (char *)0x0) {

    if (pcVar2 == (char *)0x0) goto LAB_007b7467;

  }

  else if (pcVar2 < pcVar1) {

    pcVar2 = pcVar1;

  }

  _Str = pcVar2 + 1;

LAB_007b7467:

  FUN_00989e00(&param_1,_Str);

  if ((_DAT_00d1f738 & 1) == 0) {

    _DAT_00d1f738 = _DAT_00d1f738 | 1;

    _DAT_00d1f734 = &PTR_FUN_00a95ae8;

    _atexit((_func_4879 *)&LAB_009c3070);

  }

  piVar3 = (int *)NDResourceCache_LookupOrCreate(DAT_00d1f050,&param_1,&DAT_00d1f734,0,0);

  if (piVar3 == (int *)0x0) {

    ExceptionList = local_c;

    return (uint32_t /* width from decompiler */ *)0x0;

  }

  (**(code **)(*piVar3 + 4))();

  iVar4 = NDResource_AcquireInnerObject();

  if (iVar4 == 0) {

    piVar7 = (int *)0x0;

  }

  else {

    piVar7 = *(int **)(iVar4 + 4);

  }

  if (piVar7 != (int *)0x0) {

    (**(code **)(*piVar7 + 8))();

  }

  if ((char)piVar3[0xe] != '\0') {

    EnterCriticalSection((LPCRITICAL_SECTION)(piVar3 + 8));

  }

  if (piVar3[4] != 0) {

    piVar3[4] = piVar3[4] + -1;

  }

  if ((char)piVar3[0xe] != '\0') {

    LeaveCriticalSection((LPCRITICAL_SECTION)(piVar3 + 8));

  }

  if ((*(char *)(DAT_00d1f050 + 0x68) != '\0') && (*(int *)(DAT_00d1f050 + 100) != 0)) {

    FUN_00744ea0(&param_1,0);

  }

  if (piVar7 != (int *)0x0) {

    puVar5 = operator_new(0x18);

    uStack_4 = 0;

    if (puVar5 != (uint32_t /* width from decompiler */ *)0x0) {

      iVar4 = piVar7[1];

      uVar6 = (**(code **)(*piVar7 + 0x1c))();

      puVar5[1] = iVar4;

      puVar5[3] = uVar6;

      puVar5[4] = uVar6;

      puVar5[2] = 0;

      *(uint8_t *)(puVar5 + 5) = 0;

      *puVar5 = &PTR_FUN_00a9d184;

      *(uint8_t *)((int)puVar5 + 0x15) = 1;

      ExceptionList = local_c;

      return puVar5;

    }

  }

  ExceptionList = local_c;

  return (uint32_t /* width from decompiler */ *)0x0;

}
