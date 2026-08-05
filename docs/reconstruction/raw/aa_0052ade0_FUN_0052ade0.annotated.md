# Annotated low-level: FUN_0052ade0 → CVOGCharacter_SetMissionCounterMax_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0052ade0` |
| VA | `0x0052ade0`–`0x0052ae21` (66 B / 0x42) |
| System | `missions-progression` (Val12 map @ char+0x584) — **mission-adjacent** |
| Date | 2026-08-04 (W37-P dual) |
| Named | `CVOGCharacter_SetMissionCounterMax_Inferred` |

## Machine-level notes

- **thiscall** ECX=Character*; stack `(key, value)`; void; **`RET 8`**.
- Find only via `FUN_00418b80` lower_bound on map **`char+0x584`**; compare end **`char+0x588`**.
- **Miss = pure no-op** (contrast SetMissionCounter which operator[]-inserts).
- **Hit:** write **`node+0x10 = value`**, then if **`node+0x14 < value`** clamp **`node+0x10 = node+0x14`**; **`char+0x634 |= 0x40`**.
- Sibling duals: SetMissionCounter (`005305b0`) assigns **+0x14**; AddMissionCounter (`00530610`) adds **+0x14**; GetResourceBalance (`0052ada0`) reads **+0x10**.
- Sole CODE caller: debug `adddisciplinepoints` optional third-token path (W31-T) — help text "set max as well".

## Sealed pseudocode

```c
void __thiscall CVOGCharacter_SetMissionCounterMax_Inferred(
    int character /*ECX*/, uint32_t key, int32_t value)
{
  int node = character;
  FUN_00418b80(character + 0x584, &node, &key);
  if (node == *(int *)(character + 0x588))
    return; /* miss: no insert */
  *(int32_t *)(node + 0x10) = value;
  if (*(int32_t *)(node + 0x14) < value)
    *(int32_t *)(node + 0x10) = *(int32_t *)(node + 0x14);
  *(uint32_t *)(character + 0x634) |= 0x40u;
}
```

## Open questions

- Product English: "max" is **inferred** from slash help; dual-field policy (+0x10 vs +0x14) still open across Get/Set family.
- Whether any non-debug caller exists outside current xref set.
- Runtime / bit-exact.
