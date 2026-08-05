# Review A (reconstruction fidelity): `aa_0075d610` NDResourceCache_IsKeyPresent_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075d610` |
| **VA** | `0x0075d610`–`0x0075d63f` (**48 B**) |
| **Canonical name** | `NDResourceCache_IsKeyPresent_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0075d610` |
| **Review date** | `2026-07-29` (OWN-ONLY W36-E) |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_0075d610_NDResourceCache_IsKeyPresent_Inferred.md` |
| **System** | NDResourceCache / NestedHash present-check |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (full 48 B) + `analyze_function_complete` + xrefs; nested W21-N FindIterator dual |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Predicate wrapper: **key present in NDResourceCache NestedHash with non-null value**.

```
it = HashMap_FindIterator(cache, key)
return it != cache.end(+0x08) && *(void**)(it + 0x0C) != NULL
```

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0075d610_FUN_0075d610.md` (+ W36-E append) |
| Annotated | `docs/reconstruction/raw/aa_0075d610_FUN_0075d610.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDResourceCache_IsKeyPresent_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0075d610.cpp` |
| Function | `docs/reconstruction/functions/aa_0075d610_FUN_0075d610.md` |
| Named | `docs/reconstruction/functions/aa_0075d610_NDResourceCache_IsKeyPresent_Inferred.md` |
| Live | decompile ≡ scaffold CF; full 48 B hex; 3 callers / 6 sites |
| Nested dual | W21-N `HashMap_FindIterator_Inferred` |

---

## 3. Signature (sealed)

```c
// thiscall ECX=cache/map*; stack key*; RET 4; EAX 0/1
uint32_t __fastcall NDResourceCache_IsKeyPresent_Inferred(void* cache, const void* key);
```

| Slot | Source | Conf |
|---|---|---|
| ECX cache/map | `MOV EDI,ECX` | **High** |
| stack key* | `MOV EBX,[ESP+8]` after push | **High** |
| cleanup | **`RET 4`** both paths | **High** |
| return | EAX 1 / 0 | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
PUSH EBX; key* → EBX
PUSH EDI; cache → EDI
LEA out, &key_slot; PUSH out
CALL HashMap_FindIterator   ; *out = node or end
it = key_slot
POP EDI; POP EBX
if it == EDI.end(+8): return 0
if *(it+0xC) == 0: return 0
return 1
```

| Stage | Match | Conf |
|---|---|---|
| EDI/EBX setup for find | **Yes** | **High** |
| end sentinel gate | **Yes** | **High** |
| value@+0x0C non-null | **Yes** | **High** |
| RET 4 both paths | **Yes** | **High** |
| Product English | open | **Low** |

### Machine bytes (`read_memory`)

```
53 8B 5C 24 08 57 8D 44 24 0C 8B F9 50 E8 …  ; setup + call find
8B 44 24 0C 3B 47 08 5F 5B 74 0E             ; it vs end
83 78 0C 00 74 08 B8 01 00 00 00 C2 04 00   ; value; return 1
33 C0 C2 04 00                               ; return 0
```

---

## 5. Gaps / open

1. Product/PDB method English (IsLoaded / Contains / HasResource).
2. Key object domain residual shared with FindIterator (dword eq / string hash).
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — ABI/CF/gates sealed; residual is product English + runtime only.
