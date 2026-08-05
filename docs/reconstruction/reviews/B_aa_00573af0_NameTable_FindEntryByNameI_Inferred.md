# Review B (skeptical / adversarial): `aa_00573af0` NameTable_FindEntryByNameI

| Field | Value |
|---|---|
| **Stable ID** | `aa_00573af0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00573af0_NameTable_FindEntryByNameI_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Case-sensitive `strcmp` | Body uses `_stricmp` | **Falsified** — **case-insensitive** |
| 2 | Binary search / map | Linear index 0..count | **Falsified** — O(n) |
| 3 | Name at entry+0 | Compare `entry+0x10` | **+0x10** |
| 4 | Count at fixed int field | Count from pointer span `>>2` | **Vector geometry** |
| 5 | Skill-system core | Nested from chat append under RequestCast UX | **Peripheral to cast** — still RequestCast nested residual |
| 6 | Returns index | Returns entry **pointer** or 0 | **Pointer** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `_stricmp` + `+0x10` | **High** | Missed channel match |
| Vector at +0x38/+0x3c | **High** | Wrong container |
| Null on miss/empty | **High** | NRE on ports |
| Product owner type | **Medium** | Naming |

---

## 3. Surviving contract for AutoCore

```csharp
object? NameTable_FindEntryByNameI(NameTable self, string name)
{
    var begin = self.Begin; // +0x38
    var end = self.End;     // +0x3c
    if (begin == null) return null;
    int n = (end - begin) / 4;
    for (int i = 0; i < n; i++) {
        var entry = begin[i];
        if (string.Equals(entry.NameAt0x10, name, StringComparison.OrdinalIgnoreCase))
            return entry;
    }
    return null;
}
```

**Port traps:**

- `StringComparison.Ordinal` (case-sensitive).
- Treating return as index int.
- Assuming sorted for binary search.

---

## 4. Residual gaps

1. Entry full layout.
2. Whether multiple matches possible (returns first).

**Verdict:** **accept**
