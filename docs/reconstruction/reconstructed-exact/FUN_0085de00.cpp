// =============================================================================
// FUN_0085de00
// -----------------------------------------------------------------------------
// Stable ID: aa_0085de00
// Address:   0x0085de00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0085de00 @ 0x0085de00
// Stable ID: aa_0085de00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_00413680, FUN_00413f50, FUN_0056add0, FUN_0085de00.
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



void FUN_0085de00(int *param_1,char param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int *in_EAX;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_ESI;

  int unaff_EDI;

  float fVar4;

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  int aiStack_30 [3];

  int iStack_24;

  int iStack_20;

  int iStack_1c;

  uint8_t auStack_18 [24];

  

  if ((in_EAX != (int *)0x0) && (iVar2 = (**(code **)(*in_EAX + 0x1e0))(), iVar2 != 0)) {

    iVar2 = (**(code **)(*in_EAX + 0x1e0))();

    iVar2 = *(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xac + iVar2);

    if (iVar2 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(iVar2 + 0x3c);

    }

    if (*(char *)(iVar2 + 0x3f4) != '\t') {

      fVar4 = (float)DAT_00d1e818 * _DAT_00aaab6c;

      (**(code **)(*in_EAX + 0x1e0))();

      aiStack_30[0] = FUN_0056add0();

      puVar3 = &DAT_00afdf00;

      if (param_2 == '\0') {

        puVar3 = &DAT_00afdf0c;

      }

      uVar1 = *puVar3;

      (**(code **)(*param_1 + 0x140))(&uStack_38,1);

      if ((DAT_00d1ad30 != 0) && (iVar2 = *(int *)(DAT_00d1ad30 + 0xc), iVar2 != 0)) {

        aiStack_30[2] = (unaff_EDI - (int)fVar4) + -1;

        iStack_20 = unaff_EDI + -1;

        iStack_1c = unaff_ESI + -2;

        uStack_38 = 0x20;

        uStack_34 = 0x20;

        iStack_24 = (unaff_ESI - (int)fVar4) + -2;

        aiStack_30[0] = aiStack_30[0] << 5;

        aiStack_30[1] = 0;

        FUN_00413f50(aiStack_30,&uStack_38);

        FUN_00413680(aiStack_30 + 2,iVar2,0,uVar1,1,auStack_18,0,&DAT_00d1ecac);

      }

    }

  }

  return;

}
