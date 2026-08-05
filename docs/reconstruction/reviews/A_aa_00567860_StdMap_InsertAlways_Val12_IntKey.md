# Review A (reconstruction fidelity): `aa_00567860` StdMap_InsertAlways_Val12_IntKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00567860` |
| **VA** | `0x00567860` |
| **Body** | `0x00567860`–`0x005678c0` exclusive (**96** B) |
| **Canonical name** | `StdMap_InsertAlways_Val12_IntKey` (inferred) |
| **Ghidra symbol** | `FUN_00567860` |
| **Review date** | `2026-07-29` (W29-M OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00567860_StdMap_InsertAlways_Val12_IntKey.md` |
| **System** | std map always-insert |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, meta/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Val12 red-black tree **always-insert** by **signed int key**. Walks to insertion point; always calls `Map_TreeInsertAndRebalance_Val12` (`FUN_00567450`); always returns `{it, inserted=1}`.

```
pair{it, inserted=1} = Map_InsertAlways(map, value{key,v1,v2})
// RET 8; this = map in ECX
// NOT insert-or-find — equal keys still insert
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00567860_FUN_00567860.md` (+ W29-M append) |
| Annotated | `raw/aa_00567860_FUN_00567860.annotated.md` |
| Clean | `reconstructed-exact/StdMap_InsertAlways_Val12_IntKey.cpp` |
| Function record | `functions/aa_00567860_StdMap_InsertAlways_Val12_IntKey.md` |
| Live decompile | ≡ raw (2026-07-29) |
| Bytes | `read_memory` @ `0x00567860` — epilogue `C2 08 00` |
| Callees | `0x00567450` insert+rebalance Val12 (W27-R) |
| Callers | `FUN_00565950` ×2 |
| Peers | `0053a1a0` insert-or-find int; `00573810` insert-or-find uint |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` + **`RET 8`** | **High** | epilogue `C2 08 00` |
| Signature `(map, outPair*, value*)` | **High** | stack layout + decompile |
| Out pair `{node* @+0, inserted@+4=1}` | **High** | always stores 1; no 0 path |
| Signed key compare | **High** | `*param_3 < (int)node[3]` |
| Key @ node `+0x0c`, isnil `+0x19` | **High** | walk + gate |
| Equal → go right, still insert | **High** | no equal short-circuit |
| Insert helper `FUN_00567450` | **High** | sole callee; W27-R sole parent of this unit |
| Two static call sites in `00565950` | **High** | xrefs 2026-07-29 |
| Product map type English | **Inferred** | open |
| Runtime / bit-exact | Open | matrix policy |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| Head/root; isnil `+0x19` | **Yes** |
| Walk left if key < node.key else right | **Yes** |
| Always `FUN_00567450` | **Yes** |
| Always `inserted=1` | **Yes** |
| `RET 8` | **Yes** |

---

## 5. Asm-sealed signature + layouts

```
MapShell head@+4
Node key@+0x0c, isnil@+0x19, left=*n, right=n[2]
InsertPair it@+0, inserted@+4
RET 8
```

---

## 6. Gaps

1. Product demangle / map type for spawn-unpack caller maps.
2. Whether any caller depends on multimap-style duplicate keys vs assumed uniqueness.
3. Runtime / differential.

**Verdict:** **accept-with-gaps**
