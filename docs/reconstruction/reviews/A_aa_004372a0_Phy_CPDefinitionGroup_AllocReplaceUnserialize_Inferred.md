# Review A (reconstruction fidelity): `aa_004372a0` Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004372a0` |
| **VA** | `0x004372a0`–`0x0043733e` exclusive (**158 B** / `0x9E`) |
| **Canonical name** | `Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_004372a0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-E) |
| **Counterpart** | `reviews/B_aa_004372a0_Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred.md` |
| **System** | physics / phyCPDefinition CPDG slot alloc-replace-unserialize |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (158 B full) + `analyze_function_complete` + callers/xrefs + call-site context + `FUN_004371c0` / `FUN_00989850` decompile + vtbl `read_memory` `0x00a9da68`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Allocate **phyCPDefinitionGroupImpl** (`0x14`), AddRef, release previous `*EDI`, store, unserialize **CPDG** via `FUN_00989850`. OOM returns `-1` without touching the slot.

**ABI:** **EDI=`T**`**, stack **reader**, **`RET 4`**, status in **EAX**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-E append) | `docs/reconstruction/raw/aa_004372a0_FUN_004372a0.md` |
| Annotated | `docs/reconstruction/raw/aa_004372a0_FUN_004372a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004372a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004372a0_FUN_004372a0.md` |
| Named record | `docs/reconstruction/functions/aa_004372a0_Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred.md` |
| Live | decompile CF ≡ scaffold; full 158 B hex; `C2 04 00` ×2 |
| Ctor | `FUN_004371c0` — vtbl `00a9da68`, refcount0, container@+0xc |
| Unserialize | `FUN_00989850` — CPDG / phyCPDefinition.cpp strings |
| Release sibling | `RefCountedSlot_ReleaseAndClear` `0x00437150` |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature (sealed)

```c
// EDI=outSlot; stack reader; RET 4
uint32_t Phy_CPDefinitionGroup_AllocReplaceUnserialize_Inferred(
    void** outSlot /*EDI*/,
    void* reader /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| outSlot | **EDI** (`MOV ECX,[EDI]` / `MOV [EDI],ESI`) | **High** |
| reader | stack; `MOV EBX,[ESP+0x1c]` then hybrid unserialize | **High** |
| cleanup | **RET 4** (`C2 04 00` ×2) | **High** |
| OOM | `EAX=-1`, no store | **High** |
| product | CPDG + phyCPDefinitionGroupImpl strings | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
SEH: new(0x14) + FUN_004371c0
if !obj: return -1
AddRef; if first: vtbl+4
release *EDI if any (vtbl+8 on 0)
*EDI = obj
return FUN_00989850(obj)  // EBX=reader
```

| Stage | Match | Conf |
|---|---|---|
| SEH + size 0x14 | **Yes** | **High** |
| Refcount +4 / vtbl+4 / vtbl+8 | **Yes** | **High** |
| Slot-preserving OOM | **Yes** | **High** |
| Body 158 B / RET 4 | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Prologue / epilogue anchors:

```text
0x004372a0: 6A FF 68 EB EF 9B 00   ; SEH push
            6A 14 E8 …            ; PUSH 0x14; operator_new
            …
            89 37 E8 …            ; MOV [EDI],ESI; CALL unserialize
            … C2 04 00            ; RET 4 success
            8B C3 … C2 04 00      ; EAX=EBX(-1); RET 4 OOM
```

---

## 6. Gaps

1. Product/PDB English method name (structural `_Inferred` only).  
2. Ctor field `+0x08` unset — residual layout gap.  
3. Full dual of `FUN_00989850` / `FUN_004371c0` (unowned).  
4. Runtime / bit-exact / differential.

---

## 7. Verdict rationale

ABI, CF, product class (via callee strings), refcount protocol, and OOM policy are sealed by bytes + strings. Remaining gaps are unowned callees and English name — **accept-with-gaps**.
