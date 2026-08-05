# Annotated: Deliver OnInventoryEvent (`aa_00611290`)

## Behavior

On inventory **event type 4** (`param_4==4`): if character has cargo grid (`char+0x250→+0x2b0`), count items with CBID `req+0x10` via `CountItemsByCbid(..., includeBroken=0)`. If event id `(int)param_5` equals deliver target id `req+0x18` **and** quantity gate passes, write progress slot float **1.0** (`g_flOne`) and optional toast when `req+0x22 != 0`.

**Quantity gate (sealed polarity):**

```text
(*(req+0x14) <= count) || (*(char*)(req+0x23) == 0)
```

- `+0x23 == 0` → **bypass qty** (id match + event type + cargo still required)
- `+0x23 != 0` (Deliver ctor default **1**) → enforce need ≤ count
- Same OR as CargoReady `0x00610f20`. **Not** “skip when flag set.”

**Identity:** Deliver req type **3** (ctor `0x00610bc0`, vtable `009e0f24+0x04`). **Not** Collect. Do not call this “Collect type-4” (UF-014: event type 4 ≠ Collect).

## Offsets

| Offset | Role |
|-------:|------|
| +0x08 | slot index byte |
| +0x0c | req type (**3** Deliver) — set by ctor, not this body |
| +0x10 | item CBID to count |
| +0x14 | needed count |
| +0x18 | matched id (event item / deliver target) |
| +0x22 | toast enable |
| +0x23 | require-count / enforce-qty (1=enforce; **0=bypass count**) — raw `== '\0'` ORs with need≤count |

## Confidence

| Claim | Level |
|---|---|
| Uses CountItemsByCbid cargo, includeBroken=0 | **High** |
| eventType==4 only | **High** |
| `+0x23==0` qty bypass polarity | **High** (body + CargoReady + ctor default 1) |
| Not Collect / UF-014 | **High** |
| Name Deliver_* | **Probable** (family/vtable; keep `_Inferred`) |
| event type 4 enum name | **Open** |
