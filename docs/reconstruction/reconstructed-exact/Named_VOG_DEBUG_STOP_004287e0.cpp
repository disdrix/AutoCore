// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×7, return×5, for×1, do×1, goto×1, while×1.
//  - Notable callees: FUN_007a4480×3, FUN_00415ac0, FUN_00416ff0, FUN_004287e0, FUN_00429310.
//  - Strings: "HashError:insert, already locked for traversal"; "VOG_DEBUG_STOP"; "Duplicate hash insert %u, failing out".
//  - Return sites: 5.

// =============================================================================
// Named_VOG_DEBUG_STOP_004287e0
// -----------------------------------------------------------------------------
// Stable ID: aa_004287e0
// Address:   0x004287e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_VOG_DEBUG_STOP_004287e0(int param_1,int param_2,char param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint unaff_EBX;

  

  if (param_2 == 0) {

    return 0x80004003;

  }

  if (*(char *)(param_1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:insert, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  if ((param_3 != '\0') && (iVar1 = FUN_00415ac0(), iVar1 != 0)) {

    return 1;

  }

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + (*(uint *)(param_1 + 8) & unaff_EBX) * 4) + 4

                  );

  do {

    if (iVar1 == 0) {

LAB_00428851:

      puVar2 = (uint32_t /* width from decompiler */ *)FUN_00416ff0();

      puVar2[3] = 0;

      puVar2[5] = 0;

      puVar2[6] = 0;

      *(uint8_t *)(puVar2 + 1) = 0;

      *puVar2 = &PTR_FUN_00a993cc;

      puVar2[2] = param_2;

      puVar2[4] = unaff_EBX;

      iVar1 = *(int *)(*(int *)(param_1 + 0x10) + (*(uint *)(param_1 + 8) & unaff_EBX) * 4);

      puVar2[3] = *(uint32_t /* width from decompiler */ *)(iVar1 + 4);

      *(uint32_t /* width from decompiler */ **)(iVar1 + 4) = puVar2;

      FUN_00429310();

      if (*(int *)(param_1 + 0x18) == 0) {

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x18) = puVar2;

        *(uint32_t /* width from decompiler */ **)(param_1 + 0x14) = puVar2;

        puVar2[6] = 0;

        puVar2[5] = 0;

        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;

        return 0;

      }

      *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x18) + 0x14) = puVar2;

      puVar2[5] = 0;

      puVar2[6] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x18);

      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;

      *(uint32_t /* width from decompiler */ **)(param_1 + 0x18) = puVar2;

      return 0;

    }

    if (unaff_EBX == *(uint *)(iVar1 + 0x10)) {

      if ((iVar1 != 0) && (*(int *)(iVar1 + 8) != 0)) {

        FUN_007a4480(0,"Duplicate hash insert %u, failing out");

        return 0x80004005;

      }

      goto LAB_00428851;

    }

    iVar1 = *(int *)(iVar1 + 0xc);

  } while( true );

}
