# Annotated low-level: CVOGObjectiveRequirement_Patrol_Eval

| Field | Value |
|---|---|
| Stable ID | `aa_0060e0f0` |
| VA | `0x0060e0f0` |
| System | missions-progression |
| Date | 2026-07-23 (residual notes 2026-07-29) |

## Machine-level notes

- Source: raw capture for `aa_0060e0f0`.
- Prefer assembly when decompiler conflicts.
- `req+0x24` sealed as **Laps** (GetFlags `<Laps>` + image push `[esi+0x24]`).
- `req+0xd0` sealed as **target/waypoint count**.
- Slot float is **absolute pad count**, compared as float to int product.
- Image: `imul` product, `cvtsi2ss`, `comiss` slot vs product, `jb` → incomplete, `ret 8`.

## Pseudocode (annotated copy of raw)

```c
undefined4 __thiscall
CVOGObjectiveRequirement_Patrol_Eval(int param_1,undefined4 param_2,int param_3)

{
  if ((float)(*(int *)(param_1 + 0xd0) * *(int *)(param_1 + 0x24)) <=
      *(float *)(param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4)) {
    return 1;
  }
  return 0;
}
```

## Open questions

- Runtime / bit-exact still open.
- Server NeededCount zero-edge normalize vs raw product (port note).
