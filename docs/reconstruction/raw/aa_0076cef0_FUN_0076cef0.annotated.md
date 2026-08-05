# Annotated low-level: Profiler_ScopeLeave (`FUN_0076cef0`)

| Field | Value |
|---|---|
| Stable ID | `aa_0076cef0` |
| VA | `0x0076cef0` only (**1** byte `c3`) |
| System | client instrumentation / profiler |
| Date | 2026-07-29 (W19-D dual seal) |
| Twin | `aa_0076cf00` Profiler_ScopeEnter |

---

## Machine-level notes

- Body is pure **`ret`** (`c3`). No stores, no callees, no stack cleanup.
- **Leave sibling** of `Profiler_ScopeEnter` @ `0x0076cf00` (`mov eax,[ecx+4]; ret 4`).
- Enter takes a zone **name** on the stack (`ret 4`); leave does **not** mirror `ret 4` — name was already cleaned by enter.
- High fan-in: AI heartbeat/drive/applyAction/stepTo/terrain/spawn paths call enter then leave around zones; leave is a no-op in this retail build.
- Physics port docs already label the pair as profiler enter/leave — **ignore for sector sim**.

## Recovered CF (annotated)

```c
// bare ret; ignores any this / args / return
void Profiler_ScopeLeave(void)
{
    return;
}
```

## Call pattern (callers, not body)

Typical instrumentation sandwich (from sibling dual + physics notes):

```
// ECX = *DAT_00d1f040
// push "ZoneName"; call Profiler_ScopeEnter;  // ret 4, EAX=timer*
// … work …
// call Profiler_ScopeLeave;                   // ret only
```

## Open questions

- Product/PDB spelling (ScopeLeave vs ScopeExit vs EndZone).
- Whether any residual path still pairs return timer from enter with active timing (body of leave still empty).
- Runtime / bit-exact.
