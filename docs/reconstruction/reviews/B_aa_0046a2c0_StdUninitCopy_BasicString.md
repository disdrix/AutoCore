# Review B (skeptical / adversarial): `aa_0046a2c0` StdUninitCopy_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_0046a2c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-G) |
| **Counterpart** | `reviews/A_aa_0046a2c0_StdUninitCopy_BasicString.md` |
| **Scratch** | `tmp/a_0046a2c0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | POD / dword memcpy relocate | **Falsified** — per-elem string copy-ctor IAT, stride 0x1c, SEH |
| 2 | thiscall / RET 4 | **Falsified** — bare `C3`, three stack ptrs, no ECX this |
| 3 | Always-nothrow helper | **Falsified** — catch residual destroys partial + `_CxxThrowException` |
| 4 | Domain AssManager-only helper | **Weakened** — generic STL; callers include insert-n + range assign |
| 5 | Scaffold `Named_CalleeOf_Named_*` | **Reject** — structural uninit-copy name preferred |
| 6 | Decompiler shows full function | **Weakened** — catch not in happy-path decompile; **bytes win** for EH |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Uninit-copy shape | **High** | Wrong grow/assign port |
| cdecl bare RET | **High** | Stack imbalance |
| Stride 0x1c string | **High** | Wrong destroy/copy |
| Catch path | **High** | Missed exception safety |
| Product demangle | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// FUN_004306b0 grow: FUN_0046a2c0(prefix/suffix ranges) then FUN_00430390 fill-n
// FUN_00469d10: if ready, end' = FUN_0046a2c0(src_begin, src_end, dst_begin)
// FUN_00431430: thin thiscall forwarder into FUN_0046a2c0(...)
```

Live decompile 2026-07-29 ≡ scaffold loop CF. Body 140 B exclusive end `0x0046a34c`; success JZ over throw; IAT targets sealed via `read_memory` on import slots.

---

## 4. Surviving contract for AutoCore

```
// Port as uninit_copy for vector<string> elems (0x1c):
string* UninitCopy(string* first, string* last, string* dest) {
  for (; first != last; ++first, ++dest)
    if (dest) new (dest) string(*first);  // copy-ctor
  return dest;
}
// Must be exception-safe: destroy partial dest on throw (retail SEH catch).
// cdecl; do not invent thiscall.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/stride/EH. Residual product demangle → **accept-with-gaps**.
