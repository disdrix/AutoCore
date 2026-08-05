# Raw capture: Map_LowerBoundFindByCharKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402210` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x00402210` |
| **Canonical name** | `Map_LowerBoundFindByCharKey` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall Map_LowerBoundFindByCharKey(void *this,void *pMap,void *pOutIt,char *pKey)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)((int)this + 4);
  if (*(char *)((int)puVar3[1] + 0x21) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (*(char *)(puVar1 + 3) < *(char *)pOutIt) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x21) == '\0');
  }
  if ((puVar3 != *(undefined4 **)((int)this + 4)) && (*(char *)(puVar3 + 3) <= *(char *)pOutIt)) {
    *(undefined4 **)pMap = puVar3;
    return;
  }
  *(undefined4 **)pMap = *(undefined4 **)((int)this + 4);
  return;
}
```

---

## Re-decompile confirmation (2026-07-29)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` + `analyze_function_complete` |
| **VA** | `0x00402210` |
| **Result** | Pseudocode body **identical** to authoritative raw above |
| **Bytes note** | Function ends `C2 08 00` (`ret 8`) — true stack arity is **2**, not the decompiler’s three formals |
| **Key asm** | nil: `80 78 21 00` (`[reg+0x21]`); key: `38 48 0C` / `3A 4A 0C` (`[reg+0x0C]`) |
| **Callees** | none (leaf) |
| **Integrity** | Raw body above left unchanged; this section is append-only |
