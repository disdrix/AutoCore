# Review A (reconstruction fidelity): `aa_00538780` MissionStagingTree_EraseNode

| Field | Value |
|---|---|
| **Stable ID** | `aa_00538780` |
| **VA** | `0x00538780` |
| **Canonical name** | `MissionStagingTree_EraseNode` (role-sealed; product English open) |
| **Ghidra name** | `FUN_00538780` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00538780_MissionStagingTree_EraseNode.md` |
| **System** | `missions-progression` |
| **Parent chain** | Nested from GiveMission notify `FUN_0052d8b0` @ `0x0052d9cc` (map `LEA ECX,[char+0x508]`) |
| **Dual status** | **Present** (first full A+B dual) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **ordered-map erase single node**:

1. `this` (ECX) = map header (`char+0x508` at mission call sites).
2. Stack: out-iterator / scratch + **node\*** to erase.
3. If node is-nil (`+0x49`) → throw `"invalid map/set<T> iterator"`.
4. Else: rewire parent/left/right links, rebalance red-black colors (`+0x48` / dword-index color at `+0x12`), call rotate helpers (`FUN_00568b70` / `FUN_005681a0` / `FUN_00568180` / `FUN_00537410`), then **`operator_delete(node)`**.

Companion to bulk destroy `FUN_00537ef0`. Used when `FUN_0052d8b0` removes one staging key and when `FUN_00539150` erases a range node-by-node.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00538780_FUN_00538780.md` |
| Annotated | `docs/reconstruction/raw/aa_00538780_FUN_00538780.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00538780.cpp` |
| Function record | `docs/reconstruction/functions/aa_00538780_FUN_00538780.md` |
| Live decompile | `batch_decompile` `0x00538780` (large RB erase; many “unreachable” noise blocks) |
| Entry bytes | `read_memory` — SEH prolog + `CMP byte [node+0x49],0` |
| Call site | `0x0052d9cc`: `LEA ECX,[EBX+0x508]` before CALL |

**Not performed:** full rotate math re-proof, `disassemble_bytes`, Launcher.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = tree erase + free node | **High** | CF + throw string + delete |
| Map `this` = header at `char+0x508` on mission path | **High** | Call-site LEA |
| Invalid erase on nil → C++ exception | **High** | string + `_CxxThrowException` |
| RB rebalance present | **High** | color flips + rotate callees |
| Exact rotate equivalence to Dinkumware | **Probable** | not re-verified line-by-line |
| Product name | **Open** | leave `FUN_*` |

---

## 4. Control flow (role-level)

```
if node.nil: throw invalid iterator
unlink node; fix min/max headers on map
if node was black: rebalance while climbing
operator_delete(node)
```

Decompiler lists many unreachable blocks — **ignore** for fidelity; live body matches raw erase spine.

---

## 5. Gaps

1. Full formal ABI of out-iterator slot (decompiler `param_2`).
2. Rotate helper duals optional (roles sealed as tree internals).
3. Runtime erase-after-grant capture open.

**Verdict:** Erase role High for mission staging map. **accept-with-gaps.**
