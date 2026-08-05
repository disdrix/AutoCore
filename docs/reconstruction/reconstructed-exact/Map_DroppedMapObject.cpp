// =============================================================================
// Map_DroppedMapObject
// -----------------------------------------------------------------------------
// Stable ID: aa_004cd3c0
// Address:   0x004cd3c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Map_DroppedMapObject @ 0x004cd3c0
// Stable ID: aa_004cd3c0
// Embedded strings (evidence for future rename):
//   - "Dropped map object of COID:%I64i CBID:%I32i bytes:%li pVOGO:0x%08x hr:0x%08x pModPlace:0x%"
//   - "Seek error, seeking %li bytes from current"
//   - "Hit a really bad object with an invalid COID:%I64i CBID:%I32i or bytes:%li pVOGO:0x%08x hr"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_007a4480×3, Map_DroppedMapObject.
//  - Strings: "Seek error, seeking %li bytes from current".
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Dropped map object of COID:%I64i CBID:%I32i bytes:%li pVOGO:0x%08x hr:0x%08x pModPlace:0x%"
 * Domain alias of FUN_004cd3c0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall

Map_DroppedMapObject(int param_1,int *param_2,int *param_3,uint32_t /* width from decompiler */ *param_4,int param_5,

            uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8)



{

  int iVar1;

  

  *(uint8_t *)(param_1 + 0x7f) = 1;

  iVar1 = param_4[1];

  if (((-1 < iVar1) && (-1 < *param_3)) && (0 < param_5)) {

    FUN_007a4480(1,

                 "Dropped map object of COID:%I64i CBID:%I32i bytes:%li pVOGO:0x%08x hr:0x%08x pModPlace:0x%08x"

                 ,*param_4,iVar1,*param_3,param_5,param_6,param_7,param_8);

    iVar1 = (**(code **)(*param_2 + 4))(param_5,1);

    if (iVar1 != -1) {

      return 1;

    }

    FUN_007a4480(1,"Seek error, seeking %li bytes from current",param_5);

    return 0;

  }

  FUN_007a4480(1,

               "Hit a really bad object with an invalid COID:%I64i CBID:%I32i or bytes:%li pVOGO:0x%08x hr:0x%08x"

               ,*param_4,iVar1,*param_3,param_5,param_6,param_7);

  return 0;

}
