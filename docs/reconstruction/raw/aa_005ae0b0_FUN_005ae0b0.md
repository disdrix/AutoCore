# Raw capture: FUN_005ae0b0

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae0b0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005ae0b0` |
| **Canonical name** | `FUN_005ae0b0` |
| **System** | std red-black tree / map iterator (Val12) |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_005ae0b0(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  iVar2 = *param_1;
  if (*(char *)(iVar2 + 0x19) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x19) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x19);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x19);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *param_1 = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x19);
    while ((cVar1 == '\0' && (*param_1 == *(int *)(iVar2 + 8)))) {
      *param_1 = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x19);
    }
    *param_1 = iVar2;
  }
  return;
}
```

---

## Re-verify (W28-N OWN-ONLY dual) — 2026-07-29

| Field | Value |
|---|---|
| **Tools** | Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + `get_bulk_xrefs`. **No** `disassemble_bytes`. |
| **Image** | `autoassault.exe` base `0x400000` |
| **Body** | `0x005ae0b0`–`0x005ae0fb` exclusive (**75** B / `0x4B`); pad `CC` after final `C3` |
| **Ghidra range** | body `005ae0b0`–`005ae0fa` (inclusive last RET) |
| **Live decompile** | ≡ raw 2026-07-23; leaf; **no callees**; CF matches classic MSVC `_Tree::_Inc` / iterator++ |
| **Node layout (Val12)** | left@+0, parent@+4, right@+8, isnil@+0x19 (same family as `StdTree_*_Val12`) |
| **Algorithm** | If `*it` not nil: if right not nil → right then leftmost; else walk parents while coming from right; write successor into `*it`. If `*it` is nil: no-op |
| **ABI** | ECX = `node**` (iterator / out node ptr); bare **`RET`** (`C3`); void |
| **Callees** | none (leaf) |
| **Callers (9)** | `FUN_004188e0`, `FUN_0040d5b0`, `FUN_004e4130`, `FUN_005399f0`, `FUN_0053a8e0`, `FUN_00572ab0`, `FUN_00573250`, `FUN_005ae990`, `FUN_005e15a0` — Val12 erase/successor consumers |
| **Semantic name** | `StdTree_Inc_Val12` (structural; MSVC `_Tree::_Inc` for isnil@+0x19) |
| **Legacy seed** | `Named_CalleeOf_Named_CalleeOf_Client_RecvSkillStatusEffect_005ae0b0` is **narrow** — shared tree helper |

### Full body hex (`read_memory` @ `0x005ae0b0`, 75 B through RET)

```
8b018078190075428b5008807a1900751c8b028078190075118da424000000008bd08b028078190074f68911c38b40048078190075128b113b5008750b89018b40048078190074ee8901c3
```
