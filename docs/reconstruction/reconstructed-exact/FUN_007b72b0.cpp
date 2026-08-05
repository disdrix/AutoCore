// =============================================================================
// FUN_007b72b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007b72b0
// Address:   0x007b72b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b72b0 @ 0x007b72b0
// Stable ID: aa_007b72b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×8, return×3.
//  - Notable callees: FUN_0075d5b0×2, EnterCriticalSection, FUN_007b72b0, FUN_00989e00, LeaveCriticalSection, NDResourceCache_LookupOrCreate, NDResource_AcquireInnerObject, _atexit.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ * FUN_007b72b0(uint32_t /* width from decompiler */ param_1)



{

  uint8_t uVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  int *piVar6;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b0b94;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00989e00(&param_1,param_1);

  if ((_DAT_00d1f738 & 1) == 0) {

    _DAT_00d1f738 = _DAT_00d1f738 | 1;

    _DAT_00d1f734 = &PTR_FUN_00a95ae8;

    _atexit((_func_4879 *)&LAB_009c3070);

  }

  piVar2 = (int *)NDResourceCache_LookupOrCreate(DAT_00d1f050,&param_1,&DAT_00d1f734,0,0);

  if (piVar2 != (int *)0x0) {

    (**(code **)(*piVar2 + 4))();

    uVar1 = FUN_0075d5b0(0);

    iVar3 = NDResource_AcquireInnerObject();

    if (iVar3 == 0) {

      piVar6 = (int *)0x0;

    }

    else {

      piVar6 = *(int **)(iVar3 + 4);

    }

    if ((char)piVar2[0xe] != '\0') {

      EnterCriticalSection((LPCRITICAL_SECTION)(piVar2 + 8));

    }

    if (piVar2[4] != 0) {

      piVar2[4] = piVar2[4] + -1;

    }

    if ((char)piVar2[0xe] != '\0') {

      LeaveCriticalSection((LPCRITICAL_SECTION)(piVar2 + 8));

    }

    FUN_0075d5b0(uVar1);

    if (piVar6 != (int *)0x0) {

      puVar4 = operator_new(0x18);

      uStack_4 = 0;

      if (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

        iVar3 = piVar6[1];

        uVar5 = (**(code **)(*piVar6 + 0x1c))();

        puVar4[1] = iVar3;

        puVar4[3] = uVar5;

        puVar4[4] = uVar5;

        *puVar4 = &PTR_FUN_00a9d184;

        puVar4[2] = 0;

        *(uint8_t *)(puVar4 + 5) = 0;

        *(uint8_t *)((int)puVar4 + 0x15) = 1;

        ExceptionList = local_c;

        return puVar4;

      }

    }

    ExceptionList = local_c;

    return (uint32_t /* width from decompiler */ *)0x0;

  }

  ExceptionList = local_c;

  return (uint32_t /* width from decompiler */ *)0x0;

}
