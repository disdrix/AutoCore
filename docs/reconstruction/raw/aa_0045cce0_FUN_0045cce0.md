# Raw capture: FUN_0045cce0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045cce0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0045cce0` |
| **Canonical name** | `FUN_0045cce0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
undefined4 * FUN_0045cce0(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (param_3 != param_4) {
    puVar1 = *(undefined4 **)(param_1 + 8);
    puVar2 = param_3;
    while (param_4 != puVar1) {
      puVar4 = param_4 + 7;
      puVar5 = puVar2 + 7;
      puVar6 = param_4;
      puVar7 = puVar2;
      for (iVar3 = 7; puVar2 = puVar5, param_4 = puVar4, iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    *(undefined4 **)(param_1 + 8) = puVar2;
  }
  *param_2 = param_3;
  return param_2;
}
```

---

## W36-L re-verify (2026-07-29) — append only

**Tools:** `batch_decompile` / `analyze_function_complete` + `read_memory` (full body). **No** `disassemble_bytes`.  
**Body (bytes win):** `0x0045cce0`–`0x0045cd2b` exclusive (**75 B** / `0x4B`). Epilogue `C2 10 00` (last byte inclusive `0x0045cd2a`). Pad `CC`×5 then `FUN_0045cd30` (`StdVector_InsertN_Pod28`) @ `0x0045cd30`.

### Full hex (75 B)

```
8b44240c8b5424103bc274348b4c240453558b69083bd58bd8741c56578d49008bf28bfb83c21cb90700000083c31c3bd5f3a575eb5f5e8b54240c5d895a085b8b4c240889018bc1c21000
```

### Byte-level control flow

| Bytes | Role |
|---|---|
| `8B 44 24 0C` | **EAX = first** (stack arg2 after ret = `[esp+0xC]`) |
| `8B 54 24 10` | **EDX = last** (`[esp+0x10]`) |
| `3B C2` `74 34` | if first==last → skip erase body (still write out-iter) |
| `8B 4C 24 04` | **ECX = vec*** |
| `53 55` `8B 69 08` | push; **EBP = vec->end** (`vec+8`) |
| `3B D5` `8B D8` | cmp last,end; **EBX = first** (dest cursor) |
| `74 1C` | if last==end → no shift (truncate only) |
| loop: `8B F2` `8B FB` `83 C2 1C` `B9 07 00 00 00` `83 C3 1C` `3B D5` `F3 A5` `75 EB` | copy 7 dwords from last→first; advance both by **0x1c** until last==end |
| `8B 54 24 0C` `5D` `89 5A 08` `5B` | **vec->end = dest** (after 2 pushes, `[esp+0xC]` = vec*) |
| `8B 4C 24 08` `89 01` `8B C1` | **\*out_it = first**; **EAX = out_it*** |
| `C2 10 00` | **RET 0x10** (4 stack dwords) |

### Sealed ABI (bytes win)

| Formal | Stack (entry) | Role |
|---|---|---|
| vec* | `[esp+4]` | `vector<Pod28>*` (begin@+4, end@+8) |
| out_it* | `[esp+8]` | output iterator slot (written = first) |
| first | `[esp+0xC]` | erase range begin |
| last | `[esp+0x10]` | erase range end (exclusive) |
| return | **EAX = out_it*** | MSVC erase return style |
| cleanup | **`RET 0x10`** | |

### Semantics (sealed)

MSVC-style **`vector<T>::erase(first, last)`** for trivially copyable T size **0x1c**:
1. If first≠last: shift POD elements `[last, end)` down onto `[first, …)` via 7×`movsd`/`rep movsd`; publish `end = first + (end−last)`.
2. Always `*out_it = first`; return `out_it`.
3. When last==end (resize shrink): no move; just set end=first.

### Classification / graph

| Item | Value |
|---|---|
| Classification | **leaf** |
| Callees | none |
| Callers | `FUN_0045c4b0` (`StdVector_Resize_Pod28` shrink @ `0x0045c547`), `FUN_00466df0` @ `0x00466e87` |
| Decompile ≡ bytes | CF + stride + RET 10 sealed |
