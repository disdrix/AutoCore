# Raw capture: FUN_0075ceb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075ceb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0075ceb0` |
| **Canonical name** | `FUN_0075ceb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __fastcall FUN_0075ceb0(undefined4 *param_1)

{
  float fVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  FILE *_File;
  int iVar6;
  undefined4 extraout_EDX;
  undefined4 *puVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined1 local_2c [4];
  undefined4 *local_28;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  fVar1 = g_flOne;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b25d7;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_FUN_00a9edc8;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = fVar1;
  local_28 = param_1;
  pvVar3 = _aligned_malloc(0xc0,0x10);
  uVar5 = 0;
  if (pvVar3 != (void *)0x0) {
    FUN_00972cc0();
    uVar5 = extraout_EDX;
  }
  param_1[2] = uVar5;
  local_4 = 0;
  FUN_0073f590(param_1 + 4);
  param_1[0x11] = 0;
  local_4._0_1_ = 2;
  *(undefined1 *)(param_1 + 0x12) = 1;
  *(undefined1 *)((int)param_1 + 0x49) = 1;
  param_1[0x13] = 0xffffffff;
  puVar4 = (undefined4 *)FUN_0043f780();
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar7 = &DAT_00afdf70;
    puVar8 = puVar4;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
  }
  param_1[0x14] = puVar4;
  puVar4 = (undefined4 *)FUN_0043f780();
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar7 = &DAT_00afdf70;
    puVar8 = puVar4;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
  }
  param_1[0x15] = puVar4;
  param_1[0x16] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  *(undefined1 *)(param_1 + 0x33) = 1;
  param_1[0x34] = 0xffffffff;
  param_1[0x36] = 0;
  param_1[0x35] = &PTR_FUN_00a9db18;
  uVar5 = DAT_00a0f298;
  param_1[0x37] = DAT_00d1f01c;
  param_1[0x38] = DAT_00d1f020;
  param_1[0x39] = DAT_00d1f024;
  uVar2 = DAT_00d1f028;
  param_1[0x3c] = uVar5;
  param_1[0x3d] = DAT_00aaa880;
  param_1[0x41] = DAT_00a0f520;
  uVar5 = DAT_00aaa628;
  param_1[0x3a] = uVar2;
  param_1[0x3b] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = uVar5;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  *(undefined1 *)(param_1 + 0x4a) = 0;
  *(undefined1 *)((int)param_1 + 0x129) = 0;
  param_1[0x4c] = 0;
  param_1[0x4b] = &PTR_FUN_00a9db18;
  param_1[0x4d] = 0;
  *(undefined1 *)(param_1 + 0x4e) = 0;
  *(undefined1 *)((int)param_1 + 0x139) = 0;
  *(undefined1 *)((int)param_1 + 0x13a) = 0;
  param_1[0x4f] = 0;
  local_4._0_1_ = 7;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = DAT_00afdf0c;
  *(undefined1 *)(param_1 + 0x53) = 0;
  *(undefined1 *)((int)param_1 + 0x14d) = 0;
  uVar5 = FUN_00414bc0(0x144);
  local_4._0_1_ = 8;
  iVar6 = FUN_00414c20(4,uVar5,3,0);
  local_4 = CONCAT31(local_4._1_3_,7);
  FUN_00414b60();
  if ((iVar6 < 0) &&
     (iVar6 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp",0x45,
                           "Failed to Create Background Vertex Buffer"), iVar6 == 3)) {
    _File = fopen("c:\\VOGCRASH.txt","w");
    if (_File == (FILE *)0x0) goto LAB_0075d1c6;
    pcVar9 = "Failed to Create Background Vertex Buffer";
    uVar5 = 0x45;
  }
  else {
    FUN_00989e00(local_2c,"PalViewBackground.fx");
    iVar6 = FUN_009701d0(local_2c);
    if ((-1 < iVar6) ||
       (iVar6 = FUN_0076d1b0("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp",0x48,
                             "Failed to create view background effect"), iVar6 != 3)) {
      param_1[0x10] = param_1;
      puVar4 = param_1 + 0x17;
      for (iVar6 = 0x18; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      ExceptionList = local_c;
      return param_1;
    }
    _File = fopen("c:\\VOGCRASH.txt","w");
    if (_File == (FILE *)0x0) goto LAB_0075d1c6;
    pcVar9 = "Failed to create view background effect";
    uVar5 = 0x48;
  }
  fprintf(_File,"errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",
          "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxView.cpp",uVar5,3,pcVar9);
  fclose(_File);
LAB_0075d1c6:
  raise(0x16);
                    /* WARNING: Subroutine does not return */
  ExitProcess(3);
}
```

---

## Re-verify append — 2026-07-29 W31-O (OWN-ONLY)

| Field | Value |
|---|---|
| **Tool** | `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (**no** `disassemble_bytes`) |
| **Live decompile** | ≡ raw 2026-07-23 CF / string literals / field stores |
| **Body** | `0x0075ceb0`–`0x0075d1fc` inclusive (**0x54D** / **1357 B**); pad `CC` then next unit |
| **Prologue hex (64 B)** | `6aff68d7259b0064a100000000506489250000000083ec20f30f1005a0f2a0005355568be95733dbc74500c8eda900895d046a1068c0000000896c241c895d08` |
| **Epilogue hex** | `… 5d5b64890d0000000083c42cc3` (`ADD ESP,0x2C`; plain **`RET`**; FS restore) |
| **ABI sealed** | **ECX = GfxView\*** (`MOV EBP,ECX` in prologue); no stack formals; returns **this** in EAX; SEH frame `LAB_009b25d7` |
| **Semantics sealed** | **Ctor** for product class at `…\graphics\gfxView.cpp`: install vtbl `PTR_FUN_00a9edc8`; zero/init fields; `_aligned_malloc(0xC0,0x10)` + `FUN_00972cc0` → `+0x08` transform; sub-ctor `FUN_0073f590(this+0x10)`; two identity 4×4 mats (`FUN_0043f780` + copy `DAT_00afdf70`) at `+0x50/+0x54`; default **near 0.5** (`DAT_00a0f298` → `+0xF0`), **far 10000** (`DAT_00aaa880` → `+0xF4`), **FOV π/3** (`DAT_00aaa628` → `+0x10C`); dirty `+0x48/+0xCC` init 1; background VB via `FUN_00414bc0(0x144)` + `FUN_00414c20(4,…,3,0)` line **0x45**; effect `"PalViewBackground.fx"` via `FUN_00989e00`/`FUN_009701d0` line **0x48**; success: `+0x40 = this`, zero `+0x5C..+0xBB` (0x18 dwords), return this; fail severity 3 → `c:\VOGCRASH.txt` + `raise(0x16)` + `ExitProcess(3)` |
| **Object size (caller)** | Factory `FUN_004cda90` / `FUN_00968a50` allocate **`0x150`** before this ctor |
| **Classification** | **worker** (ctor) |
| **Callers (2)** | `FUN_004cda90` @ `0x004cdac8` (`Client_InitPalantirViewBundle`); `FUN_00968a50` @ `0x00968a71` |
| **Callees** | `_aligned_malloc`, `FUN_00972cc0`, `FUN_0073f590`, `FUN_0043f780`×2, `FUN_00414bc0`, `FUN_00414c20`, `FUN_00414b60`, `FUN_00989e00`, `FUN_009701d0`, `FUN_0076d1b0`, `fopen`/`fprintf`/`fclose`, `raise`, `ExitProcess` |
| **Name (inferred)** | `GfxView_Ctor_Inferred` — path + effect strings product-sealed; MSVC demangle open |
| **Decompile caveat** | `extraout_EDX` after `FUN_00972cc0` (aligned ctor return pairing) — treat as transform pointer store to `+0x08`; nested D3D helpers product English open |

### Constants (`read_memory`)

| Symbol | VA | Hex LE | Value |
|---|---|---|---|
| `g_flOne` | `0x00a0f2a0` | `00 00 80 3f` | **1.0** → `+0x0C` zoom |
| `DAT_00a0f298` | `0x00a0f298` | `00 00 00 3f` | **0.5** → default near `+0xF0` |
| `DAT_00aaa880` | `0x00aaa880` | `00 40 1c 46` | **10000.0** → default far `+0xF4` |
| `DAT_00a0f520` | `0x00a0f520` | `00 00 7a 44` | **1000.0** → `+0x104` (not far; factory may overwrite far later) |
| `DAT_00aaa628` | `0x00aaa628` | `92 0a 86 3f` | **π/3 ≈ 1.04719758** → FOV `+0x10C` |
| `DAT_00afdf0c` | `0x00afdf0c` | `ff ff ff ff` | **-1** → `+0x148` |
| `DAT_00afdf70` | `0x00afdf70` | identity 4×4 (diag 1.0) | matrix seed for two allocs |
