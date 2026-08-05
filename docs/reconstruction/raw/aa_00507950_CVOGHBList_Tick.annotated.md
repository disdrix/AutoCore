# Annotated low-level: CVOGHBList_Tick

| Field | Value |
|---|---|
| Stable ID | `aa_00507950` |
| VA | `0x00507950` |
| System | `heartbeat` / timed-actions |
| Date | 2026-07-29 (strengthened; prior 2026-07-23 scaffold) |

## Machine-level notes

- Source: raw capture + live Ghidra `decompile_function` re-verify 2026-07-29.
- Prefer assembly when decompiler conflicts (none observed for this unit CF).
- `nForcedDeltaMsOrNull` stack slot is **reused** as TryFire out-status after tick update — not an arg to TryFire.
- List dual vectors: active `+0x1c/+0x20/+0x24`, pending `+0x28/+0x2c/+0x30`, CS `+0x04`.
- Grow helper `FUN_005b3370(slot, elemSize=4)` doubles capacity (see Enqueue twin).
- HB destroy: if `cStopped` at HB`+0x20` is 0 → vtbl+0x18(1,1); always refcount at +0x04 ++ then vtbl[0](1).

## Pseudocode (annotated)

```c
/* CVOGHBList_Tick — advance HB list using g_dwClientTickMs (0x00b041cc).

   If nForcedDeltaMsOrNull==0: g_dwClientTickMs=GetTickCount(); else add delta.
   For each active HB call vtable TryFire (vtbl+8); if status & 0x10 (Remove)
   swap-pop + destroy under CS.
   Then promote pending queue under critical section (grow active if full). */

void __thiscall CVOGHBList_Tick(void *this, int nForcedDeltaMsOrNull)
{
  int *piVar1;                 // CVOGHBBase* as int*
  int iVar2;                   // pending buffer base during promote
  byte *pbVar3;                // out-status pointer from TryFire
  int iVar4;                   // active / pending index
  LPCRITICAL_SECTION lpCriticalSection;

  // --- global tick ---
  if (nForcedDeltaMsOrNull == 0) {
    g_dwClientTickMs = GetTickCount();
  }
  else {
    g_dwClientTickMs = g_dwClientTickMs + nForcedDeltaMsOrNull;
  }

  // --- active: TryFire outside CS; remove under CS ---
  iVar4 = 0;
  if (0 < *(int *)((int)this + 0x20)) {          // active count
    do {
      piVar1 = *(int **)(*(int *)((int)this + 0x1c) + iVar4 * 4);  // active[i]
      // stack slot nForcedDeltaMsOrNull reused as EHBStatus out
      pbVar3 = (byte *)(**(code **)(*piVar1 + 8))(&nForcedDeltaMsOrNull); // TryFire
      if ((*pbVar3 & 0x10) == 0) {
        // Continue (0) or Inactive (2): keep, next index
        iVar4 = iVar4 + 1;
      }
      else {
        // Remove: swap-pop last into hole; do not advance i
        EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 4));
        *(int *)((int)this + 0x20) = *(int *)((int)this + 0x20) + -1;
        *(undefined4 *)(*(int *)((int)this + 0x1c) + iVar4 * 4) =
             *(undefined4 *)(*(int *)((int)this + 0x1c) + *(int *)((int)this + 0x20) * 4);
        if ((char)piVar1[8] == '\0') {           // HB+0x20 cStopped == 0
          (**(code **)(*piVar1 + 0x18))(1,1);  // pre-dtor lifecycle (name open)
        }
        piVar1[1] = piVar1[1] + 1;               // refcount ++
        (**(code **)*piVar1)(1);                 // deleting dtor
        LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 4));
      }
    } while (iVar4 < *(int *)((int)this + 0x20));
  }

  // --- promote pending → active (order-preserving append) ---
  lpCriticalSection = (LPCRITICAL_SECTION)((int)this + 4);
  nForcedDeltaMsOrNull = (int)lpCriticalSection;  // decomp keeps CS ptr in former arg slot
  EnterCriticalSection(lpCriticalSection);
  iVar4 = 0;
  if (0 < *(int *)((int)this + 0x2c)) {          // pending count
    do {
      iVar2 = *(int *)((int)this + 0x28);        // pending buf
      if (*(uint *)((int)this + 0x20) == (*(uint *)((int)this + 0x24) & 0x7fffffff)) {
        FUN_005b3370((int *)((int)this + 0x1c), 4);  // grow active
      }
      *(undefined4 *)(*(int *)((int)this + 0x1c) + *(int *)((int)this + 0x20) * 4) =
           *(undefined4 *)(iVar2 + iVar4 * 4);
      *(int *)((int)this + 0x20) = *(int *)((int)this + 0x20) + 1;
      iVar4 = iVar4 + 1;
      lpCriticalSection = (LPCRITICAL_SECTION)nForcedDeltaMsOrNull;
    } while (iVar4 < *(int *)((int)this + 0x2c));
  }
  *(undefined4 *)((int)this + 0x2c) = 0;         // clear pending count only
  LeaveCriticalSection(lpCriticalSection);
  return;
}
```

## Callers (live)

- `FUN_0093e010` → `Tick(client+0xd38, 0)`
- `FUN_0094b520` → `Tick(client+0xd38, 0)`

## Open questions

- Product English for vtbl+0x18.
- Extra status bits beyond 0 / 2 / 0x10.
- Forced-delta producers (none in static caller set).
