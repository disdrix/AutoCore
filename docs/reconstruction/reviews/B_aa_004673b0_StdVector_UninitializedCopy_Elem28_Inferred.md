# Review B (skeptical / adversarial): `aa_004673b0` StdVector_UninitializedCopy_Elem28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004673b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-T) |
| **Counterpart** | `reviews/A_aa_004673b0_StdVector_UninitializedCopy_Elem28_Inferred.md` |
| **Scratch** | `tmp/a_004673b0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `__thiscall` / ECX = vector host | **Falsified** — ECX is range **first** (`MOV ESI,ECX`); no host triad read |
| 2 | Stride 4 / 0x10 / 0x18 | **Falsified** — all advances `ADD …,0x1C`; 7 stores |
| 3 | Non-trivial ctor/dtor | **Falsified** — leaf; pure dword assigns; no calls |
| 4 | `RET n` / stdcall stack cleanup | **Falsified** — bare `C3`; one stack arg cleaned by caller |
| 5 | Returns dest end in EAX | **Overstated** — body clobbers EAX as cursor; sole parent does not use return |
| 6 | Product demangle `vector<T>::…` | **Overstated** — structural **Inferred** only |
| 7 | Same as BasicString uninit copy | **Falsified** — no string ctor helper; different ABI |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX dest / ECX first / stack last | **High** | Wrong relocate wiring in insert-n port |
| Stride 0x1c POD | **High** | Corrupt adjacent elements |
| Leaf trivial copy | **High** | Invented AddRef/dtor |
| Sole parent `00466ea0` | **High** | Miss other use domains |
| Runtime | **Open** | rare edge |

---

## 3. Cross-check against raw + bytes

```
bytes: push esi; mov esi,ecx; cmp esi,[esp+8]; je out;
       lea ecx,[eax+18]; lea edx,[esi+18]; test eax; je skip;
       7× mov load/store; add all +0x1c; loop; pops; ret
raw ≡ live ≡ clean: first≠last → fieldwise copy stride 28
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. 4 xrefs all CALL inside `FUN_00466ea0`.

Sibling fill-n `0x00467320` shares 7-lane POD pattern and sole parent — confirms this unit is the **copy-range** half of the pair, not a misnamed fill.

---

## 4. Surviving contract for AutoCore

```
UninitializedCopy_Elem28(dest, first, last):
  // EAX=dest, ECX=first, stack last; bare RET
  while first != last:
    if dest: *dest = *first   // 7 dwords
    first++; dest++
```

Port as trivial 28-byte range relocate. Do **not** use string uninit-copy or dword memmove helpers.

---

## 5. Open questions

None for this leaf beyond product English / runtime / dead null-dest path.

**Verdict:** **accept**
