# Review B (skeptical / adversarial): `aa_004a6b50` StdUninitCopy_BasicStringW

| Field | Value |
|---|---|
| **Stable ID** | `aa_004a6b50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-R) |
| **Counterpart** | `reviews/A_aa_004a6b50_StdUninitCopy_BasicStringW.md` |
| **Scratch** | `tmp/a_004a6b50.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `__thiscall` / ECX = vector host | **Falsified** — pure stack triad; ECX only for nested copy-ctor |
| 2 | POD 7-dword fieldwise copy | **Falsified** — IAT wstring copy-ctor; SEH; not leaf |
| 3 | Same as char `0046a2c0` binary identity | **Falsified** — different SEH scope/IAT; same *shape* only |
| 4 | `RET 0x0C` / stdcall cleanup | **Falsified** — bare `C3`; caller cleans |
| 5 | Stride 4 / 0x10 / 0x18 | **Falsified** — all advances `ADD …,0x1C` |
| 6 | No exception safety needed | **Falsified** — catch destroy + `_CxxThrowException(0,0)` @ `0x006A3D60` |
| 7 | Product demangle sealed | **Overstated** — structural **Inferred** only |
| 8 | Multiple parents / domains | **Falsified** — 4 xrefs all inside `FUN_004a7ad0` only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stack first/last/dest + EAX dest_end | **High** | Wrong relocate wiring in insert-n port |
| Stride 0x1c wstring | **High** | Corrupt adjacent elements / bad SSO |
| SEH catch destroy | **High** | Leak / double-free on throw |
| Sole parent `004a7ad0` | **High** | Miss other use domains |
| Product English | **Open** | wrong plate only |
| Runtime | **Open** | rare edge |

---

## 3. Cross-check against raw + bytes

```
bytes: push ebp; SEH; mov esi,[ebp+10]=dest; mov edi,[ebp+8]=first;
       cmp edi,[ebp+0C]; je success;
       test dest; je skip; push src; mov ecx,dest; call [IAT ctor];
       add dest/first,0x1C; loop;
       catch: dtor range; throw(0,0); epilogue mov eax,esi; ret
raw ≡ live happy-path; bytes seal catch residual
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. 4 xrefs all CALL inside `FUN_004a7ad0`.

Sibling fill-n `0x004a74f0` shares IAT ctor/dtor and parent insert-n — confirms this unit is the **copy-range** half of the pair, not a misnamed fill.

Char twin `0x0046a2c0` (W33-G) confirms the structural family; do **not** unify IAT or SEH labels.

---

## 4. Surviving contract for AutoCore

```
UninitializedCopy_BasicStringW(first, last, dest) -> dest_end:
  // cdecl stack triad; bare RET
  while first != last:
    if dest: basic_string_w_copy_ctor(dest, first)
    first += 0x1c; dest += 0x1c
  return dest
  // on throw: destroy partial dest; rethrow
```

Port as non-trivial wstring range relocate. Do **not** use POD uninit-copy or dword memmove.

---

## 5. Open questions

- Exact MSVC demangle / template plate.
- Runtime / bit-exact.
- Null-dest residual.

**Verdict:** **accept-with-gaps**
