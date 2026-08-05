# Review B (skeptical / adversarial): `aa_0074ee40` AnimSlot_BindResourceFromPath

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074ee40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W24-S) |
| **Counterpart** | `reviews/A_aa_0074ee40_AnimSlot_BindResourceFromPath.md` |
| **Scratch** | `tmp/a_0074ee40.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is a pure string path loader with no failure | **Falsified** — multiple fail paths return `0xFFFFFFFF`; parent checks `>= 0` |
| 2 | Decompiler void / wrong stack cleanup | **Falsified** — both exits `C2 04 00` (`ret 4`); ECX=this |
| 3 | Resource stored only transiently | **Falsified** — durable stores at `+0x70` and `+0x74` (ctor zeros them) |
| 4 | Success always returns 1 | **Falsified** — returns `(ready != 0)` from vtbl+4; can be 0 while still “success” for parent `>= 0` |
| 5 | `FUN_00963950` always fails (decomp returns 0 only) | **Overstated residual** — live decompile shows `return 0` but call site still compares to `-1`; treat as black-box with sealed gate |
| 6 | Name is retail PDB | **Overstated** — structural **Inferred** from parent anim-slot + ND cache; Ghidra still `FUN_0074ee40` |
| 7 | Graphics-only (not anim) | **Weakened** — callers include both anim slot load (W18-C) and `CVOGGraphicsBase_LoadNextChildAsset`; shared ND bind helper on 0x78-like host with +0x70/+0x74 |
| 8 | Nested helpers typed fully here | **Open by design** — residual; not OWN |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bind CF (lookup→store→acquire→extract→init) | **High** | Broken anim load |
| ABI thiscall + RET 4 | **High** | Stack smash |
| Offsets +0x70 / +0x74 | **High** | Corrupt slot |
| Fail = -1 | **High** | False success in parent |
| Success 0/1 from vtbl+4 | **High** | Wrong ready semantics |
| Product type English | **Medium** | Naming only |
| Nested helper internals | **Open** | Port of helpers |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
FUN_00449070 → typeDesc
LookupOrCreate(DAT_00d1f050, path, type, 0, 0) → this+0x70
vtbl+4 ready
AcquireInner → this+0x74
FUN_00963950 != -1
FUN_0074eaa0
return ready?1:0  else -1
RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Clean plates name role without changing CF.

Note on host type: structural name uses **AnimSlot** because primary sealed parent is the 0x78 anim slot ctor/`Object_LoadOrReplaceAnimSlot`; graphics caller may share the same +0x70/+0x74 layout — residual product unification.

---

## 4. Surviving contract for AutoCore

```
// Anim/ND slot bind from path key (not the full Object_LoadOrReplaceAnimSlot)
rc = AnimSlot_BindResourceFromPath(slot, pathKey)
// rc < 0  → fail (do not run duration/add)
// rc >= 0 → resource at slot+0x70, inner at +0x74; rc is ready flag 0/1
// Do not assume rc==1 on every successful bind
```

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/offsets/return domain; residuals are product English + nested helpers + multi-caller host typing → **accept-with-gaps**.
