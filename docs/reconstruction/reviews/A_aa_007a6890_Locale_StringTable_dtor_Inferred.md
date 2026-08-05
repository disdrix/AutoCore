# Review A (reconstruction fidelity): `aa_007a6890` Locale_StringTable_dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007a6890` |
| **VA** | `0x007a6890` |
| **Canonical name** | `Locale_StringTable_dtor_Inferred` (was `FUN_007a6890`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_007a6890_Locale_StringTable_dtor_Inferred.md` |
| **System** | locale / string-table (cross-cutting UI + chat) |
| **Verdict** | **accept** on CF / free loops / thiscall ECX; product name **Inferred** |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Destructor** for the locale / language string-table object (pair of ctor `FUN_007a6910`).

1. Restamp vtable `PTR_FUN_00a96f88`.
2. Free **10** ring buffers at `this+4` … `this+0x28` (`operator_delete__`), null each slot.
3. For **5** language-pack groups: if count at `this+0x58 + i*4` > 0, free up to that many pointers from the pair table, nulling slots.

Does **not** free `this` itself (scalar deleting dtor `FUN_00424810` may `operator_delete(this)` after calling this). Process exit path: atexit thunk `LAB_009c30b0` = `mov ecx, &DAT_00d1f660; jmp FUN_007a6890`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record / raw / annotated / clean | `aa_007a6890_*`, `FUN_007a6890.cpp` |
| Live decompile | Ghidra `batch_decompile` `0x007a6890` (2026-07-29) |
| Live body bytes | `read_memory` `0x007a6890` length 128 |
| Callers | `FUN_00424810` (scalar dtor), atexit path via GetInstance |
| Sibling duals | GetInstance `A_aa_007a69d0_*`; ctor/leaf this batch |

**Not performed:** runtime atexit exercise; bit-exact; Launcher.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__fastcall` / thiscall: **ECX = this** | **Confirmed** | `mov ebx, ecx`; atexit `mov ecx, imm` |
| Restamp same vtable as ctor | **Confirmed** | `c703 886fa900` |
| Free 10 ring slots at +4 step 4 | **Confirmed** | loop counter 10 |
| Free language-pack tables (5 groups) | **Confirmed** | outer count 5; inner bound by `*(this+0x58+…)` |
| Does not `delete this` | **Confirmed** | no `operator_delete(this)` in body |
| Role = dtor / cleanup of ctor state | **High** | inverse of ctor allocs |
| Product name | **Open / Inferred** | |
| Clean ≡ raw ≡ live CF | **Confirmed** | |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Vtable restamp | **Yes** |
| 10× free ring ptr if non-null + null | **Yes** |
| 5× pack groups free by count | **Yes** |
| Return void | **Yes** |
| No re-get-instance / no localize | **Yes** |

### Recovered CF

```c
void __fastcall Locale_StringTable_dtor_Inferred(LocaleStringTable *this)
{
    this->vfptr = &PTR_FUN_00a96f88;
    for (int i = 0; i < 10; ++i) {
        void **slot = &this->ringBuf[i];   // this+4 + 4*i
        if (*slot) operator_delete__(*slot);
        *slot = NULL;
    }
    // 5 language-pack groups: counts @ +0x58, pointer pairs nearby
    for (int g = 0; g < 5; ++g) {
        int n = this->packCount[g];
        for (int j = 0; j < n; ++j) {
            void **p = &this->packPtrs[g][j];
            if (*p) operator_delete__(*p);
            *p = NULL;
        }
    }
}
```

(Exact pack pointer geometry: High from decompile walk `puVar2 = this+0xc` / `piVar1 = this+0x16` with `+2` stride — sealed as “5 groups of up to count frees”, product layout names open.)

---

## 5. Assembly notes (`read_memory`)

```
007a6890  51 53 55 56           push scratch
007a6894  8bd9                  mov  ebx, ecx           ; this
007a6896  57                    push edi
007a6897  c703886fa900          mov  dword [ebx], 0x00a96f88
007a689d  8d7304                lea  esi, [ebx+4]
007a68a0  bf0a000000            mov  edi, 10
; free loop: load [esi]; if non-null delete[]; zero; esi+=4; edi--
; then pack groups with local_4=5
…
007a68xx  5f 5e 5d 5b 59 c3     restore; ret
```

---

## 6. Gaps

1. Product dtor name / exact pack struct field names.
2. Whether pack frees use `delete` vs `delete[]` consistently with allocators (body uses `operator_delete__` — array form).
3. Non-singleton instances’ lifetime (caller residual).

**Verdict:** **accept** — sealed ECX dtor CF, 10-ring free, 5-group pack free, vtable restamp; pairs with ctor dual.
