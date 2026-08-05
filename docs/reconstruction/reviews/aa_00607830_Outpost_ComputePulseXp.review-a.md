# Review A: Outpost_ComputePulseXp

| Field | Value |
|---|---|
| Stable ID | `aa_00607830` |
| Address | `0x00607830` |
| Reviewer | Agent pass A (static) |
| Date | 2026-07-23 |

## Verdict

**Accept for static scaffold / human-refined clean.** Runtime verification still open.

## Checks

- [x] Raw capture present and not overwritten
- [x] Clean preserves control-flow order vs raw
- [x] Gate `this+0x238 < 1 → 0` matches raw
- [x] Level vtable +0x27c and dual threshold calls preserved
- [x] `Outpost_GetPulseXpPercent` + `FUN_006a3db0` call order preserved
- [ ] Runtime grant amount vs live client (OPEN)
- [ ] Confirm scalar load at `this+0x21c` in assembly (OPEN — FPU elision)

## Notes

Plate comment algorithm (levelSpan × percent × scalar, round) is consistent with sibling
`Outpost_GetPulseXpPercent` table pick. Decompiler loses intermediate FPU consumers; clean
documents them without inventing new control flow.
