# Review A (reconstruction fidelity): `aa_00546060` MissionDef_SetOwnedString_OneLineAccept

| Field | Value |
|---|---|
| **Stable ID** | `aa_00546060` |
| **VA** | `0x00546060` |
| **Canonical name** | `MissionDef_SetOwnedString_OneLineAccept` (tag-sealed; offset `+0x154`) |
| **Ghidra name** | `FUN_00546060` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00546060_MissionDef_SetOwnedString_OneLineAccept.md` |
| **System** | `missions-progression` |
| **Parent chain** | Nested from GiveMission / CompleteObjective → `FUN_00547920` MissionDef_EnsureXmlLoaded (`OneLineAccept` tag) |
| **Dual status** | **Written this pass** (no prior `A_aa_*`) |
| **Verdict** | **accept** |

---

## 1. Purpose

Owned C-string replace twin of `FUN_00545f10` / `00545f80` / `00545ff0`, targeting **`this+0x154`**:

1. Free old `*(char**)(this+0x154)` if non-null (`operator_delete[]`).
2. Null the pointer.
3. `operator_new[](strlen+1)` + byte-copy including terminator.
4. Store new buffer at **`this+0x154`**.

XML product field: **`OneLineAccept`** (parent EnsureXml `_wcsicmp` → this callee).

```c
void __thiscall MissionDef_SetOwnedString_OneLineAccept(MissionDef* this, char* src);
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00546060_FUN_00546060.md` |
| Annotated | `docs/reconstruction/raw/aa_00546060_FUN_00546060.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00546060.cpp` |
| Function record | `docs/reconstruction/functions/aa_00546060_FUN_00546060.md` |
| Live decompile | Ghidra `batch_decompile` `0x00546060` ≡ raw |
| Parent dual | `A/B_aa_00547920_MissionDef_EnsureXmlLoaded` (tag → callee map) |
| Twins already dualed | `A/B_aa_00545f10` (`+0x148`), `00545f80` (`+0x14c`), `00545ff0` (`+0x150`) |
| Caller xrefs | Sole: `FUN_00547920` |

**Not performed:** Launcher, CE, bit-exact image diff, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Owned string at **`+0x154`** | **High** | decompile immediate |
| Free → null → `new[]` → strcpy algorithm | **High** | identical to prior twins |
| `__thiscall(MissionDef*, char*)` | **High** | |
| Product tag **OneLineAccept** | **High** | parent EnsureXml tag chain |
| Does not parse XML itself | **High** | assign only |
| Sole caller EnsureXml | **High** | `get_function_callers` |
| clean ≡ raw ≡ live CF | **High** | |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Delete-old if non-null | Yes |
| Zero pointer then alloc/copy | Yes |
| No extra side effects | Yes |

---

## 5. Gaps

1. Runtime consumers of `+0x154` (UI accept line) not dualed here.
2. Encoding: narrow C-string after convert helper (parent path).

**Verdict:** **accept** — offset + algorithm + tag sealed High.
