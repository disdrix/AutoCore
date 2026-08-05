# Annotated low-level: CVOGHBBase_TryFire

| Field | Value |
|---|---|
| Stable ID | `aa_005082c0` |
| VA | `0x005082c0` |
| System | heartbeat / timed-actions |
| Date | 2026-07-29 (machine seal notes) |

## Machine-level notes

- Source: raw capture for `aa_005082c0` + live `read_memory` / pcode (2026-07-29).
- Prefer machine over decompiler for field offsets and −1000 branch target.
- **Period gate is `this+0x08`**, not `+0x0C`.
- **`+0x08 == -1000` → Continue (no OnHeartBeat)** — not “always fire”.
- Combat-pool −1000 lives at **`+0x0C`** (Reschedule / SetPeriodAndCounter).
- List_Tick calls via **vtable+0x08**; Remove when `status & 0x10`.
- Globals sealed: Remove token `0x00af19e8=16`, Inactive `0x00af19e4=2`, Continue `0x00b041d0=0`, tick `0x00b041cc`.

## Field map (this function)

| Offset | Name | Use |
|---|---|---|
| +0x08 | nPeriodMs | cmp −1000; unsigned elapsed due |
| +0x14 | dwLastFireTickMs | elapsed; stamp after fire |
| +0x20 | cStopped | → Remove |
| +0x21 | fDormant | → Inactive |

## Pseudocode (machine-aligned)

```c
uint * __thiscall CVOGHBBase_TryFire(CVOGHBBase *pThis, uint *pOutStatus)
{
  if (pThis->cStopped != 0) {                 // +0x20
    *pOutStatus = g_dwTimedActionDefaultPeriodMs; // 16 = Remove
    return pOutStatus;
  }
  if (pThis->nPeriodMs == -1000) {            // +0x08
    *pOutStatus = g_dwHBStatusContinue;       // 0 — no fire
    return pOutStatus;
  }
  elapsed = g_dwClientTickMs - pThis->dwLastFireTickMs;
  if ((uint)pThis->nPeriodMs < elapsed || g_dwClientTickMs < pThis->dwLastFireTickMs) {
    if (pThis->fDormant) {                    // +0x21
      *pOutStatus = g_dwHBStatusInactive;     // 2
      return pOutStatus;
    }
    status = *(OnHeartBeat)(pThis);           // vtbl+0x0C
    pThis->dwLastFireTickMs = g_dwClientTickMs;
    *pOutStatus = status;
    return pOutStatus;
  }
  *pOutStatus = g_dwHBStatusContinue;
  return pOutStatus;
}
```

## Open questions

- OnHeartBeat return-pointer storage across subclasses.
- Which types set `nPeriodMs(+0x08) = -1000`.
