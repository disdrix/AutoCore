# Review A (reconstruction fidelity): `aa_005fe6a0` CVOGHBWeaponFire_ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005fe6a0` |
| **VA** | `0x005fe6a0` |
| **Canonical name** | `CVOGHBWeaponFire_ctor_Inferred` (Ghidra `FUN_005fe6a0`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005fe6a0_CVOGHBWeaponFire_ctor_Inferred.md` |
| **System** | skills-abilities / weapon fire HB / GhostVehicle |
| **Evidence pass** | Live `batch_decompile`; parent dual `aa_0056d520` Weapon_StartFireAndEnqueueHB; AttachOwner dual lists this ctor |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**`CVOGHBBase` subclass constructor** for weapon-fire / short HB action (object size **0x24** from parent `operator_new`):

1. SEH frame; `CVOGHBBase_ctor(this)`.
2. Vtable ← `PTR_FUN_009dd43c`.
3. `this[4] = 1`, `this[3] = 1` (flags / active seeds).
4. `this[2] = FUN_0056a680(0)` — period/timer helper result.
5. Resolve owner: if `param_2` null → owner null; else MI adjust `param_2 + *(param_2[1]+4) + 4`.
6. `CVOGHBBase_AttachOwnerObject(this, owner)`.
7. `this[7] = 9` (HB type/code **9**).
8. If owner chain field at `+0xB0` (via same MI) non-zero → `FUN_00514ff0(0)`.
9. `FUN_0056b400(1)` — weapon fire-gate latch helper (pairs parent `+0xCB` gate).
10. `(*param_2->vtbl[+0x2c])(1)` — weapon vcall enable.
11. Restore ExceptionList; return `this`.

**Callers:** `Weapon_StartFireAndEnqueueHB` path (`FUN_0056d520` / related), `FUN_005021d0`, `FUN_0056b920`, `FUN_0056be70`, `VehicleNet_UnpackGhostVehicle`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005fe6a0_FUN_005fe6a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005fe6a0_FUN_005fe6a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005fe6a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005fe6a0_FUN_005fe6a0.md` |
| Parent dual | `reviews/A_aa_0056d520_Weapon_StartFireAndEnqueueHB_Inferred.md` |

**Three-rep:** present.

---

## 3. Signature

```c
CVOGHBBase *__thiscall CVOGHBWeaponFire_ctor_Inferred(CVOGHBBase *this, int *weaponOrOwnerChain);
```

| Formal | Source | Conf |
|---|---|---|
| `this` | base ctor + vtbl | **High** |
| `param_2` | MI owner resolve + vtbl+0x2c | **High role / Tentative type name** |
| HB type code 9 at `[7]` | live store | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| CVOGHBBase_ctor → vtbl 009dd43c | **Yes** | **High** |
| flags [3]/[4]=1; [2]=helper(0) | **Yes** | **High** |
| AttachOwner via MI | **Yes** | **High** |
| [7]=9 | **Yes** | **High** |
| optional FUN_00514ff0; FUN_0056b400(1); vtbl+0x2c(1) | **Yes** | **High** |
| return this | **Yes** | **High** |

### Decompiler hazards

- Parent sites may show `FUN_005fe6a0(ptr, 1000)` — Ghidra often mangles `new`+ctor ECX with period arg on wrong formal; **this unit** only has `(this, param_2)`.
- ExceptionList restore line may write `param_1` incorrectly in some captures — treat SEH epilogue as stock MSVC.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CVOGHBBase subclass ctor, vtbl 009dd43c | **High** | body |
| Weapon-fire HB type code 9 | **High** | store + parent enqueue |
| AttachOwner + fire latch helpers | **High** | callees |
| Product class English name | **Tentative** | inferred |
| Runtime | **Open** | deferred |

---

## 6. Gaps

1. Full vtbl 009dd43c method map.
2. Seal MI offsets for owner vs weapon def at +0xB0.
3. Distinguish ghost-unpack construction vs local fire enqueue periods.

**Verdict:** **accept-with-gaps**
