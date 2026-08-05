// =============================================================================
// FUN_0053e130
// -----------------------------------------------------------------------------
// Stable ID: aa_0053e130
// Address:   0x0053e130  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053e130 @ 0x0053e130
// Stable ID: aa_0053e130
// Embedded strings (evidence for future rename):
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_004ec040, FUN_004f2890, FUN_0053ce70, FUN_0053d430, FUN_0053d720, FUN_0053e130, FUN_00560ec0, FUN_005f5700.
//  - Strings: "VOG_DEBUG_STOP".
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

void __thiscall FUN_0053e130(int param_1,float param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iVar5;

  

  if ((param_2 != g_flOne) ||

     (*(float *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + 0x6c + param_1) != g_flOne)) {

    *(float *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + 0x6c + param_1) = param_2;

    if (*(int *)(param_1 + -0x48) != 0) {

      iVar2 = *(int *)(*(int *)(param_1 + -0x48) + 0x3c);

      uVar1 = *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + 0x6c + param_1);

      iVar5 = iVar2 + 0x30;

      iVar2 = iVar2 + 0xb0;

      uVar3 = (**(code **)(*(int *)(param_1 + -0x50) + 0x18))();

      iVar4 = FUN_004f2890(uVar1,iVar2,iVar5,uVar3);

      if (iVar4 != 0) {

        if (*(int *)(*(int *)(*(int *)(param_1 + -0x4c) + 4) + 0x58 + param_1) == 0) {

          FUN_007a4480(0,"VOG_DEBUG_STOP");

        }

        FUN_0053d720();

        *(int *)(param_1 + -0x48) = iVar4;

        iVar4 = 0;

        if (param_1 != 0x50) {

          iVar4 = *(int *)(*(int *)(param_1 + -0x4c) + 4) + -0x4c + param_1;

        }

        FUN_005f5700(1,iVar4);

        FUN_00560ec0(*(uint32_t /* width from decompiler */ *)(param_1 + -0x48));

        iVar4 = *(int *)(*(int *)(param_1 + -0x4c) + 4) + param_1;

        iVar5 = FUN_004ec040(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x6c),iVar2,iVar5,*(uint32_t /* width from decompiler */ *)(iVar4 + 0x58)

                            );

        if (iVar5 != 0) {

          FUN_0053ce70();

          *(int *)(param_1 + -0x44) = iVar5;

        }

        FUN_0053d430();

        (**(code **)(*(int *)(param_1 + -0x50) + 8))();

      }

    }

  }

  return;

}
