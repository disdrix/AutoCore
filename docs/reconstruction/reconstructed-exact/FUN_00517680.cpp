// =============================================================================
// FUN_00517680
// -----------------------------------------------------------------------------
// Stable ID: aa_00517680
// Address:   0x00517680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00517680 @ 0x00517680
// Stable ID: aa_00517680
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~106 non-empty decompiler lines.
//  - Control keywords: if×20, return×16, do×1, while×1.
//  - Notable callees: FUN_00785ca0×16, Object_ResolveFromTFID×2, ABS, CVOGReaction_ResolveObjectTarget, FUN_00404d70, FUN_00517680, FUN_005d6870.
//  - Return sites: 16.

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



bool __fastcall FUN_00517680(int param_1)



{

  char cVar1;

  int iVar2;

  void *pvVar3;

  char *pcVar4;

  uint uVar5;

  uint *puVar6;

  uint32_t /* width from decompiler */ uStack_4;

  

  if (param_1 == 0) {

    return false;

  }

  uStack_4 = param_1;

  cVar1 = FUN_00785ca0(param_1);

  if (cVar1 != '\0') {

    return false;

  }

  if ((*(int *)(param_1 + 0x130) != 0) &&

     (cVar1 = FUN_00785ca0(*(int *)(param_1 + 0x130)), cVar1 != '\0')) {

    return false;

  }

  if (*(int *)(param_1 + 0x10) < -1) {

    return false;

  }

  if (*(int *)(param_1 + 0x10) < 0x81) {

    if (*(int *)(param_1 + 0xa4) == 0) {

      return false;

    }

    cVar1 = FUN_00785ca0(*(int *)(param_1 + 0xa4));

    if (cVar1 != '\0') {

      return false;

    }

    uVar5 = 0;

    puVar6 = (uint *)(param_1 + 0x28);

    do {

      if ((*puVar6 & puVar6[1]) != 0xffffffff) {

        iVar2 = CVOGReaction_ResolveObjectTarget(0,*puVar6,puVar6[1]);

        if (iVar2 == 0) {

          return false;

        }

        cVar1 = FUN_00785ca0(iVar2);

        if (cVar1 != '\0') {

          return false;

        }

      }

      uVar5 = uVar5 + 1;

      puVar6 = puVar6 + 2;

    } while (uVar5 < 3);

    if ((*(uint *)(param_1 + 0x40) & *(uint *)(param_1 + 0x44)) != 0xffffffff) {

      pvVar3 = Object_ResolveFromTFID((TFID_16 *)(param_1 + 0x40));

      if (pvVar3 == (void *)0x0) {

        return false;

      }

      cVar1 = FUN_00785ca0(pvVar3);

      if (cVar1 != '\0') {

        return false;

      }

    }

    cVar1 = FUN_00785ca0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x70));

    if (((((cVar1 == '\0') && (pcVar4 = (char *)FUN_005d6870((int)&uStack_4 + 3), *pcVar4 != '\0'))

         && (cVar1 = FUN_00785ca0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xa0)), cVar1 == '\0')) &&

        ((*(int *)(param_1 + 0xa0) != param_1 &&

         (cVar1 = FUN_00785ca0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xa8)), cVar1 == '\0')))) &&

       (cVar1 = FUN_00785ca0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xac)), cVar1 == '\0')) {

      if ((*(int *)(param_1 + 0xac) != 0) &&

         (pvVar3 = Object_ResolveFromTFID((TFID_16 *)(*(int *)(param_1 + 0xac) + 0x160)),

         pvVar3 == (void *)0x0)) {

        return false;

      }

      if ((*(int *)(param_1 + 0xb0) != 0) &&

         (cVar1 = FUN_00785ca0(*(int *)(param_1 + 0xb0)), cVar1 == '\0')) {

        iVar2 = *(int *)(*(int *)(param_1 + 0xa8) + 0x34);

        if (iVar2 != -1) {

          iVar2 = FUN_00404d70(iVar2);

          if (iVar2 == 0) {

            return false;

          }

          cVar1 = FUN_00785ca0(iVar2);

          if (cVar1 != '\0') {

            return false;

          }

        }

        if (((((((ABS(*(float *)(param_1 + 0xb8)) <= _DAT_009ce160) &&

                (*(float *)(param_1 + 0xc0) <= _DAT_009ce15c)) &&

               (0.0 < *(float *)(param_1 + 0xc0) || *(float *)(param_1 + 0xc0) == 0.0)) &&

              (((-1 < *(int *)(param_1 + 0xcc) && (*(int *)(param_1 + 0xcc) < 5)) &&

               ((cVar1 = FUN_00785ca0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xd0)), cVar1 == '\0' &&

                ((cVar1 = FUN_00785ca0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xd4)), cVar1 == '\0' &&

                 (cVar1 = FUN_00785ca0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xd8)), cVar1 == '\0')))))))) &&

             ((cVar1 = FUN_00785ca0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xdc)), cVar1 == '\0' &&

              (((-1 < *(short *)(param_1 + 0xea) && (*(short *)(param_1 + 0xea) < 0x401)) &&

               (-1 < *(short *)(param_1 + 0xec))))))) &&

            (((*(short *)(param_1 + 0xec) < 0x401 && (-1 < *(short *)(param_1 + 0xee))) &&

             (((*(short *)(param_1 + 0xee) < 0x401 &&

               ((-1 < *(short *)(param_1 + 0xf0) && (*(short *)(param_1 + 0xf0) < 0x401)))) &&

              (-1 < *(short *)(param_1 + 0xf2))))))) && (*(short *)(param_1 + 0xf2) < 0x401)) {

          cVar1 = FUN_00785ca0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x11c));

          return cVar1 == '\0';

        }

      }

    }

    return false;

  }

  return false;

}
