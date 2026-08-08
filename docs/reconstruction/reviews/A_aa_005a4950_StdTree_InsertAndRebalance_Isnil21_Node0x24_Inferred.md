# Review A (reconstruction fidelity): `aa_005a4950` StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a4950` |
| **VA** | `0x005a4950` |
| **Body** | `0x005a4950`–`0x005a4b3a` inclusive (**491 B** / `0x1EB`) |
| **Canonical name** | `StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred` |
| **Ghidra symbol** | `FUN_005a4950` |
| **Review date** | `2026-08-05` (R12-033 OWN dual; dual start 2646) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_005a4950_StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred.md` |
| **System** | skills-abilities / STL map-set (isnil@+0x21, node 0x24) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_callers` / `get_function_xrefs` + `read_memory`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style **map/set always-insert + red-black rebalance** for the **isnil@+0x21 / node 0x24** family. Parent InsertOrFind-style shell `005a4b70` supplies `where`/`addLeft` after u32 key lower-bound; this unit allocates (buynode `005a4870`), links, rebalances via dualed L/R rotates, returns the new node via `*out`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R12-033 re-verify) | `docs/reconstruction/raw/aa_005a4950_FUN_005a4950.md` |
| Annotated | `docs/reconstruction/raw/aa_005a4950_FUN_005a4950.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_005a4950.cpp` |
| Function record | `docs/reconstruction/functions/aa_005a4950_StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | `read_memory` @ `0x005a4950` length 500 (491 B + `CC` pad) |
| String | `"map/set<T> too long"` @ image string table |
| Buynode | residual `FUN_005a4870` (`operator_new(0x24)`, color@+0x20, isnil@+0x21) |
| Rotates | dualed L `0050e9f0` (R10-030), R `005a27f0` (R11-007 parent dual) |
| Caller | `FUN_005a4b70` (u32 key @ node+0x0C, isnil@+0x21) |
| Peer always-insert | `00407200` StdTree_InsertAndRebalance_Isnil21_Inferred (node 0x28 Val16) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden, parent ledgers.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Body inclusive end | `0x005a4b3a` (`CC` pad after last `C2 10 00`) |
| Size | **491** B / `0x1EB` |
| Epilogue | `83 C4 50 C2 10 00` → **`RET 0x10`** |
| Size gate | `81 7F 08 CB CC CC 0C` / `72` → throw if `size >= 0x0CCCCCCB` |
| isnil test | `80 7A 21 00` @ body+`0x184` |
| color writes | `C6 xx 20 imm` (red=0 / black=1) |
| thiscall | entry `8B F9` (`mov edi,ecx`); caller sites `8B CF` before CALL |
| Leaf rotates | callees include `0050e9f0`, `005a27f0`; one L path inlined |
| Buynode size | `FUN_005a4870` → `operator_new(0x24)` |
| Xrefs | 2 UNCONDITIONAL_CALL / 1 caller |

Full body hex: see raw R12-033 section.

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** |
| Body size inclusive end | **pass** (`005a4b3a`) |
| `RET 0x10` / 4 stack args | **pass** |
| thiscall ECX=map | **pass** (`mov edi,ecx` + caller `mov ecx,edi`) |
| Always-insert CF (no key compare) | **pass** |
| Size gate + `"map/set<T> too long"` | **pass** |
| Buynode + size++ + link + RB + root black + `*out` | **pass** |
| isnil@+0x21 / color@+0x20 | **pass** |
| Node 0x24 (not 0x28 Val16 peer) | **pass** (buynode seal) |
| Shared rotates dualed | **pass** (L/R isnil21) |
| Clean has no bare `undefined4` in typed path | **pass** (`int32_t` / struct) |
| Product demangle | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; RET 0x10 sealed |
| Always-insert + RB identity | **High** | classical algorithm; peer 00407200 CF twin |
| isnil@+0x21 / node 0x24 layout | **High** | bytes + buynode `operator_new(0x24)` |
| Name `…_Node0x24_Inferred` | **Inferred** | structural; product English open |
| Value-type English (u32+vector) | **Probable** | buynode + caller compare; not product-named |
| Runtime / differential | Open | |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| STL throw string | **Yes** |
| RB always-insert structure | **Yes** |
| color@+0x20 / isnil@+0x21 | **Yes** |
| Node size 0x24 via buynode | **Yes** |
| Dualed L/R rotates isnil21 | **Yes** |
| Distinct from 0x28 Val16 always-insert | **Yes** (`00407200`) |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_InsertAndRebalance_Isnil21_Node0x24_Inferred`**. Reject merge with `00407200` Val16/0x28 always-insert, InsertOrFind merge (`005a4b70`), freelist/CNDHash, wrong isnil family.

---

## 7. Gaps

1. Product / MSVC demangle for map value_type / instantiation.
2. Full dual of buynode `005a4870` and parent InsertOrFind `005a4b70` (not OWN).
3. Exact vector element type English inside value payload.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
