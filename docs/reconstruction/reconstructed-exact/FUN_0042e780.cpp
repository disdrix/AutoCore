// =============================================================================
// FUN_0042e780
// -----------------------------------------------------------------------------
// Stable ID: aa_0042e780
// Address:   0x0042e780  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042e780 @ 0x0042e780
// Stable ID: aa_0042e780
// Embedded strings (evidence for future rename):
//   - "LogNetInterface"
//   - "Received Connect Accept - connection established."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~89 non-empty decompiler lines.
//  - Control keywords: if×12, return×3, do×2, while×2.
//  - Notable callees: BitStream_readBits×3, FUN_0042bdf0×2, FUN_0042c540×2, FUN_00424e30, FUN_004269b0, FUN_0042bd10, FUN_0042c5a0, FUN_0042e780.
//  - Strings: "LogNetInterface"; "Received Connect Accept - connection established.".
//  - Return sites: 3.

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

/* WARNING: Type propagation algorithm not settling */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0042e780(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  char cVar1;

  int *piVar2;

  void *pvVar3;

  int iVar4;

  uint *puVar5;

  uint *puVar6;

  bool bVar7;

  uint local_28c [6];

  uint8_t local_274 [624];

  int *piStack_4;

  

  BitStream_readBits(0x40,local_28c + 2);

  BitStream_readBits(0x40,local_28c + 4);

  local_28c[0] = *(int *)(param_3 + 0x18) + 7U >> 3;

  *(uint *)(param_3 + 0x18) = local_28c[0] * 8;

  piVar2 = (int *)FUN_0042c5a0();

  if ((piVar2 != (int *)0x0) && (piVar2[0x6e] == 4)) {

    iVar4 = 2;

    bVar7 = true;

    puVar5 = (uint *)(piVar2 + 0x4e);

    puVar6 = local_28c + 2;

    do {

      if (iVar4 == 0) break;

      iVar4 = iVar4 + -1;

      bVar7 = *puVar5 == *puVar6;

      puVar5 = puVar5 + 1;

      puVar6 = puVar6 + 1;

    } while (bVar7);

    if (bVar7) {

      iVar4 = 2;

      bVar7 = true;

      puVar5 = (uint *)(piVar2 + 0x50);

      puVar6 = local_28c + 4;

      do {

        if (iVar4 == 0) break;

        iVar4 = iVar4 + -1;

        bVar7 = *puVar5 == *puVar6;

        puVar5 = puVar5 + 1;

        puVar6 = puVar6 + 1;

      } while (bVar7);

      if (bVar7) {

        if (*(char *)((int)piVar2 + 0x135) != '\0') {

          FUN_007838a0();

          cVar1 = FUN_0042bd10(param_3,5,local_274);

          if (cVar1 == '\0') {

            FUN_0042bdf0();

            return;

          }

          FUN_0042bdf0();

        }

        FUN_00424e30(local_28c);

        piVar2[0x27] = local_28c[0];

        piVar2[0x23] = local_28c[0];

        piVar2[0x29] = local_28c[0];

        local_28c[1] = 0;

        cVar1 = (**(code **)(*piVar2 + 0x2c))(param_3,local_28c + 1);

        if (cVar1 == '\0') {

          FUN_0042c540();

          return;

        }

        if (*(char *)((int)piVar2 + 0x135) != '\0') {

          BitStream_readBits(0x80,(int)piVar2 + 0x176);

          pvVar3 = operator_new(0x274);

          if (pvVar3 != (void *)0x0) {

            FUN_007839b0();

          }

          FUN_004269b0();

        }

        (**(code **)(*piStack_4 + 0xc))(piVar2);

        FUN_0042c540();

        piVar2[0x6e] = 7;

        (**(code **)(*piVar2 + 0x14))();

        if ((_DAT_00d207f8 & 1) == 0) {

          _DAT_00d207f8 = _DAT_00d207f8 | 1;

          DAT_00d207f4 = FUN_00783b60("LogNetInterface");

        }

        if (*(char *)(DAT_00d207f4 + 4) != '\0') {

          DAT_00d179a0 = DAT_00d207f4;

          FUN_00783aa0("Received Connect Accept - connection established.");

          DAT_00d179a0 = 0;

        }

      }

    }

  }

  return;

}
