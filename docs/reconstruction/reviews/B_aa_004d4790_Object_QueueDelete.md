# Review B (skeptical / adversarial): `aa_004d4790` Object_QueueDelete

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d4790` |
| **VA** | `0x004d4790` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004d4790_Object_QueueDelete.md` |
| **System** | `missions-progression` + object lifecycle |
| **Verdict** | **accept** on string-backed role; convention multi-site residual mild |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Immediate free/destructor only | Queues + flags + vcall; "delete cue" string | **Overstated immediate free** |
| 2 | Mission-only helper | 17 xrefs: inventory, vehicle, remove item, etc. | **Falsified mission-only** |
| 3 | Always logs | Log gated on inactive-hash hit | **Falsified always** |
| 4 | CompleteObjective always deletes rewards | Only non-matching COID filter branch | **Falsified** |
| 5 | Clean invents string path | Raw has format | **Survives** |
| 6 | Typo "cue" means something else | Still delete queue English | **Survives as queue** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Delete-queue intent | **High** | Leaking objects |
| Flag bit 2 | **High** | Double-delete races |
| Mission filter pairing | **High** | Granting filtered rewards |
| Exact thiscall vs cdecl | **Tentative** multi-site | Port ABI |
| Vtable slot product name | **Open** | |

---

## 3. Surviving contract for AutoCore

```
// Shared object lifecycle — not mission-private.
// Mission complete: delete only when reward COID filter rejects grant.
// Expect InactiveObjects race warn in edge cases; do not treat warn as hard fail.
```
