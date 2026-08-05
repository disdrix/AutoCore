# Review B (skeptical / adversarial): `aa_00431450` BasicString_FillAssignRange_0x1c

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431450` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00431450_BasicString_FillAssignRange_0x1c.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Uninitialized fill / ctor-N | **Falsified** — IAT `operator=` only; no placement new |
| 2 | Count-N API | **Falsified** — end iterator (`first != last`) |
| 3 | Range-to-range copy (src advances) | **Falsified** — value pointer fixed (`EBX` once) |
| 4 | thiscall host | **Falsified** — no ECX host; cdecl 3 stack |
| 5 | POD memcpy fill | **Falsified** — string assign (refcount/heap) |
| 6 | Multi-caller generic STL export | **Weak** — sole xref is vector insert; name stays structural |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Assign-fill not relocate | High | Wrong insert overwrite semantics |
| 0x1c stride | High | Buffer overrun / skip |
| Live destinations required | High | Double-free if used on raw storage |
| Sole-parent naming | Medium | Over-narrow if new xrefs appear |

---

## 3. Cross-check

```
raw decompile ≡ body hex loop.
Distinct from FUN_00430390 (uninitialized fill-n) and FUN_00431480 (copy-backward).
Parent hole arm: fill [where, new_end-count); mid arm: fill [where, where+count).
```

---

## 4. Surviving contract for AutoCore

```
BasicString_FillAssignRange_0x1c(first, last, value):
  for cur in [first, last) step 0x1c:
    *cur = *value   // basic_string::operator=
```

Do **not** use on uninitialized storage; pair with construct helpers when growing.

---

## 5. Open questions

1. Product demangle plate.

**Verdict:** **accept**
