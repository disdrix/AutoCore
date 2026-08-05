# Review B (skeptical / adversarial): `aa_00530550` CVOGCharacter_AwardMedalById

| Field | Value |
|---|---|
| **Stable ID** | `aa_00530550` |
| **VA** | `0x00530550` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00530550_CVOGCharacter_AwardMedalById.md` |
| **System** | `missions-progression` |
| **Verdict** | **accept-with-gaps** on CF/ABI; **needs-more-evidence** on product medal ownership model + chain helper |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function stores medal permanently in a medal inventory | Body only notify + dirty + optional chain | **Overstated** if claimed ownership insert |
| 2 | Single lookup sufficient | Two CALLs both executed on success | **Falsified** as noise — dual lookup real |
| 3 | `FailMissionNotify` means mission failed | Called on **award success** path | **Name inflation** — vector push reused |
| 4 | Free function / no this | `MOV ESI,ECX`; `RET 4`; dirty on ESI | **Falsified** |
| 5 | Return void | `MOV AL,1` / `XOR AL,AL` | **Falsified** |
| 6 | Always chains `FUN_005304a0` | Gated on def+0x14 != -1 | **Falsified** |
| 7 | Clean invents CF | Scaffold matches raw | **Survives** as CF-faithful |
| 8 | Only CompleteObjective calls it | xrefs also `FUN_0080ce50`, others | **Survives as multi-caller** |
| 9 | Dirty `\|0x20` is generic mission dirty | CompleteObjective also uses `\|0x10`, `\|1` elsewhere | **Survives** as **distinct bit** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Lookup gate + return 0/1 | **High** | Silent award fail |
| Notify + dirty order | **High** | UI desync |
| thiscall / RET 4 | **High** | Wrong stack on port |
| Medal id at obj+0x100 | **High** | Wrong award source |
| Permanent medal grant location | **Low** | Missing server/hash port |
| Chain helper meaning | **Tentative** | Wrong skill rank side effect |
| Product symbol | **Tentative** | Cosmetic |

---

## 3. Cross-check

Live listing 2026-07-29 matches raw body. Call site `0x0053421d` packs `obj+0x100` and character this. Toast path independently treats same id as medal string key — strengthens **medal** English without sealing ownership storage.

---

## 4. Surviving contract for AutoCore

```
// Port as award-attempt with notify, not as full medal inventory system.
// Return ignored at CompleteObjective site (no TEST AL after CALL).
// Do not skip notify when chain is -1 — chain is optional after notify/dirty.
// Dirty bit 0x20 is separate from credits |1 and objective |0x10.
```

## 5. What would overturn

1. Proof medals are stored only server-side and this unit is pure UI.
2. Different ECX at any call site (non-character).
3. Image change at VA.
