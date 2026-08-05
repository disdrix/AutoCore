// =============================================================================
// FUN_006e8d10
// -----------------------------------------------------------------------------
// Stable ID: aa_006e8d10
// Address:   0x006e8d10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e8d10 @ 0x006e8d10
// Stable ID: aa_006e8d10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0063a190, FUN_006e8880, FUN_006e8d10.
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

uint32_t /* width from decompiler */ * FUN_006e8d10(uint32_t /* width from decompiler */ *param_1,int *param_2,int *param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*DAT_00b05060 + 0x10))(0x10,0x1a);

  puVar3[2] = param_4;

  *(uint16_t *)(puVar3 + 1) = 0x10;

  *puVar3 = &PTR_LAB_00a0e87c;

  iVar1 = *param_2;

  piVar2 = *(int **)(iVar1 + 0xc);

  FUN_006e8880(param_2[2]);

  FUN_0063a190(param_2[2] + 0x20,iVar1 + 0x10);

  iVar1 = *param_3;

  iVar4 = (**(code **)(*piVar2 + 0x14))();

  iVar5 = (**(code **)(*(int *)*param_1 + 0x14))();

  uVar6 = (**(code **)(iVar1 + 0x18c + (iVar4 * 0x20 + iVar5) * 4))

                    (&stack0xffffff78,param_1,param_3,param_4);

  puVar3[3] = uVar6;

  *puVar3 = &PTR_LAB_00a0e89c;

  return puVar3;

}
