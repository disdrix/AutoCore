// =============================================================================
// Named_CalleeOf_Named_Starting_ShutDown_on_Client_0092cfd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0092cfd0
// Callee of Named_Starting_ShutDown_on_Client
// Address:   0x0092cfd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Starting_ShutDown_on_Client: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×11, goto×5, switch×3, do×2, while×2, return×1.
//  - Notable callees: FUN_0092cfd0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_Starting_ShutDown_on_Client
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

void Named_CalleeOf_Named_Starting_ShutDown_on_Client_0092cfd0(int param_1,ushort param_2,byte param_3)



{

  int iVar1;

  char *pcVar2;

  int iVar3;

  uint uVar4;

  bool bVar5;

  

  if ((0xeff < param_2) && (param_2 < 0xf08)) {

    uVar4 = 0;

    do {

      switch(uVar4) {

      case 0:

        iVar3 = 5;

        break;

      case 1:

        iVar3 = 6;

        break;

      case 2:

        iVar3 = 0x78;

        break;

      case 3:

        iVar3 = 0x14;

        break;

      default:

        iVar3 = 0;

        if (uVar4 < 4) break;

        iVar1 = 0;

        goto LAB_0092d057;

      }

                    /* WARNING: Could not find normalized switch variable to match jumptable */

      switch(uVar4) {

      case 0:

        iVar1 = param_1 + 0x1172;

        break;

      case 1:

        iVar1 = param_1 + 0x1276;

        break;

      case 2:

        iVar1 = param_1 + 0x13ae;

        break;

      default:

        iVar1 = param_1 + 0x2c0e;

      }

LAB_0092d057:

      if (iVar3 != 0) {

        pcVar2 = (char *)(iVar1 + 0x32);

        do {

          if (*(ushort *)(pcVar2 + -0x32) == param_2) {

            bVar5 = (-(pcVar2[-4] != '\0') & param_3 & 0x80) != 0;

            pcVar2[-1] = bVar5;

            if (((*pcVar2 == '\0') && (!bVar5)) || (pcVar2[-0x2e] != '\0')) {

              if (((*pcVar2 != '\0') || (bVar5)) || (pcVar2[-0x2e] == '\0')) goto LAB_0092d0ad;

              pcVar2[-0x2e] = '\0';

            }

            else {

              pcVar2[-0x2e] = '\x01';

            }

            pcVar2[-0x2d] = '\x01';

          }

LAB_0092d0ad:

          if (*(ushort *)(pcVar2 + -0x30) == param_2) {

            bVar5 = (-(pcVar2[-3] != '\0') & param_3 & 0x80) != 0;

            *pcVar2 = bVar5;

            if ((bVar5) || (pcVar2[-1] != '\0')) {

              if (pcVar2[-0x2e] != '\0') {

                if ((bVar5) || (pcVar2[-1] != '\0')) goto LAB_0092d0f5;

                goto LAB_0092d0e9;

              }

              pcVar2[-0x2e] = '\x01';

            }

            else {

LAB_0092d0e9:

              if (pcVar2[-0x2e] == '\0') goto LAB_0092d0f5;

              pcVar2[-0x2e] = '\0';

            }

            pcVar2[-0x2d] = '\x01';

          }

LAB_0092d0f5:

          pcVar2 = pcVar2 + 0x34;

          iVar3 = iVar3 + -1;

        } while (iVar3 != 0);

      }

      uVar4 = uVar4 + 1;

    } while ((int)uVar4 < 4);

  }

  return;

}
