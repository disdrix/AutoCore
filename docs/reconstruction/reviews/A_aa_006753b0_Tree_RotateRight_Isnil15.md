# Review A (reconstruction fidelity): `aa_006753b0` Tree_RotateRight_Isnil15

| Field | Value |
|---|---|
| **Stable ID** | `aa_006753b0` |
| **VA** | `0x006753b0` |
| **Body** | `0x006753b0`–`0x00675401` (82 bytes) |
| **Canonical name** | `Tree_RotateRight_Isnil15` (Ghidra `FUN_006753b0`; **Inferred**) |
| **Review date** | `2026-07-29` (W24-O dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_006753b0_Tree_RotateRight_Isnil15.md` |
| **System** | container / map-set tree |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` only (no `disassemble_bytes`).

---

## 1. Purpose

Leaf **right rotate** for MSVC-style map/set trees whose nodes expose **isnil @ +0x15**. Twin of sealed-this-wave `Tree_RotateLeft_Isnil15` (`0x004e22d0`). Staging twin `Tree_RotateRight` (`0x005681a0`, isnil@`+0x49`) is a near-clone differing only in the isnil immediate.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006753b0_FUN_006753b0.md` |
| Annotated | `docs/reconstruction/raw/aa_006753b0_FUN_006753b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Tree_RotateRight_Isnil15.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_006753b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_006753b0_FUN_006753b0.md` |
| Live decompile | `decompile_function` @ `0x006753b0` ≡ raw |
| Machine | `read_memory` 128 B @ `0x006753b0` |
| Callers | `analyze_function_complete` → 30 names (shared with `004e22d0`) |
| Staging twin | `A_aa_005681a0_Tree_RotateRight` (isnil@`+0x49`) |

---

## 3. Byte seal (`read_memory` @ `0x006753b0`)

```
8B 54 24 04        mov  edx, [esp+4]          ; x
8B 02              mov  eax, [edx]            ; y = left
...
80 7E 15 00        cmp  byte ptr [esi+0x15],0 ; isnil
...
8B 49 04           mov  ecx, [ecx+4]          ; head
3B 51 04           cmp  edx, [ecx+4]          ; root?
...
C2 04 00           ret  4                     ; three epilogues
```

Full hex (82 B):
```
8b5424048b02568b700889328b7008807e150075038956048b72048970048b49043b51045e750c894104895008894204c204008b4a043b5108750c894108895008894204c204008901895008894204c20400
```

| Claim | Confidence | Evidence |
|---|---|---|
| `__thiscall` map + stack node | **High** | ECX head load; `[esp+4]`; `ret 4` |
| Right rotate (not left) | **High** | pivot via `*node` left; `y->right = x` |
| isnil `@+0x15` | **High** | `cmp [esi+0x15],0` |
| Root at `head+4` | **High** | `cmp edx,[ecx+4]` after `ecx=map+4` |
| Leaf | **High** | no call |
| No recolor | **High** | no `+0x14` touch |
| Near-clone of `005681a0` | **High** | only isnil imm differs (`15` vs `49`) |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| y = x.left; x.left = y.right | **Yes** |
| isnil parent fixup | **Yes** |
| y.parent = x.parent | **Yes** |
| root / right-child / left-child reattach | **Yes** |
| y.right = x; x.parent = y | **Yes** |
| No callees | **Yes** |

---

## 5. Gaps (non-blocking)

- Product/PDB symbol (Inferred only).
- Runtime / bit-exact not run.

---

## 6. Verdict

Fidelity pass seals polarity, isnil offset, ABI, three reattach cases, and leaf purity → **accept**.
