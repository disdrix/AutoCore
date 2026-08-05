// =============================================================================
// FUN_005795d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005795d0
// Address:   0x005795d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005795d0 @ 0x005795d0
// Stable ID: aa_005795d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: if×16, goto×6, return×4, do×3, while×3.
//  - Notable callees: FUN_00785ca0×3, CVOGMap_LookupVariable×2, CVOGReaction_ResolveObjectTarget×2, CONCAT31, FUN_00517680, FUN_005795d0.
//  - Return sites: 4.

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



uint __fastcall FUN_005795d0(int param_1)



{

  char *pcVar1;

  char cVar2;

  uint32_t /* width from decompiler */ in_EAX;

  uint uVar3;

  char *pcVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint8_t local_8 [4];

  uint8_t local_4 [4];

  

  cVar2 = *(char *)(param_1 + 0x1d1);

  uVar3 = CONCAT31((int3)((uint)in_EAX >> 8),cVar2);

  if (((((cVar2 < '\0') || ('W' < cVar2)) || (uVar3 = *(uint *)(param_1 + 0x1f8), (int)uVar3 < 0))

      || ((8 < (int)uVar3 || (uVar3 = *(uint *)(param_1 + 0x1fc), (int)uVar3 < 0)))) ||

     ((0x400 < (int)uVar3 ||

      ((uVar3 = *(uint *)(param_1 + 0x200), (int)uVar3 < 0 || (0x400 < (int)uVar3)))))) {

    return uVar3 & 0xffffff00;

  }

  iVar5 = 0;

  iVar6 = 0;

  if (*(char *)(param_1 + 0x228) == '\0') {

    uVar3 = *(uint *)(param_1 + 0x218);

    if ((uVar3 & *(uint *)(param_1 + 0x21c)) == 0xffffffff) goto LAB_005796ab;

    iVar6 = CVOGReaction_ResolveObjectTarget(0,uVar3,*(uint *)(param_1 + 0x21c));

    uVar3 = 0;

    if (iVar6 == 0) goto LAB_005796ab;

  }

  if (*(char *)(param_1 + 0x229) == '\0') {

    uVar3 = *(uint *)(param_1 + 0x220);

    if ((uVar3 & *(uint *)(param_1 + 0x224)) == 0xffffffff) {

LAB_005796ab:

      return uVar3 & 0xffffff00;

    }

    iVar5 = CVOGReaction_ResolveObjectTarget(0,uVar3,*(uint *)(param_1 + 0x224));

    uVar3 = 0;

    if (iVar5 == 0) goto LAB_005796ab;

  }

  puVar7 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x20c);

  if (puVar7 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x210)) {

    do {

      uVar3 = CVOGMap_LookupVariable(*puVar7,local_8,iVar6);

      if (((char)uVar3 == '\0') ||

         (uVar3 = CVOGMap_LookupVariable(puVar7[1],local_4,iVar5), (char)uVar3 == '\0'))

      goto LAB_00579802;

      puVar7 = puVar7 + 3;

    } while (puVar7 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x210));

  }

  uVar3 = FUN_00785ca0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x22c));

  if ((char)uVar3 == '\0') {

    pcVar4 = *(char **)(param_1 + 0x22c);

    if (pcVar4 != (char *)0x0) {

      pcVar1 = pcVar4 + 1;

      do {

        cVar2 = *pcVar4;

        pcVar4 = pcVar4 + 1;

      } while (cVar2 != '\0');

      uVar3 = (int)pcVar4 - (int)pcVar1;

      if (0x104 < uVar3) goto LAB_00579802;

    }

    uVar3 = FUN_00785ca0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x250));

    if ((char)uVar3 == '\0') {

      pcVar4 = *(char **)(param_1 + 0x250);

      if (pcVar4 != (char *)0x0) {

        pcVar1 = pcVar4 + 1;

        do {

          cVar2 = *pcVar4;

          pcVar4 = pcVar4 + 1;

        } while (cVar2 != '\0');

        uVar3 = (int)pcVar4 - (int)pcVar1;

        if (0x104 < uVar3) goto LAB_00579802;

      }

      uVar3 = *(uint *)(param_1 + 0x254);

      if (((((-1 < (int)uVar3) && ((int)uVar3 < 3)) &&

           (uVar3 = FUN_00785ca0(*(uint32_t /* width from decompiler */ *)(param_1 + 600)), (char)uVar3 == '\0')) &&

          (((uVar3 = *(uint *)(param_1 + 0x25c), -1 < (int)uVar3 && ((int)uVar3 < 0x2801)) &&

           ((0.0 < *(float *)(param_1 + 0x260) || *(float *)(param_1 + 0x260) == 0.0 &&

            ((*(float *)(param_1 + 0x260) <= _DAT_009d4130 &&

             (uVar3 = *(uint *)(param_1 + 0x264), -1 < (int)uVar3)))))))) && ((int)uVar3 < 0x2801))

      {

        uVar3 = FUN_00517680();

        return uVar3;

      }

    }

  }

LAB_00579802:

  return uVar3 & 0xffffff00;

}
