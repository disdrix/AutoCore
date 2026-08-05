# Annotated low-level: CVOGObjectiveRequirement_UseItem_Eval

| Field | Value |
|---|---|
| Stable ID | `aa_0060cfe0` |
| VA | `0x0060cfe0` |
| System | missions-progression |
| Date | 2026-07-23 |
| Residual | 2026-07-29 absolute-slot + shared-index seal |

## Machine-level notes

- Source: raw capture for `aa_0060cfe0`.
- Prefer assembly when decompiler conflicts (body is trivial; no conflict expected).
- `param_1` / this = UseItem requirement*; `param_2` unused; `param_3` = active-objective state node*.
- Slot float is **absolute** use count written by `Client_RecvObjectiveState` (`0x2071`), not a client-side delta.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall
CVOGObjectiveRequirement_UseItem_Eval(int param_1,undefined4 param_2,int param_3)

{
  // (float)RepeatCount@req+0x50  <=  progress float @ state[+4 + slotIndex*4]
  // slotIndex = (byte)req+0x08  — same index SlotAction and RecvObjectiveState use
  if ((float)*(int *)(param_1 + 0x50) <= *(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4))
  {
    return 1; // complete
  }
  return 0; // still in progress
}
```

## Layout cross-ref

| Offset | Field | Consumer |
|---|---|---|
| `req+0x08` | slot index (byte) | Eval, SlotAction, FirstStateSlot / XML `slot` |
| `req+0x50` | RepeatCount (int) | Eval threshold; SlotAction required display |
| `state+4+slot*4` | progress float | written absolute by Recv `state[1..4]` ← packet `+0x18..+0x24` |

## Open questions

- ~~Confirm calling convention / signature~~ — thiscall; third arg state (High).
- ~~Absolute vs delta on 0x2071~~ — **sealed absolute** (residual 2026-07-29).
- ~~Same slot as SlotAction / Recv~~ — **sealed** (residual 2026-07-29).
- Runtime multi-use packet capture (open).
