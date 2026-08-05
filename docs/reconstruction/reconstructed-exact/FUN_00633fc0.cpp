// =============================================================================
// FUN_00633fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00633fc0
// Address:   0x00633fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00633fc0 @ 0x00633fc0
// Stable ID: aa_00633fc0
// Embedded strings (evidence for future rename):
//   - "Call stack info(thread=0x%X) failed.%s"
//   - "Call stack info(thread=0x%X) : %s%s"
//   - "     %s : %s \t\t"
//   - "Params(1:%x 2:%x 3:%x 4:%x)%s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~96 non-empty decompiler lines.
//  - Control keywords: for×5, if×4, return×2, goto×1, while×1.
//  - Notable callees: FUN_00633720×4, GetCurrentThread×2, StackWalk×2, info×2, FUN_00633a90, FUN_00633e60, FUN_00633fc0, GetCurrentProcess.
//  - Strings: "Call stack info(thread=0x%X) failed.%s"; "Call stack info(thread=0x%X) : %s%s"; "     %s : %s \t\t"; "Params(1:%x 2:%x 3:%x 4:%x)%s".
//  - Return sites: 2.

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

void FUN_00633fc0(HANDLE param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 DWORD *param_5)



{

  HANDLE pvVar1;

  HANDLE pvVar2;

  DWORD DVar3;

  BOOL BVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  CONTEXT *pCVar7;

  DWORD *pDVar8;

  uint32_t /* width from decompiler */ uVar9;

  DWORD local_780 [6];

  DWORD local_768;

  uint32_t /* width from decompiler */ local_760;

  DWORD local_75c;

  uint32_t /* width from decompiler */ local_754;

  uint32_t /* width from decompiler */ local_74c;

  uint32_t /* width from decompiler */ local_748;

  uint32_t /* width from decompiler */ local_744;

  uint32_t /* width from decompiler */ local_740;

  CONTEXT local_6d8;

  uint16_t local_408;

  uint32_t /* width from decompiler */ local_406 [127];

  uint16_t local_208;

  uint32_t /* width from decompiler */ local_206 [128];

  

  local_408 = 0x3f;

  puVar6 = local_406;

  for (iVar5 = 0x7f; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  *(uint16_t *)puVar6 = 0;

  local_208 = 0x3f;

  puVar6 = local_206;

  for (iVar5 = 0x7f; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  *(uint16_t *)puVar6 = 0;

  pvVar1 = GetCurrentProcess();

  pvVar2 = GetCurrentThread();

  if ((param_1 != pvVar2) && (DVar3 = SuspendThread(param_1), DVar3 == 0xffffffff)) {

LAB_006341d0:

    FUN_00633720(param_3,"Call stack info(thread=0x%X) failed.%s",param_4);

    return;

  }

  pCVar7 = &local_6d8;

  for (iVar5 = 0xb3; iVar5 != 0; iVar5 = iVar5 + -1) {

    pCVar7->ContextFlags = 0;

    pCVar7 = (CONTEXT *)&pCVar7->Dr0;

  }

  if (param_5 == (DWORD *)0x0) {

    local_6d8.ContextFlags = 0x1003f;

    BVar4 = GetThreadContext(param_1,&local_6d8);

    if (BVar4 == 0) goto LAB_006341d0;

  }

  else {

    pCVar7 = &local_6d8;

    for (iVar5 = 0xb3; iVar5 != 0; iVar5 = iVar5 + -1) {

      pCVar7->ContextFlags = *param_5;

      param_5 = param_5 + 1;

      pCVar7 = (CONTEXT *)&pCVar7->Dr0;

    }

  }

  pDVar8 = local_780;

  for (iVar5 = 0x29; iVar5 != 0; iVar5 = iVar5 + -1) {

    *pDVar8 = 0;

    pDVar8 = pDVar8 + 1;

  }

  local_780[0] = local_6d8.Eip;

  local_75c = local_6d8.Esp;

  local_768 = local_6d8.Ebp;

  local_780[2] = 3;

  local_754 = 3;

  local_760 = 3;

  uVar9 = param_4;

  DVar3 = GetCurrentThreadId();

  FUN_00633720(param_3,"Call stack info(thread=0x%X) : %s%s",DVar3,param_2,uVar9);

  iVar5 = StackWalk(0x14c,pvVar1,param_1,local_780,&local_6d8,0,SymFunctionTableAccess_exref,

                    SymGetModuleBase_exref,0);

  while ((iVar5 != 0 && (local_768 != 0))) {

    FUN_00633a90(local_780[0],local_768,&local_408);

    FUN_00633e60(local_780[0],&local_208);

    FUN_00633720(param_3,"     %s : %s \t\t",&local_208,&local_408);

    FUN_00633720(param_3,"Params(1:%x 2:%x 3:%x 4:%x)%s",local_74c,local_748,local_744,local_740,

                 param_4);

    iVar5 = StackWalk(0x14c,pvVar1,param_1,local_780,&local_6d8,0,SymFunctionTableAccess_exref,

                      SymGetModuleBase_exref,0);

  }

  pvVar1 = GetCurrentThread();

  if (param_1 != pvVar1) {

    ResumeThread(param_1);

  }

  return;

}
