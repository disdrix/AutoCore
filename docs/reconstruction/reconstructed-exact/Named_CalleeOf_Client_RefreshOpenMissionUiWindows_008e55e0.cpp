// =============================================================================
// Named_CalleeOf_Client_RefreshOpenMissionUiWindows_008e55e0
// -----------------------------------------------------------------------------
// Stable ID: aa_008e55e0
// Callee of Client_RefreshOpenMissionUiWindows
// Address:   0x008e55e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RefreshOpenMissionUiWindows: mission/objective helper. Evidence string: "You must select an item to craft!". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "You must select an item to craft!"
//   - "You need a broken item to craft!"
//   - "You don\'t have the right components!"
//   - "To craft this from Memory costs"
//   - "Chance of Success"
//   - "\n%s: %i%%"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~133 non-empty decompiler lines.
//  - Control keywords: if×13, for×1, do×1, while×1, return×1.
//  - Notable callees: sprintf×5, FUN_007a69d0×3, FUN_007a6de0×3, FUN_0040f4e0, FUN_005142a0, FUN_005202d0, FUN_00520340, FUN_0052d450.
//  - Strings: "You must select an item to craft!"; "You need a broken item to craft!"; "You don\'t have the right components!"; "To craft this from Memory costs".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_RefreshOpenMissionUiWindows
 * Xref/callee-driven rename (parent seed scan)
 *
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



void Named_CalleeOf_Client_RefreshOpenMissionUiWindows_008e55e0(void)



{

  char cVar1;

  int in_EAX;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  double dVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ uVar6;

  char cStack_21a;

  char cStack_219;

  uint8_t uStack_218;

  uint8_t uStack_217;

  char local_216;

  char local_215;

  float local_214 [2];

  uint local_20c;

  uint16_t local_208;

  uint32_t /* width from decompiler */ local_206 [128];

  

  if (DAT_00d1b6d8 != 0) {

    local_208 = 0;

    puVar3 = local_206;

    for (iVar2 = 0x7f; iVar2 != 0; iVar2 = iVar2 + -1) {

      *puVar3 = 0;

      puVar3 = puVar3 + 1;

    }

    local_215 = '\0';

    *(uint16_t *)puVar3 = 0;

    *(uint8_t *)(in_EAX + 0x7d8) = 1;

    FUN_008e54a0();

    iVar2 = 0;

    do {

      iVar2 = iVar2 + 1;

      FUN_00520340(iVar2);

    } while (iVar2 < 5);

    if ((*(int *)(in_EAX + 0x7cc) != 0) &&

       (cVar1 = FUN_0052eb90(*(int *)(in_EAX + 0x7cc)), cVar1 != '\0')) {

      local_215 = '\x01';

    }

    iVar2 = *(int *)(in_EAX + 0x7cc);

    local_216 = '\x01';

    if ((iVar2 != 0) &&

       (cVar1 = FUN_005202d0(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x160),*(uint32_t /* width from decompiler */ *)(iVar2 + 0x164)),

       cVar1 != '\0')) {

      local_214[0] = (float)FUN_005142a0();

      dVar4 = ceil((double)((float)(int)local_214[0] * DAT_00aaa680));

      local_214[0] = (float)dVar4;

      local_20c = (uint)ROUND(local_214[0]);

      iVar2 = (*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

              (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) < *(uint *)(DAT_00d1b6d8 + 0x728));

      if ((iVar2 <= (int)local_20c >> 0x1f) &&

         ((iVar2 < (int)local_20c >> 0x1f ||

          (*(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728) < local_20c)))) {

        local_216 = '\0';

      }

    }

    local_214[1] = 0.0;

    cVar1 = FUN_0052d450(*(uint32_t /* width from decompiler */ *)(in_EAX + 0x7cc),local_214 + 1);

    if ((((cVar1 == '\0') || (local_215 == '\0')) || (*(char *)(in_EAX + 0x7d8) == '\0')) ||

       (local_216 == '\0')) {

      cVar1 = (**(code **)(**(int **)(in_EAX + 0x748) + 0xd8))();

      if (cVar1 != '\0') {

        (**(code **)(**(int **)(in_EAX + 0x748) + 0xd4))(0);

        (**(code **)(**(int **)(in_EAX + 0x748) + 0x34c))();

      }

      (**(code **)(**(int **)(in_EAX + 0x528) + 0x268))();

      if (*(int *)(in_EAX + 0x7cc) == 0) {

        if ((*(int **)(in_EAX + 0x754) == (int *)0x0) ||

           (iVar2 = (**(code **)(**(int **)(in_EAX + 0x754) + 0x490))(), 0 < iVar2)) {

          sprintf((char *)&local_20c,"You must select an item to craft!",0);

        }

        else {

          sprintf((char *)&local_20c,"You need a broken item to craft!",0);

        }

      }

      else if (local_214[0] == 5.60519e-45) {

        FUN_008e3820();

      }

      else if (local_214[0] == 2.8026e-45) {

        sprintf((char *)&local_20c,"You don\'t have the right components!",0);

      }

      else if (cStack_21a == '\0') {

        uVar6 = 0xffffffff;

        local_20c = local_20c & 0xffffff00;

        iVar2 = **(int **)(in_EAX + 0x528);

        pcVar5 = "To craft this from Memory costs";

        FUN_007a69d0("To craft this from Memory costs",0xffffffff);

        uVar6 = FUN_007a6de0(pcVar5,uVar6);

        (**(code **)(iVar2 + 0x250))(uVar6);

        (**(code **)(**(int **)(in_EAX + 0x528) + 0x250))(&DAT_00a3ad3c);

        iVar2 = FUN_0040f4e0();

        FUN_00977a30(DAT_00d1ad30,iVar2,iVar2 >> 0x1f);

      }

      else if ((cStack_219 == '\0') || (local_214[0] == 7.00649e-45)) {

        FUN_008e3940();

      }

      else {

        uVar6 = 0xffffffff;

        pcVar5 = "Chance of Success";

        FUN_007a69d0("Chance of Success",0xffffffff,0);

        uVar6 = FUN_007a6de0(pcVar5,uVar6);

        sprintf((char *)&local_20c,"\n%s: %i%%",uVar6);

      }

      uStack_217 = 0;

      uStack_218 = 0;

    }

    else {

      (**(code **)(**(int **)(in_EAX + 0x748) + 0xd4))(1);

      (**(code **)(**(int **)(in_EAX + 0x528) + 0x268))();

      uVar6 = 0xffffffff;

      pcVar5 = "Chance of Success";

      FUN_007a69d0("Chance of Success",0xffffffff,(int)_DAT_00aaa708,

                   (int)((ulonglong)_DAT_00aaa708 >> 0x20));

      uVar6 = FUN_007a6de0(pcVar5,uVar6);

      sprintf((char *)&local_20c,"\n%s: %.1f%%",uVar6);

      uStack_217 = 0xff;

      uStack_218 = 0xff;

    }

    local_215 = 0xff;

    local_216 = 0xff;

    (**(code **)(**(int **)(in_EAX + 0x528) + 0x15c))(1,&uStack_218);

    FUN_008e41b0();

    (**(code **)(**(int **)(in_EAX + 0x748) + 0x34c))();

    if (local_214[0]._0_1_ != '\0') {

      (**(code **)(**(int **)(in_EAX + 0x528) + 0x1d8))(local_214,1,1);

    }

    (**(code **)(**(int **)(in_EAX + 0x528) + 0xcc))(1);

    (**(code **)(**(int **)(in_EAX + 0x528) + 0x34c))();

  }

  return;

}
