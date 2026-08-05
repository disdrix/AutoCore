# Review B (skeptical / adversarial): `aa_006078e0` Outpost_UpdateBeaconShareRatio

| Field | Value |
|---|---|
| **Stable ID** | `aa_006078e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W19-O) |
| **Counterpart** | `reviews/A_aa_006078e0_Outpost_UpdateBeaconShareRatio.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` (+ xrefs). No `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This function **is** the skill cast (BeaconShare) | **Falsified** — cast is `0x006070e0`; this unit only recomputes ratio and optionally **calls** cast |
| 2 | Ratio always updated | **Falsified** — total ≤ 0 path logs and **skips** store to `+0x24c` |
| 3 | Cast always runs after update | **Falsified** — only when `oldRatio != newRatio` |
| 4 | Decompiler `__fastcall` means no this | **Falsified** — `mov esi,ecx`; pure thiscall, `ret` |
| 5 | Two independent callers of cast ratio path | **Partially** — direct CODE xref only from CaptureOutpost `0x006082e0`; second xref is MI thunk `0x006079f0` into **same** body |
| 6 | Lookups write into outpost fields | **Falsified** — Lookup fills stack locals; only store is ratio `+0x24c` |
| 7 | Name could be generic "map var refresh" | **Weakened** — product string `"Total beacons was %f on map %s"` + division + consumer dual seal **beacon share** |
| 8 | `FUN_00606ff0` is optional / debug | **Falsified** — on change path always: push faction, `mov ecx,esi`, call, then BeaconShare cast |
| 9 | Division uses integer counts | **Falsified** — `divss` float path; `g_flOne`/`g_flZero` float constants |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ratio formula + store gate | **High** | wrong outpost skill thresholds |
| Change-only recast | **High** | spam casts or missed rebalance |
| thiscall / no stack args | **High** | ABI mismatch in ports |
| Map-var ids at +0x1d0 / +0xf0 | **High** (as ids); English **Medium** | wrong data source if ids mis-typed |
| Product method name | **Medium** | naming only |
| `FUN_00606ff0` meaning | **Medium** | may miss clear-before-recast side effects |

---

## 3. Cross-check against raw + bytes

```
seed total=1, factionB=0
old = this.ratio(+0x24c)
Lookup(totalId) → total
Lookup(factionBeaconId) → factionB
if total <= 0: log; return
this.ratio = factionB / total
if old != new:
  preRecast(faction)      // FUN_00606ff0
  CastSkillsForBeaconShare(faction)
return
```

Any clean that:

- folds full BeaconShare cast body into this unit, or
- stores ratio on total ≤ 0, or
- casts even when ratio unchanged, or
- treats ECX as non-this,

is **wrong**.

---

## 4. Surviving contract for AutoCore

```c
// Port sketch — outpost beacon share refresh
void Outpost_UpdateBeaconShareRatio(Outpost* self) {
  float total = 1.f, factionB = 0.f;
  float old = self->beaconShareRatio; // +0x24c
  Map_LookupVariable(self->totalBeaconsVarId, &total, 0);           // +0x1d0
  Map_LookupVariable(self->faction[self->factionIndex].beaconsVarId,
                     &factionB, 0);                                  // +0xf0 + f*0x48
  if (total <= 0.f) {
    Log(0, "Total beacons was %f on map %s", total, MapName(self));
    return;
  }
  float neu = factionB / total;
  self->beaconShareRatio = neu;
  if (old != neu) {
    Outpost_PreRecastBeaconBank(self, self->factionIndex); // FUN_00606ff0
    Outpost_CastSkillsForBeaconShare(self, self->factionIndex);
  }
}
```

---

## 5. Open questions

1. Exact product name (PDB).
2. Whether `FUN_00606ff0` clears status or applies "off" effects before recast.
3. Thunk `-0x260` secondary base type.
4. Runtime confirmation of map-var ids matching server beacon counters.

**Verdict:** **accept-with-gaps**
