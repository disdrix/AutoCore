# Review B (skeptical / adversarial): `aa_00618180` CVOGHBSkill_Common_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00618180` |
| **VA** | `0x00618180` |
| **Canonical name** | `CVOGHBSkill_Common_ctor` (class **Confirmed**; ctor role **High**) |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00618180_CVOGHBSkill_Common_ctor.md` |
| **System** | skills-abilities |
| **Live tools** | Independent decompile + `read_memory` + callers/xrefs + RTTI chain |
| **Verdict** | **accept** — accept CF/ABI/RTTI/float-tail/period gate; reject int-scale / void-return / invent-name / terminal claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Decompiler `param_9` is `int` / `nPeriodSentinel` overlay at tail | **Falsified** — body `F3 0F 11 86 C4 06 00 00` (**movss**) to `+0x6c4`; Virus passes `0x3f800000` (1.0f) |
| 2 | Return type `void` / undefined discard | **Falsified** — `8B C6` then `ret 0x20`; callers use returned HB pointer |
| 3 | cdecl / no ECX this | **Falsified** — `8B F1`; base ctor thiscall on ESI |
| 4 | Fewer/more than 8 stack args | **Falsified** — all paths `C2 20 00` |
| 5 | This is a leaf helper / not a ctor | **Falsified** — installs vtbl; SEH; base ctor; `operator_new(0x6d0)` sites |
| 6 | Class name inventable without RTTI | **Rejected invent** — type_info string **`.?AVCVOGHBSkill_Common@@`** sealed via COL `0x00ab1820` |
| 7 | Scaffold “unknown” system | **Falsified** — skills-abilities parent `0x005788d0` + RTTI skill class |
| 8 | Period path always runs | **Falsified** — four-way AND gate; often skipped |
| 9 | `30000` is float seconds | **Falsified** — integer ms into `+0x08` / SetPeriod divisor path |
| 10 | Runtime / terminal Confirmed | **Rejected** — no Launcher; Terminal false |
| 11 | Same object as Virus | **Falsified** — Virus re-points vtbl to `009d14bc` and extends size `0x6e0` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RTTI class Common | **Confirmed** | Wrong type hierarchy |
| ABI thiscall + ret 0x20 + EAX this | **High** | Stack smash on port |
| Tail +0x6c0 byte / +0x6c4 float / +0x6c8 0 | **High** | Corrupt subclass fields |
| Period rescale/clamp math | **High** | Wrong HB cadence |
| Gate offsets +0x44 / +0xa4 / +0xf6 | **High** (structural) | Wrong enable condition |
| Product English for gates/fields | **None** | Overclaim design |
| Full vtbl slot semantics | **Low** | Wrong virtual dispatch on port |

---

## 3. Decompiler pitfalls (must survive port)

1. Do **not** type `param_9` / `+0x6c4` as int — **float** (`movss`).  
2. Do **not** trust `param_1[0x2b].nPeriodSentinel` names — use absolute `+0x6c0/+0x6c4/+0x6c8`.  
3. Do **not** treat `iVar1` as full int — gate is **byte** `this+0x44`.  
4. Do **not** drop ECX this when calling base — SkillBase is thiscall.  
5. Do **not** claim product field English for Common scale/flag without further evidence.  
6. Parent name may appear as `FUN_005788d0` or `CVOGHBSkillBase_ctor` — same VA.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| RTTI `CVOGHBSkill_Common` ctor CF | PDB method English beyond class |
| Intermediate base for Virus et al. | “Common” gameplay design doc |
| 30.0f remaining threshold + 30000 ms clamp | Why designers chose 30 s |
| 15 CALL sites / 12 named owners | Full semantic names of all owners |
| `_ctor` role High | Confirmed product method spelling without RTTI (have RTTI) |

---

## 5. CF challenge of Review A

- Body bounds + ret 0x20: **agree Confirmed**  
- RTTI Common: **agree Confirmed**  
- Float at +0x6c4: **agree Confirmed** (adversarial strengthens A)  
- Period gate math: **agree High**  
- Product field English: **agree Open**  
- Runtime: **agree not claimed**

**Verdict:** **accept** — no CF rejects; decompiler int-overlay pitfall closed by bytes.
