# Review A (reconstruction fidelity): `aa_0051ce00` Map_EraseNode_Isnil15

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051ce00` |
| **VA** | `0x0051ce00`–`0x0051d0b5` inclusive (**694 B** / exclusive end `0x0051d0b6`) |
| **Canonical name** | `Map_EraseNode_Isnil15` |
| **Ghidra name** | `FUN_0051ce00` |
| **Review date** | `2026-08-04` (WQ9F-G OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_0051ce00_Map_EraseNode_Isnil15.md` |
| **System** | STL / map-set (WQ-009 depth-3 residual; isnil@+0x15) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` (body + epilogue + throw string) + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style red-black **single-node erase** for the **isnil@+0x15 / color@+0x14** node family. Twin role of dualed `Map_EraseNode` / `Map_EraseNode_B` (those use isnil@+0x29) for the smaller-node isnil15 family consumed by dualed `Map_EraseRange_Isnil15`. Throw string `"invalid map/set<T> iterator"` seals STL identity.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `0x0051ce00` (2026-08-04) |
| Disasm | `disassemble_function` through rebalance + delete |
| Bytes | `read_memory` entry + epilogue `0x0051d07d`–`ret 8` + pad `CC` |
| Throw string | `read_memory` `0x00a152f0` → `invalid map/set<T> iterator` |
| Callers | `Map_EraseRange_Isnil15`, `FUN_0051d940`, `FUN_0052c930` |
| Peer erase | dualed `Map_EraseNode` / `_B` isnil29; dualed `Map_EraseNode_IntKey` isnil15 other VA |
| Peer range | dualed `Map_EraseRange_Isnil15` |
| Raw / clean | `raw/aa_0051ce00_*`, `reconstructed-exact/Map_EraseNode_Isnil15.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 694 B; `ret 8` | **Confirmed** | bytes `C2 08 00` @ `0x0051d0b3` |
| `__thiscall` ECX=map; stack `(outIt, node)` | **Confirmed** | entry + ret 8 + caller sites |
| isnil@+0x15 gate + throw string | **Confirmed** | `cmp [node+0x15]` + string bytes |
| color@+0x14 | **Confirmed** | rebalance / two-child color swap |
| Successor `FUN_00673070` | **Confirmed** | first non-throw call |
| Min `004e12a0` / Max `00421b70` | **Confirmed** | leftmost/rightmost refresh |
| Lrot `004e22d0` / Rrot `006753b0` ECX=map | **Confirmed** | black fixup |
| Post-delete size-- + `*outIt=succ` | **Confirmed** | bytes after delete (decomp drops) |
| Two-child transplant live | **Confirmed** | disasm @ `0x0051cf20+` |
| Structural name `Map_EraseNode_Isnil15` | **High** | pairs range isnil15 |
| K/V payload English | Open | |
| Product/PDB symbol | Open | |
| Runtime / bit-exact | Open | no Launcher |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| isnil gate + throw | **Yes** |
| Successor capture | **Yes** |
| Unlink + head begin/root/end refresh | **Yes** |
| Black rebalance L/R rotates | **Yes** |
| Two-child path (bytes; decomp "unreachable") | **Yes** (bytes) |
| Delete + size-- + `*out` + ret 8 | **Yes** (bytes; decomp incomplete) |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| STL erase structure + throw string | **Yes** |
| isnil offset discriminator (+0x15) | **Yes** |
| Pairs dualed `Map_EraseRange_Isnil15` | **Yes** |
| Distinct from `Map_EraseNode_IntKey` VA | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`Map_EraseNode_Isnil15`** (structural; family of `Map_EraseNode` with isnil discriminator).  
**Reject:** merge with `Map_EraseNode` / `_B` (wrong isnil); identity with `Map_EraseNode_IntKey` (different VA/callees); skill-domain erase product names without RTTI.

---

## 6. Gaps

1. Exact `map<K,V>` / `set<K>` instantiation and value size.
2. Full dual of Min/Max/rotate callees (not OWN).
3. Host English for callers `0051d940` / `0052c930`.
4. Runtime / image diff / bit-exact.

**Verdict:** **accept-with-gaps**
