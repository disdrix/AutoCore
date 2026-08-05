# Annotated low-level: CVOGHBList_Enqueue

| Field | Value |
|---|---|
| Stable ID | `aa_005078f0` |
| VA | `0x005078f0` |
| System | heartbeat / timed-action list |
| Date | 2026-07-29 (dual A/B seal) |

## Machine-level notes

- Source: live Ghidra decompile `0x005078f0` + grow `0x005b3370` + ctor `0x00507d10`.
- **Start ≠ Enqueue:** `CVOGHBBase_Start` only clears dormant + OnStart; this unit is required to park the HB on the pending queue for Tick promote.
- Cap high bit: ctor seeds capacity raw `0x80000000`; usable capacity is `& 0x7fffffff`; grow frees prior buffer only if `(int)oldCap >= 0`.
- Grow: `FUN_005b3370({buf,count,cap}*, elemSize=4)` → newCap = count==0 ? 1 : count*2; memcpy; set buf+cap (count unchanged).
- Return is **HRESULT-style** (`0` / `0x80070057`), not void (raw plate comment was wrong).

## Pseudocode (annotated)

```c
/* CVOGHBList_Enqueue — append CVOGHBBase* to pending under CS.
   this: CVOGHBList*; pAction: non-null HB or E_INVALIDARG.
   Returns: 0 success; 0x80070057 if pAction null. */

uint __thiscall CVOGHBList_Enqueue(void *this, CVOGHBBase *pAction)
{
  if (pAction != (CVOGHBBase *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 4));
    /* full when pendingCount == (pendingCapRaw & 0x7fffffff) */
    if (*(uint *)((int)this + 0x2c) == (*(uint *)((int)this + 0x30) & 0x7fffffff)) {
      FUN_005b3370((int *)((int)this + 0x28), 4); /* double (or 1), ptr elems */
    }
    *(CVOGHBBase **)(*(int *)((int)this + 0x28) + *(int *)((int)this + 0x2c) * 4) = pAction;
    *(int *)((int)this + 0x2c) = *(int *)((int)this + 0x2c) + 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 4));
    return 0;
  }
  return 0x80070057; /* E_INVALIDARG */
}
```

## Sealed offsets

| Off | Meaning |
|---|---|
| +0x04 | CRITICAL_SECTION |
| +0x28 | pending buffer |
| +0x2c | pending count |
| +0x30 | pending capacity raw |

## Open questions

- Product name for `FUN_005b3370` / heap tag `0x12`.
- Exhaustive Start↔Enqueue pairing audit (callers, not this body).
