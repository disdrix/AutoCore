# Review B (skeptical / adversarial): `aa_00556b10` Weather_NfxListFillOrActivate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00556b10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-I) |
| **Counterpart** | `reviews/A_aa_00556b10_Weather_NfxListFillOrActivate_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX is the out-list | **Falsified** — prologue clears **stack0** via `MOV ECX,EBP; CALL 0043d650`; entry ECX saved as host |
| 2 | Always loads FX | **Falsified** — mode 0 only fills resource ids; mode ≠0 activates |
| 3 | Always appends `_nfx.xml` | **Falsified** — `strstr` gate skips when already present |
| 4 | Same as `FxCache_ApplyWithNfxEnsure` | **Falsified** — no vtbl apply / transform path; list fill + weather activate only |
| 5 | `__thiscall` 4-arg decompiler = list this | **Partial** — ECX is host; list is stack0; decompiler param packing is messy but RET 0xC + call sites seal 3 stack formals |
| 6 | Product name retail | **Overstated** — `_Inferred` from strings/callees |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX host + stack list/obj/mode + RET 0xC | **High** | Wrong object / stack |
| mode 0 fill vs mode 1 activate | **High** | Wrong weather path |
| `_nfx.xml` constant + strstr gate | **High** | Path suffix bugs |
| Clear-before-fill | **High** | Stale ids |
| `004b88e0` apply details | **Low** (unowned) | Incomplete activate port |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | Resource open races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  clear list; if weather null return
  mode0: name resolve + optional _nfx.xml + resource open → push id (×2 sources)
  mode1: 00555600 / 00553d20 gates → 004b88e0

bytes:
  SUB ESP,0x108; list=stack0; EDI=ECX host; CALL 0043d650(0)
  … RET 0xC

caller FUN_005575c0:
  host+0x190, mode 0 @ 005577c8
  host+0x1a4, mode 1 @ 00557851
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Constant `009ca184` sealed.

Sibling contrast: `FxCache_ApplyWithNfxEnsure` also uses `_nfx.xml` but attaches FX to entities — different unit.

---

## 4. Surviving contract for AutoCore

```
// Weather nfx list fill / activate:
//   ECX = weather host
//   stack = (GuardedVector* outList, void* weatherObj, char mode); RET 0xC
//   always clear outList first
//   mode 0: resolve names, ensure _nfx.xml unless present, push resource ids if open
//   mode 1: activate/load weather FX (unowned 004b88e0 / 00553d20)
// Do not treat ECX as the list. Do not always append _nfx.xml.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/mode/`_nfx.xml`/call sites; residuals product English + unowned activate helper → **accept-with-gaps**.
