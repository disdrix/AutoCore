// =============================================================================
// FUN_005e5e50
// -----------------------------------------------------------------------------
// Stable ID: aa_005e5e50
// Address:   0x005e5e50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e5e50 @ 0x005e5e50
// Stable ID: aa_005e5e50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~75 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, return×1, goto×1, while×1.
//  - Notable callees: FUN_005e5e50, FUN_0076e240.
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

void __fastcall FUN_005e5e50(int *param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uStack_7c;

  uint8_t *puStack_78;

  uint8_t *puStack_74;

  int *piStack_70;

  int *piStack_6c;

  uint8_t auStack_5c [4];

  uint8_t auStack_58 [12];

  uint8_t auStack_4c [20];

  uint8_t auStack_38 [4];

  uint32_t /* width from decompiler */ uStack_34;

  uint8_t auStack_30 [20];

  uint8_t auStack_1c [8];

  uint8_t auStack_14 [16];

  

  iVar5 = 0;

LAB_005e5e60:

  do {

    if (param_1[5] == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = param_1[6] - param_1[5] >> 2;

    }

    if (iVar2 <= iVar5) {

      return;

    }

    iVar2 = iVar5 * 4;

    if (*(int *)(iVar2 + param_1[5]) != 0) {

      piStack_6c = (int *)0x5e5e99;

      iVar3 = (**(code **)(**(int **)(iVar2 + param_1[5]) + 0x1c))();

      if (iVar3 != 0) {

        piStack_70 = (int *)0x5e5ead;

        piStack_6c = param_1;

        iVar3 = (**(code **)(**(int **)(iVar2 + param_1[5]) + 0x3c))();

        puStack_74 = auStack_14;

        puStack_78 = auStack_1c;

        piStack_70 = param_1;

        if (iVar3 == 0) {

          uStack_7c = 0x5e5ec7;

          (**(code **)(**(int **)(iVar2 + param_1[5]) + 0x38))();

        }

        else {

          uStack_7c = 0x5e5ecc;

          (**(code **)(**(int **)(iVar2 + param_1[5]) + 0x34))();

        }

        uStack_7c = *(uint32_t /* width from decompiler */ *)(iVar2 + param_1[5]);

        (**(code **)(*param_1 + 0x34))(auStack_30,auStack_38);

        uVar1 = uStack_34;

        (**(code **)(*param_1 + 0xa0))(auStack_5c,iVar5);

        uStack_7c = 0;

        puStack_78 = (uint8_t *)g_flOne;

        puStack_74 = (uint8_t *)0x0;

        FUN_0076e240(auStack_58,&stack0xffffff9c,&uStack_7c);

        piVar4 = (int *)(**(code **)(**(int **)(iVar2 + param_1[5]) + 0x1c))();

        (**(code **)(*piVar4 + 0xc0))

                  (auStack_4c,param_1[0x66] + iVar2,piStack_70,0,uVar1,auStack_58,0);

        iVar5 = iVar5 + 1;

        goto LAB_005e5e60;

      }

    }

    if (*(uint32_t /* width from decompiler */ **)(iVar2 + param_1[0x66]) != (uint32_t /* width from decompiler */ *)0x0) {

      piStack_6c = (int *)0x1;

      piStack_70 = (int *)0x5e5fa7;

      (**(code **)**(uint32_t /* width from decompiler */ **)(iVar2 + param_1[0x66]))();

    }

    *(uint32_t /* width from decompiler */ *)(iVar2 + param_1[0x66]) = 0;

    iVar5 = iVar5 + 1;

  } while( true );

}
