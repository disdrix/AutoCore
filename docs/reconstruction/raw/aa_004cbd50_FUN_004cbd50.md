# Raw capture: FUN_004cbd50

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbd50` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004cbd50` |
| **Canonical name** | `FUN_004cbd50` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __thiscall FUN_004cbd50(int param_1,undefined4 *param_2,int *param_3)



{

  undefined4 *puVar1;

  undefined4 *puVar2;

  undefined4 *puVar3;

  

  puVar3 = *(undefined4 **)(param_1 + 4);

  if (*(char *)((int)puVar3[1] + 0x65) == '\0') {

    puVar1 = (undefined4 *)puVar3[1];

    do {

      if ((int)puVar1[3] < *param_3) {

        puVar2 = (undefined4 *)puVar1[2];

      }

      else {

        puVar2 = (undefined4 *)*puVar1;

        puVar3 = puVar1;

      }

      puVar1 = puVar2;

    } while (*(char *)((int)puVar2 + 0x65) == '\0');

  }

  if ((puVar3 != *(undefined4 **)(param_1 + 4)) && ((int)puVar3[3] <= *param_3)) {

    *param_2 = puVar3;

    return;

  }

  *param_2 = *(undefined4 **)(param_1 + 4);

  return;

}
```

---

## Live re-decompile (2026-07-29 W26-O)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` + `analyze_function_complete` |
| **Program** | `autoassault.exe` base `0x400000` |
| **Body** | `0x004cbd50`–`0x004cbdb1` (**98 B** inclusive dual `C2 08 00`) |
| **Epilogue** | `POP EDI; POP ECX; RET 8` (`5F 59 C2 08 00`) — **thiscall**, 2 stack formals |
| **Classification** | **leaf** (0 callees) |
| **Callers (5)** | `FUN_004c9120`, `FUN_004c9430`, `CVOGHBAIDriver_DoLogic`, `FUN_005d7ca0`, `FUN_005d7f70` (`CVOGHBAICreatureBase_DoLogic`) |
| **Xrefs** | 5 call sites (`004c92b4`, `004c9498`, `005d77d9`, `005d7cdc`, `005d7faf`) |
| **Integrity** | Live decompile ≡ 2026-07-23 raw body (identical CF) |
| **Canonical name** | `Map_LowerBoundFindByIntKey_Isnil65` (Ghidra `FUN_004cbd50`) |

### Machine hex (full body, 98 B)

```
518b51048b420480786500578b7c24107518568b3739700c7d058b4008eb048bd08b008078650074ec5e8b41043bd08954241074188b0f3b4a0c7c118d4424108b108b44240c89105f59c20800894424048d4424048b108b44240c89105f59c20800
```

### Sealed ABI

```
// thiscall ECX=mapHeader; stack: Node** pOutIt, int* pKey; ret 8; void
// void Map_LowerBoundFindByIntKey_Isnil65(MapHeader *this, Node **pOutIt, int *pKey)
// Exact-find via lower_bound walk + equality gate. Writes *pOutIt = node or end.
```

### Node layout (this unit)

| Slot | Offset | Role |
|---|---|---|
| left | `node+0x00` (`*node`) | left child |
| parent (head root) | `head+0x04` (`head[1]`) | root = end→parent |
| right | `node+0x08` (`node[2]`) | right child |
| key | `node+0x0C` (`node[3]`) | **signed dword** compared vs `*pKey` |
| isnil | `node+0x65` | `0` = real node; nonzero = sentinel/nil |

### Live decompile (identical CF to raw)

```c
void __thiscall FUN_004cbd50(int param_1,undefined4 *param_2,int *param_3)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;

  puVar3 = *(undefined4 **)(param_1 + 4);
  if (*(char *)((int)puVar3[1] + 0x65) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((int)puVar1[3] < *param_3) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x65) == '\0');
  }
  if ((puVar3 != *(undefined4 **)(param_1 + 4)) && ((int)puVar3[3] <= *param_3)) {
    *param_2 = puVar3;
    return;
  }
  *param_2 = *(undefined4 **)(param_1 + 4);
  return;
}
```

### Control-flow stages (sealed)

1. `end = *(this+4)`; `cand = end`; `cur = end[1]` (root).
2. If root isnil (`cur+0x65 != 0`) skip walk.
3. Walk: if `cur.key < *pKey` → right; else `cand=cur`, left. Until isnil.
4. If `cand != end && cand.key <= *pKey` → `*pOut = cand` (exact; walk ⇒ `key >= *pKey`).
5. Else `*pOut = end` (miss).
6. No insert/erase/allocation (leaf read-only).
