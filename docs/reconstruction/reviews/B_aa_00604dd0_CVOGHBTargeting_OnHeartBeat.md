# Review B (skeptical / adversarial): `aa_00604dd0` CVOGHBTargeting_OnHeartBeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_00604dd0` |
| **VA** | `0x00604dd0` |
| **Canonical name** | `CVOGHBTargeting_OnHeartBeat` (**Inferred**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00604dd0_CVOGHBTargeting_OnHeartBeat.md` |
| **System** | `heartbeat` / targeting |
| **Live tools** | Independent force decompile + `read_memory` + TryFire / Reschedule / predicate |
| **Verdict** | **accept-with-gaps** — accept CF; reject overclaim of flag meaning / always-fire myth |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Derived-only OnHeartBeat | **Falsified** — **shared** slot 3 on base `009cdfb0` and derived `009cdfd4` |
| 2 | Always calls `vtbl+0x18` | **Falsified** — only when owner non-null **and** `FUN_005134e0` true |
| 3 | Skips Reschedule when vcall taken | **Falsified** — Reschedule is unconditional after the gated block |
| 4 | Is TryFire itself | **Falsified** — TryFire is `0x005082c0`; this is vtbl+0x0C callee |
| 5 | `__fastcall` three distinct params as decompiler prints | **Overstated** — machine is thiscall + `ret 4`; EDX “extraout” is decompiler artifact |
| 6 | Flag bit 8 English known | **Open** — only bit test sealed; product name residual |
| 7 | Product OnHeartBeat spelling proven | **Not proven** — role High via vtbl slot + TryFire dual |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gated vcall + always Reschedule | **High** | Wrong targeting HB period / teardown |
| Owner `+0x18` | **High** | Predicate on wrong object |
| `vtbl+0x18` args `(1,1)` | **High** | Wrong destroy flags |
| Shared base+derived | **High** | Duplicate subclass implementation myth |
| Flag bit 8 meaning | **Tentative** | Wrong gameplay condition |
| Return ABI exactness | **Probable** | TryFire residual shared gap |

---

## 3. Decompiler pitfalls

1. `FUN_005134e0()` printed with no owner arg — machine moves owner into **ECX** before call.
2. `param_2 = extraout_EDX` noise — ignore for port; follow RescheduleAfterFire out-param contract.
3. Typed `CVOGHBBase*` is correct family; subclass still shares this body.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| OnHeartBeat CF for targeting HB family | Flag bit 8 product name |
| Conditional `vtbl+0x18(1,1)` then always Reschedule | “Always self-destructs every tick” |
| Shared base+derived slot | Derived-only override |

---

## 5. CF challenge of Review A

- Force ≡ non-force: **agree**
- Machine gate order: **agree High**
- Inferred name + gaps: **agree**
- Shared-not-derived-only: **agree** (A already states shared)

**Verdict:** **accept-with-gaps**
