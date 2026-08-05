// =============================================================================
// FUN_009952b0
// -----------------------------------------------------------------------------
// Stable ID: aa_009952b0
// Address:   0x009952b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009952b0 @ 0x009952b0
// Stable ID: aa_009952b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: FUN_00414c20×2, FUN_0044bbc0×2, block×2, FUN_0044b9c0, FUN_00450e60, FUN_004533c0, FUN_00455e40, FUN_009952b0.
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

/* WARNING: Removing unreachable block (ram,0x0099540d) */

/* WARNING: Removing unreachable block (ram,0x00995412) */



void __thiscall

FUN_009952b0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4,uint32_t /* width from decompiler */ param_5)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint uVar3;

  uint uVar4;

  void *pvStack_24;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009b22cc;

  pvStack_14 = ExceptionList;

  if (*(int *)(param_1 + 0x14) == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + 0x18);

  }

  ExceptionList = &pvStack_14;

  FUN_00414c20(uVar2,param_5,8,0);

  if (*(int *)(param_1 + 0xc) == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc) + 0x1c);

  }

  FUN_0044b9c0(uVar2,8,0,0);

  FUN_0044bbc0(param_1 + 0x10,0,0);

  FUN_00450e60(param_1 + 8,0,0,0);

  if (*(char *)(param_1 + 0xcc) == '\0') {

    uVar3 = *(uint *)(param_1 + 0xd4);

    uVar4 = *(uint *)(param_1 + 0xd8);

    if (uVar3 < uVar4) {

      do {

        if (*(int *)(uVar3 + 4) == 0) {

          uVar2 = 0;

        }

        else {

          uVar2 = *(uint32_t /* width from decompiler */ *)(*(int *)(uVar3 + 4) + 0x18);

        }

        FUN_00414c20(uVar2,param_5,8,0);

        FUN_0044bbc0(uVar3,0,0);

        iVar1 = *(int *)(param_4 + 4);

        if ((iVar1 == 0) ||

           ((uint)(*(int *)(param_4 + 0xc) - iVar1 >> 3) <=

            (uint)(*(int *)(param_4 + 8) - iVar1 >> 3))) {

          FUN_004533c0(param_4,*(uint32_t /* width from decompiler */ *)(param_4 + 8),1,&stack0xffffffd0);

        }

        else {

          iVar1 = *(int *)(param_4 + 8);

          FUN_00455e40(iVar1,uVar4);

          *(int *)(param_4 + 8) = iVar1 + 8;

        }

        uVar3 = uVar3 + 8;

      } while (uVar3 < uVar4);

    }

  }

  ExceptionList = pvStack_24;

  return;

}
