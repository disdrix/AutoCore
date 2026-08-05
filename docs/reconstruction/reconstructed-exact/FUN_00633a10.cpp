// =============================================================================
// FUN_00633a10
// -----------------------------------------------------------------------------
// Stable ID: aa_00633a10
// Address:   0x00633a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00633a10 @ 0x00633a10
// Stable ID: aa_00633a10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: return×2, for×1, if×1, do×1, while×1.
//  - Notable callees: FUN_00633a10, GetCurrentProcess, SymGetModuleInfo.
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

uint32_t /* width from decompiler */ FUN_00633a10(uint32_t /* width from decompiler */ param_1,uint16_t *param_2)



{

  char cVar1;

  HANDLE pvVar2;

  char *pcVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ local_248 [7];

  char local_22c [552];

  

  puVar5 = local_248;

  for (iVar4 = 0x8f; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  puVar5 = local_248;

  local_248[0] = 0x23c;

  pvVar2 = GetCurrentProcess();

  iVar4 = SymGetModuleInfo(pvVar2,param_1,puVar5);

  if (iVar4 != 0) {

    pcVar3 = local_22c;

    iVar4 = (int)param_2 - (int)pcVar3;

    do {

      cVar1 = *pcVar3;

      pcVar3[iVar4] = cVar1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    return 1;

  }

  *param_2 = 0x3f;

  return 0;

}
