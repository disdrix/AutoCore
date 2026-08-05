# Review A (reconstruction fidelity): `aa_004373b0` Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004373b0` |
| **VA** | `0x004373b0`–`0x00437419` exclusive (**105 B** / `0x69`) |
| **Canonical name** | `Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_004373b0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-E) |
| **Counterpart** | `reviews/B_aa_004373b0_Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred.md` |
| **System** | graphics / gfxMorphWeightArrayImpl MWGT host-slot alloc-replace-unserialize |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (105 B full) + `analyze_function_complete` + callers/xrefs + call-site context + `FUN_0073efc0` decompile + vtbl `read_memory` `0x00aa2f48`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Allocate **gfxMorphWeightArrayImpl** (`0x1c`), inline-ctor (`PTR_FUN_00aa2f48`), AddRef, release previous `host+4`, store (including null), unserialize **MWGT** via `FUN_0073efc0`.

**ABI:** **EBX=host\***, stack **reader**, **`RET 4`**, status in **EAX** (not void).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-E append) | `docs/reconstruction/raw/aa_004373b0_FUN_004373b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004373b0_FUN_004373b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004373b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004373b0_FUN_004373b0.md` |
| Named record | `docs/reconstruction/functions/aa_004373b0_Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred.md` |
| Live | decompile CF ≡ scaffold; full 105 B hex; `C2 04 00` |
| Unserialize | `FUN_0073efc0` — MWGT / gfxMorphWeightArrayImpl.cpp strings |
| First-ref | `FUN_0056f570` bare RET |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
// EBX=host (slot @ +4); stack reader; RET 4
uint32_t Gfx_MorphWeightArray_AllocReplaceUnserialize_Inferred(
    void* host /*EBX*/,
    void* reader /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| host | **EBX** (`[EBX+4]` load/store) | **High** |
| reader | stack; `MOV ECX,[ESP+0xc]` before unserialize | **High** |
| cleanup | **RET 4** | **High** |
| return | EAX passthrough from `FUN_0073efc0`; callers `OR` | **High** |
| product | MWGT + gfxMorphWeightArrayImpl strings | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
new(0x1c)
if obj: inline ctor (vtbl 00aa2f48 + zeros)
if obj: AddRef; if first: vtbl+4
release *(host+4) if any
*(host+4) = obj   // even if null
return FUN_0073efc0(reader, obj)  // ECX=reader, stack=obj
```

| Stage | Match | Conf |
|---|---|---|
| Size 0x1c + inline vtbl | **Yes** | **High** |
| Host+4 slot (not *EBX) | **Yes** | **High** |
| Replace-on-OOM + still unserialize | **Yes** | **High** |
| Body 105 B / RET 4 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Prologue / epilogue anchors:

```text
0x004373b0: 56 57 6A 1C E8 …      ; PUSH ESI/EDI; new(0x1c)
            C7 00 48 2F AA 00    ; MOV [EAX], 0x00aa2f48
            83 46 04 01 … FF 50 04
            8B 4B 04 … FF 52 08  ; release host+4
            8B 4C 24 0C 8B C6 50
            89 73 04 E8 …        ; store; CALL FUN_0073efc0
            5F 5E C2 04 00       ; RET 4
```

---

## 6. Gaps

1. Product/PDB English method name.  
2. Full meaning of fields +8..+0x10 before unserialize fills.  
3. Full dual of `FUN_0073efc0` (unowned).  
4. Host node stride-8 product type (loop `ADD EBX,8`).  
5. Runtime / bit-exact / differential.

---

## 7. Verdict rationale

ABI, CF, product class, host+4 slot, and OOM-replace policy sealed. Gaps are English name + unowned unserialize internals — **accept-with-gaps**.
