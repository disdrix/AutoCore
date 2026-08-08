# Review A (reconstruction fidelity): `aa_00603830` StdTree_EraseAndRebalance_Val28_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00603830` |
| **VA** | `0x00603830` |
| **Body** | `0x00603830`–`0x00603b03` exclusive (**723 B** / `0x2D3`); pad `CC` |
| **Canonical name** | `StdTree_EraseAndRebalance_Val28_Isnil29_Inferred` |
| **Ghidra symbol** | `FUN_00603830` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_00603830_StdTree_EraseAndRebalance_Val28_Isnil29_Inferred.md` |
| **System** | MSVC `std::_Tree` erase + RB rebalance (Val28 / isnil@+0x29) |
| **Agent** | WQ9E-F OWN-ONLY dual |
| **Live tools** | `decompile_function` / `batch_decompile`, `read_memory`, `analyze_function_complete`, callers/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept** — CF/ABI/throw/isnil/size--/ret8/callers sealed; product demangle open |

---

## 1. Purpose

Erase one red-black tree node (Val28 payload, isnil@+0x29): nil-iterator throw, capture successor, unlink, rebalance if erased black, free mapped heap + node, size--, write out-iterator.

```c
// __thiscall RET 8
void StdTree_EraseAndRebalance_Val28_Isnil29_Inferred(
    MapShell* this, Node** outIt, Node* node);
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00603830_FUN_00603830.md` |
| Annotated | `docs/reconstruction/raw/aa_00603830_FUN_00603830.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Val28_Isnil29_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00603830.cpp` |
| Live decompile | ≡ raw 2026-07-23 CF (epilogue restored via `read_memory`) |
| Body hex | entry SEH + `80 78 29 00` isnil; epilogue `size--` + `C2 08 00` |
| Rotates | `FUN_004192a0` Lrotate / `FUN_004192f0` Rrotate (Isnil29 dualed) |
| Min/Max | `FUN_0051b5d0` / `FUN_00421b50` (Isnil29 dualed) |

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Body exclusive end | `0x00603b03` (`CC` after `C2 08 00`) |
| Size | **723** B (Ghidra end ~`0x00603acf` false-truncated on `operator_delete` noreturn) |
| Epilogue | `ret 8`; if `size > 0` then `size--`; `*outIt = successor` |
| isnil test | entry `80 78 29 00` on node |
| color | dword index 10 / byte `+0x28` |
| Throw string | `"invalid map/set<T> iterator"` @ `0x00a152f0`; ThrowInfo `DAT_00acc34c` |
| SEH | `LAB_009a7ef2` |
| Sole xref | `0x0060431f` in `FUN_00604280` |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size / pad / ret 8 | **pass** (bytes) |
| thiscall ECX=map | **pass** |
| isnil@+0x29 / color@+0x28 | **pass** |
| RB erase fixup + L/R rotates | **pass** |
| size-- after delete | **pass** (bytes; decompiler lost to noreturn) |
| Mapped heap free @+0x14 | **pass** |
| Product demangle | **gap** (`_Inferred`) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI (ret 8, two stack args) | **Confirmed** | live ≡ raw + epilogue bytes |
| Erase + rebalance identity | **Confirmed** | classical MSVC erase; peer Val12 |
| isnil@+0x29 / Val28 / node 0x2C | **Confirmed** | isnil opcode; buynode `new(0x2C)` |
| Name role | **High / Inferred English** | structural family naming |
| Runtime / differential | Open | Terminal false |

---

## 6. Gaps

1. Product / MSVC demangle for map value type (int key + vector-ish mapped).  
2. Exact English for mapped fields @+0x10..+0x27 beyond heap free @+0x14.  
3. Dual of sole caller `FUN_00604280` / buynode `FUN_00603b10` (not OWN).  
4. Bit-exact / differential — open.

**Verdict:** **accept**
