# Review A (reconstruction fidelity): `aa_0089a260` UI_RefinePanel_InsertCommodityListRow_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0089a260` |
| **VA** | `0x0089a260` |
| **Canonical name** | `UI_RefinePanel_InsertCommodityListRow_Inferred` |
| **Ghidra name** | `FUN_0089a260` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W21-S) |
| **Counterpart** | `reviews/B_aa_0089a260_UI_RefinePanel_InsertCommodityListRow_Inferred.md` |
| **System** | `inventory-transfer` (refinery UI) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Insert one commodity row** into the refine panel list:

```text
if !entry || !entry.def(+0x3c): return

switch host.filterMode(+0x52c):
  1: require qty >= 1
  2/3/4/6: require def.tier(+0x4c8) == 0/1/2/3
  7: FUN_0052d450(host+0x530) + map has entry+0x34 else return

// localize name from def+0x92; strtok quality prefix by locale
// sprintf label "[qty] …" variants into local_8a0

if FUN_00599dd0() < 1:          // no configured mod slots
  if def+0x4d0 == -1: return
  list = host+0x568
else:
  list = host+0x56c

list.vtbl+0x45c(label, entry+0x34, …)
list.vtbl+0x464(entry+0x34, …)
```

Sole caller `FUN_0089bc30` (rebuild list) — this unit is the **row binder**, not the enumerator.

---

## 2. Calling convention

| Slot | Role | Evidence |
|------|------|----------|
| `[ebp+8]` | host | prologue `mov edi, [ebp+8]` |
| `[ebp+0xc]` | entry | `mov esi, [ebp+0xc]` |
| `[ebp+0x10]` | qty | `mov ebx, [ebp+0x10]` |
| `[ebp+0x14]` | flag | **pushed by caller; unused in body** |
| Return | `void` | |
| Epilogue | **`ret 0x10`** | bytes @ end |
| SEH | `LAB_009ac5a9` | prologue |

Caller packs (`0089bc30`): `push flag; push qty; push entry; push host; call`.

---

## 3. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw / annotated / clean | `raw/aa_0089a260_*`, `UI_RefinePanel_InsertCommodityListRow_Inferred.cpp` |
| Live decompile | Ghidra `decompile_function` + `analyze_function_complete` |
| Live bytes | prologue 64 B + epilogue `ret 0x10` + DE strings @ `0x00a4e374` |
| Callers | 2× `FUN_0089bc30` |
| Related sealed | `FUN_00599dd0` ItemDef_CountConfiguredModSlots; parent `0089bc30` rebuild |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null entry / null def early out | **Yes** |
| Filter switch modes 1/2/3/4/6/7 | **Yes** |
| Locale name load def+0x92 | **Yes** |
| EN quality Salvaged/Patched/Functional/Perfect | **Yes** |
| DE quality tables (read_memory) | **Yes** |
| FR-style lang==1 full-name path | **Yes** |
| Label formats `[0]/[%i]` + optional `, %s` | **Yes** |
| Mod-slot list select +0x568/+0x56c | **Yes** |
| def+0x4d0==-1 reject list A | **Yes** |
| ret 0x10 | **Yes** |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = refine commodity row insert | **High** (sole parent rebuild) |
| ABI 4-arg stdcall ret 0x10 | **Confirmed** |
| flag unused | **Confirmed** |
| Filter + tier + list split | **Confirmed** |
| Mode/tier product English | **Open** |
| Mode-7 map exact residual | **Tentative** |
| Name `_Inferred` | **High** |

---

## 6. Gaps / open

1. Product names for filter modes and tier enum.
2. Why callers pass `flag` if unused (dead arg / versioning).
3. Exact vtbl 0x45c/464 stack packs.
4. Mode-7 `Map_LowerBoundFindByIntKey` miss condition (decomp unaff_EDI residual).
5. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps** — filter/label/insert CF sealed; mode English + mode-7 map residual open.
