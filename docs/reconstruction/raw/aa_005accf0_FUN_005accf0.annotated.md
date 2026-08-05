# Annotated low-level: FUN_005accf0 → CrazyTaxi_AccumulateLegTime

| Field | Value |
|---|---|
| Stable ID | `aa_005accf0` |
| VA | `0x005accf0`–`0x005acee7` exclusive (**503 B**); plate max `005acee6` |
| System | `CVOGObjectiveRequirement_CrazyTaxi` |
| Date | 2026-07-29 (W30-M seal) |

## Machine-level notes

- **ABI:** `__thiscall` ECX = CrazyTaxi req; five stack args; **`ret 0x14`** (`c2 14 00`); return float in x87.
- **Constants:** `DAT_00aaa688` = **5.0f** (`00 00 a0 40`).
- **this+0x4c:** TFID array (8 B/elem) — `GenericTargetCOID` stops.
- **this+0x8c:** TimeLimit map **head*** (size @ +0x90); Val12 isnil@+0x19; Stops key@+0x0C; Percent float@+0x14.
- **actor+0x250:** indirection chain to continent/map **scale** float @ +0x634.
- **fromIndex &lt; 0:** actor dual-base **GetPos** vtbl +0x1a0 → float3*.
- **Callees:** `FUN_004bb1c0` TFID resolve; `FUN_005ae050` Val12 Dec; `SQRT`.
- **Callers:** **none static** (full-image E8 + ptr scan).
- Live decompile **≡** raw body (W30-M). **No** `disassemble_bytes`.

## Pseudocode (annotated)

```c
float10 __thiscall FUN_005accf0(
    CrazyTaxi* this, Actor* actor, int stopsKey,
    float acc, int fromIndex, int toIndex)
{
  float scale = /* actor+0x250 → … → +0x634 */;
  float3 src;
  if (fromIndex < 0)
    src = *actor->GetPos();              // vtbl+0x1a0
  else {
    obj = ResolveTFID(this->targets[fromIndex]);
    if (obj) src = obj->worldPos;        // dual+0x84
  }
  dest = ResolveTFID(this->targets[toIndex]);
  if (dest) {
    d = src - dest->worldPos;
    // Val12 lower_bound on TimeLimit map (this+0x8c) by stopsKey
    // if result != begin: Dec (predecessor)
    dist = SQRT(dot(d,d));
    if (it == head) dist = dist / scale;
    else            dist = (dist / scale) * it->percent;  // +0x14
    acc += dist;
  }
  if (stopsKey < 1) acc += 5.0f;         // DAT_00aaa688
  return acc;                            // ret 0x14
}
```

## Open questions

- Product method name / demangle.
- Why zero static refs (dead vs dynamic).
- Exact TimeLimit bracket policy after Dec.
- Runtime / bit-exact / differential.
