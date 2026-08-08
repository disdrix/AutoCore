# Review A (reconstruction fidelity): `aa_00441960` StdTree_EraseRange_Isnil11_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00441960` |
| **VA** | `0x00441960`–`0x00441a11` inclusive (**178 B** / `0xB2`) |
| **Canonical name** | `StdTree_EraseRange_Isnil11_Inferred` |
| **Ghidra symbol** | `FUN_00441960` |
| **Prior / alias** | `Named_CalleeOf_Named_gfxUIWindow_00441960` (**retired**); partition `StdTree_EraseAll_ShellA4` |
| **Review date** | `2026-08-05` (MEGA-136 OWN-ONLY dual) |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_00441960_StdTree_EraseRange_Isnil11_Inferred.md` |
| **System** | skills-abilities — std map/set range erase (isnil@+0x11); gfxUIWindow shell@+0xA4 |
| **Live tools** | Ghidra `decompile_function`, `disassemble_function`, `analyze_function_complete`, `get_function_callers`, `get_xrefs_to`, `read_memory` / `read_memory_bytes` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC `_Tree::erase(first, last)` for isnil@+0x11 nodes:

```c
// EDI = MapShell*; RET 0xC; returns outIt*
Node **StdTree_EraseRange_Isnil11_Inferred(
    MapShell *map /*EDI*/, Node **outIt, Node *first, Node *last);
```

- Full clear `[begin,end)==[head->left,head]`: free root via dualed `StdTree_FreeSubtree_Isnil11_Inferred` (`0x00440d20`), reset head + size0, `*outIt=begin`.
- Partial: successor (isnil11) then residual `FUN_004477a0` single erase per node.

Primary host: **gfxUIWindow** MapShell @ **+0xA4** (head @ +0xA8) inside dualed `gfxUIWindow_CompleteDtor` residual path.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ MEGA-136 re-verify) | `docs/reconstruction/raw/aa_00441960_FUN_00441960.md` |
| Annotated | `docs/reconstruction/raw/aa_00441960_FUN_00441960.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseRange_Isnil11_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00441960.cpp` |
| Function records | `functions/aa_00441960_FUN_00441960.md` + named |
| Live decompile | ≡ raw CF; `unaff_EDI` sealed as map |
| Free callee | dualed MEGA-132 `StdTree_FreeSubtree_Isnil11_Inferred` |
| Parent | dualed WQ9L-F `gfxUIWindow_CompleteDtor` @ `0x00759de0` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Entry | `8B 47 04` (`MOV EAX,[EDI+4]`) |
| Full-clear free | `MOV ECX,EDI; CALL 0x00440d20` @ `0x0044197e` |
| Size zero | `C7 47 08 00 00 00 00` @ `0x0044198e` |
| isnil | `80 7E 11 00` / `80 78 11 00` successor immediates |
| Single erase | `PUSH ECX; LEA EAX,[ESP+14]; PUSH EAX; PUSH EDI; CALL 0x004477a0` @ `0x004419f7` |
| Epilogue full | `5E 89 55 00 8B C5 5D 5B C2 0C 00` |
| Epilogue partial | `89 75 00 5E 8B C5 5D 5B C2 0C 00` |
| Body inclusive end | `0x00441a11` (last byte of `RET 0xC`) |
| Hex length | **178 B** sealed via `read_memory_bytes` |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body 178 B / RET 0xC both exits | **pass** |
| EDI = MapShell (not ECX) | **pass** (entry + call sites) |
| Full clear begin/end gate | **pass** |
| Free `00440d20` isnil11 dual | **pass** |
| Partial uses isnil11 successor + `004477a0` | **pass** |
| Distinct from isnil29/31/Val12 ranges | **pass** |
| Clean meaningful name | **pass** (`_Inferred`) |
| Product demangle of map | **gap** |
| Single-erase helper dual | **gap** (residual) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI RET 0xC / EDI map | **High** | live ≡ raw; disasm; call sites |
| isnil@+0x11 successor | **High** | immediates |
| Callers / 2 xrefs | **High** | bulk xrefs + analyze |
| Name `…_Isnil11_Inferred` | **Inferred** | structural; free dual pairs |
| ShellA4 consumer context | **High** | parent dtor + offset seal |
| Runtime / differential | Open | |

---

## 6. Gaps

1. Product demangle for map value_type / key.  
2. Dual of residual single-erase `FUN_004477a0`.  
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
