// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00447ea0, FUN_0044c3c0, FUN_00986a60, FUN_0099a820, FUN_0099a8e0, vog_LogMessage.
//  - Strings: ",0x66,3,

                   ".
//  - Return sites: 2.

// =============================================================================
// Named_gfxVertexBufferImpl_0099a8e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0099a8e0
// Address:   0x0099a8e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxVertexBufferImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall

Named_gfxVertexBufferImpl_0099a8e0(int param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ *param_5)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  

  FUN_0099a820();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = param_2;

  *(uint32_t /* width from decompiler */ **)(param_1 + 0x1c) = param_5;

  FUN_00447ea0();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = *(uint32_t /* width from decompiler */ *)(param_3 + 0x10);

  uVar3 = DAT_00d1f634;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = *(uint32_t /* width from decompiler */ *)(param_3 + 0x14);

  iVar4 = FUN_00986a60(uVar3,param_1,param_4);

  if (iVar4 < 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x34) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0;

    FUN_0044c3c0(0,0);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxVertexBufferImpl.cpp",0x66,3,

                   "Failed to Allocate Vertex Buffer");

    iVar4 = -1;

  }

  else {

    if (param_5 != (uint32_t /* width from decompiler */ *)0x0) {

      iVar4 = (**(code **)*param_5)(param_1);

    }

    iVar2 = DAT_00d1f614;

    if (DAT_00d1f614 != 0) {

      *(int *)(DAT_00d1f614 + 0x388) =

           *(int *)(DAT_00d1f614 + 0x388) +

           *(int *)(*(int *)(param_1 + 0x10) + 8) * *(int *)(param_1 + 0x18);

      piVar1 = (int *)(iVar2 + 0x338);

      *piVar1 = *piVar1 + *(int *)(param_1 + 0x18);

      piVar1 = (int *)(iVar2 + 0x334);

      *piVar1 = *piVar1 + 1;

      return iVar4;

    }

  }

  return iVar4;

}
