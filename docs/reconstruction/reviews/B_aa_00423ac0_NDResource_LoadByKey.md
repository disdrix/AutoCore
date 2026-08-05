# Review B (skeptical / adversarial): `aa_00423ac0` NDResource_LoadByKey

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423ac0` |
| **VA** | `0x00423ac0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00423ac0_NDResource_LoadByKey.md` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + caller decompile (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** on CF/ABI; **reject** “bool-only return” and “thiscall/4-formal-as-this” myths |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Returns only success/fail **bool** | **Falsified** — machine tristate: **−1 / 0 / 1** (`or eax,-1` vs ESI 0/1) |
| 2 | Null leaves `*pOut` untouched | **Falsified** — `*pOut` written **before** null test |
| 3 | `thiscall` with cache in ECX formal | **Falsified** — no `this` formal; cache loaded from **`[DAT_00d1f050]`**; **`ret 0x10`** (4 stack args) |
| 4 | Type token is a stack formal | **Falsified** — inserted from **`FUN_00423b10()`** return, not from caller's args |
| 5 | Init-fail (**0**) is treated as error by NDXml | **Falsified as caller contract** — NDXml uses **`iVar9 < 0`** only; **0** falls into Acquire/Release path |
| 6 | Virtual slot is **+0x00** / dtor | **Falsified** — **`call [edx+4]`** only |
| 7 | Multiple distinct call sites with rich flags | **Overstated** — sole Ghidra code xref is NDXml with **`(key, 0, 0)`** |
| 8 | `DAT_00d1f050` static image holds a live pointer | **Overstated** — PE dump zeroed (BSS); sealed as **load address**, runtime-filled |
| 9 | Scaffold “returns 0/1 from init bool” plate covers null | **Incomplete** — null is **−1**, not 0; plate already noted −1 but clean types were soft |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Tristate return −1/0/1 | **High** | Port treats 0 as missing resource → skip release / double-free |
| Always-write `*pOut` | **High** | Uninit out-ptr on null path |
| stdcall `ret 0x10` | **High** | Stack imbalance |
| Type token = `FUN_00423b10` singleton | **High** | Wrong cache type match / always-miss |
| Global cache `DAT_00d1f050` | **High** | Wrong cache instance |
| vtbl+4 init bool | **High** | Wrong virtual |
| param3/param4 semantics | **Open** | Silent wrong create/lookup policy |
| Resource layout / inner COM at +4 after Acquire | **Open** | Owned by siblings (NDXml crash notes) |

---

## 3. Cross-check against raw / machine

```
type = FUN_00423b10()                          // &DAT_00d1f734
res  = NDResourceCache_LookupOrCreate(*DAT_00d1f050, key, type, p3, p4)
*pOut = res
if res == NULL: return -1
ok = (bool) res->vtable[1]()                   // slot +4
return ok ? 1 : 0
```

Caller NDXml residual (not owned, contract seal only):

```
rc = NDResource_LoadByKey(&docRes, keyObj, 0, 0)
if (rc < 0) { /* error / parse-error branch */ }
else { /* AcquireInnerObject; Release prior COM; load VARIANT */ }
```

Clean/raw CF ≡ machine after three-rep strengthen. Prior scaffold under-specified ABI (`uint` return without −1 path emphasis in clean plate).

---

## 4. Surviving contract for AutoCore

```
// __stdcall, ret 0x10
int NDResource_LoadByKey(void** pOut, KeyObj* key, void* p3, int p4) {
  TypeToken* type = GetDefaultResourceTypeToken(); // FUN_00423b10
  NDResource* res = NDResourceCache_LookupOrCreate(g_pCache, key, type, p3, p4);
  *pOut = res;                    // always
  if (!res) return -1;
  return res->vInitLoad() ? 1 : 0;  // vtbl +0x04
}

// Caller pitfall:
//   if (rc < 0) fail; else treat as loaded — even when rc == 0 (init failed)
```

---

## 5. Open questions

1. Names/types for `param3` (match predicate object?) and `param4` (create-if-missing flag; cache body compares to **1**).
2. Full set of resource subclasses sharing vtbl+4 init.
3. Whether non-XML assets use a different wrapper instead of this entry.

**Verdict:** **accept-with-gaps** on CF/ABI; **High** on tristate return and always-write out-param
