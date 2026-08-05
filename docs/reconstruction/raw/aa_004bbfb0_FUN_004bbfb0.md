# Raw capture: FUN_004bbfb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bbfb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bbfb0` |
| **Canonical name** | `FUN_004bbfb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * __thiscall FUN_004bbfb0(undefined4 *param_1,int param_2,int param_3)



{

  void *pvVar1;

  undefined4 uVar2;

  undefined4 *puVar3;

  void *local_c;

  undefined1 *puStack_8;

  undefined1 local_4;

  undefined3 uStack_3;

  

  puStack_8 = &LAB_009a1742;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_009cb448;

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  param_1[0xf] = 0;

  param_1[0x10] = 0;

  param_1[0x11] = 0;

  param_1[0x13] = 0;

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  if (param_2 < 0) {

    param_2 = 0;

  }

  if (param_3 < 0) {

    param_3 = 0;

  }

  local_4 = 2;

  uStack_3 = 0;

  param_1[4] = param_2;

  param_1[5] = param_3;

  *(bool *)(param_1 + 3) = param_2 != 0;

  *(bool *)((int)param_1 + 0xd) = param_3 != 0;

  if (param_2 != 0) {

    pvVar1 = operator_new(0x34);

    local_4 = 3;

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_004bcf90(param_2);

    }

  }

  else {

    uVar2 = 0;

  }

  local_4 = 2;

  param_1[1] = uVar2;

  if (*(char *)((int)param_1 + 0xd) == '\0') {

    uVar2 = 0;

  }

  else {

    pvVar1 = operator_new(0x34);

    local_4 = 4;

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_004bcf90(param_3);

    }

  }

  local_4 = 2;

  param_1[2] = uVar2;

  pvVar1 = operator_new(0x34);

  local_4 = 5;

  if (pvVar1 == (void *)0x0) {

    uVar2 = 0;

  }

  else {

    uVar2 = FUN_004bce90(5);

  }

  _local_4 = CONCAT31(uStack_3,2);

  param_1[6] = uVar2;

  puVar3 = operator_new(0x2c);

  if (puVar3 == (undefined4 *)0x0) {

    puVar3 = (undefined4 *)0x0;

  }

  else {

    *puVar3 = &PTR_FUN_009cb334;

    puVar3[8] = 0;

    puVar3[7] = 0;

    puVar3[9] = 0;

    *(undefined1 *)(puVar3 + 10) = 0;

    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar3 + 1));

    *puVar3 = &PTR_FUN_009cb378;

  }

  param_1[7] = puVar3;

  puVar3 = operator_new(0x2c);

  if (puVar3 == (undefined4 *)0x0) {

    puVar3 = (undefined4 *)0x0;

  }

  else {

    *puVar3 = &PTR_FUN_009cb334;

    puVar3[8] = 0;

    puVar3[7] = 0;

    puVar3[9] = 0;

    *(undefined1 *)(puVar3 + 10) = 0;

    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar3 + 1));

    *puVar3 = &PTR_FUN_009cb378;

  }

  param_1[8] = puVar3;

  puVar3 = operator_new(0x2c);

  if (puVar3 == (undefined4 *)0x0) {

    puVar3 = (undefined4 *)0x0;

  }

  else {

    *puVar3 = &PTR_FUN_009cb334;

    puVar3[8] = 0;

    puVar3[7] = 0;

    puVar3[9] = 0;

    *(undefined1 *)(puVar3 + 10) = 0;

    InitializeCriticalSection((LPCRITICAL_SECTION)(puVar3 + 1));

    *puVar3 = &PTR_FUN_009cb378;

  }

  param_1[9] = puVar3;

  *(undefined1 *)((int)param_1 + 0xe) = 0;

  ExceptionList = local_c;

  return param_1;

}
```

---

## W27-L live re-verify (2026-07-29) — APPEND ONLY

| Field | Value |
|---|---|
| **Agent** | OWN-ONLY dual W27-L |
| **Tools** | `decompile_function` + `read_memory` + `get_function_by_address` + `analyze_function_complete` + callers/xrefs (**no** `disassemble_bytes`) |
| **Body** | `0x004bbfb0`–`0x004bc17f` (**464 B / `0x1D0`**) |
| **Live decompile** | **≡** 2026-07-23 raw scaffold body (CF-identical) |
| **ABI** | `__thiscall`; ECX=`this`; stack `(int capA, int capB)`; epilogue **`ret 8`** (`C2 08 00`); returns `this` in EAX |
| **Role** | **COList** constructor (`*this = PTR_FUN_009cb448`) |
| **Object size** | **`0x58`** — `Client_InitInstance` (`FUN_0094a6a0`) `operator_new(0x58)` then `FUN_004bbfb0(5,10)` → `DAT_00b04830` and `client+0xD34` |
| **Init log** | Immediately after `"before CVOGClonedObjectList"` |
| **Callees** | `operator_new`×6 paths, `FUN_004bcf90`×2 (hash ctor, size `0x34`), `FUN_004bce90`×1 (hash-like ctor, size `0x34`, fixed arg **5**), `InitializeCriticalSection`×3 |
| **Caller (1)** | `FUN_0094a6a0` @ `0x0094a7eb` |

### Entry / exit bytes (`read_memory`)

```
004bbfb0  6A FF 68 42 17 9A 00 64 A1 00 00 00 00 50 64 89  … SEH + LAB_009a1742
004bbfd0  … C7 06 48 B4 9C 00 …                              *this = 0x009cb448
004bc170  … 83 C4 10 C2 08 00                                add esp,0x10; ret 8
```

### Layout writes (dword indices → byte offsets)

| Index / off | Write |
|---|---|
| `[0]` +0x00 | vtbl `PTR_FUN_009cb448` |
| `[1]` +0x04 | hashA = `FUN_004bcf90(capA)` if capA≠0 else 0 (`operator_new(0x34)`) |
| `[2]` +0x08 | hashB = `FUN_004bcf90(capB)` if flag@+0x0D else 0 |
| +0x0C | bool `(capA != 0)` |
| +0x0D | bool `(capB != 0)` |
| +0x0E | `0` |
| `[4]` +0x10 | capA (clamped ≥0) |
| `[5]` +0x14 | capB (clamped ≥0) |
| `[6]` +0x18 | always `FUN_004bce90(5)` on `operator_new(0x34)` |
| `[7..9]` +0x1C/+0x20/+0x24 | three `0x2C` objects: interim vtbl `009cb334`, zero dwords, ICS at +4, final vtbl `009cb378` |
| `[0xB..0xD]` +0x2C.. | zeroed buffer triple heads |
| `[0xF..0x11]` +0x3C.. | zeroed |
| `[0x13..0x15]` +0x4C.. | zeroed |

### Vtbl / product evidence

```
009cb448: B0 D1 4B 00 …  (= 0x004bd1b0 scalar dtor)
009cb464: "Threw error in COList::Insert\n"
```

### Named clean

`COList_Constructor` — see function record + dual A/B.

