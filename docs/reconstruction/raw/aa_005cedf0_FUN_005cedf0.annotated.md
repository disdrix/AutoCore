# Annotated low-level: CVOGHBAI_UpdateAimOffset_Inferred (FUN_005cedf0)

| Field | Value |
|---|---|
| Stable ID | `aa_005cedf0` |
| VA | `0x005cedf0`–`0x005cf558` (1897 B) |
| Canonical name | `CVOGHBAI_UpdateAimOffset_Inferred` |
| Ghidra name | `FUN_005cedf0` |
| System | HB AI aim-offset state |
| Date | 2026-07-29 (W26-O seal) |

## Machine-level notes

- **ABI:** ECX = this (AI aim helper); void; plain `RET` after frame teardown.
- **Worker:** multi-callee; random draws; quat transform.
- **Name evidence:** stores/compares aim vec4; fallback global `g_abInferredDefaultAimPos`; called from Driver/Creature DoLogic + OnHeartBeat.
- **Inferred** suffix: no retail string plate for this VA; structural role sealed.

## Stage map

| Stage | Condition | Action |
|---|---|---|
| Fail owner/phys | null chain | clear flag+ts; return |
| Active TTL | flag && elapsed>6 | clear flag+ts |
| Active near | flag && elapsed≤6 && near stored | clear flag+ts |
| Active far | flag && elapsed≤6 && far | keep flag; continue |
| Not candidate | phys active / moving / no combat flags | if !flag: ts=0; return |
| Moving | still vs last fails (eps 0.05) | if !flag: ts=0; return |
| No pose drift | active-pose abs all ≤1 | if !flag: ts=0; return |
| Arm wait | pose drift && ts==0 | ts=now; return |
| Hold | pose drift && flag | return |
| Hold wait | pose drift && elapsed≤1.5 | return |
| Build offset | pose drift && elapsed>1.5 | flag=1; random local→world aim; return |
| Bad finite | build path non-finite | default aim pos; return |

## Open questions

- Product English / exact class name of `this` beyond AI helper.
- Consumer of `this+0x40` aim vec (shoot/look tick — out of OWN).
- Nested callees `FUN_005d1d20`, `FUN_005d6870` full duals (not OWN).
- Runtime RNG stream bit-exact — open.
