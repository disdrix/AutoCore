// =============================================================================
// FUN_0072be00
// -----------------------------------------------------------------------------
// Stable ID: aa_0072be00
// Address:   0x0072be00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072be00 @ 0x0072be00
// Stable ID: aa_0072be00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_0072be00, FUN_0072cbc0.
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

void __thiscall FUN_0072be00(int param_1,uint32_t /* width from decompiler */ *param_2,int param_3,uint32_t /* width from decompiler */ *param_4)



{

  int in_EAX;

  void *pvVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  int *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar5;

  

  (**(code **)(*unaff_EBX + 8))();

  unaff_EBX[4] = param_1;

  unaff_EBX[3] = in_EAX / 3;

  pvVar1 = operator_new__(param_1 * 0xc);

  uVar3 = in_EAX * 2;

  unaff_EBX[5] = (int)pvVar1;

  pvVar1 = operator_new__(uVar3);

  unaff_EBX[6] = (int)pvVar1;

  uVar2 = 0;

  if (unaff_EBX[4] != 0) {

    iVar4 = 0;

    do {

      puVar5 = (uint32_t /* width from decompiler */ *)(unaff_EBX[5] + iVar4);

      *puVar5 = *param_2;

      puVar5[1] = param_2[1];

      uVar2 = uVar2 + 1;

      puVar5[2] = param_2[2];

      iVar4 = iVar4 + 0xc;

      param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + param_3);

    } while (uVar2 < (uint)unaff_EBX[4]);

  }

  puVar5 = (uint32_t /* width from decompiler */ *)unaff_EBX[6];

  for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

    *puVar5 = *param_4;

    param_4 = param_4 + 1;

    puVar5 = puVar5 + 1;

  }

  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

    *(uint8_t *)puVar5 = *(uint8_t *)param_4;

    param_4 = (uint32_t /* width from decompiler */ *)((int)param_4 + 1);

    puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

  }

  FUN_0072cbc0(unaff_EBX[4],unaff_EBX + 1);

  return;

}
