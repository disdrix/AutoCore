# Annotated low-level: CVOGHBBase_SetPeriodAndCounter

| Field | Value |
|---|---|
| Stable ID | `aa_005081a0` |
| VA | `0x005081a0` |
| System | heartbeat / timed-actions |
| Date | 2026-07-29 residual seal (prior 2026-07-23) |

## Machine-level notes

- Source: raw capture + `read_memory` body seal.
- Prefer machine bytes when decompiler field names conflict across siblings.
- `__thiscall`: ECX=this; stack `int` + `bool` (byte); `ret 8`.
- Always `this+0x0C = arg1`; if flag, `this+0x10 = arg1`. Never `+0x08` / `+0x14`.
- `-1000` sentinel is a **caller** convention, not encoded in this body.

## Pseudocode (annotated copy of raw)

```c
/* CVOGHBBase_SetPeriodAndCounter — write nPeriodSentinel (+0x0C) and optionally nPeriodCounter
   (+0x10).

   Parameters:
     this (ECX): CVOGHBBase* [API shows void*]
     nPeriodSentinel: value written to +0x0C
     bAlsoSetCounter: if true also write +0x10

   Algorithm: combat pool passes (-1000, true) for always-ready reschedule mode.

   Returns: void */

void __thiscall CVOGHBBase_SetPeriodAndCounter(void *this,int nPeriodSentinel,bool bAlsoSetCounter)

{
  *(int *)((int)this + 0xc) = nPeriodSentinel;
  if (bAlsoSetCounter) {
    *(int *)((int)this + 0x10) = nPeriodSentinel;
  }
  return;
}
```

## Machine decode (from `read_memory`; not disassemble_bytes)

```
80 7C 24 08 00    cmp  byte ptr [esp+0x8], 0
8B 44 24 04       mov  eax, [esp+0x4]
89 41 0C          mov  [ecx+0x0C], eax
74 03             jz   skip
89 41 10          mov  [ecx+0x10], eax
C2 08 00          ret  8
```

## Open questions

- Unify `+0x0C` name (`nPeriodMs` vs `nPeriodSentinel`) vs GetRemaining’s `+0x08` period.
- Live callers with `bAlsoSetCounter == false` (if any).
