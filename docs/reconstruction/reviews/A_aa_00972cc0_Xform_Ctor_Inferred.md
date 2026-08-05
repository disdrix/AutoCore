# Review A (reconstruction fidelity): `aa_00972cc0` Xform_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00972cc0` |
| **VA** | `0x00972cc0`–`0x00972d6a` (**171 B** / `0xAB`) |
| **Canonical name** | `Xform_Ctor_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00972cc0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-D) |
| **Counterpart** | `reviews/B_aa_00972cc0_Xform_Ctor_Inferred.md` |
| **System** | gfx-math / shared basis transform |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (body + `DAT_00afdf70` + `g_flOne`) + `analyze_function_complete`; **no** `disassemble_bytes` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leaf default-constructor for the shared **0xC0** transform block: two identity mat4s, identity quat, zero translation, unit scale, clean version/flag/dirty. Returns `this`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00972cc0_FUN_00972cc0.md` (+ W37-D append) |
| Annotated | `docs/reconstruction/raw/aa_00972cc0_FUN_00972cc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Xform_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00972cc0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00972cc0_FUN_00972cc0.md` |
| Named record | `docs/reconstruction/functions/aa_00972cc0_Xform_Ctor_Inferred.md` |
| Live | decompile ≡ scaffold CF; full 171 B hex; identity global + `g_flOne` sealed |
| Context | GfxView `_aligned_malloc(0xC0)` + this; `FUN_0044b440` scale @ `+0x9c`; `FUN_00972e50` rebuild |

---

## 3. Signature (sealed)

```c
// ECX=self; returns this (EAX); plain RET; leaf
XformBlock* Xform_Ctor_Inferred(XformBlock* self /*ECX*/);
```

| Slot | Source | Conf |
|---|---|---|
| self | **ECX** (`MOV EAX,ECX` early; stores via EAX/EDI) | **High** |
| stack formals | none | **High** |
| cleanup | plain `RET` (`C3`) | **High** |
| return | **EAX = this** (entry copy preserved) | **High** |
| decompiler `void` | incomplete | **High** (bytes win) |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
one = g_flOne;  z = 0 (XORPS)
memcpy(self+0x00, DAT_00afdf70, 0x40)   // identity mat4
memcpy(self+0x40, DAT_00afdf70, 0x40)   // identity mat4
self+0x80 = (0,0,0,1)                   // quat
self+0x90 = (0,0,0); +0x9c..+0xb0 = 1   // pos + scale/extra
self+0xb4 = 0; +0xb8 = 0; +0xbc = 0
return self
```

| Stage | Match | Conf |
|---|---|---|
| Dual identity mat4 copy | **Yes** (`REP MOVSD` ×16 ×2) | **High** |
| Quat (0,0,0,1) | **Yes** | **High** |
| Unit scale @ +0x9c path | **Yes** (+ family `FUN_0044b440`) | **High** |
| Version/flag/dirty zero | **Yes** | **High** |
| Leaf | **Yes** (no CALL) | **High** |
| Written span 0xC0 | **Yes** (last store `+0xBC`) | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body (171 B):

```
F3 0F 10 05 A0 F2 A0 00    ; MOVSS XMM0,[g_flOne]
0F 57 C9                   ; XORPS XMM1,XMM1
8B C1                      ; MOV EAX,ECX   ; this + return
56 57
B9 10 00 00 00 BE 70 DF AF 00 8B F8 F3 A5   ; copy mat0
8D 78 40
B9 10 00 00 00 BE 70 DF AF 00 F3 A5         ; copy mat1
; MOVSS stores +0x80..+0xB0 (0 via XMM1, 1 via XMM0)
33 C9                      ; ECX=0 for integer tails
; MOV [EAX+0xB4],ECX ; MOV [EAX+0xB8],CL ; MOV [EAX+0xBC],ECX
5E C3
```

**Globals (`read_memory`):**

| Addr | Hex | Value |
|------|-----|-------|
| `0x00a0f2a0` | `00 00 80 3F` | `1.0f` (`g_flOne`) |
| `0x00afdf70` | `00 00 80 3F` + zeros | 4×4 identity |

---

## 6. Gaps

- Product/PDB class English for the 0xC0 block (`Xform_*` structural / family only).
- Exact product meaning of secondary mat `+0x40` and extra triple `+0xa8..+0xb0`.
- Sibling rebuild/scale helpers not dual-owned here.
- Runtime / bit-exact / differential — open.
- Terminal coverage: **false**.

---

## 7. Verdict

Leaf init CF/ABI/constants/size sealed by decompile + full hex + global reads; naming and secondary field English residual → **accept-with-gaps**.
