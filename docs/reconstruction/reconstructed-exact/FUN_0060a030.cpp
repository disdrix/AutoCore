// =============================================================================
// FUN_0060a030
// -----------------------------------------------------------------------------
// Stable ID: aa_0060a030
// Address:   0x0060a030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0060a030 @ 0x0060a030
// Stable ID: aa_0060a030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_004c3700, FUN_00512460, FUN_00522f70, FUN_00524680, FUN_0060a030.
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

void __fastcall FUN_0060a030(int param_1)



{

  byte bVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  uint8_t auStack_70 [24];

  uint32_t /* width from decompiler */ uStack_58;

  uint32_t /* width from decompiler */ uStack_54;

  uint32_t /* width from decompiler */ uStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint32_t /* width from decompiler */ uStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint32_t /* width from decompiler */ uStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  iVar2 = *(int *)(param_1 + 0x5c);

  if ((iVar2 != 0) && (*(int *)(param_1 + 0x50) != 0)) {

    piVar4 = (int *)(**(code **)(**(int **)(param_1 + 0x50) + 0x1dc))();

    piVar5 = *(int **)(*(int *)(*(int *)(piVar4[1] + 4) + 0xa8 + (int)piVar4) + 0xe8a0);

    if ((piVar5 == (int *)0x0) ||

       (piVar5 = (int *)(**(code **)(*piVar5 + 0x1dc))(), piVar4 != piVar5)) {

      bVar1 = *(byte *)(iVar2 + 0x12a);

      piVar4[0x18d] = piVar4[0x18d] | 1;

      piVar4[0x1ad] = (uint)bVar1;

      FUN_004c3700(*(uint8_t *)(iVar2 + 0x128));

      uStack_28 = 0;

      uStack_2c = 0;

      uStack_30 = 0;

      uStack_40 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x70);

      uStack_3c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x74);

      uStack_38 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x78);

      uStack_34 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x7c);

      uStack_58 = *(uint32_t /* width from decompiler */ *)(iVar2 + 100);

      uStack_54 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x68);

      uStack_50 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x6c);

      uStack_20 = DAT_00d02a40;

      uStack_1c = DAT_00d02a44;

      uStack_18 = DAT_00d02a48;

      uStack_4c = DAT_00d02a40;

      uStack_48 = DAT_00d02a44;

      uStack_44 = DAT_00d02a48;

      iVar3 = *(int *)(*(int *)(piVar4[1] + 4) + 0xa4 + (int)piVar4);

      if (iVar3 == 0) {

        uStack_10 = DAT_009df5b0;

        uStack_c = DAT_009df5b4;

        uStack_8 = DAT_009df5b8;

        uStack_4 = DAT_009df5bc;

      }

      else {

        uStack_10 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x160);

        uStack_c = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x164);

        uStack_8 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x168);

        uStack_4 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x16c);

      }

      (**(code **)(*piVar4 + 0x78))(auStack_70,0);

      FUN_00524680(*(uint32_t /* width from decompiler */ *)(param_1 + 0x80));

      FUN_00522f70();

      (**(code **)(*(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4) + 0x294))

                (*(uint32_t /* width from decompiler */ *)(iVar2 + 0x20));

      FUN_00512460(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x1c));

    }

  }

  return;

}
