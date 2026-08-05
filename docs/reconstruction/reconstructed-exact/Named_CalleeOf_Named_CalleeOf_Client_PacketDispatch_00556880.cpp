// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00556880
// -----------------------------------------------------------------------------
// Stable ID: aa_00556880
// Callee of Named_CalleeOf_Client_PacketDispatch
// Address:   0x00556880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PacketDispatch: packet/network helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: FUN_00553fc0×3, FUN_004b8dc0×2, FUN_00490f40, FUN_00555f10, FUN_00556880, ROUND.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PacketDispatch
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_00556880(int param_1,int param_2,float param_3)



{

  float fVar1;

  uint uVar2;

  int iVar3;

  

  *(float *)(param_1 + 0x15c) = param_3;

  uVar2 = g_dwClientTickMs;

  if ((*(int *)(param_1 + 0x154) != param_2) && (param_2 != *(int *)(param_1 + 0x150))) {

    fVar1 = (float)*(int *)(param_1 + 0x3c);

    if (*(int *)(param_1 + 0x3c) < 0) {

      fVar1 = fVar1 + _DAT_00aaa5dc;

    }

    *(uint8_t *)(param_1 + 0x38) = 1;

    *(uint *)(param_1 + 0x158) = uVar2 - (int)ROUND(fVar1 * param_3);

    if (*(int *)(param_1 + 0x17c) != 0) {

      iVar3 = FUN_00553fc0(*(int *)(param_1 + 0x154));

      if (iVar3 != 0) {

        iVar3 = FUN_00553fc0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x150));

        if (iVar3 != 0) {

          FUN_004b8dc0(0,0);

        }

        if (*(int *)(param_1 + 0x180) != 0) {

          iVar3 = FUN_00553fc0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x150));

          if (iVar3 != 0) {

            FUN_004b8dc0(0,0);

          }

        }

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x150) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x154);

      }

      if (param_2 != *(int *)(param_1 + 0x150)) {

        FUN_00490f40();

      }

      *(int *)(param_1 + 0x154) = param_2;

      FUN_00555f10(*(uint32_t /* width from decompiler */ *)(param_1 + 0x188));

    }

    return;

  }

  *(int *)(param_1 + 0x154) = param_2;

  return;

}
