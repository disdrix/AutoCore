# Review B (skeptical / adversarial): `aa_004a1770` StringTable_FindOrIntern_u16_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a1770` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004a1770_StringTable_FindOrIntern_u16_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Lookup-only (no insert) | **Falsified** — miss paths call `StringVec_PushBack` |
| 2 | Hash map / binary search | **Falsified** — linear index + `+0x1c` stride |
| 3 | Returns pointer / full 32-bit size always | **Falsified** — hit masks `0xffff`; miss is `size-1` |
| 4 | Per-object table (thiscall) | **Falsified** — absolute globals `b0360c/b03610`; ECX fixed `b03608` on push |
| 5 | Scaffold VOG_DEBUG_STOP name | **Falsified** — parent alias trap only; reject |
| 6 | `"Empty"` is query default return string | **Weak** — it is **seeded as table[0]** on first miss, not returned as string |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Find-or-intern shape | High | Wrong env name binding |
| u16 index width | High | Truncation bugs in ports |
| Global singleton table | High | Per-instance state leaks |
| `"Empty"` seed meaning | Medium | Off-by-one if consumer assumes empty slot |

---

## 3. Cross-check

```
raw decompile ≡ empty/begin-null seed path + non-empty miss + hit return.
Caller FUN_004a18b0 stores uint16_t cloudName/skyName.
PushBack dual W33-D seals insert primitive.
```

---

## 4. Surviving contract for AutoCore

```
StringTable_FindOrIntern_u16(name):
  for i, s in g_table:
    if s == name: return u16(i)
  if g_table empty: g_table.push("Empty")
  g_table.push(name)
  return u16(g_table.size() - 1)
```

Port as process-global intern; preserve `"Empty"` seed and 16-bit index contract for env fields.

---

## 5. Open questions

1. Product table / module name.
2. Whether other writers mutate the same vector.
3. Max entries vs `u16` wrap (not checked in body).

**Verdict:** **accept-with-gaps**
