# Review A (reconstruction fidelity): `aa_0046bf90` NestedHash0x10_Insert_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046bf90` |
| **VA** | `0x0046bf90`–`0x0046c1ae` (**543 B**) |
| **Canonical name** | `NestedHash0x10_Insert_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0046bf90` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-B) |
| **Counterpart** | `reviews/B_aa_0046bf90_NestedHash0x10_Insert_Inferred.md` |
| **System** | NestedHash bag (sentinel node 0x10) |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (543 B full) + `analyze_function_complete` + callee decompile. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

**Insert-or-find** on NestedHash0x10:

1. Optional **rehash** when `maxidx(+0x24) <= list_size(+0xc) >> 2` — grow mask or rebuild bucket vector via `FUN_0044a380`.
2. Identity-hash bucket walk (ordered chain) for `kv->key`.
3. **Hit:** write `{node, inserted=0}`; **RET 8**.
4. **Miss:** `FUN_0046c2a0` buynode `new(0x10)` from ESI=kv; `FUN_0046c230(1, map+4)` size++; splice + fix bucket starts; `{node, inserted=1}`; **RET 8**.

Sole nested helpers under sto factory / operator[] / GfxMesh edge bag.

**Not** find-only (`0x0046c1b0`), not erase, not string-key hash_map insert.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0046bf90_FUN_0046bf90.md` (+ W36-B append) |
| Annotated | `docs/reconstruction/raw/aa_0046bf90_FUN_0046bf90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NestedHash0x10_Insert_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0046bf90.cpp` |
| Function record | `docs/reconstruction/functions/aa_0046bf90_FUN_0046bf90.md` |
| Named record | `docs/reconstruction/functions/aa_0046bf90_NestedHash0x10_Insert_Inferred.md` |
| Live | decompile ≡ raw CF; full 543 B hex; 2× `C2 08 00` |
| Callees | `FUN_0044a380`, `FUN_0046c2a0` (`new(0x10)`), `FUN_0046c230` (`"list<T> too long"`) |
| Context | NestedHash0x10 ctor W34-E; sibling find `0x0046c1b0` |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
// EDI=map*; stack out_pair*, kv*; RET 8
void NestedHash0x10_Insert_Inferred(
    void* map /*EDI*/,
    InsertResult* out /*stack*/,
    uint32_t* kv /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| map | **EDI** (`MOV EAX,[EDI+0x0C]`) | **High** |
| out | stack (`MOV [EAX],…`; `MOV BYTE [EAX+4],0/1`) | **High** |
| kv | stack → ESI into buynode | **High** |
| cleanup | **RET 8** (`C2 08 00` ×2) | **High** |
| node size | **0x10** (`operator_new(0x10)` in buynode) | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if load high: grow mask or FUN_0044a380 rebuild; redistribute; maxidx++
idx = key & mask; fold
walk bucket for equal key → {node,0}
else buynode + size++ + splice + bucket repair → {node,1}
```

| Stage | Match | Conf |
|---|---|---|
| Load gate `maxidx <= size>>2` | **Yes** | **High** |
| Identity hash find | **Yes** | **High** |
| Hit inserted=0 | **Yes** | **High** |
| Miss buynode 0x10 + inserted=1 | **Yes** | **High** |
| RET 8 both exits | **Yes** | **High** |
| List size via `FUN_0046c230` | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Prologue / epilogue anchors:

```
51 8B 47 0C 8B 57 24 …     ; EDI map; size / maxidx
…
C6 40 04 01 5B 59 C2 08 00 ; inserted=1; RET 8
…
C6 40 04 00 5B 59 C2 08 00 ; inserted=0; RET 8
```

Body length **543 B**. Full hex: raw W36-B append.

---

## 6. Gaps

- Product/PDB English.
- Full rehash redistribute bit-exact in clean (raw decompile is authority for splice details).
- Unowned callee full contracts.
- Runtime / bit-exact.

**Verdict:** **accept** (rehash detail residual is documentation depth, not CF doubt)
