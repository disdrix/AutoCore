# Review A (reconstruction fidelity): `aa_00409820` StdTree_Predecessor_Isnil29_Edx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00409820` |
| **VA** | `0x00409820`–`0x00409870` inclusive (**81 B** / `0x51`) |
| **Canonical name** | `StdTree_Predecessor_Isnil29_Edx_Inferred` |
| **Ghidra name** | `FUN_00409820` |
| **Review date** | `2026-08-05` (WQ9J-G dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY WQ9J-G) |
| **Counterpart** | `reviews/B_aa_00409820_StdTree_Predecessor_Isnil29_Edx_Inferred.md` |
| **System** | shared `client::stdtree` (MSVC `_Tree` predecessor / iterator--) |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 81 B) + `analyze_function_complete` + call-site bytes |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory + analyze (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

In-place **tree/map iterator predecessor** (`operator--` / `_Dec`). Advances the node pointer stored in the iterator object.

```text
// EDX = iterator*  (holds node*)
node = *it
if (node->isnil(+0x29) != 0):          // header / end
  *it = node->right                    // → max
  return
left = node->left
if (left->isnil == 0):
  // predecessor = rightmost of left subtree
  walk right(+8) while child not nil
  *it = that
  return
// else climb parents(+4) while was left-child
parent = node->parent
while (!parent->isnil && *it == parent->left)
  *it = parent; parent = parent->parent
if (!parent->isnil) *it = parent
```

Classic red-black / MSVC tree predecessor. Node layout: `+0` left, `+4` parent, `+8` right, `+0x29` nil flag.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00409820_FUN_00409820.md` (+ WQ9J-G append) |
| Annotated | `docs/reconstruction/raw/aa_00409820_FUN_00409820.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Predecessor_Isnil29_Edx_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00409820.cpp` |
| Function record | `docs/reconstruction/functions/aa_00409820_FUN_00409820.md` |
| Named record | `docs/reconstruction/functions/aa_00409820_StdTree_Predecessor_Isnil29_Edx_Inferred.md` |
| Live | decompile ≡ raw CF; full 81 B hex; 1 caller / 1 xref |
| Call site | `LEA EDX,[ESP+0x0C]` then `CALL` @ `00405c33` (`FUN_00405bd0`) |
| Twin | ECX ABI `StdTree_Predecessor_Isnil29_Inferred` (`0x004cb4f0`) |

---

## 3. Signature (sealed)

```c
// EDX = node**; void; plain RET
void StdTree_Predecessor_Isnil29_Edx_Inferred(int32_t *it /*EDX*/);
```

| Slot | Source | Conf |
|---|---|---|
| it | **EDX** (`MOV EAX,[EDX]` entry; call-site `LEA EDX`) | **High** |
| ECX | unused (decompiler phantom) | **High** |
| return | void; stores through `*it` only | **High** |
| cleanup | plain **`RET`** (`C3`) ×3 | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| isnil → right (header→max) | **Yes** | **High** |
| Left non-nil → rightmost | **Yes** | **High** |
| Left nil → parent climb while left-child | **Yes** | **High** |
| `*it` store | **Yes** | **High** |
| No callees | **Yes** | **High** |
| isnil every guard `+0x29` | **Yes** (`80 xx 29 00`) | **High** |
| Product template English | role-sealed structural | **Inferred** |

Full hex: `8b028078290074068b40088902c38b088079290075188b410880782900750c908bc88b41088078290074f5890ac38b40048078290075198b0a3b08750b89028b40048078290074ef8078290075028902c3`

---

## 5. Gaps / open

1. Per-site map key/value product types (sole caller uses 2-dword hi/lo keys).
2. Color bit offset unused here.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
