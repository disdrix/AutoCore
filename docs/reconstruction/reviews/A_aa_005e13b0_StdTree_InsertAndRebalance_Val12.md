# Review A (reconstruction fidelity): `aa_005e13b0` StdTree_InsertAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e13b0` |
| **VA** | `0x005e13b0` |
| **Body** | `0x005e13b0`–`0x005e159B` exclusive (**491** B) |
| **Canonical name** | `StdTree_InsertAndRebalance_Val12` (inferred peer clone) |
| **Ghidra symbol** | `FUN_005e13b0` |
| **Prior / alias** | Mission Named_CalleeOf_* (narrow) |
| **Review date** | `2026-08-04` (W37-K OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005e13b0_StdTree_InsertAndRebalance_Val12.md` |
| **System** | std map/set tree insert + RB rebalance |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete`, callers/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Always-insert a Val12 red-black tree node (buy via `StdTree_Buynode_Val12`), link under `where`, rebalance while parent is red, paint root black, write `*outIt`. Throw on size overflow. Parent owns key uniqueness.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005e13b0_FUN_005e13b0.md` (+ W37-K append) |
| Annotated | `docs/reconstruction/raw/aa_005e13b0_FUN_005e13b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val12_005e13b0.cpp` |
| Scaffold | `reconstructed-exact/FUN_005e13b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005e13b0_StdTree_InsertAndRebalance_Val12.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | entry + epilogue + max-size immediate |
| Peer duals | W27-Q `00539210`, W25-G `0051c1c0`, W24-I buynode, W26-Q rotates |
| Parent | W30-L `005e18d0` insert-or-find |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | SEH; `MOV EDI,ECX`; `CMP [EDI+8], 0x15555553` (`81 7F 08 54 55 55 15`) |
| Epilogue | `ADD ESP,0x50; RET 0x10` (`83 C4 50 C2 10 00`) |
| Body end | exclusive `0x005e159B` (pad `cc` after) |
| String | `"map/set<T> too long"` @ `0x00a1530c` |
| ThrowInfo | `DAT_00acc388` |
| Buynode call | `FUN_005ae220(..., color=0)` |
| Color / isnil | +0x18 / +0x19 |
| Caller | only `FUN_005e18d0` (2 sites) |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** |
| Body size exclusive end | **pass** (`005e159B` / 491 B) |
| `ret 0x10` / 4 stack args | **pass** |
| thiscall ECX=map | **pass** (`mov edi,ecx`) |
| Max-size constant `0x15555553` | **pass** |
| Throw string identity | **pass** |
| Buynode = `FUN_005ae220` color 0 | **pass** |
| Link empty / left / right cases | **pass** |
| RB recolor + rotate callouts + inlined Lrotate | **pass** |
| Clean has no bare `undefined4` | **pass** |
| Product English | **gap** |
| Buynode null-check | **gap** (not in decomp) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 0x10 |
| Val12 node layout | **High** | paired with sealed buynode/rotates |
| Sole-caller shared with parent dual | **High** | 2 xrefs / 1 function |
| Name peer of `StdTree_InsertAndRebalance_Val12` | **Inferred** | structural; VA-disambiguated clean |
| Runtime / differential | Open | |
