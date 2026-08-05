# Review A (reconstruction fidelity): `aa_0074e200` EnvSlot_SetActiveBumpGen

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074e200` |
| **VA** | `0x0074e200`–`0x0074e23c` (**61 B**) |
| **Canonical name** | `EnvSlot_SetActiveBumpGen` |
| **Ghidra name** | `FUN_0074e200` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-Q) |
| **Counterpart** | `reviews/B_aa_0074e200_EnvSlot_SetActiveBumpGen.md` |
| **System** | client / env-slot active publish |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full 61 B) + caller bytes `0x004cdbf0` + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Toggle active flag and bump generation on the related object hanging off an env slot (`*(slot+0x3c)`), gated by global env byte `DAT_00d1f048[+0x0f]`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-Q append) | `docs/reconstruction/raw/aa_0074e200_FUN_0074e200.md` |
| Annotated | `docs/reconstruction/raw/aa_0074e200_FUN_0074e200.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EnvSlot_SetActiveBumpGen.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0074e200.cpp` |
| Function record | `docs/reconstruction/functions/aa_0074e200_EnvSlot_SetActiveBumpGen.md` |
| Live | decompile ≡ raw; full hex seals RET 4 + both store paths |
| Caller | `FUN_004cda90` bytes prove ECX wiring |

---

## 3. Signature (sealed)

```c
// ECX = slot; stack char enable; RET 4; void; leaf
void __thiscall EnvSlot_SetActiveBumpGen(void* slot, char enable);
```

| Formal | Source | Conf |
|---|---|---|
| slot | ECX (`8B 41 3C` uses ECX) | **High** |
| enable | `[esp+4]` (`80 7C 24 04 00`) | **High** |
| cleanup | `C2 04 00` | **High** |
| return | void | **High** |

---

## 4. Control flow (bytes authority)

```
related = *(this+0x3c)
if !related: ret 4
if enable && *(DAT_00d1f048+0xf):
  ++*(related+0xdc); *(related+0xd1)=1; ret 4
++*(related+0xdc); *(related+0xd1)=0; ret 4
```

| Stage | Match | Conf |
|---|---|---|
| Null related early-out | decompile ≡ bytes | **High** |
| Gate AND enable for flag=1 | both paths | **High** |
| Always bump +0xdc when related | both branches | **High** |
| Leaf (no callees) | analyze_function_complete | **High** |

---

## 5. Gaps

- Product class names for slot / related.
- Whether `+0xdc` is generation, dirty stamp, or refcount-like (shape is ++ only, never -- here).
- Full product identity of `DAT_00d1f048` block (env/gfx state; byte `+0xf` also set from env+0x78 elsewhere).
- Runtime verification.

---

## 6. Verdict

ABI, CF, offsets, caller contract, and leaf classification sealed. Product English open → **accept-with-gaps**.
