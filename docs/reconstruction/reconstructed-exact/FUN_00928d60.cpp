// =============================================================================
// FUN_00928d60
// -----------------------------------------------------------------------------
// Stable ID: aa_00928d60
// Address:   0x00928d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00928d60 @ 0x00928d60
// Stable ID: aa_00928d60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: for×3, if×1, return×1.
//  - Notable callees: FUN_00928d60.
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

uint32_t /* width from decompiler */ __fastcall FUN_00928d60(int param_1,int *param_2,int param_3,int param_4)



{

  int in_EAX;

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iStack_2c;

  uint32_t /* width from decompiler */ *puStack_28;

  uint32_t /* width from decompiler */ *puStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ local_c [3];

  

  uStack_20 = 0;

  puStack_24 = local_c;

  puStack_28 = (uint32_t /* width from decompiler */ *)0x0;

  iStack_2c = param_3;

  local_c[0] = 0;

  iVar1 = (**(code **)(*param_2 + 0x5c))(param_2,param_1);

  if (((-1 < iVar1) || (iVar1 = (**(code **)(*param_2 + 0x5c))(param_2,param_1), -1 < iVar1)) &&

     (iVar1 = (**(code **)(iRam00000200 + 0x4c))(0x200,0,&iStack_2c,0,0), -1 < iVar1)) {

    puVar3 = puStack_28;

    for (; in_EAX != 0; in_EAX = in_EAX + -1) {

      puVar4 = puVar3;

      for (uVar2 = (uint)(param_4 * param_1) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

        *puVar4 = 0;

        puVar4 = puVar4 + 1;

      }

      for (uVar2 = param_4 * param_1 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

        *(uint8_t *)puVar4 = 0;

        puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

      }

      puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + iStack_2c);

    }

    (**(code **)(iRam00000200 + 0x50))(0x200,0);

  }

  return 0x200;

}
