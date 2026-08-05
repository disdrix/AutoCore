# Review A (reconstruction fidelity): `aa_0075b3b0` GfxView_SetNear_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075b3b0` |
| **VA** | `0x0075b3b0`–`0x0075b3cb` (**28 B**) |
| **Canonical name** | `GfxView_SetNear_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0075b3b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-O) |
| **Counterpart** | `reviews/B_aa_0075b3b0_GfxView_SetNear_Inferred.md` |
| **System** | graphics / client camera (GfxView) |
| **Evidence pass** | Live `decompile_function` + `analyze_function_complete` + `read_memory` (full 28 B); 4 callers; leaf; SetFar twin peek |
| **Verdict** | **accept** |

---

## 1. Purpose

Set **near plane** on GfxView and mark projection dirty so `GfxView_EnsureProjection` rebuilds.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0075b3b0_FUN_0075b3b0.md` (+ 2026-07-29 W31-O append) |
| Annotated | `docs/reconstruction/raw/aa_0075b3b0_FUN_0075b3b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GfxView_SetNear_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075b3b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0075b3b0_FUN_0075b3b0.md` |
| Named record | `docs/reconstruction/functions/aa_0075b3b0_GfxView_SetNear_Inferred.md` |
| Live | decompile ≡ raw ≡ full body hex; ECX this; RET 4 |
| Context | Factory `FUN_004cda90` passes 0.5f; EnsureProjection consumes `+0xF0` |

---

## 3. Signature (sealed)

```c
// ECX=GfxView*; stack float; RET 4
void __thiscall GfxView_SetNear_Inferred(GfxView *this, float nearPlane);
```

| Slot | Source | Conf |
|---|---|---|
| this | **ECX** (`MOVSS [ECX+0xF0]`) | **High** |
| nearPlane | **`[ESP+4]` via MOVSS** | **High** |
| cleanup | **`RET 4`** | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
near = float [ESP+4]
[ECX+0xF0] = near
[ECX+0x48] = 1
[ECX+0xCC] = 1
RET 4
```

| Stage | Match | Conf |
|---|---|---|
| Float store near | **Yes** | **High** |
| Dirty +0x48 | **Yes** | **High** |
| Dirty +0xCC | **Yes** | **High** |
| No other side effects | **Yes** (leaf) | **High** |

---

## 5. Machine bytes (`read_memory`)

```
F3 0F 10 44 24 04 B0 01 F3 0F 11 81 F0 00 00 00
88 41 48 88 81 CC 00 00 00 C2 04 00
```

---

## 6. Gaps

- Product method English (SetNear vs SetNearClip) — cosmetic.
- Runtime / bit-exact under live projection rebuild — open.

---

## 7. Verdict

Fidelity pass: ABI, offsets, float typing, dirty contract fully sealed → **accept**.
