# Function record: CVOGHBMissionEscort_ReactionFactory_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060c860` |
| **Canonical name** | `CVOGHBMissionEscort_ReactionFactory_Inferred` |
| **Ghidra name** | `FUN_0060c860` |
| **Address** | `0x0060c860`–`0x0060c991` (**306 B** / `0x132`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression / heartbeat |
| **Completion status** | **partial** — dual A/B **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open |
| **Dual A/B** | `A_aa_0060c860_…`, `B_aa_0060c860_…` |
| **Last reviewed** | `2026-08-04` (WQ9H-E OWN-ONLY) |

## Alias

- `FUN_0060c860`

## Purpose

Primary **factory/new path** for `CVOGHBMissionEscort` from a reaction context: gates, skill resolve/cast, score stamp, then allocate **0x78**, construct via dualed ctor, enqueue onto owner HB list (`+0xe4ec`), and Start. Complements dualed `CVOGHBMissionEscort_ctor` / `CVOGHBMissionEscort_OnHeartBeat`.

## Signature (sealed)

```c
bool __thiscall CVOGHBMissionEscort_ReactionFactory_Inferred(
    void *reqHost, void *ownerCtx, float *scoreFloats); // ret 8
```

## Algorithm

1. Resolve `ownerObj` from `ownerCtx`; require enable `@+0x7e` and key match.
2. Resolve skill targets; fail → false.
3. Optional cast; fail → delete targets, false.
4. Write `g_flOne` into score slot.
5. If spawn gate + target dword `@+0x14c != -1`: `new(0x78)` + ctor + Enqueue + Start (null mem preserved).
6. Delete targets; return true.

## Related

- `aa_006507c0` `CVOGHBMissionEscort_ctor`
- `aa_006508d0` `CVOGHBMissionEscort_OnHeartBeat`
- Reaction helpers `CVOGReaction_*` (not OWN)

## Artifacts

- Raw / annotated / clean / dual A/B — see FUN twin record + agent report
