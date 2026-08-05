# Review A (reconstruction fidelity): `aa_0058dc30` MapFloatTfid_EraseNode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058dc30` |
| **VA** | `0x0058dc30`–`0x0058dee5` (Ghidra truncated `0x0058deb6`) |
| **Canonical name** | `MapFloatTfid_EraseNode_Inferred` |
| **Ghidra name** | `FUN_0058dc30` |
| **Prior aliases** | `Named_CalleeOf_…Client_Input_PollB_0058dc30` (scaffold) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A) |
| **Counterpart** | `reviews/B_aa_0058dc30_MapFloatTfid_EraseNode_Inferred.md` |
| **System tag** | shared tree helper / MapFloatTfid |
| **Agent** | W25-A OWN-ONLY |
| **Verdict** | **accept** on CF / throw / layout / size-- / ret8; **accept-with-gaps** on PDB symbol + out-it slot labels |

**Tools:** Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + xrefs/callees. No `disassemble_bytes`. No Launcher. No parent ledger edits.

---

## 1. Purpose

MSVC **`map`/`set` single-node erase** for the MapFloatTfid node family (isnil `+0x29`): nil throw, unlink, black-node RB fixup, free, size--, out iterator.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | `FUN_0058dc30` |
| Entry | `read_memory` `0x0058dc30` SEH + isnil cmp |
| Epilogue | `read_memory` `0x0058deb0`–`0x0058dee5` size-- / ret 8 |
| String | `0x00a152f0` → `invalid map/set<T> iterator` |
| Caller | sole `FUN_0058df60` dual |
| Twin | `StdMap_EraseIterator_Inferred` @ `0x004baa30` (isnil `+0x15`) |
| Siblings | `MapFloatTfid_FreeSubtree` / `EraseRange` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Nil gate `+0x29` → throw string | **High** | prologue + string bytes |
| Body continues past delete | **High** | size-- / ret 8 bytes |
| ABI thiscall + ret 8 | **High** | `C2 08 00` |
| Color `+0x28` / black==1 fixup | **High** | decomp `param_3[10]` / `+0x28` |
| Head `@tree+4`, size `@tree+8` | **High** | body + parent dual |
| Sole caller = EraseRange | **High** | xrefs |
| MapFloatTfid family name | **High** | sibling seals |
| PDB K/V product names | **Open** | structural |
| Runtime / bit-exact | **Open** | deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| SEH `LAB_009a57b2` | **Yes** |
| isnil throw path | **Yes** |
| Splice + parent rewire | **Yes** |
| begin/rbegin head fixups | **Yes** |
| Black-node RB fixup + rotates | **Yes** |
| `operator_delete` | **Yes** |
| size-- + out-it + `ret 8` | **Yes** (bytes; decomp truncated) |
| Not subtree free / not list unlink | **Yes** |

---

## 5. Gaps

1. Exact symbolic names for out-iterator precompute slots.
2. PDB map typedef (float key / TFID value inferred from gather).
3. `FUN_004cb270` product role.

**Verdict:** CF **accept High**. **accept-with-gaps** for PDB/out-it labels.
