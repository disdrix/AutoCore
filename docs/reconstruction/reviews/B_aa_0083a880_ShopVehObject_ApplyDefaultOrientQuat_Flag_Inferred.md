# Review B (skeptical / adversarial): `aa_0083a880` ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0083a880` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9L-J) |
| **Counterpart** | `reviews/A_aa_0083a880_ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Thiscall ECX=obj | **Falsified** — `MOV ESI,EAX`; ECX only used for xform thiscall (`obj+0x510`) and nested vcall |
| 2 | Identity quaternion | **Falsified** — floats at `DAT_00aaa97c` are non-identity unit quat (‖q‖≈1, not {0,0,0,1}) |
| 3 | Always writes XformState | **Falsified** — flag==0 seeds only `+0x5e0` cache; Xform path only when flag≠0 |
| 4 | Always seeds `+0x5e0` | **Falsified** — flag≠0 path returns without writing `+0x5e0` |
| 5 | Stack arg is host* | **Falsified** — 1-byte flag (`CMP byte [ESP+…]`); callers `PUSH 0` / `PUSH 1` |
| 6 | Is the reindex parent | **Falsified** — callee of dualed reindex `0083ac90` and bind helper `0083ab90` |
| 7 | Decompiler `FUN_0040d1a0(&local)` is complete ABI | **Partial fail of decompiler** — assembly `LEA ECX,[ESI+0x510]; PUSH &local` (thiscall). Annotated/clean correct; Ghidra omits ECX |
| 8 | Product name sealed from RTTI here | **Fails** — shopveh English from parent graph → `_Inferred` |
| 9 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX obj + stack flag + RET 4 | **High** | Wrong ABI / stack smash |
| flag 0 → +0x5e0 / +0x5dc; flag 1 → Xform | **High** | Wrong display pose path |
| DAT_00aaa97c unit quat | **High** | Wrong default orientation |
| Math_QuatNormalize dual (`0076e5e0`) | **High** | Norm residual |
| Helper English (833490/833390/vtbl+0x44) | **Med** (not OWN) | Post-bind side effects |
| Shopveh English | **Med** (caller graph) | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check

```text
// Call sites (assembly authority):
//   0083ada2  PUSH 0 ; MOV EAX, slots[…] ; CALL 0083a880   // reindex post-swap/refresh
//   0083adde  PUSH 0 ; MOV EAX, slots[…] ; CALL 0083a880   // reindex match path
//   0083abe0  PUSH 1 ; MOV EAX,EDI       ; CALL 0083a880   // bind helper end
// Body ends RET 4 both exits; pad CC CC then 0083a950.
// Quat floats (read_memory 00aaa97c):
//   -0.2244063, 0.0923448, -0.9699135, -0.01934201  (norm ≈ 1.0)
```

A ≡ B on live decompile + full disasm + xref assembly_context + `.data` floats.

---

## 4. Surviving contract for AutoCore

```text
// Port as default-orient apply on shopveh slot object:
// - inputs: obj* (register EAX), flag (stack uint8), RET 4
// - load default unit quat from DAT_00aaa97c..988; normalize
// - flag==0: write obj+0x5e0 float[4], set obj+0x5dc=1, normalize again
// - flag!=0: thiscall FUN_0040d1a0(obj+0x510, &q); residual 833490 / vtbl+0x44 / 833390
// Do not treat as thiscall on obj; do not invent identity quat; do not invent RTTI name.
```

---

## 5. Verdict

Adversarial pass confirms A's ABI, dual flag paths, default-quat constants, and caller push 0/1 roles. Rejects thiscall-on-obj / identity / always-Xform overclaims. Residual product English + helper duals → **accept-with-gaps**.
