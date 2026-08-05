// =============================================================================
// Named_CalleeOf_Named_ChatClientImpl_00673c90
// -----------------------------------------------------------------------------
// Stable ID: aa_00673c90
// Callee of Named_ChatClientImpl
// Address:   0x00673c90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_ChatClientImpl: social/chat helper. Evidence string: "Couldnt create DS device\n". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Couldnt create DS device\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: DirectSoundCreate8, FUN_00673c90, FUN_0076c130.
//  - Strings: "Couldnt create DS device\n".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_ChatClientImpl
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

uint32_t /* width from decompiler */ __thiscall

Named_CalleeOf_Named_ChatClientImpl_00673c90(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5

            ,uint32_t /* width from decompiler */ param_6,int *param_7)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  int *local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  piVar2 = param_7;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8) = param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xac) = param_4;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x150) = param_5;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x158) = param_6;

  piVar1 = (int *)(param_1 + 0xb0);

  if (*param_7 == 0) {

    iVar3 = DirectSoundCreate8(param_1 + 0xb4,piVar1,0);

    if (iVar3 < 0) {

      FUN_0076c130("Couldnt create DS device\n");

      return 0xffffffff;

    }

    (**(code **)(*(int *)*piVar1 + 0x18))((int *)*piVar1,param_2,2);

    *piVar2 = *piVar1;

  }

  else {

    *piVar1 = *param_7;

  }

  if (*(int *)(param_1 + 0x158) == 2) {

    local_1c = 0;

    local_18 = 0;

    local_14 = (int *)0x0;

    local_10 = 0;

    local_c = 0;

    local_8 = (uint32_t /* width from decompiler */ *)0x0;

    local_4 = 0;

    local_24 = 0x24;

    local_20 = 0x11;

    iVar3 = (**(code **)(*(int *)*piVar1 + 0xc))((int *)*piVar1,&local_24,&param_3,0);

    if (-1 < iVar3) {

      iVar3 = (**(code **)*local_8)(local_8,&DAT_00a0d044,param_1 + 0x15c);

      if (iVar3 < 0) {

        (**(code **)(*local_14 + 8))(local_14);

      }

    }

  }

  return 0;

}
