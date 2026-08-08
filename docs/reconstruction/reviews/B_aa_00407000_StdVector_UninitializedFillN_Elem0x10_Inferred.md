# Review B (skeptical / adversarial): `aa_00407000` StdVector_UninitializedFillN_Elem0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00407000` |
| **VA** | `0x00407000` |
| **Canonical name** | `StdVector_UninitializedFillN_Elem0x10_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` |
| **Counterpart** | `reviews/A_aa_00407000_StdVector_UninitializedFillN_Elem0x10_Inferred.md` |
| **System** | util / container (`std::vector` Ufill POD **elem 0x10**) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is InsertOne / rebind | No index math; no vector host; returns advanced dest only | **Falsified** InsertOne claim |
| 2 | This is uninitialized_copy (range→range) | Parent passes single template value; construct-N loops value→dest | **Falsified** copy-range model |
| 3 | Decompiler `void` / no args is full ABI | Bytes: stack value*, EDI/ESI register formals, **`ret 4`** | **Falsified** void model |
| 4 | Stride 0xC / 0x28 (neighborhood siblings) | Return `*0x10` (`shl 4`); callee advances `+0x10` | **Falsified** wrong-stride |
| 5 | ECX thiscall dest | Dest is **EDI**; ECX reloaded to value* for construct-N | **Falsified** ECX-dest |
| 6 | Grows / reallocates vector | No capacity math; pure fill of provided buffer | **Falsified** grow claim |
| 7 | Leaf with zero callees | Calls `FUN_00409e20` | **Falsified** |
| 8 | Product requires interaction/input-poll name | Generic POD fill; used under InsertN; chain-of-caller scaffold retired | **Agree** structural `_Inferred` |
| 9 | `ret` plain without stack cleanup | **`C2 04 00`** | **Falsified** plain-ret |
| 10 | Count is always 1 | ESI = parent count; InsertN multi-insert uses variable N | **Falsified** always-1 |
| 11 | Is the construct-N itself (00409e20) | Wrapper only; no SEH/loop; returns end pointer | **Falsified** merge-with-construct-N |
| 12 | Is InsertN (00408640) | 29 B thin wrapper; no capacity / 1.5× growth | **Falsified** merge-with-InsertN |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ret 4 / one stack formal + EDI/ESI | **Confirmed** | Stack/register imbalance |
| Fill-N then return end | **Confirmed** | Wrong insert hole plant |
| Stride 16 | **Confirmed** | Wrong element width |
| Role under InsertN | **High** | Mis-attribute grow engine |
| Construct-N 4-dword POD | **High** | Wrong element ctor |
| Runtime | **Open** | No live capture |

---

## 3. Cross-check against raw / live / bytes

```
raw scaffold CF ≡ live decompile (2026-08-05);
bytes @ 0x00407000:
  mov eax,[esp+4]             ; value*
  push eax
  push ecx                    ; phantom
  mov ecx,[esp+0xC]           ; ECX = value*
  push esi                    ; count
  push edi                    ; dest
  call FUN_00409e20           ; StdVector_ConstructN_Elem0x10_Inferred
  mov eax,esi
  shl eax,4
  add esp,0x10
  add eax,edi                 ; dest + count*0x10
  ret 4
```

### ABI trap

Do **not** trust decompiler `int FUN_00407000(void)` + `unaff_ESI/EDI` as “undefined behavior.” Parent InsertN sets **EDI=dest**, **ESI=count** immediately before call (or leaves ESI as residual fill count after distance math on the in-place path).

### Phantom-push trap

Extra pushes + `add esp,0x10` are the same MSVC Ufill-wrapper pattern seen on elem-0xC / elem-0x28 FillN units — not evidence of four real formals consumed by construct-N. Construct-N uses **ECX=value*** + two stack formals (dest, count) and is cdecl (`C3`).

### Scaffold trap

`Named_CalleeOf_*Cli_00407000` implies input-poll domain. Partition parent `0x00409e20` is dualed as generic ConstructN under SortTargetList/InsertN host chains — **not** a reason to invent product UI names for this leaf.

---

## 4. Residual gaps (agreed with A)

1. Product type English.  
2. Dual seal of `00409f70` PodCopy (construct-N dualed).  
3. Runtime / differential.

**Verdict:** **accept-with-gaps** — no CF reject; thin wrapper sealed.
