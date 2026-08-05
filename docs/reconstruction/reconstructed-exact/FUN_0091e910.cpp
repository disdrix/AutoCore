// =============================================================================
// FUN_0091e910
// -----------------------------------------------------------------------------
// Stable ID: aa_0091e910
// Address:   0x0091e910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0091e910 @ 0x0091e910
// Stable ID: aa_0091e910
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×3, do×2, while×2, return×2.
//  - Notable callees: FUN_004e88e0, FUN_00574760, FUN_0087bb10, FUN_0091e910, FUN_00936210.
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

void FUN_0091e910(void)



{

  int iVar1;

  int in_EAX;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint32_t /* width from decompiler */ uStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  uint8_t auStack_c [12];

  

  if ((*(int *)(DAT_00d1b6d8 + 0xcb0) != 0) && (*(char *)(in_EAX + 0xce1) != '\0')) {

    iVar7 = 0;

    piVar6 = (int *)(in_EAX + 0xc8c);

    do {

      iVar2 = FUN_00574760(iVar7);

      if ((iVar2 == 0) || (iVar2 == DAT_00d1b6d8)) {

        (**(code **)(*(int *)*piVar6 + 4))(0);

      }

      else {

        uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x1a0))();

        FUN_004e88e0(&uStack_30,uVar3);

        iVar5 = *piVar6;

        uStack_24 = uStack_30;

        uStack_20 = uStack_2c;

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x508) = uStack_30;

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x50c) = uStack_2c;

        uStack_1c = uStack_28;

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x510) = uStack_28;

        puVar4 = (uint32_t /* width from decompiler */ *)FUN_00936210(&DAT_00d1a840,auStack_c);

        uStack_30 = *puVar4;

        uStack_2c = puVar4[1];

        iVar5 = *piVar6;

        uStack_28 = puVar4[2];

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x514) = uStack_30;

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x518) = uStack_2c;

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x51c) = uStack_28;

        iVar5 = *(int *)(*(int *)(iVar2 + 4) + 4);

        if ((*(uint *)(iVar5 + 0x188 + iVar2) >> 1 & 1) == 0) {

          iVar5 = 0;

        }

        else {

          iVar5 = -(int)*(float *)(iVar5 + iVar2 + 0x11c);

        }

        iVar1 = *piVar6;

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x520) = 0;

        *(int *)(iVar1 + 0x524) = iVar5;

        uStack_18 = uStack_30;

        uStack_14 = uStack_2c;

        uStack_10 = uStack_28;

        (**(code **)(*(int *)*piVar6 + 0xcc))(1);

        (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x160))();

        FUN_0087bb10();

        (**(code **)(*(int *)*piVar6 + 0x34c))();

      }

      iVar7 = iVar7 + 1;

      piVar6 = piVar6 + 1;

    } while (iVar7 < 4);

    return;

  }

  puVar4 = (uint32_t /* width from decompiler */ *)(in_EAX + 0xc8c);

  iVar7 = 4;

  do {

    (**(code **)(*(int *)*puVar4 + 4))(0);

    puVar4 = puVar4 + 1;

    iVar7 = iVar7 + -1;

  } while (iVar7 != 0);

  return;

}
