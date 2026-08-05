# Review B (skeptical / adversarial): `aa_00578830` CVOGHBSkillBase_DefaultCtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578830` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W23-S) |
| **Counterpart** | `reviews/A_aa_00578830_CVOGHBSkillBase_DefaultCtor.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Is the full skill cast ctor (`005788d0`) | **Falsified** — no blob copy, no ValidateTarget, no type tag, Attach always null |
| 2 | Different class than `CVOGHBSkillBase` | **Falsified** — same vtbl `009d3fdc` + RTTI name |
| 3 | Attaches a real owner | **Falsified** — sole Attach path pushes 0 |
| 4 | Sets period / starts HB | **Falsified** — no SetPeriodAndCounter / Start |
| 5 | `FUN_0054f3c0` this = HB base | **Falsified** — bytes `lea ecx,[esi+0x24]` |
| 6 | Final product type of factory shells | **Partial** — this installs SkillBase vtbl; callers often overwrite (e.g. `009d13b4`) — sealed as intermediate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Empty shell CF | **High** | Factories would re-init skill blob incorrectly |
| RTTI class SkillBase | **Confirmed** | Wrong port hierarchy |
| Distinct from full ctor | **High** | ValidateTarget/period paths mis-merged |
| Intermediate before subclass vtbl | **High** | Treat default vtbl as final type |

---

## 3. Cross-check

```
raw: base, vtbl 009d3fdc, FUN_0054f3c0, zeros, Attach(0), TFID sentinel
live: identical
bytes: SEH + call base + c706 dc3f9d00 + lea+0x24 partial + zeros + Attach + global TFID copy
sibling 005788d0 dual: same vtbl; notes this sibling as Attach(null) no ValidateTarget
factory 00548bd0: new(0x6c0); FUN_00578830(); *obj = subclass_vtbl
```

---

## 4. Surviving contract for AutoCore

```
CVOGHBSkillBase_DefaultCtor(this):
  CVOGHBBase_ctor(this)
  this.vtbl = CVOGHBSkillBase_vtbl
  SkillRuntime_PartialCtor(this.skillBlob@+0x24)
  zero skill-HB tails
  AttachOwner(null)
  this.ownerTfidBlock = InvalidTfidSentinel
  return this
```

Port skill catalog factories as **allocate → default skill-HB shell → install concrete subclass vtbl/fields**. Do not treat this as a cast-start path.

---

## 5. Open questions

None blocking factory construction paths. Fire/ValidateTarget live on full ctor + subclass duals.

**Verdict:** **accept**
