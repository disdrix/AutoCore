// =============================================================================
// FUN_0042d960
// -----------------------------------------------------------------------------
// Stable ID: aa_0042d960
// Address:   0x0042d960  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042d960 @ 0x0042d960
// Stable ID: aa_0042d960
// Embedded strings (evidence for future rename):
//   - "LogNetInterface"
//   - "Received Challenge Response: %8x"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~116 non-empty decompiler lines.
//  - Control keywords: if×19, return×5, do×1, while×1.
//  - Notable callees: BitStream_readBits×4, FUN_00430110×3, FUN_00424e50×2, FUN_004300e0×2, FUN_0040b290, FUN_00426b40, FUN_0042be80, FUN_0042bf60.
//  - Strings: "LogNetInterface"; "Received Challenge Response: %8x".
//  - Return sites: 5.

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



void FUN_0042d960(int param_1)



{

  int *piVar1;

  char cVar2;

  uint32_t /* width from decompiler */ in_EAX;

  int *piVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  int **ppiVar7;

  int *piVar8;

  bool bVar9;

  int *local_8 [2];

  

  piVar3 = (int *)FUN_0042c5a0();

  if ((piVar3 != (int *)0x0) && (piVar3[0x6e] == 1)) {

    BitStream_readBits(0x40,local_8);

    iVar6 = 2;

    bVar9 = true;

    ppiVar7 = local_8;

    piVar8 = piVar3 + 0x4e;

    do {

      if (iVar6 == 0) break;

      iVar6 = iVar6 + -1;

      bVar9 = *ppiVar7 == (int *)*piVar8;

      ppiVar7 = ppiVar7 + 1;

      piVar8 = piVar8 + 1;

    } while (bVar9);

    if (bVar9) {

      BitStream_readBits(0x20,local_8);

      piVar3[0x54] = (int)local_8[0];

      BitStream_readBits(0x40,piVar3 + 0x50);

      BitStream_readBits(0x20,local_8);

      piVar3[0x52] = (int)local_8[0];

      if (local_8[0] < (int *)0x1b) {

        cVar2 = FUN_00424e50();

        if (cVar2 != '\0') {

          cVar2 = FUN_00424e50();

          if (cVar2 == '\0') {

            pvVar4 = operator_new(0x24);

            if (pvVar4 != (void *)0x0) {

              FUN_0042be80(in_EAX);

            }

            FUN_00430110();

            if (*(char *)(piVar3[0x55] + 0x20) == '\0') {

              return;

            }

            cVar2 = (**(code **)(*piVar3 + 0x1c))(piVar3[0x55],1);

            if (cVar2 == '\0') {

              return;

            }

          }

          else {

            pvVar4 = operator_new(0x2c);

            if (pvVar4 != (void *)0x0) {

              FUN_0042bf60(in_EAX);

            }

            FUN_00430110();

            iVar6 = piVar3[0x57];

            if (*(char *)(iVar6 + 0x24) == '\0') {

              return;

            }

            cVar2 = (**(code **)(*piVar3 + 0x18))(iVar6,1);

            if (cVar2 == '\0') {

              return;

            }

            piVar8 = *(int **)(piVar3[0x57] + 0x18);

            if (piVar8 != (int *)0x0) {

              piVar8[2] = piVar8[2] + 1;

            }

            local_8[0] = piVar8;

            FUN_004300e0();

            if (piVar8 != (int *)0x0) {

              piVar1 = piVar8 + 2;

              *piVar1 = *piVar1 + -1;

              if (*piVar1 == 0) {

                (**(code **)(*piVar8 + 8))();

              }

            }

          }

          if ((*(int *)(param_1 + 0x3c) == 0) ||

             (*(int *)(*(int *)(param_1 + 0x3c) + 0x10) != *(int *)(piVar3[0x55] + 0x10))) {

            pvVar4 = operator_new(0x24);

            if (pvVar4 != (void *)0x0) {

              FUN_0098ba20(*(uint32_t /* width from decompiler */ *)(piVar3[0x55] + 0x10));

            }

            FUN_00430110();

          }

          else {

            FUN_004300e0();

          }

          uVar5 = FUN_0098b790(piVar3[0x56],local_8);

          FUN_00426b40(uVar5);

          FUN_0040b290();

          FUN_00975f50((int)piVar3 + 0x166,0x10);

          *(uint8_t *)((int)piVar3 + 0x135) = 1;

        }

        if ((_DAT_00d21820 & 1) == 0) {

          _DAT_00d21820 = _DAT_00d21820 | 1;

          DAT_00d2181c = FUN_00783b60("LogNetInterface");

        }

        if (*(char *)(DAT_00d2181c + 4) != '\0') {

          DAT_00d179a0 = DAT_00d2181c;

          FUN_00783aa0("Received Challenge Response: %8x",piVar3[0x54]);

          DAT_00d179a0 = 0;

        }

        piVar3[0x68] = 0;

        piVar3[0x6e] = 3;

        piVar3[0x53] = 0;

        piVar3[0x69] = *(int *)(param_1 + 0x78);

        FUN_0042dbf0(param_1);

      }

    }

  }

  return;

}
