// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: return×6, switch×1.
//  - Notable callees: CONCAT13×3, CONCAT11×2, CONCAT21×2, CONCAT31×2, CONCAT12, FUN_0099b010, vog_LogMessage.
//  - Strings: ",

                   0x88,3,".
//  - Return sites: 6.

// =============================================================================
// Named_effSurfaceFormat
// -----------------------------------------------------------------------------
// Stable ID: aa_0099b010
// Address:   0x0099b010  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "effSurfaceFormat"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_effSurfaceFormat(ushort *param_1)



{

  ushort uVar1;

  int iVar2;

  byte bVar3;

  byte bVar4;

  uint32_t /* width from decompiler */ in_EAX;

  uint uVar5;

  uint uVar6;

  uint32_t /* width from decompiler */ *unaff_EDI;

  uint8_t local_4;

  uint8_t uStack_3;

  uint16_t uStack_2;

  

  switch(in_EAX) {

  case 0x15:

    *unaff_EDI = *(uint32_t /* width from decompiler */ *)param_1;

    return;

  case 0x16:

    _local_4 = CONCAT13(0xff,*(undefined3 *)param_1);

    *unaff_EDI = _local_4;

    return;

  case 0x17:

    uVar1 = *param_1;

    uVar5 = uVar1 >> 8 & 0xf8;

    uVar6 = uVar1 >> 3 & 0xfc;

    _local_4 = (uint3)(byte)((byte)((int)uVar5 >> 5) | (byte)uVar5) << 0x10;

    iVar2 = (uVar1 & 0x1f) * 8;

    _local_4 = CONCAT13(0xff,_local_4);

    _local_4 = CONCAT31(CONCAT21(uStack_2,(byte)((int)uVar6 >> 6) | (byte)uVar6),

                        (byte)(iVar2 >> 5) | (byte)iVar2);

    *unaff_EDI = _local_4;

    return;

  default:

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effSurfaceFormat.cpp",

                   0x88,3,"Unimplemented code reached");

    *unaff_EDI = 0;

    return;

  case 0x19:

    uVar1 = *param_1;

    uVar5 = uVar1 >> 7 & 0xf8;

    uVar6 = uVar1 >> 2 & 0xf8;

    iVar2 = (uVar1 & 0x1f) * 8;

    _local_4 = CONCAT31(CONCAT21(CONCAT11(-((uVar1 & 0x8000) != 0),

                                          (byte)((int)uVar5 >> 5) | (byte)uVar5),

                                 (byte)((int)uVar6 >> 5) | (byte)uVar6),

                        (byte)(iVar2 >> 5) | (byte)iVar2);

    *unaff_EDI = _local_4;

    return;

  case 0x1a:

    uVar5 = (byte)*param_1 & 0xf0;

    bVar3 = (byte)*param_1 & 0xf;

    uVar6 = *(byte *)((int)param_1 + 1) & 0xf0;

    bVar4 = *(byte *)((int)param_1 + 1) & 0xf;

    _local_4 = CONCAT12(bVar4 << 4 | bVar4,

                        CONCAT11((byte)((int)uVar5 >> 4) | (byte)uVar5,bVar3 << 4 | bVar3));

    _local_4 = CONCAT13((byte)((int)uVar6 >> 4) | (byte)uVar6,_local_4);

    *unaff_EDI = _local_4;

    return;

  }

}
