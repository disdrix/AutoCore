// =============================================================================
// LCD_CLCDManager_Initialize_00806de0
// -----------------------------------------------------------------------------
// Stable ID: aa_00806de0
// Address:   0x00806de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for LCD_CLCDManager_Initialize_00806de0 @ 0x00806de0
// Stable ID: aa_00806de0
// Embedded strings (evidence for future rename):
//   - "CLCDManager::Initialize(): failed to initialize graphics component.\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~166 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, if×2, return×2, switch×1, goto×1.
//  - Notable callees: FUN_00418700×6, FUN_00418790×6, LoadImageA×2, CLCDManager::Initialize, FUN_007a4480, FUN_00805900, LCD_CLCDManager_Initialize_00806de0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "CLCDManager::Initialize(): failed to initialize graphics component.
"
 * Domain alias of FUN_00806de0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __fastcall LCD_CLCDManager_Initialize_00806de0(int *param_1)



{

  int **ppiVar1;

  int **ppiVar2;

  int iVar3;

  HANDLE pvVar4;

  int *piVar5;

  int *piVar6;

  int *piVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  int iVar10;

  int *piStack_34;

  int *piStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  int iStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  int **ppiStack_20;

  int **local_c;

  int *apiStack_8 [2];

  

  local_c = (int **)0x0;

  piVar6 = param_1 + 0x1c;

  do {

    ppiStack_20 = (int **)0x806dfe;

    (**(code **)(*piVar6 + 4))();

    ppiStack_20 = local_c;

    uStack_24 = 0;

    iStack_28 = 0x806e0c;

    (**(code **)(*piVar6 + 0xc))();

    iStack_28 = 0x1e;

    uStack_2c = 0xa0;

    piStack_30 = (int *)0x806e1a;

    (**(code **)(*piVar6 + 0x18))();

    piStack_30 = (int *)0x1;

    piStack_34 = (int *)0x806e26;

    (**(code **)(*piVar6 + 0xa4))();

    piStack_34 = (int *)0x1;

    (**(code **)(*piVar6 + 0x88))();

    (**(code **)(*piVar6 + 0x2c))(0);

    iVar10 = param_1[0xe];

    uStack_24 = *(uint32_t /* width from decompiler */ *)(iVar10 + 4);

    ppiStack_20 = apiStack_8;

    uStack_2c = 0x806e51;

    iStack_28 = iVar10;

    apiStack_8[0] = piVar6;

    apiStack_8[0] = (int *)FUN_00418700();

    ppiStack_20 = (int **)0x806e61;

    FUN_00418790();

    *(int **)(iVar10 + 4) = apiStack_8[0];

    *(int **)apiStack_8[0][1] = apiStack_8[0];

    local_c = local_c + 5;

    piVar6 = piVar6 + 0x5c;

  } while ((int)local_c < 0x50);

  ppiVar1 = (int **)(param_1 + 0x1d8);

  ppiStack_20 = (int **)0x806e98;

  (**(code **)(param_1[0x1d8] + 4))();

  ppiStack_20 = (int **)0x0;

  uStack_24 = 0x806ea1;

  (*(code *)(*ppiVar1)[0xb])();

  uStack_24 = 0xf;

  iStack_28 = 0xa0;

  uStack_2c = 0x806eaf;

  (*(code *)(*ppiVar1)[6])();

  ppiVar2 = (int **)(param_1 + 0x23e);

  uStack_2c = 0x806ec0;

  (**(code **)(param_1[0x23e] + 4))();

  uStack_2c = 0;

  piStack_30 = (int *)0x806eca;

  (*(code *)(*ppiVar2)[0xb])();

  piStack_30 = (int *)0xf;

  piStack_34 = (int *)0xa0;

  (*(code *)(*ppiVar2)[6])();

  iVar10 = param_1[0xe];

  ppiStack_20 = ppiVar1;

  ppiStack_20 = (int **)FUN_00418700(iVar10,*(uint32_t /* width from decompiler */ *)(iVar10 + 4),&ppiStack_20);

  FUN_00418790();

  *(int ***)(iVar10 + 4) = ppiStack_20;

  *ppiStack_20[1] = (int)ppiStack_20;

  iVar10 = param_1[0xe];

  ppiStack_20 = ppiVar2;

  iVar3 = FUN_00418700(iVar10,*(uint32_t /* width from decompiler */ *)(iVar10 + 4),&ppiStack_20);

  FUN_00418790();

  *(int *)(iVar10 + 4) = iVar3;

  **(int **)(iVar3 + 4) = iVar3;

  piVar6 = param_1 + 0x18c;

  (**(code **)(param_1[0x18c] + 4))();

  (**(code **)(*piVar6 + 0xc))(0,5);

  (**(code **)(*piVar6 + 0x18))(0x20,0x20);

  uVar9 = 0;

  (**(code **)(*piVar6 + 0x2c))(0);

  pvVar4 = LoadImageA(DAT_00d1d9c0,(LPCSTR)0x65,1,0x20,0x20,1);

  param_1[0x199] = (int)pvVar4;

  param_1[0x19a] = 0x20;

  param_1[0x19b] = 0x20;

  iVar10 = 0;

  do {

    piStack_34 = param_1 + iVar10 * 0xf;

    piVar7 = piStack_34 + 0x19c;

    (**(code **)(piStack_34[0x19c] + 4))();

    (**(code **)(*piVar7 + 0x18))(8,2);

    (**(code **)(*piVar7 + 0x2c))(0);

    pvVar4 = LoadImageA(DAT_00d1d9c0,(LPCSTR)0x69,0,0x10,0x10,1);

    piStack_34[0x1a9] = (int)pvVar4;

    switch(iVar10) {

    case 0:

      (**(code **)(param_1[0x19c] + 0xc))(10,0x28);

      break;

    case 1:

      piVar5 = param_1 + 0x1ab;

      uVar8 = 0x32;

      goto LAB_0080703e;

    case 2:

      (**(code **)(param_1[0x1ba] + 0xc))(0x6e,0x28);

      break;

    case 3:

      piVar5 = param_1 + 0x1c9;

      uVar8 = 0x96;

LAB_0080703e:

      (**(code **)(*piVar5 + 0xc))(uVar8,0x28);

    }

    iVar3 = param_1[0xe];

    piStack_34 = piVar7;

    piStack_34 = (int *)FUN_00418700(iVar3,*(uint32_t /* width from decompiler */ *)(iVar3 + 4),&piStack_34);

    FUN_00418790();

    *(int **)(iVar3 + 4) = piStack_34;

    *(int **)piStack_34[1] = piStack_34;

    iVar10 = iVar10 + 1;

    if (3 < iVar10) {

      iVar10 = 0;

      piVar7 = param_1 + 0x2d9;

      do {

        (**(code **)(*piVar7 + 4))();

        (**(code **)(*piVar7 + 0x80))(0);

        (**(code **)(*piVar7 + 0x18))(0x32,5);

        (**(code **)(*piVar7 + 0x2c))(0);

        (**(code **)(*piVar7 + 0xc))(0,uVar9);

        piStack_30 = (int *)param_1[0xe];

        piStack_34 = piVar7;

        piStack_34 = (int *)FUN_00418700(piStack_30,piStack_30[1],&piStack_34);

        FUN_00418790();

        piStack_30[1] = (int)piStack_34;

        *(int **)piStack_34[1] = piStack_34;

        iVar10 = iVar10 + 8;

        piVar7 = piVar7 + 0x13;

      } while (iVar10 < 0x18);

      iVar10 = param_1[0xe];

      piStack_30 = piVar6;

      iVar3 = FUN_00418700(iVar10,*(uint32_t /* width from decompiler */ *)(iVar10 + 4),&piStack_30);

      FUN_00418790();

      *(int *)(iVar10 + 4) = iVar3;

      **(int **)(iVar3 + 4) = iVar3;

      (**(code **)(*param_1 + 0xc))(0,0);

      (**(code **)(*param_1 + 0x18))(0xa0,0x2b);

      (**(code **)(*param_1 + 0x28))();

      (**(code **)(*param_1 + 0x24))();

      iVar10 = FUN_00805900();

      if (-1 < iVar10) {

        return 0;

      }

      FUN_007a4480(0xffffffff,&DAT_00a2c2a4,

                   "CLCDManager::Initialize(): failed to initialize graphics component.\n");

      (**(code **)(*param_1 + 8))();

      return iVar10;

    }

  } while( true );

}
