// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_007ac1c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007ac1c0
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x007ac1c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~102 non-empty decompiler lines.
//  - Control keywords: if×17, return×2, do×1, while×1.
//  - Notable callees: QueryPerformanceCounter×4, FUN_007abfe0×2, FUN_007a83a0, FUN_007abf80, FUN_007abfb0, FUN_007ac1c0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

void __thiscall Named_CalleeOf_Named_VOG_DEBUG_STOP_007ac1c0(int *param_1,char param_2,int param_3)



{

  char cVar1;

  uint8_t *puVar2;

  int iVar3;

  float fVar4;

  

  param_1[0x50] = param_3;

  if (param_2 == '\0') {

    cVar1 = (**(code **)(*param_1 + 0xd0))();

    if (cVar1 != '\0') {

      cVar1 = (**(code **)(*param_1 + 0xf0))(1);

      if (cVar1 != '\0') {

        if (param_1[0x88] == 1) {

          FUN_007abfb0();

        }

        else if (param_1[0x88] != -1) {

          FUN_007abfe0();

        }

      }

      (**(code **)(*param_1 + 0xf0))(2);

      cVar1 = (**(code **)(*param_1 + 0xf0))(4);

      if (cVar1 != '\0') {

        if (param_1[0x88] == 1) {

          FUN_007abf80();

        }

        else if (param_1[0x88] != -1) {

          FUN_007a83a0();

        }

      }

      (**(code **)(*param_1 + 0xf0))(8);

      puVar2 = (uint8_t *)param_1[0xae];

      iVar3 = param_1[0x50];

      param_1[0x88] = -1;

      QueryPerformanceCounter((LARGE_INTEGER *)(puVar2 + 0x10));

      QueryPerformanceCounter((LARGE_INTEGER *)(puVar2 + 0x18));

      *(int *)(puVar2 + 8) = iVar3;

      *(int *)(puVar2 + 0xc) = iVar3;

      fVar4 = DAT_00afa134 + g_flOne;

      *puVar2 = 1;

      param_1[0x51] = (int)fVar4;

      if (param_1[0x3d] == 0) {

        (**(code **)(*param_1 + 0x100))();

      }

    }

  }

  else {

    cVar1 = (**(code **)(*param_1 + 0xf0))(1);

    if (cVar1 != '\0') {

      if (param_1[0x88] == -1) {

        *(char *)((int)param_1 + 0x22b) = (char)param_1[0x3e];

        *(char *)((int)param_1 + 0x22f) = (char)param_1[0x3f];

        *(char *)((int)param_1 + 0x233) = (char)param_1[0x40];

      }

      else if (param_1[0x88] != 1) {

        FUN_007abfe0();

      }

      puVar2 = (uint8_t *)((int)param_1 + 0x22b);

      iVar3 = 3;

      do {

        *puVar2 = 0;

        puVar2 = puVar2 + 4;

        iVar3 = iVar3 + -1;

      } while (iVar3 != 0);

    }

    (**(code **)(*param_1 + 0xf0))(2);

    cVar1 = (**(code **)(*param_1 + 0xf0))(4);

    if (cVar1 != '\0') {

      if (param_1[0x88] == -1) {

        param_1[0x8a] = param_1[0x41];

        param_1[0x8b] = param_1[0x42];

        param_1[0x8c] = param_1[0x43];

      }

      else if (param_1[0x88] != 1) {

        param_1[0x41] = param_1[0x8a];

        param_1[0x42] = param_1[0x8b];

        param_1[0x43] = param_1[0x8c];

      }

    }

    (**(code **)(*param_1 + 0xf0))(8);

    cVar1 = (**(code **)(*param_1 + 0xd0))();

    if (cVar1 == '\0') {

      (**(code **)(*param_1 + 0xcc))(1);

    }

    (**(code **)(*param_1 + 0x34c))();

    puVar2 = (uint8_t *)param_1[0xae];

    iVar3 = param_1[0x50];

    param_1[0x88] = 1;

    QueryPerformanceCounter((LARGE_INTEGER *)(puVar2 + 0x10));

    QueryPerformanceCounter((LARGE_INTEGER *)(puVar2 + 0x18));

    *(int *)(puVar2 + 8) = iVar3;

    *(int *)(puVar2 + 0xc) = iVar3;

    fVar4 = DAT_00afa134 + g_flOne;

    *puVar2 = 1;

    param_1[0x51] = (int)fVar4;

    (**(code **)(*param_1 + 0x1f0))();

    if (param_1[0x3d] == 0) {

      (**(code **)(*param_1 + 0x100))();

      return;

    }

  }

  return;

}
