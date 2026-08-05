# Review A (reconstruction fidelity): `aa_0044a8c0` Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044a8c0` |
| **VA** | `0x0044a8c0` |
| **Body** | `0x0044a8c0`–`0x0044aa46` exclusive (**390** B) |
| **Canonical name** | `Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred` |
| **Ghidra symbol** | `FUN_0044a8c0` |
| **Review date** | `2026-07-29` (W27-P OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0044a8c0_Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred.md` |
| **System** | std map/set tree insert + RB rebalance |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete`, `get_function_by_address` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Always-insert a Val12 red-black tree node (buy via `FUN_0046c6c0` with value in ESI), link under `where`, rebalance while parent is red, paint root black, write `*outIt`. Throw on size overflow. Parent owns key walk.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0044a8c0_FUN_0044a8c0.md` (+ W27-P append) |
| Annotated | `docs/reconstruction/raw/aa_0044a8c0_FUN_0044a8c0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred.cpp` |
| Scaffold | `reconstructed-exact/FUN_0044a8c0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0044a8c0_Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | entry, buy site, epilogue |
| Buynode decompile | `FUN_0046c6c0` → `operator_new(0x1c)` + 3-dword copy from ESI |
| Rotate duals | `aa_00573170` / `aa_00418c10` (W26-Q accept) |
| Twin insert dual | `aa_0051c1c0` Map_TreeInsertAndRebalance_Val12 (W25-G) |
| Caller | `FUN_0044a730` (key walk) |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | SEH `LAB_009bc919`; `sub esp,0x44`; **no** `mov edi,ecx` |
| Map this | `cmp [edi+8], 0x15555553`; caller sites `mov edi, ebx` |
| Epilogue | `add esp,0x50; ret 0x10` @ end; pad `CC` |
| Body end | exclusive `0x0044aa46` |
| String | `"map/set<T> too long"` @ `0x00a1530c` |
| ThrowInfo | `DAT_00acc388` |
| Buynode | `mov esi,[esp+0x6c]; push 0; …; call FUN_0046c6c0` |
| Color / isnil | +0x18 / +0x19 (Val12; buy sets isnil=0) |
| Rotates | `mov ecx,edi` before L/R rotate calls |

Entry hex (32 B):

```
64a1000000006aff6819c99b00506489250000000083ec44817f0854555515
```

Epilogue:

```
83c450c21000
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **pass** |
| Body size exclusive end | **pass** (`0044aa46`) |
| `ret 0x10` / 4 stack args | **pass** |
| Map in EDI (not ECX) | **pass** (bytes + caller) |
| Max-size `0x15555553` | **pass** |
| Throw string identity | **pass** |
| Buynode = `FUN_0046c6c0` color 0 + ESI value | **pass** |
| Node `new(0x1c)` Val12 | **pass** (buynode decomp) |
| Link empty / left / right cases | **pass** (decomp CF) |
| RB recolor + rotate callouts | **pass** |
| Clean has no bare `undefined4` | **pass** |
| Product demangle / map type | **gap** |
| Buynode null OOM path | **gap** (no check in decomp) |
| Distinct from `0x0051c1c0` body | **pass** (different buy + EDI) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 0x10 |
| Val12 node layout | **High** | buy + sealed rotates |
| Always-insert | **High** | no key cmp in body |
| ESI buy vs stack buy twin | **High** | bytes + `0046c6c0` |
| Sole caller `FUN_0044a730` | **High** | 2 xrefs |
| Name `…_EsiBuy_Inferred` | **Inferred** | structural |
| Runtime / differential | Open | |

---

## 6. Verdict

**accept-with-gaps** — Val12 always-insert + RB rebalance CF/ABI/throw/ESI-buy sealed; product map demangle and OOM path open.
