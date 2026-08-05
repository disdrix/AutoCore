# Review A (reconstruction fidelity): `aa_0043c2e0` Map_TreeInsertAndRebalance_Val12_EsiBuy

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043c2e0` |
| **VA** | `0x0043c2e0`–`0x0043c45f` exclusive (**383** B) |
| **Canonical name** | `Map_TreeInsertAndRebalance_Val12_EsiBuy` |
| **Ghidra symbol** | `FUN_0043c2e0` |
| **Review date** | `2026-07-29` (W29-D OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0043c2e0_Map_TreeInsertAndRebalance_Val12_EsiBuy.md` |
| **System** | std map/set tree insert + RB rebalance |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `analyze_function_complete` (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Always-insert a Val12 red-black tree node (buy via `FUN_0046c6c0` with value in ESI), link under `where`, rebalance while parent is red, paint root black, write `*outIt`. Throw on size overflow. Parent owns key walk.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043c2e0_FUN_0043c2e0.md` (+ W29-D append) |
| Annotated | `docs/reconstruction/raw/aa_0043c2e0_FUN_0043c2e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Map_TreeInsertAndRebalance_Val12_EsiBuy.cpp` |
| Scaffold | `reconstructed-exact/FUN_0043c2e0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043c2e0_Map_TreeInsertAndRebalance_Val12_EsiBuy.md` |
| Live decompile | ≡ raw CF |
| Live body bytes | full 383 B + epilogue `ret 0x10` |
| Buynode dual | `aa_0046c6c0` StdTree_Buynode_Val12_EsiValue (W28-T **accept**) |
| Twin insert dual | `aa_0044a8c0` Map_TreeInsertAndRebalance_Val12_EsiBuy_Inferred (W27-P) |
| Callers | 6 parents / 23 xrefs |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte / constant seal

| Item | Evidence |
|---|---|
| Prologue | SEH `LAB_009bc919`; `sub esp,0x44`; **no** `mov edi,ecx` |
| Map this | `cmp [edi+8], 0x15555553` |
| Epilogue | `add esp,0x50; ret 0x10`; pad `CC` |
| Body end | exclusive `0x0043c45f` |
| String | `"map/set<T> too long"` @ `0x00a1530c` |
| ThrowInfo | `DAT_00acc388` |
| Buynode | `mov esi,[esp+…]`; `call FUN_0046c6c0` color 0 |
| Color / isnil | +0x18 / +0x19 (Val12) |
| Rotates | `FUN_00446b10` L, `FUN_0040b910` R |

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
| Body size exclusive end | **pass** (`0043c45f`) |
| `ret 0x10` / 4 stack args | **pass** (bytes win vs 3-arg decomp) |
| Map in EDI | **pass** |
| Max-size `0x15555553` | **pass** |
| Throw string identity | **pass** |
| Buynode = `FUN_0046c6c0` + ESI value | **pass** |
| Link empty / left / right cases | **pass** |
| RB recolor + rotate callouts | **pass** |
| Clean has no bare `undefined4` | **pass** |
| Distinct rotate pair vs `aa_0044a8c0` | **pass** |
| Product demangle / map type | **gap** |
| Buynode null OOM path | **gap** |
| Rotate helpers dualed | **gap** (unowned) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI | **High** | live ≡ raw; ret 0x10 |
| Val12 node layout | **High** | buy + color@+0x18 |
| Always-insert | **High** | no key cmp in body |
| ESI buy | **High** | bytes + `0046c6c0` |
| Multi-caller | **High** | 6 parents / 23 xrefs |
| Name structural | **Inferred** | not plate |
| Runtime / differential | Open | |

---

## 6. Verdict

**accept-with-gaps** — Val12 always-insert + RB rebalance CF/ABI/throw/ESI-buy sealed; product map demangle, OOM path, and rotate duals open.
