# Annotated low-level: NDResource_AcquireInnerObject

| Field | Value |
|---|---|
| Stable ID | `aa_00745ee0` |
| VA | `0x00745ee0` |
| System | client NDResource shell |
| Date | 2026-07-23; annotated strengthen **2026-07-29** dual A/B |

## Machine-level notes

- Source: raw capture for `aa_00745ee0` + live `decompile_function` ×3 + `read_memory` (2026-07-29).
- Prefer assembly/`read_memory` when decompiler conflicts (none material this unit).
- Dual A/B: `reviews/A_aa_00745ee0_NDResource_AcquireInnerObject.md`, `reviews/B_aa_00745ee0_NDResource_AcquireInnerObject.md`.

## Layout (byte offsets)

| Off | Role |
|-----|------|
| +0x00 | vtbl |
| +0x08 | inner* (return) |
| +0x10 | refcount (++) |
| +0x1c | float last-touch (`fstp`) |
| +0x20 | CRITICAL_SECTION |
| +0x38 | u8 lock flag |

## Pseudocode (annotated; CF ≡ raw ≡ live)

```c
/* NDResource_AcquireInnerObject  (thiscall)

   Bump refcount at this+0x10, optionally take critical section (this+0x20).
   If this+0x8 is null, Release this via vtable+8.
   Returns pointer at this+8 (inner resource).

   Nested CS: when lockFlag set → Enter, mutate, Enter, Leave, maybe Release, Leave.
   Timer: FUN_0076c330 → fstp float @ +0x1c (not int). */

void *__thiscall NDResource_AcquireInnerObject(int *self /* NDResource* */)
{
  LPCRITICAL_SECTION cs = (LPCRITICAL_SECTION)((char *)self + 0x20);
  char lockFlag = *(char *)((char *)self + 0x38);
  void *inner;
  int had_inner;

  if (lockFlag != 0)
    EnterCriticalSection(cs);

  self[4] = self[4] + 1;                 /* +0x10 refcount */
  *(float *)((char *)self + 0x1c) = (float)FUN_0076c330();

  if (lockFlag != 0)
    EnterCriticalSection(cs);            /* nested */

  inner = (void *)self[2];               /* +0x08 */
  had_inner = (inner != 0);

  if (lockFlag != 0)
    LeaveCriticalSection(cs);

  if (!had_inner)
    (*(void (__thiscall **)(int *))(*(int *)self + 8))(self); /* vtbl+8 */

  inner = (void *)self[2];               /* re-sample */

  if (lockFlag != 0)
    LeaveCriticalSection(cs);

  return inner;
}
```

## Open questions

- Product English name for `FUN_0076c330` and vtbl+8 Release.
- Whether null-inner Release can free `self` before re-sample (Release-body residual).
- Who sets lock flag `+0x38` (producer residual).
