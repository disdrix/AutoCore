# Raw capture: FUN_004cda90

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cda90` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cda90` |
| **Canonical name** | `FUN_004cda90` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 __fastcall FUN_004cda90(int param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a1ef7;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar2 = operator_new(0x150);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0075ceb0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0xe890) = uVar3;
  FUN_0075b3b0(0x3f000000);
  uVar3 = DAT_00a0f520;
  if (*(char *)(param_1 + 0x7d) == '\0') {
    uVar3 = DAT_00aaaa90;
  }
  FUN_0075b390(uVar3);
  if (*(int *)(param_1 + 0xe89c) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xe89c) + 0x2e4) = *(undefined4 *)(param_1 + 0xe890);
    (**(code **)(**(int **)(*(int *)(param_1 + 0xe89c) + 0x2c) + 0xc))
              (*(undefined4 *)(param_1 + 0xe890));
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xe89c) + 0x2c) + 0xc4) = DAT_00afdef0;
  }
  pvVar2 = operator_new(0x198);
  local_4 = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00492dd0(0,param_1);
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(param_1 + 0xe894) = uVar3;
  pvVar2 = operator_new(200);
  local_4 = 2;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00496f70(param_1);
  }
  *(undefined4 *)(param_1 + 0xe898) = uVar3;
  *(undefined4 *)(*(int *)(param_1 + 0xe890) + 4) = *(undefined4 *)(param_1 + 0xe894);
  *(undefined4 *)(*(int *)(param_1 + 0xe894) + 0xc0) = *(undefined4 *)(param_1 + 0xe890);
  local_4 = 0xffffffff;
  FUN_0048fc90(1);
  iVar1 = *(int *)(*(int *)(param_1 + 0xe894) + 4);
  if (DAT_00d1a54c != 0) {
    FUN_0074e200(0);
  }
  if (iVar1 != 0) {
    FUN_0074e200(1);
  }
  DAT_00d1a54c = iVar1;
  ExceptionList = pvStack_c;
  return 1;
}
```

---

## W30-F re-verify (2026-07-29)

**Tools:** live `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.

| Field | Sealed value |
|---|---|
| Body | `0x004cda90`–`0x004cdc34` exclusive (**420 B** / `0x1A4`); pad `CC` |
| ABI | `__thiscall`/`__fastcall`; ECX=`parent*`; no stack formals; bare **`C3` RET**; returns **1** (`B0 01`) |
| Entry | `6A FF 68 F7 1E 9A 00` SEH `LAB_009a1ef7`; `8B F1` (ESI=this); `68 50 01 00 00` push `0x150` |
| Epilogue | `89 35 4C A5 D1 00` (`DAT_00d1a54c`); `B0 01 5E` … `83 C4 10 C3` |
| Live decompile | **≡** 2026-07-23 raw CF (three new/ctor, wire, global stamp, return 1) |
| Caller | sole CODE: `FUN_00948530` @ `0x00948aad` (window init; string `"Could not get Palantir desktop window."`) |
| Callees | `operator_new`×3; `FUN_0075ceb0` (GfxView/`gfxView.cpp`); `FUN_0075b3b0`/`FUN_0075b390`; `FUN_00492dd0`; `FUN_00496f70` (`Class_009c7a1c_Ctor`); `FUN_0048fc90`; `FUN_0074e200`×2 |

### Constants (`read_memory`)

| Symbol / imm | Bytes | Value |
|---|---|---|
| imm to `FUN_0075b3b0` | `00 00 00 3F` | **0.5f** → view`+0xF0` |
| `DAT_00a0f520` | `00 00 7A 44` | **1000.0f** → view`+0xF4` when parent`+0x7d≠0` |
| `DAT_00aaaa90` | `00 00 FA 43` | **500.0f** → view`+0xF4` when parent`+0x7d==0` |
| `DAT_00afdef0` | `00 00 00 FF` | dword stamp on desktop child`+0xC4` |

### Role (sealed)

Factory on large client/core parent: allocate+construct three owned subsystems at `+0xE890` (GfxView `0x150`), `+0xE894` (`0x198`/`FUN_00492dd0`), `+0xE898` (`Class_009c7a1c` `0xC8`); cross-wire view↔env; optional Palantir desktop hook via `+0xE89C`; environment phase init `FUN_0048fc90(1)`; publish `*(e894+4)` into global `DAT_00d1a54c` with enable/disable via `FUN_0074e200`.
