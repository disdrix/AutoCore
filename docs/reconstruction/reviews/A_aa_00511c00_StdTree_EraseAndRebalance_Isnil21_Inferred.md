# Review A (reconstruction fidelity): `aa_00511c00` StdTree_EraseAndRebalance_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00511c00` |
| **VA** | `0x00511c00` |
| **Body** | `0x00511c00`–`0x00511ed3` exclusive (**723 B** / `0x2D3`) |
| **Canonical name** | `StdTree_EraseAndRebalance_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_00511c00` |
| **Review date** | `2026-08-05` (R12-015 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00511c00_StdTree_EraseAndRebalance_Isnil21_Inferred.md` |
| **System** | MSVC std `_Tree` erase + RB rebalance (isnil@+0x21) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_xrefs` / `get_xrefs_to` + `get_function_callees` + `read_memory`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Single-node MSVC `_Tree` erase for the isnil@+0x21 family: throw on nil iterator, unlink + fix head extremities, RB-rebalance if erased black (via dualed L/R rotates), free optional value heap @+0x14, free node, size--, write `*outIt`. Shared STL helper; residual-partition system tag is score-driven, not product-skill logic.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R12-015 re-verify) | `docs/reconstruction/raw/aa_00511c00_FUN_00511c00.md` |
| Annotated | `docs/reconstruction/raw/aa_00511c00_FUN_00511c00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_EraseAndRebalance_Isnil21_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00511c00.cpp` |
| Function records | `functions/aa_00511c00_FUN_00511c00.md` + named |
| Live decompile | ≡ raw CF through delete |
| Live body / epilogue | `read_memory` @ entry + `0x00511e7f`..`0x00511ed2` |
| Parent dual | `StdTree_Rrotate_Isnil21_Inferred` `0x005a27f0` (R11-007) |
| Twin Lrotate | `StdTree_Lrotate_Isnil21_Inferred` `0x0050e9f0` (R10-030) |
| Peer thiscall erase | `StdTree_EraseAndRebalance_Isnil29_Inferred` `0x004cb740` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden, parent ledgers.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Body exclusive end | `0x00511ed3` (`CC` pad after last `C2 08 00`) |
| Size | **723** B / `0x2D3` |
| Epilogue | `RET 8` (`C2 08 00` @ `0x00511ed0`) |
| isnil test | `80 78 21 00` on node at entry |
| color | `[reg+0x20]` black = 1 |
| size-- | `83 C0 FF` / store `[ecx+8]` when size > 0 |
| *outIt | `mov [eax], ecx` after size fix |
| thiscall | `MOV EBX,ECX` @ entry |
| throw string | `"invalid map/set<T> iterator"` @ `0x00a152f0` |
| Ghidra listed end | `0x00511e9f` truncated by false noreturn |

Entry hex (32 B):

```
6aff68f2319a0064a100000000506489250000000083ec488b44245c80782100
```

Epilogue hex (post-delete through RET 8):

```
8b4c24148b410883c4045f3bc65e5d760683c0ff8941088b4c24608b44245c89088b4c244c5b64890d0000000083c454c20800
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw throw/unlink/rebalance | **pass** |
| Body size + `RET 8` sealed | **pass** |
| thiscall ECX=tree + 2 stack args | **pass** |
| isnil@+0x21 / color@+0x20 | **pass** |
| Succ / min / max callees | **pass** (`004e12c0` / `004cb2c0` / `00421a60`) |
| L/R rotates isnil21 | **pass** (`0050e9f0` / `005a27f0`) |
| Two-child splice asm-live | **pass** (`0x00511d1d`; decomp wrong) |
| Value heap free @+0x14 | **pass** |
| size-- + *outIt epilogue | **pass** (byte-sealed) |
| Clean has meaningful name `_Inferred` | **pass** |
| Product demangle | **gap** |
| Inbound callers | **gap** (0 xrefs) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI RET 8 | **High** | live ≡ raw; epilogue sealed |
| Erase + RB rebalance identity | **High** | classical algorithm; peer erase twins |
| isnil@+0x21 layout | **High** | bytes + parent rotate duals |
| Name `StdTree_EraseAndRebalance_Isnil21_Inferred` | **Inferred** | structural + string plate |
| Value_type English | Open | heap @+0x14 only |
| Runtime / differential | Open | |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Classical erase + rebalance CF | **Yes** |
| isnil@+0x21 / color@+0x20 byte seal | **Yes** |
| Dualed isnil21 L/R rotates | **Yes** |
| Throw plate `"invalid map/set<T> iterator"` | **Yes** |
| Peer thiscall RET8 erase (isnil29) | **Yes** (`004cb740`) |
| Product/PDB English | **No** |
| Named callers | **No** (0 xrefs) |

**Decision:** promote **`StdTree_EraseAndRebalance_Isnil21_Inferred`**. Reject insert-merge, skill-specific alias, isnil29/31 family merge, stack-RET0xC merge.

---

## 7. Gaps

1. Product / MSVC demangle for map value_type / heap @+0x14.
2. Zero inbound xrefs — residual / dynamic-or-dead surface unexplained.
3. Two-child splice plate full line-by-line clean fidelity (asm-live; decomp incomplete).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
