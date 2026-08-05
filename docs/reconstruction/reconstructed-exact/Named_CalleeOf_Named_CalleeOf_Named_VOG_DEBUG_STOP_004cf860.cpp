// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004cf860
// -----------------------------------------------------------------------------
// Stable ID: aa_004cf860
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
// Address:   0x004cf860  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×18, goto×11, return×2, do×1, while×1.
//  - Notable callees: _fpclass×24, FUN_004b4b20, FUN_004cf860.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004cf860(uint32_t /* width from decompiler */ *param_1,float *param_2)



{

  float *pfVar1;

  float fVar2;

  bool bVar3;

  bool bVar4;

  char cVar5;

  uint uVar6;

  int iVar7;

  int iVar8;

  

  if ((param_2[0xd] <= 0.0 && param_2[0xd] != 0.0) ||

     (((pfVar1 = (float *)param_2[0xc], pfVar1 != (float *)0x0 &&

       (((((((pfVar1[0xf] <= 0.0 && pfVar1[0xf] != 0.0 ||

             (pfVar1[0x16] <= 0.0 && pfVar1[0x16] != 0.0)) ||

            (pfVar1[0x17] <= 0.0 && pfVar1[0x17] != 0.0)) ||

           ((pfVar1[0x18] <= 0.0 && pfVar1[0x18] != 0.0 ||

            (pfVar1[0x1a] <= 0.0 && pfVar1[0x1a] != 0.0)))) || (pfVar1[0x1e] == 0.0)) ||

         (((0xff < (uint)pfVar1[0x1e] || (uVar6 = _fpclass((double)*pfVar1), (uVar6 & 0x207) != 0))

          || ((uVar6 = _fpclass((double)pfVar1[1]), (uVar6 & 0x207) != 0 ||

              (((uVar6 = _fpclass((double)pfVar1[2]), (uVar6 & 0x207) != 0 ||

                (uVar6 = _fpclass((double)pfVar1[3]), (uVar6 & 0x207) != 0)) ||

               (uVar6 = _fpclass((double)pfVar1[4]), (uVar6 & 0x207) != 0)))))))) ||

        (((uVar6 = _fpclass((double)pfVar1[5]), (uVar6 & 0x207) != 0 ||

          (uVar6 = _fpclass((double)pfVar1[6]), (uVar6 & 0x207) != 0)) ||

         ((uVar6 = _fpclass((double)pfVar1[7]), (uVar6 & 0x207) != 0 ||

          (((uVar6 = _fpclass((double)pfVar1[8]), (uVar6 & 0x207) != 0 ||

            (uVar6 = _fpclass((double)pfVar1[9]), (uVar6 & 0x207) != 0)) ||

           ((uVar6 = _fpclass((double)pfVar1[10]), (uVar6 & 0x207) != 0 ||

            (uVar6 = _fpclass((double)pfVar1[0xb]), (uVar6 & 0x207) != 0)))))))))))) ||

      ((((((uVar6 = _fpclass((double)*param_2), (uVar6 & 0x207) != 0 ||

           (uVar6 = _fpclass((double)param_2[1]), (uVar6 & 0x207) != 0)) ||

          (uVar6 = _fpclass((double)param_2[2]), (uVar6 & 0x207) != 0)) ||

         ((uVar6 = _fpclass((double)param_2[3]), (uVar6 & 0x207) != 0 ||

          (uVar6 = _fpclass((double)param_2[4]), (uVar6 & 0x207) != 0)))) ||

        (uVar6 = _fpclass((double)param_2[5]), (uVar6 & 0x207) != 0)) ||

       (((uVar6 = _fpclass((double)param_2[6]), (uVar6 & 0x207) != 0 ||

         (uVar6 = _fpclass((double)param_2[7]), (uVar6 & 0x207) != 0)) ||

        ((uVar6 = _fpclass((double)param_2[8]), (uVar6 & 0x207) != 0 ||

         (((uVar6 = _fpclass((double)param_2[9]), (uVar6 & 0x207) != 0 ||

           (uVar6 = _fpclass((double)param_2[10]), (uVar6 & 0x207) != 0)) ||

          (uVar6 = _fpclass((double)param_2[0xb]), (uVar6 & 0x207) != 0))))))))))))

  goto LAB_004cfc6f;

  iVar8 = 0;

  if ((param_2[0xc] == 0.0) && ((int)param_2[0x15] - (int)param_2[0x14] >> 2 != 0))

  goto LAB_004cfc3d;

  uVar6 = 0;

  if ((int)param_2[0x15] - (int)param_2[0x14] >> 2 == 0) {

LAB_004cfb86:

    fVar2 = param_2[0xc];

    if (((fVar2 != 0.0) && ((*(byte *)((int)fVar2 + 0x6c) & 0x80) == 0)) &&

       ((*(float *)((int)fVar2 + 0x3c) <= 0.0 && *(float *)((int)fVar2 + 0x3c) != 0.0 ||

        ((((*(uint *)((int)fVar2 + 0x30) & 0x7fffffff) == 0 &&

          ((*(uint *)((int)fVar2 + 0x34) & 0x7fffffff) == 0)) &&

         ((*(uint *)((int)fVar2 + 0x38) & 0x7fffffff) == 0)))))) goto LAB_004cfc6f;

  }

  else {

    do {

      cVar5 = (**(code **)(**(int **)((int)param_2[0x14] + uVar6 * 4) + 8))();

      if (cVar5 == '\0') goto LAB_004cfc6f;

      if ((*(byte *)(*(int *)((int)param_2[0x14] + uVar6 * 4) + 0x38) & 7) == 0) {

        iVar8 = iVar8 + 1;

      }

      uVar6 = uVar6 + 1;

    } while (uVar6 < (uint)((int)param_2[0x15] - (int)param_2[0x14] >> 2));

    if (iVar8 == 0) goto LAB_004cfb86;

  }

  fVar2 = param_2[0xc];

  if ((fVar2 == 0.0) || (*(float *)((int)fVar2 + 0x3c) == 0.0)) {

    bVar3 = false;

  }

  else {

    bVar3 = true;

  }

  if (fVar2 == 0.0) {

LAB_004cfc25:

    bVar4 = false;

  }

  else {

    if ((((*(uint *)((int)fVar2 + 0x30) & 0x7fffffff) == 0) &&

        ((*(uint *)((int)fVar2 + 0x34) & 0x7fffffff) == 0)) &&

       ((*(uint *)((int)fVar2 + 0x38) & 0x7fffffff) == 0)) {

      iVar7 = 1;

    }

    else {

      iVar7 = 0;

    }

    if (0.0 < (float)iVar7) goto LAB_004cfc25;

    bVar4 = true;

  }

  if (iVar8 == 0) {

    if (param_2[0xd] != 0.0) goto LAB_004cfc6f;

  }

  else {

    if (param_2[0xd] != 0.0) {

      if ((bVar3) || (bVar4)) goto LAB_004cfc6f;

      goto LAB_004cfc3d;

    }

    if (!bVar3) goto LAB_004cfc6f;

    if (!bVar4) goto LAB_004cfc3d;

  }

  if ((!bVar3) || (!bVar4)) {

LAB_004cfc6f:

    *param_1 = 0;

    return;

  }

LAB_004cfc3d:

  FUN_004b4b20(param_1,param_2);

  return;

}
