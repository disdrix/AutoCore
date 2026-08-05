# Review B (skeptical / adversarial): `aa_0058e300` CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058e300` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-L) |
| **Counterpart** | `reviews/A_aa_0058e300_CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred.md` |
| **Scratch** | `docs/reconstruction/tmp/a_0058e300.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Free function / stdcall only | **Falsified** — `MOV ESI,ECX` entry; `RET 8` thiscall |
| 2 | Decompiler form is complete for callees | **Incomplete** — decompile omits ECX=want_* ; bytes `MOV ECX, want_stop/start` before calls |
| 3 | Acts for all slots | **Falsified** — `CMP [ESI+0x25c],0` / `JGE` skip when slot ≥ 0 |
| 4 | Same gate as `0058e270` | **Falsified** — e270 requires `(filter==-1\|\|slot==filter) && slot!=-1` |
| 5 | Always attaches when want_start | **Falsified** — lookup `0096d460`; attach only if result **0** |
| 6 | Always clears bit0 | **Falsified** — successful attach **sets** bit0 and returns early |
| 7 | Creates/destroys the child object | **Falsified** — only phys-list remove/attach helpers |
| 8 | Product name from body string | **Overstated** — no string; `_Inferred` required |
| 9 | Deactivate path passes want_start | **Falsified for 004b7150** — `FUN_0058e300(0, phys)` is stop-only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 8 | **High** | stack imbalance |
| Slot `< 0` gate | **High** | apply on slotted children wrongly |
| Stop/start order + bit0 | **High** | wrong FX link state |
| Callee this = want_* | **High** | wrong host for phys list |
| Sibling distinction e270 | **High** | wrong slot policy in ports |
| Product English | **Medium** | naming only |
| Nested 0096d* semantics | **Medium** | attach details residual |
| Runtime | **Open** | matrix policy |

---

## 3. Cross-check against raw + bytes

```
ESI = this
if [ESI+0x25c] >= 0: return
if want_stop:  call 0096d550 (ECX=want_stop, key=[ESI+0x914])
if want_start:
  call 0096d460 (ECX=want_start, key=[ESI+0x258])
  if EAX==0:
    call 0096dc80 (ECX=want_start, keys/params)
    OR [ESI+0x90f], 1; RET 8
AND [ESI+0x90f], 0xFE; RET 8
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Callers dualed as NDSpecialFX dispatchers seal child as this.

---

## 4. Surviving contract for AutoCore

```
// Unslotted only — do not use for positive slot ids (use FUN_0058e270 + filter).
// Deactivate/clear: often want_start=0, want_stop=physHost.
// Apply toggle: both want_* from parent flags.
void CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred(obj, want_start, want_stop);
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/gate/bit policy sealed; product name residual only → **accept**.
