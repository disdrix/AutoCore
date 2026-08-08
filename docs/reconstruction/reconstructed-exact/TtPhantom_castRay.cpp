// =============================================================================
// TtPhantom_castRay
// -----------------------------------------------------------------------------
// Stable ID: aa_00580ed0
// Address:   0x00580ed0 – 0x005810fd  (autoassault.exe, image base 0x400000)
// Size:      558 B / 0x22E
// System:    input-drive-control / physics
// Generated: 2026-08-05 MEGA-101 dual (live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher / runtime Confirmed).
// Plate:     "TtPhantom::castRay" @ 0x009d4574
// ABI:       __thiscall; ECX=this; stack ray*, result*; RET 8
// Ghidra:    FUN_00580ed0
// Retired:   Skill_TtPhantom_castRay; Named_CalleeOf_CVOGCreature_FindTerrainHeight_00580ed0
// =============================================================================

// PURPOSE:
// Cast a world-space ray against every collidable in this phantom's broadphase
// overlap list. Transform start/end into each body's local frame, invoke
// shape->vtbl[+0x20] (castRay) with a shared closest-hit result, stamp the
// hitting collidable at result+0x20, then rotate the hit normal body-local →
// world via FUN_005d6ae0.
//
// Primary consumers:
//   - FUN_0064bbd0  vehicle wheel suspension cast (framework packer)
//   - CVOGCreature_FindTerrainHeight  when creature+0x254 (phantom) non-null
// Sibling (NOT this): CVOGMap_CastTerrainHeight when no phantom body.

// Externals (unresolved types kept intentional)
extern int *DAT_00bc5644;
extern int *DAT_00bc5648;
extern int DAT_009d2878;
extern unsigned long long rdtsc(void);
extern void __thiscall FUN_005d6ae0(float *out_or_this, float *R_cols, float *v_result);

void __thiscall TtPhantom_castRay(int phantom, float *ray, int result)
{
  int *piVar1;
  int iVar2;
  unsigned long long uVar3;
  int *piVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int local_48;
  char local_44[4];
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  int local_1c;

  // Profiler entry — plate "TtPhantom::castRay"
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = (int)"TtPhantom::castRay";
    uVar3 = rdtsc();
    DAT_00bc5644[1] = (int)uVar3;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }

  local_20 = ray[9]; // loaded; unused in decompile (wheel may stash ptr @ ray+0x24)

  // Optional filter object prep (not forwarded to shape vcall in decompile)
  if ((*(char *)(ray + 8) == '\0') ||
      (local_1c = *(int *)(*(int *)(phantom + 8) + 0xd0), local_1c == 0)) {
    local_1c = 0;
  } else {
    local_1c = local_1c + 0x10;
  }

  local_48 = *(int *)(phantom + 0x84);       // overlap count
  piVar4 = *(int **)(phantom + 0x80);        // collidable** list
  if (-1 < local_48 + -1) {
    do {
      piVar1 = *(int **)*piVar4;             // shape* at collidable+0
      if (piVar1 != (int *)0x0) {
        iVar2 = ((int *)*piVar4)[2];         // body/transform @ collidable+8

        // world start - T, then R^T * d  → local_40/3c/38
        fVar6 = ray[1] - *(float *)(iVar2 + 0x54);
        fVar7 = ray[2] - *(float *)(iVar2 + 0x58);
        fVar5 = *ray - *(float *)(iVar2 + 0x50);
        local_40 = *(float *)(iVar2 + 0x28) * fVar7 + *(float *)(iVar2 + 0x24) * fVar6 +
                   *(float *)(iVar2 + 0x20) * fVar5;
        local_3c = *(float *)(iVar2 + 0x38) * fVar7 + *(float *)(iVar2 + 0x34) * fVar6 +
                   fVar5 * *(float *)(iVar2 + 0x30);
        local_38 = *(float *)(iVar2 + 0x48) * fVar7 + *(float *)(iVar2 + 0x44) * fVar6 +
                   fVar5 * *(float *)(iVar2 + 0x40);

        // world end - T, then R^T * d  → local_30/2c/28
        fVar7 = ray[6] - *(float *)(iVar2 + 0x58);
        fVar6 = ray[5] - *(float *)(iVar2 + 0x54);
        fVar5 = ray[4] - *(float *)(iVar2 + 0x50);
        local_30 = *(float *)(iVar2 + 0x28) * fVar7 + *(float *)(iVar2 + 0x24) * fVar6 +
                   *(float *)(iVar2 + 0x20) * fVar5;
        local_2c = *(float *)(iVar2 + 0x38) * fVar7 + *(float *)(iVar2 + 0x34) * fVar6 +
                   fVar5 * *(float *)(iVar2 + 0x30);
        local_28 = *(float *)(iVar2 + 0x48) * fVar7 + *(float *)(iVar2 + 0x44) * fVar6 +
                   fVar5 * *(float *)(iVar2 + 0x40);

        // shape->vtbl[+0x20](hitFlag, &localRay, result)
        (**(void (**)(char *, float *, int))(*piVar1 + 0x20))(local_44, &local_40, result);
        if (local_44[0] != '\0') {
          *(int *)(result + 0x20) = *piVar4; // stamp collidable*
        }
      }
      piVar4 = piVar4 + 1;
      local_48 = local_48 + -1;
    } while (local_48 != 0);
  }

  // Hit: rotate normal body-local → world (FUN_005d6ae0)
  if (*(int *)(result + 0x20) != 0) {
    FUN_005d6ae0(
        (float *)result,
        (float *)(*(int *)(*(int *)(result + 0x20) + 8) + 0x20),
        (float *)result);
  }

  // Profiler exit
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = (int)&DAT_009d2878;
    uVar3 = rdtsc();
    DAT_00bc5644[1] = (int)uVar3;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  return;
}
