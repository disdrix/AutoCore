# Review A (reconstruction fidelity): `aa_0056b400` Weapon_SetSuppressFlag_Cb_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056b400` |
| **VA** | `0x0056b400` |
| **Canonical name** | `Weapon_SetSuppressFlag_Cb_Inferred` |
| **Ghidra symbol** | `FUN_0056b400` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0056b400_Weapon_SetSuppressFlag_Cb_Inferred.md` |
| **System** | combat / weapon flags (nested from `Vehicle_ActivateEnterWorld` via `setDrivingInputs`) |
| **Dual status** | **Written this pass** (no prior `A_aa_*`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Leaf-ish **weapon thiscall** dual to fire-flag family (`Weapon_SetFireFlagPair_Inferred` @ `+0xC7/+0xC8`):

1. Always write **`weapon+0xCB = param_2`** (u8).
2. If **`param_2 != 0`**: zero **`weapon+0xD8`** as **f32** (`xorps` + `movss`) → `0.0f`, then `ret 4`.
3. If **`param_2 == 0`**: if **`weapon+0xC0 != 0`**, call **`CVOGTacArc_UpdateMesh`** (with mesh this from `+0xC0`); else return.

**Not** the same as `+0xC7` fire pair — separate suppress/busy-class flag. `FUN_0056d520` start-fire residual can early-out when `+0xCB` set (see primary fire dual notes).

### ActivateEnterWorld use

For each of 3 hardpoints at `*(vehicle+0x260)` non-null:

```
FUN_0056b400(0);   // clear suppress
FUN_0056a260(0);   // clear fire flag pair
```

Also called from `FUN_004f4eb0`, `FUN_005fe6a0`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_0056b400_*`, `reconstructed-exact/FUN_0056b400.cpp` |
| Function record | `functions/aa_0056b400_FUN_0056b400.md` |
| Sibling dual | `A_aa_0056a260_Weapon_SetFireFlagPair_Inferred` |
| Ghidra | `decompile_function` + `read_memory` 48 B |

### Asm seal (`read_memory` @ entry)

```
8a 44 24 04           mov  al, [esp+4]
84 c0                 test al, al
88 81 cb 00 00 00     mov  [ecx+0xcb], al     ; ALWAYS store
74 0e                 jz   clear_path         ; param==0
0f 57 c0              xorps xmm0, xmm0
f3 0f 11 81 d8 00 00 00  movss [ecx+0xd8], xmm0
c2 04 00              ret  4
clear_path:
8b 89 c0 00 00 00     mov  ecx, [ecx+0xc0]
85 c9                 test ecx, ecx
74 xx                 jz   ret
…                     setup + jmp CVOGTacArc_UpdateMesh
```

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX weapon; `RET 4` one stack byte | **High** | Same ABI family as 0056a260 |
| Always stores `+0xCB` | **High** | Asm before branch |
| Non-zero → `+0xD8 = 0.0f` | **High** | movss; decompile as dword 0 same bits |
| Zero → optional TacArc mesh update via `+0xC0` | **High** CF | Named callee |
| Distinct from fire flags `+0xC7/+0xC8` | **High** | Different offsets; sibling dual |
| Product word “suppress” | **Probable** | Blocks start-fire residual; not RTTI |
| `+0xD8` semantic (timer/heat/aim) | **Tentative** | Zeroed on set only |

---

## 4. Control flow seal

```
Weapon_SetSuppressFlag_Cb_Inferred(weapon, value):
  weapon+0xCB = value
  if value != 0:
    weapon+0xD8 = 0.0f
    return
  if weapon+0xC0 != 0:
    CVOGTacArc_UpdateMesh(weapon+0xC0)  // thiscall on mesh
```

---

## 5. Gaps / open

1. Product English for `+0xCB` / `+0xD8` / `+0xC0` mesh link.
2. Full interaction matrix with `FUN_0056d520` early-out.
3. Runtime / bit-exact deferred.

**Verdict:** **accept-with-gaps**
