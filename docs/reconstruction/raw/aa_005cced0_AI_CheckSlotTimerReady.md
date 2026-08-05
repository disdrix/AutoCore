# Raw capture: AI_CheckSlotTimerReady

| Field | Value |
|---|---|
| **Stable ID** | `aa_005cced0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005cced0` |
| **Canonical name** | `AI_CheckSlotTimerReady` |
| **System** | inventory-transfer |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
uint __thiscall AI_CheckSlotTimerReady(void *this,void *pAiCtx,uint nSlotIndex)

{
  int iVar1;
  
  if (*(uint *)((int)this + (int)pAiCtx * 0xc + 0x74) <
      g_dwClientTickMs - *(int *)((int)this + (int)pAiCtx * 0xc + 0x70)) {
    iVar1 = (int)pAiCtx * 3 + 0x1e;
    *(undefined1 *)((int)this + iVar1 * 4) = 1;
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  return (uint)pAiCtx & 0xffffff00;
}
```

---

## Re-verify append (2026-07-29 dual A/B)

| Field | Value |
|---|---|
| **Tool** | Ghidra MCP `decompile_function` + `read_memory` + `get_function_xrefs` / `get_function_callers` + `audit_global` |
| **Body range** | `0x005cced0`–`0x005ccefc` |
| **Integrity** | Original raw body above preserved; this section is additive |

### Live body hex (through both `ret 4`)

```text
8b442404 56 8b35cc41b000 8d1440 2b749170 8d1491 3b7274 5e 760d
8d44401e c6048101 b001 c20400
32c0 c20400
```

### Sealed corrections (do not rewrite raw decomp above)

| Topic | Raw decomp | Sealed |
|---|---|---|
| Stack arity | 2 formals after `this` | **1** stack dword (`RET 4`) |
| `pAiCtx` type | `void*` | **integer slot index** |
| `nSlotIndex` formal | present | **decomp artifact / unused** |
| Ready flag | `(pAiCtx*3+0x1e)*4` | ≡ `this + i*0xC + 0x78` |
| System tag (header) | inventory-transfer | **npc-ai / HBAI** (header left historical) |

### Call xrefs (2026-07-29)

```
005d079d CVOGHBAICreatureBase_OnHeartBeat
005d13ee NPC_TryCastSkillFromSet          ; PUSH 2
005d7845 CVOGHBAIDriver_DoLogic           ; PUSH 0
005d7ac1 CVOGHBAIDriver_DoLogic           ; PUSH 0
005d7ffe FUN_005d7f70
005d8264 FUN_005d7f70
```
