// =============================================================================
// FUN_004c8050
// -----------------------------------------------------------------------------
// Stable ID: aa_004c8050
// Address:   0x004c8050  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c8050 @ 0x004c8050
// Stable ID: aa_004c8050
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, if×1, return×1.
//  - Notable callees: FUN_00403450, FUN_004c8050, FUN_00585ae0, free.
//  - Return sites: 1.

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

void __fastcall FUN_004c8050(int param_1)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uStack_18c;

  char *local_188;

  char local_184 [128];

  char acStack_104 [260];

  

  iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);

  local_188 = local_184;

  uVar3 = (*(code *)PTR_FUN_00af8c9c)();

  FUN_00403450(iVar2 + 0x10,uVar3);

  pcVar4 = local_188;

  do {

    cVar1 = *pcVar4;

    pcVar4[(int)(acStack_104 + -(int)local_188)] = cVar1;

    pcVar4 = pcVar4 + 1;

  } while (cVar1 != '\0');

  if (local_188 != local_184) {

    free(local_188);

  }

  iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);

  uStack_18c = *(uint32_t /* width from decompiler */ *)(param_1 + 0x48);

  FUN_00585ae0(&uStack_18c,1,acStack_104,*(uint32_t /* width from decompiler */ *)(iVar2 + 0x504),

               *(uint32_t /* width from decompiler */ *)(iVar2 + 0x508),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x50c),&DAT_00a1419b);

  return;

}
