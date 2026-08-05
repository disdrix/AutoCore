// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_004bafe0, FUN_005131b0, FUN_00521310, FUN_005c9120, GetTickCount.
//  - Return sites: 1.

// =============================================================================
// CVOGCharacter_CreateFromPacket
// -----------------------------------------------------------------------------
// Stable ID: aa_005237a0
// Address:   0x005237a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

void __thiscall

CVOGCharacter_CreateFromPacket

          (int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4,uint32_t /* width from decompiler */ param_5,

          uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8)



{

  DWORD DVar1;

  int iVar2;

  int iVar3;

  

  FUN_005c9120(param_2,param_3,param_4,param_5,param_6,param_7,param_8);

  if (((*(uint *)(param_1 + -0xb90) & *(uint *)(param_1 + -0xb8c)) != 0xffffffff) && (param_4 != 0))

  {

    DVar1 = GetTickCount();

    *(DWORD *)(param_1 + -0xd8c) = DVar1;

    iVar2 = FUN_004bafe0(*(uint8_t *)

                          (*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xc34 + param_1),

                         *(uint32_t /* width from decompiler */ *)(param_1 + -0xb90),*(uint32_t /* width from decompiler */ *)(param_1 + -0xb8c));

    *(int *)(param_1 + -0xb50) = iVar2;

    if (iVar2 != 0) {

      if (param_1 == 0xda0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xd9c + param_1;

      }

      FUN_005131b0(iVar3);

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x218))

                (*(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xcf8 + param_1));

    }

    if (((char)param_7 == '\0') ||

       ((*(uint *)(*(int *)(*(int *)(param_1 + -0xd9c) + 4) + -0xc20 + param_1) >> 6 & 1) == 0)) {

      FUN_00521310(param_2,param_3,param_5,param_6,param_7,0);

    }

  }

  return;

}
