# Review A (reconstruction fidelity): `aa_0043d570` StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d570` |
| **VA** | `0x0043d570`–`0x0043d5e0` (**112 B**) |
| **Canonical name** | `StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0043d570` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-A) |
| **Counterpart** | `reviews/B_aa_0043d570_StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred.md` |
| **System** | std red-black map operator[] / get-or-insert (Val12, u32 key) |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 112 B) + `analyze_function_complete` + callers/xrefs; **no** `disassemble_bytes` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + analyze/callers/xrefs only. No Launcher.

---

## 1. Purpose

MSVC `_Tree` **operator[]-style** get-or-insert for unsigned 32-bit keys on Val12 nodes:

1. Lower-bound walk from root (`head->parent`) using isnil@`+0x19`.
2. Equality gate: `cand != end && *key >= cand->key`.
3. Hit → return mapped at node+`0x10`; miss → insert `{*key,0,0}` and return new mapped.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-A append) | `docs/reconstruction/raw/aa_0043d570_FUN_0043d570.md` |
| Annotated | `docs/reconstruction/raw/aa_0043d570_FUN_0043d570.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d570.cpp` |
| Function records | `functions/aa_0043d570_FUN_0043d570.md`, `…_StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred.md` |
| Live | decompile ≡ raw CF; full 112 B hex; plain `C3`; isnil `80 78 19 00`; key `39 48 0C` / `3B 46 0C` |
| Context | Peer W37-Q op[] `0043bd40` (EAX key); sibling find `0043d5e0`; AssPreloader drain caller |

---

## 3. Signature (sealed)

```c
// EDI=map; EDX=const uint32_t* key; EAX=mapped*; RET
int32_t* StdTree_OperatorIndex_Val12_U32Key_EdiEdx_Inferred(
    void *map, const uint32_t *key);
```

| Slot | Source | Conf |
|---|---|---|
| map | **EDI** (`MOV ECX,[EDI+4]`) | **High** |
| key* | **EDX** (`MOV ECX,[EDX]` / `MOV EAX,[EDX]`) | **High** |
| return | **EAX** = node+`0x10` | **High** |
| cleanup | plain **`RET`** (`C3`) | **High** |
| stack formals | none | **High** |

Decompiler shows unused `__fastcall param_1` + `unaff_EDI` — **bytes win**.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
cand = head; node = root (head->parent)
while !isnil(node):
  if node.key < *key: node = right
  else: cand = node; node = left
if cand != head && *key >= cand.key: return cand+0x10
stage {*key,0,0}; insert-hint; return *it+0x10
```

| Stage | Match | Conf |
|---|---|---|
| Body 112 B / ends before `0043d5e0` | **Yes** | **High** |
| isnil@+0x19 / key-u32@+0x0C unsigned | **Yes** | **High** |
| Equality gate after lower_bound | **Yes** | **High** |
| Miss → c8b0 + d7d0 | **Yes** | **High** |
| RET plain | **Yes** | **High** |
| Product map English | inferred only | **Inferred** |

---

## 5. Machine bytes (`read_memory`)

Full body (112 B):

```
8b4f048b410483ec1880781900568bf175168b0a39480c73058b4008eb048bf08b008078190074ec3b770474078b023b460c73340f57c08d4c24088d442410c744240800000000f30f1144240ce8eef2ffff568d7424088bcfe8020200008b0083c0105e83c418c38d46105e83c418c3
```

| Site | Bytes | Meaning |
|---|---|---|
| Map | `8B 4F 04` | head from `[EDI+4]` |
| Root | `8B 41 04` | `[head+4]` parent |
| isnil | `80 78 19 00` | node+`0x19` |
| Key load | `8B 0A` | `*EDX` |
| Hit | `8D 46 10` | mapped @ +`0x10` |
| Miss ret | `8B 00 83 C0 10` | `*it + 0x10` |

---

## 6. Gaps

- Unowned insert helpers `FUN_0043c8b0` / `FUN_0043d7d0` full formal ABI residual.
- Product/PDB map value_type English (AssPreloader tree slot).
- Runtime / bit-exact (no Launcher).

---

## 7. Verdict

Reconstruction fidelity sealed for ABI, body bounds, Val12 layout, unsigned op[] semantics. Insert-helper English residual → **accept-with-gaps**.
