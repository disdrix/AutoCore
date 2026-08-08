# Review A (reconstruction fidelity): `aa_00603c90` StdTree_InsertAndRebalance_Val28_Isnil29_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00603c90` |
| **VA** | `0x00603c90` |
| **Body** | `0x00603c90`–`0x00603e7a` exclusive (**490 B** / `0x1EA`); pad `CC` |
| **Canonical name** | `StdTree_InsertAndRebalance_Val28_Isnil29_Inferred` |
| **Ghidra symbol** | `FUN_00603c90` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_00603c90_StdTree_InsertAndRebalance_Val28_Isnil29_Inferred.md` |
| **System** | MSVC `std::_Tree` always-insert + RB rebalance (Val28 / isnil@+0x29) |
| **Agent** | WQ9E-F OWN-ONLY dual |
| **Live tools** | `decompile_function` / `batch_decompile`, `read_memory`, `analyze_function_complete`, callers/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept** — CF/ABI/max-size/buynode/rotates/ret10 sealed; product demangle open |

---

## 1. Purpose

Always-insert a Val28 node under `where` (addLeft selects left vs right link), increment size, RB-fixup while parent is red, paint root black, write `*outIt`.

```c
// __thiscall RET 0x10
void StdTree_InsertAndRebalance_Val28_Isnil29_Inferred(
    MapShell* this, Node** outIt, char addLeft, Node* where, Val28* value);
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00603c90_FUN_00603c90.md` |
| Annotated | `docs/reconstruction/raw/aa_00603c90_FUN_00603c90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val28_Isnil29_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00603c90.cpp` |
| Live decompile | ≡ raw 2026-07-23 |
| Buynode | `FUN_00603b10` → `operator_new(0x2C)` + `FUN_00603730` |
| Rotates | `FUN_004192a0` / `FUN_004192f0` (Isnil29) |
| Sole caller | `FUN_00603f00` @ `0x00603f4a` |

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Body exclusive end | `0x00603e7a` (`CC` after `C2 10 00`) |
| Size | **490** B |
| Epilogue | `ret 0x10` (4 stack args) |
| Max size | `cmp [edi+8], 0x09249247` then throw path |
| Throw string | `"map/set<T> too long"`; ThrowInfo `DAT_00acc388` (length_error) |
| SEH | `LAB_009a7ef2` |
| color/isnil | color @+0x28; isnil @+0x29 on nodes |
| size++ | `*(map+8) += 1` after buynode |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size / pad / ret 0x10 | **pass** |
| thiscall ECX=map | **pass** |
| Max-size throw | **pass** |
| Empty / left / right link + leftmost/rightmost | **pass** |
| RB insert fixup + rotates | **pass** |
| Root painted black; *outIt = n | **pass** |
| Product demangle | **gap** (`_Inferred`) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **Confirmed** | live ≡ raw; ret 0x10 sealed |
| Always-insert identity | **Confirmed** | no equal-key reject in this unit |
| Val28 / isnil29 / node 0x2C | **Confirmed** | max 0x9249247 ≈ 0xFFFFFFFF/0x1C; buynode |
| Name role | **High / Inferred English** | structural family |
| Runtime / differential | Open | Terminal false |

---

## 6. Gaps

1. Product demangle / map typedef English.  
2. Full mapped-type layout beyond key@+0x0C + heap vector pattern.  
3. Dual of buynode `FUN_00603b10` / ctor `FUN_00603730` / caller `FUN_00603f00` (not OWN).  
4. One rebalance arm inlines rotate CF (decompiler shows pointer surgery) — equivalent to Lrotate; port may call helper.  
5. Bit-exact / differential — open.

**Verdict:** **accept**
