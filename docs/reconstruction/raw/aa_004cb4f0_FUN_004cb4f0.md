# Raw capture: FUN_004cb4f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cb4f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cb4f0` |
| **Canonical name** | `FUN_004cb4f0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004cb4f0(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = (int *)*param_1;
  if (*(char *)((int)piVar4 + 0x29) != '\0') {
    *param_1 = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x29) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x29);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x29);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *param_1 = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x29) == '\0') {
    do {
      if (*param_1 != *piVar4) break;
      *param_1 = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x29) == '\0');
    if (*(char *)((int)piVar4 + 0x29) == '\0') {
      *param_1 = (int)piVar4;
    }
  }
  return;
}
```

---

## Re-verify append — WQ9G-B dual seal (2026-08-04)

| Field | Value |
|---|---|
| Agent | OWN-ONLY dual **WQ9G-B** |
| Tools | Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context` (**no** `disassemble_bytes`) |
| Live decompile | ≡ frozen raw CF (three-arm predecessor; isnil@+0x29) |
| Body | `0x004cb4f0`–`0x004cb540` exclusive (**80 B** / `0x50`); pad `CC` then `FUN_004cb550` |
| ABI | **ECX = Node**** (`8B 01`); bare **`C3`**; leaf (no callees) |
| Layout | left@+0, parent@+4, right@+8, isnil@**+0x29** |
| Callers (5) | `FUN_00406040`, `FUN_004cbe20`, `FUN_004cbee0`, `FUN_004cc220` (`StdTree_InsertHint_Isnil29_Inferred`), `FUN_005a3b00` |
| Xrefs | 5 UNCONDITIONAL_CALL |
| Call-site | e.g. `004cc2db: LEA ECX,[ESP+0x24]` → `CALL 0x004cb4f0` |
| Named | `StdTree_Predecessor_Isnil29_Inferred` |

### Body hex (`read_memory` 0x50)

```
8b018078290074068b40088901c38b10807a290075188b420880782900750c908bd08b42088078290074f58911c38b40048078290075198b113b10750b89018b40048078290074ef8078290075028901c3
```

### Byte seals

| Item | Bytes |
|---|---|
| Load *it from ECX | `8B 01` |
| isnil cmp | `80 78 29 00` / `80 7A 29 00` |
| right / parent / left | `+8` / `+4` / `+0` |
| Exit | `C3` ×3 arms |
| Pad | `CC` to `004cb550` |
