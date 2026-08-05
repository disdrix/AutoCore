# Review B (skeptical / adversarial): `aa_009697a0` StringVec_PushBackIfAbsent_EnsureTrailingDirSep

| Field | Value |
|---|---|
| **Stable ID** | `aa_009697a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-J) |
| **Counterpart** | `reviews/A_aa_009697a0_StringVec_PushBackIfAbsent_EnsureTrailingDirSep.md` |
| **Scratch** | `tmp/a_009697a0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Always push_back | **Falsified** — push only when scan hits end (`75 0B` skips call when found) |
| 2 | Push_front / insert at begin | **Falsified** — calls `FUN_004301f0` (push_back), not `FUN_00430310` at begin |
| 3 | ECX/ESI thiscall like `00969830` | **Falsified** — shell is **EDI** (`8B 77 04`, `8B CF`); ESI only used as iterator |
| 4 | Case-insensitive match | **Falsified** — IAT `operator==` on `basic_string`, not `_stricmp` |
| 5 | Mutates input path in place | **Falsified** — builds local via `FUN_009694e0`; dtors local |
| 6 | Erases duplicates | **Falsified** — sibling `009696c0` erases; this unit only skips push when present |
| 7 | Has AssManager xrefs like push_front | **Open/falsified for seal** — Ghidra xrefs empty (cannot claim AssManager binding) |
| 8 | Returns bool found/inserted | **Falsified** — void; `ret 4` with no AL success store |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI shell ABI + RET 4 | **High** | Wrong register → corrupt wrong list |
| Absent-only push_back CF | **High** | Duplicate paths / missing paths |
| Trailing-sep via helper | **High** (W32-A sealed) | Path join bugs |
| Retail caller | **Open** | Dead code vs live unknown entry |
| Product English | **Low** | Naming only |

---

## 3. Cross-check against raw + bytes + family

```
// Family (W31-E / W32-A / W34-J):
FUN_009694e0: normalize trailing sep
FUN_009696c0: normalize → find + erase
FUN_009697a0: normalize → find; if absent push_back   // THIS
FUN_00969830: normalize → insert at begin
```

Decompile ≡ hex for scan stride, equality break, and conditional `FUN_004301f0`.  
Contrast push_front sibling: uses ESI + `FUN_00430310` at begin — different ABI and insert policy.

---

## 4. Surviving contract for AutoCore

```
// Port:
void PushBackIfAbsent_DirSep(std::vector<std::string>& list, const std::string& path) {
  auto n = EnsureTrailingDirSep(path); // append '/' unless last in : / \ or empty
  if (std::find(list.begin(), list.end(), n) == list.end())
    list.push_back(std::move(n));
}
// Retail: EDI=list shell; stack basic_string*; ret 4; MSVC string sizeof 0x1c.
// Do not push_front; do not erase; do not case-fold.
```

---

## 5. Verdict

Adversarial pass confirms A on EDI ABI, absent-only push_back, and normalize-first order. Caller vacuum + product English remain open → **accept-with-gaps**.
