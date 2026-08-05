# Review B (skeptical / adversarial): `aa_005d7f70` CVOGHBAICreatureBase_DoLogic

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d7f70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W25-J) |
| **Counterpart** | `reviews/A_aa_005d7f70_CVOGHBAICreatureBase_DoLogic.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs/vtbl). No `disassemble_bytes`. Own VA `0x005d7f70` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Same body as Driver DoLogic | no FireWeapons; DoCreaturePursue vs DoVehiclePursue/ReturnToNormal | **Falsified identity** — **creature twin, not alias** |
| 2 | Free function / static | `mov esi,ecx`; DATA vtbl slot | **Falsified** — **virtual thiscall** |
| 3 | Class is Driver | sibling vtbl `DecideHeading` plate `CVOGHBAICreatureBase::…` | **Falsified** — **CreatureBase** |
| 4 | Method name proven as DoLogic | no local string | **Survives only as Probable** |
| 5 | Always pursues | combat path requires target `+0xa0` and helper gates | **Falsified** — gated |
| 6 | Profile miss continues | early `return` on end iterator | **Falsified** — hard out |
| 7 | `AI_CheckSlotTimerReady` 3-arg | sealed sibling RET 4; unaff_EDI noise | **Falsified decomp arity** — **1 stack index** |
| 8 | Three-rep diverges | live ≡ raw CF; entry/tail bytes match | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall void + state 0/1/other | **High** | wrong AI port |
| Class CreatureBase | **High** | wrong type ownership |
| Method English DoLogic | **Probable** | rename if plate found |
| Profile dword meanings | **Low–Partial** | wrong flee/engage tuning |
| Shared helper product names | **Partial** | incomplete call graph docs |
| Runtime / bit-exact | **Open** | shipping parity |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  profile lower_bound; if end → return
  owner+0x26c == 0 / == 1 / else
  NPC_TryCastSkillFromSet(0|1|2)
  AI_CheckSlotTimerReady → vtbl actions
  combat: RNG * 1/65536 vs profile floats; DoCreaturePursue
  engage: timer + HP promote

bytes:
  83 EC 0C 53 55 56 8B F1 …
  8B 46 64 …
  … 5F 5E 5D 5B 83 C4 0C C3
  DAT_00aaa638 ≈ 1/65536; _DAT_00aaa5dc = 2^32
vtbl:
  009db194 = DecideHeading; 009db19c = this
```

**No conflict** on owned ABI/CF/class. Method English remains Probable (not string-sealed).

---

## 4. Surviving contract for AutoCore

```csharp
// CVOGHBAICreatureBase_DoLogic @ 0x005d7f70
// retail: ECX=this, bare ret, void; virtual via creature vtbl

void DoLogic(HBAICreature self)
{
  // Lookup profile by def float; state machine on owner.CombatState;
  // cast skill sets; pursue / leash; no vehicle FireWeapons.
}
```

Port rules:

- Do **not** merge with `CVOGHBAIDriver_DoLogic` — different pursue + no weapon tail.
- Keep **profile miss → return** (silent no-op tick).
- Treat `owner+0x26c` as the same idle/engage/combat byte family as Driver duals.
- Skill-set indices **0/1/2** must match `NPC_TryCastSkillFromSet` banks.
