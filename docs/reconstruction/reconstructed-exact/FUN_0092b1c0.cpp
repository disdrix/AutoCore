// =============================================================================
// FUN_0092b1c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0092b1c0
// Address:   0x0092b1c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092b1c0 @ 0x0092b1c0
// Stable ID: aa_0092b1c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×6, goto×2, while×2, return×2, do×1.
//  - Notable callees: FUN_004022a0×2, CVOGCharacter_WeaponAllowsKillXpBonus, FUN_004294f0, FUN_00563440, FUN_0092b1c0, LeaveCriticalSection.
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

uint32_t /* width from decompiler */ FUN_0092b1c0(void)



{

  char cVar1;

  int *in_EAX;

  int iVar2;

  int iVar3;

  int *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  *(uint8_t *)((int)in_EAX + 6) = 0;

  cVar1 = CVOGCharacter_WeaponAllowsKillXpBonus();

  if (cVar1 != '\0') {

    iVar3 = *(int *)(*(int *)(*in_EAX + 0xd34) + 0x18);

    iVar3 = *(int *)(*(int *)(*(int *)(iVar3 + 0x10) + (*(uint *)(iVar3 + 8) & 0x36) * 4) + 4);

    if (iVar3 == 0) {

LAB_0092b215:

      iVar3 = 0;

    }

    else {

      do {

        if (*(int *)(iVar3 + 0x10) == 0x36) {

          if (iVar3 == 0) goto LAB_0092b215;

          iVar3 = *(int *)(iVar3 + 8);

          goto LAB_0092b21c;

        }

        iVar3 = *(int *)(iVar3 + 0xc);

      } while (iVar3 != 0);

      iVar3 = 0;

    }

LAB_0092b21c:

    if (iVar3 != 0) {

      local_4 = 0;

      local_8 = (int *)0x0;

      FUN_004294f0();

      iVar2 = FUN_004022a0(&local_4,&local_8);

      while (iVar2 == 0) {

        (**(code **)(*local_8 + 0x1ec))();

        FUN_00563440();

        iVar2 = FUN_004022a0(&local_4,&local_8);

      }

      if (*(char *)(iVar3 + 0x28) != '\0') {

        *(uint8_t *)(iVar3 + 0x28) = 0;

        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 4));

      }

      return 1;

    }

  }

  return 0;

}
