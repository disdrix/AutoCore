// =============================================================================
// Named_nfx_00542e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00542e20
// Address:   0x00542e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_nfx_00542e20 @ 0x00542e20
// Stable ID: aa_00542e20
// Embedded strings (evidence for future rename):
//   - "_nfx.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~104 non-empty decompiler lines.
//  - Control keywords: if×17, goto×4, while×3, return×3, do×2.
//  - Notable callees: Object_ResolveFromTFID×2, FUN_0043d650, FUN_004a04f0, FUN_004a16d0, FUN_004a6390, FUN_004ed310, Named_nfx_00542e20, FUN_00545500.
//  - Strings: "_nfx.xml".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "_nfx.xml"
 * Domain alias of FUN_00542e20 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_nfx_00542e20(int param_1)



{

  int iVar1;

  char cVar2;

  uint uVar3;

  char *pcVar4;

  int *piVar5;

  void *pvVar6;

  int iVar7;

  char local_104 [260];

  

  if (*(int *)(param_1 + 0xf2c) != 0) {

    while( true ) {

      iVar1 = **(int **)(param_1 + 0xf28);

      cVar2 = FUN_004ed310(iVar1 + 0x44,(uint8_t *)(iVar1 + 0x40),(uint32_t /* width from decompiler */ *)(iVar1 + 0x3c));

      if (cVar2 == '\0') break;

      iVar7 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xf0c) + 0x10) +

                               (*(uint *)(*(int *)(param_1 + 0xf0c) + 8) & *(uint *)(iVar1 + 0x2c))

                               * 4) + 4);

      if (iVar7 == 0) {

LAB_00542ea4:

        iVar7 = 0;

      }

      else {

        do {

          if (*(uint *)(iVar1 + 0x2c) == *(uint *)(iVar7 + 0x10)) {

            if (iVar7 == 0) goto LAB_00542ea4;

            iVar7 = *(int *)(iVar7 + 8);

            goto LAB_00542eab;

          }

          iVar7 = *(int *)(iVar7 + 0xc);

        } while (iVar7 != 0);

        iVar7 = 0;

      }

LAB_00542eab:

      if (iVar7 == 0) {

LAB_00542f7b:

        piVar5 = (int *)**(int **)(param_1 + 0xf28);

        if (piVar5 != *(int **)(param_1 + 0xf28)) {

          *(int *)piVar5[1] = *piVar5;

          *(int *)(*piVar5 + 4) = piVar5[1];

LAB_00542ffc:

          FUN_00545500();

                    /* WARNING: Subroutine does not return */

          operator_delete(piVar5);

        }

      }

      else if (*(char *)(iVar1 + 0x58) == '\0') {

        iVar7 = FUN_004a16d0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x28),1,0xffffffff);

        if (iVar7 == 0) goto LAB_00542f7b;

        piVar5 = Object_ResolveFromTFID((TFID_16 *)(iVar1 + 0x18));

        pvVar6 = Object_ResolveFromTFID((TFID_16 *)(iVar1 + 8));

        if (piVar5 != (int *)0x0) {

          (**(code **)(*piVar5 + 0x238))

                    (*(uint32_t /* width from decompiler */ *)(iVar1 + 0x28),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x2c),

                     *(uint32_t /* width from decompiler */ *)(iVar1 + 0x30),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x34),pvVar6,

                     *(uint32_t /* width from decompiler */ *)(iVar1 + 0x38),1,iVar7);

        }

        piVar5 = (int *)**(int **)(param_1 + 0xf28);

        if (piVar5 != *(int **)(param_1 + 0xf28)) {

          *(int *)piVar5[1] = *piVar5;

          *(int *)(*piVar5 + 4) = piVar5[1];

          goto LAB_00542ffc;

        }

      }

      else {

        if ((*(char *)(iVar7 + 10) == '\0') && (*(int *)(iVar1 + 0x54) != 0)) {

          uVar3 = *(uint *)(iVar1 + 0x50) >> 2;

          iVar7 = uVar3 * -4;

          if (*(uint *)(iVar1 + 0x4c) <= uVar3) {

            uVar3 = uVar3 - *(uint *)(iVar1 + 0x4c);

          }

          pcVar4 = *(char **)(*(int *)(*(int *)(iVar1 + 0x48) + uVar3 * 4) +

                             (*(uint *)(iVar1 + 0x50) + iVar7) * 4);

          if (pcVar4 == (char *)0x0) {

            pcVar4 = PTR_DAT_00afa2bc;

          }

          iVar7 = -(int)pcVar4;

          do {

            cVar2 = *pcVar4;

            pcVar4[(int)(local_104 + iVar7)] = cVar2;

            pcVar4 = pcVar4 + 1;

          } while (cVar2 != '\0');

          pcVar4 = strstr(local_104,"_nfx.xml");

          if (pcVar4 != (char *)0x0) {

            *pcVar4 = '\0';

            FUN_004a6390(local_104);

          }

        }

        *(uint8_t *)(iVar1 + 0x58) = 0;

        FUN_0043d650(0);

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x3c) = 0;

        *(uint8_t *)(iVar1 + 0x40) = 0;

        FUN_004a04f0(iVar1 + 0x44,1,1,1);

      }

      if (*(int *)(param_1 + 0xf2c) == 0) {

        return;

      }

    }

    if (*(char *)(iVar1 + 0x40) == '\0') {

      FUN_00971820(iVar1 + 0x44);

    }

  }

  return;

}
