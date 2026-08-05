// =============================================================================
// FUN_00522e90
// -----------------------------------------------------------------------------
// Stable ID: aa_00522e90
// Address:   0x00522e90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00522e90 @ 0x00522e90
// Stable ID: aa_00522e90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: CARRY4×2, FUN_004022a0×2, CONCAT44, FUN_004294f0, FUN_00522e90, LeaveCriticalSection.
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

uint64_t __fastcall FUN_00522e90(int param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  uint uVar4;

  int iVar5;

  uint uVar6;

  bool bVar7;

  int *local_10;

  uint32_t /* width from decompiler */ local_c;

  int iStack_8;

  int local_4;

  

  iVar1 = *(int *)(param_1 + 0xce0);

  iVar5 = 0;

  local_c = 0;

  uVar6 = 0;

  local_4 = param_1;

  FUN_004294f0();

  iVar3 = FUN_004022a0(&local_c,&local_10);

  if (iVar3 == 0) {

    iVar5 = 0;

    do {

      piVar2 = local_10;

      iStack_8 = (**(code **)(*local_10 + 0x25c))();

      iVar3 = (**(code **)(*piVar2 + 0x168))();

      uVar4 = iVar3 * iStack_8;

      bVar7 = CARRY4(uVar6,uVar4);

      uVar6 = uVar6 + uVar4;

      iVar5 = iVar5 + ((int)uVar4 >> 0x1f) + (uint)bVar7;

      iVar3 = FUN_004022a0(&local_c,&local_10);

      param_1 = local_4;

    } while (iVar3 == 0);

  }

  if (*(char *)(iVar1 + 0x54) != '\0') {

    *(uint8_t *)(iVar1 + 0x54) = 0;

    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x30));

  }

  return CONCAT44(*(int *)(param_1 + 0xcec) + iVar5 + (uint)CARRY4(*(uint *)(param_1 + 0xce8),uVar6)

                  ,*(uint *)(param_1 + 0xce8) + uVar6);

}
