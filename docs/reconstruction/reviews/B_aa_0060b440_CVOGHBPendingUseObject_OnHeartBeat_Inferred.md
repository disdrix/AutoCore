# Review B (skeptical / adversarial): `aa_0060b440` CVOGHBPendingUseObject_OnHeartBeat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060b440` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-T) |
| **Counterpart** | `reviews/A_aa_0060b440_CVOGHBPendingUseObject_OnHeartBeat_Inferred.md` |
| **Verdict** | **accept** on CF/ABI/fields; **needs-more-evidence** on product English + post-commit list fate |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `+0x24` is heat/shield debounce bytes | **Falsified** — dword load compared to `char+0xc9c`; ctor stores object* |
| 2 | `param_1[1].pVTable` is second HB vtbl | **Falsified** — `mov ecx,[esi+0x28]`; subclass past base size |
| 3 | Always commits resolve | **Falsified** — gates + secondary match required |
| 4 | Fail writes Continue (0) | **Falsified** — `DAT_00af49ac` = 16 Remove |
| 5 | Direct CODE callers exist | **Survives as empty** — only DATA vtbl xref (expected OnHB) |
| 6 | `pOutNextDelayMs` is separate uninitialized | **Falsified** — same stack out as param_2 (EDI) |
| 7 | Base `CVOGHBBase` size alone suffices | **Falsified** — needs `+0x24`/`+0x28` subclass fields |
| 8 | Product name is retail | **Overstated** — inferred from RecordFirstTimeEvent + Resolve chain |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gate + match CF | **High** | Wrong commit / list remove |
| Remove token 16 | **High** | Wrong EHBStatus |
| thiscall ret 4 / return out* | **High** | ABI break |
| OnHeartBeat vtbl slot | **High** | Wrong dispatch |
| Product English | **Tentative** | Docs only |
| Post-commit reschedule semantics | **Medium** | List churn residual |

---

## 3. Cross-check against raw + bytes

```
gate owner / [+0x28] / [+0x24] / !stopped
cmp [char+0xc9c], secondary → mismatch: *out=16
else: Resolve(char,1); Reschedule(this,out); return out
fail: *out=16; return out
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Field types corrected in clean from `read_memory` (not decomp pad names).

Clean preserves spine. **No invented static callers.** Remove token sealed via `read_memory @ 0x00af49ac`.

---

## 4. Surviving contract for AutoCore

```
// Pending-use HB OnHeartBeat (period from object+0x25c seconds * 1000):
if secondary still == char+0xc9c:
  commit ResolveUseObjectPending(1); RescheduleAfterFire
else:
  *out = Remove (16)  // leave list
```

Port must keep **secondary match** gate — do not commit blindly on every beat.

---

## 5. Residual

- Product class name / PDB.
- Whether Reschedule after commit is dead (resolve may clear aux) vs intentional one-more tick — runtime.

**Verdict:** **accept** (CF/ABI/fields sealed). English + post-commit residual only.
