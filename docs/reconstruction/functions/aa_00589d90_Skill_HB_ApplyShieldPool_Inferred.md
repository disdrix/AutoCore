# Function record: Skill_HB_ApplyShieldPool_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00589d90` |
| **Canonical name** | `Skill_HB_ApplyShieldPool_Inferred` |
| **Ghidra name** | `FUN_00589d90` |
| **Address** | `0x00589d90`–`0x00589e5c` inclusive (**205 B** / `0xCD`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Partition** | MEGA-007 (parent dual context `0x0061b6f0`) |
| **Completion status** | **Dual sealed** — accept-with-gaps (MEGA-007 2026-08-05) |
| **Bit-for-bit / runtime / diff** | Open (Terminal false; no Launcher) |

## Purpose

Apply a skill-HB shield-pool mutation: resolve combat host → vehicle combat pool → add (or fractional) delta to current shield, clamp to max, return actual change.

## Signature (sealed)

```c
// cdecl; bare RET; EAX = applied delta (0 if unchanged/unresolved)
int Skill_HB_ApplyShieldPool_Inferred(
    int *fallbackHost,     /* [ESP+4]  */
    int *preferredHost,    /* [ESP+8]  */
    float amount);         /* [ESP+0xC] */
```

## Sealed facts

1. Body `0x00589d90`–`0x00589e5c` (**0xCD** B); pad `CC`.
2. cdecl three stack args; bare `RET`; callers `ADD ESP,0xC`.
3. Resolve: preferred `vtbl+0x19c` → MI component; else preferred `+0xAC`; else fallback same path; then `vtbl+0x1d4` → pool.
4. Amount ∈ [`DAT_00aaa668`=-1.0f, `g_flOne`=1.0f] → `(int)(max * amount)`; else `(int)amount`.
5. Store clamp(cur+delta, 0, max) at pool `+0x144`; max at `+0x148`.
6. Return `new - cur` if changed else 0.
7. Callers: `FUN_0061b6f0`, `FUN_00618270`, orphan `0x0061be96`.
8. Field plate shared with `Vehicle_SetCurrentShield` (`0x00419140`) — different ABI/role.

## Gaps

- Product / PDB symbol.
- Virtual slot English (`+0x19c`, `+0x1d4`).
- Orphan call-site function plate.
- Runtime / bit-exact / differential.

## Artifacts

- Raw (+ re-verify): `docs/reconstruction/raw/aa_00589d90_FUN_00589d90.md`
- Annotated: `docs/reconstruction/raw/aa_00589d90_FUN_00589d90.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Skill_HB_ApplyShieldPool_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00589d90.cpp`
- FUN record: `docs/reconstruction/functions/aa_00589d90_FUN_00589d90.md`
- A: `docs/reconstruction/reviews/A_aa_00589d90_Skill_HB_ApplyShieldPool_Inferred.md`
- B: `docs/reconstruction/reviews/B_aa_00589d90_Skill_HB_ApplyShieldPool_Inferred.md`
- Report: `docs/agents/task-dual-ab-00589d90-mega-007-report.md`

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / clamp / return delta | **Confirmed** |
| Skill-HB consumer role | **Confirmed** (parent call sites) |
| Shield pool semantics | **High** (field plate + family) |
| Product English | **Inferred** |
| Runtime | Open |
