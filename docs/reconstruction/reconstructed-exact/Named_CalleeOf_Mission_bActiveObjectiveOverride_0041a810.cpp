// =============================================================================
// Named_CalleeOf_Mission_bActiveObjectiveOverride_0041a810
// -----------------------------------------------------------------------------
// Stable ID: aa_0041a810
// Callee of Mission_bActiveObjectiveOverride (+9 other named callers)
// Address:   0x0041a810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_bActiveObjectiveOverride: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Mission_bActiveObjectiveOverride (+9 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, for×1.
//  - Notable callees: FUN_0041de50×2, FUN_00422d10×2, FUN_0041a810, MultiByteToWideChar, lstrlenA.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Mission_bActiveObjectiveOverride (+9 other named callers)
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Unable to track spacebase fully for stack */



void Named_CalleeOf_Mission_bActiveObjectiveOverride_0041a810(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int iVar3;

  uint8_t *puVar4;

  uint uVar5;

  LPCSTR unaff_EBX;

  uint8_t *puVar6;

  UINT aUStackY_2c [2];

  DWORD aDStackY_24 [3];

  

  uVar1 = (*(code *)PTR_FUN_00af8c9c)();

  if (unaff_EBX == (LPCSTR)0x0) {

    aDStackY_24[2] = 0x41a836;

    iVar2 = FUN_00422d10();

    if (-1 < iVar2) {

      aDStackY_24[2] = param_4;

      aDStackY_24[1] = param_3;

      aDStackY_24[0] = 0x41a855;

      FUN_0041de50();

      return;

    }

  }

  else {

    iVar3 = lstrlenA(unaff_EBX);

    puVar4 = (uint8_t *)((iVar3 + 1) * 2 + 3U & 0xfffffffc);

    iVar2 = -(int)puVar4;

    puVar6 = &stack0xfffffff0 + iVar2;

    if (&stack0xfffffff0 == puVar4) {

      uVar5 = 0;

    }

    else {

      *(int *)(&stack0xffffffec + iVar2) = iVar3 + 1;

      *(uint8_t **)(&stack0xffffffe8 + iVar2) = &stack0xfffffff0 + iVar2;

      *(uint32_t /* width from decompiler */ *)((int)aDStackY_24 + iVar2 + 8) = 0xffffffff;

      *(LPCSTR *)((int)aDStackY_24 + iVar2 + 4) = unaff_EBX;

      *(uint32_t /* width from decompiler */ *)((int)aDStackY_24 + iVar2) = 0;

      *(uint32_t /* width from decompiler */ *)((int)aUStackY_2c + iVar2 + 4) = uVar1;

      *(uint16_t *)(&stack0xfffffff0 + iVar2) = 0;

      puVar6 = (uint8_t *)((int)aUStackY_2c + iVar2);

      *(uint32_t /* width from decompiler */ *)((int)aUStackY_2c + iVar2) = 0x41a895;

      iVar3 = MultiByteToWideChar(*(UINT *)((int)aUStackY_2c + iVar2 + 4),

                                  *(DWORD *)((int)aDStackY_24 + iVar2),

                                  *(LPCSTR *)((int)aDStackY_24 + iVar2 + 4),

                                  *(int *)((int)aDStackY_24 + iVar2 + 8),

                                  *(LPWSTR *)(&stack0xffffffe8 + iVar2),

                                  *(int *)(&stack0xffffffec + iVar2));

      uVar5 = -(uint)(iVar3 != 0) & (uint)(&stack0xfffffff0 + iVar2);

    }

    *(uint32_t /* width from decompiler */ *)(puVar6 + -4) = param_5;

    *(uint *)(puVar6 + -8) = uVar5;

    *(uint32_t /* width from decompiler */ *)(puVar6 + -0xc) = 0x41a8b2;

    iVar2 = FUN_00422d10();

    if (-1 < iVar2) {

      *(uint32_t /* width from decompiler */ *)(puVar6 + -4) = param_7;

      *(uint32_t /* width from decompiler */ *)(puVar6 + -8) = param_6;

      *(uint32_t /* width from decompiler */ *)(puVar6 + -0xc) = param_4;

      *(uint32_t /* width from decompiler */ *)(puVar6 + -0x10) = param_3;

      *(uint32_t /* width from decompiler */ *)(puVar6 + -0x14) = 0x41a8cd;

      FUN_0041de50();

    }

  }

  return;

}
