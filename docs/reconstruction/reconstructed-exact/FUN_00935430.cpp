// =============================================================================
// FUN_00935430
// -----------------------------------------------------------------------------
// Stable ID: aa_00935430
// Address:   0x00935430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00935430 @ 0x00935430
// Stable ID: aa_00935430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~259 non-empty decompiler lines.
//  - Control keywords: if×45, while×5, do×4, for×1, return×1.
//  - Notable callees: FUN_00401540, FUN_00756be0, FUN_007aac90, FUN_007fb990, FUN_007fca10, FUN_007fe2c0, FUN_00890660, FUN_009103d0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00935430(void)



{

  int *piVar1;

  int *piVar2;

  char cVar3;

  int in_EAX;

  int *piVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  float fVar7;

  int local_4;

  

  piVar4 = (int *)(in_EAX + 0x1030);

  local_4 = 0x3a;

  do {

    if (((int *)*piVar4 != (int *)0x0) &&

       (cVar3 = (**(code **)(*(int *)*piVar4 + 0x3d8))(), cVar3 != '\0')) {

      FUN_007fca10();

    }

    piVar4 = piVar4 + 1;

    local_4 = local_4 + -1;

  } while (local_4 != 0);

  FUN_009349b0();

  *(uint8_t *)(in_EAX + 0x30b6) = 1;

  *(uint8_t *)(in_EAX + 0x30b7) = 0;

  if (*(int **)(in_EAX + 0x30a0) != (int *)0x0) {

    (**(code **)(**(int **)(in_EAX + 0x30a0) + 4))(0);

    *(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x30a0) + 0x514) = 0;

    *(uint8_t *)(*(int *)(in_EAX + 0x30a0) + 0x4fc) = 0;

  }

  *(uint8_t *)(in_EAX + 0x30b4) = 1;

  *(uint8_t *)(in_EAX + 0x30b5) = 0;

  if (*(int **)(in_EAX + 0x309c) != (int *)0x0) {

    (**(code **)(**(int **)(in_EAX + 0x309c) + 4))(0);

  }

  *(uint8_t *)(in_EAX + 0x30bc) = 1;

  *(uint8_t *)(in_EAX + 0x30bd) = 0;

  if (*(int **)(in_EAX + 0x30ac) != (int *)0x0) {

    (**(code **)(**(int **)(in_EAX + 0x30ac) + 4))(0);

  }

  *(uint8_t *)(in_EAX + 0x30be) = 1;

  *(uint8_t *)(in_EAX + 0x30bf) = 0;

  if (*(int **)(in_EAX + 0x30b0) != (int *)0x0) {

    (**(code **)(**(int **)(in_EAX + 0x30b0) + 4))(0);

  }

  FUN_007fb990();

  iVar5 = 0;

  do {

    FUN_009103d0();

    iVar5 = iVar5 + 1;

  } while (iVar5 < 2);

  if (*(int *)(in_EAX + 0x10ec) != 0) {

    FUN_00890660(*(int *)(in_EAX + 0x10ec));

  }

  FUN_007fe2c0();

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x3084) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x3084))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x3084) = 0;

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x1150) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x1150))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1150) = 0;

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x1154) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x1154))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1154) = 0;

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x114c) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x114c))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x114c) = 0;

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x1158) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x1158))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1158) = 0;

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x1144) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x1144))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1144) = 0;

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x1148) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x1148))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1148) = 0;

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x115c) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x115c))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x115c) = 0;

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x1160) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x1160))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1160) = 0;

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x1164) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x1164))(1);

  }

  piVar4 = *(int **)(in_EAX + 0x3094);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1164) = 0;

  piVar2 = (int *)*piVar4;

  while (piVar2 != piVar4) {

    piVar4 = (int *)piVar2[6];

    (**(code **)(*piVar4 + 0x440))();

    (**(code **)*piVar4)(1);

    piVar4 = *(int **)(in_EAX + 0x3094);

  }

  FUN_00401540(*(uint32_t /* width from decompiler */ *)(*(int *)(in_EAX + 0x3094) + 4));

  *(int *)(*(int *)(in_EAX + 0x3094) + 4) = *(int *)(in_EAX + 0x3094);

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x3098) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(in_EAX + 0x3094) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x3094);

  *(int *)(*(int *)(in_EAX + 0x3094) + 8) = *(int *)(in_EAX + 0x3094);

  (**(code **)(**(int **)(in_EAX + 0x309c) + 0x440))();

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x309c) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x309c))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x309c) = 0;

  (**(code **)(**(int **)(in_EAX + 0x30a0) + 0x440))();

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x30a0) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x30a0))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x30a0) = 0;

  (**(code **)(**(int **)(in_EAX + 0x30a4) + 0x440))();

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x30a4) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x30a4))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x30a4) = 0;

  (**(code **)(**(int **)(in_EAX + 0x30a8) + 0x440))();

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x30a8) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x30a8))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x30a8) = 0;

  (**(code **)(**(int **)(in_EAX + 0x30ac) + 0x440))();

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x30ac) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x30ac))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x30ac) = 0;

  (**(code **)(**(int **)(in_EAX + 0x30b0) + 0x440))();

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x30b0) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x30b0))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x30b0) = 0;

  if (*(int **)(in_EAX + 0x1120) != (int *)0x0) {

    (**(code **)(**(int **)(in_EAX + 0x1120) + 0x440))();

  }

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x1120) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x1120))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1120) = 0;

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x1138) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x1138))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1138) = 0;

  (**(code **)(**(int **)(in_EAX + 0x1118) + 0x440))();

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x1118) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x1118))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1118) = 0;

  if (*(int **)(in_EAX + 0x111c) != (int *)0x0) {

    (**(code **)(**(int **)(in_EAX + 0x111c) + 0x440))();

  }

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x111c) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x111c))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x111c) = 0;

  (**(code **)(**(int **)(in_EAX + 0x1124) + 0x440))();

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x1124) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x1124))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1124) = 0;

  (**(code **)(**(int **)(in_EAX + 0x1128) + 0x440))();

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x1128) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x1128))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1128) = 0;

  (**(code **)(**(int **)(in_EAX + 0x112c) + 0x440))();

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x112c) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x112c))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x112c) = 0;

  (**(code **)(**(int **)(in_EAX + 0x1130) + 0x440))();

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x1130) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x1130))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1130) = 0;

  (**(code **)(**(int **)(in_EAX + 0x1134) + 0x440))();

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x1134) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x1134))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1134) = 0;

  (**(code **)(**(int **)(in_EAX + 0x113c) + 0x440))();

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x113c) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x113c))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x113c) = 0;

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x1140) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x1140))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1140) = 0;

  puVar6 = (uint32_t /* width from decompiler */ *)(in_EAX + 0x22);

  for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {

    *puVar6 = 0;

    puVar6 = puVar6 + 1;

  }

  *(uint16_t *)puVar6 = 0;

  piVar4 = (int *)(in_EAX + 0x1030);

  iVar5 = 0x3a;

  do {

    if ((int *)*piVar4 != (int *)0x0) {

      (**(code **)(*(int *)*piVar4 + 0x440))();

      if ((uint32_t /* width from decompiler */ *)*piVar4 != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)*piVar4)(1);

      }

    }

    *piVar4 = 0;

    piVar4 = piVar4 + 1;

    iVar5 = iVar5 + -1;

  } while (iVar5 != 0);

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x9b8) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x9b8))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x9b8) = 0;

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0xf38) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0xf38))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xf38) = 0;

  if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0xf3c) != (uint32_t /* width from decompiler */ *)0x0) {

    (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0xf3c))(1);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xf3c) = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xf40) = 0;

  if (*(int *)(in_EAX + 0x1168) != 0) {

    FUN_00756be0(*(int *)(in_EAX + 0x1168));

    if (*(uint32_t /* width from decompiler */ **)(in_EAX + 0x1168) != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)**(uint32_t /* width from decompiler */ **)(in_EAX + 0x1168))(1);

    }

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x1168) = 0;

  }

  piVar4 = &DAT_00d1e7e0;

  do {

    piVar2 = (int *)*piVar4;

    if (piVar2 != (int *)0x0) {

      piVar1 = piVar2 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar2 + 8))();

      }

      *piVar4 = 0;

    }

    piVar4 = piVar4 + 1;

  } while ((int)piVar4 < 0xd1e818);

  DAT_00d17944 = 0;

  fVar7 = SQRT(_DAT_00afdb80 * _DAT_00afdb80 +

               _DAT_00afdb84 * _DAT_00afdb84 + _DAT_00afdb88 * _DAT_00afdb88);

  if ((_DAT_00a240ec <= fVar7) || (fVar7 <= DAT_00aaa640)) {

    fVar7 = g_flOne / fVar7;

    _DAT_00afdb80 = fVar7 * _DAT_00afdb80;

    _DAT_00afdb84 = fVar7 * _DAT_00afdb84;

    _DAT_00afdb88 = fVar7 * _DAT_00afdb88;

  }

  FUN_007aac90();

  return;

}
