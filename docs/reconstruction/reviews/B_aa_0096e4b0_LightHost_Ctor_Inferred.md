# Review B (skeptical / adversarial): `aa_0096e4b0` LightHost_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096e4b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-AB) |
| **Counterpart** | `reviews/A_aa_0096e4b0_LightHost_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is a free function / no this | **Falsified** — `MOV ESI,ECX`; returns ESI |
| 2 | This fully configures a light (type/color/dir) | **Falsified** — only base + two zeros + vtable; type strings set by callers via `FUN_0096e430` |
| 3 | Object size is 0x94 proven in this body | **Overstated as body-local** — size from callers' `operator_new(0x94)` only (still High via xrefs) |
| 4 | Name is retail demangle | **Overstated** — `_Inferred` from light-host call sites; no RTTI sealed |
| 5 | Scaffold `Named_CalleeOf_Client_RecvLoginCa_*` is product role | **Falsified** — callee-of ladder; reject as canonical |
| 6 | `param_1[0x23]` is abstract index not `+0x8c` | **Falsified** — bytes `89 86 8C 00 00 00` |
| 7 | Base `FUN_0096d830` is exclusive to lights | **Falsified** — also used by CVOGGraphicsBody / UI directional paths (unowned context) |
| 8 | Runtime verified | **Open** — no Launcher |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Ctor CF / ABI / return this | **High** | Wrong construction |
| Zero +0x8c / +0x90 | **High** | Stale effect pointers |
| Vtable `00aa0394` | **High** | Wrong dispatch |
| Alloc size 0x94 | **High** (callers) | Heap overrun if ignored |
| Product class English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
ESI=this
CALL FUN_0096d830(ESI)
[ESI+0x8C]=0; [ESI+0x90]=0
[ESI]=00AA0394
EAX=ESI; RET
```

Live 2026-08-04 ≡ raw 2026-07-23 CF; 33 B hex sealed. Callers: RebuildDefaultLights ×2 + particle Point ×1.

---

## 4. Surviving contract for AutoCore

```
// After operator_new(0x94):
light = LightHost_Ctor_Inferred(light);
// Must: base init + clear +0x8C/+0x90 + vtable 00aa0394
// Must not: set Direction/Hemispheric/Point/colors here
// Pair with: FUN_0096e430(type), effect ops via light+0x8C (W32-R context)
```

---

## 5. Verdict

Adversarial pass **confirms** A: ctor role, sealed offsets/vtable/ABI; product demangle open → **accept-with-gaps**.
