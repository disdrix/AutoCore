// =============================================================================
// Named_Function_info_thread_failed
// -----------------------------------------------------------------------------
// Stable ID: aa_006341f0
// Address:   0x006341f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Function_info_thread_failed @ 0x006341f0
// Stable ID: aa_006341f0
// Embedded strings (evidence for future rename):
//   - "Function info(thread=0x%X) failed.\n"
//   - "Function info(thread=0x%X) : %s\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×3, for×3, return×3, do×1, while×1.
//  - Notable callees: FUN_00633720×3, info×3, FUN_00633a90, Named_Function_info_thread_failed, GetCurrentProcess, GetCurrentThread, GetCurrentThreadId, GetThreadContext.
//  - Strings: "Function info(thread=0x%X) failed.\n"; "Function info(thread=0x%X) : %s\n".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Function info(thread=0x%X) failed.
"
 * Domain alias of FUN_006341f0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_Function_info_thread_failed(uint32_t /* width from decompiler */ param_1,DWORD *param_2)



{

  HANDLE pvVar1;

  HANDLE hThread;

  BOOL BVar2;

  int iVar3;

  DWORD DVar4;

  int iVar5;

  CONTEXT *pCVar6;

  DWORD *pDVar7;

  uint8_t *puVar8;

  DWORD local_580 [6];

  DWORD local_568;

  uint32_t /* width from decompiler */ local_560;

  DWORD local_55c;

  uint32_t /* width from decompiler */ local_554;

  CONTEXT local_4d8;

  uint8_t local_208 [516];

  

  pvVar1 = GetCurrentProcess();

  hThread = GetCurrentThread();

  pCVar6 = &local_4d8;

  iVar5 = 0xb3;

  if (param_2 == (DWORD *)0x0) {

    for (; iVar5 != 0; iVar5 = iVar5 + -1) {

      pCVar6->ContextFlags = 0;

      pCVar6 = (CONTEXT *)&pCVar6->Dr0;

    }

    local_4d8.ContextFlags = 0x10007;

    BVar2 = GetThreadContext(hThread,&local_4d8);

    if (BVar2 == 0) {

      FUN_00633720(param_1,"Function info(thread=0x%X) failed.\n");

      return;

    }

  }

  else {

    for (; iVar5 != 0; iVar5 = iVar5 + -1) {

      pCVar6->ContextFlags = *param_2;

      param_2 = param_2 + 1;

      pCVar6 = (CONTEXT *)&pCVar6->Dr0;

    }

  }

  pDVar7 = local_580;

  for (iVar5 = 0x29; iVar5 != 0; iVar5 = iVar5 + -1) {

    *pDVar7 = 0;

    pDVar7 = pDVar7 + 1;

  }

  local_55c = local_4d8.Esp;

  local_4d8.ContextFlags = 0x10007;

  local_580[0] = local_4d8.Eip;

  local_568 = local_4d8.Ebp;

  local_580[2] = 3;

  local_554 = 3;

  local_560 = 3;

  iVar5 = 2;

  do {

    iVar3 = StackWalk(0x14c,pvVar1,hThread,local_580,0,0,SymFunctionTableAccess_exref,

                      SymGetModuleBase_exref,0);

    iVar5 = iVar5 + -1;

  } while (iVar5 != 0);

  if ((iVar3 != 0) && (local_568 != 0)) {

    FUN_00633a90(local_580[0],local_568,local_208);

    puVar8 = local_208;

    DVar4 = GetCurrentThreadId();

    FUN_00633720(param_1,"Function info(thread=0x%X) : %s\n",DVar4,puVar8);

    return;

  }

  FUN_00633720(param_1,"Function info(thread=0x%X) failed.\n");

  return;

}
