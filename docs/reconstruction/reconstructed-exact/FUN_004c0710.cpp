// =============================================================================
// FUN_004c0710
// -----------------------------------------------------------------------------
// Stable ID: aa_004c0710
// Address:   0x004c0710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c0710 @ 0x004c0710
// Stable ID: aa_004c0710
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: ROUND×2, CONCAT11, CONCAT31, FUN_004c0710.
//  - Return sites: 2.

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

uint __thiscall

FUN_004c0710(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,float param_4,float param_5,

            uint8_t param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8)



{

  int iVar1;

  int iVar2;

  uint in_EAX;

  uint uVar3;

  uint8_t local_4;

  

  uVar3 = *(uint *)(param_1 + 0xc0);

  if (uVar3 < *(uint *)(param_1 + 0xbc)) {

    local_4 = (uint8_t)(int)ROUND(param_5 * DAT_00aaa6f8);

    param_4 = param_4 * DAT_00aaa6f8;

    iVar1 = uVar3 * 4;

    iVar2 = uVar3 * 0x70;

    *(uint32_t /* width from decompiler */ *)(iVar2 + *(int *)(param_1 + 0xb4)) = *param_2;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 4 + iVar2) = param_2[1];

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 8 + iVar2) = param_2[2];

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 0xc + iVar2) = param_3;

    uVar3 = (uint)CONCAT11(param_6,local_4) << 8 | (int)ROUND(param_4) & 0xffU;

    *(uint *)(*(int *)(param_1 + 0xb4) + 0x10 + iVar2) = uVar3;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 0x14 + iVar2) = param_7;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 0x18 + iVar2) = param_8;

    iVar2 = (iVar1 + 1) * 0x1c;

    *(uint32_t /* width from decompiler */ *)(iVar2 + *(int *)(param_1 + 0xb4)) = *param_2;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 4 + iVar2) = param_2[1];

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 8 + iVar2) = param_2[2];

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 0xc + iVar2) = param_3;

    *(uint *)(iVar2 + 0x10 + *(int *)(param_1 + 0xb4)) = uVar3 | 0x3f000000;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 0x14 + iVar2) = param_7;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 0x18 + iVar2) = param_8;

    iVar2 = (iVar1 + 2) * 0x1c;

    *(uint32_t /* width from decompiler */ *)(iVar2 + *(int *)(param_1 + 0xb4)) = *param_2;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 4 + iVar2) = param_2[1];

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 8 + iVar2) = param_2[2];

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 0xc + iVar2) = param_3;

    *(uint *)(iVar2 + 0x10 + *(int *)(param_1 + 0xb4)) = uVar3 | 0x7f000000;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 0x14 + iVar2) = param_7;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 0x18 + iVar2) = param_8;

    iVar2 = (iVar1 + 3) * 0x1c;

    *(uint32_t /* width from decompiler */ *)(iVar2 + *(int *)(param_1 + 0xb4)) = *param_2;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 4 + iVar2) = param_2[1];

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 8 + iVar2) = param_2[2];

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 0xc + iVar2) = param_3;

    *(uint *)(*(int *)(param_1 + 0xb4) + 0x10 + iVar2) = uVar3 | 0xbf000000;

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xb4) + 0x14 + iVar2) = param_7;

    iVar1 = *(int *)(param_1 + 0xb4);

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x18 + iVar2) = param_8;

    *(int *)(param_1 + 0xc0) = *(int *)(param_1 + 0xc0) + 1;

    return CONCAT31((int3)((uint)iVar1 >> 8),1);

  }

  return in_EAX & 0xffffff00;

}
