// =============================================================================
// FUN_00787d40
// -----------------------------------------------------------------------------
// Stable ID: aa_00787d40
// Address:   0x00787d40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00787d40 @ 0x00787d40
// Stable ID: aa_00787d40
// Embedded strings (evidence for future rename):
//   - "Unpacked too much! %d + %d > %d"
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×2, for×2, if×1.
//  - Notable callees: FUN_007a4480×2, FUN_00787d40.
//  - Strings: "Unpacked too much! %d + %d > %d"; "VOG_DEBUG_STOP".
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

void __thiscall FUN_00787d40(int param_1,uint32_t /* width from decompiler */ *param_2,uint param_3)



{

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  iVar1 = *(int *)(param_1 + 0x101c);

  if (*(int *)(param_1 + 0x1018) < (int)(iVar1 + param_3)) {

    FUN_007a4480(1,"Unpacked too much! %d + %d > %d",iVar1,param_3,*(int *)(param_1 + 0x1018));

    FUN_007a4480(0,"VOG_DEBUG_STOP");

    return;

  }

  puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1014) + iVar1);

  for (uVar2 = param_3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

    *param_2 = *puVar3;

    puVar3 = puVar3 + 1;

    param_2 = param_2 + 1;

  }

  for (uVar2 = param_3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

    *(uint8_t *)param_2 = *(uint8_t *)puVar3;

    puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

    param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

  }

  *(int *)(param_1 + 0x101c) = *(int *)(param_1 + 0x101c) + param_3;

  return;

}
