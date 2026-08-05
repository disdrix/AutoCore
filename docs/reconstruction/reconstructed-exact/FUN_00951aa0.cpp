// =============================================================================
// FUN_00951aa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00951aa0
// Address:   0x00951aa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00951aa0 @ 0x00951aa0
// Stable ID: aa_00951aa0
// Embedded strings (evidence for future rename):
//   - "Object %d %I64d had an owner %I64d. Good:%d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×2, while×1, return×1.
//  - Notable callees: FUN_004022a0×2, FUN_004294f0, FUN_007a4480, FUN_00951aa0, LeaveCriticalSection.
//  - Strings: "Object %d %I64d had an owner %I64d. Good:%d".
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

uint32_t /* width from decompiler */ __fastcall FUN_00951aa0(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint8_t uVar3;

  int iVar4;

  int iVar5;

  int *local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  int local_4;

  

  iVar5 = *(int *)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 0xa8 +

                                    *(int *)(param_1 + 0xe98)) + 0xe4e8) + 0x20);

  local_4 = iVar5;

  FUN_004294f0();

  local_10 = (int *)0x0;

  local_c = 0;

  iVar4 = FUN_004022a0(&local_c,&local_10);

  while (iVar4 == 0) {

    iVar4 = local_10[0x2b];

    if (iVar4 != 0) {

      uVar1 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x160);

      uVar2 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x164);

      local_8 = *(uint32_t /* width from decompiler */ *)(local_10[0x2a] + 0x34);

      iVar5 = local_10[0x58];

      iVar4 = local_10[0x59];

      uVar3 = (**(code **)(*local_10 + 0x128))();

      FUN_007a4480(0,"Object %d %I64d had an owner %I64d. Good:%d",local_8,iVar5,iVar4,uVar1,uVar2,

                   uVar3);

      iVar5 = local_4;

    }

    iVar4 = FUN_004022a0(&local_c,&local_10);

  }

  if (*(char *)(iVar5 + 0x28) != '\0') {

    *(uint8_t *)(iVar5 + 0x28) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar5 + 4));

  }

  return 0;

}
