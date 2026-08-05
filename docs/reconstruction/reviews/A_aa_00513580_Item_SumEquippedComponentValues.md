# Review A (reconstruction fidelity): `aa_00513580` Item_SumEquippedComponentValues

| Field | Value |
|---|---|
| **Stable ID** | `aa_00513580` |
| **VA** | `0x00513580` |
| **Canonical name** | `Item_SumEquippedComponentValues` (proposed; was `FUN_00513580`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw + live re-decompile + bytes) |
| **Counterpart** | `reviews/B_aa_00513580_Item_SumEquippedComponentValues.md` |
| **System** | `inventory-transfer` (vendor / item value) |
| **Dual status** | **Present** (first full dual; supersedes 2026-07-23 scaffold) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Sum equipped component/mod value integers** for a host inventory item. For each slot (`vtbl+0x60` count, `vtbl+0x5c` slot id), resolve a component object via a **type-keyed catalog lookup** (host `clonebase+0x38`), and add **`*(int32*)(component + 0x94)`** when found. Returns **0** if catalog singleton is null or no components resolve.

Primary known use: store sell price `Item_GetStoreSellPrice_Inferred` (`0x005142a0`) does `base = this() + item+0xC4` then `*0.1` / optional half / min 1.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00513580_FUN_00513580.md` |
| Annotated | `docs/reconstruction/raw/aa_00513580_FUN_00513580.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Item_SumEquippedComponentValues.cpp` |
| Function record | `docs/reconstruction/functions/aa_00513580_FUN_00513580.md` |
| Live re-decompile | Ghidra `decompile_function` @ `0x00513580` — **≡ raw body** |
| Live bytes | `read_memory` prologue + sum path + epilogue + jump table |
| Catalog gate | `FUN_004ce940` decompile (singleton get-or-create) |
| Sample lookup | `FUN_00508b60` (list find by key `+0x6c`) |
| Caller dual | `aa_005142a0` Item_GetStoreSellPrice_Inferred |

**Not performed:** `disassemble_bytes`, Launcher, live CE, golden price tables.

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| ECX `this` | Item* | prologue `mov esi, ecx` |
| stack | none | plain `ret` |
| EAX return | int32 sum | `mov eax, ebx; ret` |
| EBP after gate | catalog* | `mov ebp, eax` after `FUN_004ce940` |

Decompiler `__fastcall` label is a **presentation artifact**; bytes are standard **thiscall**.

---

## 4. Control flow: live ≡ raw

| Stage | Match |
|---|---|
| sum=0; call `FUN_004ce940`; null → return 0 | **Yes** |
| slotCount = `vtbl[+0x60]()`; zero → skip loop | **Yes** |
| loop i++, re-read count each iter | **Yes** |
| switch on `*(item[0x2a]+0x38)` types 10/0xc/0xe/0x1c/0x44/0x46 | **Yes** |
| per case: get slot id vtbl+0x5c; lookup; if non-null re-fetch + add `+0x94` | **Yes** |
| return sum | **Yes** |

### Closed form (sealed)

```text
catalog = FUN_004ce940()
if catalog == 0: return 0
sum = 0
for i in 0 .. item.vtbl[+0x60]()-1:
  type = *(item.clonebase + 0x38)   // item[0x2a]+0x38
  slotId = item.vtbl[+0x5c](i)
  comp = type_lookup(catalog, slotId)  // one of six FUN_00508*
  if comp: sum += *(int32*)(comp + 0x94)
return sum
```

### Sum field **`+0x94`** — **SEALED**

| Evidence | Detail |
|----------|--------|
| Decompile | `iVar4 = iVar4 + *(int *)(iVar2 + 0x94)` |
| Bytes | `03 98 94 00 00 00` = `add ebx, [eax+0x94]` |

### Jump table — **SEALED**

| Case type | Lookup | JT target |
|----------:|--------|-----------|
| 10 | `FUN_00508b60` | `0x0051366c` |
| 0xc | `FUN_00508ac0` | `0x005135d3` |
| 0xe | `FUN_00508bb0` | `0x00513639` |
| 0x1c | `FUN_00508b10` | `0x00513606` |
| 0x44 | `FUN_00508c50` | `0x00513698` |
| 0x46 | `FUN_00508c00` | `0x005136c4` |
| default | no add | `0x005136f4` |

---

## 5. Callers

| Site | Role |
|------|------|
| `0x005142a0` `Item_GetStoreSellPrice_Inferred` | `sum + +0xC4` then `*0.1` … |
| `0x00514250` | related pricing: base+sum (with half-path variant) |

---

## 6. Confidence

| Claim | Level |
|---|---|
| thiscall Item* → int sum | **High / Sealed** |
| Catalog gate `FUN_004ce940` | **High** |
| Loop vtbl +0x60 / +0x5c | **High** |
| Six type cases + jump table | **High / Sealed** |
| Addend offset **`+0x94`** | **High / Sealed** |
| Role = component value sum for pricing | **High** CF; English **Probable** |
| Type enum / field product names | Tentative / Open |
| Original PDB | Open |
| Overall | **Probable / accept-with-gaps** |

---

## 7. Verdict

### **accept-with-gaps**

**Accept:** Live ≡ raw; bytes seal catalog gate, slot loop, six-type switch, and **`+0x94`** sum. Callers confirm pricing use.

**Gaps:** product English for types and `+0x94`; whether empty slots use `-1` ids; runtime golden sums.
