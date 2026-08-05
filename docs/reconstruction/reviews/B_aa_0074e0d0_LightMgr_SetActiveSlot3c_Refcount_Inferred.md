# Review B (skeptical / adversarial): `aa_0074e0d0` LightMgr_SetActiveSlot3c_Refcount_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074e0d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-AE) |
| **Counterpart** | `reviews/A_aa_0074e0d0_LightMgr_SetActiveSlot3c_Refcount_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Unit is a generic refcount helper with unknown slot | **Partially true but overstated** — slot fixed at **+0x3c**; all 3 callers are light attach/tear |
| 2 | Scaffold VOG_DEBUG_STOP name is product | **Falsified** — string is in large caller `00792600`, not this body |
| 3 | Decompiler void/no-arg signature is full ABI | **Falsified** — stack arg + `RET 4`; ECX host |
| 4 | Releases before AddRef (use-after-free if same ptr) | **Falsified** — bytes AddRef new **first**, then Release old (safe self-assign) |
| 5 | Same as `FUN_0074e260` unregister | **Falsified** — `0074e260` walks list `+8/+c` and different release policy; this unit only swaps `+0x3c` |
| 6 | Tear with 0 is a no-op | **Falsified** — still Releases old and stores null |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RET 4 / thiscall / +0x3c | **High** | ABI crash / wrong field |
| Refcount protocol | **High** | leak or double-free |
| Light-domain role | **High** | wrong subsystem port |
| Product class English | **Low** | naming only |
| Runtime | **Open** | matrix |

---

## 3. Cross-check against raw + bytes + callers

```
// Tear (0048eb10):  mov ecx,[esi+4]; push 0; call 0074e0d0
// Rebuild (0048f370): mov ecx,[esi+4]; push <light>; call 0074e0d0
// UI (00792600): push light+0x8c; ECX=mgr-like; call 0074e0d0
// Sibling 0074e310: list insert + different slot math — not this unit
```

Decompile CF matches raw 2026-07-23 and live 2026-08-04.

---

## 4. Surviving contract for AutoCore

```
// Port as thiscall host method:
void LightMgr_SetActiveSlot3c_Refcount_Inferred(Host* host, RefCounted* neu);
// Must: AddRef neu (vtbl+4 on 0→1); Release old at host+0x3c (vtbl+8 on 0); store.
// Must: accept neu==nullptr (clear).
// Must not: walk registration lists (that is FUN_0074e260); invent VOG plate name.
```

---

## 5. Verdict

Adversarial pass confirms A: CF/ABI/slot/callers sealed; naming residual only → **accept**.
