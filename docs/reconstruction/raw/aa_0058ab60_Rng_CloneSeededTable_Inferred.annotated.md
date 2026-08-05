# Annotated low-level: Rng_CloneSeededTable_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_0058ab60` |
| VA | `0x0058ab60` |
| System | `skills-abilities` (global RNG helper) |
| Date | `2026-07-29` (dual A/B) |
| Canonical | `Rng_CloneSeededTable_Inferred` (was `FUN_0058ab60`) |

## Machine-level notes

- Source: raw capture for `aa_0058ab60` + live re-decompile 2026-07-29.
- **cdecl**, one stack arg (seed index), return EAX = heap `uint32_t*` (`0x4b0` bytes).
- Global RNG singleton: `CVOGReaction_RandomUnitScalar()` → `&DAT_00d20c1c`.
  - `+0x08` table base (`new[] 0x200000` from `FUN_007a4200`)
  - `+0x0C` cursor (ushort index into table)
- Source pointer: `table + cursor * 2` then 300-dword copy → 600 ushort window.
- Wrap: `if (cursor + 600 > 0xFFFFF) cursor = 0`.
- Side effect: `cursor += 1` after copy.
- Consumers often cast return to `uint16_t*`; HB stores at `+0x6a0` with seed at `+0x6a8`.

## Pseudocode (annotated)

```c
// __cdecl
uint32_t * Rng_CloneSeededTable_Inferred(uint32_t seedIndex /* param_1 */)
{
  uint32_t *heap;      // puVar1 — operator_new[](0x4b0)
  int rng;             // iVar2 — &DAT_00d20c1c as int
  int n;               // iVar3 — copy countdown 300
  uint32_t *src;       // puVar4
  uint32_t *dst;       // puVar5

  heap = operator_new__(0x4b0);                    // 300 dwords / 600 ushorts
  rng = CVOGReaction_RandomUnitScalar();
  *(uint32_t *)(rng + 0xc) = seedIndex;            // force cursor = seed
  rng = CVOGReaction_RandomUnitScalar();
  if (0xfffff < *(int *)(rng + 0xc) + 600) {       // need 600 ushort headroom
    *(uint32_t *)(rng + 0xc) = 0;
  }
  // ushort index → byte offset; then read as dwords
  src = (uint32_t *)(*(int *)(rng + 8) + *(int *)(rng + 0xc) * 2);
  dst = heap;
  for (n = 300; n != 0; n = n + -1) {
    *dst = *src;
    src = src + 1;
    dst = dst + 1;
  }
  *(int *)(rng + 0xc) = *(int *)(rng + 0xc) + 1;   // advance global cursor by 1 ushort
  return heap;
}
```

## Open questions

- Product / PDB name (keep `_Inferred`).
- Free site for HB-held clone (`hb+0x6a0`).
- Names of 3 orphan CALL parents (`0x0054ef92`, `0x0061e909`, `0x0061ea62`).
