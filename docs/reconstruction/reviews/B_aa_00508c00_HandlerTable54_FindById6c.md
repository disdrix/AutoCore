# Review B (skeptical / adversarial): `aa_00508c00` HandlerTable54_FindById6c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508c00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Agent** | W20-R |
| **Counterpart** | `reviews/A_aa_00508c00_HandlerTable54_FindById6c.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is a hash map | Assume O(1) skill map | **Falsified** — pure linear scan; no hash |
| 2 | Count lives on `this` | Local length field | **Falsified** — exclusive count is global `DAT_00d02988` |
| 3 | Matches on entry header / first dword | Common pattern | **Falsified** — match field is **`+0x6c`** |
| 4 | `__cdecl` / no stack cleanup | Ghidra void signature noise | **Falsified** — **`ret 4`**, one stack arg |
| 5 | Same table as `FUN_00508c50` | Twin confusion | **Falsified** — this = **`+0x54`/`DAT_00d02988`**; twin = **`+0x58`/`DAT_00d02984`** |
| 6 | Id `-1` walks full table | Sentinel ignored | **Falsified** — early return 0 |
| 7 | Product name sealed | Scaffold “Skill_GetModifier…” alias | **Not sealed** — structural name only; leave English open |
| 8 | Returns index | Array position | **Falsified** — returns **entry pointer** `table[i]` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Linear scan + `+0x6c` id | **High** | Wrong port of lookup |
| Table at `+0x54` | **High** | Wrong slot vs 0xa twin |
| Global count `DAT_00d02988` | **High** | OOB or empty always |
| ABI thiscall + ret 4 | **High** | Stack imbalance |
| Subtype 0xb association | **High** (caller) | Hook apply miss |
| Registry/entry product types | **Low–Med** | Doc only |

---

## 3. Cross-check against raw / bytes

```text
// decompiler:
if ((param_2 != -1) && (0 < DAT_00d02988)) {
  piVar2 = *(int**)(param_1 + 0x54);
  do {
    if (*(int*)(*piVar2 + 0x6c) == param_2)
      return (*(int**)(param_1 + 0x54))[iVar1];
    iVar1++; piVar2++;
  } while (iVar1 < DAT_00d02988);
}
return 0;
// bytes: ret 4 both paths; mov esi,[ecx+54]; cmp [ebx+6c],edi — MATCH
```

No decomp residual (no unaff_*). Clean must not invent hash or local count.

---

## 4. Surviving contract for AutoCore

```
HandlerTable54_FindById6c(registry, id) -> entry*|null:
  if id == -1 or g_count_d02988 <= 0: return null
  table = registry.ptr_table_at_0x54
  for i in 0 .. g_count_d02988-1:
    if table[i].id_at_0x6c == id: return table[i]
  return null
```

**Port tests:**

* Id `-1` never scans.
* Empty global count returns null without deref.
* Match uses **`+0x6c`**, not `*entry` first field.
* Distinct from `+0x58` twin (subtype 0xa path).

---

## 5. Open questions

1. Loader/populator for `DAT_00d02988` and table vectors.
2. Exact C++ type of entry (vtbl used by callers at `handler.vtbl+4`).
3. Whether multiple entries can share an id (first-wins only sealed).

**Verdict:** **accept**
