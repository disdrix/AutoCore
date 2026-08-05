# Review B (skeptical / adversarial): `aa_004dbef0` CVOGReaction_RegisterObjectHashEntry_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004dbef0` |
| **VA** | `0x004dbef0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004dbef0_CVOGReaction_RegisterObjectHashEntry_Inferred.md` |
| **System** | client world object hash / spawn-link |
| **Verdict** | **accept-with-gaps** on CF/ABI; **reject** any port based solely on raw decompile signature |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Free function with 5 stack args only (raw decompile) | `MOV EDI,ECX`; uses `EDI+0xe8f4`; `RET 0x14` | **Falsified free** — **thiscall + 5 stack** |
| 2 | arg1 (`param_2`) participates in logic | No load from stack+8 after `obj` bind | **Falsified use** — dead at body |
| 3 | Always inserts fresh without remove | `FUN_004e23d0` then conditional `FUN_004e3170` | **Falsified** — replace path exists |
| 4 | Resolve uses object TFID as target | Resolve args are stack linkLo/Hi, not +0x160 | **Falsified** as same-as-key always |
| 5 | SpawnObject always calls this | Gated on `(obj[0xe] & obj[0xf]) != -1` in parent | **Survives as conditional caller** |
| 6 | `obj+0x11c` only written on insert success | Store **before** insert; fail deletes desc | **Falsified “success-only store”** — possible dangling |
| 7 | `FUN_004bb1c0` is identity lookup | Calls Resolve then vfunc `+0x1e8` | **Falsified identity** |
| 8 | Hash is medal / mission table | Offsets on world host; spawn/creature callers | **Falsified medal** |
| 9 | Clean invents remove/insert | Listing matches raw control shape | **Survives** CF (not ABI of decompiler) |
| 10 | Only SpawnObject uses it | 6 callers including CompleteObjective rebind | **Falsified sole-caller** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 0x14 | **High** | Stack smash on port |
| Remove-then-insert | **High** | Duplicate hash insert failures |
| Key = obj TFID +0x160 | **High** | Wrong identity |
| Link args separate from key | **High** | Wrong resolve target |
| `+0x11c` lifetime on insert fail | **Open** | UAF / stale pointer |
| Descriptor field English | **Tentative** | Misnamed server mirror |
| Product method name | **Low** | Cosmetic / search only |

---

## 3. Cross-check

Raw decompile **must not** be the ABI authority for this unit: it elides ECX host and mis-frames `FUN_004e23d0`/`FUN_004e3170` as free calls. Live listing 2026-07-29 is authoritative for:

* `this = ECX`
* table `host+0xe8f4`
* resolve ctx `host+0xe4e8`
* store `obj+0x11c`
* `RET 0x14`

SpawnObject dual already flagged this callee as open; this dual seals CF for that gap without claiming product symbols.

---

## 4. Surviving contract for AutoCore

```
// Signature MUST include host this + five stack args (last often -1).
// Never trust Ghidra's free-function decompile for this VA.
// Replace semantics: remove existing key before insert.
// Treat obj+0x11c as client link descriptor, not mission state.
// arg1 may be omitted in a clean port if always 0 — keep slot if matching stack packs.
```

## 5. What would overturn

1. Call site that does not set ECX to the large host (would force free/stdcall reinterpretation — currently none).
2. Proof `+0x11c` is cleared on insert failure in a tail not visible here.
3. PDB name showing a different domain (e.g. pure physics register).
