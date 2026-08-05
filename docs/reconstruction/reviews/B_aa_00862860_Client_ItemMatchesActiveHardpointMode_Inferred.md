# Review B (skeptical / adversarial): `aa_00862860` Client_ItemMatchesActiveHardpointMode_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00862860` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W18-O) |
| **Counterpart** | `reviews/A_aa_00862860_Client_ItemMatchesActiveHardpointMode_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This sends a network packet | **Falsified** — pure predicate; callers send `0x2036` later |
| 2 | ESI is unused decompiler noise | **Falsified** — drop path `mov esi,[esp+..]`; click path `mov esi,ebp` |
| 3 | ECX is uiHost, ESI is item | **Falsified** — null test on ECX; cloneBase loads from ECX; mode vcall on ESI |
| 4 | Covers all inventory item classes | **Falsified** — only 6/10/0xc/0xe/0x10/0x1c; else false |
| 5 | Mode values are hardpoint slot indices 0..n | **Not proven** — integers 1–9/0xd sealed; semantic labels open |
| 6 | Case 0xe is “armor” | **Falsified** — armor is `0x1c`; 0xe is separate (town-gated in drop parent) |
| 7 | Always calls `FUN_0040da70` | **Falsified** — weapon case only |
| 8 | Product name proven | **Sustained as gap** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bool gate role | **High** | Port skipping gate equips wrong class |
| Class→mode table | **High** | Wrong UI filter / false rejects |
| ESI/ECX ABI | **Confirmed** | Crashes or always-false |
| Mode product meaning | **Open** | Misnamed enums in server docs |
| Weapon flag decoding | **Medium** | Wrong subgroup (4/5/6) |

---

## 3. Cross-check against raw + bytes

```
if !item: return false
switch cloneClass(item):
  map → expectedMode
  return uiHost.GetMode() == expectedMode
return false
```

Clean must **not** invent packet IO, equip mutators, or extra classes. Parent `Client_SendInventoryDrop_Hardpoint` still applies town checks after this returns true.

---

## 4. Surviving contract for AutoCore

```c
// Client UI gate only — server equip validation is separate.
// When porting client UI or bot automation:
//   require active hardpoint mode matches item clone class map below.
// Server authority must not trust this alone.
```

| Class | Expected mode |
|---|---|
| 10 plant | 1 |
| 0x10 wheelset | 2 |
| 0x1c armor | 3 |
| 0x0c weapon (+flags/subtype) | 4/5/6/7 |
| 6 ornament (+subtype) | 8/9 |
| 0x0e | 0x0d |

---

## 5. Open questions

1. Product name of `vtbl+0x3cc` and mode enum.
2. Whether mode is sheet page id vs hardpoint highlight id.
3. Full meaning of weapon bits at nested `+0x536`.

**Verdict:** **accept-with-gaps**
