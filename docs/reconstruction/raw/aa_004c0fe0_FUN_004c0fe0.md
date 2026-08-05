# Raw capture: FUN_004c0fe0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c0fe0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004c0fe0` |
| **Canonical name** | `FUN_004c0fe0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_004c0fe0(int *param_1)

{
  void *pvVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  void **ppvVar5;
  int *piVar6;
  int iStack_74;
  void *pvStack_6c;
  undefined4 uStack_68;
  void *pvStack_64;
  void *local_60;
  int iStack_5c;
  int local_58;
  int local_54;
  undefined1 local_50 [8];
  undefined1 local_48 [8];
  undefined1 local_40 [8];
  undefined1 local_38 [8];
  float local_30;
  void *local_2c;
  float local_28;
  float local_24;
  undefined1 uStack_20;
  void *pvStack_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_009a1a6d;
  pvStack_1c = ExceptionList;
  local_58 = *(int *)(*(int *)(DAT_00d1f058 + 0x2c) + 0x80);
  local_54 = *(int *)(*(int *)(DAT_00d1f058 + 0x2c) + 0x84);
  ExceptionList = &pvStack_1c;
  local_60 = operator_new(0x18);
  local_14 = 0;
  if (local_60 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_009886d0();
  }
  local_14 = 0xffffffff;
  param_1[8] = iVar4;
  local_60 = operator_new(0x18);
  local_14 = 1;
  if (local_60 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_009886d0();
  }
  local_14 = 0xffffffff;
  param_1[10] = iVar4;
  local_60 = operator_new(0x18);
  local_14 = 2;
  if (local_60 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_009886d0();
  }
  local_14 = 0xffffffff;
  param_1[0xc] = iVar4;
  local_60 = operator_new(0x18);
  local_14 = 3;
  if (local_60 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_009886d0();
  }
  local_14 = 0xffffffff;
  param_1[0xe] = iVar4;
  FUN_0096f530();
  local_14 = 4;
  FUN_00989e00(&local_60,"UIFluidDownsample.fx");
  FUN_009701d0(&local_60);
  iVar4 = FUN_00988610(local_38);
  if (iVar4 < 0) {
    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGEnvironmentLiquid.cpp",0x1cb,3,
                   "failed to load filter effect.");
  }
  FUN_00970140("BackBufferTexture",*(undefined4 *)(*param_1 + 0x94));
  if (*(int *)(param_1[8] + 0xc) == 0) {
    local_60 = (void *)0xffffffff;
    ppvVar5 = &local_60;
  }
  else {
    ppvVar5 = (void **)FUN_00752310(&local_60,"UIMapExtents0");
  }
  pvVar1 = *ppvVar5;
  local_24 = g_flOne / (float)local_54;
  local_28 = g_flOne / (float)local_58;
  local_30 = g_flOne;
  local_2c = (void *)g_flOne;
  cVar3 = FUN_0096fdf0();
  uStack_68._3_1_ = cVar3;
  iVar4 = FUN_00752a00(pvVar1,&local_30);
  if ((iVar4 == -1) && (uStack_68._3_1_ != '\0')) {
    FUN_0096f5d0();
  }
  FUN_0096f530();
  local_14 = CONCAT31(local_14._1_3_,5);
  FUN_00989e00(&local_60,"UIFluidBlurHorizontal.fx");
  FUN_009701d0(&local_60);
  iVar4 = FUN_00988610(local_40);
  if (iVar4 < 0) {
    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGEnvironmentLiquid.cpp",0x1d9,3,
                   "failed to load filter effect.");
  }
  FUN_0096f530();
  local_14 = CONCAT31(local_14._1_3_,6);
  FUN_00989e00(&local_60,"UIFluidBlurVertical.fx");
  FUN_009701d0(&local_60);
  iVar4 = FUN_00988610(local_48);
  if (iVar4 < 0) {
    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGEnvironmentLiquid.cpp",0x1df,3,
                   "failed to load filter effect.");
  }
  FUN_0096f530();
  local_14 = CONCAT31(local_14._1_3_,7);
  FUN_00989e00(&local_60,"UIFluidSurfaceBlend.fx");
  FUN_009701d0(&local_60);
  iVar4 = FUN_00988610(local_50);
  if (iVar4 < 0) {
    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGEnvironmentLiquid.cpp",0x1e5,3,
                   "failed to load filter effect.");
  }
  *(undefined1 *)(param_1[0xe] + 0x15) = 0;
  local_60 = operator_new(0xd4);
  local_14._0_1_ = 8;
  if (local_60 == (void *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)FUN_009685e0();
  }
  param_1[0xf] = (int)piVar6;
  local_14 = CONCAT31(local_14._1_3_,7);
  (**(code **)(*piVar6 + 8))(&local_58);
  pvStack_64 = operator_new(0xd4);
  puStack_18._0_1_ = 9;
  if (pvStack_64 == (void *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)FUN_009685e0();
  }
  pvStack_64 = (void *)((int)(iStack_5c + (iStack_5c >> 0x1f & 3U)) >> 2);
  local_60 = (void *)((int)(local_58 + (local_58 >> 0x1f & 3U)) >> 2);
  param_1[9] = (int)piVar6;
  puStack_18 = (undefined1 *)CONCAT31(puStack_18._1_3_,7);
  (**(code **)(*piVar6 + 8))(&pvStack_64);
  uStack_68 = operator_new(0xd4);
  pvStack_1c._0_1_ = 10;
  if (uStack_68 == (void *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)FUN_009685e0();
  }
  uStack_68 = (void *)((int)((int)local_60 + ((int)local_60 >> 0x1f & 3U)) >> 2);
  pvStack_64 = (void *)((int)(iStack_5c + (iStack_5c >> 0x1f & 3U)) >> 2);
  param_1[0xb] = (int)piVar6;
  pvStack_1c = (void *)CONCAT31(pvStack_1c._1_3_,7);
  (**(code **)(*piVar6 + 8))(&uStack_68);
  pvStack_6c = operator_new(0xd4);
  uStack_20 = 0xb;
  if (pvStack_6c == (void *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)FUN_009685e0();
  }
  pvStack_6c = (void *)((int)((int)pvStack_64 + ((int)pvStack_64 >> 0x1f & 3U)) >> 2);
  uStack_68 = (void *)((int)((int)local_60 + ((int)local_60 >> 0x1f & 3U)) >> 2);
  param_1[0xd] = (int)piVar6;
  uStack_20 = 7;
  (**(code **)(*piVar6 + 8))(&pvStack_6c);
  FUN_0096ef70();
  local_24 = (float)CONCAT31(local_24._1_3_,0xc);
  iVar4 = FUN_0096f0e0(0x15,param_1[9] + 0x80,1,0x4011,0,0);
  if (iVar4 < 0) {
    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGEnvironmentLiquid.cpp",0x204,3,
                   "failed to create buffer texture for buffered window");
  }
  iVar4 = param_1[9];
  if (iStack_74 != 0) {
    *(int *)(iStack_74 + 8) = *(int *)(iStack_74 + 8) + 1;
    if (*(int *)(iStack_74 + 8) == 1) {
      (**(code **)(*(int *)(iStack_74 + 4) + 4))();
    }
  }
  iVar2 = *(int *)(iVar4 + 0xb8);
  if (iVar2 != 0) {
    piVar6 = (int *)(iVar2 + 8);
    *piVar6 = *piVar6 + -1;
    if (*piVar6 == 0) {
      (**(code **)(*(int *)(iVar2 + 4) + 8))();
    }
  }
  *(int *)(iVar4 + 0xb8) = iStack_74;
  *(undefined4 *)(param_1[9] + 0xc0) = 0;
  iVar4 = FUN_0096f0e0(0x15,param_1[0xb] + 0x80,1,0x4011,0,0);
  if (iVar4 < 0) {
    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGEnvironmentLiquid.cpp",0x20b,3,
                   "failed to create buffer texture for buffered window");
  }
  iVar4 = param_1[0xb];
  if (iStack_74 != 0) {
    *(int *)(iStack_74 + 8) = *(int *)(iStack_74 + 8) + 1;
    if (*(int *)(iStack_74 + 8) == 1) {
      (**(code **)(*(int *)(iStack_74 + 4) + 4))();
    }
  }
  iVar2 = *(int *)(iVar4 + 0xb8);
  if (iVar2 != 0) {
    piVar6 = (int *)(iVar2 + 8);
    *piVar6 = *piVar6 + -1;
    if (*piVar6 == 0) {
      (**(code **)(*(int *)(iVar2 + 4) + 8))();
    }
  }
  *(int *)(iVar4 + 0xb8) = iStack_74;
  *(undefined4 *)(param_1[0xb] + 0xc0) = 0;
  iVar4 = FUN_0096f0e0(0x15,param_1[0xd] + 0x80,1,0x4011,0,0);
  if (iVar4 < 0) {
    vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGEnvironmentLiquid.cpp",0x212,3,
                   "failed to create buffer texture for buffered window");
  }
  iVar4 = param_1[0xd];
  if (iStack_74 != 0) {
    *(int *)(iStack_74 + 8) = *(int *)(iStack_74 + 8) + 1;
    if (*(int *)(iStack_74 + 8) == 1) {
      (**(code **)(*(int *)(iStack_74 + 4) + 4))();
    }
  }
  iVar2 = *(int *)(iVar4 + 0xb8);
  if (iVar2 != 0) {
    piVar6 = (int *)(iVar2 + 8);
    *piVar6 = *piVar6 + -1;
    if (*piVar6 == 0) {
      (**(code **)(*(int *)(iVar2 + 4) + 8))();
    }
  }
  *(int *)(iVar4 + 0xb8) = iStack_74;
  *(undefined4 *)(param_1[0xd] + 0xc0) = 0;
  iVar4 = *param_1;
  *(int *)(iVar4 + 0x98) = iStack_74;
  if (*(int *)(iVar4 + 0x8c) != 0) {
    FUN_00970140("NormalMapTexture",iStack_74);
  }
  FUN_007567b0(param_1[8],0);
  FUN_009888b0(param_1[9],0);
  FUN_007567b0(param_1[10],0);
  FUN_009888b0(param_1[0xb],0);
  FUN_007567b0(param_1[0xc],0);
  FUN_009888b0(param_1[0xd],1);
  *(undefined1 *)(param_1[0xe] + 0x14) = 1;
  local_24._0_1_ = 7;
  FUN_0096efd0();
  local_24._0_1_ = 6;
  FUN_0096f510();
  local_24._0_1_ = 5;
  FUN_0096f510();
  local_24 = (float)CONCAT31(local_24._1_3_,4);
  FUN_0096f510();
  local_24 = -NAN;
  FUN_0096f510();
  ExceptionList = local_2c;
  return 0;
}
```

---

## W37-F re-verify append (2026-08-04)

| Field | Value |
|---|---|
| **Wave** | W37-F OWN-ONLY dual |
| **Tools** | `batch_decompile` / `decompile_function` / `analyze_function_complete` / `get_function_by_address` / `read_memory` / callers/callees — **no** `disassemble_bytes` |
| **Body** | `0x004c0fe0`–`0x004c16cf` inclusive (**1776 B** / `0x6F0`); next `0x004c16d0` |
| **Live decompile** | ≡ scaffold raw CF (2026-07-23); return **0** |

### Prologue / epilogue seals (`read_memory`)

**Prologue (entry):**
```
55 8B EC 83 E4 F0          ; push ebp; mov ebp,esp; and esp,-16
6A FF 68 6D 1A 9A 00       ; SEH push; handler LAB_009a1a6d
64 A1 00 00 00 00 50       ; ExceptionList
64 89 25 00 00 00 00
83 EC 58                   ; locals
A1 58 F0 D1 00             ; DAT_00d1f058
8B 40 2C                   ; +0x2c device/context
53 56 8B F1                ; push ebx/esi; **mov esi, ecx**  ← thiscall liquid child
... load [eax+0x80]/[eax+0x84] dims into stack
```

**Epilogue (tail @ ~0x004c16c0):**
```
5F 5E 33 C0                ; pop edi/esi; **xor eax,eax** return 0
64 89 0D 00 00 00 00       ; restore ExceptionList
5B 8B E5 5D C3             ; pop ebx; mov esp,ebp; pop ebp; ret
```

### Slot map on liquid child (`param_1` / ESI) — dword index → byte offset

| Index | Off | Alloc / role |
|---|---|---|
| `[0]` | `+0x00` | parent phase* (ctor `FUN_004c1800`) |
| `[8]` | `+0x20` | `new(0x18)+FUN_009886d0` — filter host 0 (Downsample) |
| `[9]` | `+0x24` | `new(0xd4)+FUN_009685e0` — RT host quarter cascade |
| `[10]` | `+0x28` | filter host 1 (BlurHorizontal) |
| `[11]` | `+0x2c` | RT host next quarter |
| `[12]` | `+0x30` | filter host 2 (BlurVertical) |
| `[13]` | `+0x34` | RT host next quarter |
| `[14]` | `+0x38` | filter host 3 (SurfaceBlend); flags `+0x14`/`+0x15` |
| `[15]` | `+0x3c` | `new(0xd4)+FUN_009685e0` — full-dim RT; vcall `vtbl+8` with device dims |

Bytes seal stores: `89 46 20` / `28` / `30` / `38` after each 0x18 ctor path.

### Product strings (body)

| String | Role |
|---|---|
| `UIFluidDownsample.fx` | first filter effect |
| `UIFluidBlurHorizontal.fx` | second |
| `UIFluidBlurVertical.fx` | third |
| `UIFluidSurfaceBlend.fx` | fourth |
| `BackBufferTexture` | param bind from `*parent+0x94` |
| `UIMapExtents0` | map extents param (via `FUN_00752310`) |
| `NormalMapTexture` | optional bind if parent `+0x8c` |
| `VOGEnvironmentLiquid.cpp` | source path in all `vog_LogMessage` fails |
| `failed to load filter effect.` | lines `0x1cb`, `0x1d9`, `0x1df`, `0x1e5` |
| `failed to create buffer texture for buffered window` | lines `0x204`, `0x20b`, `0x212` |

### Algorithm (sealed stages)

1. Read device dims from `*(DAT_00d1f058+0x2c)+0x80/0x84`.
2. Four× `new(0x18)+FUN_009886d0` → child `+0x20/+0x28/+0x30/+0x38`.
3. Load four UIFluid*.fx via `FUN_0096f530` / `FUN_00989e00` / `FUN_009701d0` / `FUN_00988610`; log on `<0`.
4. Bind `BackBufferTexture`; set `UIMapExtents0` to `(1,1, 1/w, 1/h)` (g_flOne ratios).
5. Four× `new(0xd4)+FUN_009685e0` RT hosts: full dims @ `[0xf]`; then cascaded `>>2` dims @ `[9]`, `[0xb]`, `[0xd]` with vcall `(*obj)(+8)`.
6. `FUN_0096f0e0(0x15, rt+0x80, 1, 0x4011, 0, 0)` ×3 for cascade RTs; refcount wire to `rt+0xb8`, clear `+0xc0`.
7. `*parent+0x98 = last tex`; optional `NormalMapTexture`.
8. Pair setup: `FUN_007567b0` filters + `FUN_009888b0` RTs; set blend filter `+0x14=1`.
9. Destroy local effect wrappers (`FUN_0096efd0` / `FUN_0096f510`×4); return **0**.

### Callers / callees (live)

| Direction | Count / note |
|---|---|
| Callers | **1** — `FUN_004c1960` (`ParticleFluidPhase_CreateLiquidChild_Inferred`, W34-O) @ `0x004c19ae` |
| Callees | `operator_new`, `FUN_009886d0`, `FUN_009685e0`, FX load/bind helpers, `FUN_0096f0e0`, `FUN_007567b0`, `FUN_009888b0`, `FUN_00752310`, `FUN_00752a00`, `vog_LogMessage`, … |

### ABI

- **ECX = liquid child*** (`0x40` object from W34-O); **`8B F1`**.
- No stack formals; bare **RET**; returns **0**.
- SEH `LAB_009a1a6d`.

### Name

`VOGEnvironmentLiquid_InitFilterPipeline_Inferred` — product path `VOGEnvironmentLiquid.cpp` + UIFluid*.fx. Reject bare scaffold-only plate without pipeline semantics. Nested helpers remain free/unowned.
