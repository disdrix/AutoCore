# Review B (skeptical / adversarial): `aa_0089a260` UI_RefinePanel_InsertCommodityListRow_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0089a260` |
| **VA** | `0x0089a260` |
| **Canonical name** | `UI_RefinePanel_InsertCommodityListRow_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0089a260_UI_RefinePanel_InsertCommodityListRow_Inferred.md` |
| **System** | `inventory-transfer` (refinery UI) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is the list rebuild enumerator | Rebuild is `0089bc30`; this only formats+inserts one row | **Falsified** as enumerator |
| 2 | 3-arg function (decomp signature) | `ret 0x10` + 4 pushes at both call sites | **Falsified** 3-arg — **4 stack args** |
| 3 | `param_3` is `char*` | Compared as `(int)param_3 < 1` and sprintf `%i` | **Falsified** char* — **int qty** |
| 4 | Always inserts a row | Many early returns (filter/tier/qty/def+0x4d0) | **Falsified** always |
| 5 | Always uses host+0x568 | Mod-slot count routes to +0x56c | **Falsified** single list |
| 6 | flag drives reverse vs forward | Body never loads `[ebp+0x14]` | **Attack fails as used** — **unused** |
| 7 | Quality split always applies | lang==1 uses full-name path; non-matching tokens skip quality form | **Falsified** always |
| 8 | Mode 5 special-cased | No case 5 in switch (fallthrough) | **Attack fails** — fallthrough sealed |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 0x10 / 4-arg ABI | **Confirmed** | Stack imbalance |
| qty int + flag unused | **Confirmed** | Wrong third type |
| Filter modes + tier | **Confirmed** | Wrong rows shown |
| List A/B split | **Confirmed** | Wrong widget |
| Mode-7 map details | **Tentative** | Extra/missing rows in mode 7 |
| Product English | **Open** | Docs |

---

## 3. Cross-check against raw / live / bytes

```
decompile_function ≡ raw body (incl. quality strcmp soup + insert tail)
read_memory prologue: EDI=host ESI=entry EBX=qty; test entry; load def+0x3c
read_memory epilogue: ret 0x10
read_memory DE strings @ 0x00a4e374: Perfekter/Perfekte/Perfektes/Hochwertig*/Aufbereitet*/Verwertbar*
Caller 0089bc30: 4 pushes both sites
Body Ghidra: 0x0089a260–0x0089b06f (0xE10)
```

### Merge trap

Do **not** fold into `0089bc30` (enumeration) or `0089b090` (bind display sibling). This VA is **per-row filter + label + insert**.

### Decomp trap

Do **not** trust 3-arg `char* param_3` signature. Bytes + callers seal **int qty** + unused flag.

### Zero-qty trap

Mode 1 rejects `qty < 1`; other modes may still format `[0] …` when qty is non-positive after filters.

---

## 4. Surviving contract for AutoCore

```
InsertCommodityListRow(host, entry, qty, flag_unused):
  require entry.def
  apply host+0x52c filter (qty / tier / mode-7 map)
  build localized label with optional quality prefix
  if modSlots < 1:
    require def+0x4d0 != -1
    insert into host+0x568
  else:
    insert into host+0x56c

AutoCore must NOT:
  - treat this as full list rebuild
  - use only one list widget
  - require flag for CF (unused)
  - insert when filters reject
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Row insert binder | **Agree Confirmed** |
| 4-arg ret 0x10 | **Agree Confirmed** |
| Filter/label/list split sealed | **Agree Confirmed** |
| accept-with-gaps | **Agree** (mode-7 + English open) |

---

## 6. Verdict

**accept-with-gaps** — adversarial checks kill enumerator/3-arg/char* traps; residual is mode-7 map exactness and product English.
