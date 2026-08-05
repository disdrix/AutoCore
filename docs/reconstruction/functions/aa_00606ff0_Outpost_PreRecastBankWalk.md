# Function record: Outpost_PreRecastBankWalk

| Field | Value |
|---|---|
| **Stable ID** | `aa_00606ff0` |
| **Canonical name** | `Outpost_PreRecastBankWalk` |
| **Ghidra name** | `FUN_00606ff0` |
| **Address** | `0x00606ff0` |
| **Body range** | `0x00606ff0`–`0x006070d6` (exclusive end; **230** B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities / outpost |
| **Completion status** | **partial** — dual A/B **accept-with-gaps**; CF + ABI + layout sealed; vfunc English / runtime open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_00606ff0_Outpost_PreRecastBankWalk.md`, `reviews/B_aa_00606ff0_Outpost_PreRecastBankWalk.md` |
| **Last reviewed** | `2026-07-29` (W20-C) |

## Alias

- `FUN_00606ff0` (Ghidra)
- `Named_CalleeOf_Named_CalleeOf_CVOGReaction_Dispatch_00606ff0` (auto parent-seed — **misleading**)
- `Outpost_FactionSkillBank_InvokeV220OnTargets` (descriptive)

## Purpose

Per-faction **pre-recast / teardown skill-bank walk** on outpost:

1. Gate `factionIndex` to `[0, 3]`.
2. `factionBase = this + faction * 0x48`.
3. For each skill-bank entry (stride `0x10` at `factionBase+0xd4/0xd8`) with **`flag@+0x0C == 0`**:
4. For each TFID (stride 8 at `factionBase+0xb4/0xb8`):
5. `ResolveObjectTarget(0, lo, hi)` → `vtbl+0x1ec` container → **`vtbl+0x220(skillId, 1)`**.

No ratio gate, no `ResolveSkillTargets`, no batch `CastSkillOnTarget`. Called **before** BeaconShare recast on ratio change, and during CaptureOutpost outgoing-faction teardown.

## Signature

```c
// ECX = outpost; stack factionIndex; ret 4
void __thiscall Outpost_PreRecastBankWalk(void *thisOutpost, unsigned factionIndex);
```

## Algorithm

See annotated + clean. Sole direct callee: `CVOGReaction_ResolveObjectTarget`.

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00606ff0_FUN_00606ff0.md`
- Annotated: `docs/reconstruction/raw/aa_00606ff0_FUN_00606ff0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/Outpost_PreRecastBankWalk.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00606ff0.cpp`
- Review A/B: as above
- Report: `docs/agents/task-dual-ab-00606ff0-00424830-w20c-report.md`

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `CVOGReaction_ResolveObjectTarget` @ `0x004bae70`; virtuals `+0x1ec`, `+0x220` |
| **Callers** | `Outpost_UpdateBeaconShareRatio` (`FUN_006078e0` @ `0060799a`); CaptureOutpost (`FUN_006082e0` @ `00608543`) |

## Confidence

| Claim | Level |
|---|---|
| thiscall ECX + faction stack + ret 4 | **High** |
| factionBase +0x48; bank +0xd4; TFID +0xb4 | **High** |
| flag@+0x0C == 0 only; no ratio | **High** |
| Resolve mode 0; vfunc 0x1ec → 0x220(skillId,1) | **High** |
| Product English for +0x220 | Open |
| Runtime / bit-exact | Open |

## Related

- `aa_006070e0` Outpost_CastSkillsForBeaconShare (post-walk cast; ratio-gated)
- `aa_006078e0` Outpost_UpdateBeaconShareRatio (primary ratio-change caller)
- `aa_00606d70` Outpost_CastSkillsForFaction (different flag polarity / mode)
- CaptureOutpost `FUN_006082e0` (second caller; not dualed here)
