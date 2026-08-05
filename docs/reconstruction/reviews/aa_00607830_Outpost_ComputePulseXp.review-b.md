# Review B: Outpost_ComputePulseXp

| Field | Value |
|---|---|
| Stable ID | `aa_00607830` |
| Address | `0x00607830` |
| Reviewer | Agent pass B (independent static) |
| Date | 2026-07-23 |

## Verdict

**Concur with Review A** — human-refined clean OK for missions-progression wave.

## Independent checks

- [x] Signature `__thiscall (this, pCharacter)` matches raw
- [x] Early-out on inactive outpost state
- [x] No invented branches beyond raw
- [x] XP system tag correct (missions-progression)
- [ ] Diff vs retail EXE deferred per project policy

## Residual risk

Medium on exact float formula constants until assembly FPU sequence is reconstructed from
callees (`Experience_GetCumulativeThreshold`, `Outpost_GetPulseXpPercent`) without
`disassemble_bytes` (use decompile + `read_memory` for tables).
