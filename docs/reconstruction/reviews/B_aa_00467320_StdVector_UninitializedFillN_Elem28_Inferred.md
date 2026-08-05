# Review B (skeptical / adversarial): `aa_00467320` StdVector_UninitializedFillN_Elem28_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00467320` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-T) |
| **Counterpart** | `reviews/A_aa_00467320_StdVector_UninitializedFillN_Elem28_Inferred.md` |
| **Scratch** | `tmp/a_00467320.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Count is stack formal / ECX is count | **Falsified** — `MOV ESI,EAX`; ECX is dest cursor |
| 2 | Stride 4 / memmove fill | **Falsified** — `ADD ECX/EAX,0x1C`; 7 explicit dword stores from EDX |
| 3 | Non-trivial fill (ctor) | **Falsified** — leaf; pure dword assigns from `*value` |
| 4 | `RET n` / stdcall | **Falsified** — bare `C3`; zero stack args |
| 5 | `jbe` means signed `count <= 0` | **Nuance** — after `TEST`, CF clear → `JBE` ≡ `JZ`; decompiler `!= 0` matches |
| 6 | Product demangle | **Overstated** — structural **Inferred** only |
| 7 | Same helper as copy @ `004673b0` | **Falsified** — different ABI (count/value vs first/last); fill vs range copy |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX dest / EDX value* / EAX count | **High** | Wrong fill wiring in insert-n port |
| Stride 0x1c POD | **High** | Corrupt buffer |
| Leaf trivial fill | **High** | Invented string ctor |
| Sole parent `00466ea0` | **High** | Miss domains |
| Runtime | **Open** | rare edge |

---

## 3. Cross-check against raw + bytes

```
bytes: push esi; mov esi,eax; test esi; jbe out;
       lea eax,[ecx+18]; … mov edi,edx; 7× stores; add ecx/eax +0x1c; sub esi,1; jnz; ret
raw ≡ live ≡ clean: count times fieldwise *value → dest++
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. 2 xrefs all CALL inside `FUN_00466ea0`.

Sibling copy `0x004673b0` shares 7-lane POD pattern — confirms this unit is the **fill-n** half of the pair.

---

## 4. Surviving contract for AutoCore

```
UninitializedFillN_Elem28(dest, value, count):
  // ECX=dest, EDX=value*, EAX=count; bare RET
  while count != 0:
    if dest: *dest = *value   // 7 dwords
    dest++; count--
```

Port as trivial 28-byte fill-n. Do **not** treat as range copy or string fill.

---

## 5. Open questions

None for this leaf beyond product English / runtime / dead null-dest path.

**Verdict:** **accept**
