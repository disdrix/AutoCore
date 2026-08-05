# Review B (skeptical / independent): `aa_006061e0` CVOGHBWakeupSkill_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_006061e0` |
| **VA** | `0x006061e0` |
| **Canonical name** | `CVOGHBWakeupSkill_ctor` |
| **Review date** | `2026-07-29` (W19-G OWN dual) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_006061e0_CVOGHBWakeupSkill_ctor.md` |
| **System** | `skills-abilities` / heartbeat |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_006061e0` only | Acceptable scaffold; under-describes sealed RTTI class |
| `Named_CalleeOf_…VOG_DEBUG_STOP_006061e0` | **Reject** — auto-chain garbage; no VOG_DEBUG string in body |
| `CVOGHBWakeupSkill_Fire` | **Reject** — Fire is sibling `0x00606180` vtbl+0x14 |
| `CVOGHBSkillBase_ctor` | **Reject** — wrong class; SkillBase is `0x005788d0` / different vtbl |
| `CVOGHBWakeupSkill_ctor_Inferred` | Unnecessary `_Inferred` — RTTI class Confirmed + ctor role Confirmed |
| `CVOGHBWakeupSkill_ctor` | **Accept** |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Object is not 0x674 / skill not at +0x24 | **Fails** — callers `operator_new(0x674)`; `lea edi,[ebp+0x24]` + `0x18c` movsd; Fire uses skill@+0x24 |
| Vtbl is base CVOGHBBase not WakeupSkill | **Fails** — write `0x009de7b4`; RTTI string; Fire sole DATA xref at +0x14 of same vtbl |
| TFID vector at wrong offsets | **Fails** — zero three dwords then capacity `>>4`; Fire reads first TFID via +0x660 |
| Always-append sentinel is optional | **Fails** — both branches after while unconditionally push `DAT_009de7a0` |
| Function allocates the HB itself | **Fails** — no `operator_new` in body; returns pre-allocated this |
| AttachOwner subject is skill not host | **Fails** — `param_3` pushed after seed; matches ApplyStatusEffectLocal host pass |
| `param_1[3]/[4]=1` are type tags | **Unproven English** — values Confirmed; period-seed interpretation High not product-named — keep gap |

---

## 3. Agreement with Review A

- Class RTTI Confirmed + ctor role: **agree**
- Field seed map for Fire dual offsets: **agree High/Confirmed**
- Three-rep raw ≡ live ≡ bytes: **agree**
- Gaps (param_2/param_9 English, helpers, runtime): **agree open**
- Name without `_Inferred`: **agree** (RTTI bar met)

---

## 4. Residual risks

- Decompiler surfaces `FUN_004cbfc0(end,1,src)` without ECX — agents may mis-bind insert API; annotated/clean document container @ `+0x65c`.
- `FUN_00608720` call sites may push extra stack junk (5 dwords cleaned) while helper body uses 3 — do not invent a 5-arg product API without a dedicated dual of that VA.
- Do not claim period Start happens inside this ctor (Start is caller / list path).

**Verdict:** **accept-with-gaps**
