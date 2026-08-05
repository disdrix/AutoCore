// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00631dc0×6, FUN_00631da0, FUN_00631e10, FUN_00631f80, FUN_0063f630, FUN_00640e30.
//  - Strings: "VisualDebugger: ["; " with new client"; "Registering viewer ".
//  - Return sites: 1.

// =============================================================================
// Named_with_new_client_00640e30
// -----------------------------------------------------------------------------
// Stable ID: aa_00640e30
// Address:   0x00640e30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: " with new client"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __fastcall Named_with_new_client_00640e30(int *param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int iVar4;

  uint8_t *puVar5;

  int iVar6;

  uint16_t *puVar7;

  char *pcVar8;

  char *pcVar9;

  uint32_t /* width from decompiler */ uVar10;

  

  piVar1 = (int *)FUN_0063f630();

  iVar4 = 0;

  if (0 < piVar1[1]) {

    iVar3 = 0;

    do {

      if (0 < DAT_00d030ec) {

        pcVar9 = "VisualDebugger: [";

        (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

        FUN_00631dc0(pcVar9);

        uVar2 = *(uint32_t /* width from decompiler */ *)(iVar3 + *piVar1);

        uVar10 = 0x5d;

        pcVar8 = " with new client";

        puVar7 = &DAT_00a62c94;

        puVar5 = &DAT_00a62c98;

        pcVar9 = "Registering viewer ";

        iVar6 = iVar4;

        (**(code **)(*DAT_00d030e0 + 4))

                  ("Registering viewer ",uVar2,&DAT_00a62c98,iVar4,&DAT_00a62c94," with new client",

                   0x5d);

        FUN_00631dc0(pcVar9);

        FUN_00631dc0(uVar2);

        FUN_00631dc0(puVar5);

        FUN_00631e10(iVar6);

        FUN_00631dc0(puVar7);

        FUN_00631dc0(pcVar8);

        uVar2 = FUN_00631da0(uVar10);

        FUN_00631f80(uVar2);

      }

      (**(code **)(*param_1 + 4))

                (*(int *)(iVar3 + *piVar1),*(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + *piVar1) + -0xc),iVar4);

      iVar4 = iVar4 + 1;

      iVar3 = iVar3 + 0xc;

    } while (iVar4 < piVar1[1]);

  }

  return 0;

}
