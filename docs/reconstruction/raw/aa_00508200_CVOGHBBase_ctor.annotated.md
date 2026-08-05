# Annotated low-level: CVOGHBBase_ctor

| Field | Value |
|---|---|
| Stable ID | `aa_00508200` |
| VA | `0x00508200`–`0x0050822c` |
| System | heartbeat / timed-actions |
| Date | 2026-07-23; residual annotate 2026-07-29 |

## Machine-level notes

- Source: raw capture + `read_memory` residual seal.
- Body **45** bytes; **no callees**; `__thiscall` ECX=this.
- **Dual period:** +0x08 `nPeriodMs` and +0x0C `nPeriodSentinel` both zeroed (do not alias).
- **lastFire** +0x14 ← `g_dwClientTickMs` @ `0x00b041cc` (plate name `g_ActionSchedulerTickMs` is alias).
- **fDormant** +0x21 = 1; **cStopped** +0x20 = 0.
- **+0x1C** type tag zeroed here; siblings set 1 (skill HB), 4 (weapon track), 8 (OKToCastAgain).
- **+0x22..+0x27** not written — subclass/debounce tail inside sizeof 0x28.
- Base vtbl `0x009cdab0`; slot1 = StampLastFireTime (default OnStart).

## Pseudocode (annotated ≡ raw ≡ machine order)

```c
/* TimedAction_ctorBase — zero/init common TimedAction fields; vtable = base.
   Sets lastFireTick(+0x14) = g_dwClientTickMs. */

void __thiscall CVOGHBBase_ctor(void *this)
{
  *(void ***)this = &PTR_FUN_009cdab0;           /* +0x00 pVTable */
  *(int *)((int)this + 0x1c) = 0;                /* +0x1C nTypeTag */
  *(unsigned char *)((int)this + 0x21) = 1;      /* +0x21 fDormant */
  *(int *)((int)this + 8) = 0;                   /* +0x08 nPeriodMs */
  *(int *)((int)this + 0xc) = 0;                 /* +0x0C nPeriodSentinel */
  *(int *)((int)this + 0x10) = 0;                /* +0x10 nPeriodCounter */
  *(unsigned *)((int)this + 0x14) = g_dwClientTickMs; /* +0x14 lastFire */
  *(unsigned char *)((int)this + 0x20) = 0;      /* +0x20 cStopped */
  *(int *)((int)this + 0x18) = 0;                /* +0x18 pOwnerObject */
  *(int *)((int)this + 4) = 0;                   /* +0x04 nRefOrFlags */
  return;
  /* +0x22..+0x27 untouched */
}
```

## Open questions

- Full `nTypeTag` enum beyond {0,1,4,8}.
- `nRefOrFlags` (+0x04) consumers.
- Whether heap alloc pre-zeros +0x22..+0x27.
