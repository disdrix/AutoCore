# Raw capture: FUN_004e2bd0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e2bd0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004e2bd0` |
| **Canonical name** | `FUN_004e2bd0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004e2bd0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    puVar3 = *(undefined4 **)(*(int *)(*(int *)(param_1 + 0x10) + uVar4 * 4) + 4);
    while (puVar3 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)puVar3[4];
      *puVar3 = &PTR_FUN_009cb360;
      if ((undefined4 *)puVar3[3] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)puVar3[3])(1);
      }
      puVar3[3] = 0;
      *puVar3 = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 **)(param_1 + 0x20) = puVar3;
      puVar3 = puVar2;
    }
    iVar1 = uVar4 * 4;
    uVar4 = uVar4 + 1;
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x10) + iVar1) + 4) = 0;
  } while (uVar4 <= *(uint *)(param_1 + 8));
  return;
}
```

---

## W37-J re-verify (2026-08-04) — append only

**Agent:** OWN-ONLY dual W37-J  
**Tools:** `batch_decompile` / `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Live decompile ≡ raw 2026-07-23 CF** (bucket loop, value delete, freelist push, clear heads).

### Body bounds / bytes

| Field | Value |
|---|---|
| Start | `0x004e2bd0` |
| Exclusive end | `0x004e2c2e` (pad `CC`; next prologue twin-like) |
| Size | **94 B** / `0x5E` |
| Epilogue | `POP EDI; POP ESI; POP EBP; POP EBX; RET` (`5F 5E 5D 5B C3`) |

Full hex:
```
53555633c0578bd933ed8d9b000000008b4b108b14a98b7a043bf8742c8d49008bf78b4e0c3bc88b7f10c70660b39c0074088b016a01ff1033c03bf889460c8b4b20890e89732075d78b53108b0caa83c5018941043b6b0876b65f5e5d5bc3
```

### ABI (sealed)

- **`__thiscall`**: ECX = hash*; Ghidra shows `__fastcall` ECX.
- Prologue: `PUSH EBX/EBP/ESI/EDI`; `MOV EBX,ECX` (this in EBX).
- No stack args; plain **`RET`** (`C3`); void (no EAX set for return).

### Algorithm (sealed)

```
for i = 0 .. mask(+0x08) inclusive:
  node = buckets[i]->head (+4)
  while node:
    next = node[+0x10]           // [4]
    *node = &PTR_FUN_009cb360    // stamp freelist-class vtbl
    if node[+0x0C] (value*):
      (*value_vtbl)(value, 1)    // scalar-deleting destroy
    node[+0x0C] = 0
    *node = freelist(+0x20)      // intrusive freelist push (overwrites stamp)
    freelist = node
    node = next
  buckets[i]->head = 0
```

### Layout

| Off | Role |
|---:|---|
| hash+0x08 | mask (loop `i <= mask`) |
| hash+0x10 | buckets* table |
| hash+0x20 | freelist head |
| bucket+0x04 | chain head |
| node+0x00 | vtbl / freelist next |
| node+0x0C | owned value* |
| node+0x10 | chain next |

### Twin diff vs `FUN_004bcae0` @ `0x004bcae0` (W37-G OWN)

| Field | `004e2bd0` | `004bcae0` |
|---|---|---|
| Node stamp | `009cb360` | `009cb358` |
| Value slot | node[+0x0C] | node[+0x08] |
| Chain next | node[+0x10] | node[+0x0C] |

### Callers

| Caller | Site | Role |
|---|---|---|
| `FUN_004bcca0` / `CNDHash_FreeBuckets_009cb45c` | `0x004bccaa` | sole static xref (W31-M) |

### Name

`CNDHash_ReclaimAll_ValueOwning_009cb360` (Ghidra `FUN_004e2bd0`).  
Reject scaffold `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_004e2bd0`.

### Classification

**worker / leaf** (no direct FUN callees; virtual delete only).
