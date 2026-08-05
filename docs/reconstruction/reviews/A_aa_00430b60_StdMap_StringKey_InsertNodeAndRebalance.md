# Review A (reconstruction fidelity): `aa_00430b60` StdMap_StringKey_InsertNodeAndRebalance

| Field | Value |
|---|---|
| **Stable ID** | `aa_00430b60` |
| **VA** | `0x00430b60` |
| **Body span** | `00430b60` – `00430cdd` (**381 B**) |
| **Canonical name** | `StdMap_StringKey_InsertNodeAndRebalance` (**Inferred**) |
| **Ghidra name** | `FUN_00430b60` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W22-E) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00430b60_StdMap_StringKey_InsertNodeAndRebalance.md` |
| **System** | stl-map / MSVC `_Tree` insert+rebalance |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **map/set tree insert + red-black rebalance** for the **string-key** node specialization:

1. If `size > 0x7FFFFFD` → throw length_error with **`"map/set<T> too long"`**.
2. `FUN_0042a890` → `operator_new(0x30)`, copy string key @ `+0x0C`, mapped dword @ `+0x28`, color **red (0)** @ `+0x2C`, isnil **0** @ `+0x2D`.
3. `size++`; link under `where` (empty / left / right + leftmost/rightmost).
4. RB fixup while parent color red; rotates `FUN_0044e010` (L) / `FUN_0042a840` (R).
5. Root black; `*outIt = newNode`; **`RET 0x0C`**.

Always allocates — not insert-or-find (that is parent `FUN_004309c0`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ W22-E re-verify) | `raw/aa_00430b60_FUN_00430b60.md` |
| Annotated | `raw/aa_00430b60_FUN_00430b60.annotated.md` |
| Clean | `reconstructed-exact/StdMap_StringKey_InsertNodeAndRebalance.cpp` |
| Alias | `reconstructed-exact/FUN_00430b60.cpp` |
| Function record | `functions/aa_00430b60_FUN_00430b60.md` |

**This pass (live, OWN VA):**

- Ghidra `decompile_function` @ `0x00430b60` — CF ≡ raw 2026-07-23
- Ghidra `read_memory` entry + mid + epilogue — `cmp [edi+8],0x07FFFFFE`, `mov esi,ecx`, `mov ebx,1`, color `+0x2C`, **`C2 0C 00`**
- Ghidra `get_function_by_address` bounds `00430b60`–`00430cdd`
- Ghidra callees / callers / xrefs
- Context decompile: node ctor `FUN_0042a890`, rotates `FUN_0042a840` / `FUN_0044e010`
- Parent dual `aa_004309c0` StdMap_StringKey_InsertOrFind
- String plate `read_memory` @ `0x00A1530C`
- **Not performed:** Launcher, `disassemble_bytes`, runtime golden, bit-exact image diff

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| **EDI** | MapShell* | size/head uses `[edi+…]` before any mov into EDI |
| **ECX → ESI** | where* | `mov esi,ecx` at entry |
| stack0 | outIt* | store before return |
| stack1 | addLeft | link branch |
| stack2 | valuePair* | ECX for node ctor |
| cleanup | **`ret 0x0C`** | epilogue |

Decompiler `__thiscall` + `unaff_EDI` is a **hazard** — map is EDI, not ECX.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 381 B + `ret 0x0C` | **High** | bounds + epilogue |
| Always alloc + size++ | **High** | no key compare |
| Max size throw plate | **High** | string + `FUN_00401a40` + ThrowInfo |
| Node **0x30** / color **+0x2C** / isnil **+0x2D** | **High** | ctor + rebalance + rotates |
| 0=red, 1=black | **High** | `mov ebx,1`; new color 0 |
| Head left/root/right | **High** | empty + extremum updates |
| `FUN_0044e010` L / `FUN_0042a840` R | **High** | callee decompile isnil +0x2D |
| Callers 004309c0 / 004303c0 / 0044d9f0 | **High** | xrefs |
| Product English / PDB | **Open** | role Inferred |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Size cap → `"map/set<T> too long"` | **Yes** |
| Node ctor + size++ | **Yes** |
| Empty / left / right link + extrema | **Yes** |
| While parent red: uncle recolor + rotates | **Yes** |
| Root black; `*outIt = new` | **Yes** |
| No key compare / no equal path | **Yes** |

### Recovered contract

```c
// EDI=map, ECX=where; RET 0x0C
void StdMap_StringKey_InsertNodeAndRebalance(
    MapShell *map, Node *where,
    Node **outIt, char addLeft, const void *valuePair);
```

---

## 6. Callers

| Caller | Sites | Role |
|---|---|---|
| `FUN_004309c0` StdMap_StringKey_InsertOrFind | 2 | miss → insert |
| `FUN_004303c0` | 6 | string-map mutations |
| `FUN_0044d9f0` | 2 | string-map consumer |

---

## 7. Gaps

1. Product/PDB English symbol for this template instance.
2. Full mapped-value typedef beyond u32 @ `+0x28` (consumers).
3. Runtime multi-insert rebalance capture; bit-exact image diff.
4. Formal Ghidra rename of rotate helpers (roles High).

**Verdict:** **accept-with-gaps**
