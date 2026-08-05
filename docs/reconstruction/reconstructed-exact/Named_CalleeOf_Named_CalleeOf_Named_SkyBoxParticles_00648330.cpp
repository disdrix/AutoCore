// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_00648330
// -----------------------------------------------------------------------------
// Stable ID: aa_00648330
// Callee of Named_CalleeOf_Named_SkyBoxParticles
// Address:   0x00648330  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_SkyBoxParticles: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×2, while×1, return×1.
//  - Notable callees: FUN_0065ad10×2, FUN_00648330, FUN_00650420, FUN_0065ac90, FUN_0065acb0, FUN_0065acc0, FUN_0065ace0, FUN_0065af00.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_SkyBoxParticles
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_SkyBoxParticles_00648330(uint32_t /* width from decompiler */ *param_1)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ uStack_4;

  

  *param_1 = &PTR_FUN_009e4730;

  uStack_4 = param_1;

  uVar3 = FUN_0065ac90();

  pcVar4 = (char *)FUN_0065ad10((int)&uStack_4 + 3,uVar3);

  cVar1 = *pcVar4;

  while (cVar1 != '\0') {

    uVar5 = FUN_0065acb0(uVar3);

    (**(code **)(*DAT_00b05060 + 4))(uVar5);

    puVar6 = (uint32_t /* width from decompiler */ *)FUN_0065acc0(uVar3);

    if ((((uint)puVar6 & 1) == 0) &&

       (*(short *)((int)puVar6 + 6) = *(short *)((int)puVar6 + 6) + -1,

       *(short *)((int)puVar6 + 6) == 0)) {

      (**(code **)*puVar6)(1);

    }

    uVar3 = FUN_0065ace0(uVar3);

    pcVar4 = (char *)FUN_0065ad10((int)&uStack_4 + 3,uVar3);

    cVar1 = *pcVar4;

  }

  iVar2 = param_1[2];

  if (iVar2 != 0) {

    FUN_00650420();

    FUN_0065af00();

    (**(code **)(*DAT_00b05060 + 0x14))(iVar2,0x18,0x17);

  }

  *param_1 = &PTR_LAB_009cc290;

  return;

}
