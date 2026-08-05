# Review B (skeptical / adversarial): `aa_006070e0` Outpost_CastSkillsForBeaconShare

| Field | Value |
|---|---|
| **Stable ID** | `aa_006070e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_006070e0_Outpost_CastSkillsForBeaconShare.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Generic “outpost skill cast” identical to faction path | Flag polarity inverted; ratio gate; different TFID list + Resolve mode 0 vs 1; nested CS walk | **Distinct product path** — beacon-share, not faction mirror |
| 2 | Name overclaims “beacon” without evidence | Sole caller `FUN_006078e0` writes `+0x24c = factionBeacons/totalBeacons` then calls this only when ratio **changes**; gate compares entry float to `+0x24c` | **Name justified** (share ratio, not raw beacon count) |
| 3 | Processes every bank skill | Skip when `flag(+0xC)!=0` **or** `ratio < threshold` | **Filtered** |
| 4 | Flag+0xC means “enabled” like faction | Faction processes flag≠0; beacon processes flag==0 | **Polarity inverted** — do not share one English name without evidence |
| 5 | Targets = global outpost list `+0x228` | Beacon uses `factionBase+0xb4/0xb8` only; no `+0x228` gate | **Falsified** for this unit |
| 6 | `ResolveObjectTarget(0,…)` same as faction | Faction passes **1** | **Mode differs** — product filter residual |
| 7 | Invalid log only on resolve failure | Decompile places log after `if (skill)` block; Ghidra marks `operator_delete` noreturn | **Unresolved CF** — product intent ≈ fail path; absolute always-fire needs asm (disallowed here) |
| 8 | Stack array `aiStack_640[400]` = 400 targets | Each TFID is 4 dwords; 400 ints ⇒ 100 TFID slots; flush at >98 leaves terminator room | **~100 TFID capacity** including terminator slot, not 400 objects |
| 9 | `DAT_00d029d0` is a live aim table | `read_memory` → all zeros (static BSS) | **Zero aim / empty float3** at call time (static image) |
| 10 | Unit emits network skill packets | Only `CastSkillOnTarget` (dual: local 0x2031 pack, no wire in that unit) | **No direct wire** here |
| 11 | `CONCAT22` high word is product skill level | High half comes from skill-bank **pointer** upper bits | **Decompiler artifact** — seal low byte of entry+0x4 only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + factionIndex [0,3] | **High** | Cast wrong faction bank |
| `+0x24c` ratio vs entry `+0x8` | **High** | Wrong share unlock curve |
| Flag skip polarity (0 process) | **High** | Cast opposite skills vs retail |
| Per-faction TFID list +0xb4 | **High** | Wrong targets |
| Resolve mode **0** | **High** static / residual English | Wrong object class filter |
| Batch flush `> 0x62` + FFFF terminator | **High** | Truncate / infinite cast |
| Nested vfunc `+0x1ec` / `+0x1d8` / `+0x250` | **Low** names | Miss occupant/filter semantics |
| Invalid log after free | **Medium** | Spam vs silent success |
| CastSkillOnTarget full ABI mapping | **Medium** (sibling dual) | Wrong source/aim/extra |

---

## 3. Cross-check raw ≡ live decompile

Live `decompile_function(0x006070e0)` matches raw body structure:

- faction bound check
- bank walk `+0xd4/+0xd8` stride 0x10
- skip OR of flag and strict-less ratio
- ResolveSkillTargets → nested for on `+0xb4/+0xb8`
- mode-0 ResolveObjectTarget
- vfunc/CS/Validate/batch/Cast/delete/log

Sibling `00606d70` confirms shared cast/batch/terminator/invalid string; **differences above are intentional**, not decompiler noise.

Caller `006078e0` seals when this runs: **only on ratio change** after recompute (not every tick).

---

## 4. Surviving contract for AutoCore

```
// When outpost beacon share ratio changes (caller), for faction f in 0..3:
void Outpost_CastSkillsForBeaconShare(Outpost op, int factionIndex):
  if factionIndex not in [0,3]: return
  base = op + factionIndex * 0x48
  ratio = op.beaconShareRatio   // +0x24c
  for entry in skillBank(base+0xd4, base+0xd8, stride=0x10):
    if entry.flag != 0: continue
    if ratio < entry.minRatio: continue
    skill = ResolveSkillTargets(entry.skillId, entry.rankByte)
    if skill is null:
      LogInvalid(entry.skillId, mapName(op)); continue
    batch = []
    for tfid in tfidList(base+0xb4, base+0xb8, stride=8):
      obj = ResolveObjectTarget(mode=0, tfid)
      if !obj: continue
      // residual: expand via vtbl+0x1ec container + CS iterator
      // residual: filter vtbl+0x1d8 / +0x250
      for entity in expanded(obj):
        if ValidateTargetForSkill(skill, entity, null):
          batch.append(entity.tfid)  // +0x160
          if len(batch) > 0x62:
            CastSkillOnTarget(skill, op.asSource, batch+terminator, aimZero, extras…)
            batch.clear()
    if batch: CastSkillOnTarget(...)
    delete skill
```

**Do not** port as copy of `Outpost_CastSkillsForFaction` without mode/list/flag/ratio deltas.

---

## 5. Falsifiers for future duals

1. Live capture: ratio change fires bank casts with mode-0 targets only.
2. WAD/data: entry `+0xC` meaning (spent vs disabled vs “beacon-only”).
3. Asm: whether invalid log executes after successful free.
4. Product names for vfuncs `+0x1ec`, `+0x1d8`, field `+0x250`.
