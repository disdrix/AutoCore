// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_OnBadCharac_00931570
// -----------------------------------------------------------------------------
// Stable ID: aa_00931570
// Callee of Named_CalleeOf_Named_CalleeOf_Client_OnBadCharacterLoginId
// Address:   0x00931570  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_OnBadCharacterLoginId: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~105 non-empty decompiler lines.
//  - Control keywords: if×10, while×1, return×1.
//  - Notable callees: ROUND×2, FUN_007fdba0, FUN_008f6b70, FUN_008f6f60, FUN_008f7040, FUN_008f7140, FUN_00931570, fclose.
//  - Strings: "%d: %d,%d;\n".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_OnBadCharacterLoginId
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_OnBadCharac_00931570(int param_1)



{

  byte bVar1;

  int *piVar2;

  char cVar3;

  char *in_EAX;

  FILE *_File;

  int iVar4;

  float *pfVar5;

  int unaff_EBX;

  float local_64;

  float fStack_60;

  int iStack_5c;

  int iStack_58;

  int local_50;

  int local_4c;

  int iStack_48;

  float fStack_44;

  float local_40;

  float local_3c;

  float local_38;

  float local_34;

  float local_30;

  float local_2c;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  uint8_t local_18 [8];

  uint8_t local_10 [12];

  

  FUN_007fdba0();

  if (in_EAX != (char *)0x0) {

    _File = fopen(in_EAX,"r");

    if (_File != (FILE *)0x0) {

      local_64 = -NAN;

      bVar1 = (byte)_File->_flag;

      while ((bVar1 & 0x10) == 0) {

        iVar4 = fscanf(_File,"%d: %d,%d;\n",&local_64,&local_50,&local_4c);

        if ((iVar4 == 3) && (-1 < (int)local_64)) {

          if (((int)local_64 < 0x3a) &&

             (iVar4 = *(int *)(param_1 + 0x1030 + (int)local_64 * 4), iVar4 != 0)) {

            if ((*(char *)(iVar4 + 0xc5) != '\0') || (*(char *)(iVar4 + 0xc6) != '\0')) {

              if (*(char *)(iVar4 + 0x1c9) == '\0') {

                local_30 = (float)DAT_00d1e818 * (float)local_50 * DAT_00aaa67c;

                local_2c = (float)DAT_00d1e81c * (float)local_4c * DAT_00aaa678;

                pfVar5 = &local_30;

              }

              else {

                local_38 = (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80) * (float)local_50 *

                           DAT_00aaa67c;

                local_34 = (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84) * (float)local_4c *

                           DAT_00aaa678;

                pfVar5 = &local_38;

              }

              piVar2 = *(int **)(param_1 + 0x1030 + (int)local_64 * 4);

              local_40 = *pfVar5;

              local_3c = pfVar5[1];

              iVar4 = *piVar2;

              if (*(char *)((int)piVar2 + 0x1ca) == '\0') {

                pfVar5 = (float *)(**(code **)(iVar4 + 0x134))(local_10);

                fStack_24 = (float)DAT_00d1e818 * *pfVar5 * DAT_00aaa67c;

                fStack_20 = (float)DAT_00d1e81c * pfVar5[1] * DAT_00aaa678;

                pfVar5 = &fStack_24;

              }

              else {

                pfVar5 = (float *)(**(code **)(iVar4 + 0x134))(local_18);

                local_2c = (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x80) * *pfVar5 *

                           DAT_00aaa67c;

                fStack_28 = (float)*(int *)(*(int *)(DAT_00d17944 + 0x2c) + 0x84) * pfVar5[1] *

                            DAT_00aaa678;

                pfVar5 = &local_2c;

              }

              local_64 = local_40 -

                         *(float *)(*(int *)(param_1 + 0x1030 + unaff_EBX * 4) + 0x260) * pfVar5[1];

              iStack_58 = (int)ROUND(local_64);

              fStack_60 = fStack_44 -

                          *(float *)(*(int *)(param_1 + 0x1030 + unaff_EBX * 4) + 0x25c) * *pfVar5;

              iStack_5c = (int)ROUND(fStack_60);

              local_4c = iStack_5c;

              iStack_48 = iStack_58;

              (**(code **)(**(int **)(param_1 + 0x1030 + unaff_EBX * 4) + 0x110))(&local_4c);

            }

          }

          else if (499 < (int)local_64) {

            if (local_64 == 7.00649e-43) {

              DAT_00af9214 = local_4c;

            }

            else {

              (&DAT_00af8a3c)[(int)local_64] = local_4c;

            }

          }

        }

        bVar1 = (byte)_File->_flag;

      }

      fclose(_File);

    }

    piVar2 = *(int **)(param_1 + 0x109c);

    if ((piVar2 != (int *)0x0) && (cVar3 = (**(code **)(*piVar2 + 0x3d8))(), cVar3 != '\0')) {

      FUN_008f7140();

      FUN_008f7040();

      FUN_008f6f60();

      FUN_008f6b70(piVar2);

    }

  }

  return;

}
