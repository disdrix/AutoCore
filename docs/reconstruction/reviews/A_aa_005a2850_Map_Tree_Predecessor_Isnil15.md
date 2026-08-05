# Review A (reconstruction fidelity): `aa_005a2850` Map_Tree_Predecessor_Isnil15

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a2850` |
| **VA** | `0x005a2850` |
| **Canonical name** | `Map_Tree_Predecessor_Isnil15` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_005a2850_Map_Tree_Predecessor_Isnil15.md` |
| **System** | shared map/tree helper (isnil `+0x15` family) |
| **Wave** | W19-N OWN |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`__fastcall` **leaf** helper: `void Map_Tree_Predecessor_Isnil15(Node** pIt)` with **`ECX = pIt`**.

Classic MSVC `_Tree` / `std::map` **iterator decrement** for nodes whose **isnil** flag lives at **`node+0x15`** and child/parent links are:

| Offset | Field |
|---|---|
| `+0x00` | left* |
| `+0x04` | parent* |
| `+0x08` | right* |
| `+0x15` | isnil (u8); non-zero ⇒ head/end sentinel |

Control flow (sealed):

1. **`cur = *pIt`**. If **`cur->isnil`**: `*pIt = cur->right` (end → rightmost / max) and return.
2. Else if **`cur->left` is not isnil**: set `*pIt` to **rightmost** of the left subtree.
3. Else climb parents: while parent not isnil and `cur == parent->left`, step to parent; if final parent not isnil, `*pIt = parent`.

**No** allocation, rebalance, key compare, color touch, or map-shell access. Pure link walk.

Already referenced as “tree predecessor” by dual `aa_005d2360` Map_InsertOrFind_IntKey. Sibling algorithm: `aa_00537770` Isnil49.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005a2850_FUN_005a2850.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_005a2850_FUN_005a2850.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005a2850.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/Map_Tree_Predecessor_Isnil15.cpp` |
| Function record | `docs/reconstruction/functions/aa_005a2850_Map_Tree_Predecessor_Isnil15.md` |
| Fresh decompile | Ghidra `decompile_function` + `force_decompile` @ `0x005a2850` — CF ≡ raw 2026-07-23 |
| Body image | Ghidra `read_memory` @ `0x005a2850` — leaf (`C3` rets, **no `E8` CALL**); isnil `cmp byte [reg+0x15],0` |
| Callers | `analyze_function_complete` — 21 static callers |
| Sibling dual | `A|B_aa_00537770_Map_Predecessor` (isnil `+0x49`) |
| Parent insert dual | `A_aa_005d2360_Map_InsertOrFind_IntKey` labels `0x005a2850` predecessor |

**Not performed:** `disassemble_bytes`, Launcher, runtime, bit-exact image diff.

---

## 3. Evidence table

| Claim | Evidence | Confidence |
|---|---|---|
| `__fastcall(Node** pIt)` via **ECX**; **no stack args** | Body `mov eax,[ecx]`; all exits **`C3`** | **High** |
| void; mutates `*pIt` only | Stores only through `[ecx]` | **High** |
| isnil at **`+0x15`** | Bytes: `80 78 15 00` throughout | **High** |
| left `+0`, parent `+4`, right `+8` | `mov edx,[eax]`; `mov eax,[eax+4]`; `mov eax,[eax+8]` | **High** |
| isnil path → right child | First arm | **High** |
| left-subtree max via right walk | Second arm | **High** |
| climb while `cur == parent->left` | `cmp edx,[eax]` | **High** |
| Leaf (no callees) | analyze empty; no `E8` | **High** |
| Role = **predecessor** (not successor/insert) | Algorithm + insert dual usage | **High** |
| Product English / MSVC template name | No string this pass | **Open** |
| Runtime / bit-exact | Not run | **Open** |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Load `cur = *pIt` from ECX | **Yes** |
| isnil → `*pIt = right`; ret | **Yes** |
| left non-nil → rightmost of left; ret | **Yes** |
| else climb while left-child; maybe set parent | **Yes** |
| No CALL / no map shell / no key cmp | **Yes** |

---

## 5. Callers (OWN boundary = this VA; listed for context)

21 static xrefs across map insert/find helpers (isnil`+0x15` family), including:

- `Map_InsertOrFind_IntKey` (`0x005d2360`) — predecessor after left step
- `FUN_004e47b0` / `FUN_004e46f0` — insert-or-find with byte key @ `+0x0C`
- Additional map helpers (`FUN_0041b1e0`, `FUN_0050fcd0`, `FUN_0053a460`, …)

Domain meaning of those maps is **caller-owned**.

---

## 6. Gaps

1. Product / MSVC template English name.
2. Full node schemas per caller (only links+isnil here).
3. Runtime multi-iterator decrement capture.
4. Bit-exact image diff.
5. Formal Ghidra rename — role **High**, English Tentative.

---

## 7. Verdict

### **accept-with-gaps**

**Accept because:** Fresh decompile matches raw CF; body bytes seal `__fastcall` ECX iterator, isnil `+0x15`, left/parent/right links, leaf predecessor algorithm; 21 shared callers; sibling Isnil49 dual validates algorithm family. Product name and per-map schemas remain open.
