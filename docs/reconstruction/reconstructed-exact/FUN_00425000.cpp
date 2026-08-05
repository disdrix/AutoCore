// =============================================================================
// FUN_00425000
// -----------------------------------------------------------------------------
// Stable ID: aa_00425000
// Address:   0x00425000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00425000 @ 0x00425000
// Stable ID: aa_00425000
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, return×2, goto×2, while×2.
//  - Notable callees: FUN_00425000, __RTDynamicCast.
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

int FUN_00425000(byte *param_1)



{

  byte bVar1;

  uint32_t /* width from decompiler */ *puVar2;

  byte *pbVar3;

  int iVar4;

  int *piVar5;

  byte *pbVar6;

  bool bVar7;

  

  puVar2 = DAT_00d1795c;

  do {

    if (puVar2 == (uint32_t /* width from decompiler */ *)0x0) {

      return 0;

    }

    if (*(char *)(puVar2 + 2) != '\0') {

      pbVar6 = *(byte **)(puVar2[1] + 0x20);

      pbVar3 = param_1;

      do {

        bVar1 = *pbVar3;

        bVar7 = bVar1 < *pbVar6;

        if (bVar1 != *pbVar6) {

LAB_00425044:

          iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);

          goto LAB_00425049;

        }

        if (bVar1 == 0) break;

        bVar1 = pbVar3[1];

        bVar7 = bVar1 < pbVar6[1];

        if (bVar1 != pbVar6[1]) goto LAB_00425044;

        pbVar3 = pbVar3 + 2;

        pbVar6 = pbVar6 + 2;

      } while (bVar1 != 0);

      iVar4 = 0;

LAB_00425049:

      if (iVar4 == 0) {

        piVar5 = (int *)(**(code **)(*(int *)puVar2[1] + 4))();

        iVar4 = __RTDynamicCast(piVar5,0,&TNL::Object::RTTI_Type_Descriptor,

                                &TNL::NetConnection::RTTI_Type_Descriptor,0);

        if ((iVar4 == 0) && (piVar5 != (int *)0x0)) {

          (**(code **)(*piVar5 + 4))(1);

        }

        return iVar4;

      }

    }

    puVar2 = (uint32_t /* width from decompiler */ *)*puVar2;

  } while( true );

}
