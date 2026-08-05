# Review B (skeptical / adversarial): `aa_009694e0` BasicString_CopyEnsureTrailingDirSep

| Field | Value |
|---|---|
| **Stable ID** | `aa_009694e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-A) |
| **Counterpart** | `reviews/A_aa_009694e0_BasicString_CopyEnsureTrailingDirSep.md` |
| **Scratch** | `tmp/a_009694e0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Always appends `/` | **Falsified** — empty size early-copies; last ∈ `{':','/','\\'}` pure-copies |
| 2 | Appends `\\` on Windows | **Falsified** — append path pushes `0x2F` only (`6A 2F`) |
| 3 | thiscall / ECX this | **Falsified** — cdecl two stack args; `C3` not `C2`; ESI is out, not this |
| 4 | Mutates src in place | **Falsified** — always constructs into `out`; src read-only |
| 5 | Heap-only string (no SSO) | **Falsified** — `_Myres < 0x10` uses `lea edx,[eax+4]` |
| 6 | Scaffold assManager plate is product name | **Rejected** — structural `BasicString_CopyEnsureTrailingDirSep` only |
| 7 | Returns void | **Falsified** — `mov eax,esi` before every ret |
| 8 | Treats `:` as needing append | **Falsified** — `80 F9 3A 74` skips append (drive-root style) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Trailing-sep charset + `/` append | **High** | Path join double-sep / missing sep |
| cdecl out-string ABI | **High** | Wrong stack / crash |
| SSO offsets +0x14/+0x18/+4 | **High** | Misread last char |
| Nested append helper details | **Med** | Port reimplements += wrong |
| Product path-list English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + callers

```
// FUN_009694e0
if size==0: copy; ret out
last = data[size-1]
if last not in : / \:
  tmp = src + '/'; copy out from tmp
else:
  copy out from src

// Callers (normalize then act on list):
FUN_00969830: normalize → StringVec_InsertOne at begin
FUN_009696c0: normalize → find+erase match
FUN_009697a0: normalize → find; if absent push_back (FUN_004301f0)
```

Decompile ≡ hex for branch order and constants. Parent W31-E already depended on these trailing-sep rules.

---

## 4. Surviving contract for AutoCore

```
// Port as pure path normalize/copy:
std::string BasicString_CopyEnsureTrailingDirSep(const std::string& src) {
  if (src.empty()) return src;
  char last = src.back();
  if (last == ':' || last == '/' || last == '\\') return src;
  return src + '/';
}
// Retail uses MSVC basic_string out-param form; behavior equivalent.
// Do not append '\\'; do not mutate src; do not treat ':' as incomplete.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, charset, SSO, and non-mutating copy. Product English + nested `FUN_00416510` dual remain open → **accept-with-gaps**.
