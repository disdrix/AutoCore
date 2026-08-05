# Raw capture: FUN_004c1cb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c1cb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c1cb0` |
| **Canonical name** | `FUN_004c1cb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004c1cb0(int param_1,int param_2)

{
  uint *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  void *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a1b4a;
  local_c = ExceptionList;
  iVar4 = param_2 * 4;
  ExceptionList = &local_c;
  *(int *)(param_1 + 0xbc) = param_2;
  *(int *)(param_1 + 0xb8) = iVar4;
  if (iVar4 == 0) {
    FUN_007a4480(1,"Invalid arg to CreateFluidParticles %u",0);
    ExceptionList = local_c;
    return;
  }
  pvVar2 = operator_new__(param_2 * 0x70);
  local_4 = 0;
  local_40 = pvVar2;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    FUN_00404d80(pvVar2,0x1c,iVar4,FUN_005edf20);
  }
  local_4 = 0xffffffff;
  *(void **)(param_1 + 0xb4) = pvVar2;
  local_40 = operator_new(0x14c);
  local_4 = 1;
  if (local_40 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00764030();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0xac) = uVar3;
  FUN_007638d0(1);
  local_3c = DAT_00a1401c;
  local_38 = DAT_00a1401c;
  local_34 = DAT_00a1401c;
  puVar7 = &local_3c;
  puVar6 = &local_30;
  local_30 = DAT_00aaab38;
  local_2c = DAT_00aaab38;
  local_28 = DAT_00aaab38;
  (**(code **)(**(int **)(param_1 + 0xac) + 0x4c))(puVar6,puVar7);
  FUN_0074b8f0(puVar6,puVar7);
  local_40 = operator_new(0xc4);
  local_4 = 2;
  if (local_40 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00748960();
  }
  *(undefined4 *)(param_1 + 0xb0) = uVar3;
  local_4 = 0xffffffff;
  FUN_00989e00(&local_40,"NDParticleFluid.fx");
  FUN_009701d0(&local_40);
  FUN_0096ef70();
  local_4 = 3;
  FUN_00989e00(&local_40,"Particles.dds");
  FUN_0096f3e0(&local_40,0);
  FUN_00970140("ParticleTexture",param_2);
  if (*(int *)(param_1 + 0x94) != 0) {
    FUN_00970140("NormalMapTexture",*(int *)(param_1 + 0x94));
  }
  if (((*(int *)(param_1 + 0xa8) != 0) && (*(int *)(*(int *)(param_1 + 0xa8) + 0xc4) != 0)) &&
     (iVar4 = FUN_005b3400(), iVar4 != 0)) {
    uVar3 = FUN_005b3400();
    FUN_00970140("ReflectionSurface",uVar3);
  }
  FUN_004148e0(param_1 + 0x8c);
  puVar1 = (uint *)(*(int *)(param_1 + 0xb0) + 0xbc);
  *puVar1 = *puVar1 | 1;
  pvStack_20 = (void *)0x0;
  uStack_1c = 0;
  uStack_18 = 0;
  local_4._0_1_ = 4;
  uStack_14 = 0;
  uStack_10 = 0;
  FUN_007478c0(0x1c2);
  local_4._0_1_ = 5;
  iVar4 = FUN_00414c20(*(undefined4 *)(param_1 + 0xb8),auStack_24,3,0);
  local_4 = CONCAT31(local_4._1_3_,3);
  uStack_14 = 0;
  uStack_10 = 0;
  if (pvStack_20 == (void *)0x0) {
    pvStack_20 = (void *)0x0;
    uStack_1c = 0;
    uStack_18 = 0;
    if (iVar4 < 0) {
      FUN_007a4480(1,"Unable to allocated %u verts for fluid particles",
                   *(undefined4 *)(param_1 + 0xbc));
    }
    else {
      iVar4 = *(int *)(param_1 + 0xb0);
      iVar5 = FUN_0044b9c0(*(int *)(param_1 + 0xbc) * 6,2,0,0);
      if (iVar5 < 0) {
        FUN_007a4480(1,"Unable to allocated %u indices for fluid particles",
                     *(int *)(param_1 + 0xbc) * 6);
      }
      else {
        iVar5 = *(int *)(iVar4 + 0xc);
        if ((*(int *)(iVar5 + 0x10) == 0) ||
           (iVar5 = FUN_00743be0(*(undefined4 *)(iVar5 + 0x18),*(undefined4 *)(iVar5 + 0x1c),0x800),
           iVar5 == 0)) {
          FUN_007a4480(1,"Unable to lock %u indices for fluid particles",
                       *(int *)(param_1 + 0xbc) * 6);
        }
        else {
          FUN_004c05d0(iVar5);
          if (*(int *)(*(int *)(iVar4 + 0xc) + 0x10) != 0) {
            FUN_00743ba0();
          }
          *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0xa8) = 0;
          *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0xac) = 5;
          puVar1 = (uint *)(*(int *)(param_1 + 0xb0) + 0xbc);
          *puVar1 = *puVar1 & 0xfffffffe;
          FUN_007647c0(*(undefined4 *)(param_1 + 0xb0));
        }
      }
    }
    local_4 = 0xffffffff;
    FUN_0096efd0();
    ExceptionList = local_c;
    return;
  }
                    /* WARNING: Subroutine does not return */
  operator_delete(pvStack_20);
}
```

---

## Re-verify W34-N (2026-07-29)

| Field | Value |
|---|---|
| **Tool** | Ghidra `batch_decompile` / `analyze_function_complete` / `get_function_by_address` / `read_memory`. **No** `disassemble_bytes`. |
| **Live decompile** | = 2026-07-23 raw CF (capacity gates ? particle array ? view/mesh children ? FX/textures ? VB/IB fill) |
| **Body** | `0x004c1cb0`–`0x004c207c` exclusive (**972 B** / `0x3CC`). Final `C2 04 00` (`RET 4`); pad `CC`. Ghidra body ends `004c207b` (last byte of RET 4). SEH `LAB_009a1b4a`. |
| **ABI** | **`__thiscall`**; ECX=`phase*` (`mov esi,ecx`); stack formal **capacity** (`param_2`, loaded from `[esp+0x10]` after SEH); **void**; **`RET 4`**. |
| **Semantics** | Product **CreateFluidParticles(capacity)** on ParticleFluidPhase host: store `phase+0xbc = capacity`, `phase+0xb8 = capacity*4`; reject capacity*4==0 with log `Invalid arg to CreateFluidParticles %u`; `operator_new[](capacity*0x70)` + `FUN_00404d80(..., 0x1c, capacity*4, FUN_005edf20)` ? `+0xb4`; `new(0x14c)+FUN_00764030` ? `+0xac` with color triple setup; `new(0xc4)+FUN_00748960` ? `+0xb0`; load `NDParticleFluid.fx` + `Particles.dds`; set `ParticleTexture` (capacity), optional `NormalMapTexture` from `phase+0x94` (filled by fluid-bump child), optional `ReflectionSurface` via `FUN_005b3400`; build VB (`capacity*4` verts) + IB (`capacity*6` indices) with fill `FUN_004c05d0`; mesh flags `+0xa8=0`, `+0xac=5`, clear busy bit, `FUN_007647c0`. |
| **Callers** | 1: `FUN_004c2080` (`ParticleFluidPhase_Init_Inferred`, W33-S) @ `0x004c209b` — always `push 0x7fff` (32767). |
| **Callees (high-signal)** | `operator_new` / `operator_new[]` / `operator_delete`, `FUN_00404d80`, `FUN_00764030`, `FUN_007638d0`, `FUN_0074b8f0`, `FUN_00748960`, `FUN_00989e00`, `FUN_009701d0`, `FUN_0096ef70`, `FUN_0096f3e0`, `FUN_00970140`, `FUN_005b3400`, `FUN_004148e0`, `FUN_007478c0`, `FUN_00414c20`, `FUN_0044b9c0`, `FUN_00743be0`, `FUN_004c05d0`, `FUN_00743ba0`, `FUN_007647c0`, `FUN_007a4480`, `FUN_0096efd0` |
| **Classification** | worker |
| **Named** | `ParticleFluidPhase_CreateFluidParticles_Inferred` |
| **Aliases** | registry `Gfx_NDParticleFluid` (FX string); product log stem **CreateFluidParticles** |
| **Reject** | scaffold `Named_CalleeOf_*_Drive_NDRiver_fx_004c1cb0` |
| **Prologue hex (80 B)** | `64a1000000006aff684a1b9a00508b4424106489250000000083ec345556578d3c85000000008bf133ed3bfd8986bc00000089beb8000000772c81ffffff00007324576890b89c006a01e881272e0083` |
| **Epilogue hex** | `...83c440c20400` + `CC` pad |
| **Note** | Early path has `cmp edi,0` / `ja good` plus redundant `cmp edi,0xffff` / `jae good`; only **zero** capacity*4 rejects (decompiler correctly shows `if (iVar4==0)`). Factory capacity **0x7FFF** ? `*4 = 0x1FFFC` accepted. Dead `operator_delete` tail is MSVC EH residual when stack holder non-null. |
