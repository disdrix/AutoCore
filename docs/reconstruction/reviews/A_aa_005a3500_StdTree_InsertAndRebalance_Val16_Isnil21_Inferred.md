# Review A (reconstruction fidelity): `aa_005a3500` StdTree_InsertAndRebalance_Val16_Isnil21_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005a3500` |
| **VA** | `0x005a3500` |
| **Body** | `0x005a3500`–`0x005a36ea` inclusive (**491 B** / `0x1EB`) |
| **Canonical name** | `StdTree_InsertAndRebalance_Val16_Isnil21_Inferred` |
| **Ghidra symbol** | `FUN_005a3500` |
| **Prior / alias** | scaffold `FUN_005a3500` only |
| **Review date** | `2026-08-05` (R12-031 OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005a3500_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md` |
| **System** | skills-abilities / STL map-set tree insert + RB rebalance |
| **Parent dual** | `0x005a27f0` `StdTree_Rrotate_Isnil21_Inferred` |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `get_function_callers` / `get_function_xrefs`, `read_memory`, `get_function_by_address` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Always-insert a Val16 red-black tree node (buy via residual `FUN_004e2b80`), link under `where` / `addLeft`, rebalance while parent is red (L/R rotates + recolor + one inlined Lrotate), paint root black, write `*out`. Throw on size overflow (`"map/set<T> too long"`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ R12-031 append) | `docs/reconstruction/raw/aa_005a3500_FUN_005a3500.md` |
| Annotated | `docs/reconstruction/raw/aa_005a3500_FUN_005a3500.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_InsertAndRebalance_Val16_Isnil21_005a3500_Inferred.cpp` |
| Scaffold twin | `reconstructed-exact/FUN_005a3500.cpp` |
| Function record | `docs/reconstruction/functions/aa_005a3500_StdTree_InsertAndRebalance_Val16_Isnil21_Inferred.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | `read_memory` full 491 B + entry 64 B + epilogue |
| String | `"map/set<T> too long"` @ `0x00a1530c` |
| Buynode | residual `FUN_004e2b80` (`operator_new(0x28)`) |
| Rotates | dualed `005a27f0` R; dualed `0050e9f0` L |
| Twin insert | dualed `004e37e0` (R12-012; same CF/size/buynode) |
| Peer insert | dualed `00407200` (buynode `00408990`) |
| Sole caller | residual `FUN_005a3be0` (2 sites) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden, parent ledgers.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | SEH `LAB_009a6342`; `mov edi,ecx` (thiscall) |
| Size gate | `cmp [edi+8], 0x0FFFFFFE` (`81 7f 08 fe ff ff 0f`); `jb` continue |
| Epilogue | `add esp,0x50; ret 0x10` (`83 c4 50 c2 10 00`) @ `0x005a36e5` |
| Body end | inclusive last byte `0x005a36ea`; exclusive `0x005a36eb` (`cc` pad) |
| String | `"map/set<T> too long"` @ `0x00a1530c` (`push 0x00a1530c`) |
| ThrowInfo | `DAT_00acc388` |
| Buynode call | `FUN_004e2b80(..., color=0)` @ `0x005a3592` |
| Lrotate call | `FUN_0050e9f0` @ `0x005a362b` |
| Rrotate calls | `FUN_005a27f0` @ `0x005a3649`, `0x005a365f` |
| Inlined L isnil | `80 7a 21 00` |
| Color / isnil | +0x20 / +0x21 |
| Ghidra bounds | `get_function_by_address`: Body `005a3500 - 005a36ea` |

Entry hex (64 B):

```
64a1000000006aff6842639a00506489250000000083ec44578bf9817f08feffff0f7259680c53a1008d4c2408ff15f8629c008d4c2420c744245000000000ff
```

Epilogue tail:

```
8b42048858208b4424605e89088b4c244c5b5f64890d0000000083c450c21000cc
; ... root black; *out; add esp,0x50; ret 0x10; int3 pad
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **pass** |
| Body size 491 B / end `005a36ea` | **pass** |
| `RET 0x10` / 4 stack args | **pass** |
| thiscall ECX=map | **pass** (`mov edi,ecx`; caller `mov ecx,edi`) |
| Size gate `0x0FFFFFFE` + throw string | **pass** |
| Buynode 0x28 / Val16 / color red / isnil0 | **pass** (live `004e2b80`) |
| Link empty / left / right + extremum | **pass** |
| RB while parent red; L/R + inlined L | **pass** |
| Root black before `*out` | **pass** |
| Always-insert (no key compare) | **pass** |
| Clean has no bare `undefined4` | **pass** (`uint32_t` / typed nodes) |
| Twin `004e37e0` same structural role | **pass** |
| Product demangle | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; RET 0x10 sealed |
| Always-insert identity | **High** | classical algorithm; twin dualed R12-012 |
| Val16 / isnil@+0x21 layout | **High** | buynode + isnil imm + color@+0x20 |
| Name `StdTree_InsertAndRebalance_Val16_Isnil21_Inferred` | **Inferred** | structural; product English open |
| Runtime / differential | Open | |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| STL throw string | **Yes** |
| RB always-insert structure | **Yes** |
| Family buynode Val16 isnil21 | **Yes** (`004e2b80`) |
| Twin dualed `004e37e0` same name | **Yes** (R12-012) |
| Peer dualed `00407200` (different buynode) | **Yes** |
| Parent dual Rrotate isnil21 | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_InsertAndRebalance_Val16_Isnil21_Inferred`**. Reject freelist / CNDHash / InsertHint-merge / isnil29 family merge / key-compare-in-body. Clean path VA-qualified (`…_005a3500_…`) to avoid overwrite of twin `004e37e0` clean.

---

## 7. Gaps

1. Product/PDB symbol for this MSVC map instantiation.
2. Residual dual of buynode `004e2b80` and parent shell `005a3be0`.
3. Exact pair-key English under parent (caller compares node+0x10/+0x14).
4. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
