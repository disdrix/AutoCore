# Review A (reconstruction fidelity): `aa_0058e300` CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058e300` |
| **VA** | `0x0058e300`–`0x0058e370` |
| **Canonical name** | `CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred` |
| **Ghidra name** | `FUN_0058e300` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W26-L) |
| **Counterpart** | `reviews/B_aa_0058e300_CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred.md` |
| **System** | client object / FX phys link |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; callers/callees |
| **Verdict** | **accept** |

---

## 1. Purpose

Unslotted FX phys start/stop apply on a client object:

1. No-op unless `*(this+0x25c) < 0`.
2. If `want_stop != 0`: remove phys-link entry for key `*(this+0x914)` on host `want_stop`.
3. If `want_start != 0` and no existing link for key `*(this+0x258)`: attach via `0096dc80` and set `+0x90f` bit0.
4. Otherwise (gate open): clear `+0x90f` bit0.

Dispatched from NDSpecialFX owned-child walkers (`004b7030` / `004b7150`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0058e300_FUN_0058e300.md` (+ 2026-07-29 W26-L append) |
| Annotated | `docs/reconstruction/raw/aa_0058e300_FUN_0058e300.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0058e300.cpp` |
| Function record | `docs/reconstruction/functions/aa_0058e300_FUN_0058e300.md` |
| Named record | `docs/reconstruction/functions/aa_0058e300_CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred.md` |
| Live | decompile ≡ raw; `read_memory` 112 B; `C2 08 00` epilogues |
| Sibling | live decompile `FUN_0058e270` (slot-filter gate contrast) |

---

## 3. Signature (sealed)

```c
// thiscall; 2 stack formals; RET 8; void
void __thiscall CVOGObject_FxPhysStartStop_IfSlotNeg_Inferred(
    void* self, void* want_start, void* want_stop);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX | **High** |
| want_start | Stack[0x4] | **High** |
| want_stop | Stack[0x8] | **High** |
| cleanup | `RET 8` | **High** |
| return | void (no EAX contract) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if slot_0x25c >= 0: return
if want_stop:  0096d550(this=want_stop, key=+0x914)
if want_start:
  if 0096d460(this=want_start, key=+0x258) == 0:
    0096dc80(this=want_start, +0x258, +0x914, +0x254)
    flags_0x90f |= 1
    return
flags_0x90f &= ~1
return
```

| Stage | Match | Conf |
|---|---|---|
| Slot gate `< 0` | **Yes** | **High** |
| Stop before start | **Yes** | **High** |
| Lookup-before-attach | **Yes** | **High** |
| bit0 set only on new attach | **Yes** | **High** |
| bit0 clear when start skipped/hit | **Yes** | **High** |
| Callee this restored | **Yes** (bytes) | **High** |

---

## 5. Machine bytes (`read_memory`)

Body **112 B** hex (pad `CC` after last RET):

```
568bf183be5c020000007d5f8b4c240c85c9740c8b861409000050e830f23d00
578b7c240c85ff743a8b8e58020000518bcfe829f13d0085c075288b96540200
008b86140900008b8e580200005250518bcfe829f93d00808e0f090000015f5e
c2080080a60f090000fe5f5ec20800
```

Epilogues: `5F 5E C2 08 00` (both success and clear paths). Gate fail falls into clear-or-skip structure ending same RET family.

---

## 6. Gaps

- Product English / original method name.
- Exact type of phys-list hosts (`want_start` / `want_stop`).
- Nested `0096d*` product duals — not OWN.
- Runtime attach/detach differential — open.

---

## 7. Verdict

CF, ABI, slot gate, start/stop order, bit0 policy, and caller roles are sealed. Naming is evidence-backed inference. → **accept**.
