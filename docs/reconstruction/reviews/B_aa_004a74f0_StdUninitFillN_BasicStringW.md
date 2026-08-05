# Review B (skeptical / adversarial): `aa_004a74f0` StdUninitFillN_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a74f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-R) |
| **Counterpart** | `reviews/A_aa_004a74f0_StdUninitFillN_BasicStringW.md` |
| **Scratch** | `tmp/a_004a74f0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Thin thiscall wrapper like char `00430390` | **Falsified** — full 140 B SEH loop; bare `C3`; no nested fill callee |
| 2 | Register ABI (ECX=dest, EDX=value, EAX=count) like POD fill-n | **Falsified** — stack triad `[ebp+8/C/10]` |
| 3 | Range copy / uninit-copy | **Falsified** — count countdown; single value* source |
| 4 | POD 7-dword stores | **Falsified** — IAT wstring copy-ctor; SEH |
| 5 | `RET 0x0C` | **Falsified** — bare `C3` |
| 6 | Sole parent insert-n only | **Partially falsified** — also `FUN_004a7a70`, `FUN_004a8100` |
| 7 | Product demangle sealed | **Overstated** — structural **Inferred** only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stack dest/count/value* + void | **High** | Wrong fill wiring in insert-n port |
| Stride 0x1c wstring | **High** | Corrupt adjacent elements |
| SEH catch destroy | **High** | Leak on throw mid-fill |
| Three callers | **High** | Miss hole/resize domains |
| Product English | **Open** | wrong plate only |
| Runtime | **Open** | rare edge |

---

## 3. Cross-check against raw + bytes

```
bytes: push ebp; SEH; mov esi,[ebp+8]=dest; mov edi,[ebp+0C]=count;
       cmp edi,0; jbe success;
       test dest; je skip; push [ebp+10]; mov ecx,dest; call [IAT ctor];
       dec count; add dest,0x1C; loop;
       catch: dtor range; throw(0,0); epilogue ret
raw ≡ live happy-path; bytes seal catch residual
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. 3 xrefs: insert-n + hole + resize paths.

Sibling uninit-copy `0x004a6b50` shares IAT and SEH pattern — confirms this unit is the **fill-n** half, not a second copy.

---

## 4. Surviving contract for AutoCore

```
UninitializedFillN_BasicStringW(dest, count, value):
  // cdecl stack triad; bare RET; void
  while count != 0:
    if dest: basic_string_w_copy_ctor(dest, value)
    dest += 0x1c; count--
  // on throw: destroy partial dest; rethrow
```

Port as non-trivial wstring fill-n. Do **not** use POD fill-n or char thin wrapper ABI (`RET 0x0C` / ECX alloc).

---

## 5. Open questions

- Exact MSVC demangle / template plate.
- Full dual of `FUN_004a7a70` / `FUN_004a8100` (not owned).
- Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
