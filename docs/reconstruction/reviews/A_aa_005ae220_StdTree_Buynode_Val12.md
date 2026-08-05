# Review A (reconstruction fidelity): `aa_005ae220` StdTree_Buynode_Val12

| Field | Value |
|---|---|
| **Stable ID** | `aa_005ae220` |
| **VA** | `0x005ae220` |
| **Body** | `0x005ae220`–`0x005ae268` exclusive (**72** B) |
| **Canonical name** | `StdTree_Buynode_Val12` (inferred) |
| **Ghidra symbol** | `FUN_005ae220` |
| **Prior / alias** | `Named_CalleeOf_…Skill_CategoryCooldownMap_Insert_005ae220` (narrow) |
| **Review date** | `2026-07-29` (W24-I OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005ae220_StdTree_Buynode_Val12.md` |
| **System** | std map/set tree node buy |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, meta/xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Allocate a **0x1c** red-black tree node and initialize:

1. left / parent / right from three pointer args  
2. 12-byte value (3 dwords) from `*value`  
3. color byte; **isnil = 0**  
4. return node* or null (`operator_new` fail)

Shared `_Buynode` helper — not category-cooldown exclusive despite auto-seed name.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005ae220_FUN_005ae220.md` (+ W24-I append) |
| Annotated | `docs/reconstruction/raw/aa_005ae220_FUN_005ae220.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_Val12.cpp` |
| Scaffold | `reconstructed-exact/FUN_005ae220.cpp` |
| Function record | `docs/reconstruction/functions/aa_005ae220_StdTree_Buynode_Val12.md` |
| Live decompile | ≡ raw |
| Live body bytes | `read_memory` @ `0x005ae220` length 72 |
| Consumer | `FUN_0051c1c0` insert+rebalance (`map/set too long`) |
| Twin | `FUN_005ae1c0` Val20 / 0x24 |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte seal (`read_memory` @ `0x005ae220`)

```
push 0x1c / call operator_new / add esp,4
test eax / jz ret
store left@0, parent@4, right@8
copy value[3] → +0x0c
color → +0x18; isnil=0 @ +0x19
ret 0x14
```

Hex (72 B):

```
6a1ce86bb6edff83c40485c074388b4c24048b54240889088b4c240c8950048948088b4c2410568b318d500c89328b71048972048b4908894a088a542418885018c64019005ec21400
```

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Body size exclusive end | **pass** (`005ae268`) |
| `ret 0x14` | **pass** |
| Null path returns EAX=0 | **pass** |
| isnil forced 0 (not from arg) | **pass** |
| No extra ctor / vtbl stamp | **pass** (plain POD node) |
| Decompiler void vs EAX return | **corrected** |

---

## 5. Gaps

1. Full MSVC demangle for each instantiating map type.  
2. Runtime OOM path.  
3. Bit-exact / differential — open.

**Verdict:** **accept**
