# Review A (reconstruction fidelity): `aa_005681a0` Tree_RotateRight

| Field | Value |
|---|---|
| **Stable ID** | `aa_005681a0` |
| **VA** | `0x005681a0` |
| **Body** | `0x005681a0`–`0x005681f1` (82 bytes) |
| **Canonical name** | `Tree_RotateRight` (Ghidra `FUN_005681a0`; **Inferred**) |
| **Review date** | `2026-07-29` (W23-B dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005681a0_Tree_RotateRight.md` |
| **System** | container / map-set tree |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`).

---

## 1. Purpose

Leaf **right rotate** for MSVC-style map/set trees whose nodes expose **isnil @ +0x49**. Used by mission-staging insert/erase rebalance (and other same-layout trees). Twin of sealed `Tree_RotateLeft` (`0x00568b70`).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005681a0_FUN_005681a0.md` |
| Annotated | `docs/reconstruction/raw/aa_005681a0_FUN_005681a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Tree_RotateRight.cpp` |
| Function record | `docs/reconstruction/functions/aa_005681a0_FUN_005681a0.md` |
| Live decompile | `decompile_function` @ `0x005681a0` ≡ raw |
| Machine | `read_memory` 96 B @ `0x005681a0` |
| Callers | `get_function_callers` → `00538780`, `00538ea0`, `00568c60`, `005690a0` |
| Parent duals | `A_aa_00538ea0_*` (names this unit R-rotate at High), `A_aa_00568b70_Tree_RotateLeft` |

---

## 3. Byte seal (`read_memory` @ `0x005681a0`)

```
8B 54 24 04        mov  edx, [esp+4]          ; x
8B 02              mov  eax, [edx]            ; y = left
...
80 7E 49 00        cmp  byte ptr [esi+0x49],0 ; isnil
...
8B 49 04           mov  ecx, [ecx+4]          ; head
3B 51 04           cmp  edx, [ecx+4]          ; root?
...
C2 04 00           ret  4                     ; three epilogues
```

Full hex (82 B):
```
8b5424048b02568b700889328b7008807e490075038956048b72048970048b49043b51045e750c894104895008894204c204008b4a043b5108750c894108895008894204c204008901895008894204c20400
```

| Claim | Confidence | Evidence |
|---|---|---|
| `__thiscall` map + stack node | **High** | ECX head load; `[esp+4]`; `ret 4` |
| Right rotate (not left) | **High** | pivot via `*node` left; `y->right = x` |
| isnil `@+0x49` | **High** | `cmp [esi+0x49],0` |
| Root at `head+4` | **High** | `cmp edx,[ecx+4]` after `ecx=map+4` |
| Leaf | **High** | no call |
| No recolor | **High** | no `+0x48` touch |

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

## 5. Caller usage (context only)

Insert rebalance (`FUN_00538ea0`) and erase rebalance (`FUN_00538780`) call with `ECX=map`, stack node. Parent duals already sealed this as R-rotate at High confidence.

---

## 6. Gaps

1. Product/PDB symbol string — open (`Tree_RotateRight` INFERRED).
2. Runtime / bit-exact differential — open.
3. Full enumeration of all tree specializations sharing isnil@0x49 — not required for leaf seal.

**Verdict:** **accept**
