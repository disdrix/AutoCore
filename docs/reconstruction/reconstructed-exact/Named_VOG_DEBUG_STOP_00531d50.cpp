// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, goto×2, do×1, while×1, for×1.
//  - Notable callees: FUN_007a4480×3, CNDHash_LookupByKey×2, FUN_00531d50, FUN_00537d30, FUN_0053ada0.
//  - Strings: "HashError:insert, already locked for traversal"; "VOG_DEBUG_STOP"; "Duplicate hash insert %u, failing out".
//  - Return sites: 3.

// =============================================================================
// Named_VOG_DEBUG_STOP_00531d50
// -----------------------------------------------------------------------------
// Stable ID: aa_00531d50
// Address:   0x00531d50  (autoassault.exe, image base 0x400000)
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

void __thiscall Named_VOG_DEBUG_STOP_00531d50(int param_1,uint param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  void *this;

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  

  iVar3 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1) + 0xe5c4);

  iVar3 = *(int *)(*(int *)(*(int *)(iVar3 + 0x10) + (*(uint *)(iVar3 + 8) & param_2) * 4) + 4);

  if (iVar3 == 0) {

LAB_00531d94:

    iVar3 = 0;

  }

  else {

    do {

      if (param_2 == *(uint *)(iVar3 + 0x10)) {

        if (iVar3 == 0) goto LAB_00531d94;

        iVar3 = *(int *)(iVar3 + 8);

        goto LAB_00531d9b;

      }

      iVar3 = *(int *)(iVar3 + 0xc);

    } while (iVar3 != 0);

    iVar3 = 0;

  }

LAB_00531d9b:

  if (iVar3 != 0) {

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x20) = param_3;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x24) = param_4;

    this = *(void **)(param_1 + 0x6f0);

    if (*(char *)((int)this + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:insert, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    pvVar1 = CNDHash_LookupByKey(this,param_2);

    if (pvVar1 == (void *)0x0) {

      pvVar1 = CNDHash_LookupByKey(this,param_2);

      if (pvVar1 != (void *)0x0) {

        FUN_007a4480(0,"Duplicate hash insert %u, failing out",param_2);

        return;

      }

      puVar2 = (uint32_t /* width from decompiler */ *)FUN_0053ada0();

      puVar2[3] = 0;

      puVar2[5] = 0;

      puVar2[6] = 0;

      *(uint8_t *)(puVar2 + 1) = 0;

      *puVar2 = &PTR_LAB_009cefdc;

      puVar2[2] = iVar3;

      puVar2[4] = param_2;

      iVar3 = *(int *)(*(int *)((int)this + 0x10) + (*(uint *)((int)this + 8) & param_2) * 4);

      puVar2[3] = *(uint32_t /* width from decompiler */ *)(iVar3 + 4);

      *(uint32_t /* width from decompiler */ **)(iVar3 + 4) = puVar2;

      FUN_00537d30();

      if (*(int *)((int)this + 0x18) != 0) {

        *(uint32_t /* width from decompiler */ **)(*(int *)((int)this + 0x18) + 0x14) = puVar2;

        puVar2[5] = 0;

        puVar2[6] = *(uint32_t /* width from decompiler */ *)((int)this + 0x18);

        *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;

        *(uint32_t /* width from decompiler */ **)((int)this + 0x18) = puVar2;

        return;

      }

      *(uint32_t /* width from decompiler */ **)((int)this + 0x18) = puVar2;

      *(uint32_t /* width from decompiler */ **)((int)this + 0x14) = puVar2;

      puVar2[6] = 0;

      puVar2[5] = 0;

      *(int *)((int)this + 0xc) = *(int *)((int)this + 0xc) + 1;

    }

  }

  return;

}
