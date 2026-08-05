# Review A (reconstruction fidelity): `aa_005690a0` StdMap_IntKey_InsertNodeAndRebalance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005690a0` |
| **VA** | `0x005690a0` |
| **Body span** | `005690a0` – `0056928a` (**490 B**) |
| **Canonical name** | `StdMap_IntKey_InsertNodeAndRebalance_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_005690a0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W22-E) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005690a0_StdMap_IntKey_InsertNodeAndRebalance_Inferred.md` |
| **System** | stl-map / MSVC `_Tree` insert+rebalance |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`__thiscall` on **MapShell** (`head @ +4`, `size @ +8`): MSVC-style `_Tree::_Insert` helper that **always** constructs a new **0x4C** node and rebalances.

1. If `size > 0x4444442` → throw with **`"map/set<T> too long"`** (inlined exception + length_error vftables).
2. `FUN_00568f60(head, where, head, value, color=0)` → `operator_new(0x4C)`, copy **15 dwords** @ `+0x0C`, color `+0x48=0`, isnil `+0x49=0`.
3. `size++`; link under `where` (empty / left / right + extrema).
4. RB fixup while parent color red (`+0x48 == 0`): uncle recolor; `FUN_00568b70` L-rotate / `FUN_005681a0` R-rotate; one grandparent **L-rotate inlined**.
5. Root black; `*outIt = newNode`; **`RET 0x10`**.

Parents: `StdMap_InsertOrFindByIntKey_Inferred` (`0x00569320`), `StdMap_InsertWithHint_IntKey_Inferred` (`0x00569560`), and `FUN_005692b0`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ W22-E re-verify) | `raw/aa_005690a0_FUN_005690a0.md` |
| Annotated | `raw/aa_005690a0_FUN_005690a0.annotated.md` |
| Clean | `reconstructed-exact/StdMap_IntKey_InsertNodeAndRebalance_Inferred.cpp` |
| Alias | `reconstructed-exact/FUN_005690a0.cpp` |
| Function record | `functions/aa_005690a0_FUN_005690a0.md` |

**This pass (live, OWN VA):**

- Ghidra `decompile_function` @ `0x005690a0` — CF ≡ raw
- Ghidra `read_memory` entry + body + epilogue — `mov edi,ecx`, `cmp [edi+8],0x04444443`, color `+0x48`, isnil `+0x49` in inlined rotate, **`C2 10 00`**
- Ghidra bounds `005690a0`–`0056928a`
- Callees / callers / xrefs
- Context: node ctor `FUN_00568f60` (`new(0x4C)`, 15 dwords); rotates `FUN_00568b70` / `FUN_005681a0`
- Sibling dual `aa_00538ea0` Map_InsertNodeAndRebalance (same rotate helpers, **0x50** nodes)
- Parent duals `aa_00569320` / `aa_00569560` (int key @ `node+0x0C`)
- **Not performed:** Launcher, `disassemble_bytes`, runtime, bit-exact

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| **ECX** | MapShell* | `mov edi,ecx` |
| stack0 | outIt* | `*out = new` |
| stack1 | addLeft | link branch |
| stack2 | where* | parent / head |
| stack3 | value* | 15 dwords into ctor |
| cleanup | **`ret 0x10`** | epilogue |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 490 B + `ret 0x10` thiscall | **High** | bytes |
| Always alloc + rebalance | **High** | no key compare |
| Max size `"map/set<T> too long"` | **High** | plate + cmp |
| Node **0x4C** / 15 dwords / color **+0x48** / isnil **+0x49** | **High** | ctor + body |
| 0=red, 1=black | **High** | `mov ebx,1` |
| L=`00568b70` / R=`005681a0` + one L inlined | **High** | matches sibling pattern |
| Int key domain via parents | **High** role | full value typedef **Open** |
| Product English | **Open** | Inferred name |
| Runtime / bit-exact | **Open** | deferred |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Size cap → throw | **Yes** |
| Node ctor + size++ | **Yes** |
| Empty / left / right link | **Yes** |
| Uncle recolor + rotates (incl. inlined L) | **Yes** |
| Root black; `*outIt = new`; `ret 0x10` | **Yes** |
| No equal-key path | **Yes** |

### Recovered contract

```c
void __thiscall StdMap_IntKey_InsertNodeAndRebalance(
    MapShell *map, Node **outIt, char addLeft,
    Node *where, const void *value15);
// RET 0x10
```

---

## 6. Callers

| Caller | Sites | Role |
|---|---|---|
| `FUN_00569320` InsertOrFindByIntKey | 2 | miss → insert |
| `FUN_00569560` InsertWithHint | 8 | hint insert path |
| `FUN_005692b0` | 1 | related wrapper |

---

## 7. Gaps

1. Product/PDB typedef for this map specialization.
2. Full 15-dword value English (key int @ +0x0C sealed by parents only).
3. Why grandparent L-rotate inlined vs `FUN_00568b70` (codegen; CF sealed).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
