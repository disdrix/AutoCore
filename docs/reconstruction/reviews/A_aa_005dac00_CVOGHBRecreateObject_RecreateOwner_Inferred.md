# Review A (reconstruction fidelity): `aa_005dac00` CVOGHBRecreateObject_RecreateOwner_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005dac00` |
| **VA** | `0x005dac00`–`0x005dae45` |
| **Canonical name** | `CVOGHBRecreateObject_RecreateOwner_Inferred` |
| **Ghidra name** | `FUN_005dac00` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W22-J) |
| **Counterpart** | `reviews/B_aa_005dac00_CVOGHBRecreateObject_RecreateOwner_Inferred.md` |
| **System** | combat / world-object lifecycle |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs; callers `0x005dae50`, `0x004cd4e0` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Recreate/rebind HB owner** for `CVOGHBRecreateObject`:

1. Require owner at `this+0x18` and successful `CVOGPhysicsBase` cast with non-null body host `phys+0x8`.
2. Refresh owner resources (`FUN_004bcda0`, owner vcall `+0x2a4`).
3. Cast to `CVOGGraphicsBase`; copy pose/orient; multi-vcall graphics rebind.
4. Phys wake (`vtbl+0x10`), `FUN_00560e90(body,1)`, clear soft flag bit0 `@layout+0x181`.
5. If soft-not-ready (`FUN_00418d10()==0`) → `Object_SetPhysBodyTypeIfNotReady(0)`.
6. Apply **zero** impulse via `DAT_00bc5670` + `FUN_0040d040`.
7. Phys vcall pair `+0x244` → `+0x240`; unless body type is `0x12`/`0x14`, `FUN_00516a00(1)`.
8. Tail `FUN_004cd540(phys_base, 1)`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005dac00_FUN_005dac00.md` (+ W22-J append) |
| Annotated | `docs/reconstruction/raw/aa_005dac00_FUN_005dac00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBRecreateObject_RecreateOwner_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005dac00.cpp` |
| Function record | `docs/reconstruction/functions/aa_005dac00_FUN_005dac00.md` |
| Callers | `CVOGHBRecreateObject_OnHeartBeat`, `FUN_004cd4e0` |
| Live | decompile ≡ raw; prologue/epilogue + RTTI + `DAT_00bc5670` via `read_memory` |

---

## 3. Signature (sealed)

```c
// __thiscall; plain RET; void
void CVOGHBRecreateObject_RecreateOwner_Inferred(void *pHB);
```

| Formal | Source | Conf |
|---|---|---|
| pHB | ECX (`8B F1`); `+0x18` owner | **High** |
| Return | void (`C3`) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live decompile)

```
if owner==0: return
phys = dynamic_cast<PhysicsBase*>(owner)
if phys==0 || phys.body==0: return
refresh + gfx rebind + phys wake
clear flag bit0 @ +0x181
soft? SetPhysBodyTypeIfNotReady(0)
zero impulse
type filter → maybe FUN_00516a00(1)
FUN_004cd540(..., 1)
```

| Stage | Match | Conf |
|---|---|---|
| Owner null / phys body gates | **Yes** | **High** |
| Dual RTTI Physics+Graphics | **Yes** | **High** |
| Flag `&= ~1` @ +0x181 | **Yes** | **High** |
| Zero impulse + soft type request | **Yes** | **High** |
| Type 0x12/0x14 skip `00516a00` | **Yes** | **High** |
| Callers recreate-HB only | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

| Item | Evidence |
|---|---|
| Prologue | `83 EC 20 53 56 8B F1` |
| Epilogue | `5F 5E 5B 83 C4 20 C3` @ end |
| Body size | **582 B** (`0x005dac00`–`0x005dae45`) |
| RTTI Physics | `0x00af8dd0` plate: `CVOGPhysicsBase` |
| RTTI Graphics | `0x00af8df0` plate: `CVOGGraphicsBase` |
| RTTI Cloned | `0x00af8e10` plate: `CVOGClonedObjectBase` |
| Zero vec | `DAT_00bc5670` live zeros |

---

## 6. Confidence / gaps

| Area | Conf |
|---|---|
| ABI + body bounds | **High** |
| Recreate-owner role | **High** structural |
| Vfunc product English | **Open** |
| `FUN_004cd540` / `FUN_00516a00` | **Open** |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — CF/ABI/callers/flag/impulse sealed; product English residuals remain.
