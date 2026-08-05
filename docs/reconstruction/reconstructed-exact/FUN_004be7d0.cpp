// =============================================================================
// FUN_004be7d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004be7d0
// Address:   0x004be7d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004be7d0 @ 0x004be7d0
// Stable ID: aa_004be7d0
// Embedded strings (evidence for future rename):
//   - "MatDiffuse"
//   - "Translucent"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~135 non-empty decompiler lines.
//  - Control keywords: if×13, while×6, do×5, return×3, goto×2.
//  - Notable callees: FUN_00416160, FUN_00497f40, FUN_004be7d0, FUN_0074c9c0, FUN_007522a0, FUN_00764dc0, FUN_00765170, FUN_0096fdf0.
//  - Strings: "MatDiffuse"; "Translucent".
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

uint __fastcall FUN_004be7d0(int param_1)



{

  int iVar1;

  int iVar2;

  uint *puVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ in_EAX;

  uint3 uVar8;

  int iVar5;

  int iVar6;

  void *pvVar7;

  int *piVar9;

  uint *puVar10;

  uint32_t /* width from decompiler */ uVar11;

  TypeDescriptor *pTVar12;

  TypeDescriptor *pTVar13;

  uint32_t /* width from decompiler */ uVar14;

  int local_38;

  uint local_34;

  int local_2c;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  TFID_16 local_10;

  

  pcVar4 = DAT_00b035cc;

  uVar8 = (uint3)((uint)in_EAX >> 8);

  if ((*DAT_00b035cc != '\0') || (DAT_00b035c8 != '\0')) {

    *(uint8_t *)(param_1 + 0x573) = 0;

    return (uint)uVar8 << 8;

  }

  iVar1 = (int)ROUND(DAT_00aefa50 * DAT_00a14000);

  local_34 = 0;

  if (iVar1 < 1) {

    *(uint8_t *)(param_1 + 0x573) = 0;

    return (uint)uVar8 << 8;

  }

  do {

    iVar2 = *(int *)(param_1 + 0x5a8);

    local_38 = 0;

    do {

      iVar5 = FUN_00497f40(iVar2 * iVar1 + local_34,*(int *)(param_1 + 0x5ac) * iVar1 + local_38);

      if ((0 < iVar5) && (local_2c = 0, 0 < *(int *)(pcVar4 + 0x10))) {

        piVar9 = (int *)(pcVar4 + 0x14);

        do {

          iVar5 = 0;

          puVar3 = (uint *)*piVar9;

          if (puVar3[4] != 0) {

            iVar6 = *(int *)(*(int *)(*(int *)(*(int *)(DAT_00b041fc + 0xf10) + 0x10) +

                                     (*(uint *)(*(int *)(DAT_00b041fc + 0xf10) + 8) & *puVar3) * 4)

                            + 4);

            if (iVar6 == 0) {

LAB_004be8c4:

              iVar6 = 0;

            }

            else {

              do {

                if (*puVar3 == *(uint *)(iVar6 + 0x10)) {

                  if (iVar6 == 0) goto LAB_004be8c4;

                  iVar6 = *(int *)(iVar6 + 8);

                  goto LAB_004be8cb;

                }

                iVar6 = *(int *)(iVar6 + 0xc);

              } while (iVar6 != 0);

              iVar6 = 0;

            }

LAB_004be8cb:

            if (iVar6 != 0) {

              local_10.dwCoidLo = *(uint *)(iVar6 + 0x100);

              local_10.dwCoidHi = *(uint *)(iVar6 + 0x104);

              uVar14 = 0;

              local_10._8_4_ = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x108);

              local_10._12_4_ = *(uint32_t /* width from decompiler */ *)(iVar6 + 0x10c);

              pTVar13 = &CVOGGraphicsBase::RTTI_Type_Descriptor;

              pTVar12 = &CVOGClonedObjectBase::RTTI_Type_Descriptor;

              uVar11 = 0;

              pvVar7 = Object_ResolveFromTFID(&local_10);

              iVar6 = __RTDynamicCast(pvVar7,uVar11,pTVar12,pTVar13,uVar14);

              if (((iVar6 != 0) && (*(int *)(iVar6 + 8) != 0)) && (0 < (int)puVar3[4])) {

                puVar10 = puVar3 + 8;

                do {

                  uVar11 = 3;

                  (**(code **)(**(int **)(iVar6 + 8) + 0x10))(3,puVar10 + 4);

                  FUN_00416160(uVar11);

                  (**(code **)(*(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6) + 0xb8))

                            (*puVar10);

                  FUN_00765170(*(uint32_t /* width from decompiler */ *)(iVar6 + 8),0);

                  iVar5 = iVar5 + 1;

                  puVar10 = puVar10 + 0x34;

                } while (iVar5 < (int)puVar3[4]);

              }

            }

            puVar3[4] = 0;

          }

          local_2c = local_2c + 1;

          piVar9 = piVar9 + 1;

        } while (local_2c < *(int *)(pcVar4 + 0x10));

      }

      piVar9 = (int *)(param_1 + 0x17c);

      FUN_00764dc0(0);

      (**(code **)(*piVar9 + 0x50))();

      uVar11 = (**(code **)(*piVar9 + 0xc))();

      uVar14 = (**(code **)(*piVar9 + 0x48))(uVar11);

      FUN_0074c9c0(&DAT_00d1eb60,uVar14,uVar11);

      if (DAT_00b03e64 == '\0') {

        fStack_20 = g_flOne;

        fStack_1c = g_flOne;

        fStack_18 = g_flOne;

        uStack_14 = 0;

        iVar5 = 0;

        while( true ) {

          if (*(int *)(param_1 + 0x23c) == 0) {

            iVar6 = 0;

          }

          else {

            iVar6 = *(int *)(param_1 + 0x240) - *(int *)(param_1 + 0x23c) >> 2;

          }

          if (iVar6 <= iVar5) break;

          FUN_0096fdf0();

          FUN_009700f0("MatDiffuse",&fStack_20);

          FUN_007522a0("Translucent");

          iVar5 = iVar5 + 1;

        }

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x5cc) = uStack_14;

        *(uint8_t *)(param_1 + 0x5c5) = 1;

      }

      local_38 = local_38 + 1;

    } while (local_38 < iVar1);

    local_34 = local_34 + 1;

    if (iVar1 <= (int)local_34) {

      *(uint8_t *)(param_1 + 0x573) = 0;

      return local_34 & 0xffffff00;

    }

  } while( true );

}
