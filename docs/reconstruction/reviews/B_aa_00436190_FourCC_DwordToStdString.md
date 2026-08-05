# Review B (skeptical / adversarial): `FourCC_DwordToStdString` @ `0x00436190`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436190` |
| **VA** | `0x00436190` |
| **Body span** | `00436190` – `0043621f` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra; independent of Review A wording) |
| **Counterpart** | `reviews/A_aa_00436190_FourCC_DwordToStdString.md` |
| **System** | `util` / fourcc |
| **Verdict** | **accept** on OWN CF + BE layout; **needs-more-evidence** only on host `std::string` ABI details (out of scope) |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Bytes are little-endian host memory order as the string | **Falsified** — stores put **MSB first** (`>>24` in `buf[0]`). Host LE dword `0x50535642` would print `"PSVB"` if LE string; live path prints BE character order of the dword value. |
| 2 | Function is `__thiscall` / `__stdcall` | **Falsified** — epilogue is `add esp,0x34; ret` (cdecl). |
| 3 | Returns the temporary string | **Falsified** — returns **out** (`ESI`), not stack temp. |
| 4 | Constructs in-place without temp | **Falsified** — temp ctor + copy-ctor + dtor (three imports). |
| 5 | “Empty on tag 0” is special-cased | **Overstated** — no branch; natural consequence of `buf[0]==0`. |
| 6 | Name implies physics-only | **Overstated** — also called from `stoChunkWriter_BeginChunk`; util helper. |
| 7 | Clean `*out = tmp` is bit-identical to MSVC copy-ctor into unconstructed out | **Residual** — semantic CF match; placement-new vs assign depends on caller having raw storage (retail out is stack `basic_string` object). Ports must construct into out storage as retail does. |
| 8 | Runtime verified | **Falsified** — open. |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| BE four-byte + NUL layout | **High** | Wrong tag strings in logs / chunk names |
| cdecl / two stack args / return out | **High** | ABI crash |
| Import-only callees | **High** | False dependency on local FUN_* |
| FourCC product meaning | **High** | Misname only; CF still correct as “u32→string” |
| Exact Dinkumware layout of out | **Medium (use)** / not owned | Port using modern `std::string` assign vs construct-in-place |
| Clean modernization-safe | **N/A** | Clean is CF scaffold, not EXE proof |

---

## 3. Surviving contract for AutoCore

```
// __cdecl
out = FourCC_DwordToStdString(out, tag):
  char buf[5] = {
    (tag >> 24) & 0xff,
    (tag >> 16) & 0xff,
    (tag >>  8) & 0xff,
    (tag      ) & 0xff,
    0
  };
  construct tmp from buf;   // C-string, stops at first 0
  construct/copy into *out from tmp;
  destroy tmp;
  return out;
```

**Port rules that survive adversarial review:**

1. Never reverse the byte order when matching retail log / chunk text for integer FourCC tags (e.g. `0x42565350` → `"BVSP"`).
2. Treat as pure util; do not bury under physics-only module API.
3. Preserve empty-string behavior for tag `0`.

---

## 4. CF cross-check vs three-rep

| Check | Result |
|---|---|
| Live decompile vs raw body | **Match** |
| Clean vs raw CF stages | **Match** |
| `read_memory` end / ret form | **Match** (`C3`) |
| Xref set size 3 | **Match** |

---

## 5. Open questions (OWN residual only)

1. Whether `FUN_00436250` is a pure tail/wrapper with fixed args (wrapper body not dual-owned here).
2. Whether any tag with internal zero bytes is intentionally used (would truncate).

**Verdict:** **accept** on OWN control flow and big-endian FourCC contract. Safe behavioral map for AutoCore stringification of 32-bit tags.
