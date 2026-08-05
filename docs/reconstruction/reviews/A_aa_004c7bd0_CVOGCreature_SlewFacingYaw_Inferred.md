# Review A (reconstruction fidelity): `aa_004c7bd0` CVOGCreature_SlewFacingYaw_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c7bd0` |
| **VA** | `0x004c7bd0`–`0x004c7fc1` |
| **Canonical name** | `CVOGCreature_SlewFacingYaw_Inferred` |
| **Ghidra name** | `FUN_004c7bd0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W22-J) |
| **Counterpart** | `reviews/B_aa_004c7bd0_CVOGCreature_SlewFacingYaw_Inferred.md` |
| **System** | creature / facing / aim |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs; callers SetupGraphics + `005d6b80`/`005d6c10` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Rate-limited **horizontal facing-yaw slew** for a creature/object:

1. Require graphics host `*(this+8)`; extract pose; `_finite` on X.
2. Resolve aim target XZ (linked phys offset **or** free aim / camera slot path).
3. Delta vs self position; reject near-zero horizontal length (`1.192e-7f`).
4. Normalize XZ (Y forced 0); `Math_AcosClamped`; basis extract; optional `2π - ang`.
5. Combine with current yaw `@+0x11c`; sin/cos; alignment dot.
6. If align `< 0.999`: step `= (1-align) * u32ms * 0.001 * 9.6`; signed by 2D cross; wrap; **store `+0x11c`**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c7bd0_FUN_004c7bd0.md` (+ W22-J append) |
| Annotated | `docs/reconstruction/raw/aa_004c7bd0_FUN_004c7bd0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGCreature_SlewFacingYaw_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c7bd0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c7bd0_FUN_004c7bd0.md` |
| Callers | `CVOGCreature_SetupGraphics`, `FUN_005d6b80`, `FUN_005d6c10` |
| Live | decompile ≡ raw; constants + epilogue `C2 04 00` via `read_memory` |

---

## 3. Signature (sealed)

```c
// __thiscall; RET 4; void
void CVOGCreature_SlewFacingYaw_Inferred(void *pCreature, int deltaMs);
```

| Formal | Source | Conf |
|---|---|---|
| pCreature | ECX | **High** |
| deltaMs | stack; may be period ms from HB | **High** |
| Return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live decompile)

```
host? → finite pose → aim path → delta XZ → dist gate → unit XZ
→ acos + basis → wrap combine → align gate → rate step → write +0x11c
```

| Stage | Match | Conf |
|---|---|---|
| Host + finite gates | **Yes** | **High** |
| Dual aim path (phys vs free) | **Yes** | **High** |
| Y zeroed unit dir | **Yes** | **High** |
| Rate formula + 2π wrap | **Yes** | **High** |
| Sole store `+0x11c` | **Yes** | **High** |
| `RET 4` ABI | **Yes** | **High** |

---

## 5. Machine bytes / constants (`read_memory`)

| Item | Evidence |
|---|---|
| Prologue | `55 8B EC 83 E4 F0 83 EC 38 56 8B F1` |
| Epilogue | `5F 5E 8B E5 5D C2 04 00` |
| Body size | **1010 B** |
| `DAT_009cb8d4` | `00 00 00 34` → `1.192e-7f` |
| `DAT_00aaa7dc` | `da 0f c9 40` → `≈6.283185f` |
| `DAT_009cbab0` | `9a 99 19 41` → `9.6f` |
| `DAT_009cbab8` | double `0.999` |
| `g_flMsToSeconds` | `≈0.001f` @ `0x00a0f72c` |
| `DAT_00aaa5dc` | `2^32` float |

Callee: **`Math_AcosClamped` @ `0x0040d0a0`**.

---

## 6. Confidence / gaps

| Area | Conf |
|---|---|
| ABI + rate + wrap + write site | **High** |
| Creature facing role | **High** structural |
| Acos formal (elided in decomp) | **Medium** |
| Aim-slot product English | **Open** |
| Runtime | **Open** |

**Verdict:** **accept-with-gaps** — slew kernel sealed; acos-arg + aim English residuals remain.
