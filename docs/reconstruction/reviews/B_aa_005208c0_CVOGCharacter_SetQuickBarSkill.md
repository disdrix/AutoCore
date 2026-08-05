# Review B (skeptical / adversarial): `aa_005208c0` CVOGCharacter_SetQuickBarSkill

| Field | Value |
|---|---|
| **Stable ID** | `aa_005208c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual strengthen) |
| **Counterpart** | `reviews/A_aa_005208c0_CVOGCharacter_SetQuickBarSkill.md` |
| **Prior dual quality** | Thin adversarial stub (two false claims only) |
| **Verdict** | **accept** — attacks on wrong array/COID/wire closed; residual empty-sentinel + dirty-reader English open |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Writes item COID / int64 | Body stores single int32 at `+0x74c` stride 4; item path is sibling `+0x930` | **Falsified** |
| 2 | Slot unbounded / OOB write | `cmp al,0x64` / `jae` → no-op, no dirty | **Falsified** |
| 3 | Sends QuickBarUpdate / network | Zero callees; no packet builders | **Falsified** |
| 4 | Clears item when setting skill | No touch of `+0x930` array in this unit | **Falsified** (exclusivity is caller/server policy) |
| 5 | Dirty bit 2 is skill-only | Identical `\|2` in `SetQuickBarItem` | **Falsified as exclusive** |
| 6 | Empty skill must be `-1` always | Clear UI often passes `-1`; create/server empty often `0`; body stores any int32 | **Overstated** — producer-dependent |
| 7 | Empty skill must be `0` always | Same | **Overstated** |
| 8 | `slot` signed compare | Bytes: `cmp al` / `jae` = **unsigned** byte | **Falsified as signed** |
| 9 | Needs dual depth / non-trivial CF | Body ~32 B, linear guard+store+OR | **N/A complexity** — still dual-strengthened for completeness |
| 10 | Clean invented CF beyond raw | Clean ≡ raw ≡ live decomp ≡ bytes | **Falsified** |
| 11 | RET stack clean unknown | `c2 08 00` = `ret 8` | **Sealed High** |
| 12 | Shared `+0x634` is mission dirty only | Bit `0x10` used by FailMission family; bit `2` used by QB setters | **Falsified as single-purpose dword** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bounds + store address math | **High** | OOB write into character object |
| Dirty bit value `2` | **High** | Missed UI refresh / wrong flag family |
| Thiscall + `ret 8` | **High** | Stack corruption at callers |
| No network / no item side effects | **High** | Over-implement exclusivity here |
| Empty sentinel single value | **None as unit contract** | Port may normalize 0/−1 at wrong layer |
| Dirty bit English (product) | **Probable** | Wrong refresh semantics |
| Full exclusive slot policy | **N/A here** | Owned by UI/server `QuickBarUpdate` |
| Runtime / bit-exact | **Open** | Deferred |

---

## 3. Cross-check against raw / live decompile / bytes

Entire body is ~12 decompiler lines / 32 code bytes. Surviving facts after attack:

```
if (slot < 100u) {
  *(int32*)(this + 0x74c + slot*4) = skillId;
  *(uint32*)(this + 0x634) |= 2;
}
// ret 8
```

- Clean ≡ raw plate ≡ live Ghidra 2026-07-29 ≡ `read_memory` decode.
- **No** invented exclusivity clear of item COID.
- **No** invented empty validation.

---

## 4. Surviving contract for AutoCore

```
SetQuickBarSkill(char, slot:u8, skillId:i32) -> void
  if slot >= 100: return          // no dirty
  char.qbSkills[slot] = skillId   // base +0x74c, stride 4, 100 slots
  char.flags(+0x634) |= 2         // shared with SetQuickBarItem

DO NOT implement in this unit:
  - item COID clear at +0x930
  - network QuickBarUpdate 0x2062
  - empty-id enforcement (0 vs -1)
  - UI chrome rebuild

CALLER / SERVER may:
  - pass skillId=-1 on clear (QuickBar_ClearActiveSlot_INFERRED)
  - pass skillId=0 as empty on create/persist (server Character defaults)
  - send 0x2062 for persistence separately
  - apply exclusive item/skill policy at update boundary
```

**Port note:** AutoCore `Character.QuickBarSkills` is `int[100]` default 0; client clear path may write `-1` locally before persist mapping. Do not collapse both into this setter’s contract.

---

## 5. Contradictions / doc debt

| Source | Statement | This review |
|---|---|---|
| Prior Review A gap “empty 0 vs -1” | Open | **Still open as product** — sealed as *not this unit’s job* |
| Clean plate “0 or -1 = empty depending on path” | Correct as commentary | **Not a body assert** |
| `docs/skills-quickbar.md` server empty skill = 0 | Server/persist mapping | Do not force client local clear to 0 without wire evidence |
| Prior dual “not required” for trivial | Policy | Residual dual still useful for byte/offset seal |

---

## 6. Open questions

1. Full reader set of `char+0x634` bit `2` (serialize / QB UI tick).
2. Whether any login restore path writes skill empty as `-1` into `+0x74c` (vs 0).
3. Runtime golden of one assign + one clear on live character object.

---

## 7. Verdict

Attacks on COID/network/exclusivity/OOB closed hard. Kernel contract survives. Residual openness is **policy outside the store**, not CF doubt.

**Verdict: accept**
