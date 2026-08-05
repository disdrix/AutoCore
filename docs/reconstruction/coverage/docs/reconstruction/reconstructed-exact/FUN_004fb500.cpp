// =============================================================================
// FUN_004fb500
// -----------------------------------------------------------------------------
// Stable ID: aa_004fb500
// Address:   0x004fb500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

void __thiscall FUN_004fb500(int param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  byte bVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  if (*(int *)(param_1 + 8) == 0) {
    pfVar4 = (float *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);
  }
  else {
    pfVar4 = (float *)(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0xb0);
  }
  fVar6 = *pfVar4;
  fVar7 = pfVar4[1];
  fVar8 = pfVar4[2];
  fVar1 = pfVar4[3];
  iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);
  if (iVar2 != 0) {
    bVar5 = 0;
    do {
      if ((char)((int)(7 << (bVar5 * '\x03' & 0x1f) & *(uint *)(iVar2 + 0x50c)) >>
                (bVar5 * '\x03' & 0x1f)) == '\x02') {
        iVar3 = (char)bVar5 * 0xc;
        if (iVar3 + 0x4e8 + iVar2 != 0) {
          iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c);
          fVar6 = *(float *)(iVar2 + 0x4e8 + iVar3) + fVar6;
          fVar7 = *(float *)(iVar2 + ((char)bVar5 * 3 + 0x13b) * 4) + fVar7;
          fVar8 = *(float *)(iVar2 + 0x4f0 + iVar3) + fVar8;
        }
        break;
      }
      bVar5 = bVar5 + 1;
    } while (bVar5 < 3);
  }
  *param_2 = fVar6;
  param_2[1] = fVar7;
  param_2[2] = fVar8;
  param_2[3] = fVar1;
  return;
}
