# Review B (skeptical / adversarial): `aa_0061fdf0` CVOGHBSkill_Virus_OnHeartBeat

| Field | Value |
|---|---|
| **Stable ID** | `aa_0061fdf0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_0061fdf0_CVOGHBSkill_Virus_OnHeartBeat.md` |
| **Verdict** | **accept-with-gaps** — class/slot/mode sealed; product skill English open |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is free function / cast entry | DATA xref only on vtbl; RTTI Virus | **Falsified** — virtual HB method |
| 2 | Gather mode defaults to 4 | Bytes push `1`; residual row mode=1 | **Falsified** — **mode=1**; **4** is maxTargets default |
| 3 | Always spreads every tick | RNG `>25` and flags and budget | **Falsified as always** |
| 4 | Hostile gather (mode 2) | Literal 1 + Gather dual table | **Falsified** |
| 5 | Creates generic CVOGHBSkillBase only | Ctor sets Virus vtbl `009d14bc` | **Falsified** — Virus children |
| 6 | Direct CALL fan-in | xrefs DATA-only | **Survives** — virtual only |
| 7 | `param_1[0x1a2]` is skill def row | Used as `+0xe4ec` list host → world | **Survives as world/map** (offset = skill +0x688 store) |
| 8 | Class name from plate string | RTTI `.?AVCVOGHBSkill_Virus@@` | **Confirmed** |
| 9 | OnHeartBeat vs RescheduleAfterFire slot | Peer OKToCastAgain maps +0x0c Reschedule; base TryFire dual says OnHeartBeat at +0x0c | **Survives as OnHeartBeat** for this class (overrides base reschedule slot with work body) |
| 10 | 100% fire when gates pass | `(u%100)>0x19` is ~75% | **Falsified as 100%** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RTTI class name | **Confirmed** | Wrong type docs |
| mode=1 / filterA=-1 | **High** | Wrong ally/hostile policy |
| maxTargets default 4 | **High** | Cap wrong |
| radius 50 default | **High** | Range wrong |
| Child size 0x6e0 + Virus ctor | **High** | Wrong factory |
| Budget dwords +0x6d0/+0x6d4 | **High** | Infinite spread |
| Resolve iterator variable | **Medium-High** | Multi-target miss if sticky |
| Skill product English | **Open** | Doc only |
| Runtime stacking | **Open** | Live parity |

---

## 3. Cross-check constants

```
DAT_00a0f524 = 00 00 48 42  → 50.0f
DAT_009e2df0 = FF×8 + 00×8 → null TFID
ret 4 at body end
vtbl[3] @ 009d14c8 = f0 fd 61 00 → 0x0061fdf0
type string @ 00af2b10 = ".?AVCVOGHBSkill_Virus@@"
```

Live decompile 2026-08-04 ≡ raw 2026-07-23 CF skeleton.

---

## 4. Surviving contract for AutoCore

- Port Virus HB as **periodic ally multi-spread**: gather mode **1**, default range **50**, default max **4**, ~**75%** RNG, budget counters, child HBs on world list `+0xe4ec`.
- Do not model as single-target cast validator.
- Fail path hard-stops via **vtbl+0x18(1,1)** when primary target invalid.

**Verdict:** **accept-with-gaps**.
