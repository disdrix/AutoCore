// =============================================================================
// FUN_004f3f70
// -----------------------------------------------------------------------------
// Stable ID: aa_004f3f70
// Address:   0x004f3f70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f3f70 @ 0x004f3f70
// Stable ID: aa_004f3f70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: if×13, return×6, while×1, goto×1.
//  - Notable callees: FUN_0053dee0×5, NetObject_SetMaskBits×4, FUN_004f3f70, FUN_0053e820.
//  - Return sites: 6.

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

uint32_t /* width from decompiler */ __fastcall FUN_004f3f70(int param_1)



{

  uint *puVar1;

  void *pvVar2;

  int iVar3;

  int iVar4;

  char cVar5;

  uint32_t /* width from decompiler */ uVar6;

  char cVar7;

  

  if ((*(char *)(param_1 + 0x61c) == '\0') && (*(char *)(param_1 + 0x109) == '\0')) {

    cVar5 = '\0';

  }

  else {

    cVar5 = '\x01';

  }

  if (*(char *)(param_1 + 0x130) != cVar5) {

    pvVar2 = *(void **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x18 + param_1);

    if (pvVar2 != (void *)0x0) {

      NetObject_SetMaskBits(pvVar2,2,0);

    }

    if ((*(char *)(param_1 + 0x61c) == '\0') && (*(char *)(param_1 + 0x109) == '\0')) {

      *(uint8_t *)(param_1 + 0x130) = 0;

      FUN_0053dee0();

      return 1;

    }

    *(uint8_t *)(param_1 + 0x130) = 1;

    FUN_0053dee0();

    return 1;

  }

  cVar7 = '\0';

  cVar5 = '\0';

  while ((iVar3 = *(int *)(*(int *)(param_1 + 0x260) + cVar5 * 4), iVar3 == 0 ||

         (*(char *)(iVar3 + 199) == '\0'))) {

    cVar5 = cVar5 + '\x01';

    if ('\x02' < cVar5) {

LAB_004f4013:

      if (*(char *)(param_1 + 0x131) != cVar7) {

        pvVar2 = *(void **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x18 + param_1);

        if (pvVar2 != (void *)0x0) {

          NetObject_SetMaskBits(pvVar2,2,0);

        }

        *(char *)(param_1 + 0x131) = cVar7;

        FUN_0053dee0();

        return 1;

      }

      iVar3 = *(int *)(*(int *)(param_1 + 4) + 4);

      iVar4 = *(int *)(iVar3 + 0xb0 + param_1);

      iVar3 = iVar3 + param_1;

      if (iVar4 != 0) {

        iVar4 = *(int *)(iVar4 + 0xa0);

        puVar1 = (uint *)(param_1 + 0x120);

        if (iVar4 == 0) {

          if (((*puVar1 & *(uint *)(param_1 + 0x124)) != 0xffffffff) ||

             (*(char *)(param_1 + 0x128) != '\0')) {

            pvVar2 = *(void **)(iVar3 + 0x18);

            if (pvVar2 != (void *)0x0) {

              NetObject_SetMaskBits(pvVar2,4,0);

            }

            FUN_0053dee0();

            *puVar1 = DAT_009cd0f8;

            *(uint32_t /* width from decompiler */ *)(param_1 + 0x124) = DAT_009cd0fc;

            *(uint32_t /* width from decompiler */ *)(param_1 + 0x128) = DAT_009cd100;

            *(uint32_t /* width from decompiler */ *)(param_1 + 300) = DAT_009cd104;

            return 1;

          }

        }

        else if (((*(uint *)(iVar4 + 0x160) != *puVar1) ||

                 (*(int *)(iVar4 + 0x164) != *(int *)(param_1 + 0x124))) ||

                (*(char *)(iVar4 + 0x168) != *(char *)(param_1 + 0x128))) {

          pvVar2 = *(void **)(iVar3 + 0x18);

          if (pvVar2 != (void *)0x0) {

            NetObject_SetMaskBits(pvVar2,4,0);

          }

          FUN_0053dee0();

          iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1) + 0xa0);

          *puVar1 = *(uint *)(iVar3 + 0x160);

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x124) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x164);

          *(uint32_t /* width from decompiler */ *)(param_1 + 0x128) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x168);

          *(uint32_t /* width from decompiler */ *)(param_1 + 300) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x16c);

          return 1;

        }

      }

      uVar6 = FUN_0053e820();

      return uVar6;

    }

  }

  cVar7 = '\x01';

  goto LAB_004f4013;

}
