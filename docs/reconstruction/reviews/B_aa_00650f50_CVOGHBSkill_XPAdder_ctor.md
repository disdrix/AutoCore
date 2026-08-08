# Review B (skeptical / adversarial): `aa_00650f50` CVOGHBSkill_XPAdder_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00650f50` |
| **VA** | `0x00650f50` |
| **Canonical name** | `CVOGHBSkill_XPAdder_ctor` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R11-025 OWN dual) |
| **Counterpart** | `reviews/A_aa_00650f50_CVOGHBSkill_XPAdder_ctor.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** — agree with A |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `read_memory` + callers/xrefs. No Launcher. No `disassemble_bytes`.

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_00650f50` only | Acceptable scaffold; under-describes sealed RTTI class |
| `Skill_HB_SpawnEntities_ctor_Inferred` | **Reject** — different vtbl (`009d0ec4`), different subclass field (`+0x6c4` ushort) |
| `CVOGHBSkillBase_ctor` | **Reject** — base is `0x005788d0` / vtbl `009d3fdc` |
| `CVOGHBMissionPatrol_*` | **Reject** — Ghidra mislabel on peer `0x00650f90` does **not** transfer to this ctor; RTTI is XPAdder |
| `CVOGHBSkill_XPAdder_ctor_Inferred` | Unnecessary `_Inferred` — RTTI class Confirmed + ctor role Confirmed |
| `CVOGHBSkill_XPAdder_ctor` | **Accept** |

---

## 2. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler 6-stack + this signature is wrong | **Survives** — `ret 0x18` + six pushes; `mov esi,ecx` |
| 2 | Base call omits `this` in decompile → base not thiscall | **Falsified as ABI** — `mov ecx,esi` before call; base dual thiscall |
| 3 | `param_1[0x1b0]=0` is a dword integer clear | **Falsified width** — `MOVSS` float zero at **byte** `+0x6c0` |
| 4 | This function *is* the XP apply / tick logic | **Falsified** — body only base+vtbl+float0; tick is vtbl peer `00650f90` |
| 5 | Object size unknown / larger than base | **Falsified** — sole caller `operator_new(0x6d0)` |
| 6 | Multiple independent callers construct this class | **Falsified count** — only `FUN_0061c940` (2 call sites) |
| 7 | Class is MissionPatrol because of nearby Ghidra names | **Falsified** — RTTI `CVOGHBSkill_XPAdder`; COL on this vtbl |
| 8 | Allocates the HB itself | **Falsified** — no `operator_new` in body; returns pre-allocated this |
| 9 | Runtime Confirmed | **Falsified** — no Launcher; Terminal false |

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Base→vtbl→float0 CF | **High** | Wrong subclass init order |
| `ret 0x18` / 6 stack args | **High** | Stack corruption if ported as ret 0 |
| RTTI class identity | **High** | Mis-bind XP adder vs other skill HB |
| Float @ `+0x6c0` (not dword index product) | **High** | Port stores wrong width/offset |
| Product English of float field | Medium | Naming only until peer dual |
| Stack formal English beyond base plate | High inherit / not re-proven product | Low for this unit |

---

## 4. Cross-check against raw + bytes

```
mov esi, ecx
… push 6 args …
mov ecx, esi
call CVOGHBSkillBase_ctor     ; E8 … → 005788d0
xorps xmm0, xmm0
mov dword [esi], 009e5304     ; subclass vtbl
movss [esi+0x6c0], xmm0       ; float residual = 0
mov eax, esi
ret 0x18
```

Clean must **not** invent XP apply loops, character `+0xc54` math, Enqueue, or Start — those are caller / peer virtuals.

---

## 5. Agreement with Review A

- Class RTTI Confirmed + ctor role: **agree**
- Float store width/offset: **agree Confirmed**
- Three-rep raw ≡ live ≡ bytes (with documented decomp hazards): **agree**
- Gaps (peer duals, float English, runtime): **agree open**
- Name without `_Inferred`: **agree** (RTTI bar met)
- Verdict **accept-with-gaps**: **agree**

---

## 6. Residual risks

- Ghidra still labels peer `0x00650f90` as `CVOGHBMissionPatrol_Tick` — do not import that name into this unit; RTTI on **this** vtbl is XPAdder.
- Decompiler dword-index `param_1[0x1b0]` may mislead ports into writing a 32-bit integer store without float semantics.
- Base formal names are inherited from `aa_005788d0`; this dual does not re-open ValidateTarget attach residual.

**Verdict:** **accept-with-gaps**
