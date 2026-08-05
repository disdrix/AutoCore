# Review A (reconstruction fidelity): `aa_00573510` StdTree_InsertAndRebalance_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573510` |
| **VA** | `0x00573510` |
| **Body** | `0x00573510`–`0x005736FC` exclusive (**492** B) |
| **Canonical name** | `StdTree_InsertAndRebalance_Val12` (inferred) |
| **Ghidra symbol** | `FUN_00573510` |
| **Prior / alias** | `Named_CalleeOf_…Client_ShowInvento…` (narrow) |
| **Review date** | `2026-07-29` (W27-S OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00573510_StdTree_InsertAndRebalance_Val12.md` |
| **System** | std map/set tree insert + RB rebalance |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, meta/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Always-insert a Val12 red-black tree node (buy via `StdTree_Buynode_Val12`), link under `where`, rebalance while parent is red, paint root black, write `*outIt`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00573510_FUN_00573510.md` (+ W27-S append) |
| Annotated | `docs/reconstruction/raw/aa_00573510_FUN_00573510.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val12.cpp` |
| Scaffold | `reconstructed-exact/FUN_00573510.cpp` |
| Function record | `docs/reconstruction/functions/aa_00573510_StdTree_InsertAndRebalance_Val12.md` |
| Live decompile | ≡ raw |
| Twin dual | `aa_0051c1c0` Map_TreeInsertAndRebalance_Val12 (W25-G) |
| Buynode dual | `aa_005ae220` StdTree_Buynode_Val12 (W24-I accept) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | SEH; `mov edi,ecx`; `cmp [edi+8], 0x15555553` |
| Epilogue | `add esp,0x50; ret 0x10` |
| Body end | exclusive `0x005736FC` (pad `cc` after) |
| String | `"map/set<T> too long"` @ `0x00a1530c` |
| ThrowInfo | `DAT_00acc388` |
| Buynode call | `FUN_005ae220(..., color=0)` |
| Color / isnil | +0x18 / +0x19 |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** |
| Body size exclusive end | **pass** |
| `ret 0x10` / 4 stack args | **pass** |
| thiscall ECX=map | **pass** |
| Max-size constant `0x15555553` | **pass** |
| Throw string identity | **pass** |
| Buynode = `FUN_005ae220` color 0 | **pass** |
| Twin of `aa_0051c1c0` pattern | **pass** (structural) |
| Product map type name | **gap** |

---

## 5. Gaps (non-blocking)

1. Product/MSVC demangle for map owned by `FUN_00573810`.  
2. Clean plate omits full RB loop (raw remains authoritative).  
3. Runtime / bit-exact / differential.

---

## 6. Verdict rationale

**accept-with-gaps** — CF, ABI, length constant, buynode, rotates sealed. Naming is structural; sole caller is a lower-bound insert helper, not a product plate.
