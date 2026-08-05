// =============================================================================
// Named_CalleeOf_Named_Palantir_007540e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007540e0
// Callee of Named_Palantir
// Address:   0x007540e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Palantir: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~86 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: D3DXGetImageInfoFromFileA, D3DXLoadSurfaceFromFileA, FUN_007540e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Palantir
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

void Named_CalleeOf_Named_Palantir_007540e0(void)



{

  int *in_EAX;

  int iVar1;

  int unaff_ESI;

  int unaff_EDI;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uStack_78;

  int *piStack_74;

  uint32_t /* width from decompiler */ uStack_70;

  uint32_t /* width from decompiler */ uStack_6c;

  int *piStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  uint32_t /* width from decompiler */ uStack_60;

  uint32_t /* width from decompiler */ uStack_5c;

  int *piStack_58;

  int *piStack_54;

  int *piStack_50;

  uint32_t /* width from decompiler */ uStack_4c;

  uint uStack_48;

  uint uStack_44;

  int *piStack_40;

  int **ppiStack_3c;

  int local_34 [6];

  int *local_1c;

  uint32_t /* width from decompiler */ local_18;

  

  ppiStack_3c = &local_1c;

  uStack_44 = 0x7540f1;

  iVar1 = D3DXGetImageInfoFromFileA();

  if (-1 < iVar1) {

    piStack_54 = (int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x28);

    ppiStack_3c = (int **)0x0;

    piStack_40 = local_34;

    uStack_44 = 0;

    uStack_48 = 0x15;

    uStack_4c = local_18;

    piStack_50 = local_1c;

    piStack_58 = (int *)0x75411c;

    iVar1 = (**(code **)(*piStack_54 + 0x90))();

    if (-1 < iVar1) {

      piStack_58 = (int *)0x0;

      uStack_5c = 0;

      uStack_60 = 0xffffffff;

      uStack_64 = 0;

      uStack_6c = 0;

      uStack_70 = 0;

      piStack_74 = piStack_50;

      uStack_78 = 0x75413b;

      piStack_68 = in_EAX;

      iVar1 = D3DXLoadSurfaceFromFileA();

      if (-1 < iVar1) {

        uStack_48 = (uint)(*(int *)(unaff_ESI + 8) - unaff_EDI) >> 1;

        piStack_40 = (int *)(uStack_48 + unaff_EDI);

        uStack_44 = (uint)(*(int *)(unaff_ESI + 0xc) - local_34[0]) >> 1;

        piStack_58 = &uStack_4c;

        uStack_5c = 0;

        ppiStack_3c = (int **)(uStack_44 + local_34[0]);

        uStack_60 = 0;

        piStack_68 = (int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x28);

        uStack_64 = 0;

        uStack_6c = 0x754183;

        (**(code **)(*piStack_68 + 0x48))();

        uStack_6c = 0;

        uStack_70 = 0x3f800000;

        piStack_74 = (int *)0x0;

        uStack_78 = 1;

        uVar4 = 0;

        uVar3 = 0;

        (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x28) + 0xac))

                  ((int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x28),0,0);

        (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x28) + 0x88))

                  ((int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x28),uVar3,0,uVar4,&uStack_78,0);

        piVar2 = (int *)0x0;

        (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x28) + 0x44))

                  ((int *)**(uint32_t /* width from decompiler */ **)(unaff_ESI + 0x28),0,0,0,0);

        (**(code **)(*piVar2 + 8))(piVar2);

      }

      piStack_58 = piStack_50;

      uStack_5c = 0x7541e8;

      (**(code **)(*piStack_50 + 8))();

    }

  }

  return;

}
