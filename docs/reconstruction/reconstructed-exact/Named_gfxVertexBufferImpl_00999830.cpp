// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×10, for×4, return×3, do×1, while×1.
//  - Notable callees: vog_LogMessage×2, FUN_00414aa0, FUN_00746520, FUN_00999830.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp"; ",0xea,2,

                 ".
//  - Return sites: 3.

// =============================================================================
// Named_gfxVertexBufferImpl_00999830
// -----------------------------------------------------------------------------
// Stable ID: aa_00999830
// Address:   0x00999830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxVertexBufferImpl"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_gfxVertexBufferImpl_00999830(int param_1,int param_2,uint32_t /* width from decompiler */ *param_3)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  uint in_EAX;

  uint32_t /* width from decompiler */ *puVar5;

  uint uVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iVar9;

  uint32_t /* width from decompiler */ *puVar10;

  uint local_4;

  

  iVar2 = *(int *)(param_2 + 0x10);

  if (iVar2 == 0) {

    local_4 = 0;

  }

  else {

    local_4 = *(uint *)(iVar2 + 8);

  }

  if ((param_1 == 0) || (iVar9 = *(int *)(param_2 + 0x18), *(int *)(param_2 + 0x18) < param_1)) {

    param_1 = *(int *)(param_2 + 0x18);

    iVar9 = param_1;

  }

  if (in_EAX == 0) {

    in_EAX = local_4;

  }

  if (iVar2 != 0) {

    iVar7 = param_1;

    if (param_1 < 1) {

      iVar7 = iVar9;

    }

    puVar5 = (uint32_t /* width from decompiler */ *)

             FUN_00746520(*(uint32_t /* width from decompiler */ *)(param_2 + 0x14),iVar7,*(uint *)(iVar2 + 4) & 1);

    if (puVar5 != (uint32_t /* width from decompiler */ *)0x0) {

      if (in_EAX == local_4) {

        for (uVar6 = param_1 * in_EAX >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

          *puVar5 = *param_3;

          param_3 = param_3 + 1;

          puVar5 = puVar5 + 1;

        }

        for (uVar6 = param_1 * in_EAX & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

          *(uint8_t *)puVar5 = *(uint8_t *)param_3;

          param_3 = (uint32_t /* width from decompiler */ *)((int)param_3 + 1);

          puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

        }

      }

      else if (0 < param_1) {

        do {

          puVar8 = param_3;

          puVar10 = puVar5;

          for (uVar6 = in_EAX >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

            *puVar10 = *puVar8;

            puVar8 = puVar8 + 1;

            puVar10 = puVar10 + 1;

          }

          param_1 = param_1 + -1;

          for (uVar6 = in_EAX & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

            *(uint8_t *)puVar10 = *(uint8_t *)puVar8;

            puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

            puVar10 = (uint32_t /* width from decompiler */ *)((int)puVar10 + 1);

          }

          puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + local_4);

          param_3 = (uint32_t /* width from decompiler */ *)((int)param_3 + in_EAX);

        } while (param_1 != 0);

      }

      piVar3 = *(int **)(param_2 + 0x10);

      if ((piVar3 != (int *)0x0) && (piVar4 = (int *)*piVar3, piVar4 != (int *)0x0)) {

        piVar1 = piVar3 + 4;

        *piVar1 = *piVar1 + -1;

        if (*piVar1 < 0) {

          vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,1,

                         "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

          piVar3[4] = 0;

          return 0;

        }

        (**(code **)(*piVar4 + 0x30))(piVar4);

      }

      return 0;

    }

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxVertexBufferImpl.cpp",0xea,2,

                 "Was unable to lock the vertex buffer in gfxVertexBufferImpl::CopyFromPointer");

  FUN_00414aa0();

  return 0xffffffff;

}
