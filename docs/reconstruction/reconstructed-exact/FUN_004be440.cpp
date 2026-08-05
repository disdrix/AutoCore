// =============================================================================
// FUN_004be440
// -----------------------------------------------------------------------------
// Stable ID: aa_004be440
// Address:   0x004be440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004be440 @ 0x004be440
// Stable ID: aa_004be440
// Embedded strings (evidence for future rename):
//   - "MatDiffuse"
//   - "Translucent"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~139 non-empty decompiler lines.
//  - Control keywords: if×15, while×3, do×2, return×2, goto×1.
//  - Notable callees: FUN_0076c3c0×3, FUN_00404d70, FUN_0040d1a0, FUN_004be440, FUN_0074c9c0, FUN_007522a0, FUN_00764dc0, FUN_00765170.
//  - Strings: "MatDiffuse"; "Translucent".
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

uint32_t /* width from decompiler */ __thiscall FUN_004be440(int param_1,uint32_t /* width from decompiler */ param_2,int *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  void *pvVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  int *piVar8;

  int *piVar9;

  TypeDescriptor *pTVar10;

  TypeDescriptor *pTVar11;

  int iStack_2c;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  TFID_16 TStack_10;

  

  iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 0x14);

  if (((iVar2 != 0) && (*(int *)(*(int *)(param_1 + 0xc) + 0x18) - iVar2 >> 2 != 0)) &&

     (*(char *)(*(int *)(param_1 + 0x5d4) + 0x7d) == '\0')) {

    if (*(int *)(param_1 + 0x5b8) == 0) {

      (**(code **)(*(int *)(param_1 + 0x30) + 0x58))();

      iVar2 = (**(code **)(*(int *)(param_1 + 0x30) + 0x10))(3);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0xbc) = 0xffffffff;

      *(int *)(iVar2 + 0xb4) = *(int *)(iVar2 + 0xb4) + 1;

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0x90) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x598);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0x94) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x59c);

      *(uint32_t /* width from decompiler */ *)(iVar2 + 0x98) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x5a0);

    }

    iVar2 = *(int *)(param_1 + 0xc);

    if (*(int *)(iVar2 + 0x14) == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(iVar2 + 0x18) - *(int *)(iVar2 + 0x14) >> 2;

    }

    if (*(int *)(param_1 + 0x5b8) < iVar3) {

      piVar9 = *(int **)(iVar2 + 0x14);

      iStack_2c = 0;

      if (piVar9 != *(int **)(iVar2 + 0x18)) {

        do {

          puVar1 = (uint32_t /* width from decompiler */ *)*piVar9;

          if (iStack_2c < *(int *)(param_1 + 0x5b8)) {

            iStack_2c = iStack_2c + 1;

          }

          else {

            iVar2 = FUN_00404d70(*puVar1);

            if (iVar2 != 0) {

              TStack_10.dwCoidLo = *(uint *)(iVar2 + 0x100);

              TStack_10.dwCoidHi = *(uint *)(iVar2 + 0x104);

              uVar7 = 0;

              TStack_10._8_4_ = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x108);

              TStack_10._12_4_ = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x10c);

              pTVar11 = &CVOGGraphicsBase::RTTI_Type_Descriptor;

              pTVar10 = &CVOGClonedObjectBase::RTTI_Type_Descriptor;

              uVar6 = 0;

              pvVar4 = Object_ResolveFromTFID(&TStack_10);

              iVar2 = __RTDynamicCast(pvVar4,uVar6,pTVar10,pTVar11,uVar7);

              if ((iVar2 != 0) && (*(int *)(iVar2 + 8) != 0)) {

                piVar8 = *(int **)puVar1[2];

                iVar3 = 0;

                if (piVar8 != (int *)puVar1[2]) {

                  do {

                    if (iVar3 < *(int *)(param_1 + 0x5bc)) {

                      iVar3 = iVar3 + 1;

                    }

                    else {

                      iVar3 = piVar8[2];

                      iVar5 = (**(code **)(**(int **)(iVar2 + 8) + 0x10))(3);

                      *(uint32_t /* width from decompiler */ *)(iVar5 + 0xbc) = 0xffffffff;

                      *(int *)(iVar5 + 0xb4) = *(int *)(iVar5 + 0xb4) + 1;

                      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x90) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x90);

                      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x94) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x94);

                      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x98) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x98);

                      uVar6 = 3;

                      (**(code **)(**(int **)(iVar2 + 8) + 0x10))(3,piVar8[2] + 0x80);

                      FUN_0040d1a0(uVar6);

                      (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0xb8))

                                (*(uint32_t /* width from decompiler */ *)(piVar8[2] + 0x9c));

                      FUN_00765170(*(uint32_t /* width from decompiler */ *)(iVar2 + 8),0);

                      *(int *)(param_1 + 0x5bc) = *(int *)(param_1 + 0x5bc) + 1;

                      iVar3 = *(int *)(param_1 + 0x5bc);

                      iVar5 = FUN_0076c3c0();

                      if (*param_3 <= iVar5) goto LAB_004be6a3;

                    }

                    piVar8 = (int *)*piVar8;

                  } while (piVar8 != (int *)puVar1[2]);

                }

                *(int *)(param_1 + 0x5b8) = *(int *)(param_1 + 0x5b8) + 1;

                iStack_2c = *(int *)(param_1 + 0x5b8);

                *(uint32_t /* width from decompiler */ *)(param_1 + 0x5bc) = 0;

                iVar2 = FUN_0076c3c0();

                if (*param_3 <= iVar2) break;

              }

            }

          }

          piVar9 = piVar9 + 1;

        } while (piVar9 != *(int **)(*(int *)(param_1 + 0xc) + 0x18));

      }

    }

LAB_004be6a3:

    iVar2 = FUN_0076c3c0();

    if (*param_3 <= iVar2) {

      return 1;

    }

    piVar9 = (int *)(param_1 + 0x30);

    FUN_00764dc0(0);

    (**(code **)(*piVar9 + 0x50))();

    uVar6 = (**(code **)(*piVar9 + 0xc))();

    uVar7 = (**(code **)(*piVar9 + 0x48))(uVar6);

    FUN_0074c9c0(&DAT_00d1eb60,uVar7,uVar6);

    fStack_20 = g_flOne;

    fStack_1c = g_flOne;

    fStack_18 = g_flOne;

    uStack_14 = 0;

    iVar2 = 0;

    while( true ) {

      if (*(int *)(param_1 + 0xf0) == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2;

      }

      if (iVar3 <= iVar2) break;

      FUN_0096fdf0();

      FUN_009700f0("MatDiffuse",&fStack_20);

      FUN_007522a0("Translucent");

      iVar2 = iVar2 + 1;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5cc) = uStack_14;

    *(uint8_t *)(param_1 + 0x5c5) = 1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5b8) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5bc) = 0;

  }

  *(uint8_t *)(param_1 + 0x572) = 0;

  return 0;

}
