# Review B (skeptical / adversarial): `aa_00606d70` Outpost_CastSkillsForFaction

| Field | Value |
|---|---|
| **Stable ID** | `aa_00606d70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00606d70_Outpost_CastSkillsForFaction.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is a client UI cast / C2S 0x2030 path | No RequestCastSkill; callees are Resolve* + ValidateTarget + CastSkillOnTarget packer | **Falsified** — reaction/sim cast path |
| 2 | Emits S2C 0x2031 on the wire | Downstream `CastSkillOnTarget` dual: **no network in unit** (resolve/apply/heap only) | **Falsified as wire emit** — packs/applies locally only inside callee |
| 3 | Casts for all 4 factions every call | `factionIndex` gated `[0,3]`; single bank `this+index*0x48` | **Falsified** — one faction per call |
| 4 | Object list is per-faction | Objects always from `this+0x228/22c`; only skills are per-faction | **Falsified** — shared object pool |
| 5 | Disabled skills still cast | `*(char*)(entry+0x0C)==0` continues without resolve | **Falsified** |
| 6 | Unlimited multi-target list | Flush when count `> 0x62` (99); stack 100 TFID slots | **Falsified** — hard batch cap |
| 7 | Terminator is zero TFID | `read_memory` `DAT_009de7d8` = `ff×8 + 00×8` | **Falsified as zero** — `{-1,-1,0,0}` |
| 8 | `operator_delete` aborts function (noreturn) | Same false warning class as CastSkillOnTarget dual; bank walk continues after free | **Falsified as noreturn** |
| 9 | BeaconShare is the same function | Sibling uses different object source (`bank+0xb4`), ResolveObjectTarget type **0**, extra vehicle/CS walk, float gate @ entry+8 | **Distinct** |
| 10 | Finished bit-exact / runtime proven | Static decompile + constants only | **Overstated** if claimed finished |
| 11 | Decomp is register-faithful for multi-skill | `iVar4`/`param_1` reused for bank base, batch count, source adjust | **Overstated** — merge hazard; algorithm still recoverable |
| 12 | `"Invalid…"` only on failure | Decomp places log after success free as well; skillId may be clobbered by object-loop `puVar3` | **Unsealed polarity** — do not claim product logging policy |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Capture-only sole caller | **High** | Miss other faction-cast entry |
| Faction `[0,3]` + bank stride `0x48` | **High** | Wrong bank / OOB |
| Skill stride 0x10 / enable `@+0xC` / id `@+0` | **High** | Cast disabled or wrong skills |
| Object stride 8 / resolve type 1 | **High** | Wrong target set |
| ValidateTarget notify 0 | **High** | HB attach side effects |
| Batch 99 + `{-1,-1,0,0}` terminator | **High** | Buffer overrun / endless targets |
| Aim zero + statusC 0 + charge 0 | **High** | Wrong packer fields |
| Rank = entry+4 byte as rankPacked | **Medium** | Wrong skill rank on cast |
| Invalid log only on miss | **Low–Medium** | Noise vs real failure telemetry |
| Decomp multi-skill var merge | **Medium** algorithm / **Low** naive port | Second skill bank walk broken if port copies decomp vars |
| World/this ECX into CastSkillOnTarget | **Medium** | Missing world gate `+0x7e` if ECX wrong |

---

## 3. Cross-check against raw / siblings

| Check | Result |
|---|---|
| Raw `aa_00606d70` body ≡ live decompile | **Match** |
| Clean scaffold CF ≡ raw | **Match** (scaffold naming) |
| Sibling BeaconShare batch/terminator/Cast args | **Same** 99 / `DAT_009de7d8` / aim zeros / extra `-1` |
| Sibling skill bank base `this+faction*0x48+0xd4` | **Same** |
| Sibling object source | **Different** (`+0xb4` per bank vs shared `+0x228`) |
| Capture caller passes race as faction | **Match** (`local_28` root race) |
| ResolveSkillTargets dual (0x630, rank @ +0x5f6) | **Consistent** with free+delete of `skill` |
| ValidateTarget dual lists this site `0x00606EB6` notify 0 | **Match** |

---

## 4. Surviving contract for AutoCore

```
// On capture → newFaction in [0,3], world.flag(+0x7e) already checked by caller
void Outpost_CastSkillsForFaction(Outpost* op, int faction)
{
  if (faction < 0 || faction > 3) return;
  var objects = op.ObjectRefs;           // +0x228/+0x22c, stride 8
  if (objects empty) return;

  var skills = op.FactionSkillBank[faction]; // base op+faction*0x48, vec +0xd4/+0xd8, stride 0x10

  foreach (entry in skills) {
    if (!entry.Enabled) continue;        // +0x0C == 0
    var skill = ResolveSkillTargets(entry.SkillId, entry.Rank); // +0 / +4
    if (skill == null) {
      Log(1, "Invalid outpost skill cast for skill %d, map: %s", entry.SkillId, mapName);
      continue;
    }

    TFID batch[100]; int n = 0;
    foreach (oref in objects) {
      var obj = ResolveObjectTarget(type:1, oref.a, oref.b);
      if (obj == null) continue;
      if (!ValidateTargetForSkill(skill, obj, notify:false)) continue;
      batch[n++] = obj.TFID;             // +0x160
      if (n > 99) {                      // 0x62
        batch[n] = Terminator_FF_FF_0_0;
        CastSkillOnTarget(skill, op.AsSourceEntity(), null, list:batch,
                          aim:Zero, hasExtra:false, extra:0xFFFFFFFF,
                          statusC:false, charge:0);
        n = 0;
      }
    }
    if (n > 0) {
      batch[n] = Terminator_FF_FF_0_0;
      CastSkillOnTarget(...same...);
    }
    delete skill;                        // free 0x630
    // logging polarity after success: OPEN — do not require always-log
  }
}
```

**Do not:**

- Treat as C2S 0x2030 UI cast.
- Assume S2C emit inside this unit or inside CastSkillOnTarget.
- Share BeaconShare's object list (`+0xb4`) or ResolveObjectTarget type 0.
- Port decompiler variable reuse (`param_1`/`iVar4`) literally.
- Claim bit-exact / runtime without capture.

---

## 5. Open questions

1. Exact product English for object-vector entries at `+0x228` (players? beacons? all map objects?).
2. Rank field width (u8 vs u16) and whether high bits of decomp `CONCAT22` ever matter.
3. Whether Invalid log is miss-only or always-on at level 1.
4. Whether CastSkillOnTarget receives world in ECX from a hidden register (caller-side `+0x7e` already gated in CaptureOutpost).
5. Runtime observation of multi-skill multi-batch casts on capture.

**Verdict:** **accept-with-gaps** — adversarial checks leave core algorithm + layouts intact; log polarity and decomp merge are the main residual traps.
