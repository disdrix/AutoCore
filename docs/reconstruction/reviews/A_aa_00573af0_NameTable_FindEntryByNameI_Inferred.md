# Review A (reconstruction fidelity): `aa_00573af0` NameTable_FindEntryByNameI

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573af0` |
| **VA** | `0x00573af0`–`0x00573b4c` |
| **Canonical name** | `NameTable_FindEntryByNameI` (INFERRED; Ghidra `FUN_00573af0`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (name vector linear scan) |
| **Counterpart** | `reviews/B_aa_00573af0_NameTable_FindEntryByNameI_Inferred.md` |
| **System** | UI / chat (RequestCast nested via `CDlgChatLog_AppendChannelMessage`) |
| **Parent chain** | `Client_RequestCastSkill` → failure/chat path → `008f8200` → **this** |
| **Verdict** | **accept** |

---

## 1. Purpose

**Case-insensitive linear search** over a pointer vector at **`this+0x38` / `this+0x3c`**:

```
count = (end - begin) >> 2   // if begin != 0 else 0
for i in 0 .. count-1:
    entry = *(begin + i)
    if _stricmp(entry + 0x10, name) == 0:
        return entry
return 0
```

`__thiscall(this, char *name)` — returns matching entry pointer or **null**.

Callers: `FUN_008f8200` (`CDlgChatLog_AppendChannelMessage`), `FUN_0082f8d0`, `FUN_0094d700`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw / annotated / clean | `raw/aa_00573af0_*` |
| Live Ghidra | `decompile_function`, callers |
| Parent dual | `A_aa_008f8200_CDlgChatLog_AppendChannelMessage` (RequestCast nested) |

---

## 3. Signature (sealed)

```c
void * __thiscall NameTable_FindEntryByNameI(NameTable *this, char *name);
// Vector of pointers: begin=*(this+0x38), end=*(this+0x3c)
// Name string at entry+0x10; compare via _stricmp
```

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Linear O(n) scan | **Confirmed** | body loop |
| `_stricmp` (case-insensitive) | **Confirmed** | decompile |
| Name at `entry+0x10` | **Confirmed** | |
| Empty vector → 0 | **Confirmed** | begin==0 short |
| Miss → 0 | **Confirmed** | |
| Product table type (channels vs other) | **Medium** | chat caller High; general name open |

---

## 5. Gaps

1. Product class owning `this` (channel table vs broader string registry).
2. Entry structure beyond `+0x10` name.
3. Runtime seal.

**Verdict:** **accept**
