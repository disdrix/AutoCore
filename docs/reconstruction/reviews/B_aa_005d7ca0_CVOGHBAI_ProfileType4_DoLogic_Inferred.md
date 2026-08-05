# Review B (skeptical / adversarial): `aa_005d7ca0` CVOGHBAI_ProfileType4_DoLogic_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d7ca0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W27-I) |
| **Counterpart** | `reviews/A_aa_005d7ca0_CVOGHBAI_ProfileType4_DoLogic_Inferred.md` |
| **Scratch** | `tmp/a_005d7ca0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same ternary SM as CreatureBase (0/1/other) | **Falsified** — only `==0` vs else; no engage middle arm |
| 2 | Casts skill set 1 | **Falsified** — only sets **0** and **2** |
| 3 | Is Driver::DoLogic (plate string) | **Falsified** — no plate; different VA/vtbl; no FireWeapons |
| 4 | Leaf / no profile map | **Falsified** — `00540890`×2 + `004cbd50` early-out |
| 5 | Does not touch owner+0x278 | **Falsified** — `FUN_004c3c80(0)` clears it |
| 6 | Product class name sealed | **Overstated** — only vtbl/factory linkage; no RTTI string in body |
| 7 | stdcall with stack args | **Falsified** — ECX this; bare `RET` |
| 8 | Shared by all HBAI types | **Falsified** — sole DATA xref in type-4 vtbl `009db0dc` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall void bare ret | **High** | ABI break |
| Profile map early-out | **High** | Tick without profile |
| Binary +0x26c SM | **High** | Wrong combat behavior |
| Skill sets 0/2 | **High** | Wrong cast table |
| Type-4 vtbl only | **High** | Mis-assign to CreatureBase |
| DoLogic product name | **Probable** | Naming only |
| Class product English | **Open** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
thiscall CVOGHBAI_ProfileType4_DoLogic_Inferred(self)
key = owner→def+0x4dc
if lower_bound miss: return
FUN_004c3c80(owner, 0)
if owner+0x26c == 0:
  cast(0); aim; path-clear arm → vtbl tails
else:
  cast(2); aim; path-clear arm → pursue / clear state
if path-mode busy: FUN_005cc450
RET
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Vtbl dword `@009db0dc = 005d7ca0`. Factory case 4 ctor installs `009db08c`.

---

## 4. Surviving contract for AutoCore

```
// Profile-type-4 HBAI tick (virtual):
// 1) Require AI profile row (same map as Driver/CreatureBase)
// 2) Clear owner+0x278 each tick (mode 0)
// 3) owner+0x26c==0 → idle skill set 0 + face/path helpers
//    else → combat skill set 2 + pursue while target present
// 4) Do not implement CreatureBase engage state (type1) or Driver FireWeapons here
```

---

## 5. Verdict

Adversarial pass **confirms** A: CF/ABI/vtbl/binary-SM sealed; DoLogic/class product English residual → **accept-with-gaps**.
