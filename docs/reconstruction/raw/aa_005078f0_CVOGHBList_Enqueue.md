# Raw capture: CVOGHBList_Enqueue

| Field | Value |
|---|---|
| **Stable ID** | `aa_005078f0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x005078f0` |
| **Canonical name** | `CVOGHBList_Enqueue` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
/* CVOGHBList_Enqueue
   
   Parameters:
     pList - heartbeat list (map-owned)
     pAction - CVOGHBBase* action to enqueue
   
   Algorithm: append action to timed-action list for later TryFire/OnTick.
   
   Returns: void
   
   Dependency of Vehicle_CreateCombatPoolAction (session combat-pool RE). */

uint __thiscall CVOGHBList_Enqueue(void *this,CVOGHBBase *pAction)

{
  if (pAction != (CVOGHBBase *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 4));
    if (*(uint *)((int)this + 0x2c) == (*(uint *)((int)this + 0x30) & 0x7fffffff)) {
      FUN_005b3370((int *)((int)this + 0x28),4);
    }
    *(CVOGHBBase **)(*(int *)((int)this + 0x28) + *(int *)((int)this + 0x2c) * 4) = pAction;
    *(int *)((int)this + 0x2c) = *(int *)((int)this + 0x2c) + 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 4));
    return 0;
  }
  return 0x80070057;
}
```
---

## Version note (2026-07-29 dual A/B — do not alter raw body above)

Live Ghidra re-decompile of `0x005078f0` matches the body above bit-for-bit in CF. Plate comment "Returns: void" is **incorrect**; body returns `0` / `0x80070057`. Grow callee `FUN_005b3370` doubles capacity (or 1 if empty); see reviews A/B and `docs/agents/task-dual-ab-005078f0-cvoghb-list-enqueue-report.md`.