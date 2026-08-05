// =============================================================================
// CVOGGraphicsBase_InitializeGraphics
// -----------------------------------------------------------------------------
// Stable ID: aa_00586060
// Address:   0x00586060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for CVOGGraphicsBase_InitializeGraphics @ 0x00586060
// Stable ID: aa_00586060
// Embedded strings (evidence for future rename):
//   - "Loading %s"
//   - "CVOGGraphicsBase::InitializeGraphics"
//   - "RefractionSurface"
//   - "ReflectionSurface"
//   - "ad-decal"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~145 non-empty decompiler lines.
//  - Control keywords: if×20, return×5, do×1, while×1, goto×1.
//  - Notable callees: FUN_0040ac90×2, FUN_00581dd0×2, FUN_007a4480×2, FUN_00970140×2, CVOGGraphicsBase::InitializeGraphics, FUN_0040b140, FUN_00491e30, FUN_004eb1c0.
//  - Strings: "Loading %s"; "CVOGGraphicsBase::InitializeGraphics"; "RefractionSurface"; "ReflectionSurface".
//  - Return sites: 5.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CVOGGraphicsBase::InitializeGraphics"
 * Domain alias of FUN_00586060 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall CVOGGraphicsBase_InitializeGraphics(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *pvVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  char *unaff_EBX;

  undefined *unaff_EBP;

  void *unaff_ESI;

  uint8_t in_stack_00000014;

  uint32_t /* width from decompiler */ in_stack_00000024;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a552b;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  if (param_1[2] != 0) {

    ExceptionList = &pvStack_c;

    FUN_007a4480(0,

                 "CVOGGraphicsBase::InitializeGraphics() - attempting to load asset more than once <%s>.. releaseing and reinitting"

                 ,*(int *)(*(int *)(param_1[1] + 4) + 0xac + (int)param_1) + 0x188);

    (**(code **)(*param_1 + 4))();

  }

  iVar4 = *(int *)(*(int *)(param_1[1] + 4) + 0xac + (int)param_1);

  if (iVar4 != 0) {

    if (((iVar4 == -0x188) || (*(char *)(iVar4 + 0x188) == '\0')) ||

       (*(char *)(iVar4 + 0x188) == ' ')) {

      ExceptionList = pvStack_c;

      return 1;

    }

    if (*(char *)(*(int *)((int)param_1 + *(int *)(param_1[1] + 4) + 0xa8) + 0x7d) != '\0') {

LAB_0058612b:

      if (*(short *)(*(int *)(*(int *)(*(int *)(param_1[1] + 4) + 0xac + (int)param_1) + 0x3c) +

                    0x3f4) == 3) {

        uVar2 = FUN_00582090(param_2,&stack0x00000008,&stack0x00000014,in_stack_00000024);

        ExceptionList = pvStack_c;

        return uVar2;

      }

      (**(code **)(*param_1 + 0x18))(0);

      pvVar3 = operator_new(0x14c);

      puStack_8 = (uint8_t *)0x0;

      if (pvVar3 == (void *)0x0) {

        iVar4 = 0;

      }

      else {

        iVar4 = FUN_00764030();

      }

      param_1[2] = iVar4;

      puStack_8 = (uint8_t *)0xffffffff;

      FUN_004eb1c0(&stack0xffffffe4);

      if (unaff_EBP == (undefined *)0x0) {

        unaff_EBP = PTR_DAT_00afa2bc;

      }

      FUN_007a4480(0xffffffff,"Loading %s",unaff_EBP);

      FUN_0040b140("CVOGGraphicsBase::InitializeGraphics");

      puStack_8 = (uint8_t *)0x1;

      iVar5 = (**(code **)(*(int *)param_1[2] + 0x5c))(&stack0xffffffe4);

      iVar4 = *(int *)(param_1[1] + 4);

      if (*(float *)(iVar4 + 0xbc + (int)param_1) == g_flOne) {

        (**(code **)(*(int *)((int)param_1 + iVar4 + 4) + 0xb8))

                  (*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(iVar4 + 0xac + (int)param_1) + 0x3c) + 0x3ec));

      }

      pvStack_c = (void *)0xffffffff;

      FUN_0076cef0();

      if (iVar5 < 0) {

        if ((uint32_t /* width from decompiler */ *)param_1[2] != (uint32_t /* width from decompiler */ *)0x0) {

          (*(code *)**(uint32_t /* width from decompiler */ **)param_1[2])(1);

        }

        param_1[2] = 0;

        ExceptionList = pvVar3;

        return 0;

      }

      puVar6 = operator_new(0xc);

      *puVar6 = 0;

      puVar6[1] = 0;

      puVar6[2] = 0;

      *(uint8_t *)puVar6 = 1;

      puVar6[1] = *(int *)(param_1[1] + 4) + 4 + (int)param_1;

      *(uint32_t /* width from decompiler */ **)(param_1[2] + 0x78) = puVar6;

      (**(code **)(*(int *)param_1[2] + 0x18))(&stack0x00000000);

      (**(code **)(*(int *)param_1[2] + 0x14))(&stack0x00000008);

      if (*(char *)(*(int *)(*(int *)(*(int *)(param_1[1] + 4) + 0xac + (int)param_1) + 0x3c) +

                   0x408) == '\x01') {

        FUN_00763370();

      }

      if (*(short *)(*(int *)(*(int *)(*(int *)(param_1[1] + 4) + 0xac + (int)param_1) + 0x3c) +

                    0x3f4) == 0xc) {

        iVar5 = 0;

        iVar4 = FUN_0040ac90();

        if (0 < iVar4) {

          do {

            uVar2 = FUN_00491e30(0);

            FUN_00970140("RefractionSurface",uVar2);

            uVar2 = FUN_005b3400();

            FUN_00970140("ReflectionSurface",uVar2);

            iVar5 = iVar5 + 1;

            iVar4 = FUN_0040ac90();

          } while (iVar5 < iVar4);

        }

      }

      if (unaff_EBX == (char *)0x0) {

        unaff_EBX = PTR_DAT_00afa2bc;

      }

      strstr(unaff_EBX,"ad-decal");

      iVar4 = *(int *)(*(int *)(param_1[1] + 4) + 0xa8 + (int)param_1);

      if ((iVar4 != 0) && (*(char *)(iVar4 + 0x7d) == '\0')) {

        cVar1 = FUN_00581dd0();

        if (cVar1 == '\0') {

          pvStack_c = (void *)((uint)pvStack_c & 0xffffff00);

        }

      }

      iVar5 = (**(code **)(*(int *)param_1[2] + 0x48))();

      iVar4 = *(int *)(param_1[1] + 4);

      if ((((_DAT_009d45d8 < *(float *)(iVar4 + 0xbc + (int)param_1) * *(float *)(iVar5 + 0xc)) ||

           (*(char *)(*(int *)(*(int *)((int)param_1 + iVar4 + 0xac) + 0x3c) + 0x408) == '\x03')) ||

          ((*(byte *)((int)param_1 + iVar4 + 0x182) & 4) != 0)) ||

         (0 < *(int *)((int)param_1 + iVar4 + 0x118))) {

        *(uint8_t *)((int)param_1 + 0xd) = 0;

      }

      else {

        *(uint8_t *)((int)param_1 + 0xd) = in_stack_00000014;

      }

      (**(code **)(*param_1 + 0x18))(pvStack_c);

      if ((*(byte *)(*(int *)(param_1[1] + 4) + 0x188 + (int)param_1) & 1) != 0) {

        FUN_00585e00(0);

      }

      FUN_00583f10(param_1[2],0,0,0xffffffff);

      (**(code **)(*(int *)(*(int *)(param_1[1] + 4) + 4 + (int)param_1) + 0x48))();

      ExceptionList = unaff_ESI;

      return 1;

    }

    iVar4 = *(int *)(iVar4 + 0x38);

    if (((iVar4 != 0x36) && (iVar4 != 0x38)) && ((iVar4 != 0x1e && (iVar4 != 0x3c)))) {

      cVar1 = FUN_00581dd0();

      if (cVar1 != '\0') goto LAB_0058612b;

    }

  }

  ExceptionList = pvStack_c;

  return 0;

}
