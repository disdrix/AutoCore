// =============================================================================
// FUN_0080ce90
// -----------------------------------------------------------------------------
// Stable ID: aa_0080ce90
// Address:   0x0080ce90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080ce90 @ 0x0080ce90
// Stable ID: aa_0080ce90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×7, return×2.
//  - Notable callees: Object_ResolveFromTFID×2, __RTDynamicCast×2, FUN_007fca10, FUN_0080ce90, FUN_0088f790.
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

void __fastcall FUN_0080ce90(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  char cVar2;

  int in_EAX;

  void *pvVar3;

  int iVar4;

  TFID_16 *pTfid;

  uint32_t /* width from decompiler */ uVar5;

  TypeDescriptor *pTVar6;

  TypeDescriptor *pTVar7;

  uint32_t /* width from decompiler */ uVar8;

  

  uVar8 = 0;

  pTVar7 = &CVOGStore::RTTI_Type_Descriptor;

  pTVar6 = &CVOGClonedObjectBase::RTTI_Type_Descriptor;

  uVar5 = 0;

  if (*(char *)(in_EAX + 4) == '\0') {

    pvVar3 = Object_ResolveFromTFID((TFID_16 *)(in_EAX + 8));

    iVar4 = __RTDynamicCast(pvVar3,uVar5,pTVar6,pTVar7,uVar8);

    if (iVar4 != 0) {

      FUN_007fca10();

    }

  }

  else {

    pTfid = (TFID_16 *)(in_EAX + 8);

    pvVar3 = Object_ResolveFromTFID(pTfid);

    iVar4 = __RTDynamicCast(pvVar3,uVar5,pTVar6,pTVar7,uVar8);

    if (iVar4 != 0) {

      if (*(char *)(iVar4 + 0x4e5) == '\0') {

        cVar2 = (**(code **)(*DAT_00d1b89c + 0x3d8))();

        if (cVar2 != '\0') {

          iVar4 = *(int *)(param_1 + 0x105c);

          uVar5 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc);

          uVar8 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10);

          uVar1 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x14);

          *(uint *)(iVar4 + 0x528) = pTfid->dwCoidLo;

          *(uint32_t /* width from decompiler */ *)(iVar4 + 0x52c) = uVar5;

          *(uint32_t /* width from decompiler */ *)(iVar4 + 0x530) = uVar8;

          *(uint32_t /* width from decompiler */ *)(iVar4 + 0x534) = uVar1;

          FUN_0088f790();

        }

      }

      else {

        cVar2 = (**(code **)(*DAT_00d1b8a0 + 0x3d8))();

        if (cVar2 != '\0') {

          iVar4 = *(int *)(param_1 + 0x1060);

          uVar5 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc);

          uVar8 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x10);

          uVar1 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x14);

          *(uint *)(iVar4 + 0x548) = pTfid->dwCoidLo;

          *(uint32_t /* width from decompiler */ *)(iVar4 + 0x54c) = uVar5;

          *(uint32_t /* width from decompiler */ *)(iVar4 + 0x550) = uVar8;

          *(uint32_t /* width from decompiler */ *)(iVar4 + 0x554) = uVar1;

          (**(code **)(**(int **)(param_1 + 0x1060) + 0x448))();

        }

      }

      if (*(int *)(param_1 + 0xf38) != 0) {

        (**(code **)(**(int **)(param_1 + 0xf38) + 0x3c4))(1);

        return;

      }

    }

  }

  return;

}
