# Review B (skeptical / adversarial): `aa_005d7de0` CVOGHBAI_ProfileType4_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d7de0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-K) |
| **Counterpart** | `reviews/A_aa_005d7de0_CVOGHBAI_ProfileType4_ctor_Inferred.md` |
| **Scratch** | `docs/reconstruction/tmp/a_005d7de0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Full HBAI init is in this leaf | **Falsified** — only base call + vtbl write (25 B) |
| 2 | Ghidra `FUN_005d1990(param_2)` drops this | **Explained residual** — bytes keep ECX=this, push owner |
| 3 | Same as AICode CreateByAICode case 4 (Mine) | **Not evidenced** — different factory; do not invent |
| 4 | Installs DoLogic pointer directly | **Falsified** — installs whole vtbl; DoLogic is slot at +0x50 |
| 5 | stdcall void | **Falsified** — thiscall returns this; `RET 4` |
| 6 | Shared ctor with type 2/3/5 | **Falsified** — parent switch uses distinct ctors per case |
| 7 | Product class name sealed | **Overstated** — ProfileType4 structural only |
| 8 | Secondary slew HB ctor | **Falsified** — that is `005d6b80` / `009daee8` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall thin chain + RET 4 | **High** | ABI break |
| vtbl `009db08c` only post-base write | **High** | Wrong subclass methods |
| Factory type-4 / 0xC0 | **High** | Wrong alloc size |
| DoLogic linkage via vtbl | **High** | Miss combat tick |
| Product class English | **Open** | Naming only |
| Base mid field map | **Open** | Init incomplete if porting without base |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
thiscall CVOGHBAI_ProfileType4_ctor_Inferred(self, pOwner)
  FUN_005d1990(self, pOwner)
  *self = 009db08c
  return self
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Vtbl dword @`009db0dc` = `005d7ca0` (sealed DoLogic). Sole call site factory case 4 @ `004c9556`.

---

## 4. Surviving contract for AutoCore

```
// Profile-type-4 HBAI construction:
// 1) Allocate 0xC0
// 2) Mid-base init FUN_005d1990(this, owner)  // period -1000, attach, timers, …
// 3) Install vtbl 009db08c (DoLogic = 005d7ca0 @ +0x50)
// 4) Do not fold AICode CreateByAICode table into this path
// 5) Do not confuse with secondary slew HB 005d6b80 (size 0x28)
```

---

## 5. Verdict

Adversarial pass **confirms** A: leaf CF/ABI/vtbl/factory sealed; product English + base mid residual → **accept-with-gaps**.
