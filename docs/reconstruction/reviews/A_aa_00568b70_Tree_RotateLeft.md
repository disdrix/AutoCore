# Review A (reconstruction fidelity): `aa_00568b70` Tree_RotateLeft

| Field | Value |
|---|---|
| **Stable ID** | `aa_00568b70` |
| **VA** | `0x00568b70` |
| **Body** | `0x00568b70`–`0x00568bbd` (78 bytes) |
| **Canonical name** | `Tree_RotateLeft` (Ghidra `FUN_00568b70`; **Inferred**) |
| **Review date** | `2026-07-29` (W19-K dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00568b70_Tree_RotateLeft.md` |
| **System** | container / map-set tree |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`).

---

## 1. Purpose

Leaf **left rotate** for MSVC-style map/set trees whose nodes expose **isnil @ +0x49**. Used by mission-staging insert/erase rebalance (and other same-layout trees).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00568b70_FUN_00568b70.md` |
| Annotated | `docs/reconstruction/raw/aa_00568b70_FUN_00568b70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Tree_RotateLeft.cpp` |
| Function record | `docs/reconstruction/functions/aa_00568b70_FUN_00568b70.md` |
| Live decompile | `decompile_function` @ `0x00568b70` ≡ raw |
| Machine | `read_memory` 256 B @ `0x00568b70` |
| Callers | `get_function_callers` → `00538780`, `00538ea0`, `00568c60`, `005690a0` |
| Parent duals | `A_aa_00538ea0_*`, `A_aa_00538780_*` (role already High) |

---

## 3. Byte seal (`read_memory` @ `0x00568b70`)

```
8B 54 24 04        mov  edx, [esp+4]          ; x
8B 42 08           mov  eax, [edx+8]          ; y = right
... 
80 7E 49 00        cmp  byte ptr [esi+0x49],0 ; isnil
...
8B 49 04           mov  ecx, [ecx+4]          ; head
3B 51 04           cmp  edx, [ecx+4]          ; root?
...
C2 04 00           ret  4                     ; three epilogues
```

| Claim | Confidence | Evidence |
|---|---|---|
| `__thiscall` map + stack node | **High** | ECX head load; `[esp+4]`; `ret 4` |
| Left rotate (not right) | **High** | pivot via `+8` right; `y->left = x` |
| isnil `@+0x49` | **High** | `cmp [esi+0x49],0` |
| Root at `head+4` | **High** | `cmp edx,[ecx+4]` after `ecx=map+4` |
| Leaf | **High** | no call |
| No recolor | **High** | no `+0x48` touch |

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

## 5. Caller usage (context only)

Insert rebalance (`FUN_00538ea0`) and erase rebalance (`FUN_00538780`) call with `ECX=map`, stack node. Sibling duals already sealed this as L-rotate.

---

## 6. Gaps

1. Product/PDB symbol string — open (`Tree_RotateLeft` INFERRED).
2. Runtime / bit-exact differential — open.
3. Full enumeration of all tree specializations sharing isnil@0x49 — not required for leaf seal.

**Verdict:** **accept**
