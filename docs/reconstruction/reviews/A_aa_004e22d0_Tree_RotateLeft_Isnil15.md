# Review A (reconstruction fidelity): `aa_004e22d0` Tree_RotateLeft_Isnil15

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e22d0` |
| **VA** | `0x004e22d0` |
| **Body** | `0x004e22d0`–`0x004e231d` (78 bytes) |
| **Canonical name** | `Tree_RotateLeft_Isnil15` (Ghidra `FUN_004e22d0`; **Inferred**) |
| **Review date** | `2026-07-29` (W24-O dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004e22d0_Tree_RotateLeft_Isnil15.md` |
| **System** | container / map-set tree |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` only (no `disassemble_bytes`).

---

## 1. Purpose

Leaf **left rotate** for MSVC-style map/set trees whose nodes expose **isnil @ +0x15**. Shared by ~30 insert/erase rebalance callers in the isnil15 family. Twin of sealed-this-wave `Tree_RotateRight_Isnil15` (`0x006753b0`). Staging twin `Tree_RotateLeft` (`0x00568b70`, isnil@`+0x49`).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e22d0_FUN_004e22d0.md` |
| Annotated | `docs/reconstruction/raw/aa_004e22d0_FUN_004e22d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Tree_RotateLeft_Isnil15.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004e22d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e22d0_FUN_004e22d0.md` |
| Live decompile | `decompile_function` @ `0x004e22d0` ≡ raw |
| Machine | `read_memory` 128 B @ `0x004e22d0` |
| Callers | `analyze_function_complete` → 30 names (shared with `006753b0`) |
| Parent duals | `A_aa_0054de50_SkillElementTypeMap_TreeInsertAndRebalance` (names rotates) |

---

## 3. Byte seal (`read_memory` @ `0x004e22d0`)

```
8B 54 24 04        mov  edx, [esp+4]          ; x
8B 42 08           mov  eax, [edx+8]          ; y = right
...
80 7E 15 00        cmp  byte ptr [esi+0x15],0 ; isnil
...
8B 49 04           mov  ecx, [ecx+4]          ; head
3B 51 04           cmp  edx, [ecx+4]          ; root?
...
C2 04 00           ret  4                     ; three epilogues
```

Full hex (78 B):
```
8b5424048b4208568b308972088b30807e150075038956048b72048970048b49043b51045e750b8941048910894204c204008b4a043b11750a89018910894204c204008941088910894204c20400
```

| Claim | Confidence | Evidence |
|---|---|---|
| `__thiscall` map + stack node | **High** | ECX head load; `[esp+4]`; `ret 4` |
| Left rotate (not right) | **High** | pivot via `[edx+8]` right; `y->left = x` |
| isnil `@+0x15` | **High** | `cmp [esi+0x15],0` |
| Root at `head+4` | **High** | `cmp edx,[ecx+4]` after `ecx=map+4` |
| Leaf | **High** | no call |
| No recolor | **High** | no `+0x14` touch |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| y = x.right; x.right = y.left | **Yes** |
| isnil parent fixup | **Yes** |
| y.parent = x.parent | **Yes** |
| root / left-child / right-child reattach | **Yes** |
| y.left = x; x.parent = y | **Yes** |
| No callees | **Yes** |

---

## 5. Gaps (non-blocking)

- Product/PDB symbol (Inferred only).
- Runtime / bit-exact not run.
- Value-payload typedef varies by map consumer (links+isnil sealed).

---

## 6. Verdict

Fidelity pass seals polarity, isnil offset, ABI, three reattach cases, and leaf purity → **accept**.
