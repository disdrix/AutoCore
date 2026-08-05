# Review B (skeptical / adversarial): `aa_004de9f0` CVOGReaction_RebindCreatureObjectLinks_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004de9f0` |
| **VA** | `0x004de9f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004de9f0_CVOGReaction_RebindCreatureObjectLinks_Inferred.md` |
| **System** | `missions-progression` / client world object links |
| **Verdict** | **accept-with-gaps** on CF/ABI; **needs-more-evidence** on host class English + why-rebind |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Free function / no `this` | `MOV EDI,ECX` at entry; list off EDI | **Falsified** — host thiscall |
| 2 | Decompiler `__fastcall` invents second register arg | Body uses only ECX; bare RET | **Survives as 0 stack args**; name as thiscall |
| 3 | Walks all world objects | Only `+0xe720` creature vector | **Falsified** as global walk |
| 4 | Always clears interact FX | Gated on `adj+0x134 != 0` | **Falsified** as unconditional clear |
| 5 | Always calls `FUN_004dbef0` | TFID AND==-1 or type 0x36 skip | **Falsified** |
| 6 | `FUN_004dbef0` is free / first stack = host | Call site `MOV ECX,EDI` then 5 pushes | **Falsified free**; host is ECX |
| 7 | Type 0x36 is “vehicle” | Peer SpawnObject treats 0x36 as special repair path | **Survives as skip-type only** |
| 8 | Completes objectives / grants rewards | No mission hash / medal / toast callees | **Falsified** as reward unit |
| 9 | Only CompleteObjective calls it | Also `FUN_005307e0` EndQuest | **Survives multi-caller** |
| 10 | Clean invents CF | Scaffold ≡ raw ≡ live listing | **Survives** as CF-faithful |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + list bounds | **High** | Wrong host / wrong list |
| Gate TFID & type | **High** | Wrong skip set |
| FX clear + rebind order | **High** | FX leak or missing rebind |
| Host product class name | **Tentative** | Mis-owned port module |
| Why mission-complete needs rebind | **Open** | Port may omit side effect safely or not |

---

## 3. Cross-check

Live listing 2026-07-29 matches raw pseudocode shape. Decompiler omits that `FUN_004dbef0` receives **ECX=host** (visible at `0x004dea53`). Sibling `StepCreatures` seals the same creature range offsets. Interact FX dual (`aa_005179a0`) seals clear-to-null path; adj `+0x134` ↔ object-this `+0x130` is arithmetic, not a second slot.

---

## 4. Surviving contract for AutoCore

```
// Port as post-objective creature link refresh, not as mission logic.
// Preserve type-0x36 skip and TFID==-1 skip.
// Must pass the large host as `this` into RegisterObjectHashEntry.
// Safe no-op when creature range empty.
```

## 5. What would overturn

1. PDB name showing different responsibility (e.g. pure FX sweep).
2. Call site with ECX ≠ reaction/map host.
3. Proof `+0xe720` is not creatures on this host type.
