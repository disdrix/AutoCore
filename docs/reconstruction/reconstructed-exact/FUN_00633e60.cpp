// =============================================================================
// FUN_00633e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00633e60
// Address:   0x00633e60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00633e60 @ 0x00633e60
// Stable ID: aa_00633e60
// Embedded strings (evidence for future rename):
//   - "%s(%d)"
//   - "%s!0x%08X"
//   - "0x%08X"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: return×3, for×2, if×2, do×1, while×1.
//  - Notable callees: sprintf×3, FUN_00633a10, FUN_00633e60, GetCurrentProcess, SymGetLineFromAddr, s.
//  - Strings: "%s(%d)"; "%s!0x%08X"; "0x%08X".
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

uint32_t /* width from decompiler */ FUN_00633e60(uint32_t /* width from decompiler */ param_1,char *param_2)



{

  char cVar1;

  HANDLE pvVar2;

  char *pcVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint8_t *puVar7;

  uint32_t /* width from decompiler */ local_420;

  uint32_t /* width from decompiler */ local_41c;

  uint32_t /* width from decompiler */ local_418;

  char *local_414;

  uint32_t /* width from decompiler */ local_410;

  uint8_t local_40c [4];

  char local_408;

  uint32_t /* width from decompiler */ local_407;

  char local_208;

  uint32_t /* width from decompiler */ local_207;

  

  local_208 = '\0';

  puVar5 = &local_207;

  for (iVar4 = 0x7f; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  *(uint8_t *)((int)puVar5 + 2) = 0;

  local_408 = '\0';

  puVar5 = &local_407;

  for (iVar4 = 0x7f; iVar4 != 0; iVar4 = iVar4 + -1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  *(uint16_t *)puVar5 = 0;

  *(uint8_t *)((int)puVar5 + 2) = 0;

  *(uint32_t /* width from decompiler */ *)param_2 = DAT_009e3714;

  param_2[4] = DAT_009e3718;

  local_41c = 0;

  puVar5 = &local_420;

  puVar7 = local_40c;

  local_418 = 0;

  local_414 = (char *)0x0;

  local_410 = 0;

  local_420 = 0x14;

  uVar6 = param_1;

  pvVar2 = GetCurrentProcess();

  iVar4 = SymGetLineFromAddr(pvVar2,uVar6,puVar7,puVar5);

  if (iVar4 != 0) {

    pcVar3 = local_414;

    do {

      cVar1 = *pcVar3;

      pcVar3[(int)(&local_208 + -(int)local_414)] = cVar1;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    sprintf(param_2,"%s(%d)",&local_208,local_418);

    return 1;

  }

  FUN_00633a10(param_1,&local_408);

  if ((local_408 != '?') && (local_408 != '\0')) {

    sprintf(param_2,"%s!0x%08X",&local_408,param_1);

    return 0;

  }

  sprintf(param_2,"0x%08X",param_1);

  return 0;

}
