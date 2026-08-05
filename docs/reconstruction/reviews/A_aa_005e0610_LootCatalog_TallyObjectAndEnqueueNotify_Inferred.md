# Review A (reconstruction fidelity): `aa_005e0610` LootCatalog_TallyObjectAndEnqueueNotify_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e0610` |
| **VA** | `0x005e0610`–`0x005e07c5` exclusive (**437 B** / `0x1B5`) |
| **Canonical name** | `LootCatalog_TallyObjectAndEnqueueNotify_Inferred` |
| **Ghidra name** | `FUN_005e0610` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-AA) |
| **Counterpart** | `reviews/B_aa_005e0610_LootCatalog_TallyObjectAndEnqueueNotify_Inferred.md` |
| **System** | loot catalog / CloneBase load accounting |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full body) + callers/callees/xrefs + callee decompiles (`005e0480`, `004149d0`, caller `00541e70`). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

On CloneBase load of a catalog-eligible object: derive loot **type** (with clonebase kind overrides), optionally **insert-or-find** a Val12 map entry (type `0xC` path), map type→**row**, bump four **manager counters**, and when `notifyPath∈{0,1}` **push object id** onto a path-selected reaction vector.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-AA append) | `docs/reconstruction/raw/aa_005e0610_FUN_005e0610.md` |
| Annotated | `docs/reconstruction/raw/aa_005e0610_FUN_005e0610.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LootCatalog_TallyObjectAndEnqueueNotify_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_005e0610.cpp` |
| Function record | `docs/reconstruction/functions/aa_005e0610_LootCatalog_TallyObjectAndEnqueueNotify_Inferred.md` |
| Related duals | `005e0480` type→row; `005e18d0` Val12 insert-or-find (W30-L) |
| Live | decompile skeleton ≡ raw; **bytes correct** bucket/counters/notify bases |

---

## 3. Signature (sealed)

```c
// ECX = manager*; stack object*, bandIndex, notifyPath; RET 0x0C; void
void __thiscall LootCatalog_TallyObjectAndEnqueueNotify_Inferred(
    LootCatalogManagerOpaque* mgr,
    GameObjectOpaque* obj,
    int bandIndex,
    int notifyPath);
```

| Formal | Source | Conf |
|---|---|---|
| mgr | ECX (`8B F1`) | **High** |
| obj / band / path | stack; **`C2 0C 00`** | **High** |
| obj+0x34 id, +0x38 type, +0x3c clonebase* | decompile + uses | **High** |
| counters @ +0x13ce0c / +0x13ce1c / +0x13cf5c / +0x13cf8c | `ADD [ESI+idx*4+disp], EBX` with EBX=1 | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| vfunc `[cb.vt+0x14]()` | decompile + entry bytes | **High** |
| type remap 0xB→0x46, 0xA→0x44 else obj type | decompile | **High** |
| type 0xC + flags → Val12 insert-or-find on **mgr** | decompile + `005e18d0` this=ESI | **High** |
| skip if `(vfuncRet==-1 && type==0xE)` | bytes | **High** |
| M = map vfuncRet → {0,1,2,3} | **bytes only** (decomp miss) | **High** |
| R = type→row; skip if R<0 | `005e0480` | **High** |
| ++counters[M], [P], [R], [S] | bytes SIB forms | **High** |
| notify path0/1 with bases 0x8700C / 0x0C | bytes lea | **High** |
| RET 0x0C both notify exits | `C2 0C 00` | **High** |

### Bytes formula (notify this)

```
t = 0x50 * (R + 12*M) + P
u = 16 * (S + 9*t)
this = mgr + u + (path==1 ? 0xC : 0x8700C)
CVOGReaction_FailMissionNotify(this, &objectId)  // dword vector push
```

---

## 5. Machine bytes (`read_memory`)

Full body hex (437 B) — raw W37-AA append.

Entry: `83 EC 1C 53 55 56 57 8B F1`.  
Epilogues: `83 C4 1C C2 0C 00` ×2.  
Pad `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | **worker** (catalog tally + enqueue) |
| Callers | `FUN_00541e70` ×3 (`00542341`, `0054236d`, `0054239c`) |
| Callees | vfunc+0x14; `004f1e20`; `00418b80`; `005e18d0`; `005e0480`; `CVOGReaction_FailMissionNotify` |

---

## 7. Gaps

1. Product English for counter banks, reaction grid, and manager type.  
2. Exact Val12 value dword layout beyond key=objectId (flag packing residual).  
3. Semantic name of clonebase vfunc @ +0x14 (only bucket map sealed).  
4. Runtime / bit-exact / differential.

---

## 8. Verdict

**accept-with-gaps** — ABI/CF/type remap/row gate/counters/notify path formula sealed; decompiler defects documented and corrected from bytes; product English residual.
