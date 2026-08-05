# Review B (skeptical / adversarial): `aa_00508c50` HandlerTable58_FindById6c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508c50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W21-D) |
| **Counterpart** | `reviews/A_aa_00508c50_HandlerTable58_FindById6c.md` |
| **Verdict** | **accept** on sealed CF; reject listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is a hash map | Assume O(1) skill map | **Falsified** — pure linear scan; no hash |
| 2 | Count lives on `this` | Local length field | **Falsified** — exclusive count is global `DAT_00d02984` |
| 3 | Matches on entry header / first dword | Common pattern | **Falsified** — match field is **`+0x6c`** |
| 4 | `__cdecl` / no stack cleanup | Ghidra void signature noise | **Falsified** — **`ret 4`**, one stack arg |
| 5 | Same table as `FUN_00508c00` | Twin confusion | **Falsified** — this = **`+0x58`/`DAT_00d02984`**; twin = **`+0x54`/`DAT_00d02988`** |
| 6 | Id `-1` walks full table | Sentinel ignored | **Falsified** — early return 0 |
| 7 | Product name is Skill_GetModifier… | Auto parent-seed alias | **Not sealed** — structural name only |
| 8 | Returns index | Array position | **Falsified** — returns **entry pointer** `table[i]` |
| 9 | Same as subtype 0xb path | Equip dual mix-up | **Falsified** — parent dual: this unit = subtype **0xa**; 00508c00 = **0xb** |
| 10 | Bit-exact / runtime verified | Static dual only | **Fail** if claimed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Linear scan + `+0x6c` id | **High** | Wrong port of lookup |
| Table at `+0x58` | **High** | Wrong slot vs 0xb twin |
| Global count `DAT_00d02984` | **High** | OOB or empty always |
| ABI thiscall + ret 4 | **High** | Stack imbalance |
| Subtype 0xa association | **High** (caller) | Hook apply miss |
| Registry/entry product types | **Low–Med** | Doc only |

---

## 3. Cross-check against raw / bytes

```text
// decompiler:
if ((param_2 != -1) && (0 < DAT_00d02984)) {
  piVar2 = *(int**)(param_1 + 0x58);
  do {
    if (*(int*)(*piVar2 + 0x6c) == param_2)
      return (*(int**)(param_1 + 0x58))[iVar1];
    iVar1++; piVar2++;
  } while (iVar1 < DAT_00d02984);
}
return 0;
// bytes: ret 4 both paths; mov esi,[ecx+58]; cmp [ebx+6c],edi — MATCH
```

No decomp residual (no unaff_*). Clean must not invent hash or local count.

**Attack on “this is HandlerTable54 / subtype 0xb”:** **Fails** — different table offset + different count global + parent dual mapping.

**Attack on “Skill_GetModifier product API”:** **Fails** — pure leaf table find shared by loot/equip consumers.

---

## 4. Surviving contract for AutoCore

```
HandlerTable58_FindById6c(registry, id) -> entry*|null:
  if id == -1 or g_count_d02984 <= 0: return null
  table = registry.ptr_table_at_0x58
  for i in 0 .. g_count_d02984-1:
    if table[i].id_at_0x6c == id: return table[i]
  return null
```

**Port tests:**

* Id `-1` never scans.
* Empty global count returns null without deref.
* Match uses **`+0x6c`**, not `*entry` first field.
* Distinct from `+0x54` twin (subtype 0xb path).

---

## 5. Open questions

1. Loader/populator for `DAT_00d02984` and table vectors.
2. Exact C++ type of entry (vtbl used by callers at `handler.vtbl+4`).
3. Whether multiple entries can share an id (first-wins only sealed).

**Verdict:** **accept** — sealed CF/ABI/offsets; reject identity-with-00508c00 and product-name myths.
