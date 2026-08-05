# Review B (skeptical / adversarial): `aa_005825d0` Object_UnloadGraphics_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005825d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-T) |
| **Counterpart** | `reviews/A_aa_005825d0_Object_UnloadGraphics_Inferred.md` |
| **Scratch** | `tmp/a_005825d0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is `Object_SetMissionStateFx` itself | **Falsified** — **calls** `00518370` with constant **3**; larger body with untrack + virtuals |
| 2 | This is `FUN_00582670` sibling | **Falsified** — sibling is larger, takes stack param, different CF (FX events 0x10/0x11/0x12) |
| 3 | `FUN_004bfd10(this)` as decompiler shows | **Falsified as ABI** — bytes load manager `ECX` from `*(host+0xE914)`, stack = this |
| 4 | Free function / no this | **Falsified** — `MOV ESI,ECX`; MI vb adjust uses `this+4` |
| 5 | Mission state 0/1/2 path | **Falsified** — immediate `PUSH 3` before `CALL 00518370` |
| 6 | Always notifies host | **Falsified** — null check on `*(host+0xE500)` |
| 7 | Name is retail demangle | **Overstated** — inferred from caller `"UnloadGraphics on %s (%d)"` |
| 8 | Complete dtor / frees this | **Falsified** — bare RET; no `operator_delete` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| UnloadGraphics role | **High** | Wrong lifecycle port |
| thiscall MI + bare RET | **High** | ABI break |
| Manager this residual | **High** | Wrong list untrack |
| State 3 FX | **High** | Wrong audio/FX side effect |
| Product vfunc names | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
ESI=this
manager = *(*( *(this+4)+4 + this + 0xA8 ) + 0xE914)
FUN_004bfd10(manager, this)
byte[this+0xF]=0
root = this + adj + 4
root.vtbl+0x144()
SetMissionStateFx(root, 3)
if notify=*(host+0xE500): (*notify)(root)
root.vtbl+0xFC()
this.vtbl+0x04(); this.vtbl+0x18(0); this.vtbl+0x18(1)
RET
```

Live 2026-07-29 ≡ raw 2026-07-23 CF spine; first-callee this corrected by bytes. CODE caller: `FUN_005d4fd0` @ `005d5016`.

---

## 4. Surviving contract for AutoCore

```
// Unload graphics for MI object subobject (not full delete):
Object_UnloadGraphics_Inferred(mi_this);
// 1) untrack via FUN_004bfd10(manager_from_host+0xE914, mi_this)
// 2) clear flag mi+0x0F
// 3) object_root vtbl+0x144 destroy-graphics
// 4) Object_SetMissionStateFx(root, 3)  // sealed W30-H
// 5) optional host notify @ +0xE500
// 6) root vtbl+0xFC; self vtbl+0x04; self vtbl+0x18(0); self vtbl+0x18(1)
// Do not free this here. Do not use decompiler's FUN_004bfd10(this) alone.
```

---

## 5. Verdict

Adversarial pass **confirms** A: unload role, CF order, manager-this residual, state 3 sealed; product English open → **accept-with-gaps**.
